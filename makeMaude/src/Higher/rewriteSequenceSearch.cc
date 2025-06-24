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
  explored_vec.push_back(0);
  // normal_vec.push_back(0);
  result_vec.push_back(0);
  interesting_state_idx = 0; // [GM]
  //explored_vec;
  exploreDepth = -1;
  lastDepth = false;
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
  // printf("[GM] rewriteSequenceSearch::findNextMatch\n");
  if (matchState != 0)
    goto tryMatch;  // non-startup case

  for(;;)
    {
	stateNr = findNextInterestingState();
  printf("[GM] rewriteSequenceSearch::findNextMatch, Interesting state : %d \n", stateNr);
	if (stateNr == NONE)
	  break;
	matchState = new MatchSearchState(getContext()->makeSubcontext(getStateDag(stateNr)),
					  goal,
					  MatchSearchState::GC_CONTEXT);
    tryMatch:
      bool foundMatch = matchState->findNextMatch();// This is a solution for code
      matchState->transferCountTo(*(getContext()));
      if (foundMatch){
        // printf("[GM] rewriteSequenceSearch::findNextMatch, solution found in %d \n", stateNr);
	      return true;
      }

      delete matchState;
    }

  matchState = 0;
  return false;
}


int
RewriteSequenceSearch::findNextInterestingState(){

	 printf("[GM] rewriteSequenceSearch::findNextInterestingState()\n"); 
	 if(needToTryInitialState){
	 	// Checks the initial state
	 	needToTryInitialState = false; // Don't run this twice
	 	int last_val = result_vec.back(); // We initialized the result_vec with 0, so cleaning it our
	 	result_vec.pop_back();
	 	interesting_state_idx++;
	 	return last_val; // Since the value is always 0, though we should be more carefule, maybe use a value
	 }


	 // To return the standard output, we expect the interesting state idx would have been set to 0
	 BFSlevelComplete:

	 if(!(normalFormNeeded || branchNeeded)){
		 if(interesting_state_idx < explored_vec.size()){ // This go on till this set is empty
		 	int state_id = explored_vec[interesting_state_idx];
		 	interesting_state_idx++;
		 	return state_id;
		 }
	}
	else{

		 if(interesting_state_idx < result_vec.size()){ // This go on till this set is empty
		 	int state_id = result_vec[interesting_state_idx];
		 	interesting_state_idx++;
		 	return state_id;
		 }
		 else if(lastDepth == true){
		 	return NONE;
		 }
	}

	 /*
		The thread specific values will handle the to_explore case, we do not need to ensure anything here
	 */

	 // to_explore.clear(); // Cleaning the to_explore bit to test out start fresh


	 /*
		Starting the timer to check out how long it takes to run each iteration
	 */

	 std::chrono::time_point<std::chrono::high_resolution_clock> seq_start;

	 /*
		This is previous code to test, if we should explore the graph
	 */

	 ++exploreDepth;
	 if (normalFormNeeded || branchNeeded)
	    {
	      /*
	      	If we're looking for a state that has a certain number of successors we need to
	      	search one level beyond maxDepth
	      */
	      if (maxDepth != NONE && exploreDepth > maxDepth){
	      	return NONE;
	      }
	    }
	 else
	    {
	      /*
	      	Otherwise we just search to maxDepth (which will never be true if maxDepth == NONE).
	      */
	      if (exploreDepth == maxDepth){
	        return NONE;
	      }
	    }


	  printf("[GM] rewriteSequenceSearch::findNextInterestingState() .. just before pragma\n");

	  /*
		nrState: the number of current state in the graph -- used to check if new states are being created
		firstDeeperNodeNr is the first nodeID of the next level, that ID node has not been created yet
	  */

	  firstDeeperNodeNr = getNrStates();
	  int nrStates = getNrStates();

	  /*Creating the data structure*/
	  std::vector<std::vector<int>> thread_local_to_explore;
  	  std::vector<std::vector<int>> thread_local_result_vec;

	  /*
		Initializing the local level thread storage
		Note: This can be done in the constructor
	  */

	  int num_threads = omp_get_max_threads();
	  thread_local_to_explore.resize(num_threads);
	  thread_local_result_vec.resize(num_threads);

	  /*
		Pragma Code begins here
	  */

	   #pragma omp parallel private(explore,nextArc,returnedStateAlready,seq_start)
	  {
	  		int thread_id = omp_get_thread_num();

	  		#pragma omp for 
	  		for(int exp = 0; exp < explored_vec.size(); ++exp)
	  		{
	  			 seq_start = std::chrono::high_resolution_clock::now();

	  			 /*
	  			 	Node that we are exploring in the tree
	  			 */

	  			 explore = explored_vec[exp];

	  			 printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() Inside the for loop of thread_d: %d, exploring state: %d \n", thread_id,explore);

	  			 nextArc = 0; // We set this to 0, and it will be incremented in the while loop

	  			 int nextStateNr; // Store the ID of the next state 

	  			 while ((nextStateNr = getNextState(explore, nextArc)) != NONE){

	  			 	/*
	  			 	This loop explores the node explore, and if we find new nodes it is added to the tree
	  			 	*/
	  			 	++nextArc; 

	  			 	returnedStateAlready = nextStateNr >= nrStates ? false:true; // If its larger we have not returned the state

	  			 	/*
						thread_local_to_explore[] adds the next layer of state that has not been observed before. For the standard form, this will be returned.

	  			 	*/
	  			 	if(nextStateNr >= nrStates){
	  			 		thread_local_to_explore[thread_id].push_back(nextStateNr);
	  			 	}


	  			 	if (normalFormNeeded){

			                if (exploreDepth == maxDepth){
			                	break;
			                }
		              }
		            else if (branchNeeded){
		            	if (!returnedStateAlready && nextArc >= 2 && nextStateNr != getNextState(explore, 0)) // Need this node being sent out to explore
		                      {
		                        returnedStateAlready = true;  // so we don't return the state again if we see another distinct next state
		                        /*
		                        We will add the values from the branch form and the normal form in result_vec, we should put everything to the result_vec
		                        */
		                        thread_local_result_vec[thread_id].push_back(explore);
		                      }
			            }

	  			 }

	  			 /*
	  			 The while node exploration (while) loop ends here. 
	  			 Now we will check if we were able to explore anything, especially for the normal form
	  			 */
	  			 if(normalFormNeeded && nextArc == 0){
	  			 	nextArc = NONE;
	  			 	thread_local_result_vec[thread_id].push_back(explore);
	  			 }

	  			 /*
					Get the time of a single node exploration. This should not be impacted by threading.
	  			 */
	  			 std::chrono::time_point<std::chrono::high_resolution_clock> seq_end = std::chrono::high_resolution_clock::now();
      			 std::chrono::nanoseconds::rep seq_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(seq_end - seq_start).count();

      			 printf("[GM] End of the exploration of state %d . Thread ID %d. Time: %lld\n",explore,thread_id,seq_duration);
	  		} // for loop

	  } // pragma

	  /*
		We end the pragma here. So this is a natural barrier to the code
	  */

	 explored_vec.clear();
	 result_vec.clear();
	 for(int i = 0; i < num_threads; i++) {

		    explored_vec.insert(explored_vec.end(), thread_local_to_explore[i].begin(), thread_local_to_explore[i].end());
		    result_vec.insert(result_vec.end(), thread_local_result_vec[i].begin(), thread_local_result_vec[i].end());	    
		}

	//Get the unique values
	sort(explored_vec.begin(), explored_vec.end());
	explored_vec.erase(unique(explored_vec.begin(),explored_vec.end()),explored_vec.end());
	sort(result_vec.begin(), result_vec.end());
	result_vec.erase(unique(result_vec.begin(),result_vec.end()),result_vec.end());

	
	if(explored_vec.size() == 0){
		
		if(!(normalFormNeeded ||branchNeeded)){
			return NONE;
		}
		else{
			interesting_state_idx = 0;
			lastDepth = true;
			goto BFSlevelComplete;
		}
	 }
	else{
		interesting_state_idx = 0;
		goto BFSlevelComplete;
	}

	return NONE;
}


int
RewriteSequenceSearch::findNextInterestingStateP(){ // this is my playground. I will use this function to play around, and ensure it doesn't break things

  printf("[GM] rewriteSequenceSearch::findNextInterestingState()\n");
  if (needToTryInitialState)
    {
      //
      //	Special case: return the initial state.
      //
      needToTryInitialState = false;  // don't do this again
      result_vec.pop_back();
      interesting_state_idx++;
      return 0;
    }
  listReturn:
    // Condition for normal form

    if (interesting_state_idx < result_vec.size()) { // We have states ready to be explored
      printf("[GM] rewriteSequenceSearch::findNextInterestingState() Inside the small loop \n");
      int state_id = result_vec[interesting_state_idx];
      interesting_state_idx++;
      return state_id;
    }
    else if (interesting_state_idx > 1){
      return NONE;
    }

  loopReturn:
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
  printf("[GM] rewriteSequenceSearch::findNextInterestingState() .. just before pragma\n");
	firstDeeperNodeNr = getNrStates(); // we have not generated it yet, but this will be the state ID
  int nrStates = getNrStates(); // size of the graph currently, common for all threads

 // Thread-local storage for collecting results
  std::vector<std::vector<int>> thread_local_to_explore;
  std::vector<std::vector<int>> thread_local_result_vec;


  #pragma omp parallel for private(explore,nextArc,returnedStateAlready)
  for(int exp = 0; exp < explored_vec.size(); ++exp) // exp is the one for explore now
    {
    
      seq_start = std::chrono::high_resolution_clock::now();
      //
      //	Get index of next state to explore.
      //

      explore = explored_vec[exp]; // [GM] This is the value or the id of the graph that we will explore
      // if (exploredSet.find(explore) != exploredSet.end()){
      //   continue;
      // }
      // exploredSet.insert(explore);
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
            printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() the while loop, nextStateNr : %d , nrState: %d \n",nextStateNr,nrStates);
            printf("[GMDip] rewriteSequenceSearch::findNextInterestingState() the while loop, normalFormNeeded : %d , branchNeeded: %d \n",normalFormNeeded,branchNeeded);
            
            if(nextStateNr >= nrStates){
              to_explore.push_back(nextStateNr);
            }

            ++nextArc;
            if (normalFormNeeded)
              {
                if (exploreDepth == maxDepth){
                  // add nothing and be merry
                    // to_explore.push_back(explore); // will this help the normalForm issue?
                    break;
                }
            // no point looking for further arcs from this state
              }
            else if (branchNeeded)
              {
                if (!returnedStateAlready && nextArc >= 2 && nextStateNr != getNextState(explore, 0)) // Need this node being sent out to explore
                      {
                        returnedStateAlready = true;  // so we don't return the state again if we see another distinct next state
                        //[GM] add to to explore, we should create a local thread vector, which will add the states, and we can push
                        // all the vector addition to the end
                        // #pragma omp critical
                        //   {
                              // to_explore.push_back(explore);
                          // }
                        
                      }
              }
          }
  // //!!!!!!!!!![GM] We do not know if we need to use this may be problematic
  // if (getContext()->traceAbort())
	// return NONE;

  // !!!!!!!!!!!!  [This is state does not need exploring]
      if (normalFormNeeded && nextArc == 0){
	  //
	  //	No next states so we can return the state we just explored as a normal form.
	  //
            nextArc = NONE;
            result_vec.push_back(explore);
	      }
    std::chrono::time_point<std::chrono::high_resolution_clock> seq_end = std::chrono::high_resolution_clock::now();
	  std::chrono::nanoseconds::rep seq_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(seq_end - seq_start).count();
    iter++;
    printf("[GM] End of for loop. Iteration Count %d. Time: %lld\n",iter,seq_duration);
    }
  printf("[GM] rewriteSequenceSearch::findNextInterestingState - Number of iterations: %d \n" , iter);
  printf("[GM] ewriteSequenceSearch::findNextInterestingState Length of to_explore - %d \n",to_explore.size());
  if(to_explore.size()==0){
    goto listReturn;
  }
  //
  // Do our thing
  sort(to_explore.begin(),to_explore.end());
  to_explore.erase(unique(to_explore.begin(),to_explore.end()),to_explore.end());
  explored_vec.clear();
  explored_vec.assign(to_explore.begin(),to_explore.end());
  if(normalFormNeeded==false){
    result_vec.insert(result_vec.end(),explored_vec.begin(),explored_vec.end());
  }

  // interesting_state_idx = 0;
  goto loopReturn;

  return NONE;
}

int
RewriteSequenceSearch::findNextInterestingStateOG() // this is the original code
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
