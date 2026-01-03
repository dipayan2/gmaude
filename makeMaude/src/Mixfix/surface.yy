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
//	Parser for Maude surface syntax.
//

%{
#include <string>
#include <stack>

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//	interface class definitions
#include "dagNode.hh"

//	core class definitions
#include "lineNumber.hh"
#include "module.hh"

//	higher class definitions
#include "narrowingSequenceSearch3.hh"

//	front end class definitions
#include "token.hh"
#include "renaming.hh"
#include "moduleExpression.hh"
#include "viewExpression.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "syntacticPreModule.hh"
#include "visibleModule.hh"
#include "syntacticView.hh"
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "global.hh"
#define PARSE_RESULT	(*parseResult)
#define CM		interpreter.getCurrentModule()
#define CV		interpreter.getCurrentView()
#include "lexerAux.hh"

Vector<Token> singleton(1);
Vector<Token> tokenSequence;
Vector<Token> lexerBubble;
Vector<Token> fragments;
Vector<Token> moduleExpr;
Vector<Token> opDescription;
Vector<Token> strategyCall;

inline void
tokensClear()
{
  tokenSequence.clear();
}

inline void
tokensStore(const Token& token)
{
  tokenSequence.append(token);
}

inline void
fragClear()
{
  fragments.clear();
}

inline void
fragStore(const Token& token)
{
  fragments.append(token);
}

Renaming* currentRenaming = 0;
SyntaxContainer* currentSyntaxContainer = 0;
SyntaxContainer* oldSyntaxContainer = 0;
bool suppressParserErrorMessage = false;

Int64 number;
Int64 number2;
int variantOptions;

static void yyerror(UserLevelRewritingContext::ParseResult* parseResult, const char *s);

void cleanUpModuleExpression();
void cleanUpParser();
void deepSelfDestructViewExpressionVector(Vector<ViewExpression*>* viewExpressions);
void missingSpace(const Token& token);
%}
%define api.pure
%parse-param {UserLevelRewritingContext::ParseResult* parseResult}

%union
{
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;
  ModuleExpression* yyModuleExpression;
  ViewExpression* yyViewExpression;
  Vector<ViewExpression*>* yyViewExpressionVector;
}

%destructor { $$->deepSelfDestruct(); } <yyModuleExpression> <yyViewExpression>
%destructor { deepSelfDestructViewExpressionVector($$); } <yyViewExpressionVector>
%{
int yylex(YYSTYPE* lvalp);
%}

%token <yyString> FILE_NAME_STRING UNINTERPRETED_STRING LATEX_STRING
/*
 *	Inert keywords: these are only recognized by lexer when in initial mode.
 */
%token <yyToken> KW_MOD KW_VIEW
%token KW_PARSE KW_NORMALIZE KW_REDUCE KW_REWRITE KW_OO
%token KW_LOOP KW_NARROW KW_XG_NARROW KW_MATCH KW_XMATCH KW_UNIFY KW_CHECK
%token KW_GET KW_VARIANTS KW_VARIANT
%token KW_EREWRITE KW_FREWRITE KW_SREWRITE KW_DSREWRITE
%token KW_CONTINUE KW_SEARCH
%token KW_SET KW_SHOW KW_ON KW_OFF KW_ON_DOT KW_OFF_DOT
%token KW_TRACE KW_BODY KW_BUILTIN KW_WHOLE KW_SELECT KW_DESELECT KW_CONDITION KW_SUBSTITUTION
%token KW_PRINT KW_GRAPH KW_MIXFIX KW_FLAT KW_ATTRIBUTE KW_NEWLINE
%token KW_WITH KW_PARENS KW_ALIASES KW_GC KW_RESOURCES KW_TIME KW_STATS KW_TIMING
%token KW_CMD KW_BREAKDOWN KW_BREAK KW_PATH KW_STATE KW_CONST
%token KW_MODULE KW_MODULES KW_VIEWS KW_ALL KW_SORTS KW_OPS2 KW_VARS
%token KW_MBS KW_EQS KW_RLS KW_STRATS KW_SDS KW_SUMMARY KW_KINDS KW_ADVISE KW_VERBOSE
%token KW_DO KW_CLEAR KW_CACHES KW_HOOKS KW_COMBINE
%token KW_PROTECT KW_EXTEND KW_GENERATE_BY KW_INCLUDE KW_EXCLUDE
%token KW_CONCEAL KW_REVEAL KW_COMPILE KW_COUNT
%token KW_DEBUG KW_IRREDUNDANT KW_FILTERED
%token KW_RESUME KW_ABORT KW_STEP  KW_WHERE KW_CREDUCE KW_SREDUCE KW_DUMP KW_PROFILE
%token KW_NUMBER KW_RAT KW_COLOR KW_IMPLIED_STEP
%token <yyInt64> SIMPLE_NUMBER
%token KW_PWD KW_CD KW_PUSHD KW_POPD KW_LS KW_LL KW_LOAD KW_SLOAD KW_QUIT
%token KW_EOF KW_TEST KW_SMT_SEARCH KW_VU_NARROW KW_FVU_NARROW KW_FOLD KW_VFOLD
%token KW_DESUGARED KW_PROCESSED KW_FRONTIER KW_MOST KW_GENERAL

/*
 *	Start keywords: signal end of mixfix statement if following '.'.
 */
%token <yyToken> KW_ENDM KW_IMPORT KW_ENDV
%token <yyToken> KW_SORT KW_SUBSORT KW_OP KW_OPS KW_MSGS KW_VAR KW_CLASS KW_SUBCLASS KW_DSTRAT
%token <yyToken> KW_MB KW_CMB KW_EQ KW_CEQ KW_RL KW_CRL KW_SD KW_CSD KW_ATTR

/*
 *	Mid keywords: need to be recognized in the middle of mixfix syntax.
 */
%token <yyToken> KW_IS KW_FROM
%token <yyToken> KW_ARROW KW_ARROW2 KW_PARTIAL KW_IF KW_ASSIGN
%type <yyToken> ':' '=' '(' ')' '.' '<' '[' ']' ',' '|' '@'

/*
 *	Module expression keywords.
 */
%token <yyToken> KW_LABEL KW_TO KW_COLON2
%left <yyToken> '+'
%left <yyToken> '*'
%type <yyToken> '{' '}'

/*
 *	Attribute keywords need to be recognized when parsing attributes.
 */
%token <yyToken> KW_ASSOC KW_COMM KW_ID KW_IDEM KW_ITER KW_PCONST
%token <yyToken> KW_LEFT KW_RIGHT KW_PREC KW_GATHER KW_METADATA KW_STRAT KW_ASTRAT KW_POLY
%token <yyToken> KW_MEMO KW_FROZEN KW_CTOR KW_LATEX KW_SPECIAL KW_CONFIG KW_OBJ KW_MSG KW_PORTAL
%token <yyToken> KW_DITTO KW_FORMAT
%token <yyToken> KW_ID_HOOK KW_OP_HOOK KW_TERM_HOOK

/*
 *	Command keywords need to be recognized when parsing commands.
 */
%token <yyToken> KW_IN KW_FILTER KW_DELAY

/*
 *	Special tokens.
 */
%token <yyToken> IDENTIFIER NUMERIC_ID ENDS_IN_DOT

/*
 *	This is a dummy token that is never passed by the lexer but by
 *	giving this as an alternative we force the parser to lookahead
 *	one token and allow the lexer to grab a bubble.
 */
%token FORCE_LOOKAHEAD

/*
 *	These tokens are returned by the lexer when an actual end-of-file is handled.
 *	CHANGE_FILE means we resumed reading the previous file.
 *	It is used to prevent parsing modules/commands across file boundries.
 *	END_OF_INPUT  means there are no more characters to read.
 */
%token CHANGE_FILE END_OF_INPUT

/*
 *	Nonterminals that return tokens.
 */
%type <yyToken> stratName attributeName
%type <yyToken> token endsInDot badType
%type <yyToken> tokenBarColon
%type <yyToken> tokenBarDot
%type <yyToken> cTokenBarIn
%type <yyToken> cTokenBarLeftIn cTokenBarDotNumber cTokenBarDotRight
%type <yyToken> cSimpleTokenBarDot
%type <yyToken> cTokenBarDotCommaRight cTokenBarDotCommaNumber
%type <yyToken> cTokenBarOpenLeftIn cTokenBarDotCommaClose cOptionToken cTokenBarDotOptionToken
%type <yyToken> sortName sortToken sortDot tokenDot

/*
 *	Nonterminals that return Interpreter::SearchKind.
 */
%type <yySearchKind> search
/*
 *	Nonterminals that return bool.
 */
%type <yyBool> polarityDot select match optDebug optIrredundant conceal exclude arrow typeName1 typeName1Dot
/*
 *	Nonterminals that return int.
 */
%type <yyInt64> optNumber optOptions optionsList option
/*
 *	Nonterminals that return ImportMode.
 */
%type <yyImportMode> importMode
/*
 *	Nonterminals that return Flags.
 */
%type <yyFlags> traceOption
/*
 *	Nonterminals that return PrintFlags.
 */
%type <yyPrintFlags> printOption
/*
 *	Nonterminals that return ModuleExpression*.
 */
%type <yyModuleExpression> moduleExprDot moduleExpr moduleExpr2 moduleExpr3
%type <yyModuleExpression> renameExpr instantExpr parenExpr
/*
 *	Nonterminals that return ViewExpression*.
 */
%type <yyViewExpression> viewExpr
/*
 *	Nonterminals that return Vector<ViewExpression*>*.
 */
%type <yyViewExpressionVector> instantArgs

%start top

%%

top		:	item { YYACCEPT; }
		|	END_OF_INPUT
			{
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
		|	error END_OF_INPUT
			{
			  //
			  //	This is the back stop if we see a END_OF_INPUT when we're part way
			  //	through the item, and justifies suppressing the yyerror() message.
			  //
			  IssueWarning(LineNumber(lineNumber) << ": unexpected end-of-input.");
			  YYABORT;
			}
		|	error CHANGE_FILE
			{
			  //
			  //	This is the back stop if we see a CHANGE_FILE when we're part way
			  //	through an item, and justifies suppressing the yyerror() message.
			  //
			  IssueWarning(LineNumber(lineNumber) << ": unexpected end-of-file.");
			  YYABORT;
			}
		;

item		:	module
		|	view
		|	directive
		|	command
		|	CHANGE_FILE
			{
			  //
			  //	Benign change of file; reenable yyerror() message.
			  //
			  suppressParserErrorMessage = false;
			}
		;

/*
 *	Directives.
 */
directive	:	KW_IN		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
		|	KW_LOAD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			}
		|	KW_SLOAD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr) &&
			      !directoryManager.alreadySeen(directory, fileName))
			    includeFile(directory, fileName, true, lineNr);
			}
		|	KW_PWD
			{
			  cout << directoryManager.getCwd() << '\n';
			}
		|	KW_CD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  string directory;
			  directoryManager.realPath($3, directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			}
		|	KW_PUSHD	{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  string directory;
			  directoryManager.realPath($3, directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			}
		|	KW_POPD
			{
			  const char* path = directoryManager.popd();
			  if (path != 0)
			    cout << path << '\n';
			  else
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": popd failed");
			    }
			}
		|	KW_LS		{ lexerStringMode(); }
			UNINTERPRETED_STRING
			{
			  returnValueDump = system((string("ls") + $3).c_str());
			}
		|	KW_LL		{ lexerStringMode(); }
			UNINTERPRETED_STRING
			{
			  returnValueDump = system((string("ls -l") + $3).c_str());
			}
		|	KW_QUIT
			{
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
		|	KW_EOF
			{
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
		;
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

/*
 *	Module expressions.
 */
moduleExprDot	:	tokenBarDot expectedDot
                        {
                          $$ =  new ModuleExpression($1);
                        }
		|	endsInDot '.'
                        {
                          $$ = new ModuleExpression($1);
                        }
		|	parenExpr expectedDot
		|	renameExpr expectedDot
		|	instantExpr expectedDot
		|	moduleExpr '+' moduleExprDot
			{
			  if ($3)
			    $$ = new ModuleExpression($1, $3);
			  else
			    {
			      IssueWarning(&($2) << ": missing module expression after " << QUOTE($2) << ".");
			      $$ = $1;
			    }
			}
		|	tokenDot
			{
			  $$ = new ModuleExpression($1);
			}
		|	'.'
			{
			  $$ = 0;
			}
		;

moduleExpr	:	moduleExpr2
		|	moduleExpr '+' moduleExpr
			{
			  $$ = new ModuleExpression($1, $3);
			}
		;

moduleExpr2	:	moduleExpr3
		|	renameExpr
		;

moduleExpr3	:	parenExpr
		|	instantExpr
		|	token
		        {
                          $$ = new ModuleExpression($1);
                        }

		;
		
renameExpr	:	moduleExpr2 '*' renaming
			{
			  $$ = new ModuleExpression($1, currentRenaming);
			  currentRenaming = 0;
			}
		;

instantExpr	:	moduleExpr3 '{' instantArgs '}'
			{
			  $$ = new ModuleExpression($1, *($3));
			  delete $3;
			}
		;

parenExpr	:	'(' moduleExpr ')'
			{
			  $$ = $2;
			}
		;

/*
 *	View expressions (parameters are treated as uninstantiated views for syntax purposes).
 */
viewExpr	:	viewExpr '{' instantArgs '}'
			{
			  $$ = new ViewExpression($1, *($3));
			  delete $3;
			}
		|	token
			{
			  $$ = new ViewExpression($1);
			}
		;

instantArgs	:	instantArgs ',' viewExpr
			{
			  $1->append($3);
			  $$ = $1;
			}
		|	viewExpr
			{
			  Vector<ViewExpression*>* t =  new Vector<ViewExpression*>();
			  t->append($1);
			  $$ = t;
			}
		;

/*
 *	Renamings.
 */
renaming	:	'('
			{
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
			renaming2  /* must succeed so we can restore currentSyntaxContainer */
			{
			  currentSyntaxContainer = oldSyntaxContainer;
			}
			')'
		;

renaming2	:	mappingList
		|	error
		;

mappingList	:	mappingList ',' mapping
		|	mapping
		;

mapping		:	KW_SORT sortName KW_TO sortName
			{
			  currentRenaming->addSortMapping($2, $4);
			}
		|	KW_LABEL token KW_TO token
			{
			  currentRenaming->addLabelMapping($2, $4);
			}
		|	KW_OP			{ lexBubble(BAR_COLON | BAR_TO, 1); }
			fromSpec KW_TO		{ lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
			toAttributes		{}
		|	KW_STRAT stratName	{ currentRenaming->addStratMapping($2); }
			fromStratSpec
			KW_TO stratName 	{ currentRenaming->addStratTarget($6); }
		|	KW_CLASS sortName KW_TO sortName
			{
			  currentRenaming->addClassMapping($2, $4);
			}
		|	KW_ATTR token
			{
			  currentRenaming->addAttrMapping($2);
			}
			fromAttrSpec KW_TO token
			{
			  currentRenaming->addAttrTarget($6);
			}
		|	KW_MSG
			{
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
			fromSpec KW_TO
			{
			  lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1);
			}
			toAttributes
			{
			  currentRenaming->markAsMsg();
			}
		;

/*
 *	The ':' alternative forces lookahead which allows the lexer to grab the bubble.
 */
fromSpec	:	':'			{ Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
			typeList arrow typeName {}
		|				{ Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
		;

fromAttrSpec	:	':' typeName1
			{
			  currentRenaming->addAttrType($2 ? tokenSequence : singleton);
			}
		|	
		;

fromStratSpec	:	stratSignature
		|
		;

/*
 *	The '[' alternative forces lookahead which allows the lexer to grab the bubble.
 */
toAttributes	:	'['			{ Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
			toAttributeList ']'	{}
		|				{ Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
		;

toAttributeList	:	toAttributeList toAttribute
		|	toAttribute
		;

toAttribute	:	KW_PREC IDENTIFIER	{ currentRenaming->setPrec($2); }
		|	KW_PREC			{ IssueWarning(&($1) << ": prec attribute without value in operator mapping."); }
		|	KW_GATHER '('		{ tokensClear(); }
			idList ')'		{ currentRenaming->setGather(tokenSequence); }
		|	KW_GATHER		{ IssueWarning(&($1) << ": gather attribute without pattern in operator mapping."); }
		|	KW_FORMAT '('		{ tokensClear(); }
			idList ')'		{ currentRenaming->setFormat(tokenSequence); }
		|	KW_FORMAT		{ IssueWarning(&($1) << ": format attribute without specification in operator mapping."); }
		|	KW_LATEX '('		{ lexerLatexMode(); }
			LATEX_STRING ')'	{ currentRenaming->setLatexMacro($4); }
		|	KW_LATEX     		{ IssueWarning(&($1) << ": latex attribute without latex code in operator mapping."); }
		;

/*
 *	Views.
 */
view		:	KW_VIEW			{ lexerIdMode(); }
			token
			{
			  fileTable.beginModule($1, $3);
			  interpreter.setCurrentView(new SyntacticView($3, &interpreter));
			  currentSyntaxContainer = CV;
			}
			parameters KW_FROM moduleExpr
			KW_TO moduleExpr
			expectedIs viewDecList KW_ENDV
			{
			  CV->addFrom($7);
			  CV->addTo($9);
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  bool displacedView = interpreter.insertView(($3).code(), CV);
			  CV->finishView();
			  if (displacedView)
			    interpreter.cleanCaches();
			}
		;

viewDecList	:	viewDecList viewDeclaration
		|	{}
		;

skipStrayArrow	:	KW_ARROW
			{
			  IssueWarning(&($1) << ": skipping " << QUOTE("->") << " in variable declaration.");
			}
		|	{}
		;

viewDeclaration	:	KW_SORT sortName KW_TO sortDot
			{
			  CV->addSortMapping($2, $4);
			}
		|	KW_VAR varNameList ':' skipStrayArrow typeDot {}
		|	KW_OP
			{
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
			viewEndOpMap
		|	KW_STRAT viewStratMap
		|	KW_CLASS sortName KW_TO sortDot
			{
			  CV->addClassMapping($2, $4);
			}
		|	KW_ATTR token
			{
			  CV->addAttrMapping($2);
			}
			fromAttrSpec KW_TO token expectedDot
			{
			  CV->addAttrTarget($6);
			}
		|	KW_MSG
			{
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
			endMsgMap
		|	error '.'
		|	error END_OF_INPUT
			{
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-input while parsing view " << QUOTE(CV) << ".");
			  YYABORT;  // rely on the caller to clear up view database and lexer
			}
		|	error CHANGE_FILE
			{
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-file while parsing view " << QUOTE(CV) << ".");
			  YYABORT;  // rely on the caller to clear up view database and lexer
			}
		;

sortDot		:	sortName expectedDot		{ $$ = $1; }
		|	tokenDot
		;

viewEndOpMap	:	':'
			{
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
			typeList arrow typeName KW_TO
			{
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
		|	KW_TO
			{
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  if (lexerBubble[0].code() == Token::encode("term"))
			    {
			      //
			      //	Op->term mapping.
			      //
			      CV->addOpTermMapping(opDescription, lexerBubble);
			    }
			  else
			    {
			      //
			      //	Generic op->op mapping.
			      //
			      Token::peelParens(opDescription);  // remove any enclosing parens from op name
			      CV->addOpMapping(opDescription);
			      Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			      CV->addOpTarget(lexerBubble);
			    }
			}
		;

endMsgMap	:	':'
			{
			  //
			  //	Specific msg->msg mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
			typeList arrow typeName KW_TO
			{
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			  CV->markAsMsg();
			}
		|	KW_TO
			{
			  //
			  //	At this point we don't know if we have an msg->term mapping
			  //	or a generic msg->msg mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  if (lexerBubble[0].code() == Token::encode("term"))
			    {
			      //
			      //	msg->term mapping.
			      //
			      CV->addOpTermMapping(opDescription, lexerBubble, true);
			    }
			  else
			    {
			      //
			      //	Generic msg->msg mapping.
			      //
			      Token::peelParens(opDescription);  // remove any enclosing parens from op name
			      CV->addOpMapping(opDescription);
			      Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			      CV->addOpTarget(lexerBubble);
			      CV->markAsMsg();
			    }
			}
		;

strategyCall	:	stratName
			{
			  strategyCall.resize(1);
			  strategyCall[0] = $1;
			}
		|	stratName '('			{ lexBubble(BAR_RIGHT_PAREN, 1); }
			')'
			{
			  // Adds the stratName and parentheses to the lexer bubble
			  int bubbleSize = lexerBubble.length();
			  strategyCall.resize(bubbleSize + 3);
			  strategyCall[0] = $1;
			  strategyCall[1] = $2;
			  for (int i = 0; i < bubbleSize; i++)
			    strategyCall[2 + i] = lexerBubble[i];
			  strategyCall[bubbleSize + 2] = $4;
			}

viewStratMap	:	stratName
			{
			  CV->addStratMapping($1);
			}
			stratSignature KW_TO stratName '.'
			{
			  CV->addStratTarget($5);
			}
		|	strategyCall KW_TO
			{
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  if (lexerBubble[0].code() == Token::encode("expr"))
			    {
			      //
			      //	Strat->expr mapping.
			      //
			      CV->addStratExprMapping(strategyCall, lexerBubble);
			    }
			  else if (strategyCall.length() == 1 && lexerBubble.length() == 1)
			    {
			      //
			      //	Generic strat->strat mapping.
			      //
			      CV->addStratMapping(strategyCall[0]);
			      CV->addStratTarget(lexerBubble[0]);
			    }
			  else
			    {
			      IssueWarning(&(strategyCall[0]) << ": bad syntax for strategy mapping.");
			    }
			}
		;

endBubble	:	'.'		{}
		|	tokenDot	{ lexerBubble.append($1); }
		;

parenBubble	:	'(' 		{ lexBubble(BAR_RIGHT_PAREN, 1); }
			')'		{}
		;

/*
 *	Modules and theories.
 */
module		:	KW_MOD		{ lexerIdMode(); }
			token
			{
			  interpreter.setCurrentModule(new SyntacticPreModule($1, $3, &interpreter));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule($1, $3);
			}
			parameters expectedIs decList KW_ENDM
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule($8);
			}
		;

dot		:	'.'		{}
		|	tokenDot	{ tokensStore($1); }
		;

parameters	:	'{' parameterList '}' {}
		|	{}
		;

parameterList	:	parameterList ',' parameter
		|	parameter
		;

parameter	:	token colon2 moduleExpr
			{
			  currentSyntaxContainer->addParameter2($1, $3);
			}
		;

colon2		:	KW_COLON2 {}
		|	':'
			{
			  IssueWarning(&($1) << ": saw " << QUOTE(':') << " instead of " << QUOTE("::") << " in parameter declaration.");
			}
		;

badType		:	ENDS_IN_DOT
			{
			  singleton[0].dropChar($1);
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  $$ = $1;  // needed for line number
			}
		;

typeDot		:	typeName expectedDot
		|	badType {}
		;

decList		:	decList declaration
		|	{}
		;

declaration	:	KW_IMPORT moduleExprDot
			{
			  if ($2)
			    CM->addImport($1, $2);
			  else
			    {
			      IssueWarning(&($1) << ": missing module expression after " << QUOTE($1) << ".");
			    }
			}

		|	KW_SORT			{ tokensClear(); }
			endSortNameList		{ CM->addSortDecl(tokenSequence); }

		|	KW_SUBSORT		{ tokensClear(); }
			endSubsortList		{ CM->addSubsortDecl(tokenSequence); }

		|	KW_OP			{ lexBubble(BAR_COLON, 1); }
			':'			{ Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
			domainRangeAttr		{}

		|	KW_OPS opNameList ':' domainRangeAttr {}

		|	KW_VAR varNameList ':' skipStrayArrow typeDot {}

		|	KW_MB			{ lexBubble($1, BAR_COLON, 1); }
			':'			{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble	       	{ CM->addStatement(lexerBubble); }

		|	KW_CMB			{ lexBubble($1, BAR_COLON, 1);  }
			':'			{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble		{ CM->addStatement(lexerBubble); }

		|	KW_EQ			{ lexBubble($1, BAR_EQUALS, 1); }
			'='			{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble	  	{ CM->addStatement(lexerBubble); }

		|	KW_CEQ			{ lexBubble($1, BAR_EQUALS, 1); }
			'='			{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble	  	{ CM->addStatement(lexerBubble); }

		|	KW_RL			{ lexBubble($1, BAR_ARROW2, 1); }
			KW_ARROW2		{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble		{ CM->addStatement(lexerBubble); }

		|	KW_CRL			{ lexBubble($1, BAR_ARROW2, 1); }
			KW_ARROW2		{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble	    	{ CM->addStatement(lexerBubble); }

		|	KW_SD			{ lexBubble($1, BAR_ASSIGN, 1); }
			KW_ASSIGN		{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble		{ CM->addStatement(lexerBubble); }

		|	KW_CSD			{ lexBubble($1, BAR_ASSIGN, 1); }
			KW_ASSIGN		{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble	    	{ CM->addStatement(lexerBubble); }

		|	stratDeclKeyword	{ tokensClear(); }
			stratIdList
			stratSignature
			stratAttributes
			dot			{}

		|	KW_MSG			{ lexBubble(BAR_COLON, 1); }
			':'			{ Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
			domainRangeAttr		{
						  CM->endMsg();
						}

		|	KW_MSGS opNameList ':' domainRangeAttr
			{
			  CM->endMsg();
			}

		|	KW_CLASS classDecl

		|	KW_SUBCLASS		{ tokensClear(); }
			endSubsortList		{ CM->addSubclassDecl(tokenSequence); }
		
		|	error '.'
		        {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeDeclsConsistent();
			}
		|	error END_OF_INPUT
			{
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-input while parsing module " << QUOTE(CM) << ".");
			  YYABORT;  // rely on the caller to clear up module database and lexer
			}
		|	error CHANGE_FILE
			{
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-file while parsing module " << QUOTE(CM) << ".");
			  YYABORT;  // rely on the caller to clear up module database and lexer
			}
		;

classDecl	:	sortName
			{
			  CM->addClassDecl($1);
			}
			classDef
			{
			}
		|	tokenDot
			{
			  CM->addClassDecl($1);
			}
		;

classDef	:	expectedDot
		|	'|' cPairList finalPair {}
		;

finalPair	:	attributeName ':' typeName1Dot
			{
			  CM->addAttributePair($1, $3, $3 ? tokenSequence : singleton);
			}
		|	attributeName typeName1Dot
			{
			  CM->addAttributePairNoColon($1, $2, $2 ? tokenSequence : singleton);
			}
		;

cPairList	:	cPairList cPair ','
		|
		;

cPair		:	attributeName ':' typeName1
			{
			  CM->addAttributePair($1, $3, $3 ? tokenSequence : singleton);
			}
		|	attributeName typeName1
			{
			  CM->addAttributePairNoColon($1, $2, $2 ? tokenSequence : singleton);
			}
		;

varNameList	:	varNameList tokenBarColon	{ currentSyntaxContainer->addVarDecl($2); }
		|	tokenBarColon			{ currentSyntaxContainer->addVarDecl($1); }
		;

opNameList	:	opNameList simpleOpName
		|	simpleOpName
		;

simpleOpName	:	tokenBarColon		{ singleton[0] = $1; CM->addOpDecl(singleton); }
		|	parenBubble		{ CM->addOpDecl(lexerBubble); }
		;

domainRangeAttr	:	typeName typeList dra2
		|	rangeAttr
		|	badType
			{
			  IssueWarning(&($1) << ": missing " << QUOTE("->") << " in constant declaration.");
			}
		;

stratDeclKeyword : 	KW_STRAT | KW_DSTRAT ;

stratIdList	: 	stratIdList stratId
		|	stratId
		;

stratId		:	stratName	{ CM->addStratDecl($1); }
		;

stratSignature	:	'@'
			typeName
		|	':'
			typeList
			'@'
			typeName
		;

stratAttributes :	'[' stratAttrList ']'	{}
		|	{}
		;

stratAttrList 	:	KW_METADATA IDENTIFIER
			{
			  CM->setMetadata($2);
			}
		;

skipStrayColon 	:	':'
			{
			  IssueWarning(&($1) << ": skipping stray " << QUOTE(":") << " in operator declaration.");
			}
		|	{}
		;

dra2		:	skipStrayColon rangeAttr
		|	'.'
			{
			  IssueWarning(&($1) << ": missing " << QUOTE("->") << " in operator declaration.");
			}
		|	badType
			{
			  IssueWarning(&($1) << ": missing " << QUOTE("->") << " in operator declaration.");
			}
		;

rangeAttr	:	arrow typeAttr
			{
			  if ($1)
			    CM->convertSortsToKinds();
			}
		;

typeAttr	:	typeName attributes expectedDot
		|	badType {}
		;

arrow		:	KW_ARROW      		{ $$ = false; }
		|	KW_PARTIAL	       	{ $$ = true; }
		;

typeList	:	typeList typeName
		|	{}
		;

typeName1	:	sortName
			{
			  singleton[0] = $1;
			  $$ = false;
			}
		|	kind
			{
			  $$ = true;
			}
		;
		
typeName1Dot	:	sortName expectedDot
			{
			  singleton[0] = $1;
			  $$ = false;
			}
		|	tokenDot
			{
			  singleton[0] = $1;
			  $$ = false;
			}
		|	kind expectedDot
			{
			  $$ = true;
			}
		;

kind		:	'['			{ tokensClear(); }
			sortNames ']'
		;

typeName	:	sortName
			{
			  singleton[0] = $1;
			  currentSyntaxContainer->addType(false, singleton);
			}
		|	'['			{ tokensClear(); }
			sortNames ']'
			{
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
		;

sortNames	:	sortNames ',' sortName		{ tokensStore($3); }
		|	sortName			{ tokensStore($1); }
		;

attributes	:	'[' attributeList ']'	{}
		|	{}
		;

attributeList	:	attributeList attribute
		|	attribute
		;

idKeyword	:	KW_ID
			{
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
		|	KW_LEFT KW_ID
			{
			  CM->setFlag(SymbolType::LEFT_ID);
			}
		|	KW_RIGHT KW_ID
			{
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
		;

attribute	:	KW_ASSOC		
			{
			  CM->setFlag(SymbolType::ASSOC);
			}
		|	KW_COMM
			{
			  CM->setFlag(SymbolType::COMM);
			}
		|	idKeyword		{ lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
			identity		{ CM->setIdentity(lexerBubble); }
		|	KW_IDEM
			{
			  CM->setFlag(SymbolType::IDEM);
			}
		|	KW_ITER
			{
			  CM->setFlag(SymbolType::ITER);
			}
		|	KW_PREC IDENTIFIER	{ CM->setPrec($2); }
		|	KW_PREC			{ IssueWarning(&($1) << ": prec attribute without value in operator declaration."); }
		|	KW_GATHER '('		{ tokensClear(); }
			idList ')'		{ CM->setGather(tokenSequence); }
		|	KW_GATHER 		{ IssueWarning(&($1) << ": gather attribute without pattern in operator declaration."); }
		|	KW_FORMAT '('		{ tokensClear(); }
			idList ')'		{ CM->setFormat(tokenSequence); }
		|	KW_FORMAT 		{ IssueWarning(&($1) << ": format attribute without specification in operator declaration."); }
		|	KW_STRAT '('		{ tokensClear(); }
			idList ')'		{ CM->setStrat(tokenSequence); }
		|	KW_STRAT 		{ IssueWarning(&($1) << ": strat attribute without strategy in operator declaration."); }
		|	KW_ASTRAT '('		{ tokensClear(); }
			idList ')'		{ CM->setStrat(tokenSequence); }
		|	KW_ASTRAT		{ IssueWarning(&($1) << ": strategy attribute without strategy in operator declaration."); }
		|	KW_POLY '('		{ tokensClear(); }
			idList ')'		{ CM->setPoly(tokenSequence); }
		|	KW_POLY			{ IssueWarning(&($1) << ": poly attribute without specification in operator declaration."); }
		|	KW_MEMO
			{
			  CM->setFlag(SymbolType::MEMO);
			}
		|	KW_CTOR
			{
			  CM->setFlag(SymbolType::CTOR);
			}
		|	KW_FROZEN
			{
			  tokensClear();
			  CM->setFrozen(tokenSequence);
			}
		|	KW_FROZEN '('		{ tokensClear(); }
			idList ')'		{ CM->setFrozen(tokenSequence); }
		|	KW_CONFIG
			{
			  CM->setFlag(SymbolType::CONFIG);
			}
		|	KW_OBJ
			{
			  CM->setFlag(SymbolType::OBJECT);
			}
		|	KW_MSG
			{
			  CM->setFlag(SymbolType::MESSAGE);
			}
		|	KW_PORTAL
			{
			  CM->setFlag(SymbolType::PORTAL);
			}
		|	KW_METADATA IDENTIFIER
			{
			  CM->setMetadata($2);
			}
		|	KW_LATEX '('		{ lexerLatexMode(); }
			LATEX_STRING ')'	{ CM->setLatexMacro($4); }
		|	KW_LATEX		{ IssueWarning(&($1) << ": latex attribute without latex code in operator declaration."); }
		|	KW_SPECIAL '(' hookList ')'	{}
		|	KW_DITTO
			{
			  CM->setFlag(SymbolType::DITTO);
			}
		|	KW_PCONST
			{
			  CM->setFlag(SymbolType::PCONST);
			}
		;

/*
 *	The ony point of this rule is to force a one token lookahead and allow the lexer to grab the
 *	bubble corresponding to the identity. We never see a FORCE_LOOKAHEAD token.
 */
identity	:	FORCE_LOOKAHEAD
		|	{}
		;

idList		:	idList IDENTIFIER	{ tokensStore($2); }
		|	IDENTIFIER		{ tokensStore($1); }
		;

hookList	:	hookList hook		{}
		|	hook	 		{}
		;

hook		:	KW_ID_HOOK token		{ tokensClear(); CM->addHook(SyntacticPreModule::ID_HOOK, $2, tokenSequence); }
		|	KW_ID_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::ID_HOOK, $2, lexerBubble); }
		|	KW_OP_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::OP_HOOK, $2, lexerBubble); }
		|	KW_TERM_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::TERM_HOOK, $2, lexerBubble); }
		;

/*
 *	Recovery from missing tokens
 */
expectedIs	:	KW_IS {}
		|
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing " << QUOTE("is") << " keyword.");
			}
		;

expectedDot	:	'.' {}
		|
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
		;

/*
 *	Sort lists.
 */
sortNameList	:	sortNameList sortName	{ tokensStore($2); }
		|	sortName     		{ tokensStore($1); }
		;

		
endSortNameList :	tokenDot		{ tokensStore($1); }
	    	|	sortNameList dot
		;

/*
 *	Subsort lists.
 */
subsortList	:	subsortList sortNameList '<'	{ tokensStore($3); }
		|	sortNameList '<'		{ tokensStore($2); }
	    	;

endSubsortList	:	subsortList endSortNameList
	       	;

/*
 *	Sort names
 */
sortName	:	sortNameFrag
			{
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  $$ = t;
			}
		;

sortNameFrag	:	sortToken		{ fragStore($1); }
		|	sortNameFrag '{'	{ fragStore($2); }
			sortNameFrags '}'	{ fragStore($5); }
		;

sortNameFrags	:	sortNameFrags ','	{ fragStore($2); }
			sortNameFrag		{}
		|	sortNameFrag		{}
		;
		
tokenDot	:	ENDS_IN_DOT
			{
			  Token t;
			  t.dropChar($1);
			  missingSpace(t);
			  $$ = t;
			}

/*
 *	Sets of tokens returned in <ID_MODE>.
 */

/*
 *	Single token sort names are the most restricted general class of token.
 *	We exclude
 *	  '(' ')'
 *	for all token types to avoid parentheses balancing issues
 *	  ':' KW_ARROW KW_PARTIAL
 *	to avoid ambiguity in operator declarations
 *	  ':' '@'
 *	to avoid ambiguity in strategy declarations
 *	  '<'
 *	to avoid ambiguity in subsort declarations
 *	  ':' KW_COLON2 KW_ASSIGN KW_ID
 *	because colons are not allowed in sort names (full variable name confusion)
 *	  '.' ENDS_IN_DOT
 *	because periods are not allowed sort names (metalevel constant confusion)
 *	  '[' ',' ']'
 *	to avoid ambiguity in kinds
 *	  '{' ',' '}'
 *	to avoid ambiguity in parameterized sort names
 */
sortToken	:	IDENTIFIER
 
 		|	KW_IMPORT | KW_SORT | KW_SUBSORT | KW_OP | KW_OPS | KW_VAR
		|	KW_STRAT | KW_DSTRAT
		|	KW_CLASS | KW_SUBCLASS | KW_ATTR | KW_MSG | KW_MSGS
		|	KW_MB | KW_CMB | KW_EQ | KW_CEQ | KW_RL | KW_CRL
		|	KW_SD | KW_CSD
		|	KW_ENDM | KW_ENDV

		|	KW_IF | KW_IS | KW_FROM | KW_TO | KW_LABEL

		|	KW_ASSOC | KW_COMM | KW_IDEM | KW_ITER | KW_LEFT | KW_RIGHT
		|	KW_PREC | KW_GATHER | KW_ASTRAT | KW_POLY | KW_MEMO | KW_CTOR
		|	KW_LATEX | KW_SPECIAL | KW_FROZEN | KW_METADATA
		|	KW_CONFIG | KW_OBJ | KW_DITTO | KW_FORMAT
		|	KW_ID_HOOK | KW_OP_HOOK | KW_TERM_HOOK | KW_PCONST
		
		|	'=' | '|' | '+' | '*' |	KW_ARROW2
		;

/*
 *	An unrestricted token adds back these excluded tokens except  '(' ')'
 */
token		:	sortToken | ENDS_IN_DOT | KW_ID 
		|	':' | '@' | '<' | ',' | '.' | '[' | ']' | '{' | '}'
		|	KW_ARROW | KW_PARTIAL | KW_COLON2 | KW_ASSIGN
		;

/*
 *	A strategy name excludes
 *	  ':' '@'
 *	to avoid ambiguity in strategy declarations
 */
stratName	:	sortToken | ENDS_IN_DOT | KW_ID 
		|	'<' | ',' | '.' | '[' | ']' | '{' | '}'
		|	KW_ARROW | KW_PARTIAL | KW_COLON2 | KW_ASSIGN
		;

/*
 *	An attribute name excludes
 *	  ',' '[' ']' '{' '}'
 *	to avoid the formation of illegal operator names
 */
attributeName	:	sortToken | ENDS_IN_DOT | KW_ID 
		|	':' | '@' | '<' | '.'
		|	KW_ARROW | KW_PARTIAL | KW_COLON2 | KW_ASSIGN
		;

/*
 *	A tokenBarColon (used for variable names and single token operator names) excludes
 *	  ':'
 *	to avoid ambiguity in variable declarations and ops declarations.
 */
tokenBarColon	:	sortToken | ENDS_IN_DOT | KW_ID 
		|	'@' | '<' | ',' | '.' | '[' | ']' | '{' | '}'
		|	KW_ARROW | KW_PARTIAL | KW_COLON2 | KW_ASSIGN
		;

/*
 *	For parsing modules expressions we split off
 *	  '.' ENDS_IN_DOT
 *	into a separate class so that M. can be overparsed as M . rather than M. .
 *	and a bare . without a terminating dot is not overparsed as module name.
 */
tokenBarDot	:	sortToken | KW_ID 
		|	':' | '@' | '<' | ',' | '[' | ']' | '{' | '}'
		|	KW_ARROW | KW_PARTIAL | KW_COLON2 | KW_ASSIGN
		;

endsInDot	:	'.' | ENDS_IN_DOT
		;
/*

    This file is part of the Maude 3 interpreter.

    Copyright 1997-2024 SRI International, Menlo Park, CA 94025, USA.

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

/*
 *	Commands.
 */
command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1); }
			endBubble
			{
			  interpreter.setCurrentModule(lexerBubble);
			}
		|	KW_DUMP			{ lexBubble(END_COMMAND, 1); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
		|	KW_PARSE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}

		|	KW_CREDUCE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}

		|	KW_SREDUCE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}

		|	optDebug KW_REDUCE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, $1);
			}

		|	optDebug KW_REWRITE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, $1);
			}
		|	optDebug KW_EREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, $1);
			}
		|	optDebug KW_FREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, $1);
			}
		|	optDebug KW_SREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, $1);
			}
		|	optDebug KW_DSREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, $1, true);
			}

		|	KW_CHECK
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}

		|	optDebug search
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, $2, $1);
			}
		|	optDebug optOptions KW_VU_NARROW
			{
			  variantOptions = $2;
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;			  
			}
			optionsNumbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, Interpreter::VU_NARROW, $1, variantOptions);
			}
		|	match
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, $1, number);
			}
		|	optIrredundant KW_UNIFY
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number, $1);
			}
		|	optDebug KW_VARIANT KW_UNIFY
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, false, $1);
			}
		|	optDebug KW_FILTERED KW_VARIANT KW_UNIFY
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, true, $1);
			}
		|	optDebug KW_VARIANT KW_MATCH
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantMatch(lexerBubble, number, $1);
			}

		|	optDebug KW_GET optIrredundant KW_VARIANTS
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, $3, $1);
			}
		|	optDebug KW_CONTINUE optNumber '.'
			{
			  interpreter.cont($3, $1);
			}
		|	KW_TEST 
			{
			  //
			  //	test is a generic command to call code with a term for development purposes.
			  //
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.test(lexerBubble);
			    //interpreter.newNarrow(lexerBubble);

			}
		|	KW_LOOP
			{
			  lexerCmdMode();
			  moduleExpr.clear();
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
		|	parenBubble
			{
			  moduleExpr.clear();
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
		|	KW_TRACE select		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.traceSelect($2);
			}
		|	KW_TRACE exclude		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.traceExclude($2);
			}
		|	KW_BREAK select		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.breakSelect($2);
			}
		|	KW_PRINT conceal		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.printConceal($2);
			}
		|	KW_DO KW_CLEAR KW_MEMO	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->getFlatSignature()->clearMemo();
			}
/*
 *	Commands to show interpreter state.
 */
		|	KW_SHOW kw_module	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showPreModule();
			}
		|	KW_SHOW KW_ALL		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
		|	KW_SHOW KW_DESUGARED	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(false);
			}
		|	KW_SHOW KW_VIEW		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
		|	KW_SHOW KW_PROCESSED KW_VIEW	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showProcessedView();
			}
		|	KW_SHOW KW_MODULES '.'
			{
			  interpreter.showModules(true);
			}
		|	KW_SHOW KW_VIEWS '.'
			{
			  interpreter.showViews(true);
			}
		|	KW_SHOW KW_SORTS	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
		|	KW_SHOW KW_OPS2		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
		|	KW_SHOW KW_VARS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
		|	KW_SHOW KW_MBS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
		|	KW_SHOW KW_EQS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
		|	KW_SHOW KW_RLS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
		|	KW_SHOW KW_STRATS	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showStrats();
			}
		|	KW_SHOW KW_SDS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSds();
			}
		|	KW_SHOW KW_SUMMARY	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
		|	KW_SHOW KW_KINDS	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
		|	KW_SHOW KW_PATH SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPath($3, true);
			}
		|	KW_SHOW KW_PATH KW_STATE SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPath($4, false);
			}
		|	KW_SHOW KW_PATH KW_LABEL SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPathLabels($4);
			}
		|	KW_SHOW KW_SEARCH KW_GRAPH '.'
			{
			  interpreter.showSearchGraph();
			}
		|	KW_SHOW KW_PROFILE	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
		|	KW_SHOW KW_FRONTIER KW_STATE '.'
			{
			  interpreter.showFrontierStates();
			}
		|	KW_SHOW KW_MOST KW_GENERAL KW_STATE '.'
			{
			  interpreter.showMostGeneralStates();
			}
/*
 *	Commands to set interpreter state variables.
 */
		|	KW_SET KW_SHOW KW_ADVISE polarityDot
			{
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : $4;
			}
		|	KW_SET KW_SHOW KW_STATS polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_STATS, $4);
			}
		|	KW_SET KW_SHOW KW_LOOP KW_STATS polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, $5);
			}
		|	KW_SET KW_SHOW KW_TIMING polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_TIMING, $4);
			}
		|	KW_SET KW_SHOW KW_BREAKDOWN polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, $4);
			}
		|	KW_SET KW_SHOW KW_LOOP KW_TIMING polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, $5);
			}
		|	KW_SET KW_SHOW KW_CMD polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, $4);
			}
		|	KW_SET KW_SHOW KW_GC polarityDot
			{
			  MemoryCell::setShowGC($4);
			}
		|	KW_SET KW_SHOW KW_RESOURCES polarityDot
			{
			  MemoryCell::setShowResources($4);
			}
		|	KW_SET KW_PRINT printOption polarityDot
			{
			  interpreter.setPrintFlag($3, $4);
			}
		|	KW_SET KW_PRINT KW_ATTRIBUTE polarityDot
			{
			  // a general flag, not a print flag, to activate print attribute
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, $4);
			}
		|	KW_SET KW_PRINT KW_ATTRIBUTE KW_NEWLINE polarityDot
			{
			  // a general flag, not a print flag, to print a newline after print attribute message
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, $5);
			}
		|	KW_SET KW_TRACE traceOption polarityDot
			{
			  interpreter.setFlag($3, $4);
			}
		|	KW_SET KW_BREAK polarityDot
			{
			  interpreter.setFlag(Interpreter::BREAK, $3);
			}
		|	KW_SET importMode		{ lexerCmdMode(); }
			cSimpleTokenBarDot		{ lexerInitialMode(); }
			polarityDot
			{
			  interpreter.setAutoImport($2, $4, $6);
			}
		|	KW_SET KW_OO KW_INCLUDE		{ lexerCmdMode(); }
			cSimpleTokenBarDot		{ lexerInitialMode(); }
			polarityDot
			{
			  interpreter.setOoInclude($5, $7);
			}
		|	KW_SET KW_VERBOSE polarityDot
			{
			  globalVerboseFlag = $3;
			}
		|	KW_SET KW_CLEAR KW_MEMO polarityDot
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, $4);
			}
		|	KW_SET KW_CLEAR KW_RLS polarityDot
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, $4);
			}
		|	KW_SET KW_COMPILE KW_COUNT polarityDot
			{
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, $4);
			}
		|	KW_SET KW_PROFILE polarityDot
			{
			  interpreter.setFlag(Interpreter::PROFILE, $3);
			}
		|	KW_SET KW_CLEAR KW_PROFILE polarityDot
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, $4);
			}
		|	KW_SET KW_CLEAR kw_module KW_CACHES polarityDot
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_CACHES, $5);
			}
/*
 *	Debugger mode commands
 */
		|	KW_RESUME '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
		|	KW_ABORT '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
		|	KW_STEP '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
		|	KW_IMPLIED_STEP
			{
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
		|	KW_WHERE '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
/*
 *	OBJ3 legacy cruft.
 */
		|	KW_SET KW_GC KW_SHOW polarityDot
			{
			  MemoryCell::setShowGC($4);
			}
		|	KW_SET KW_STATS polarityDot
			{
			  interpreter.setFlag(Interpreter::SHOW_STATS, $3);
			}
/*
 *	Error recovery.
 */
		|	error			{ lexerInitialMode(); }
			'.'
		;
/*
 *	Allow mod as an abbreviation for module (can't do this is lexer because of mod ... endm for system modules).
 */
kw_module	:	KW_MODULE
		|	KW_MOD
		;

/*
 *	Options
 */
printOption	:	KW_MIXFIX		{ $$ = PrintSettings::PRINT_MIXFIX; }
		|	KW_FLAT			{ $$ = PrintSettings::PRINT_FLAT; }
		|	KW_WITH KW_ALIASES	{ $$ = PrintSettings::PRINT_WITH_ALIASES; }
		|	KW_WITH KW_PARENS	{ $$ = PrintSettings::PRINT_WITH_PARENS; }
		|	KW_GRAPH		{ $$ = PrintSettings::PRINT_GRAPH; }
		|	KW_CONCEAL		{ $$ = PrintSettings::PRINT_CONCEAL; }
		|	KW_NUMBER		{ $$ = PrintSettings::PRINT_NUMBER; }
		|	KW_RAT			{ $$ = PrintSettings::PRINT_RAT; }
		|	KW_COLOR		{ $$ = PrintSettings::PRINT_COLOR; }
		|	KW_FORMAT		{ $$ = PrintSettings::PRINT_FORMAT; }
		|	KW_CONST KW_WITH KW_SORTS	{ $$ = PrintSettings::PRINT_DISAMBIG_CONST; }
		|	KW_LABEL KW_ATTRIBUTE	{ $$ = PrintSettings::PRINT_LABEL_ATTRIBUTE; }
		|	KW_HOOKS 		{ $$ = PrintSettings::PRINT_HOOKS; }
		|	KW_COMBINE KW_VARS	{ $$ = PrintSettings::PRINT_COMBINE_VARS; }
		|	KW_LATEX   		{ $$ = PrintSettings::PRINT_LATEX; }
		;

traceOption	:				{ $$ = Interpreter::TRACE; }
		|	KW_CONDITION		{ $$ = Interpreter::TRACE_CONDITION; }
		|	KW_WHOLE		{ $$ = Interpreter::TRACE_WHOLE; }
		|	KW_SUBSTITUTION		{ $$ = Interpreter::TRACE_SUBSTITUTION; }
		|	KW_SELECT		{ $$ = Interpreter::TRACE_SELECT; }
		|	KW_MBS			{ $$ = Interpreter::TRACE_MB; }
		|	KW_EQS			{ $$ = Interpreter::TRACE_EQ; }
		|	KW_RLS			{ $$ = Interpreter::TRACE_RL; }
		|	KW_SDS			{ $$ = Interpreter::TRACE_SD; }
		|	KW_REWRITE		{ $$ = Interpreter::TRACE_REWRITE; }
		|	KW_BODY			{ $$ = Interpreter::TRACE_BODY; }
		|	KW_BUILTIN		{ $$ = Interpreter::TRACE_BUILTIN; }
		;

polarityDot	:	KW_ON '.'		{ $$ = true; }
		|	KW_OFF '.'		{ $$ = false; }
		|	KW_ON_DOT
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing space between " << QUOTE("on") << " and period.");
			  $$ = true;
			}
		|	KW_OFF_DOT
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing space between " << QUOTE("off") << " and period.");
			  $$ = false;
			}
		;

select		:	KW_SELECT		{ $$ = true; }
		|	KW_DESELECT		{ $$ = false; }
		;

exclude		:	KW_EXCLUDE	       	{ $$ = true; }
		|	KW_INCLUDE	       	{ $$ = false; }
		;

conceal		:	KW_CONCEAL		{ $$ = true; }
		|	KW_REVEAL		{ $$ = false; }
		;
/*
 *	Return what sort of search we should do; vu-narrow is handle separately because it has two sets of options.
 */
search		:	KW_NARROW		{ $$ = Interpreter::NARROW; }
		|	KW_XG_NARROW		{ $$ = Interpreter::XG_NARROW; }
		|	KW_SEARCH		{ $$ = Interpreter::SEARCH; }
		|	KW_SMT_SEARCH		{ $$ = Interpreter::SMT_SEARCH; }
		|	KW_FVU_NARROW		{ $$ = Interpreter::FVU_NARROW; }
		;

match		:	KW_XMATCH		{ $$ = true; }
		|	KW_MATCH		{ $$ = false; }
		;

optDebug       	:	KW_DEBUG 	       	{ $$ = true; }
		|	       			{ $$ = false; }
		;

optIrredundant	:	KW_IRREDUNDANT		{ $$ = true; }
		|	       			{ $$ = false; }
		;

optNumber	:	SIMPLE_NUMBER	        { $$ = $1; }
		|				{ $$ = NONE; }
		;

optOptions	:	'{' optionsList '}'	{ $$ = $2; }
		|	    			{ $$ = 0; }
		;

optionsList	:	option			{ $$ = $1; }
		|	optionsList ',' option  { $$ = $1 | $3; }
		;

option		:	KW_FOLD			{ $$ = NarrowingSequenceSearch3::FOLD; }
		|	KW_VFOLD		{ $$ = NarrowingSequenceSearch3::VFOLD; }
		|	KW_PATH			{ $$ = NarrowingSequenceSearch3::KEEP_PATHS; }
		;

importMode	:	KW_PROTECT		{ $$ = ImportModule::PROTECTING; }
		|	KW_EXTEND		{ $$ = ImportModule::EXTENDING; }
		|	KW_GENERATE_BY		{ $$ = ImportModule::GENERATED_BY; }
		|	KW_INCLUDE		{ $$ = ImportModule::INCLUDING; }
		;
/*
 *	Optional module expression followed by term followed by dot.
 *	{"in" <module expression> ":"} <term> "."
 *	<module expression> is a (possibly empty) bubble not containing ':' or '.'
 *	<term> is a (non-empty) bubble not containing '.' except as first token
 */

moduleAndTerm	:	initialEndBubble
		|	cTokenBarIn		{ lexBubble($1, END_COMMAND, 0); }
			endBubble
		;

inEnd		:	':'			{ moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
			endBubble
		|	endBubble
		;

/*
 *	Optional [number] followed by optional module expression, followed
 *	by term, followed by dot.
 *	{"[" <number> "]"} {"in" <module expression> ":"} <term> "."
 */

numberModuleTerm
		:	'['			{ lexSave($1); }
			numberModuleTerm1
		|	initialEndBubble
		|	cTokenBarLeftIn		{ lexBubble($1, END_COMMAND, 0);  }
			endBubble
		;

numberModuleTerm1
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numberModuleTerm2
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

numberModuleTerm2
		:	']'			{ number = Token::codeToInt64(lexerBubble[1].code()); }
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Optional [number],  [, number] or [number, number] followed by optional
 *	module expression, followed by term, followed by dot.
 *	{"[" { {<number>} , } <number> "]"} {"in" <module expression> ":"} <term> "."
 */


/*
 *	Seen <command>; looking for "{", "[", "in", or start of term.
 */
optionsNumbersModuleTerm
		:	'{'			{ lexSave($1); }
			optionsNumbersModuleTerm1
		|	'['			{ lexSave($1); }
			numbersModuleTerm1
		|	initialEndBubble
		|	cTokenBarOpenLeftIn	{ lexBubble($1, END_COMMAND, 0); }
			endBubble
		;

optionsNumbersModuleTerm1
		:	KW_FILTER
			{
			  lexContinueSave($1);
			  variantOptions |= VariantUnificationProblem::FILTER_VARIANT_UNIFIERS;
			}
			optionsNumbersModuleTerm2
		|	KW_DELAY
			{
			  lexContinueSave($1);
			  variantOptions |= VariantSearch::IRREDUNDANT_MODE;
			}
			optionsNumbersModuleTerm2
		|	cTokenBarDotOptionToken	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;
		
optionsNumbersModuleTerm2
		:	'}'
			numbersModuleTerm
		|	','			{ lexContinueSave($1); }
			optionsNumbersModuleTerm1
		|	cTokenBarDotCommaClose	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command>; looking for "[", "in", or start of term.
 */
numbersModuleTerm
		:	'['			{ lexSave($1); }
			numbersModuleTerm1
		|	initialEndBubble
		|	cTokenBarLeftIn		{ lexBubble($1, END_COMMAND, 0); }
			endBubble
		;

/*
 *	Seen <command> "["; looking for <number>, ",", continuation of
 *	term or "." to end command.
 */
numbersModuleTerm1
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm2
		|	','			{ lexContinueSave($1); }
			numbersModuleTerm5
		|	cTokenBarDotCommaNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number>; looking for "]", ",",
 *	continuation of term or "." to end command.
 */
numbersModuleTerm2
		:	']'			{ number = Token::codeToInt64(lexerBubble[1].code()); }
			moduleAndTerm
		|	','			{ lexContinueSave($1); }
			numbersModuleTerm3
		|	cTokenBarDotCommaRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number> ","; looking for <number>,
 *	continuation of term or "." to end command.
 */
numbersModuleTerm3
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm4
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number> "," <number>; looking for "]",
 *	continuation of term or "." to end command.
 */
numbersModuleTerm4
		:	']'
			{
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  tokensClear();
			}
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" ","; looking for <number>, continuation of
 *	term or "." to end command. 
 */
numbersModuleTerm5
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm6
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" "," <number>; looking for "]", continuation
 *	of term or "." to end command. 
 */
numbersModuleTerm6
		:	']'			{ number2 = Token::codeToInt64(lexerBubble[2].code()); }
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

miscEndBubble	:	'('			{ lexContinueBubble($1, END_COMMAND, 0, 1); }
			endBubble
		|	endBubble
		;

/*
 *	Handles ( <bubble> )
 *	        in <bubble> :
 *		foo.
 */
initialEndBubble
		:	'('			{ lexBubble($1, END_COMMAND, 1, 1); }
			endBubble
		|	KW_IN			{ lexBubble($1, BAR_COLON | END_COMMAND, 0); }
			inEnd
		|	ENDS_IN_DOT
			{
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar($1);
			  missingSpace(lexerBubble[0]);
			}
		;

/*
 *	Command mode token types.
 */
cTokenBarIn	:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '}' | '[' | ']' | ':' | '.' | ','
		;

cTokenBarLeftIn	:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '}' | ']' | ':' | '.' | ','
		;

cTokenBarOpenLeftIn
		:	cOptionToken | IDENTIFIER | NUMERIC_ID | '}' | ']' | ':' | '.' | ','
		;

cTokenBarDotNumber
		:	cOptionToken | IDENTIFIER | '{' | '}' | '[' | ']' | KW_IN | ':' | ','
		;

cTokenBarDotRight
		:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '}' | '[' | KW_IN | ':' | ','
		;

cTokenBarDotCommaNumber
		:	cOptionToken | IDENTIFIER | '{' | '}' | '[' | ']' | KW_IN | ':'
		;

cTokenBarDotCommaRight
		:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '}' | '[' | KW_IN | ':'
		;

cTokenBarDotCommaClose
		:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '[' | ']' | KW_IN | ':'
		;

cTokenBarDotOptionToken
		:	IDENTIFIER | NUMERIC_ID | '{' | '}' | '[' | ']' | KW_IN | ':' | ','
		;

/*
 *	Selections are lists of operator names.
 */
opSelect	:	cOpNameList endSelect
		|	badSelect
		;

endSelect	:	'.'		{}
		|	badSelect
		;

badSelect	:	ENDS_IN_DOT
			{
			  singleton[0].dropChar($1);
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}

cOpNameList	:	cOpNameList cSimpleOpName
		|	cSimpleOpName
		;

cSimpleOpName	:	cSimpleTokenBarDot
			{
			  singleton[0] = $1;
			  interpreter.addSelected(singleton);
			}
		|	parenBubble
			{
			  interpreter.addSelected(lexerBubble);
			}
		;

cSimpleTokenBarDot
		:	cOptionToken | IDENTIFIER | NUMERIC_ID | '{' | '}' | '[' | ']' | KW_IN | ':' | ','
		;

cOptionToken	:	KW_FILTER
		|	KW_DELAY
		;
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

%%

static void
yyerror(UserLevelRewritingContext::ParseResult* /*parseResult*/, const char *s)
{
  if (!suppressParserErrorMessage)
    IssueWarning(LineNumber(lineNumber) << ": " << s);
}

void
cleanUpModuleExpression()
{
  //cout << "cleanUpModuleExpression() called" << endl;
  //
  //	Delete pieces of a partly built module expression.
  //
  delete currentRenaming;
  currentRenaming = 0;
}

void
cleanUpParser()
{
  suppressParserErrorMessage = false;
  interpreter.makeClean(lineNumber);
}

void
deepSelfDestructViewExpressionVector(Vector<ViewExpression*>* viewExpressions)
{
  for (ViewExpression* v : *viewExpressions)
    v->deepSelfDestruct();
  delete viewExpressions;
}

void
missingSpace(const Token& token)
{
  IssueWarning(LineNumber(token.lineNumber()) << ": missing space between " <<
	       QUOTE(token) << " and period.");
}
