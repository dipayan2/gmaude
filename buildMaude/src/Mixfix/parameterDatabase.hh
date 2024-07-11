/*

    This file is part of the Maude 3 interpreter.

    Copyright 2019 SRI International, Menlo Park, CA 94025, USA.

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
//      Class to hold database of parameters.
//
//	This is just a pool of Parameter objects that we make and reuse as needed.
//	A Parameter is just a NamedEntity that can be passed as an Argument in
//	instantiations, and that we can test that it is a Parameter, rather than a View.
//
#ifndef _parameterDatabase_hh_
#define _parameterDatabase_hh_
#include <map>
#include "parameter.hh"

class ParameterDatabase
{
  NO_COPYING(ParameterDatabase);

public:
  ParameterDatabase(){}
  ~ParameterDatabase();

  Parameter* getParameter(int parameterName);

private:
  typedef map<int, Parameter*> ParameterMap;

  ParameterMap parameterMap;
};

#endif
