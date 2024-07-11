/*

    This file is part of the Maude 3 interpreter.

    Copyright 2023-2024 SRI International, Menlo Park, CA 94025, USA.

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
//      Class to generate Latex from Maude internal data structures.
//
#ifndef _maudeLatexBuffer_hh_
#define _maudeLatexBuffer_hh_
#include <stack>
#include "interpreter.hh"

class MaudeLatexBuffer
{
  NO_COPYING(MaudeLatexBuffer);

public:
  MaudeLatexBuffer(const char* fileName);
  ~MaudeLatexBuffer();

  ostream& getStream();

  void generateBanner(const char* date, const char* time, time_t seconds);
  void generateHeading(const char* message);
  void generateModuleName(NamedEntity* module);
  void generateState(DagNode* stateDag, const char* message = nullptr);
  //
  //	Functions to start latex for commands.
  //
  void generateCommand(bool showCommand, const string& command, Term* subject);
  void generateCommand(bool showCommand,
		       const string& command,
		       DagNode* subject,
		       Int64 number = NONE,
		       Int64 number2 = NONE,
		       StrategyExpression* strategy = 0);
  
  void generateUnify(bool showCommand,
		     bool irredundant,
		     Vector<Term*> lhs,
		     Vector<Term*> rhs,
		     int64_t limit);
  void generateMatch(bool showCommand,
		     bool withExtension,
		     Term* pattern,
		     DagNode* subject,
		     const Vector<ConditionFragment*>& condition,
		     int64_t limit);
  void generateGetVariants(bool showCommand,
			   bool irredundant,
			   DagNode* dag,
			   Vector<Term*> constraint,
			   int64_t limit,
			   bool debug);
  void generateVariantUnify(bool showCommand,
			    bool filtered,
			    Vector<Term*> lhs,
			    Vector<Term*> rhs,
			    Vector<Term*> constraint,
			    int64_t limit,
			    bool debug);
  void generateVariantMatch(bool showCommand,
			    Vector<Term*> lhs,
			    Vector<Term*> rhs,
			    Vector<Term*> constraint,
			    int64_t limit,
			    bool debug);

  void generateSearch(bool showCommand,
		      Interpreter::SearchKind searchKind,
		      const Vector<DagNode*>& subjects,
		      int searchType,
		      Term* target,
		      const Vector<ConditionFragment*>& condition,
		      int variantFlags,
		      int64_t limit,
		      int64_t depth,
		      bool debug);
  void generateContinue(bool showCommand, Int64 limit, bool debug = false);
  void generateShow(bool showCommand, const string& command, NamedEntity* module);
  void generateShow(bool showCommand, const string& command, View* module);
  void generateShow(bool showCommand, const string& command);
  void generateLoopTokens(bool showCommand, const Vector<Token>& tokens);
  //
  //	Functions to print results.
  //
  void generateSolutionNr(int64_t solutionNr, int stateNr = NONE);
  void generateStats(RewritingContext& context,
		     int64_t cpuTime,
		     int64_t realTime,
		     bool showTiming,
		     bool showBreakdown,
		     int64_t nrStates = NONE);
  void generateResult(Term* result);
  void generateResult(const string& message, DagNode* result);
  void generateResult(RewritingContext& context,
		      DagNode* result,
		      int64_t cpuTime,
		      int64_t realTime,
		      bool showStats,
		      bool showTiming,
		      bool showBreakdown);
  void generateNonResult(RewritingContext& context,
			 const string& message,
			 int64_t cpuTime,
			 int64_t realTime,
			 bool showStats,
			 bool showTiming,
			 bool showBreakdown);
  void generateSmtResult(SMT_RewriteSequenceSearch* state,
			 int64_t solutionNr,
			 int64_t cpuTime,
			 int64_t realTime,
			 bool showStats,
			 bool showTiming,
			 bool showBreakdown);
  void generateSearchNonResult(RewriteSequenceSearch* state,
			       const string& message,
			       int64_t cpuTime,
			       int64_t realTime,
			       bool showStats,
			       bool showTiming,
			       bool showBreakdown);
  void generateSearchResult(RewriteSequenceSearch* state,
			    int64_t solutionNr,
			    int64_t cpuTime,
			    int64_t realTime,
			    bool showStats,
			    bool showTiming,
			    bool showBreakdown);
  void generateDecisionTime(int64_t cpuTime, int64_t realTime);
  void generateNonResult(const string& message);
  void generateResult(const string& message, int64_t solutionNr);
  void generateMatchResult(MatchSearchState* state, int64_t matchNr);
  void generateBubbleResult(const Vector<int>& bubble);
  //
  //	Commands for interogating a search graph.
  //
  void generateSearchPath(const RewriteSequenceSearch* graph,
			  const Vector<int>& steps,
			  int stateNr,
			  bool showCommand,
			  bool showRule);
  void generateNarrowingSearchPath(const NarrowingSequenceSearch3* state,
				   const Vector<int>& steps,
				   int stateNr,
				   bool showCommand,
				   bool showRule);
  void generateSearchPathLabels(const RewriteSequenceSearch* graph,
				const Vector<int>& steps,
				int stateNr,
				bool showCommand);
  void generateSearchGraph(const RewriteSequenceSearch* graph, bool showCommand);
  void generateStateSet(bool showCommand,
			const char* command,
			const Vector<DagNode*>& firstPart,
			bool highlight,
			const Vector<DagNode*>& secondPart,
			const char* emptyMessage);
  //
  //	Three different representations of substitutions.
  //
  void generateSubstitution(const Substitution& substitution,
			    const VariableInfo& varInfo,
			    const NatSet& ignoredIndices = NatSet());
  void generateSubstitution(const Substitution& substitution,
			    const NarrowingVariableInfo& varInfo);
  void generateSubstitution(const Vector<DagNode*>& substitution,
			    const NarrowingVariableInfo& variableInfo);

  void generateVariant(const Vector<DagNode*>& variant, const NarrowingVariableInfo& variableInfo);

  void generateCompoundSubstitution(const Substitution& substitution,
				    const VariableInfo& variableInfo,
				    const NarrowingVariableInfo& narrowingVariableInfo,
				    Module* m);
  
  void generateWarning(const char* message);
  void generateAdvisory(const char* message);
  void cleanUp();

private:
  void commentTerm(Term* t);
  void commentDagNode(DagNode* d);
  void startComment();
  void endComment();
  void generateType(Sort* sort);
  void generateModifiers(Module* module, int64_t  number = NONE, int64_t  number2 = NONE);

  
  ofstream output;
  PrintSettings commentSettings;  // for terms and dagnodes printed in comments
  stack<string> pendingCloseStack;
  bool needNewline;
};

inline ostream&
MaudeLatexBuffer::getStream()
{
  return output;
}

inline void
MaudeLatexBuffer::cleanUp()
{
  output << pendingCloseStack.top();
  pendingCloseStack.pop();
}

inline void
MaudeLatexBuffer::generateHeading(const char* message)
{
  output << "\\par\\maudeResponse{" << message << "}\n";
}

inline void
MaudeLatexBuffer::commentTerm(Term* t)
{
  MixfixModule::prettyPrint(output, t, commentSettings, false);
}

inline void
MaudeLatexBuffer::commentDagNode(DagNode* d)
{
  MixfixModule::prettyPrint(output, d, commentSettings, false);
}

inline void
MaudeLatexBuffer::startComment()
{
  output << "%\n%  ";
}

inline void
MaudeLatexBuffer::endComment()
{
  output << " .\n%\n";
}

#endif
