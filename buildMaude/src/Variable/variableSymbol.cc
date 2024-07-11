/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class VariableSymbol.
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
#include "term.hh"

//	core class definitions
#include "sortBdds.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"
#include "variableDagNode.hh"

VariableSymbol::VariableSymbol(int id)
  : Symbol(id, 0)
{
}

Term*
VariableSymbol::makeTerm(const Vector<Term*>& args)
{
  Assert(false, "makeTerm() not useable on variable symbol " << this);
  return 0;
}

DagNode*
VariableSymbol::makeDagNode(const Vector<DagNode*>& args)
{
  Assert(false, "makeDagNode() not useable on variable symbol " << this);
  return 0;
}

bool
VariableSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  return applyReplace(subject, context);
}

void
VariableSymbol::computeBaseSort(DagNode* subject)
{
  subject->setSortIndex(getSort()->index());
}

void
VariableSymbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  fastComputeTrueSort(subject, context);
}

Term*
VariableSymbol::termify(DagNode* dagNode)
{
  VariableDagNode* v = safeCastNonNull<VariableDagNode*>(dagNode);
  return new VariableTerm(this, v->id());
}

//
//	Unification code.
//

void
VariableSymbol::computeGeneralizedSort(const SortBdds& sortBdds,
				       const Vector<int>& realToBdd,
				       DagNode* subject,
				       Vector<Bdd>& generalizedSort)
{
  int firstVariable = realToBdd[safeCastNonNull<VariableDagNode*>(subject)->getIndex()];  // first BDD variable for this variable
  int nrVariables = sortBdds.getNrVariables(rangeComponent()->getIndexWithinModule());  // number of BDD variables depends on sort
  sortBdds.makeVariableVector(firstVariable, nrVariables, generalizedSort);
}

void
VariableSymbol::computeGeneralizedSort2(const SortBdds& sortBdds,
					const Vector<int>& realToBdd,
					DagNode* subject,
					Vector<Bdd>& outputBdds)
{
  sortBdds.appendVariableVector(realToBdd[safeCastNonNull<VariableDagNode*>(subject)->getIndex()],  // first BDD variable
				sortBdds.getNrVariables(rangeComponent()->getIndexWithinModule()),  // # BDD variables
				outputBdds);
}

bool
VariableSymbol::isStable() const
{
  return false;
}

bool
VariableSymbol::determineGround(DagNode* /* dagNode */)
{
  return false;
}

//
//	Hash cons code.
//

DagNode*
VariableSymbol::makeCanonical(DagNode* original, HashConsSet* /* hcs */)
{
  //
  //	No arguments that could be non-canonical so we can make the original
  //	instance into the canonical instance.
  //
  return original;
}

DagNode*
VariableSymbol::makeCanonicalCopy(DagNode* original, HashConsSet* /* hcs */)
{
  //
  //	We have a unreduced node - copy forced -  in principle variable could rewrite to something else!
  //
  VariableDagNode* v = safeCastNonNull<VariableDagNode*>(original);
  VariableDagNode* n = new VariableDagNode(this, v->id(), v->getIndex());
  n->copySetRewritingFlags(original);
  n->setSortIndex(original->getSortIndex());
  return n;
}
