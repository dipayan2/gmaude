/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2020 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class CUI_UnificationSubproblem.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"

#include "CUI_Theory.hh"

//      interface class definitions
#include "dagNode.hh"

//      core class definitions
#include "variableInfo.hh"
#include "unificationContext.hh"
#include "localBinding.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//	CUI theory class definitions
#include "CUI_Symbol.hh"
#include "CUI_DagNode.hh"
#include "CUI_UnificationSubproblem.hh"

CUI_UnificationSubproblem::CUI_UnificationSubproblem()
{
  DebugAdvisory("Created CUI_UnificationSubproblem() base " << ((void*) this));
}

CUI_UnificationSubproblem::~CUI_UnificationSubproblem()
{
}

void
CUI_UnificationSubproblem::markReachableNodes()
{
  for (const Problem& p : problems)
    {
      int nrFragile = p.savedSubstitution.nrFragileBindings();
      for (int j = 0; j < nrFragile; j++)
	{
	  if (DagNode* d = p.savedSubstitution.value(j))
	    d->mark();
	}
    }
}

void
CUI_UnificationSubproblem::addUnification(DagNode* lhs,
					  DagNode* rhs,
					  bool marked,
					  UnificationContext& /* solution */)
{
  DebugEnter(lhs << " vs " << rhs);
  Assert(marked == false, "this class shouldn't get collapse problems");
  problems.append(Problem(safeCast(CUI_DagNode*, lhs), safeCast(CUI_DagNode*, rhs)));
}

bool
CUI_UnificationSubproblem::solve(bool findFirst,
				 UnificationContext& solution,
				 PendingUnificationStack& pending)
{
  int nrProblems = problems.size();
  int i;

  if (findFirst)
    {
      i = 0;
    forward:
      for (; i < nrProblems; ++i)
	{
	  Problem& p = problems[i];
	  //
	  //	Save state before solving this problem.
	  //
	  p.savedSubstitution.clone(solution);
	  p.savedPendingState = pending.checkPoint();
	  p.reverseTried = false;
	  DebugInfo("trying " << (DagNode*) p.lhs << " vs " << (DagNode*) p.rhs << " forwards");
	  if (!(p.lhs->getArgument(0)->computeSolvedForm(p.rhs->getArgument(0), solution, pending) &&
		p.lhs->getArgument(1)->computeSolvedForm(p.rhs->getArgument(1), solution, pending)))
	    goto backtrack;
	}
      return true;
    }
  else
    {
      i = nrProblems - 1;
    backtrack:
      for (; i >= 0; --i)
	{
	  Problem& p = problems[i];
	  if (!p.reverseTried)
	    {
	      //
	      //	Restore the state to what it was before we solved this problem the first time.
	      //
	      solution.restoreFromClone(p.savedSubstitution);
	      pending.restore(p.savedPendingState);
	      DebugInfo("trying " << (DagNode*) p.lhs << " vs " << (DagNode*) p.rhs << " backwards");
	      if (p.lhs->getArgument(0)->computeSolvedForm(p.rhs->getArgument(1), solution, pending) &&
		  p.lhs->getArgument(1)->computeSolvedForm(p.rhs->getArgument(0), solution, pending))
		{
		  p.reverseTried = true;
		  ++i;
		  goto forward;
		}
	    }
	}
    }
  //
  //	Restore initial state.
  //
  Problem& p = problems[0];
  solution.restoreFromClone(p.savedSubstitution);
  pending.restore(p.savedPendingState);
  return false;
}
