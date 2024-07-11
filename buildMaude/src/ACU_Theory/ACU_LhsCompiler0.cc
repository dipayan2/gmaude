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
//	Implementation of match compilation for AC and ACU theories.
//	Part 0: See if the pattern falls into one of several common cases
//	where we can try a fast heuristic.
//
#include "ACU_VarLhsAutomaton.hh"
#include "ACU_BndVarLhsAutomaton.hh"
#include "ACU_NGA_LhsAutomaton.hh"
#include "ACU_GndLhsAutomaton.hh"
#include "ACU_NonLinearLhsAutomaton.hh"

LhsAutomaton*
ACU_Term::compileLhs2(bool matchAtTop,
		      const VariableInfo& variableInfo,
		      NatSet& boundUniquely,
		      bool& subproblemLikely)
{
  ACU_LhsAutomaton* a = tryToMakeSpecialCaseAutomaton(matchAtTop,
						      variableInfo,
						      boundUniquely);
  if (a == 0)
    {
      a = new ACU_LhsAutomaton(symbol(),
			       matchAtTop,
			       !(collapseSymbols().empty()),
			       variableInfo.getNrProtectedVariables());
      DebugInfo("this = " << this << "local size = " << variableInfo.getNrProtectedVariables());
    }
  compileLhs3(matchAtTop, variableInfo, boundUniquely, subproblemLikely, a);
  return a;
}

ACU_LhsAutomaton*
ACU_Term::tryToMakeSpecialCaseAutomaton(bool matchAtTop,
					const VariableInfo& variableInfo,
					NatSet& boundUniquely)
{
  if (matchAtTop && argArray.length() == 1)
    return tryToMakeNonLinearLhsAutomaton(variableInfo, boundUniquely);
  if (argArray.length() == 2 &&
      argArray[0].multiplicity == 1 &&
      argArray[1].multiplicity == 1 &&
      (!matchAtTop || collapseSymbols().empty()))  // don't handle collapses at the top
    {
      ACU_LhsAutomaton* t = 
	tryToMakeCollectorLhsAutomaton(matchAtTop, variableInfo, boundUniquely, 0);
      if (t != 0)
	return t;
      return tryToMakeCollectorLhsAutomaton(matchAtTop, variableInfo, boundUniquely, 1);
    }
  return 0;
}

ACU_LhsAutomaton*
ACU_Term::tryToMakeNonLinearLhsAutomaton(const VariableInfo& variableInfo,
					 NatSet& boundUniquely)
{

  VariableTerm* v = dynamic_cast<VariableTerm*>(argArray[0].term);
  if (v == 0)
    return 0;
  ACU_Symbol* s = symbol();
  int vi = v->getIndex();
  Sort* vs = v->getSort();
  int multiplicity = argArray[0].multiplicity;
  Assert(multiplicity >= 2, "bad multiplicity");
  //
  //	Non linear variable should:
  //	(1) be unbound at match time (can't guarantee this of course);
  //	(2) not occur in condition;
  //	(3) not occur elsewhere in lhs;
  //	(4) have unit, limit or pure sort w.r.t. top symbol;
  //	(5) not be able to take identity; and
  //
  if (boundUniquely.contains(vi) ||
      variableInfo.getConditionVariables().contains(vi) ||
      v->occursInContext().contains(vi) ||
      (s->sortBound(vs) > 1 &&
       s->sortStructure(vs) != AssociativeSymbol::LIMIT_SORT &&
       s->sortStructure(vs) != AssociativeSymbol::PURE_SORT) ||
      s->takeIdentity(vs))
    return 0;
  Assert(collapseSymbols().empty(), "shouldn't be able to collapse");
  return new ACU_NonLinearLhsAutomaton(s,
				       variableInfo.getNrProtectedVariables(),
				       vi, 
				       multiplicity,
				       vs);
}

ACU_LhsAutomaton*
ACU_Term::tryToMakeCollectorLhsAutomaton(bool matchAtTop,
					 const VariableInfo& variableInfo,
					 NatSet& boundUniquely,
					 int collectorCandidate)
{
  //
  //	We require that our top symbol be free of sort constraints.
  //
  if (!(symbol()->sortConstraintFree()))
    return 0;
  //
  //	First check collector.
  //
  VariableTerm* c = dynamic_cast<VariableTerm*>(argArray[collectorCandidate].term);
  if (c == 0)
    return 0;
  int ci = c->getIndex();
  //
  //	Collector variable should:
  //	(1) be unbound at match time (can't guarantee this of course); and
  //	(2) have unbounded sort
  //	Unless stripper is a ground term or a bound variable and there is no extension (i.e.
  //	there will be a unique match) we also require that variable should:
  //	(3) not occur in condition; and
  //	(4) not occur elsewhere in lhs.
  //
  if (boundUniquely.contains(ci) || symbol()->sortBound(c->getSort()) != UNBOUNDED)
    return 0;
  //
  //	If the collector variable appears in the condition or elsewhere in the pattern  we need
  //	to be able to compute all values it could take.
  //
  bool needAllCollectorSolutions = variableInfo.getConditionVariables().contains(ci) || c->occursInContext().contains(ci);
  if (matchAtTop && needAllCollectorSolutions)
    {
      //
      //	If we matching at the top, we can't uniquely determine the split between the extension
      //	and the collector variable, and so we give up on a stripper-collector automaton.
      //
      return 0;
    }
  //
  //	Then check stripper.
  //
  Term* t = argArray[1 - collectorCandidate].term;
  if (t->ground())
    {
      //
      //	Stripping a ground term gives a unique solution if there is no extension.
      //
      return new ACU_GndLhsAutomaton(symbol(),
				     matchAtTop,
				     !(collapseSymbols().empty()),
				     variableInfo.getNrProtectedVariables(),
				     t,
				     c);
    }
  VariableTerm* v = dynamic_cast<VariableTerm*>(t);
  if (v != 0)
    {
      int vi = v->getIndex();
      if (boundUniquely.contains(vi))
	{
	  //
	  //	Bound stripper variable implies a unique solution if there is no extension; for
	  //	fast matching we require that a bound stripper variable:
	  //	(1) have an element sort; and
	  //	(2) not be able to take the identity
	  //	so it strips exactly one subterm from the pattern.
	  //
	  Sort* stripperSort = v->getSort();
	  if (symbol()->sortBound(stripperSort) != 1 || symbol()->takeIdentity(stripperSort))
	    return 0;
	  return new ACU_BndVarLhsAutomaton(symbol(),
					    matchAtTop,
					    !(collapseSymbols().empty()),
					    variableInfo.getNrProtectedVariables(),
					    v,
					    c);
	}
      else
	{
	  //
	  //	Because the stripper variable is not guaranteed to be bound, many solutions
	  //	might be possible, with different values for the collector variable.
	  //
	  if (needAllCollectorSolutions)
	    return 0;
	  //
	  //	Unbound stripper variable should:
	  //	(1) not occur in condition;
	  //	(2) not occur elsewhere in lhs; and
	  //	(3) not be able to take identity.
	  //
	  int vi = v->getIndex();
	  if (variableInfo.getConditionVariables().contains(vi) ||
	      v->occursInContext().contains(vi) ||
	      symbol()->takeIdentity(v->getSort()))
	    return 0;
	  return new ACU_VarLhsAutomaton(symbol(),
					 matchAtTop,
					 !(collapseSymbols().empty()),
					 variableInfo.getNrProtectedVariables(),
					 v,
					 c);
	}
    }
  //
  //	A non-ground alien term might have multiple matches in the subject which would
  //	result in alternative values for the collector variable.
  //
  if (needAllCollectorSolutions)
    return 0;
  //
  //	Non ground stripper term should:
  //	(1) be stable;
  //	(2) not be abstracted (might match identity);
  //	(3) be greedySafe (not contain unbound bad variables); and
  //	(4) not be likely to return subproblems.
  //
  if (!(t->stable()) ||
      argArray[1 - collectorCandidate].abstractionVariableIndex != NONE ||
      !(t->greedySafe(variableInfo, boundUniquely)))
    return 0;
  NatSet local(boundUniquely);
  bool spl;
  LhsAutomaton* a = t->compileLhs(false, variableInfo, local, spl);
  if (spl)
    {
      delete a;
      return 0;
    }
  return new ACU_NGA_LhsAutomaton(symbol(),
				  matchAtTop,
				  !(collapseSymbols().empty()),
				  variableInfo.getNrProtectedVariables(),
				  a,
				  t,
				  c);
}
