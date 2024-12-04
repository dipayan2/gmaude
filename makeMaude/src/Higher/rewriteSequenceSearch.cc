/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2024 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Implementation for class RewriteSequenceSearch.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "pattern.hh"
#include "rewriteSearchState.hh"
#include "rewriteSequenceSearch.hh"

RewriteSequenceSearch::RewriteSequenceSearch(RewritingContext* initial,
					     SearchType searchType,
					     Pattern* goal,
					     int maxDepth)
  : StateTransitionGraph(initial),
    goal(goal),
    maxDepth((searchType == ONE_STEP) ? 1 : maxDepth)
{
  matchState = 0;
  explore = -1;
  to_explore.push_back(0); // [GM -- adding the first vector that will be explored]
  interesting_state_idx = 0; // [GM]
  //explored_vec;
  exploreDepth = -1;
  firstDeeperNodeNr = 0;
  returnedStateAlready = false;
  needToTryInitialState = (searchType == ANY_STEPS);
  reachingInitialStateOK = (searchType == AT_LEAST_ONE_STEP || searchType == ONE_STEP);
  normalFormNeeded = (searchType == NORMAL_FORM);
  branchNeeded = (searchType == BRANCH);
  nextArc = NONE;
}

RewriteSequenceSearch::~RewriteSequenceSearch()
{
  delete matchState;
  delete goal;
}

bool
RewriteSequenceSearch::findNextMatch()
{
  printf("[GM] rewriteSequenceSearch::findNextMatch\n");
  if (matchState != 0)
    goto tryMatch;  // non-startup case

  for(;;)
    {
	stateNr = findNextInterestingState();
	if (stateNr == NONE)
	  break;
	matchState = new MatchSearchState(getContext()->makeSubcontext(getStateDag(stateNr)),
					  goal,
					  MatchSearchState::GC_CONTEXT);
    tryMatch:
      bool foundMatch = matchState->findNextMatch();
      matchState->transferCountTo(*(getContext()));
      if (foundMatch)
	return true;
      delete matchState;
    }

  matchState = 0;
  return false;
}

int
RewriteSequenceSearch::findNextInterestingState(){ // this is my playground. I will use this function to play around, and ensure it doesn't break things

  printf("[GM] rewriteSequenceSearch::findNextInterestingState()\n");
  if (needToTryInitialState)
    {
      //
      //	Special case: return the initial state.
      //
      needToTryInitialState = false;  // don't do this again
      return 0;
    }
  listReturn:
    if (interesting_state_idx < explored_vec.size()){ // We have states ready to be explored
      int state_id = explored_vec[interesting_state_idx];
      interesting_state_idx++;
      return explored_vec[interesting_state_idx];
    }
  // this is the else condition
  to_explore.clear(); // cleaned that stuff, we will add our values to this vector
    // [This above bit is not used any more]
  int iter = 0;
  std::chrono::time_point<std::chrono::high_resolution_clock> seq_start;
  // if (nextArc != NONE)
  //   goto exploreArcs;

//[!!! PARALLEL] This is the code, which will search through all the states, or atleast that's the idea
  printf("[GM] rewriteSequenceSearch::findNextInterestingState() .. starting the loop\n");
  // As we are exploring the next state, we do these house keeping stuff
  ++exploreDepth;
  if (normalFormNeeded || branchNeeded)
    {
      //
      //	If we're looking for a state that has a certain number of successors we need to
      //	search one level beyond maxDepth
      //
      if (maxDepth != NONE && exploreDepth > maxDepth){
        return NONE;
      }
    }
  else
    {
      //
      //	Otherwise we just search to maxDepth (which will never be true if maxDepth == NONE).
      //
      if (exploreDepth == maxDepth){
        return NONE;
      }
    }
	  //
	  //	Next state generated (if there is one) will be the first node of the following level.
	  //
	firstDeeperNodeNr = getNrStates(); // we have not generated it yet, but this will be the state ID
  int nrStates = getNrStates(); // size of the graph currently
  // #pragma omp parallel for private(explore,nextArc)
  for(int exp = 0; exp < explored_vec.size(); ++ exp) // exp is the one for explore now
    {
    
      seq_start = std::chrono::high_resolution_clock::now();
      //
      //	Get index of next state to explore.
      //

      explore = to_explore[exp]; // [GM] This is the value or the id of the graph that we will explore
      printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() Inside the for loop, exploring state: %d \n", explore);
      nextArc = 0;
      //
      //	Explore the arcs of the current state.
      //
    // exploreArcs:
    //   seq_start = std::chrono::high_resolution_clock::now();
      // int nrStates = getNrStates();
      int nextStateNr; // 
      while ((nextStateNr = getNextState(explore, nextArc)) != NONE)
          {
            returnedStateAlready = nextStateNr>=nrStates ? true:false;
            printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() the while loop, curr State:%d, the nextArc: %d\n",explore,nextArc);
            ++nextArc;
            if (normalFormNeeded)
              {
                if (exploreDepth == maxDepth){
                  // add nothing and be merry
                    break;
                }
            // no point looking for further arcs from this state
              }
            else if (branchNeeded)
              {
                if (!returnedStateAlready && nextArc >= 2 && nextStateNr != getNextState(explore, 0)) // Need this node being sent out to explore
                      {
                        returnedStateAlready = true;  // so we don't return the state again if we see another distinct next state
                        // add to to explore
                        // #pragma omp critical
                          // {
                              to_explore.push_back(explore);
                          // }
                        
                      }
              }
            else
              {
                if (nextStateNr >= nrStates){
                  // #pragma omp critical
                      // {
                          to_explore.push_back(nextStateNr);// we reached a new state so return it
                      // }
                }
                    
                //
                //	We reached a state that we already saw.
                //
            //     if (nextStateNr == 0 && reachingInitialStateOK)
            // {
            //   //
            //   //	We have arrived back at our initial state, but because
            //   //	we didn't try matching the initial state, we do it now.
            //   //
            //     #pragma omp critical
            //       {   
            //           reachingInitialStateOK = false;
            //           to_explore.push_back(0);// we reached a new state so return it
            //       }
            //     // don't do this again
            // }
              }
          }
  // //!!!!!!!!!![GM] We do not know if we need to use this may be problematic
  // if (getContext()->traceAbort())
	// return NONE;

  // !!!!!!!!!!!!  [This is state does not need exploring]
  //     if (normalFormNeeded && nextArc == 0)
	// {
	//   //
	//   //	No next states so we can return the state we just explored as a normal form.
	//   //
	//   nextArc = NONE;
	//   return explore;
	// }
    std::chrono::time_point<std::chrono::high_resolution_clock> seq_end = std::chrono::high_resolution_clock::now();
	  std::chrono::nanoseconds::rep seq_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(seq_end - seq_start).count();
    iter++;
    printf("[GM] End of for loop. Iteration Count %d. Time: %lld\n",iter,seq_duration);
    }
  printf("[GM] rewriteSequenceSearch::findNextInterestingState - Number of iterations: %d \n" , iter);

  if(to_explore.size()==0){
    return NONE; // can't find more states
  }
  //
  // Do our thing
  sort(to_explore.begin(),to_explore.end());
  to_explore.erase(unique(to_explore.begin(),to_explore.end()),to_explore.end());
  explored_vec = to_explore;
  interesting_state_idx = 0;
  goto listReturn;

  return NONE;
}

int
RewriteSequenceSearch::findNextInterestingStateP() // this is the original code
{
  printf("[GM] rewriteSequenceSearch::findNextInterestingState()\n");
  if (needToTryInitialState)
    {
      //
      //	Special case: return the initial state.
      //
      needToTryInitialState = false;  // don't do this again
      return 0;
    }
    // [This above bit is not used any more]
  int iter = 0;
  std::chrono::time_point<std::chrono::high_resolution_clock> seq_start;
  if (nextArc != NONE)
    goto exploreArcs;

//[!!! PARALLEL] This is the code, which will search through all the states, or atleast that's the idea
  printf("[GM] rewriteSequenceSearch::findNextInterestingState() .. starting the loop\n");

  // #pragma omp parallel for private(explore)
  // for(int exp = 0; exp < to_explore.size(); ++ exp) // exp is the one for explore now
  for(;;)
    {
    
    seq_start = std::chrono::high_resolution_clock::now();
      //
      //	Get index of next state to explore.
      //

      // update lastExplore nrsize 
      // update graph size cont 
      // for explore in .. (lastexplore+1 -> nrsize-1)

      ++explore;
      // explore = to_explore[exp]; // [GM] This is the value or the id of the graph that we will explore
      printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() Inside the for loop, exploring state: %d \n", explore);
      returnedStateAlready = false;  // needed for BRANCH search type
      //[GM] we won't need this as our for loop has fixed length

      // [GM] !!!!!!!!!!!!!!!!!!!! COMMENT -- START our logic will handle it
      
      if (explore == getNrStates()){ 
        printf("[GMDip] ENDDDD the search of the for loop, the state number is: %d\n",explore); // we might not need this based on other factors
	      break;  // all states explored
      }
      
      // [GM] !!!!!!!!!!!!!!!!!!!!   COMMENT - END (should uncomment if we need to handle it)

      //
      //	Are we at the first node of the next level? this part is triggered when we get set the 
      //
      // if(exp == 0)
      if (explore == firstDeeperNodeNr)
	{
	  ++exploreDepth;
	  if (normalFormNeeded || branchNeeded)
	    {
	      //
	      //	If we're looking for a state that has a certain number of successors we need to
	      //	search one level beyond maxDepth
	      //
	      if (maxDepth != NONE && exploreDepth > maxDepth)
		break;
	    }
	  else
	    {
	      //
	      //	Otherwise we just search to maxDepth (which will never be true if maxDepth == NONE).
	      //
	      if (exploreDepth == maxDepth)
		break;
	    }
	  //
	  //	Next state generated (if there is one) will be the first node of the following level.
	  //
	  firstDeeperNodeNr = getNrStates();
	}
  //[GM] barrier in pragma 
      nextArc = 0;
      //
      //	Explore the arcs of the current state.
      //
    exploreArcs:
      seq_start = std::chrono::high_resolution_clock::now();
      int nrStates = getNrStates();
      int nextStateNr; // 
      while ((nextStateNr = getNextState(explore, nextArc)) != NONE)
	{
    printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() the while loop, curr State:%d, the nextArc: %d\n",explore,nextArc);
	  ++nextArc;
	  if (normalFormNeeded)
	    {
	      if (exploreDepth == maxDepth)
		break;  // no point looking for further arcs from this state
	    }
	  else if (branchNeeded)
	    {
	      if (!returnedStateAlready && nextArc >= 2 && nextStateNr != getNextState(explore, 0)) // Need this node being sent out to explore
              {
                returnedStateAlready = true;  // so we don't return the state again if we see another distinct next state
                return explore;
              }
	    }
	  else
	    {
	      if (nextStateNr == nrStates)
		return nextStateNr;  // we reached a new state so return it
	      //
	      //	We reached a state that we already saw.
	      //
	      if (nextStateNr == 0 && reachingInitialStateOK)
		{
		  //
		  //	We have arrived back at our initial state, but because
		  //	we didn't try matching the initial state, we do it now.
		  //
		  reachingInitialStateOK = false;  // don't do this again
		  return 0;
		}
	    }
	}
      if (getContext()->traceAbort())
	return NONE;
      if (normalFormNeeded && nextArc == 0)
	{
	  //
	  //	No next states so we can return the state we just explored as a normal form.
	  //
	  nextArc = NONE;
	  return explore;
	}
    std::chrono::time_point<std::chrono::high_resolution_clock> seq_end = std::chrono::high_resolution_clock::now();
	  std::chrono::nanoseconds::rep seq_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(seq_end - seq_start).count();
    iter++;
    printf("[GM] End of for loop. Iteration Count %d. Time: %lld\n",iter,seq_duration);
    }
  printf("[GM] rewriteSequenceSearch::findNextInterestingState - Number of iterations: %d \n" , iter);
  return NONE;
}

Rule*
RewriteSequenceSearch::getStateRule(int stateNr) const
{
  const ArcMap& fwdArcs = getStateFwdArcs(getStateParent(stateNr));
  return *(fwdArcs.find(stateNr)->second.begin());
}
