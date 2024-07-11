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
// 	Abstract base class for binary symbols with attributes.
//	This class adds extra functionality needed by:
//	(1) commutative function symbols;
//	(2) idempotent function symbols; and
//	(3) function symbols with an identity.
//
#ifndef _binarySymbol_hh_
#define _binarySymbol_hh_
#include "symbol.hh"
#include "term.hh"
#include "cachedDag.hh"

class BinarySymbol : public Symbol
{
public:
  //
  //	Distinguishing arguments for permutative function symbols is not possible
  //	so only three strategies make sense.
  //
  enum PermuteStrategy
  {
    EAGER,              // [strat (1 2 0)]
    SEMI_EAGER,         // [strat (0 1 2 0)]
    LAZY                // [strat (0)]
  };

  BinarySymbol(int id, bool memoFlag, Term* identity = 0);

  void setPermuteStrategy(const Vector<int>& userStrategy);
  PermuteStrategy getPermuteStrategy() const;
  void setPermuteFrozen(const NatSet& frozen);
  void setIdentity(Term* id);
  Term* getIdentity() const;
  bool hasIdentity() const;
  bool hasUnequalLeftIdentityCollapse() const;
  bool hasUnequalRightIdentityCollapse() const;
  bool hasCyclicIdentity() const;
  DagNode* getIdentityDag();
  bool mightMatchOurIdentity(const Term* subterm) const;
  bool takeIdentity(const Sort* sort);
  bool interSymbolPass();
  void reset();
  int computeSortIndex(int index1, int index2);
  int computeMultSortIndex(int index1, int index2, int multiplicity);
  //
  //	Default definition returns true iff we don't have an identity. This must
  //	be overridden for any symbol with other behavior.
  //
  bool isStable() const;

protected:
  void commutativeSortCompletion();
  void idempotentSortCheck();
  void processIdentity();
  void leftIdentitySortCheck();
  void rightIdentitySortCheck();

private:
  enum IdentityStatus
  {
    NOT_NORMALIZED,
    IN_PROCESS,
    NORMALIZED
  };

  bool lookForCycle(Term* term, NatSet& examinedIds) const;

  PermuteStrategy permuteStrategy;
  CachedDag identityTerm;
  //
  //	These flags record if we detected a collapse from one sort to another.
  //	Collapsing to a lower sort is legal but complicates unification.
  //
  bool unequalLeftIdCollapse;
  bool unequalRightIdCollapse;
  //
  //	This flag records if we can reach find a cycle of symbols by examining identities of symbols.
  //	We need this information for breaking non-disjoint cycles during unification.
  //	Because it is potentially expensive to compute we only compute it if needed and therefore
  //	store it as an int so we can have an undecided state.
  //
  mutable int cyclicIdentity;
};

inline BinarySymbol::PermuteStrategy
BinarySymbol::getPermuteStrategy() const
{
  return permuteStrategy;
}

inline void
BinarySymbol::setIdentity(Term* id)
{
  Assert(identityTerm.getTerm() == 0, "overwriting identity for " << this);
  identityTerm.setTerm(id);
  cyclicIdentity = UNDECIDED;
}

inline Term*
BinarySymbol::getIdentity() const
{
  return identityTerm.getTerm();
}

inline bool
BinarySymbol::hasIdentity() const
{
  return identityTerm.getTerm() != 0;
}

inline bool
BinarySymbol::hasCyclicIdentity() const
{
  if (cyclicIdentity == UNDECIDED)
    {
      NatSet examinedIds;
      cyclicIdentity = lookForCycle(getIdentity(), examinedIds);
    }
  return cyclicIdentity;
}

inline bool
BinarySymbol::hasUnequalLeftIdentityCollapse() const
{
  return unequalLeftIdCollapse;
}

inline bool
BinarySymbol::hasUnequalRightIdentityCollapse() const
{
  return unequalRightIdCollapse;
}

inline bool
BinarySymbol::takeIdentity(const Sort* sort)
{
  Term* id = identityTerm.getTerm();
  return id != 0 && id->leq(sort);
}

inline DagNode*
BinarySymbol::getIdentityDag()
{
  Assert(identityTerm.getTerm() != 0, "null identity for symbol " << this);
  return identityTerm.getDag();
}

inline int
BinarySymbol::computeSortIndex(int index1, int index2)
{
  return traverse(traverse(0, index1), index2);
}

inline int
BinarySymbol::computeMultSortIndex(int index1, int index2, int multiplicity)
{
  while (multiplicity > 0)
    {
      if (multiplicity & 1)
	index1 = computeSortIndex(index1, index2);
      multiplicity >>= 1;
      index2 = computeSortIndex(index2, index2);
    }
  return index1;
}

#endif
