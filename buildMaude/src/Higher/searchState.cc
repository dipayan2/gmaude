/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2023 SRI International, Menlo Park, CA 94025, USA.

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
//	Implementation for class SearchState.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "lhsAutomaton.hh"
#include "preEquation.hh"
#include "conditionState.hh"
#include "dagRoot.hh"
#include "searchState.hh"


local_inline bool
SearchState::hasCondition(const PreEquation* preEqn)
{
  //
  //	First test most likely to fail so we do it first.
  //
  return preEqn->hasCondition() && !(getFlags() & IGNORE_CONDITION);
}

SearchState::SearchState(RewritingContext* context,
			 int flags,
			 int minDepth,
			 int maxDepth)
  : PositionState(context->root(), flags, minDepth, maxDepth),
    context(context)
{
  matchingSubproblem = 0;
}

SearchState::~SearchState()
{
  //
  //	Delete stuff we created.
  //
  while (!conditionStack.empty())
    {
      delete conditionStack.top();
      conditionStack.pop();
    }
  delete matchingSubproblem;
  //
  //	Delete stuff entrusted to us by our creator.
  //
  if (getFlags() & GC_SUBSTITUTION)
    {
      int nrUserVars = substVariables.length();
      for (int i = 0; i < nrUserVars; i++)
	{
	  substVariables[i]->deepSelfDestruct();
	  delete substValues[i];
	}
    }
  if (getFlags() & GC_CONTEXT)
    delete context;
}

bool
SearchState::findFirstSolution(const PreEquation* preEqn, LhsAutomaton* automaton)
{
  delete matchingSubproblem;
  matchingSubproblem = 0;
  DagNode* subject = getDagNode();
  //
  //	If we're searching with nonzero maxDepth it is reasonable for pattern
  //	and subject to be in different components.
  //
  if (preEqn->getLhs()->getComponent() == subject->symbol()->rangeComponent())
    {
      context->clear(preEqn->getNrProtectedVariables());
      if (initSubstitution(*preEqn) &&
	  automaton->match(subject, *context, matchingSubproblem, getExtensionInfo()) &&
	  (matchingSubproblem == 0 ||
	   matchingSubproblem->solve(true, *context)) &&
	  (!hasCondition(preEqn) ||
	   preEqn->checkCondition(true,
				  subject,
				  *context,
				  matchingSubproblem,
				  trialRef,
				  conditionStack)))
	{
	  preEquation = preEqn;
	  return true;
	}
    }
  return false;
}

bool
SearchState::findNextSolution()
{
  if (hasCondition(preEquation))
    {
      return preEquation->checkCondition(false,
					 getDagNode(),
					 *context,
					 matchingSubproblem,
					 trialRef,
					 conditionStack);
    }
  else
    return matchingSubproblem != 0 && matchingSubproblem->solve(false, *context);
}

bool
SearchState::initSubstitution(const VariableInfo& varInfo)
{
  if (substVariables.empty())
    return varInfo.getUnboundVariables().empty();
  int nrUserVars = substVariables.length();
  int nrVars = varInfo.getNrRealVariables();
  NatSet bound;
  for (int i = 0; i < nrUserVars; i++)
    {
      Term* userVar = substVariables[i];
      for (int j = 0; j < nrVars; j++)
	{
	  if (userVar->equal(varInfo.index2Variable(j)))
	    {
	      context->bind(j, substValues[i]->getNode());
	      bound.insert(j);
	      break;
	    }
	}
    }
  return bound.contains(varInfo.getUnboundVariables());
}
