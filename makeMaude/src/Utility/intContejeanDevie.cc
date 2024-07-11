/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2021 SRI International, Menlo Park, CA 94025, USA.

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
//	Solver based on:
//	  Evelyn Contejean and Herve Devie,
//	  "An efficient incremental algorithm for solving systems of linear diophantine equations",
//	  Information and Computation 113, pages 143-172, 1994.
//
//	We use the non-incremental version of their algorithm with the >q ordering.
//

bool
IntSystem::isZero(const IntVec& arg)
{
  for (int i : arg)
    {
      if (i != 0)
	return false;
    }
  return true;
}

int
IntSystem::scalerProduct(const IntVec& arg, int varNr)
{
  //
  //	Compute the scalar product between a vector and a column through
  //	the equations corresponding to a variable.
  //
  Assert(arg.size() == eqns.size(), "size clash");
  int sum = 0;
  IntVec::const_iterator j = arg.begin();
  for (const IntVec& v : eqns)
    {
      sum += v[varNr] * *j;
      ++j;
    }
  return sum;
}

void
IntSystem::initialize()
{
  initializeUpperBounds();
  states.resize(nrVariables);
  NatSet frozen;
  int nrEquations = eqns.size();
  for (int i = 0; i < nrVariables; ++i)
    {
      State& s = states[i];
      {
	s.assignment.resize(nrVariables);
	for (int& j : s.assignment)
	  j = 0;
	s.assignment[i] = 1;
      }
      {
	s.residue.resize(nrEquations);
	IntVec::iterator k = s.residue.begin();
	for (const IntVec& v : eqns)
	  {
	    *k = v[i];
	    ++k;
	  }
      }
      Assert(upperBounds[i] > 0, "zero upper bound");
      //
      //	We maintain the invariant that any variable that has reached its
      //	upper bound is frozen.
      //
      if (upperBounds[i] == 1)
	frozen.insert(i);
      s.frozen = frozen;
      frozen.insert(i);
    }
  current.residue.resize(nrEquations);
  stackPointer = nrVariables;
}

bool
IntSystem::findNextMinimalSolution(IntVec& solution)
{
  if (states.isNull())
    initialize();
  while (stackPointer > 0)
    {
      --stackPointer;
      State& s = states[stackPointer];
      if (isZero(s.residue))
	{
	  solutions.push_back(s.assignment);
	  solution = s.assignment;
	  return true;
	}
      else
	{
	  //
	  //	Check that each equation has a non-frozen coefficient left that will move its
	  //	residue in the right direction. Also see if we have forced assignments to a variable.
	  //
	retry:
	  IntVec::const_iterator res = s.residue.begin();
	  for (const IntVec& v : eqns)
	    {
	      int d = *res;
	      ++res;
	      bool ok = (d == 0);
	      int nfnzCount = 0;
	      int lastNfnz = NONE;
	      for (int i = 0; i < nrVariables; ++i)
		{
		  if (!(s.frozen.contains(i)))
		    {
		      int c = v[i];
		      if (c != 0)
			{
			  ++nfnzCount;
			  lastNfnz = i;
			  ok = ok || (d * c < 0);
			}
		    }
		}
	      if (!ok)
		goto skip;
	      if (nfnzCount == 1)
		{
		  //
		  //	Equation v has only a single nonzero, non-frozen coefficent left.
		  //	If residue is 0 we can freeze it; if residue is nonzero, it must
		  //	move us in the right direction and we have a forced assignment (or
		  //	faliure) for the corresponding variable.
		  //
		  if (d == 0)
                    {
                      //cout << "freezing " << lastNfnz << endl;
                      s.frozen.insert(lastNfnz);
                      goto retry;
                    }
		  //
		  //	We can force variable v.
		  //
		  //cout << "one var " << lastNfnz << endl;
		  int c = v[lastNfnz];
		  if (d % c == 0)
		    {
		      int delta = -d / c;
		      //cout << "div ok delta = " << delta << endl;
		      Assert(delta > 0, "delta = " << delta);
		      s.assignment[lastNfnz] += delta;
		      if (s.assignment[lastNfnz] <= upperBounds[lastNfnz] && minimal(s.assignment))
			{
			  //
			  //	Assignment produced a new state that satisfies upper bounds
			  //	and is minimal so it replaces the old state.
			  //
			  IntVec::iterator res2 = s.residue.begin();
			  for (const IntVec& k : eqns)
			    {
			      *res2 += delta * k[lastNfnz];
			      ++res2;
			    }
			  //cout << "forced " << lastNfnz << " by " << delta << endl;
			  s.frozen.insert(lastNfnz);
                          ++stackPointer;
			  //
			  //	Now redo from start since new state might be a solution.
			  //
			}
		    }
		  goto skip;
		}
	    }
	  //
	  //	State survived initial checks so expand it out by incrementing its
	  //	non-frozen variables. We first save the old state in current.
	  //
	  current.assignment.swap(s.assignment);
	  current.residue.swap(s.residue);
	  current.frozen.swap(s.frozen);
	  //
	  //	Now for each non-frozen variable that moves the solution in the right direction,
	  //	try to form a new state by incrementing it.
	  //
	  for (int i = 0; i < nrVariables; ++i)
	    {
	      if (!(current.frozen.contains(i)) && scalerProduct(current.residue, i) < 0)
		{
		  int& component = current.assignment[i];
		  ++component;
		  if (minimal(current.assignment))
		    {
		      //
		      //	If we are still minimal, stack the new state.
		      //
		      State& n = states[stackPointer];
		      n.assignment = current.assignment;
		      n.residue = current.residue;
		      IntVec::const_iterator from = current.residue.begin();
		      IntVec::iterator to = n.residue.begin();
		      for (const IntVec& v : eqns)
			{
			  *to = *from + v[i];
			  ++from;
			  ++to;
			}
		      //
		      //	We maintain the invariant that any variable that has reached its
		      //	upper bound is frozen.
		      //
		      if  (component == upperBounds[i])
			current.frozen.insert(i);
		      n.frozen = current.frozen;
		      ++stackPointer;
		    }
		  --component;
		  current.frozen.insert(i);  // freeze variable in remaining decendents whether minimal or not
		}
	    }
	}
    skip:
      ;
    }
  return false;
}
