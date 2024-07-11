/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2010 SRI International, Menlo Park, CA 94025, USA.

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
//	Class for rewriting equations
//
#ifndef _equation_hh_
#define _equation_hh_
#include "preEquation.hh"
#include "rhsBuilder.hh"

class Equation : public PreEquation
{
public:
  Equation(int label,
	   Term* lhs,
	   Term* rhs,
	   bool owise = false,
	   const Vector<ConditionFragment*>& condition = noCondition);
  ~Equation();

  Term* getRhs() const;
  void check();
  void preprocess();
  void compile(bool compileLhs);
  const RhsBuilder& getRhsBuilder() const;
  long fastNrVariables() const;
  void print(ostream& s) const;

  bool isOwise() const;
  void setVariant();
  void clearVariant();
  bool isVariant() const;

  void stackMachineCompile();
  Instruction* getInstructionSequence() const;

private:
  enum Flags
  {
    OWISE = 0x10,
    VARIANT = 0x20
  };

  int traceBeginTrial(DagNode* subject, RewritingContext& context) const;
  //
  //	To qualify for "fast" treatment an equation must:
  //	(1) be unconditional
  //
  //	In this case we set fast to PreEquation::nrVariables; otherwise
  //	we set fast to DEFAULT.
  //
  long fast;  // avoid the need for explicit extension instruction on x86-64
  Term* rhs;
  RhsBuilder builder;
  //
  //	For stack based execution.
  //
  Instruction* instructionSequence;
  // int nrSlots;
};

inline bool
Equation::isOwise() const
{
  return getFlag(OWISE);
}

inline bool
Equation::isVariant() const
{
  return getFlag(VARIANT);
}

inline void
Equation::setVariant()
{
  setFlags(VARIANT);
}

inline void
Equation::clearVariant()
{
  clearFlags(VARIANT);
}

inline long
Equation::fastNrVariables() const
{
  return fast;
}

inline Term*
Equation::getRhs() const
{
  return rhs;
}

inline const RhsBuilder&
Equation::getRhsBuilder() const
{
  return builder;
}

inline Instruction*
Equation::getInstructionSequence() const
{
  return instructionSequence;
}

//
//      Output function for Equation must be defined by library user.
//
ostream& operator<<(ostream& s, const Equation* equation);

#endif
