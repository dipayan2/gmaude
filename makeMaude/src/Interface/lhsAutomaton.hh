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
//	Abstract base class for left hand side automata.
//
#ifndef _lhsAutomaton_hh_
#define _lhsAutomaton_hh_

class LhsAutomaton
{
public:
  virtual ~LhsAutomaton() {}

  //
  //	If match() returns true, returnedSubproblem is set to remaining subproblem
  //	to be solved or 0 if matching is complete.
  //	If match() returns false, returnedSubproblem is not touched.
  //
  virtual bool match(DagNode* subject,
		     Substitution& solution,
		     Subproblem*& returnedSubproblem,
		     ExtensionInfo* extensionInfo = 0) = 0;

#ifdef DUMP
  virtual void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0) = 0;
#endif

};

#endif
