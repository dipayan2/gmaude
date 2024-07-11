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
//	Code for tracing trails of conditional mbs/eqs/rls.
//
int UserLevelRewritingContext::trialCount = 0;

int
UserLevelRewritingContext::traceBeginEqTrial(DagNode* subject, const Equation* equation)
{
  Assert(equation != 0, "null equation in trial");
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileEqConditionStart(equation);
    }
  if (handleDebug(subject, equation))
    return UNDEFINED;
  if (!localTraceFlag || !(interpreter.getFlag(Interpreter::TRACE_EQ)) || dontTrace(subject, equation))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n' << equation << '\n';
  if (interpreter.getFlag(Interpreter::TRACE_SUBSTITUTION))
    printSubstitution(*this, *equation);
  return trialCount;
}

int
UserLevelRewritingContext::traceBeginRuleTrial(DagNode* subject, const Rule* rule)
{
  Assert(rule != 0, "null rule in trial");
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileRlConditionStart(rule);
    }
  if (handleDebug(subject, rule))
    return UNDEFINED;
  if (!localTraceFlag || !(interpreter.getFlag(Interpreter::TRACE_RL)) || dontTrace(subject, rule))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n' << rule << '\n';
  if (interpreter.getFlag(Interpreter::TRACE_SUBSTITUTION))
    printSubstitution(*this, *rule);
  return trialCount;
}

int
UserLevelRewritingContext::traceBeginScTrial(DagNode* subject, const SortConstraint* sc)
{
  Assert(sc != 0, "null membership axiom in trial");
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileMbConditionStart(sc);
    }
  if (handleDebug(subject, sc))
    return UNDEFINED;
  if (!localTraceFlag || !(interpreter.getFlag(Interpreter::TRACE_MB)) || dontTrace(subject, sc))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n' << sc << '\n';
  if (interpreter.getFlag(Interpreter::TRACE_SUBSTITUTION))
    printSubstitution(*this, *sc);
  return trialCount;
}

int
UserLevelRewritingContext::traceBeginSdTrial(DagNode* subject, const StrategyDefinition* sdef)
{
  Assert(sdef != 0, "null strategy definition in trial");
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
        safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileSdConditionStart(sdef);
    }
  if (handleDebug(subject, sdef))
    return UNDEFINED;
  if (!localTraceFlag || !(interpreter.getFlag(Interpreter::TRACE_SD)) || dontTrace(subject, sdef))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n' << sdef << '\n';
  if (interpreter.getFlag(Interpreter::TRACE_SUBSTITUTION))
    printSubstitution(*this, *sdef);
  return trialCount;
}

void
UserLevelRewritingContext::traceEndTrial(int trialRef, bool success)
{
  if (!abortFlag && trialRef != UNDEFINED)
    cout << header << (success ? "success #" : "failure #") << trialRef << '\n';
}

void
UserLevelRewritingContext::traceExhausted(int trialRef)
{
  if (!abortFlag && trialRef != UNDEFINED)
    cout << header << "exhausted (#" << trialRef << ")\n";
}

void
UserLevelRewritingContext::traceBeginFragment(int trialRef,
					      const PreEquation* preEquation,
					      int fragmentIndex,
					      bool firstAttempt)
{
  if (abortFlag || trialRef == UNDEFINED)
    return;
  ConditionFragment* fragment = (preEquation->getCondition())[fragmentIndex];
  cout << header;
  if (!firstAttempt)
    cout << "re-";
  cout << "solving condition fragment" << '\n' << fragment << '\n';
}

void
UserLevelRewritingContext::traceEndFragment(int trialRef,
					    const PreEquation* preEquation,
					    int fragmentIndex,
					    bool success)
{
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      //
      //	Before we profile a fragment we need to check
      //	if it belongs to a module and is therefore profileable.
      //	PreEquations (Patterns actually) used for conditions
      //	in commands and descent functions have a null module.
      //
      if (Module* module = preEquation->getModule())
	{
	  safeCast(ProfileModule*, module)->
	    profileFragment(preEquation, fragmentIndex, success);
	}
    }
  //
  //	If trialRef == UNDEFINED it means we're not tracing whatever
  //	owns the condition that owns this condition fragment.
  //
  if (abortFlag || trialRef == UNDEFINED)
    return;

  ConditionFragment* fragment = (preEquation->getCondition())[fragmentIndex];
  if (success)
    {
      cout << header << "success for condition fragment" << '\n' << fragment << '\n';
      if (interpreter.getFlag(Interpreter::TRACE_SUBSTITUTION))
	printSubstitution(*this, *preEquation);
    }
  else
    cout << header << "failure for condition fragment" << '\n' << fragment << '\n';
}
