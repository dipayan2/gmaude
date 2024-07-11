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
//      Abstract base class for maps from symbols to symbols.
//
#ifndef _symbolMap_hh_
#define _symbolMap_hh_

class SymbolMap
{
public:
  //
  //	For safety since this class is intended to be derived from.
  //
  virtual ~SymbolMap() {}
  //
  //	If translate() returns 0, this indicates that the symbol will
  //	be translated by a term an that the entire construction will be
  //	handled by calling makeTranslatedTerm() the orginal term.
  //
  virtual Symbol* translate(Symbol* symbol) = 0;
  virtual Term* translateTerm(const Term* term) = 0;
  //
  //	This functions returns the symbol that has the same name and
  //	and domain/range sort names as that of its argument, but in
  //	the target module (into which translations are being made).
  //
  virtual Symbol* findTargetVersionOfSymbol(Symbol* symbol) = 0;
  //
  //	This carries a flag say if variable indices should be preserved during a deepCopy()
  //	Usually no, since statement compilation relies on the variable indices being
  //	UNDEFINED. But for certain module operations we do want them preserved.
  //
  virtual bool preserveVariableIndices() = 0;
};

#endif
