/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2008 SRI International, Menlo Park, CA 94025, USA.

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
//      Class for unification subproblems in the AC and ACU theories.
//	It consists of the AC(U) symbol, a vector of abstracted subterms and a basis for the
//	Diophantine system corresponding the purified AC(U) unification problem.
//
#ifndef _ACU_UnificationSubproblem2_hh_
#define _ACU_UnificationSubproblem2_hh_
#include <list>
#include "unificationSubproblem.hh"
#include "simpleRootContainer.hh"
#include "natSet.hh"
#include "bddUser.hh"
#include "allSat.hh"
#include "dagNode.hh"
//#include "dagNodeSet.hh"
#include "substitution.hh"
#include "pendingUnificationStack.hh"

class ACU_UnificationSubproblem2 : public UnificationSubproblem, private SimpleRootContainer
{
  NO_COPYING(ACU_UnificationSubproblem2);

public:
  ACU_UnificationSubproblem2(ACU_Symbol* topSymbol);
  ~ACU_UnificationSubproblem2();

  void addUnification(DagNode* lhs, DagNode* rhs, bool marked, UnificationContext& solution);
  bool solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending);

#ifdef DUMP
  //void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  //  DagNodeSet subterms;

  struct Entry
  {
    Vector<int> element;	// practical basis elements will fit in 32-bit machine integers
    NatSet remainder;		// which subterms will be assigned by remaining elements
    int index;
  };

  typedef list<Entry> Basis;
  typedef list<NatSet> NatSetList;

  void markReachableNodes();

  int setMultiplicity(DagNode* dagNode, int multiplicity, UnificationContext& solution);
  void killCancelledSubterms(int nrOldSubterms);
  void unsolve(int index, UnificationContext& solution);

  void classify(int subtermIndex,
		UnificationContext& solution,
		bool& canTakeIdentity,
		int& upperBound,
		Symbol*& stableSymbol);
  bool buildAndSolveDiophantineSystem(UnificationContext& solution);
  bool nextSelection(bool findFirst);
  bool nextSelectionWithIdentity(bool findFirst);
  bool includable(Basis::const_iterator potential);
  bdd computeLegalSelections();
  bool buildSolution(UnificationContext& solution, PendingUnificationStack& pending);
  int reuseVariable(int selectionIndex);

  ACU_Symbol* topSymbol;
  Vector<DagNode*> subterms;
  list<Vector<int> > unifications;

  Basis basis;
  Vector<int> multiplicities;
  NatSet accumulator;
  Vector<int> totals;
  Vector<int> upperBounds;
  NatSet needToCover;
  NatSet uncovered;
  Vector<Basis::const_iterator> selection;
  Basis::const_iterator current;
  Substitution savedSubstitution;
  Substitution preSolveSubstitution;
  PendingUnificationStack::Marker savedPendingState;
  //
  //	Needed for identity case.
  //
  NatSetList old;
  NatSet selectionSet;
  AllSat* maximalSelections;
  NatSet markedSubterms;  // indices of subterms that have been marked
};

#endif
