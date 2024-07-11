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
//	Slow version of certain Vector class template code with extensive runtime checking.
//

#include <checkedIterator.hh>

template<class T>
inline typename Vector<T>::iterator
Vector<T>::begin()
{
  return iterator(this, 0);
}

template<class T>
inline typename Vector<T>::iterator
Vector<T>::end()
{
  return iterator(this, pv.getLength());
}

#include <checkedConstIterator.hh>

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::begin() const
{
  return const_iterator(this, 0);
}

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::end() const
{
  return const_iterator(this, pv.getLength());
}
