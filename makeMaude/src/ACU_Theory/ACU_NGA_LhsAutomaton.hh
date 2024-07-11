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
//      Class for ACU non-ground alien stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_NGA_LhsAutomaton_hh_
#define _ACU_NGA_LhsAutomaton_hh_
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_NGA_LhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_NGA_LhsAutomaton);

public:
  ACU_NGA_LhsAutomaton(ACU_Symbol* symbol,
		       bool matchAtTop,
		       bool collapsePossible,
		       int nrVariables,
		       LhsAutomaton* stripperAutomaton,
		       Term* stripperTerm,
		       VariableTerm* collector);
  ~ACU_NGA_LhsAutomaton();
  //
  //	Standard LhsAutomaton operations.
  //
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  //
  //	The stripper automaton strips off one argument; it must be
  //	non-ground and stable.
  //
  LhsAutomaton* const stripperAutomaton;
  Term* const stripperTerm;
};

#endif
