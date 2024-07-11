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
//      Class for streambuf with automatic line wrapping.
//
//	The basic idea is when we see a legal place to insert a \n
//	we put subsequent chars into a pending buffer until we known
//	whether to use this place.
//
//	Decisions on legal places are complicated by "strings",
//	ESC ... m sequences and backquotes.
//
//	Decisions on whether we need to insert a \n depend on width
//	calculations which are complicated by tabs and ESC ... m sequences.
//
//	This class now has a second function: to block using waitFunction
//	to avoid writing to a terminal that is being used by a child for
//	a nonblocking getLine.
//
#ifndef _autoWrapBuf_hh_
#define _autoWrapBuf_hh_
#include <string>

class AutoWrapBuffer : public std::streambuf
{
  NO_COPYING(AutoWrapBuffer);

public:
  typedef void (*WaitFunction)();

  AutoWrapBuffer(streambuf* outputBuffer,
		 int lineWidth,
		 bool respectFlush,
		 WaitFunction waitFunction);

  void setLineWidth(int lineWidth);
  void resetCursorPosition();
  //
  //	Member functions we need to override from streambuf to get
  //	hold of raw characters.
  //
  int sync();
  int overflow(int ch);

private:
  enum Options
  {
    LEFT_MARGIN = 4,
    RIGHT_MARGIN = 1
  };

  void handleChar(int ch);
  void handleEscapeSequenceChar(int ch);
  int nextTabPosition(int pos);
  void dumpBuffer();
  void decideOnBreak();
  void legalPositionToBreak();

  streambuf* outputBuffer;
  int lineWidth;		// width of output device
  bool respectFlush;
  WaitFunction waitFunction;

  int cursorPosition;		// cursor position if we were to print pendingBuffer
  bool seenBackQuote;		// last char was a `
  bool seenBackSlash;		// inside a "string" and last char was an unescaped
  				// backslash
  bool inString;		// inside a "string"
  bool inEscape;		// inside an ESC sequence
  string pendingBuffer;
  int pendingWidth;		// number of chars in buffer excluding \t and ESC sequences
};

inline void
AutoWrapBuffer::setLineWidth(int lineWidth)
{
  AutoWrapBuffer::lineWidth = lineWidth;
}

inline int
AutoWrapBuffer::nextTabPosition(int pos)
{
  return (pos + 8) & ~7;
}

inline void
AutoWrapBuffer::resetCursorPosition()
{
  //
  //	We need this to account for newline characters implicit in user input.
  //
  cursorPosition = 0;
}

#endif
