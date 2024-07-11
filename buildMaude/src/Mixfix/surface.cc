/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 27 "surface.yy"

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

#line 164 "surface.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "surface.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FILE_NAME_STRING = 3,           /* FILE_NAME_STRING  */
  YYSYMBOL_UNINTERPRETED_STRING = 4,       /* UNINTERPRETED_STRING  */
  YYSYMBOL_LATEX_STRING = 5,               /* LATEX_STRING  */
  YYSYMBOL_KW_MOD = 6,                     /* KW_MOD  */
  YYSYMBOL_KW_VIEW = 7,                    /* KW_VIEW  */
  YYSYMBOL_KW_PARSE = 8,                   /* KW_PARSE  */
  YYSYMBOL_KW_NORMALIZE = 9,               /* KW_NORMALIZE  */
  YYSYMBOL_KW_REDUCE = 10,                 /* KW_REDUCE  */
  YYSYMBOL_KW_REWRITE = 11,                /* KW_REWRITE  */
  YYSYMBOL_KW_OO = 12,                     /* KW_OO  */
  YYSYMBOL_KW_LOOP = 13,                   /* KW_LOOP  */
  YYSYMBOL_KW_NARROW = 14,                 /* KW_NARROW  */
  YYSYMBOL_KW_XG_NARROW = 15,              /* KW_XG_NARROW  */
  YYSYMBOL_KW_MATCH = 16,                  /* KW_MATCH  */
  YYSYMBOL_KW_XMATCH = 17,                 /* KW_XMATCH  */
  YYSYMBOL_KW_UNIFY = 18,                  /* KW_UNIFY  */
  YYSYMBOL_KW_CHECK = 19,                  /* KW_CHECK  */
  YYSYMBOL_KW_GET = 20,                    /* KW_GET  */
  YYSYMBOL_KW_VARIANTS = 21,               /* KW_VARIANTS  */
  YYSYMBOL_KW_VARIANT = 22,                /* KW_VARIANT  */
  YYSYMBOL_KW_EREWRITE = 23,               /* KW_EREWRITE  */
  YYSYMBOL_KW_FREWRITE = 24,               /* KW_FREWRITE  */
  YYSYMBOL_KW_SREWRITE = 25,               /* KW_SREWRITE  */
  YYSYMBOL_KW_DSREWRITE = 26,              /* KW_DSREWRITE  */
  YYSYMBOL_KW_CONTINUE = 27,               /* KW_CONTINUE  */
  YYSYMBOL_KW_SEARCH = 28,                 /* KW_SEARCH  */
  YYSYMBOL_KW_SET = 29,                    /* KW_SET  */
  YYSYMBOL_KW_SHOW = 30,                   /* KW_SHOW  */
  YYSYMBOL_KW_ON = 31,                     /* KW_ON  */
  YYSYMBOL_KW_OFF = 32,                    /* KW_OFF  */
  YYSYMBOL_KW_ON_DOT = 33,                 /* KW_ON_DOT  */
  YYSYMBOL_KW_OFF_DOT = 34,                /* KW_OFF_DOT  */
  YYSYMBOL_KW_TRACE = 35,                  /* KW_TRACE  */
  YYSYMBOL_KW_BODY = 36,                   /* KW_BODY  */
  YYSYMBOL_KW_BUILTIN = 37,                /* KW_BUILTIN  */
  YYSYMBOL_KW_WHOLE = 38,                  /* KW_WHOLE  */
  YYSYMBOL_KW_SELECT = 39,                 /* KW_SELECT  */
  YYSYMBOL_KW_DESELECT = 40,               /* KW_DESELECT  */
  YYSYMBOL_KW_CONDITION = 41,              /* KW_CONDITION  */
  YYSYMBOL_KW_SUBSTITUTION = 42,           /* KW_SUBSTITUTION  */
  YYSYMBOL_KW_PRINT = 43,                  /* KW_PRINT  */
  YYSYMBOL_KW_GRAPH = 44,                  /* KW_GRAPH  */
  YYSYMBOL_KW_MIXFIX = 45,                 /* KW_MIXFIX  */
  YYSYMBOL_KW_FLAT = 46,                   /* KW_FLAT  */
  YYSYMBOL_KW_ATTRIBUTE = 47,              /* KW_ATTRIBUTE  */
  YYSYMBOL_KW_NEWLINE = 48,                /* KW_NEWLINE  */
  YYSYMBOL_KW_WITH = 49,                   /* KW_WITH  */
  YYSYMBOL_KW_PARENS = 50,                 /* KW_PARENS  */
  YYSYMBOL_KW_ALIASES = 51,                /* KW_ALIASES  */
  YYSYMBOL_KW_GC = 52,                     /* KW_GC  */
  YYSYMBOL_KW_RESOURCES = 53,              /* KW_RESOURCES  */
  YYSYMBOL_KW_TIME = 54,                   /* KW_TIME  */
  YYSYMBOL_KW_STATS = 55,                  /* KW_STATS  */
  YYSYMBOL_KW_TIMING = 56,                 /* KW_TIMING  */
  YYSYMBOL_KW_CMD = 57,                    /* KW_CMD  */
  YYSYMBOL_KW_BREAKDOWN = 58,              /* KW_BREAKDOWN  */
  YYSYMBOL_KW_BREAK = 59,                  /* KW_BREAK  */
  YYSYMBOL_KW_PATH = 60,                   /* KW_PATH  */
  YYSYMBOL_KW_STATE = 61,                  /* KW_STATE  */
  YYSYMBOL_KW_CONST = 62,                  /* KW_CONST  */
  YYSYMBOL_KW_MODULE = 63,                 /* KW_MODULE  */
  YYSYMBOL_KW_MODULES = 64,                /* KW_MODULES  */
  YYSYMBOL_KW_VIEWS = 65,                  /* KW_VIEWS  */
  YYSYMBOL_KW_ALL = 66,                    /* KW_ALL  */
  YYSYMBOL_KW_SORTS = 67,                  /* KW_SORTS  */
  YYSYMBOL_KW_OPS2 = 68,                   /* KW_OPS2  */
  YYSYMBOL_KW_VARS = 69,                   /* KW_VARS  */
  YYSYMBOL_KW_MBS = 70,                    /* KW_MBS  */
  YYSYMBOL_KW_EQS = 71,                    /* KW_EQS  */
  YYSYMBOL_KW_RLS = 72,                    /* KW_RLS  */
  YYSYMBOL_KW_STRATS = 73,                 /* KW_STRATS  */
  YYSYMBOL_KW_SDS = 74,                    /* KW_SDS  */
  YYSYMBOL_KW_SUMMARY = 75,                /* KW_SUMMARY  */
  YYSYMBOL_KW_KINDS = 76,                  /* KW_KINDS  */
  YYSYMBOL_KW_ADVISE = 77,                 /* KW_ADVISE  */
  YYSYMBOL_KW_VERBOSE = 78,                /* KW_VERBOSE  */
  YYSYMBOL_KW_DO = 79,                     /* KW_DO  */
  YYSYMBOL_KW_CLEAR = 80,                  /* KW_CLEAR  */
  YYSYMBOL_KW_CACHES = 81,                 /* KW_CACHES  */
  YYSYMBOL_KW_HOOKS = 82,                  /* KW_HOOKS  */
  YYSYMBOL_KW_COMBINE = 83,                /* KW_COMBINE  */
  YYSYMBOL_KW_PROTECT = 84,                /* KW_PROTECT  */
  YYSYMBOL_KW_EXTEND = 85,                 /* KW_EXTEND  */
  YYSYMBOL_KW_GENERATE_BY = 86,            /* KW_GENERATE_BY  */
  YYSYMBOL_KW_INCLUDE = 87,                /* KW_INCLUDE  */
  YYSYMBOL_KW_EXCLUDE = 88,                /* KW_EXCLUDE  */
  YYSYMBOL_KW_CONCEAL = 89,                /* KW_CONCEAL  */
  YYSYMBOL_KW_REVEAL = 90,                 /* KW_REVEAL  */
  YYSYMBOL_KW_COMPILE = 91,                /* KW_COMPILE  */
  YYSYMBOL_KW_COUNT = 92,                  /* KW_COUNT  */
  YYSYMBOL_KW_DEBUG = 93,                  /* KW_DEBUG  */
  YYSYMBOL_KW_IRREDUNDANT = 94,            /* KW_IRREDUNDANT  */
  YYSYMBOL_KW_FILTERED = 95,               /* KW_FILTERED  */
  YYSYMBOL_KW_RESUME = 96,                 /* KW_RESUME  */
  YYSYMBOL_KW_ABORT = 97,                  /* KW_ABORT  */
  YYSYMBOL_KW_STEP = 98,                   /* KW_STEP  */
  YYSYMBOL_KW_WHERE = 99,                  /* KW_WHERE  */
  YYSYMBOL_KW_CREDUCE = 100,               /* KW_CREDUCE  */
  YYSYMBOL_KW_SREDUCE = 101,               /* KW_SREDUCE  */
  YYSYMBOL_KW_DUMP = 102,                  /* KW_DUMP  */
  YYSYMBOL_KW_PROFILE = 103,               /* KW_PROFILE  */
  YYSYMBOL_KW_NUMBER = 104,                /* KW_NUMBER  */
  YYSYMBOL_KW_RAT = 105,                   /* KW_RAT  */
  YYSYMBOL_KW_COLOR = 106,                 /* KW_COLOR  */
  YYSYMBOL_KW_IMPLIED_STEP = 107,          /* KW_IMPLIED_STEP  */
  YYSYMBOL_SIMPLE_NUMBER = 108,            /* SIMPLE_NUMBER  */
  YYSYMBOL_KW_PWD = 109,                   /* KW_PWD  */
  YYSYMBOL_KW_CD = 110,                    /* KW_CD  */
  YYSYMBOL_KW_PUSHD = 111,                 /* KW_PUSHD  */
  YYSYMBOL_KW_POPD = 112,                  /* KW_POPD  */
  YYSYMBOL_KW_LS = 113,                    /* KW_LS  */
  YYSYMBOL_KW_LL = 114,                    /* KW_LL  */
  YYSYMBOL_KW_LOAD = 115,                  /* KW_LOAD  */
  YYSYMBOL_KW_SLOAD = 116,                 /* KW_SLOAD  */
  YYSYMBOL_KW_QUIT = 117,                  /* KW_QUIT  */
  YYSYMBOL_KW_EOF = 118,                   /* KW_EOF  */
  YYSYMBOL_KW_TEST = 119,                  /* KW_TEST  */
  YYSYMBOL_KW_SMT_SEARCH = 120,            /* KW_SMT_SEARCH  */
  YYSYMBOL_KW_VU_NARROW = 121,             /* KW_VU_NARROW  */
  YYSYMBOL_KW_FVU_NARROW = 122,            /* KW_FVU_NARROW  */
  YYSYMBOL_KW_FOLD = 123,                  /* KW_FOLD  */
  YYSYMBOL_KW_VFOLD = 124,                 /* KW_VFOLD  */
  YYSYMBOL_KW_DESUGARED = 125,             /* KW_DESUGARED  */
  YYSYMBOL_KW_PROCESSED = 126,             /* KW_PROCESSED  */
  YYSYMBOL_KW_FRONTIER = 127,              /* KW_FRONTIER  */
  YYSYMBOL_KW_MOST = 128,                  /* KW_MOST  */
  YYSYMBOL_KW_GENERAL = 129,               /* KW_GENERAL  */
  YYSYMBOL_KW_ENDM = 130,                  /* KW_ENDM  */
  YYSYMBOL_KW_IMPORT = 131,                /* KW_IMPORT  */
  YYSYMBOL_KW_ENDV = 132,                  /* KW_ENDV  */
  YYSYMBOL_KW_SORT = 133,                  /* KW_SORT  */
  YYSYMBOL_KW_SUBSORT = 134,               /* KW_SUBSORT  */
  YYSYMBOL_KW_OP = 135,                    /* KW_OP  */
  YYSYMBOL_KW_OPS = 136,                   /* KW_OPS  */
  YYSYMBOL_KW_MSGS = 137,                  /* KW_MSGS  */
  YYSYMBOL_KW_VAR = 138,                   /* KW_VAR  */
  YYSYMBOL_KW_CLASS = 139,                 /* KW_CLASS  */
  YYSYMBOL_KW_SUBCLASS = 140,              /* KW_SUBCLASS  */
  YYSYMBOL_KW_DSTRAT = 141,                /* KW_DSTRAT  */
  YYSYMBOL_KW_MB = 142,                    /* KW_MB  */
  YYSYMBOL_KW_CMB = 143,                   /* KW_CMB  */
  YYSYMBOL_KW_EQ = 144,                    /* KW_EQ  */
  YYSYMBOL_KW_CEQ = 145,                   /* KW_CEQ  */
  YYSYMBOL_KW_RL = 146,                    /* KW_RL  */
  YYSYMBOL_KW_CRL = 147,                   /* KW_CRL  */
  YYSYMBOL_KW_SD = 148,                    /* KW_SD  */
  YYSYMBOL_KW_CSD = 149,                   /* KW_CSD  */
  YYSYMBOL_KW_ATTR = 150,                  /* KW_ATTR  */
  YYSYMBOL_KW_IS = 151,                    /* KW_IS  */
  YYSYMBOL_KW_FROM = 152,                  /* KW_FROM  */
  YYSYMBOL_KW_ARROW = 153,                 /* KW_ARROW  */
  YYSYMBOL_KW_ARROW2 = 154,                /* KW_ARROW2  */
  YYSYMBOL_KW_PARTIAL = 155,               /* KW_PARTIAL  */
  YYSYMBOL_KW_IF = 156,                    /* KW_IF  */
  YYSYMBOL_KW_ASSIGN = 157,                /* KW_ASSIGN  */
  YYSYMBOL_158_ = 158,                     /* ':'  */
  YYSYMBOL_159_ = 159,                     /* '='  */
  YYSYMBOL_160_ = 160,                     /* '('  */
  YYSYMBOL_161_ = 161,                     /* ')'  */
  YYSYMBOL_162_ = 162,                     /* '.'  */
  YYSYMBOL_163_ = 163,                     /* '<'  */
  YYSYMBOL_164_ = 164,                     /* '['  */
  YYSYMBOL_165_ = 165,                     /* ']'  */
  YYSYMBOL_166_ = 166,                     /* ','  */
  YYSYMBOL_167_ = 167,                     /* '|'  */
  YYSYMBOL_168_ = 168,                     /* '@'  */
  YYSYMBOL_KW_LABEL = 169,                 /* KW_LABEL  */
  YYSYMBOL_KW_TO = 170,                    /* KW_TO  */
  YYSYMBOL_KW_COLON2 = 171,                /* KW_COLON2  */
  YYSYMBOL_172_ = 172,                     /* '+'  */
  YYSYMBOL_173_ = 173,                     /* '*'  */
  YYSYMBOL_174_ = 174,                     /* '{'  */
  YYSYMBOL_175_ = 175,                     /* '}'  */
  YYSYMBOL_KW_ASSOC = 176,                 /* KW_ASSOC  */
  YYSYMBOL_KW_COMM = 177,                  /* KW_COMM  */
  YYSYMBOL_KW_ID = 178,                    /* KW_ID  */
  YYSYMBOL_KW_IDEM = 179,                  /* KW_IDEM  */
  YYSYMBOL_KW_ITER = 180,                  /* KW_ITER  */
  YYSYMBOL_KW_PCONST = 181,                /* KW_PCONST  */
  YYSYMBOL_KW_LEFT = 182,                  /* KW_LEFT  */
  YYSYMBOL_KW_RIGHT = 183,                 /* KW_RIGHT  */
  YYSYMBOL_KW_PREC = 184,                  /* KW_PREC  */
  YYSYMBOL_KW_GATHER = 185,                /* KW_GATHER  */
  YYSYMBOL_KW_METADATA = 186,              /* KW_METADATA  */
  YYSYMBOL_KW_STRAT = 187,                 /* KW_STRAT  */
  YYSYMBOL_KW_ASTRAT = 188,                /* KW_ASTRAT  */
  YYSYMBOL_KW_POLY = 189,                  /* KW_POLY  */
  YYSYMBOL_KW_MEMO = 190,                  /* KW_MEMO  */
  YYSYMBOL_KW_FROZEN = 191,                /* KW_FROZEN  */
  YYSYMBOL_KW_CTOR = 192,                  /* KW_CTOR  */
  YYSYMBOL_KW_LATEX = 193,                 /* KW_LATEX  */
  YYSYMBOL_KW_SPECIAL = 194,               /* KW_SPECIAL  */
  YYSYMBOL_KW_CONFIG = 195,                /* KW_CONFIG  */
  YYSYMBOL_KW_OBJ = 196,                   /* KW_OBJ  */
  YYSYMBOL_KW_MSG = 197,                   /* KW_MSG  */
  YYSYMBOL_KW_PORTAL = 198,                /* KW_PORTAL  */
  YYSYMBOL_KW_DITTO = 199,                 /* KW_DITTO  */
  YYSYMBOL_KW_FORMAT = 200,                /* KW_FORMAT  */
  YYSYMBOL_KW_ID_HOOK = 201,               /* KW_ID_HOOK  */
  YYSYMBOL_KW_OP_HOOK = 202,               /* KW_OP_HOOK  */
  YYSYMBOL_KW_TERM_HOOK = 203,             /* KW_TERM_HOOK  */
  YYSYMBOL_KW_IN = 204,                    /* KW_IN  */
  YYSYMBOL_KW_FILTER = 205,                /* KW_FILTER  */
  YYSYMBOL_KW_DELAY = 206,                 /* KW_DELAY  */
  YYSYMBOL_IDENTIFIER = 207,               /* IDENTIFIER  */
  YYSYMBOL_NUMERIC_ID = 208,               /* NUMERIC_ID  */
  YYSYMBOL_ENDS_IN_DOT = 209,              /* ENDS_IN_DOT  */
  YYSYMBOL_FORCE_LOOKAHEAD = 210,          /* FORCE_LOOKAHEAD  */
  YYSYMBOL_CHANGE_FILE = 211,              /* CHANGE_FILE  */
  YYSYMBOL_END_OF_INPUT = 212,             /* END_OF_INPUT  */
  YYSYMBOL_YYACCEPT = 213,                 /* $accept  */
  YYSYMBOL_top = 214,                      /* top  */
  YYSYMBOL_item = 215,                     /* item  */
  YYSYMBOL_directive = 216,                /* directive  */
  YYSYMBOL_217_1 = 217,                    /* $@1  */
  YYSYMBOL_218_2 = 218,                    /* $@2  */
  YYSYMBOL_219_3 = 219,                    /* $@3  */
  YYSYMBOL_220_4 = 220,                    /* $@4  */
  YYSYMBOL_221_5 = 221,                    /* $@5  */
  YYSYMBOL_222_6 = 222,                    /* $@6  */
  YYSYMBOL_223_7 = 223,                    /* $@7  */
  YYSYMBOL_moduleExprDot = 224,            /* moduleExprDot  */
  YYSYMBOL_moduleExpr = 225,               /* moduleExpr  */
  YYSYMBOL_moduleExpr2 = 226,              /* moduleExpr2  */
  YYSYMBOL_moduleExpr3 = 227,              /* moduleExpr3  */
  YYSYMBOL_renameExpr = 228,               /* renameExpr  */
  YYSYMBOL_instantExpr = 229,              /* instantExpr  */
  YYSYMBOL_parenExpr = 230,                /* parenExpr  */
  YYSYMBOL_viewExpr = 231,                 /* viewExpr  */
  YYSYMBOL_instantArgs = 232,              /* instantArgs  */
  YYSYMBOL_renaming = 233,                 /* renaming  */
  YYSYMBOL_234_8 = 234,                    /* $@8  */
  YYSYMBOL_235_9 = 235,                    /* $@9  */
  YYSYMBOL_renaming2 = 236,                /* renaming2  */
  YYSYMBOL_mappingList = 237,              /* mappingList  */
  YYSYMBOL_mapping = 238,                  /* mapping  */
  YYSYMBOL_239_10 = 239,                   /* $@10  */
  YYSYMBOL_240_11 = 240,                   /* $@11  */
  YYSYMBOL_241_12 = 241,                   /* $@12  */
  YYSYMBOL_242_13 = 242,                   /* $@13  */
  YYSYMBOL_243_14 = 243,                   /* $@14  */
  YYSYMBOL_244_15 = 244,                   /* $@15  */
  YYSYMBOL_fromSpec = 245,                 /* fromSpec  */
  YYSYMBOL_246_16 = 246,                   /* $@16  */
  YYSYMBOL_fromAttrSpec = 247,             /* fromAttrSpec  */
  YYSYMBOL_fromStratSpec = 248,            /* fromStratSpec  */
  YYSYMBOL_toAttributes = 249,             /* toAttributes  */
  YYSYMBOL_250_17 = 250,                   /* $@17  */
  YYSYMBOL_toAttributeList = 251,          /* toAttributeList  */
  YYSYMBOL_toAttribute = 252,              /* toAttribute  */
  YYSYMBOL_253_18 = 253,                   /* $@18  */
  YYSYMBOL_254_19 = 254,                   /* $@19  */
  YYSYMBOL_255_20 = 255,                   /* $@20  */
  YYSYMBOL_view = 256,                     /* view  */
  YYSYMBOL_257_21 = 257,                   /* $@21  */
  YYSYMBOL_258_22 = 258,                   /* $@22  */
  YYSYMBOL_viewDecList = 259,              /* viewDecList  */
  YYSYMBOL_skipStrayArrow = 260,           /* skipStrayArrow  */
  YYSYMBOL_viewDeclaration = 261,          /* viewDeclaration  */
  YYSYMBOL_262_23 = 262,                   /* $@23  */
  YYSYMBOL_263_24 = 263,                   /* $@24  */
  YYSYMBOL_264_25 = 264,                   /* $@25  */
  YYSYMBOL_sortDot = 265,                  /* sortDot  */
  YYSYMBOL_viewEndOpMap = 266,             /* viewEndOpMap  */
  YYSYMBOL_267_26 = 267,                   /* $@26  */
  YYSYMBOL_268_27 = 268,                   /* $@27  */
  YYSYMBOL_269_28 = 269,                   /* $@28  */
  YYSYMBOL_endMsgMap = 270,                /* endMsgMap  */
  YYSYMBOL_271_29 = 271,                   /* $@29  */
  YYSYMBOL_272_30 = 272,                   /* $@30  */
  YYSYMBOL_273_31 = 273,                   /* $@31  */
  YYSYMBOL_strategyCall = 274,             /* strategyCall  */
  YYSYMBOL_275_32 = 275,                   /* $@32  */
  YYSYMBOL_viewStratMap = 276,             /* viewStratMap  */
  YYSYMBOL_277_33 = 277,                   /* $@33  */
  YYSYMBOL_278_34 = 278,                   /* $@34  */
  YYSYMBOL_endBubble = 279,                /* endBubble  */
  YYSYMBOL_parenBubble = 280,              /* parenBubble  */
  YYSYMBOL_281_35 = 281,                   /* $@35  */
  YYSYMBOL_module = 282,                   /* module  */
  YYSYMBOL_283_36 = 283,                   /* $@36  */
  YYSYMBOL_284_37 = 284,                   /* $@37  */
  YYSYMBOL_dot = 285,                      /* dot  */
  YYSYMBOL_parameters = 286,               /* parameters  */
  YYSYMBOL_parameterList = 287,            /* parameterList  */
  YYSYMBOL_parameter = 288,                /* parameter  */
  YYSYMBOL_colon2 = 289,                   /* colon2  */
  YYSYMBOL_badType = 290,                  /* badType  */
  YYSYMBOL_typeDot = 291,                  /* typeDot  */
  YYSYMBOL_decList = 292,                  /* decList  */
  YYSYMBOL_declaration = 293,              /* declaration  */
  YYSYMBOL_294_38 = 294,                   /* $@38  */
  YYSYMBOL_295_39 = 295,                   /* $@39  */
  YYSYMBOL_296_40 = 296,                   /* $@40  */
  YYSYMBOL_297_41 = 297,                   /* $@41  */
  YYSYMBOL_298_42 = 298,                   /* $@42  */
  YYSYMBOL_299_43 = 299,                   /* $@43  */
  YYSYMBOL_300_44 = 300,                   /* $@44  */
  YYSYMBOL_301_45 = 301,                   /* $@45  */
  YYSYMBOL_302_46 = 302,                   /* $@46  */
  YYSYMBOL_303_47 = 303,                   /* $@47  */
  YYSYMBOL_304_48 = 304,                   /* $@48  */
  YYSYMBOL_305_49 = 305,                   /* $@49  */
  YYSYMBOL_306_50 = 306,                   /* $@50  */
  YYSYMBOL_307_51 = 307,                   /* $@51  */
  YYSYMBOL_308_52 = 308,                   /* $@52  */
  YYSYMBOL_309_53 = 309,                   /* $@53  */
  YYSYMBOL_310_54 = 310,                   /* $@54  */
  YYSYMBOL_311_55 = 311,                   /* $@55  */
  YYSYMBOL_312_56 = 312,                   /* $@56  */
  YYSYMBOL_313_57 = 313,                   /* $@57  */
  YYSYMBOL_314_58 = 314,                   /* $@58  */
  YYSYMBOL_315_59 = 315,                   /* $@59  */
  YYSYMBOL_316_60 = 316,                   /* $@60  */
  YYSYMBOL_317_61 = 317,                   /* $@61  */
  YYSYMBOL_318_62 = 318,                   /* $@62  */
  YYSYMBOL_319_63 = 319,                   /* $@63  */
  YYSYMBOL_320_64 = 320,                   /* $@64  */
  YYSYMBOL_321_65 = 321,                   /* $@65  */
  YYSYMBOL_classDecl = 322,                /* classDecl  */
  YYSYMBOL_323_66 = 323,                   /* $@66  */
  YYSYMBOL_classDef = 324,                 /* classDef  */
  YYSYMBOL_finalPair = 325,                /* finalPair  */
  YYSYMBOL_cPairList = 326,                /* cPairList  */
  YYSYMBOL_cPair = 327,                    /* cPair  */
  YYSYMBOL_varNameList = 328,              /* varNameList  */
  YYSYMBOL_opNameList = 329,               /* opNameList  */
  YYSYMBOL_simpleOpName = 330,             /* simpleOpName  */
  YYSYMBOL_domainRangeAttr = 331,          /* domainRangeAttr  */
  YYSYMBOL_stratDeclKeyword = 332,         /* stratDeclKeyword  */
  YYSYMBOL_stratIdList = 333,              /* stratIdList  */
  YYSYMBOL_stratId = 334,                  /* stratId  */
  YYSYMBOL_stratSignature = 335,           /* stratSignature  */
  YYSYMBOL_stratAttributes = 336,          /* stratAttributes  */
  YYSYMBOL_stratAttrList = 337,            /* stratAttrList  */
  YYSYMBOL_skipStrayColon = 338,           /* skipStrayColon  */
  YYSYMBOL_dra2 = 339,                     /* dra2  */
  YYSYMBOL_rangeAttr = 340,                /* rangeAttr  */
  YYSYMBOL_typeAttr = 341,                 /* typeAttr  */
  YYSYMBOL_arrow = 342,                    /* arrow  */
  YYSYMBOL_typeList = 343,                 /* typeList  */
  YYSYMBOL_typeName1 = 344,                /* typeName1  */
  YYSYMBOL_typeName1Dot = 345,             /* typeName1Dot  */
  YYSYMBOL_kind = 346,                     /* kind  */
  YYSYMBOL_347_67 = 347,                   /* $@67  */
  YYSYMBOL_typeName = 348,                 /* typeName  */
  YYSYMBOL_349_68 = 349,                   /* $@68  */
  YYSYMBOL_sortNames = 350,                /* sortNames  */
  YYSYMBOL_attributes = 351,               /* attributes  */
  YYSYMBOL_attributeList = 352,            /* attributeList  */
  YYSYMBOL_idKeyword = 353,                /* idKeyword  */
  YYSYMBOL_attribute = 354,                /* attribute  */
  YYSYMBOL_355_69 = 355,                   /* $@69  */
  YYSYMBOL_356_70 = 356,                   /* $@70  */
  YYSYMBOL_357_71 = 357,                   /* $@71  */
  YYSYMBOL_358_72 = 358,                   /* $@72  */
  YYSYMBOL_359_73 = 359,                   /* $@73  */
  YYSYMBOL_360_74 = 360,                   /* $@74  */
  YYSYMBOL_361_75 = 361,                   /* $@75  */
  YYSYMBOL_362_76 = 362,                   /* $@76  */
  YYSYMBOL_identity = 363,                 /* identity  */
  YYSYMBOL_idList = 364,                   /* idList  */
  YYSYMBOL_hookList = 365,                 /* hookList  */
  YYSYMBOL_hook = 366,                     /* hook  */
  YYSYMBOL_expectedIs = 367,               /* expectedIs  */
  YYSYMBOL_expectedDot = 368,              /* expectedDot  */
  YYSYMBOL_sortNameList = 369,             /* sortNameList  */
  YYSYMBOL_endSortNameList = 370,          /* endSortNameList  */
  YYSYMBOL_subsortList = 371,              /* subsortList  */
  YYSYMBOL_endSubsortList = 372,           /* endSubsortList  */
  YYSYMBOL_sortName = 373,                 /* sortName  */
  YYSYMBOL_sortNameFrag = 374,             /* sortNameFrag  */
  YYSYMBOL_375_77 = 375,                   /* $@77  */
  YYSYMBOL_sortNameFrags = 376,            /* sortNameFrags  */
  YYSYMBOL_377_78 = 377,                   /* $@78  */
  YYSYMBOL_tokenDot = 378,                 /* tokenDot  */
  YYSYMBOL_sortToken = 379,                /* sortToken  */
  YYSYMBOL_token = 380,                    /* token  */
  YYSYMBOL_stratName = 381,                /* stratName  */
  YYSYMBOL_attributeName = 382,            /* attributeName  */
  YYSYMBOL_tokenBarColon = 383,            /* tokenBarColon  */
  YYSYMBOL_tokenBarDot = 384,              /* tokenBarDot  */
  YYSYMBOL_endsInDot = 385,                /* endsInDot  */
  YYSYMBOL_command = 386,                  /* command  */
  YYSYMBOL_387_79 = 387,                   /* $@79  */
  YYSYMBOL_388_80 = 388,                   /* $@80  */
  YYSYMBOL_389_81 = 389,                   /* $@81  */
  YYSYMBOL_390_82 = 390,                   /* $@82  */
  YYSYMBOL_391_83 = 391,                   /* $@83  */
  YYSYMBOL_392_84 = 392,                   /* $@84  */
  YYSYMBOL_393_85 = 393,                   /* $@85  */
  YYSYMBOL_394_86 = 394,                   /* $@86  */
  YYSYMBOL_395_87 = 395,                   /* $@87  */
  YYSYMBOL_396_88 = 396,                   /* $@88  */
  YYSYMBOL_397_89 = 397,                   /* $@89  */
  YYSYMBOL_398_90 = 398,                   /* $@90  */
  YYSYMBOL_399_91 = 399,                   /* $@91  */
  YYSYMBOL_400_92 = 400,                   /* $@92  */
  YYSYMBOL_401_93 = 401,                   /* $@93  */
  YYSYMBOL_402_94 = 402,                   /* $@94  */
  YYSYMBOL_403_95 = 403,                   /* $@95  */
  YYSYMBOL_404_96 = 404,                   /* $@96  */
  YYSYMBOL_405_97 = 405,                   /* $@97  */
  YYSYMBOL_406_98 = 406,                   /* $@98  */
  YYSYMBOL_407_99 = 407,                   /* $@99  */
  YYSYMBOL_408_100 = 408,                  /* $@100  */
  YYSYMBOL_409_101 = 409,                  /* $@101  */
  YYSYMBOL_410_102 = 410,                  /* $@102  */
  YYSYMBOL_411_103 = 411,                  /* $@103  */
  YYSYMBOL_412_104 = 412,                  /* $@104  */
  YYSYMBOL_413_105 = 413,                  /* $@105  */
  YYSYMBOL_414_106 = 414,                  /* $@106  */
  YYSYMBOL_415_107 = 415,                  /* $@107  */
  YYSYMBOL_416_108 = 416,                  /* $@108  */
  YYSYMBOL_417_109 = 417,                  /* $@109  */
  YYSYMBOL_418_110 = 418,                  /* $@110  */
  YYSYMBOL_419_111 = 419,                  /* $@111  */
  YYSYMBOL_420_112 = 420,                  /* $@112  */
  YYSYMBOL_421_113 = 421,                  /* $@113  */
  YYSYMBOL_422_114 = 422,                  /* $@114  */
  YYSYMBOL_423_115 = 423,                  /* $@115  */
  YYSYMBOL_424_116 = 424,                  /* $@116  */
  YYSYMBOL_425_117 = 425,                  /* $@117  */
  YYSYMBOL_426_118 = 426,                  /* $@118  */
  YYSYMBOL_427_119 = 427,                  /* $@119  */
  YYSYMBOL_428_120 = 428,                  /* $@120  */
  YYSYMBOL_429_121 = 429,                  /* $@121  */
  YYSYMBOL_430_122 = 430,                  /* $@122  */
  YYSYMBOL_431_123 = 431,                  /* $@123  */
  YYSYMBOL_432_124 = 432,                  /* $@124  */
  YYSYMBOL_433_125 = 433,                  /* $@125  */
  YYSYMBOL_434_126 = 434,                  /* $@126  */
  YYSYMBOL_kw_module = 435,                /* kw_module  */
  YYSYMBOL_printOption = 436,              /* printOption  */
  YYSYMBOL_traceOption = 437,              /* traceOption  */
  YYSYMBOL_polarityDot = 438,              /* polarityDot  */
  YYSYMBOL_select = 439,                   /* select  */
  YYSYMBOL_exclude = 440,                  /* exclude  */
  YYSYMBOL_conceal = 441,                  /* conceal  */
  YYSYMBOL_search = 442,                   /* search  */
  YYSYMBOL_match = 443,                    /* match  */
  YYSYMBOL_optDebug = 444,                 /* optDebug  */
  YYSYMBOL_optIrredundant = 445,           /* optIrredundant  */
  YYSYMBOL_optNumber = 446,                /* optNumber  */
  YYSYMBOL_optOptions = 447,               /* optOptions  */
  YYSYMBOL_optionsList = 448,              /* optionsList  */
  YYSYMBOL_option = 449,                   /* option  */
  YYSYMBOL_importMode = 450,               /* importMode  */
  YYSYMBOL_moduleAndTerm = 451,            /* moduleAndTerm  */
  YYSYMBOL_452_127 = 452,                  /* $@127  */
  YYSYMBOL_inEnd = 453,                    /* inEnd  */
  YYSYMBOL_454_128 = 454,                  /* $@128  */
  YYSYMBOL_numberModuleTerm = 455,         /* numberModuleTerm  */
  YYSYMBOL_456_129 = 456,                  /* $@129  */
  YYSYMBOL_457_130 = 457,                  /* $@130  */
  YYSYMBOL_numberModuleTerm1 = 458,        /* numberModuleTerm1  */
  YYSYMBOL_459_131 = 459,                  /* $@131  */
  YYSYMBOL_460_132 = 460,                  /* $@132  */
  YYSYMBOL_numberModuleTerm2 = 461,        /* numberModuleTerm2  */
  YYSYMBOL_462_133 = 462,                  /* $@133  */
  YYSYMBOL_463_134 = 463,                  /* $@134  */
  YYSYMBOL_optionsNumbersModuleTerm = 464, /* optionsNumbersModuleTerm  */
  YYSYMBOL_465_135 = 465,                  /* $@135  */
  YYSYMBOL_466_136 = 466,                  /* $@136  */
  YYSYMBOL_467_137 = 467,                  /* $@137  */
  YYSYMBOL_optionsNumbersModuleTerm1 = 468, /* optionsNumbersModuleTerm1  */
  YYSYMBOL_469_138 = 469,                  /* $@138  */
  YYSYMBOL_470_139 = 470,                  /* $@139  */
  YYSYMBOL_471_140 = 471,                  /* $@140  */
  YYSYMBOL_optionsNumbersModuleTerm2 = 472, /* optionsNumbersModuleTerm2  */
  YYSYMBOL_473_141 = 473,                  /* $@141  */
  YYSYMBOL_474_142 = 474,                  /* $@142  */
  YYSYMBOL_numbersModuleTerm = 475,        /* numbersModuleTerm  */
  YYSYMBOL_476_143 = 476,                  /* $@143  */
  YYSYMBOL_477_144 = 477,                  /* $@144  */
  YYSYMBOL_numbersModuleTerm1 = 478,       /* numbersModuleTerm1  */
  YYSYMBOL_479_145 = 479,                  /* $@145  */
  YYSYMBOL_480_146 = 480,                  /* $@146  */
  YYSYMBOL_481_147 = 481,                  /* $@147  */
  YYSYMBOL_numbersModuleTerm2 = 482,       /* numbersModuleTerm2  */
  YYSYMBOL_483_148 = 483,                  /* $@148  */
  YYSYMBOL_484_149 = 484,                  /* $@149  */
  YYSYMBOL_485_150 = 485,                  /* $@150  */
  YYSYMBOL_numbersModuleTerm3 = 486,       /* numbersModuleTerm3  */
  YYSYMBOL_487_151 = 487,                  /* $@151  */
  YYSYMBOL_488_152 = 488,                  /* $@152  */
  YYSYMBOL_numbersModuleTerm4 = 489,       /* numbersModuleTerm4  */
  YYSYMBOL_490_153 = 490,                  /* $@153  */
  YYSYMBOL_491_154 = 491,                  /* $@154  */
  YYSYMBOL_numbersModuleTerm5 = 492,       /* numbersModuleTerm5  */
  YYSYMBOL_493_155 = 493,                  /* $@155  */
  YYSYMBOL_494_156 = 494,                  /* $@156  */
  YYSYMBOL_numbersModuleTerm6 = 495,       /* numbersModuleTerm6  */
  YYSYMBOL_496_157 = 496,                  /* $@157  */
  YYSYMBOL_497_158 = 497,                  /* $@158  */
  YYSYMBOL_miscEndBubble = 498,            /* miscEndBubble  */
  YYSYMBOL_499_159 = 499,                  /* $@159  */
  YYSYMBOL_initialEndBubble = 500,         /* initialEndBubble  */
  YYSYMBOL_501_160 = 501,                  /* $@160  */
  YYSYMBOL_502_161 = 502,                  /* $@161  */
  YYSYMBOL_cTokenBarIn = 503,              /* cTokenBarIn  */
  YYSYMBOL_cTokenBarLeftIn = 504,          /* cTokenBarLeftIn  */
  YYSYMBOL_cTokenBarOpenLeftIn = 505,      /* cTokenBarOpenLeftIn  */
  YYSYMBOL_cTokenBarDotNumber = 506,       /* cTokenBarDotNumber  */
  YYSYMBOL_cTokenBarDotRight = 507,        /* cTokenBarDotRight  */
  YYSYMBOL_cTokenBarDotCommaNumber = 508,  /* cTokenBarDotCommaNumber  */
  YYSYMBOL_cTokenBarDotCommaRight = 509,   /* cTokenBarDotCommaRight  */
  YYSYMBOL_cTokenBarDotCommaClose = 510,   /* cTokenBarDotCommaClose  */
  YYSYMBOL_cTokenBarDotOptionToken = 511,  /* cTokenBarDotOptionToken  */
  YYSYMBOL_opSelect = 512,                 /* opSelect  */
  YYSYMBOL_endSelect = 513,                /* endSelect  */
  YYSYMBOL_badSelect = 514,                /* badSelect  */
  YYSYMBOL_cOpNameList = 515,              /* cOpNameList  */
  YYSYMBOL_cSimpleOpName = 516,            /* cSimpleOpName  */
  YYSYMBOL_cSimpleTokenBarDot = 517,       /* cSimpleTokenBarDot  */
  YYSYMBOL_cOptionToken = 518              /* cOptionToken  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 139 "surface.yy"

int yylex(YYSTYPE* lvalp);

#line 720 "surface.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  127
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  213
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  844
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   452


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     160,   161,   173,   172,   166,     2,   162,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   158,     2,
     163,   159,     2,     2,   168,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   164,     2,   165,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   174,   167,   175,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   169,   170,   171,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   283,   283,   284,   289,   298,   309,   310,   311,   312,
     313,   325,   325,   335,   335,   345,   345,   355,   359,   359,
     370,   370,   381,   392,   392,   397,   397,   402,   407,   440,
     444,   448,   449,   450,   451,   461,   465,   471,   472,   478,
     479,   482,   483,   484,   491,   498,   505,   514,   519,   525,
     530,   542,   547,   541,   553,   554,   557,   558,   561,   565,
     569,   570,   569,   572,   572,   575,   580,   579,   588,   592,
     587,   604,   604,   606,   609,   613,   616,   617,   623,   623,
     625,   628,   629,   632,   633,   634,   634,   636,   637,   637,
     639,   640,   640,   642,   648,   650,   648,   670,   671,   674,
     678,   681,   685,   687,   686,   691,   692,   697,   696,   705,
     704,   709,   710,   717,   726,   727,   731,   739,   730,   748,
     747,   780,   788,   779,   798,   797,   830,   835,   835,   849,
     848,   857,   856,   884,   885,   888,   888,   895,   897,   895,
     910,   911,   914,   915,   918,   919,   922,   928,   929,   935,
     944,   945,   948,   949,   952,   962,   962,   965,   965,   968,
     969,   968,   972,   974,   976,   977,   976,   980,   981,   982,
     980,   985,   986,   985,   989,   990,   991,   989,   994,   995,
     994,   998,   999,  1000,   998,  1003,  1004,  1003,  1007,  1008,
    1009,  1007,  1012,  1012,  1018,  1019,  1018,  1024,  1029,  1031,
    1031,  1034,  1043,  1050,  1060,  1059,  1066,  1072,  1073,  1076,
    1080,  1086,  1087,  1090,  1094,  1100,  1101,  1104,  1105,  1108,
    1109,  1112,  1113,  1114,  1120,  1120,  1122,  1123,  1126,  1129,
    1131,  1137,  1138,  1141,  1147,  1151,  1154,  1155,  1159,  1165,
    1172,  1173,  1176,  1177,  1180,  1181,  1184,  1189,  1195,  1200,
    1205,  1211,  1211,  1215,  1220,  1220,  1227,  1228,  1231,  1232,
    1235,  1236,  1239,  1243,  1247,  1253,  1257,  1261,  1261,  1263,
    1267,  1271,  1272,  1273,  1273,  1275,  1276,  1276,  1278,  1279,
    1279,  1281,  1282,  1282,  1284,  1285,  1285,  1287,  1288,  1292,
    1296,  1301,  1301,  1303,  1307,  1311,  1315,  1319,  1323,  1323,
    1325,  1326,  1327,  1331,  1341,  1342,  1345,  1346,  1349,  1350,
    1353,  1354,  1355,  1356,  1362,  1364,  1369,  1371,  1379,  1380,
    1384,  1385,  1391,  1392,  1395,  1401,  1413,  1414,  1414,  1418,
    1418,  1420,  1423,  1455,  1457,  1457,  1457,  1457,  1457,  1457,
    1458,  1458,  1459,  1459,  1459,  1459,  1459,  1460,  1460,  1460,
    1460,  1460,  1460,  1461,  1461,  1462,  1462,  1464,  1464,  1464,
    1464,  1464,  1466,  1466,  1466,  1466,  1466,  1466,  1467,  1467,
    1467,  1467,  1467,  1467,  1468,  1468,  1468,  1468,  1469,  1469,
    1469,  1469,  1470,  1470,  1470,  1470,  1472,  1472,  1472,  1472,
    1472,  1478,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1479,
    1479,  1479,  1479,  1480,  1480,  1480,  1480,  1488,  1488,  1488,
    1489,  1489,  1489,  1489,  1489,  1489,  1489,  1490,  1490,  1490,
    1490,  1498,  1498,  1498,  1499,  1499,  1499,  1499,  1500,  1500,
    1500,  1500,  1508,  1508,  1508,  1509,  1509,  1509,  1509,  1509,
    1509,  1509,  1509,  1510,  1510,  1510,  1510,  1519,  1519,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1521,  1521,  1521,
    1521,  1524,  1524,  1551,  1551,  1556,  1556,  1563,  1562,  1575,
    1574,  1587,  1586,  1599,  1598,  1611,  1610,  1623,  1622,  1636,
    1635,  1649,  1648,  1661,  1660,  1674,  1673,  1686,  1685,  1699,
    1698,  1713,  1712,  1725,  1724,  1737,  1736,  1749,  1748,  1761,
    1760,  1774,  1773,  1785,  1790,  1789,  1806,  1805,  1816,  1822,
    1822,  1828,  1828,  1834,  1834,  1840,  1840,  1846,  1846,  1855,
    1855,  1861,  1861,  1867,  1867,  1873,  1873,  1879,  1879,  1885,
    1889,  1893,  1893,  1899,  1899,  1905,  1905,  1911,  1911,  1917,
    1917,  1923,  1923,  1929,  1929,  1935,  1935,  1941,  1941,  1947,
    1947,  1953,  1957,  1961,  1965,  1969,  1969,  1975,  1979,  1986,
    1990,  1994,  1998,  2002,  2006,  2010,  2014,  2018,  2022,  2026,
    2031,  2036,  2040,  2044,  2045,  2044,  2050,  2051,  2050,  2056,
    2060,  2064,  2068,  2072,  2076,  2080,  2087,  2091,  2095,  2099,
    2103,  2110,  2114,  2121,  2121,  2127,  2128,  2134,  2135,  2136,
    2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,
    2147,  2148,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  2165,  2166,  2167,  2172,  2179,  2180,
    2183,  2184,  2187,  2188,  2193,  2194,  2195,  2196,  2197,  2200,
    2201,  2204,  2205,  2208,  2209,  2212,  2213,  2216,  2217,  2220,
    2221,  2224,  2225,  2226,  2229,  2230,  2231,  2232,  2241,  2242,
    2242,  2246,  2246,  2248,  2258,  2258,  2260,  2261,  2261,  2266,
    2266,  2268,  2268,  2270,  2274,  2274,  2276,  2276,  2278,  2292,
    2292,  2294,  2294,  2296,  2297,  2297,  2303,  2302,  2309,  2308,
    2314,  2314,  2316,  2320,  2322,  2322,  2324,  2324,  2326,  2333,
    2333,  2335,  2336,  2336,  2345,  2345,  2347,  2347,  2349,  2349,
    2351,  2359,  2359,  2361,  2361,  2363,  2363,  2365,  2373,  2373,
    2375,  2375,  2377,  2386,  2385,  2392,  2392,  2394,  2402,  2402,
    2404,  2404,  2406,  2414,  2414,  2416,  2416,  2418,  2421,  2421,
    2423,  2432,  2432,  2434,  2434,  2436,  2447,  2447,  2447,  2447,
    2447,  2447,  2447,  2447,  2447,  2447,  2450,  2450,  2450,  2450,
    2450,  2450,  2450,  2450,  2450,  2454,  2454,  2454,  2454,  2454,
    2454,  2454,  2454,  2458,  2458,  2458,  2458,  2458,  2458,  2458,
    2458,  2458,  2462,  2462,  2462,  2462,  2462,  2462,  2462,  2462,
    2462,  2466,  2466,  2466,  2466,  2466,  2466,  2466,  2466,  2470,
    2470,  2470,  2470,  2470,  2470,  2470,  2470,  2474,  2474,  2474,
    2474,  2474,  2474,  2474,  2474,  2478,  2478,  2478,  2478,  2478,
    2478,  2478,  2478,  2478,  2484,  2485,  2488,  2489,  2492,  2499,
    2500,  2503,  2508,  2515,  2515,  2515,  2515,  2515,  2515,  2515,
    2515,  2515,  2515,  2518,  2519
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FILE_NAME_STRING",
  "UNINTERPRETED_STRING", "LATEX_STRING", "KW_MOD", "KW_VIEW", "KW_PARSE",
  "KW_NORMALIZE", "KW_REDUCE", "KW_REWRITE", "KW_OO", "KW_LOOP",
  "KW_NARROW", "KW_XG_NARROW", "KW_MATCH", "KW_XMATCH", "KW_UNIFY",
  "KW_CHECK", "KW_GET", "KW_VARIANTS", "KW_VARIANT", "KW_EREWRITE",
  "KW_FREWRITE", "KW_SREWRITE", "KW_DSREWRITE", "KW_CONTINUE", "KW_SEARCH",
  "KW_SET", "KW_SHOW", "KW_ON", "KW_OFF", "KW_ON_DOT", "KW_OFF_DOT",
  "KW_TRACE", "KW_BODY", "KW_BUILTIN", "KW_WHOLE", "KW_SELECT",
  "KW_DESELECT", "KW_CONDITION", "KW_SUBSTITUTION", "KW_PRINT", "KW_GRAPH",
  "KW_MIXFIX", "KW_FLAT", "KW_ATTRIBUTE", "KW_NEWLINE", "KW_WITH",
  "KW_PARENS", "KW_ALIASES", "KW_GC", "KW_RESOURCES", "KW_TIME",
  "KW_STATS", "KW_TIMING", "KW_CMD", "KW_BREAKDOWN", "KW_BREAK", "KW_PATH",
  "KW_STATE", "KW_CONST", "KW_MODULE", "KW_MODULES", "KW_VIEWS", "KW_ALL",
  "KW_SORTS", "KW_OPS2", "KW_VARS", "KW_MBS", "KW_EQS", "KW_RLS",
  "KW_STRATS", "KW_SDS", "KW_SUMMARY", "KW_KINDS", "KW_ADVISE",
  "KW_VERBOSE", "KW_DO", "KW_CLEAR", "KW_CACHES", "KW_HOOKS", "KW_COMBINE",
  "KW_PROTECT", "KW_EXTEND", "KW_GENERATE_BY", "KW_INCLUDE", "KW_EXCLUDE",
  "KW_CONCEAL", "KW_REVEAL", "KW_COMPILE", "KW_COUNT", "KW_DEBUG",
  "KW_IRREDUNDANT", "KW_FILTERED", "KW_RESUME", "KW_ABORT", "KW_STEP",
  "KW_WHERE", "KW_CREDUCE", "KW_SREDUCE", "KW_DUMP", "KW_PROFILE",
  "KW_NUMBER", "KW_RAT", "KW_COLOR", "KW_IMPLIED_STEP", "SIMPLE_NUMBER",
  "KW_PWD", "KW_CD", "KW_PUSHD", "KW_POPD", "KW_LS", "KW_LL", "KW_LOAD",
  "KW_SLOAD", "KW_QUIT", "KW_EOF", "KW_TEST", "KW_SMT_SEARCH",
  "KW_VU_NARROW", "KW_FVU_NARROW", "KW_FOLD", "KW_VFOLD", "KW_DESUGARED",
  "KW_PROCESSED", "KW_FRONTIER", "KW_MOST", "KW_GENERAL", "KW_ENDM",
  "KW_IMPORT", "KW_ENDV", "KW_SORT", "KW_SUBSORT", "KW_OP", "KW_OPS",
  "KW_MSGS", "KW_VAR", "KW_CLASS", "KW_SUBCLASS", "KW_DSTRAT", "KW_MB",
  "KW_CMB", "KW_EQ", "KW_CEQ", "KW_RL", "KW_CRL", "KW_SD", "KW_CSD",
  "KW_ATTR", "KW_IS", "KW_FROM", "KW_ARROW", "KW_ARROW2", "KW_PARTIAL",
  "KW_IF", "KW_ASSIGN", "':'", "'='", "'('", "')'", "'.'", "'<'", "'['",
  "']'", "','", "'|'", "'@'", "KW_LABEL", "KW_TO", "KW_COLON2", "'+'",
  "'*'", "'{'", "'}'", "KW_ASSOC", "KW_COMM", "KW_ID", "KW_IDEM",
  "KW_ITER", "KW_PCONST", "KW_LEFT", "KW_RIGHT", "KW_PREC", "KW_GATHER",
  "KW_METADATA", "KW_STRAT", "KW_ASTRAT", "KW_POLY", "KW_MEMO",
  "KW_FROZEN", "KW_CTOR", "KW_LATEX", "KW_SPECIAL", "KW_CONFIG", "KW_OBJ",
  "KW_MSG", "KW_PORTAL", "KW_DITTO", "KW_FORMAT", "KW_ID_HOOK",
  "KW_OP_HOOK", "KW_TERM_HOOK", "KW_IN", "KW_FILTER", "KW_DELAY",
  "IDENTIFIER", "NUMERIC_ID", "ENDS_IN_DOT", "FORCE_LOOKAHEAD",
  "CHANGE_FILE", "END_OF_INPUT", "$accept", "top", "item", "directive",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "moduleExprDot",
  "moduleExpr", "moduleExpr2", "moduleExpr3", "renameExpr", "instantExpr",
  "parenExpr", "viewExpr", "instantArgs", "renaming", "$@8", "$@9",
  "renaming2", "mappingList", "mapping", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "fromSpec", "$@16", "fromAttrSpec", "fromStratSpec",
  "toAttributes", "$@17", "toAttributeList", "toAttribute", "$@18", "$@19",
  "$@20", "view", "$@21", "$@22", "viewDecList", "skipStrayArrow",
  "viewDeclaration", "$@23", "$@24", "$@25", "sortDot", "viewEndOpMap",
  "$@26", "$@27", "$@28", "endMsgMap", "$@29", "$@30", "$@31",
  "strategyCall", "$@32", "viewStratMap", "$@33", "$@34", "endBubble",
  "parenBubble", "$@35", "module", "$@36", "$@37", "dot", "parameters",
  "parameterList", "parameter", "colon2", "badType", "typeDot", "decList",
  "declaration", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44",
  "$@45", "$@46", "$@47", "$@48", "$@49", "$@50", "$@51", "$@52", "$@53",
  "$@54", "$@55", "$@56", "$@57", "$@58", "$@59", "$@60", "$@61", "$@62",
  "$@63", "$@64", "$@65", "classDecl", "$@66", "classDef", "finalPair",
  "cPairList", "cPair", "varNameList", "opNameList", "simpleOpName",
  "domainRangeAttr", "stratDeclKeyword", "stratIdList", "stratId",
  "stratSignature", "stratAttributes", "stratAttrList", "skipStrayColon",
  "dra2", "rangeAttr", "typeAttr", "arrow", "typeList", "typeName1",
  "typeName1Dot", "kind", "$@67", "typeName", "$@68", "sortNames",
  "attributes", "attributeList", "idKeyword", "attribute", "$@69", "$@70",
  "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "identity", "idList",
  "hookList", "hook", "expectedIs", "expectedDot", "sortNameList",
  "endSortNameList", "subsortList", "endSubsortList", "sortName",
  "sortNameFrag", "$@77", "sortNameFrags", "$@78", "tokenDot", "sortToken",
  "token", "stratName", "attributeName", "tokenBarColon", "tokenBarDot",
  "endsInDot", "command", "$@79", "$@80", "$@81", "$@82", "$@83", "$@84",
  "$@85", "$@86", "$@87", "$@88", "$@89", "$@90", "$@91", "$@92", "$@93",
  "$@94", "$@95", "$@96", "$@97", "$@98", "$@99", "$@100", "$@101",
  "$@102", "$@103", "$@104", "$@105", "$@106", "$@107", "$@108", "$@109",
  "$@110", "$@111", "$@112", "$@113", "$@114", "$@115", "$@116", "$@117",
  "$@118", "$@119", "$@120", "$@121", "$@122", "$@123", "$@124", "$@125",
  "$@126", "kw_module", "printOption", "traceOption", "polarityDot",
  "select", "exclude", "conceal", "search", "match", "optDebug",
  "optIrredundant", "optNumber", "optOptions", "optionsList", "option",
  "importMode", "moduleAndTerm", "$@127", "inEnd", "$@128",
  "numberModuleTerm", "$@129", "$@130", "numberModuleTerm1", "$@131",
  "$@132", "numberModuleTerm2", "$@133", "$@134",
  "optionsNumbersModuleTerm", "$@135", "$@136", "$@137",
  "optionsNumbersModuleTerm1", "$@138", "$@139", "$@140",
  "optionsNumbersModuleTerm2", "$@141", "$@142", "numbersModuleTerm",
  "$@143", "$@144", "numbersModuleTerm1", "$@145", "$@146", "$@147",
  "numbersModuleTerm2", "$@148", "$@149", "$@150", "numbersModuleTerm3",
  "$@151", "$@152", "numbersModuleTerm4", "$@153", "$@154",
  "numbersModuleTerm5", "$@155", "$@156", "numbersModuleTerm6", "$@157",
  "$@158", "miscEndBubble", "$@159", "initialEndBubble", "$@160", "$@161",
  "cTokenBarIn", "cTokenBarLeftIn", "cTokenBarOpenLeftIn",
  "cTokenBarDotNumber", "cTokenBarDotRight", "cTokenBarDotCommaNumber",
  "cTokenBarDotCommaRight", "cTokenBarDotCommaClose",
  "cTokenBarDotOptionToken", "opSelect", "endSelect", "badSelect",
  "cOpNameList", "cSimpleOpName", "cSimpleTokenBarDot", "cOptionToken", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1069)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-645)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     795,   -26, -1069, -1069, -1069, -1069, -1069, -1069, -1069,    33,
     958,    20, -1069,   102,   213,    -7, -1069, -1069,   -36,   -33,
      -5,    51, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069,   160, -1069, -1069, -1069, -1069, -1069, -1069, -1069,   461,
     217, -1069, -1069,   127,  1352,  1352,   451,   451,   451,   177,
      88,   380,   482,   262,   354,   354,   354,    24, -1069, -1069,
   -1069, -1069,   207,   354, -1069, -1069, -1069,   266,   -18, -1069,
     156,   159, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,   331,   293,   242, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  -112, -1069, -1069, -1069, -1069,
     189, -1069, -1069, -1069, -1069,   451,   451,  -112,   379,   390,
     402,   405,   408,   427,   451,   272,   429, -1069,   569, -1069,
   -1069, -1069, -1069,   341,   284, -1069, -1069, -1069, -1069,   328,
   -1069,   416, -1069, -1069,    -2, -1069,   319, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069,   216,   354,   354,   354,
     354,   354,   354,   354, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,   354, -1069, -1069, -1069,   318,
     325,   392, -1069,   378, -1069, -1069, -1069, -1069,   406, -1069,
   -1069,   354,   354,   287,   294, -1069, -1069, -1069, -1069, -1069,
     354,   354,   354,   376,   354, -1069,   678,  -112,   299,   356,
     303,   359, -1069, -1069,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112, -1069,   308,   412,
    -112,   784,   784, -1069, -1069, -1069, -1069,   784,   784, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,   451,   569,   459, -1069, -1069,
     808,   808,   569,   569, -1069,   320,   473, -1069, -1069, -1069,
     119, -1069,   808, -1069,   569,   322,   322,  -112,   -97,  -112,
     678,   354,   354, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069,   354, -1069, -1069, -1069,   450, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,   354, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
     362, -1069,   368, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069,  -112, -1069,   377, -1069,
   -1069, -1069, -1069, -1069,   941, -1069, -1069, -1069, -1069, -1069,
    -112,  3068,  -112, -1069, -1069, -1069,   569,   569, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069,    -2, -1069, -1069,
    3086, -1069,  1352,   367,   369, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069,   354, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069,   569, -1069, -1069,  3104,  -112,   569, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069,   137, -1069,   -87, -1069, -1069,  1032,  -112,   354,
   -1069,  -112,  3122,  -112, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    3104,  3140,  -112,  1352, -1069, -1069, -1069,  1032,   788,  1032,
     190,   352,   364, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069,  3158,  3176,  -112, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069,   370,   -73, -1069,  1112, -1069, -1069,
   -1069,  1432,  1432,  1752,  2552, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,    58,
    1032,  1032,   383,  1352,   451,  -112, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069,  3194,  3194,  -112, -1069, -1069, -1069,
     223,   226,   241,   254,   143,   271,   305,   321,   326,   330,
     333,   336,   340,   360,   151, -1069,   373,    26,   157,   191,
   -1069,   363,   384,   385,  2552,  3022,   382, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069,  1192, -1069, -1069, -1069,  1272,  1512, -1069, -1069,
   -1069,   374, -1069, -1069,  3022,   391,   393,   396,   398,   407,
     409,   395,   410,   401,  1832, -1069,   -70, -1069, -1069, -1069,
     394,   169, -1069, -1069, -1069,  3212,  -112,   451,  3230,  -112,
   -1069, -1069, -1069, -1069, -1069,   808, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  1112, -1069, -1069, -1069, -1069,
   -1069, -1069,  2312, -1069, -1069, -1069,  2788,  2552, -1069, -1069,
    1992, -1069,  1992,   397, -1069,    -4, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    1592, -1069, -1069, -1069, -1069,   158,  1352,  1352, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    3140, -1069,  -112, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    2152, -1069,  1992, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    2392, -1069, -1069, -1069, -1069,  2392, -1069, -1069, -1069,  3022,
    -112,   413,  -112,   417,  -112,   421,  -112,   423,  1992, -1069,
    2866, -1069,   418,    34, -1069,  3022, -1069,  3022,  1352,  1352,
    1832, -1069, -1069,   400, -1069,   193,   394,   451,  -112,  3248,
    -112, -1069, -1069, -1069, -1069,  3022, -1069, -1069,   420,  2072,
   -1069, -1069,   384,  1912,   374,   195, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  2710, -1069,   386,  -110,   -59,
   -1069,  3022, -1069,  1752,  3022,  1352,  1832, -1069, -1069,   415,
     422,   419, -1069,   425, -1069,   422,   431,   187, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069,   236, -1069,   859,   384,
   -1069, -1069, -1069,   237, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,   424, -1069,
    2232, -1069, -1069,  -112,  -112,  -112,  -112,  2866,   399,   432,
   -1069, -1069, -1069, -1069,   430,   -65,  1672,   435, -1069,   438,
   -1069,    -6,    13,  3022, -1069,   440,  3022,   441,  1352,    86,
     442, -1069, -1069,   451,  -112, -1069,  3022, -1069, -1069, -1069,
   -1069, -1069, -1069,   436,   449,   411,   460,   426,   468,   469,
     470, -1069,   471, -1069,   474,   476, -1069, -1069, -1069, -1069,
   -1069,   477,   943, -1069, -1069, -1069, -1069, -1069,  2472, -1069,
   -1069, -1069,   103,   122, -1069,  3022, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069,  2552, -1069, -1069, -1069,   397,  2552,   441,
   -1069, -1069,    86, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
    2944,   478, -1069,   479, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,   140,
   -1069, -1069, -1069,   428, -1069, -1069,  3022, -1069, -1069,   374,
   -1069,   384, -1069, -1069,  -112,  2392, -1069,   480,  -112,   458,
     484, -1069,  -112,  2632,   437, -1069, -1069, -1069,  1352,  1832,
     437,   433,   433,   433,   433,   433,   597,  1352,  1352,  1352,
      59, -1069,   433, -1069, -1069,   258, -1069,  2632, -1069, -1069,
    1352, -1069, -1069,  1832,  2632, -1069,  2866, -1069, -1069, -1069,
   -1069, -1069, -1069,   -84,   -82,   -30,   -12,    15,   483,   481,
     481,   481, -1069, -1069,    29, -1069,  2866,   384,   485,  2866,
   -1069,    63, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069,   491, -1069, -1069,   492,   439,   503,   504,
     506,   111, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069,  -112,  -112,   433,   634,   433, -1069, -1069,    35,   507,
      36, -1069, -1069, -1069
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   593,   137,    94,   467,   506,   640,   639,   485,     0,
       0,     0,   463,     0,     0,     0,   641,   643,     0,     0,
       0,     0,   469,   471,   465,   589,    17,    18,    20,    22,
      23,    25,    13,    15,    27,    28,   504,   135,    11,    10,
       3,     0,     2,     8,     7,   508,     6,     9,   491,   648,
       0,     5,     4,     0,     0,     0,     0,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,     0,   654,   655,
     656,   657,     0,     0,   573,   596,   525,     0,     0,   595,
       0,     0,   521,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   555,   523,     0,     0,     0,   519,   628,
     629,   631,   630,   509,   511,     0,   632,   633,   515,   513,
       0,   586,   587,   588,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   473,
     475,   634,   635,   644,     0,   477,   479,   481,   483,   646,
     636,     0,   637,   638,     0,   487,     0,   493,   594,   355,
     334,   356,   335,   336,   337,   338,   346,   339,   342,   343,
     341,   347,   348,   349,   350,   351,   352,   353,   354,   344,
     358,   359,   403,   390,   404,   357,   406,   394,   386,   398,
     396,   399,   400,   397,   387,   395,   361,   360,   405,   388,
     389,   401,   402,   362,   363,   393,   364,   365,   385,   366,
     367,   368,   369,   377,   340,   370,   371,   372,   376,   373,
     374,   375,   378,   379,   345,   380,   381,   382,   383,   384,
     333,   392,   391,   138,    95,   753,   741,   754,   751,   752,
     755,   749,   750,   743,   843,   844,   747,   748,   745,   468,
     658,   659,   746,   507,   486,   576,     0,     0,     0,     0,
       0,     0,     0,     0,   621,   622,   623,   614,   616,   613,
     615,   617,   618,   619,   620,     0,   601,   597,   598,     0,
       0,     0,   609,     0,   602,   603,   604,   605,     0,   611,
     606,     0,     0,     0,     0,   626,   627,   592,   572,   579,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,   529,   530,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,   133,   332,   464,   134,     0,     0,   517,
     470,   472,   466,    19,    21,    24,    26,    14,    16,   505,
     136,    12,   762,   763,   664,   761,   764,   759,   760,   757,
     758,   492,   666,   667,   756,     0,     0,     0,   499,   495,
       0,     0,     0,     0,   645,     0,     0,   653,   651,   652,
       0,   649,     0,   489,     0,   143,   143,     0,     0,     0,
       0,     0,     0,   566,   567,   560,   562,   565,   563,   559,
     571,     0,   569,   600,   599,     0,   610,   608,   568,   591,
     624,   625,   581,   584,   580,     0,   582,   841,   838,   839,
     842,   836,   837,   840,   834,   835,   574,   833,   526,   554,
       0,   551,     0,   522,   532,   534,   536,   538,   540,   542,
     544,   546,   548,   550,   556,   524,     0,   557,     0,   520,
     828,   832,   510,   825,     0,   830,   831,   512,   516,   514,
       0,     0,     0,   474,   476,   501,     0,     0,   699,   478,
     701,   702,   480,   482,   484,   503,   497,     0,   647,   488,
       0,   494,     0,   315,     0,   742,   661,   663,   744,   660,
     577,   561,   564,   570,   607,   585,     0,   552,   553,   528,
     558,   826,   824,   827,   829,   518,   780,   738,   777,   778,
     781,   775,   776,   779,   774,   669,   740,   665,   673,   671,
     773,   668,     0,   500,   496,     0,     0,     0,   650,   770,
     771,   681,   769,   772,   679,   768,   766,   767,   490,   683,
     684,   765,     0,   145,     0,   314,   153,     0,     0,     0,
     575,     0,     0,     0,   502,   798,   795,   796,   706,   793,
     794,   797,   792,   704,   700,   710,   708,   791,   703,   498,
       0,     0,     0,     0,   142,   148,   147,     0,     0,     0,
       0,    37,    39,    40,    42,    41,    43,   662,   578,   739,
     789,   787,   674,   790,   785,   786,   788,   783,   784,   670,
     678,   676,   782,   672,     0,     0,     0,   682,   822,   819,
     820,   823,   817,   818,   821,   686,   688,   815,   816,   680,
     692,   690,   685,   144,   146,     0,   139,     0,   155,   157,
     159,     0,     0,     0,     0,   199,   225,   164,   167,   171,
     174,   178,   181,   185,   188,   224,   194,   152,   192,     0,
       0,     0,     0,     0,     0,     0,   728,   707,   732,   730,
     806,   804,   711,   713,   802,   803,   805,   800,   801,   705,
     717,   715,   799,   709,     0,     0,     0,   201,   203,   202,
     457,   458,   460,   449,    36,   451,   453,   454,   452,   450,
     459,   455,   456,   448,   332,   154,     0,   317,   317,   317,
      35,   447,   317,     0,     0,     0,     0,   443,   444,   446,
     438,   436,   439,   440,   437,   435,   445,   441,   442,   434,
     433,   220,     0,   218,   432,   219,     0,     0,   216,   198,
     204,   325,   206,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,   315,    38,    51,    44,
      50,     0,    48,   675,   677,     0,     0,     0,     0,     0,
     814,   811,   812,   694,   810,     0,   813,   808,   809,   687,
     698,   696,   807,   689,   691,     0,   316,    32,    33,    31,
      29,    30,     0,   156,   319,   320,     0,     0,   158,   160,
       0,   217,     0,   100,   215,   317,   327,   200,   165,   168,
     172,   175,   179,   182,   186,   189,   195,   417,   418,   420,
     412,   410,   413,   414,   411,   419,   415,   416,   409,   408,
       0,   227,   407,   228,    98,     0,     0,     0,    45,   733,
     729,   737,   735,   731,   712,   718,   714,   722,   720,   716,
       0,   693,     0,    34,    38,   140,   321,   318,   141,   323,
       0,   324,     0,   242,   243,   254,   149,   223,   162,   222,
       0,   245,   253,   197,    99,     0,   212,   205,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,   226,   232,     0,    55,     0,    60,     0,     0,     0,
       0,    68,    52,    54,    57,     0,    49,     0,     0,     0,
       0,   695,   697,   322,   161,     0,   241,   239,   259,   235,
     151,   163,   317,     0,   331,     0,   166,   169,   173,   176,
     180,   183,   187,   190,   196,     0,   229,     0,     0,     0,
      96,     0,   103,     0,     0,     0,     0,   109,    97,     0,
      73,     0,    66,     0,    63,    73,     0,     0,    47,   734,
     736,   723,   719,   727,   725,   721,     0,   257,     0,   317,
     234,   237,   238,     0,   221,   244,   150,   428,   429,   431,
     424,   427,   426,   425,   430,   423,   422,   208,     0,   421,
       0,   329,   328,     0,     0,     0,     0,     0,     0,     0,
     193,   111,   113,   112,     0,     0,     0,     0,   107,     0,
     105,   129,     0,     0,    71,     0,     0,    75,     0,    77,
       0,    53,    56,     0,     0,   255,     0,   265,   266,   262,
     269,   270,   303,     0,     0,   272,   275,     0,   281,   284,
     287,   288,   290,   289,   300,     0,   293,   294,   295,   296,
     302,   278,     0,   267,   261,   240,   236,   211,     0,   251,
     214,   210,   317,   317,   249,     0,   170,   177,   184,   191,
     230,   233,   231,     0,   116,   119,   104,   100,     0,    75,
     131,   127,     0,   121,   124,   110,    58,   245,    61,    65,
       0,     0,    59,     0,    76,    69,   724,   726,   256,   263,
     264,   271,   273,   297,   279,   282,   285,   291,   298,     0,
     276,   258,   260,   305,   213,   209,     0,   250,   248,   330,
     101,   317,   115,   245,     0,     0,   106,     0,     0,     0,
       0,   245,     0,     0,    80,    74,   247,   246,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   304,   268,     0,   114,     0,   120,   102,
       0,   132,   128,     0,     0,   125,     0,    78,    62,    67,
      64,    70,   307,     0,     0,     0,     0,     0,     0,   310,
       0,     0,   301,   308,     0,   252,     0,   317,     0,     0,
      72,     0,   274,   306,   280,   283,   286,   292,   299,   311,
     312,   313,   277,     0,   108,   130,     0,    84,    87,    93,
      90,     0,    82,   117,   122,    83,    85,    91,    88,    79,
      81,     0,     0,     0,     0,     0,   118,   123,     0,     0,
       0,    86,    92,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069,  -122,  -531, -1069, -1069,  -591,  -586,  -585,  -165,  -149,
   -1069, -1069, -1069, -1069, -1069,  -266, -1069, -1069, -1069, -1069,
   -1069, -1069,  -263, -1069,  -386, -1069,  -446, -1069, -1069,  -514,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069,  -379, -1069, -1069,
   -1069, -1069,  -378, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069,  -104,     0, -1069, -1069,
   -1069, -1069,  -237,   307, -1069,   121, -1069,  -827,  -420, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  -235,    64,  -376,  -736, -1069,
   -1069,  -120,  -946, -1069, -1069, -1069, -1069,  -262, -1069, -1046,
    -821,  -976,  -346,  -377, -1069,  -700, -1069,  -402, -1069, -1069,
   -1069,  -337, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1068, -1069,  -434,   -39,  -670,  -647,   -79, -1069,   -25,
    -317,  -830, -1069, -1069, -1069,  -590,   -47,   -52,  -860, -1069,
    -617, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069,   633, -1069, -1069,   -24,   688, -1069, -1069, -1069,
   -1069, -1069,   570, -1069, -1069, -1069,   238, -1069,   -46, -1069,
   -1069, -1069,  -323, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  -121, -1069, -1069, -1069,    43,
   -1069, -1069,  -347, -1069, -1069,   150, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069, -1069,
   -1069, -1069, -1069, -1069, -1069,  -447, -1069,  -123, -1069, -1069,
   -1069,  -351, -1069,  -570,  -708, -1069, -1069, -1069, -1069,  -166,
   -1069,   267, -1069,   269,  -252,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    41,    42,    43,   126,   122,   123,   118,   119,   120,
     121,   685,   570,   571,   572,   573,   574,   575,   740,   741,
     739,   815,   936,   882,   883,   884,   930,  1114,   999,   997,
     935,  1120,   995,  1067,  1071,  1073,  1148,  1171,  1191,  1192,
    1203,  1205,  1204,    44,    55,   376,   873,   855,   928,   985,
    1059,   992,  1100,  1056,  1103,  1201,  1104,  1065,  1111,  1202,
    1112,   989,  1109,   990,  1062,  1108,   506,   441,   125,    46,
      54,   375,   836,   473,   532,   533,   567,   847,   901,   568,
     637,   694,   695,   696,   842,   725,   860,   726,   861,   973,
     727,   862,   728,   863,   974,   729,   864,   730,   865,   975,
     731,   866,   732,   867,   976,   734,   733,   868,   724,   719,
     785,   857,   967,   903,   968,   717,   712,   713,   848,   638,
     810,   811,   872,   918,   979,   953,   954,   849,   897,   850,
     899,  1040,  1041,  1042,  1096,   955,   895,   946,   949,  1032,
    1033,  1034,  1093,  1121,  1132,  1122,  1123,  1124,  1125,  1126,
    1134,  1153,  1130,  1131,   536,   767,   776,   773,   777,   778,
     852,   721,   859,   905,  1045,   326,   723,   576,   813,   970,
     715,   692,   693,    47,   105,   117,    56,   115,   116,   355,
     356,   360,   361,   362,   363,    58,   372,   470,   128,   374,
     457,   517,   456,   512,   124,    57,   321,   322,   328,   327,
     450,   320,   304,   316,   297,   436,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   296,   486,   380,
     539,    53,    98,   281,   265,   287,   103,   104,   108,   145,
      48,    49,    50,   365,   146,   370,   371,    74,   239,   379,
     478,   538,   351,   451,   452,   507,   542,   543,   589,   644,
     645,   528,   561,   560,   562,   609,   664,   665,   666,   759,
     830,   832,   459,   515,   516,   554,   595,   594,   596,   659,
     747,   748,   749,   826,   889,   890,   942,  1003,  1004,   647,
     745,   746,   820,   887,   888,   555,   541,   240,   377,   378,
     241,   353,   530,   509,   591,   556,   661,   761,   611,   442,
     492,   443,   444,   445,   446,   354
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   325,   223,   224,   508,   352,   718,   222,   222,   461,
     461,   243,   244,   332,   462,   242,   242,   242,   768,   769,
     934,   461,   770,   896,   649,   469,   687,   690,   900,   904,
      75,   688,   689,   454,   722,   919,   614,   822,   639,   463,
     464,   288,   289,   299,   416,    59,   853,   772,   915,   295,
     323,   471,   835,  1074,  1154,  1155,  1156,  1157,   367,    99,
     100,   476,  1094,    60,  1164,   323,   991,  1146,    61,   330,
     331,   565,   952,   110,   242,   242,    62,  1172,   339,  1174,
     851,   535,   851,   242,   566,    63,   686,    79,    64,   667,
     300,  1166,    65,  1054,  1115,   590,   290,   324,  1169,   324,
     784,   246,   641,   981,   775,  1055,   894,   101,   102,   736,
     737,    66,   324,    67,   610,   858,  1110,    68,    69,    70,
      71,   368,   369,  1173,    72,  1173,   111,   291,   480,   112,
     840,  1175,   914,   513,   514,  1208,    73,  1210,   668,   669,
     247,   248,   851,   249,   250,   251,   252,   648,   660,  1176,
     898,   301,   982,   983,  1061,   902,   447,   113,   766,   874,
     127,   448,   449,   856,  -126,   253,   920,   921,   851,   922,
     916,  1063,   923,   924,   687,   690,  1177,  1173,   828,   688,
     689,   944,   838,  1064,   925,    51,    52,   775,   766,   544,
    1182,   106,   107,   418,   559,  1173,  1211,  1213,   -40,   -40,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   114,   292,  1099,   439,   760,   760,   735,
    1162,   926,  1173,   383,   384,   385,   386,   387,   388,   389,
     641,   927,   956,   352,   834,   147,  1173,   460,   460,   352,
     352,   390,  1173,  1173,   869,   392,  1113,  1187,  1188,   460,
     838,   352,    99,   100,   870,   417,  1189,   398,   399,  1150,
    1127,  1128,  1129,  1190,   245,   766,   402,   403,   404,  -247,
     406,   381,   382,   475,   477,   479,  1199,  1050,   900,  1035,
     417,   417,  1137,  1168,   766,   467,   417,   417,  -246,   148,
    1144,   875,   282,   876,   468,  1187,  1188,   877,   821,   294,
     358,   827,   359,   563,  1189,  -461,   718,   720,   878,   453,
     298,  1190,   564,  -462,   242,  -398,  -398,  -398,   302,   766,
     875,   303,   876,  -392,  -392,  -392,   877,   879,   838,   -42,
     -42,   -42,   489,   352,   352,   817,   781,   878,   317,   417,
     781,  1127,  1128,  1129,   818,   880,   495,   529,   511,   283,
     284,   285,   286,   766,   318,   881,   879,   481,   482,   817,
     640,   971,   641,   -41,   -41,   -41,   391,   483,   938,   784,
     972,   319,  1097,  1098,   880,   393,   394,   774,   774,   329,
    1044,   485,   333,   610,   881,   283,   284,   285,   286,   352,
     843,   254,   844,   334,   352,  -403,  -403,  -403,  -404,  -404,
    -404,  1005,  1006,   417,   461,   902,   335,   774,   831,   336,
     510,   337,   558,  -406,  -406,  -406,   255,   256,   257,   258,
     534,   259,   260,  1165,  1006,   222,  -394,  -394,  -394,   531,
     338,  1136,   341,   340,   577,    17,   364,   579,   366,   593,
     373,   395,   943,  -396,  -396,  -396,  1170,   396,  1044,   400,
     261,   262,   263,   397,   264,   837,   401,   405,   612,   837,
     774,   419,   540,  1102,   420,   421,  1183,   422,  1102,  1186,
     437,   129,   130,   438,   557,   131,   132,  -399,  -399,  -399,
     455,   133,   465,   134,   135,   136,   137,   138,   139,   140,
     222,   466,   663,  -400,  -400,  -400,   472,  1184,  -397,  -397,
    -397,   592,  -395,  -395,  -395,  -405,  -405,  -405,  -401,  -401,
    -401,   534,  -402,  -402,  -402,   578,   222,   484,   535,   557,
     222,   537,   222,   837,   487,   642,   266,   267,   268,   269,
     488,   270,  -393,  -393,  -393,  -391,  -391,  -391,   643,   490,
     779,   744,   641,   738,   271,   765,   766,   771,   786,   788,
     854,   789,   794,   510,   662,   790,   141,   791,   929,   796,
     931,   792,   764,   793,   272,   273,   937,   795,   816,   907,
     691,   274,   978,   909,   714,   714,   714,   911,   947,   913,
     994,   142,   917,   143,   948,   993,   275,   276,   277,   996,
    1037,   742,  1001,   222,   222,   998,   222,  1052,   743,  1070,
    1053,  1147,  1158,   242,   984,  1058,  1051,   987,  1060,   225,
    1068,   226,  1075,   227,  1079,   228,   229,   230,  1081,  1142,
    1082,   711,   711,   762,   762,   231,   232,  1080,  1084,  1085,
    1086,  1087,   460,  1083,  1088,   144,  1089,  1090,  1133,  1209,
    1152,    37,   823,   833,  1178,   829,  1195,  1185,  1118,  1119,
    1140,   278,   886,  1043,  1143,   233,   234,   235,   236,   237,
     238,  1193,  1194,  1196,  1197,   714,  1198,   885,  1212,   714,
     714,  1002,  1000,  1107,  1151,   279,  1066,  1200,  1105,  1069,
    1106,   980,   280,   474,   613,  1139,   716,   812,   986,  1078,
     871,  1036,  1095,  1116,  1135,  1092,  1163,   814,   841,   787,
     293,   824,   109,   357,   592,   518,   242,   510,   763,   891,
     597,   493,   711,   494,     0,     0,   711,     0,   691,     0,
       0,  1043,     0,     0,     0,     0,     0,   342,   892,   226,
       0,   343,     0,   344,   345,   346,  1101,     0,     0,     0,
       0,  1101,     0,   347,   348,     0,     0,     0,     0,     0,
       0,     0,     0,  1117,     0,     0,   906,     0,   908,     0,
     910,     0,   912,   812,   742,   742,     0,     0,     0,   222,
     222,     0,     0,   233,   234,   235,   349,   350,   238,   947,
       0,     0,     0,     0,   940,     0,   945,     0,     0,   615,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     2,     3,     4,     0,  -642,  -642,     0,     5,  -642,
    -642,     6,     7,  -644,     8,  -642,     0,  -642,  -642,  -642,
    -642,  -642,  -642,  -642,     9,    10,   932,   933,     0,     0,
      11,   222,   222,   812,    12,     0,   407,     0,    13,     0,
       0,   939,   408,   409,   410,     0,   242,     0,   592,     0,
       0,     0,   411,   412,    14,     0,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,   988,    15,     0,   714,     0,   222,   812,
       0,     0,   413,   234,   235,   414,   415,     0,    16,    17,
    -642,    18,    19,    20,    21,    22,    23,    24,     0,     0,
    1077,     0,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,  -642,  -642,  -642,   616,   617,
       0,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,     0,   714,
       0,     0,   407,     0,    37,     0,  1072,     0,   408,   409,
     410,   222,     0,     0,     0,    37,     0,  1076,   411,   412,
       0,     0,   242,     0,    75,    76,   342,     0,   226,  -642,
     343,     0,   458,   345,   346,   635,     0,     0,     0,     0,
       0,     0,   347,   348,     0,   636,    77,     0,   413,   234,
     235,   414,   415,   440,     0,     0,     0,     0,     0,    38,
    1138,     0,     0,     0,  1141,     0,    39,    40,  1145,     0,
       0,     0,   233,   234,   235,   349,   350,   238,    78,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
       0,    93,     0,     0,     0,     0,  1149,     0,     0,     0,
       0,   222,   812,     0,     0,  1159,  1160,  1161,     0,     0,
     222,   222,   222,    94,    95,    96,    97,     0,  1167,     0,
       0,     0,     0,   222,     0,     0,   812,  1206,  1207,   407,
       0,    37,     0,   491,     0,   408,   409,   410,  1091,     0,
       0,     0,     0,     0,     0,   411,   412,     0,     0,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,     0,   413,   234,   235,   414,   415,
     440,     0,     0,     0,     0,     0,     0,     0,     0,  1179,
    1180,  1181,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   569,     0,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   221,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   670,   173,   671,   175,   672,
     673,   178,   569,     0,   674,   675,   676,   677,   678,   184,
     679,   186,   187,   680,   189,   190,   681,   682,   193,   194,
     683,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   684,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
     780,   178,    37,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
     782,   178,    37,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   221,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
       0,   178,    37,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
     783,   178,     0,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   797,   173,   798,   175,   799,
     869,   178,     0,     0,   800,   801,   802,   803,   804,   184,
     870,   186,   187,   805,   189,   190,   806,   807,   193,   194,
     808,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   809,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
    1057,   178,     0,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   697,   173,   698,   175,   699,
       0,   178,     0,     0,   700,   701,   702,   703,   704,   184,
     705,   186,   187,   706,   189,   190,   707,   708,   193,   194,
     709,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   710,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   797,   173,   798,   175,   799,
       0,   178,     0,     0,   800,   801,   802,   803,   804,   184,
       0,   186,   187,   805,   189,   190,   806,   807,   193,   194,
     808,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   809,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   957,   173,   958,   175,   959,
     960,   178,     0,     0,   961,   962,     0,     0,     0,   184,
     963,   186,   187,   964,   189,   190,     0,     0,   193,   194,
     965,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   966,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   843,   173,   844,   175,     0,
       0,   178,     0,     0,     0,     0,   845,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   846,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
     950,   178,     0,     0,   951,     0,   845,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   846,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,   835,   893,     0,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   324,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
    1038,   178,     0,     0,     0,     0,  1039,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   324,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,   835,     0,     0,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   324,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,     0,     0,   845,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   846,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,     0,     0,  1039,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   324,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
       0,   324,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   843,   173,   844,   175,     0,
       0,   178,     0,     0,     0,     0,   845,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,     0,     0,     0,   220,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   173,     0,   175,     0,     0,   178,
       0,     0,     0,     0,   845,     0,     0,   184,   977,   186,
     187,     0,   189,   190,     0,     0,   193,   194,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,     0,   215,
     216,   217,   218,   219,     0,     0,     0,   220,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,   173,     0,   175,     0,     0,   178,     0,     0,
       0,   839,     0,     0,     0,   184,     0,   186,   187,     0,
     189,   190,     0,     0,   193,   194,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,     0,   215,   216,   217,
     218,   219,     0,     0,     0,   220,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     173,     0,   175,     0,     0,   178,     0,     0,     0,     0,
     845,     0,     0,   184,     0,   186,   187,     0,   189,   190,
       0,     0,   193,   194,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,     0,   215,   216,   217,   218,   219,
       0,     0,     0,   220,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,   173,     0,
     175,     0,     0,   178,     0,     0,     0,     0,  1039,     0,
       0,   184,     0,   186,   187,     0,   189,   190,     0,     0,
     193,   194,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,     0,   215,   216,   217,   218,   219,     0,     0,
       0,   220,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,   173,     0,   175,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,   184,
       0,   186,   187,     0,   189,   190,     0,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,   215,   216,   217,   218,   219,   496,     0,   497,   220,
     323,     0,   498,   499,   500,     0,     0,     0,     0,     0,
       0,     0,   501,   502,   519,     0,   226,     0,   520,     0,
     521,   522,   523,     0,     0,     0,     0,     0,     0,     0,
     524,   525,   545,     0,   497,     0,   323,     0,   546,   547,
     548,     0,   503,   234,   235,   504,   505,   324,   549,   550,
     580,     0,   497,     0,   323,     0,   581,   582,   583,     0,
     233,   234,   235,   526,   527,   238,   584,   585,   598,     0,
     497,     0,   323,     0,   599,   600,   601,     0,   551,   234,
     235,   552,   553,   324,   602,   603,   496,     0,   497,     0,
     323,     0,   498,   499,   500,     0,   586,   234,   235,   587,
     588,   324,   501,   502,   650,     0,   497,     0,   323,     0,
     651,   652,   653,     0,   604,   605,   606,   607,   608,   324,
     654,   655,   750,     0,   497,     0,   323,     0,   751,   752,
     753,     0,   503,   234,   235,   504,   646,   324,   754,   755,
     580,     0,   497,     0,   323,     0,   581,   819,   583,     0,
     656,   234,   235,   657,   658,   324,   584,   585,   496,     0,
     497,     0,   323,     0,   498,   499,   500,     0,   756,   234,
     235,   757,   758,   324,   501,   502,   580,     0,   497,     0,
     323,     0,   581,   941,   583,     0,   586,   234,   235,   587,
     588,   324,   584,   585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,   234,   235,   504,   825,   324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   234,   235,   587,   588,   324
};

static const yytype_int16 yycheck[] =
{
       0,   105,    54,    55,   451,   128,   623,    54,    55,   360,
     361,    57,    58,   117,   361,    56,    57,    58,   688,   689,
     880,   372,   692,   850,   594,   372,   617,   617,   855,   859,
       6,   617,   617,   356,   624,     1,   567,   745,   569,   362,
     363,    65,    66,    61,   296,    12,   782,   694,   869,    73,
     162,   374,   162,   999,  1122,  1123,  1124,  1125,    60,    39,
      40,   158,  1038,    30,  1132,   162,   926,  1113,    35,   115,
     116,   158,   899,    80,   115,   116,    43,   161,   124,   161,
     780,   151,   782,   124,   171,    52,   617,    63,    55,   162,
     108,  1137,    59,   158,  1070,   542,    72,   209,  1144,   209,
     717,    13,   172,   162,   694,   170,   842,    87,    88,   640,
     641,    78,   209,    80,   561,   785,  1062,    84,    85,    86,
      87,   123,   124,   207,    91,   207,   162,   103,   380,   162,
     777,   161,   868,   456,   457,  1203,   103,  1205,   211,   212,
      52,    53,   842,    55,    56,    57,    58,   594,   595,   161,
     850,   169,   211,   212,   160,   855,   322,   162,   162,     1,
       0,   327,   328,   167,   170,    77,   132,   133,   868,   135,
     870,   158,   138,   139,   765,   765,   161,   207,   748,   765,
     765,   889,   772,   170,   150,   211,   212,   777,   162,   512,
     161,    89,    90,   297,   517,   207,   161,   161,   172,   173,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   162,   190,  1045,   320,   664,   665,   161,
     161,   187,   207,   247,   248,   249,   250,   251,   252,   253,
     172,   197,   902,   356,   765,    18,   207,   360,   361,   362,
     363,   265,   207,   207,   158,   269,  1067,   184,   185,   372,
     840,   374,    39,    40,   168,   296,   193,   281,   282,  1119,
     201,   202,   203,   200,    87,   162,   290,   291,   292,   166,
     294,    55,    56,   377,   378,   379,   165,   977,  1105,   949,
     321,   322,  1103,  1143,   162,   166,   327,   328,   166,   162,
    1111,   133,    30,   135,   175,   184,   185,   139,   745,    92,
      16,   748,    18,   166,   193,   162,   923,   624,   150,   355,
      44,   200,   175,   162,   355,   172,   173,   174,   162,   162,
     133,   162,   135,   172,   173,   174,   139,   169,   918,   172,
     173,   174,   436,   456,   457,   166,   712,   150,     7,   380,
     716,   201,   202,   203,   175,   187,   450,   470,   452,    31,
      32,    33,    34,   162,    61,   197,   169,   381,   382,   166,
     170,   166,   172,   172,   173,   174,    48,   391,   175,   986,
     175,   129,  1042,  1043,   187,    50,    51,   694,   695,   190,
     970,   405,     3,   830,   197,    31,    32,    33,    34,   512,
     153,    11,   155,     3,   517,   172,   173,   174,   172,   173,
     174,   165,   166,   444,   755,  1105,     4,   724,   755,     4,
     451,     3,   516,   172,   173,   174,    36,    37,    38,    39,
     472,    41,    42,   165,   166,   472,   172,   173,   174,   470,
       3,  1101,     3,   161,   538,    94,   108,   541,    22,   543,
     121,    49,   889,   172,   173,   174,  1146,    69,  1038,   162,
      70,    71,    72,    47,    74,   772,   162,    81,   562,   776,
     777,   162,   486,  1053,   108,   162,  1166,   108,  1058,  1169,
     162,    10,    11,    61,   515,    14,    15,   172,   173,   174,
      21,    20,   162,    22,    23,    24,    25,    26,    27,    28,
     537,    18,   596,   172,   173,   174,   174,  1167,   172,   173,
     174,   542,   172,   173,   174,   172,   173,   174,   172,   173,
     174,   563,   172,   173,   174,   539,   563,    67,   151,   560,
     567,   152,   569,   840,   162,   173,    44,    45,    46,    47,
     162,    49,   172,   173,   174,   172,   173,   174,   174,   162,
     158,   645,   172,   160,    62,   172,   162,   162,   174,   158,
     153,   158,   157,   594,   595,   159,    95,   159,   875,   158,
     877,   154,   666,   154,    82,    83,   166,   157,   174,   156,
     617,    89,   186,   156,   621,   622,   623,   156,   895,   156,
     158,   120,   164,   122,   164,   170,   104,   105,   106,   170,
     166,   643,   161,   640,   641,   170,   643,   165,   644,   158,
     170,   164,     5,   644,   921,   170,   207,   924,   170,   158,
     170,   160,   170,   162,   178,   164,   165,   166,   207,   161,
     160,   621,   622,   664,   665,   174,   175,   178,   160,   160,
     160,   160,   755,   207,   160,   174,   160,   160,   210,     5,
     207,   160,   746,   765,   161,   749,   207,   162,   170,   170,
     170,   169,   817,   970,   170,   204,   205,   206,   207,   208,
     209,   170,   170,   160,   160,   712,   160,   816,   161,   716,
     717,   937,   935,  1059,  1120,   193,   993,  1191,  1057,   996,
    1058,   918,   200,   376,   563,  1105,   622,   734,   923,  1006,
     810,   953,  1038,  1070,  1096,  1032,  1130,   736,   777,   724,
      67,   747,    14,   133,   745,   467,   747,   748,   665,   830,
     560,   444,   712,   444,    -1,    -1,   716,    -1,   765,    -1,
      -1,  1038,    -1,    -1,    -1,    -1,    -1,   158,   832,   160,
      -1,   162,    -1,   164,   165,   166,  1053,    -1,    -1,    -1,
      -1,  1058,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1070,    -1,    -1,   860,    -1,   862,    -1,
     864,    -1,   866,   810,   816,   817,    -1,    -1,    -1,   816,
     817,    -1,    -1,   204,   205,   206,   207,   208,   209,  1096,
      -1,    -1,    -1,    -1,   888,    -1,   890,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   878,   879,    -1,    -1,
      35,   878,   879,   880,    39,    -1,   158,    -1,    43,    -1,
      -1,   887,   164,   165,   166,    -1,   887,    -1,   889,    -1,
      -1,    -1,   174,   175,    59,    -1,   903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   973,
     974,   975,   976,   925,    79,    -1,   923,    -1,   925,   926,
      -1,    -1,   204,   205,   206,   207,   208,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
    1004,    -1,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   130,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   986,
      -1,    -1,   158,    -1,   160,    -1,   998,    -1,   164,   165,
     166,   998,    -1,    -1,    -1,   160,    -1,  1003,   174,   175,
      -1,    -1,  1003,    -1,     6,     7,   158,    -1,   160,   174,
     162,    -1,   164,   165,   166,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,    -1,   197,    28,    -1,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,   204,
    1104,    -1,    -1,    -1,  1108,    -1,   211,   212,  1112,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   103,    -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,
      -1,  1118,  1119,    -1,    -1,  1127,  1128,  1129,    -1,    -1,
    1127,  1128,  1129,   125,   126,   127,   128,    -1,  1140,    -1,
      -1,    -1,    -1,  1140,    -1,    -1,  1143,  1201,  1202,   158,
      -1,   160,    -1,   162,    -1,   164,   165,   166,   165,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,    -1,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,
    1160,  1161,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
     158,   159,    -1,    -1,   162,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
      -1,   209,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,    -1,    -1,    -1,   207,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,   154,    -1,   156,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,    -1,    -1,   167,   168,   169,
     170,    -1,   172,   173,    -1,    -1,   176,   177,    -1,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,    -1,    -1,    -1,   207,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,    -1,   169,   170,    -1,
     172,   173,    -1,    -1,   176,   177,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,    -1,    -1,    -1,   207,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
     154,    -1,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,
     164,    -1,    -1,   167,    -1,   169,   170,    -1,   172,   173,
      -1,    -1,   176,   177,    -1,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
      -1,    -1,    -1,   207,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,    -1,
     156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
      -1,   167,    -1,   169,   170,    -1,   172,   173,    -1,    -1,
     176,   177,    -1,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,    -1,    -1,
      -1,   207,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,   169,   170,    -1,   172,   173,    -1,    -1,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   158,    -1,   160,   207,
     162,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   158,    -1,   160,    -1,   162,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   158,    -1,   160,    -1,   162,    -1,   164,   165,
     166,    -1,   204,   205,   206,   207,   208,   209,   174,   175,
     158,    -1,   160,    -1,   162,    -1,   164,   165,   166,    -1,
     204,   205,   206,   207,   208,   209,   174,   175,   158,    -1,
     160,    -1,   162,    -1,   164,   165,   166,    -1,   204,   205,
     206,   207,   208,   209,   174,   175,   158,    -1,   160,    -1,
     162,    -1,   164,   165,   166,    -1,   204,   205,   206,   207,
     208,   209,   174,   175,   158,    -1,   160,    -1,   162,    -1,
     164,   165,   166,    -1,   204,   205,   206,   207,   208,   209,
     174,   175,   158,    -1,   160,    -1,   162,    -1,   164,   165,
     166,    -1,   204,   205,   206,   207,   208,   209,   174,   175,
     158,    -1,   160,    -1,   162,    -1,   164,   165,   166,    -1,
     204,   205,   206,   207,   208,   209,   174,   175,   158,    -1,
     160,    -1,   162,    -1,   164,   165,   166,    -1,   204,   205,
     206,   207,   208,   209,   174,   175,   158,    -1,   160,    -1,
     162,    -1,   164,   165,   166,    -1,   204,   205,   206,   207,
     208,   209,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,     6,     7,     8,    13,    16,    17,    19,    29,
      30,    35,    39,    43,    59,    79,    93,    94,    96,    97,
      98,    99,   100,   101,   102,   107,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   160,   204,   211,
     212,   214,   215,   216,   256,   280,   282,   386,   443,   444,
     445,   211,   212,   434,   283,   257,   389,   408,   398,    12,
      30,    35,    43,    52,    55,    59,    78,    80,    84,    85,
      86,    87,    91,   103,   450,     6,     7,    28,    60,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   103,   125,   126,   127,   128,   435,    39,
      40,    87,    88,   439,   440,   387,    89,    90,   441,   439,
      80,   162,   162,   162,   162,   390,   391,   388,   220,   221,
     222,   223,   218,   219,   407,   281,   217,     0,   401,    10,
      11,    14,    15,    20,    22,    23,    24,    25,    26,    27,
      28,    95,   120,   122,   174,   442,   447,    18,   162,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   199,   200,   201,   202,   203,
     207,   209,   379,   380,   380,   158,   160,   162,   164,   165,
     166,   174,   175,   204,   205,   206,   207,   208,   209,   451,
     500,   503,   518,   451,   451,    87,    13,    52,    53,    55,
      56,    57,    58,    77,    11,    36,    37,    38,    39,    41,
      42,    70,    71,    72,    74,   437,    44,    45,    46,    47,
      49,    62,    82,    83,    89,   104,   105,   106,   169,   193,
     200,   436,    30,    31,    32,    33,    34,   438,   438,   438,
      72,   103,   190,   435,    92,   438,   430,   417,    44,    61,
     108,   169,   162,   162,   415,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   416,     7,    61,   129,
     414,   409,   410,   162,   209,   279,   378,   412,   411,   190,
     451,   451,   279,     3,     3,     4,     4,     3,     3,   451,
     161,     3,   158,   162,   164,   165,   166,   174,   175,   207,
     208,   455,   500,   504,   518,   392,   393,   445,    16,    18,
     394,   395,   396,   397,   108,   446,    22,    60,   123,   124,
     448,   449,   399,   121,   402,   284,   258,   501,   502,   452,
     432,    55,    56,   438,   438,   438,   438,   438,   438,   438,
     438,    48,   438,    50,    51,    49,    69,    47,   438,   438,
     162,   162,   438,   438,   438,    81,   438,   158,   164,   165,
     166,   174,   175,   204,   207,   208,   517,   518,   279,   162,
     108,   162,   108,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   418,   162,    61,   279,
     209,   280,   512,   514,   515,   516,   517,   512,   512,   512,
     413,   456,   457,   451,   455,    21,   405,   403,   164,   475,
     500,   504,   475,   455,   455,   162,    18,   166,   175,   475,
     400,   455,   174,   286,   286,   279,   158,   279,   453,   279,
     517,   438,   438,   438,    67,   438,   431,   162,   162,   279,
     162,   162,   513,   514,   516,   279,   158,   160,   164,   165,
     166,   174,   175,   204,   207,   208,   279,   458,   498,   506,
     518,   279,   406,   455,   455,   476,   477,   404,   449,   158,
     162,   164,   165,   166,   174,   175,   207,   208,   464,   500,
     505,   518,   287,   288,   380,   151,   367,   152,   454,   433,
     438,   499,   459,   460,   455,   158,   164,   165,   166,   174,
     175,   204,   207,   208,   478,   498,   508,   518,   279,   455,
     466,   465,   467,   166,   175,   158,   171,   289,   292,   160,
     225,   226,   227,   228,   229,   230,   380,   279,   438,   279,
     158,   164,   165,   166,   174,   175,   204,   207,   208,   461,
     498,   507,   518,   279,   480,   479,   481,   478,   158,   164,
     165,   166,   174,   175,   204,   205,   206,   207,   208,   468,
     498,   511,   279,   288,   225,     1,   130,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   187,   197,   293,   332,   225,
     170,   172,   173,   174,   462,   463,   208,   492,   498,   506,
     158,   164,   165,   166,   174,   175,   204,   207,   208,   482,
     498,   509,   518,   279,   469,   470,   471,   162,   211,   212,
     153,   155,   157,   158,   162,   163,   164,   165,   166,   168,
     171,   174,   175,   178,   209,   224,   225,   228,   229,   230,
     378,   379,   384,   385,   294,   295,   296,   153,   155,   157,
     162,   163,   164,   165,   166,   168,   171,   174,   175,   178,
     209,   280,   329,   330,   379,   383,   329,   328,   383,   322,
     373,   374,   378,   379,   321,   298,   300,   303,   305,   308,
     310,   313,   315,   319,   318,   161,   225,   225,   160,   233,
     231,   232,   380,   451,   279,   493,   494,   483,   484,   485,
     158,   164,   165,   166,   174,   175,   204,   207,   208,   472,
     498,   510,   518,   472,   279,   172,   162,   368,   368,   368,
     368,   162,   369,   370,   373,   378,   369,   371,   372,   158,
     158,   330,   158,   158,   383,   323,   174,   372,   158,   158,
     159,   159,   154,   154,   157,   157,   158,   153,   155,   157,
     162,   163,   164,   165,   166,   171,   174,   175,   178,   209,
     333,   334,   379,   381,   367,   234,   174,   166,   175,   165,
     495,   498,   507,   279,   451,   208,   486,   498,   506,   279,
     473,   475,   474,   224,   225,   162,   285,   373,   378,   163,
     369,   370,   297,   153,   155,   164,   209,   290,   331,   340,
     342,   348,   373,   331,   153,   260,   167,   324,   368,   375,
     299,   301,   304,   306,   309,   311,   314,   316,   320,   158,
     168,   334,   335,   259,     1,   133,   135,   139,   150,   169,
     187,   197,   236,   237,   238,   232,   231,   496,   497,   487,
     488,   468,   279,   163,   331,   349,   290,   341,   348,   343,
     290,   291,   348,   326,   374,   376,   279,   156,   279,   156,
     279,   156,   279,   156,   331,   343,   348,   164,   336,     1,
     132,   133,   135,   138,   139,   150,   187,   197,   261,   373,
     239,   373,   380,   380,   381,   243,   235,   166,   175,   451,
     279,   165,   489,   498,   507,   279,   350,   373,   164,   351,
     158,   162,   290,   338,   339,   348,   368,   153,   155,   157,
     158,   162,   163,   168,   171,   178,   209,   325,   327,   379,
     382,   166,   175,   302,   307,   312,   317,   168,   186,   337,
     285,   162,   211,   212,   373,   262,   328,   373,   380,   274,
     276,   381,   264,   170,   158,   245,   170,   242,   170,   241,
     245,   161,   238,   490,   491,   165,   166,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   352,   353,   354,   368,   340,   166,   158,   164,
     344,   345,   346,   373,   378,   377,   279,   279,   279,   279,
     348,   207,   165,   170,   158,   170,   266,   158,   170,   263,
     170,   160,   277,   158,   170,   270,   373,   246,   170,   373,
     158,   247,   380,   248,   335,   170,   451,   279,   373,   178,
     178,   207,   160,   207,   160,   160,   160,   160,   160,   160,
     160,   165,   354,   355,   344,   345,   347,   368,   368,   374,
     265,   373,   378,   267,   269,   260,   265,   247,   278,   275,
     335,   271,   273,   343,   240,   344,   346,   373,   170,   170,
     244,   356,   358,   359,   360,   361,   362,   201,   202,   203,
     365,   366,   357,   210,   363,   350,   368,   343,   279,   291,
     170,   279,   161,   170,   343,   279,   342,   164,   249,   380,
     381,   249,   207,   364,   364,   364,   364,   364,     5,   380,
     380,   380,   161,   366,   364,   165,   342,   380,   381,   342,
     348,   250,   161,   207,   161,   161,   161,   161,   161,   280,
     280,   280,   161,   348,   368,   162,   348,   184,   185,   193,
     200,   251,   252,   170,   170,   207,   160,   160,   160,   165,
     252,   268,   272,   253,   255,   254,   279,   279,   364,     5,
     364,   161,   161,   161
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   213,   214,   214,   214,   214,   215,   215,   215,   215,
     215,   217,   216,   218,   216,   219,   216,   216,   220,   216,
     221,   216,   216,   222,   216,   223,   216,   216,   216,   224,
     224,   224,   224,   224,   224,   224,   224,   225,   225,   226,
     226,   227,   227,   227,   228,   229,   230,   231,   231,   232,
     232,   234,   235,   233,   236,   236,   237,   237,   238,   238,
     239,   240,   238,   241,   238,   238,   242,   238,   243,   244,
     238,   246,   245,   245,   247,   247,   248,   248,   250,   249,
     249,   251,   251,   252,   252,   253,   252,   252,   254,   252,
     252,   255,   252,   252,   257,   258,   256,   259,   259,   260,
     260,   261,   261,   262,   261,   261,   261,   263,   261,   264,
     261,   261,   261,   261,   265,   265,   267,   268,   266,   269,
     266,   271,   272,   270,   273,   270,   274,   275,   274,   277,
     276,   278,   276,   279,   279,   281,   280,   283,   284,   282,
     285,   285,   286,   286,   287,   287,   288,   289,   289,   290,
     291,   291,   292,   292,   293,   294,   293,   295,   293,   296,
     297,   293,   293,   293,   298,   299,   293,   300,   301,   302,
     293,   303,   304,   293,   305,   306,   307,   293,   308,   309,
     293,   310,   311,   312,   293,   313,   314,   293,   315,   316,
     317,   293,   318,   293,   319,   320,   293,   293,   293,   321,
     293,   293,   293,   293,   323,   322,   322,   324,   324,   325,
     325,   326,   326,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   331,   332,   332,   333,   333,   334,   335,
     335,   336,   336,   337,   338,   338,   339,   339,   339,   340,
     341,   341,   342,   342,   343,   343,   344,   344,   345,   345,
     345,   347,   346,   348,   349,   348,   350,   350,   351,   351,
     352,   352,   353,   353,   353,   354,   354,   355,   354,   354,
     354,   354,   354,   356,   354,   354,   357,   354,   354,   358,
     354,   354,   359,   354,   354,   360,   354,   354,   354,   354,
     354,   361,   354,   354,   354,   354,   354,   354,   362,   354,
     354,   354,   354,   354,   363,   363,   364,   364,   365,   365,
     366,   366,   366,   366,   367,   367,   368,   368,   369,   369,
     370,   370,   371,   371,   372,   373,   374,   375,   374,   377,
     376,   376,   378,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   385,   385,   387,   386,   388,   386,   389,   386,   390,
     386,   391,   386,   392,   386,   393,   386,   394,   386,   395,
     386,   396,   386,   397,   386,   398,   386,   399,   386,   400,
     386,   401,   386,   402,   386,   403,   386,   404,   386,   405,
     386,   406,   386,   386,   407,   386,   408,   386,   386,   409,
     386,   410,   386,   411,   386,   412,   386,   413,   386,   414,
     386,   415,   386,   416,   386,   417,   386,   418,   386,   386,
     386,   419,   386,   420,   386,   421,   386,   422,   386,   423,
     386,   424,   386,   425,   386,   426,   386,   427,   386,   428,
     386,   386,   386,   386,   386,   429,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   430,   431,   386,   432,   433,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   434,   386,   435,   435,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   438,   438,   438,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   442,   442,   442,   443,
     443,   444,   444,   445,   445,   446,   446,   447,   447,   448,
     448,   449,   449,   449,   450,   450,   450,   450,   451,   452,
     451,   454,   453,   453,   456,   455,   455,   457,   455,   459,
     458,   460,   458,   458,   462,   461,   463,   461,   461,   465,
     464,   466,   464,   464,   467,   464,   469,   468,   470,   468,
     471,   468,   468,   472,   473,   472,   474,   472,   472,   476,
     475,   475,   477,   475,   479,   478,   480,   478,   481,   478,
     478,   483,   482,   484,   482,   485,   482,   482,   487,   486,
     488,   486,   486,   490,   489,   491,   489,   489,   493,   492,
     494,   492,   492,   496,   495,   497,   495,   495,   499,   498,
     498,   501,   500,   502,   500,   500,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   505,   505,   505,   505,   505,
     505,   505,   505,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   508,   508,   508,   508,   508,   508,   508,   508,   509,
     509,   509,   509,   509,   509,   509,   509,   510,   510,   510,
     510,   510,   510,   510,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   512,   512,   513,   513,   514,   515,
     515,   516,   516,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   518,   518
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     1,     2,
       2,     2,     2,     2,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     4,     3,     4,     1,     3,
       1,     0,     0,     5,     1,     1,     3,     1,     4,     4,
       0,     0,     6,     0,     6,     4,     0,     6,     0,     0,
       6,     0,     5,     0,     2,     0,     1,     0,     0,     4,
       0,     2,     1,     2,     1,     0,     5,     1,     0,     5,
       1,     0,     5,     1,     0,     0,    12,     2,     0,     1,
       0,     4,     5,     0,     3,     2,     4,     0,     7,     0,
       3,     2,     2,     2,     2,     1,     0,     0,     8,     0,
       3,     0,     0,     8,     0,     3,     1,     0,     4,     0,
       6,     0,     4,     1,     1,     0,     3,     0,     0,     8,
       1,     1,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     1,     2,     0,     2,     0,     3,     0,     3,     0,
       0,     5,     4,     5,     0,     0,     5,     0,     0,     0,
       7,     0,     0,     5,     0,     0,     0,     7,     0,     0,
       5,     0,     0,     0,     7,     0,     0,     5,     0,     0,
       0,     7,     0,     6,     0,     0,     5,     4,     2,     0,
       3,     2,     2,     2,     0,     3,     1,     1,     3,     3,
       2,     3,     0,     3,     2,     2,     1,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     2,
       4,     3,     0,     2,     1,     0,     2,     1,     1,     2,
       3,     1,     1,     1,     2,     0,     1,     1,     2,     1,
       2,     0,     4,     1,     0,     4,     3,     1,     3,     0,
       2,     1,     1,     2,     2,     1,     1,     0,     3,     1,
       1,     2,     1,     0,     5,     1,     0,     5,     1,     0,
       5,     1,     0,     5,     1,     0,     5,     1,     1,     1,
       1,     0,     5,     1,     1,     1,     1,     2,     0,     5,
       1,     4,     1,     1,     1,     0,     2,     1,     2,     1,
       2,     3,     3,     3,     1,     0,     1,     0,     2,     1,
       1,     2,     3,     2,     2,     1,     1,     0,     5,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     3,     0,     4,     0,
       5,     0,     3,     0,     4,     0,     5,     0,     6,     0,
       5,     0,     6,     4,     0,     3,     0,     3,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     5,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     5,     3,
       3,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     4,     5,     5,     4,     0,     4,     4,     5,     4,
       4,     5,     4,     4,     5,     4,     4,     4,     4,     4,
       5,     4,     3,     0,     0,     6,     0,     0,     7,     3,
       4,     4,     4,     3,     4,     5,     2,     2,     2,     1,
       2,     4,     3,     0,     3,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       2,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     0,     3,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     3,     1,     0,     3,     1,     0,     3,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     1,     0,
       3,     0,     3,     1,     0,     3,     0,     3,     0,     3,
       0,     3,     1,     2,     0,     3,     0,     3,     1,     0,
       3,     1,     0,     3,     0,     3,     0,     3,     0,     3,
       1,     0,     3,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       0,     3,     1,     0,     3,     0,     3,     1,     0,     3,
       1,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (parseResult, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parseResult); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parseResult);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parseResult);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, UserLevelRewritingContext::ParseResult* parseResult)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parseResult);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parseResult); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, UserLevelRewritingContext::ParseResult* parseResult)
{
  YY_USE (yyvaluep);
  YY_USE (parseResult);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_moduleExprDot: /* moduleExprDot  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2877 "surface.c"
        break;

    case YYSYMBOL_moduleExpr: /* moduleExpr  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2883 "surface.c"
        break;

    case YYSYMBOL_moduleExpr2: /* moduleExpr2  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2889 "surface.c"
        break;

    case YYSYMBOL_moduleExpr3: /* moduleExpr3  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2895 "surface.c"
        break;

    case YYSYMBOL_renameExpr: /* renameExpr  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2901 "surface.c"
        break;

    case YYSYMBOL_instantExpr: /* instantExpr  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2907 "surface.c"
        break;

    case YYSYMBOL_parenExpr: /* parenExpr  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyModuleExpression)->deepSelfDestruct(); }
#line 2913 "surface.c"
        break;

    case YYSYMBOL_viewExpr: /* viewExpr  */
#line 137 "surface.yy"
            { ((*yyvaluep).yyViewExpression)->deepSelfDestruct(); }
#line 2919 "surface.c"
        break;

    case YYSYMBOL_instantArgs: /* instantArgs  */
#line 138 "surface.yy"
            { deepSelfDestructViewExpressionVector(((*yyvaluep).yyViewExpressionVector)); }
#line 2925 "surface.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (UserLevelRewritingContext::ParseResult* parseResult)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* top: item  */
#line 283 "surface.yy"
                             { YYACCEPT; }
#line 3201 "surface.c"
    break;

  case 3: /* top: END_OF_INPUT  */
#line 285 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
#line 3210 "surface.c"
    break;

  case 4: /* top: error END_OF_INPUT  */
#line 290 "surface.yy"
                        {
			  //
			  //	This is the back stop if we see a END_OF_INPUT when we're part way
			  //	through the item, and justifies suppressing the yyerror() message.
			  //
			  IssueWarning(LineNumber(lineNumber) << ": unexpected end-of-input.");
			  YYABORT;
			}
#line 3223 "surface.c"
    break;

  case 5: /* top: error CHANGE_FILE  */
#line 299 "surface.yy"
                        {
			  //
			  //	This is the back stop if we see a CHANGE_FILE when we're part way
			  //	through an item, and justifies suppressing the yyerror() message.
			  //
			  IssueWarning(LineNumber(lineNumber) << ": unexpected end-of-file.");
			  YYABORT;
			}
#line 3236 "surface.c"
    break;

  case 10: /* item: CHANGE_FILE  */
#line 314 "surface.yy"
                        {
			  //
			  //	Benign change of file; reenable yyerror() message.
			  //
			  suppressParserErrorMessage = false;
			}
#line 3247 "surface.c"
    break;

  case 11: /* $@1: %empty  */
#line 325 "surface.yy"
                                        { lexerFileNameMode(); }
#line 3253 "surface.c"
    break;

  case 12: /* directive: KW_IN $@1 FILE_NAME_STRING  */
#line 327 "surface.yy"
                        {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
#line 3266 "surface.c"
    break;

  case 13: /* $@2: %empty  */
#line 335 "surface.yy"
                                        { lexerFileNameMode(); }
#line 3272 "surface.c"
    break;

  case 14: /* directive: KW_LOAD $@2 FILE_NAME_STRING  */
#line 337 "surface.yy"
                        {
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			}
#line 3285 "surface.c"
    break;

  case 15: /* $@3: %empty  */
#line 345 "surface.yy"
                                                { lexerFileNameMode(); }
#line 3291 "surface.c"
    break;

  case 16: /* directive: KW_SLOAD $@3 FILE_NAME_STRING  */
#line 347 "surface.yy"
                        {
			  int lineNr = lineNumber;
			  string directory;
			  string fileName;
			  if (findFile((yyvsp[0].yyString), directory, fileName, lineNr) &&
			      !directoryManager.alreadySeen(directory, fileName))
			    includeFile(directory, fileName, true, lineNr);
			}
#line 3304 "surface.c"
    break;

  case 17: /* directive: KW_PWD  */
#line 356 "surface.yy"
                        {
			  cout << directoryManager.getCwd() << '\n';
			}
#line 3312 "surface.c"
    break;

  case 18: /* $@4: %empty  */
#line 359 "surface.yy"
                                        { lexerFileNameMode(); }
#line 3318 "surface.c"
    break;

  case 19: /* directive: KW_CD $@4 FILE_NAME_STRING  */
#line 361 "surface.yy"
                        {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			}
#line 3332 "surface.c"
    break;

  case 20: /* $@5: %empty  */
#line 370 "surface.yy"
                                        { lexerFileNameMode(); }
#line 3338 "surface.c"
    break;

  case 21: /* directive: KW_PUSHD $@5 FILE_NAME_STRING  */
#line 372 "surface.yy"
                        {
			  string directory;
			  directoryManager.realPath((yyvsp[0].yyString), directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			}
#line 3352 "surface.c"
    break;

  case 22: /* directive: KW_POPD  */
#line 382 "surface.yy"
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
#line 3367 "surface.c"
    break;

  case 23: /* $@6: %empty  */
#line 392 "surface.yy"
                                        { lexerStringMode(); }
#line 3373 "surface.c"
    break;

  case 24: /* directive: KW_LS $@6 UNINTERPRETED_STRING  */
#line 394 "surface.yy"
                        {
			  returnValueDump = system((string("ls") + (yyvsp[0].yyString)).c_str());
			}
#line 3381 "surface.c"
    break;

  case 25: /* $@7: %empty  */
#line 397 "surface.yy"
                                        { lexerStringMode(); }
#line 3387 "surface.c"
    break;

  case 26: /* directive: KW_LL $@7 UNINTERPRETED_STRING  */
#line 399 "surface.yy"
                        {
			  returnValueDump = system((string("ls -l") + (yyvsp[0].yyString)).c_str());
			}
#line 3395 "surface.c"
    break;

  case 27: /* directive: KW_QUIT  */
#line 403 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
#line 3404 "surface.c"
    break;

  case 28: /* directive: KW_EOF  */
#line 408 "surface.yy"
                        {
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
#line 3415 "surface.c"
    break;

  case 29: /* moduleExprDot: tokenBarDot expectedDot  */
#line 441 "surface.yy"
                        {
                          (yyval.yyModuleExpression) =  new ModuleExpression((yyvsp[-1].yyToken));
                        }
#line 3423 "surface.c"
    break;

  case 30: /* moduleExprDot: endsInDot '.'  */
#line 445 "surface.yy"
                        {
                          (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[-1].yyToken));
                        }
#line 3431 "surface.c"
    break;

  case 34: /* moduleExprDot: moduleExpr '+' moduleExprDot  */
#line 452 "surface.yy"
                        {
			  if ((yyvsp[0].yyModuleExpression))
			    (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[-2].yyModuleExpression), (yyvsp[0].yyModuleExpression));
			  else
			    {
			      IssueWarning(&((yyvsp[-1].yyToken)) << ": missing module expression after " << QUOTE((yyvsp[-1].yyToken)) << ".");
			      (yyval.yyModuleExpression) = (yyvsp[-2].yyModuleExpression);
			    }
			}
#line 3445 "surface.c"
    break;

  case 35: /* moduleExprDot: tokenDot  */
#line 462 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[0].yyToken));
			}
#line 3453 "surface.c"
    break;

  case 36: /* moduleExprDot: '.'  */
#line 466 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = 0;
			}
#line 3461 "surface.c"
    break;

  case 38: /* moduleExpr: moduleExpr '+' moduleExpr  */
#line 473 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[-2].yyModuleExpression), (yyvsp[0].yyModuleExpression));
			}
#line 3469 "surface.c"
    break;

  case 43: /* moduleExpr3: token  */
#line 485 "surface.yy"
                        {
                          (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[0].yyToken));
                        }
#line 3477 "surface.c"
    break;

  case 44: /* renameExpr: moduleExpr2 '*' renaming  */
#line 492 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[-2].yyModuleExpression), currentRenaming);
			  currentRenaming = 0;
			}
#line 3486 "surface.c"
    break;

  case 45: /* instantExpr: moduleExpr3 '{' instantArgs '}'  */
#line 499 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = new ModuleExpression((yyvsp[-3].yyModuleExpression), *((yyvsp[-1].yyViewExpressionVector)));
			  delete (yyvsp[-1].yyViewExpressionVector);
			}
#line 3495 "surface.c"
    break;

  case 46: /* parenExpr: '(' moduleExpr ')'  */
#line 506 "surface.yy"
                        {
			  (yyval.yyModuleExpression) = (yyvsp[-1].yyModuleExpression);
			}
#line 3503 "surface.c"
    break;

  case 47: /* viewExpr: viewExpr '{' instantArgs '}'  */
#line 515 "surface.yy"
                        {
			  (yyval.yyViewExpression) = new ViewExpression((yyvsp[-3].yyViewExpression), *((yyvsp[-1].yyViewExpressionVector)));
			  delete (yyvsp[-1].yyViewExpressionVector);
			}
#line 3512 "surface.c"
    break;

  case 48: /* viewExpr: token  */
#line 520 "surface.yy"
                        {
			  (yyval.yyViewExpression) = new ViewExpression((yyvsp[0].yyToken));
			}
#line 3520 "surface.c"
    break;

  case 49: /* instantArgs: instantArgs ',' viewExpr  */
#line 526 "surface.yy"
                        {
			  (yyvsp[-2].yyViewExpressionVector)->append((yyvsp[0].yyViewExpression));
			  (yyval.yyViewExpressionVector) = (yyvsp[-2].yyViewExpressionVector);
			}
#line 3529 "surface.c"
    break;

  case 50: /* instantArgs: viewExpr  */
#line 531 "surface.yy"
                        {
			  Vector<ViewExpression*>* t =  new Vector<ViewExpression*>();
			  t->append((yyvsp[0].yyViewExpression));
			  (yyval.yyViewExpressionVector) = t;
			}
#line 3539 "surface.c"
    break;

  case 51: /* $@8: %empty  */
#line 542 "surface.yy"
                        {
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
#line 3548 "surface.c"
    break;

  case 52: /* $@9: %empty  */
#line 547 "surface.yy"
                        {
			  currentSyntaxContainer = oldSyntaxContainer;
			}
#line 3556 "surface.c"
    break;

  case 58: /* mapping: KW_SORT sortName KW_TO sortName  */
#line 562 "surface.yy"
                        {
			  currentRenaming->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3564 "surface.c"
    break;

  case 59: /* mapping: KW_LABEL token KW_TO token  */
#line 566 "surface.yy"
                        {
			  currentRenaming->addLabelMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3572 "surface.c"
    break;

  case 60: /* $@10: %empty  */
#line 569 "surface.yy"
                                                { lexBubble(BAR_COLON | BAR_TO, 1); }
#line 3578 "surface.c"
    break;

  case 61: /* $@11: %empty  */
#line 570 "surface.yy"
                                                { lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
#line 3584 "surface.c"
    break;

  case 62: /* mapping: KW_OP $@10 fromSpec KW_TO $@11 toAttributes  */
#line 571 "surface.yy"
                                                {}
#line 3590 "surface.c"
    break;

  case 63: /* $@12: %empty  */
#line 572 "surface.yy"
                                                { currentRenaming->addStratMapping((yyvsp[0].yyToken)); }
#line 3596 "surface.c"
    break;

  case 64: /* mapping: KW_STRAT stratName $@12 fromStratSpec KW_TO stratName  */
#line 574 "surface.yy"
                                                { currentRenaming->addStratTarget((yyvsp[0].yyToken)); }
#line 3602 "surface.c"
    break;

  case 65: /* mapping: KW_CLASS sortName KW_TO sortName  */
#line 576 "surface.yy"
                        {
			  currentRenaming->addClassMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3610 "surface.c"
    break;

  case 66: /* $@13: %empty  */
#line 580 "surface.yy"
                        {
			  currentRenaming->addAttrMapping((yyvsp[0].yyToken));
			}
#line 3618 "surface.c"
    break;

  case 67: /* mapping: KW_ATTR token $@13 fromAttrSpec KW_TO token  */
#line 584 "surface.yy"
                        {
			  currentRenaming->addAttrTarget((yyvsp[0].yyToken));
			}
#line 3626 "surface.c"
    break;

  case 68: /* $@14: %empty  */
#line 588 "surface.yy"
                        {
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
#line 3634 "surface.c"
    break;

  case 69: /* $@15: %empty  */
#line 592 "surface.yy"
                        {
			  lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1);
			}
#line 3642 "surface.c"
    break;

  case 70: /* mapping: KW_MSG $@14 fromSpec KW_TO $@15 toAttributes  */
#line 596 "surface.yy"
                        {
			  currentRenaming->markAsMsg();
			}
#line 3650 "surface.c"
    break;

  case 71: /* $@16: %empty  */
#line 604 "surface.yy"
                                                { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 3656 "surface.c"
    break;

  case 72: /* fromSpec: ':' $@16 typeList arrow typeName  */
#line 605 "surface.yy"
                                                {}
#line 3662 "surface.c"
    break;

  case 73: /* fromSpec: %empty  */
#line 606 "surface.yy"
                                                { Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
#line 3668 "surface.c"
    break;

  case 74: /* fromAttrSpec: ':' typeName1  */
#line 610 "surface.yy"
                        {
			  currentRenaming->addAttrType((yyvsp[0].yyBool) ? tokenSequence : singleton);
			}
#line 3676 "surface.c"
    break;

  case 78: /* $@17: %empty  */
#line 623 "surface.yy"
                                                { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 3682 "surface.c"
    break;

  case 79: /* toAttributes: '[' $@17 toAttributeList ']'  */
#line 624 "surface.yy"
                                                {}
#line 3688 "surface.c"
    break;

  case 80: /* toAttributes: %empty  */
#line 625 "surface.yy"
                                                { Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
#line 3694 "surface.c"
    break;

  case 83: /* toAttribute: KW_PREC IDENTIFIER  */
#line 632 "surface.yy"
                                                { currentRenaming->setPrec((yyvsp[0].yyToken)); }
#line 3700 "surface.c"
    break;

  case 84: /* toAttribute: KW_PREC  */
#line 633 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": prec attribute without value in operator mapping."); }
#line 3706 "surface.c"
    break;

  case 85: /* $@18: %empty  */
#line 634 "surface.yy"
                                                { tokensClear(); }
#line 3712 "surface.c"
    break;

  case 86: /* toAttribute: KW_GATHER '(' $@18 idList ')'  */
#line 635 "surface.yy"
                                                { currentRenaming->setGather(tokenSequence); }
#line 3718 "surface.c"
    break;

  case 87: /* toAttribute: KW_GATHER  */
#line 636 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": gather attribute without pattern in operator mapping."); }
#line 3724 "surface.c"
    break;

  case 88: /* $@19: %empty  */
#line 637 "surface.yy"
                                                { tokensClear(); }
#line 3730 "surface.c"
    break;

  case 89: /* toAttribute: KW_FORMAT '(' $@19 idList ')'  */
#line 638 "surface.yy"
                                                { currentRenaming->setFormat(tokenSequence); }
#line 3736 "surface.c"
    break;

  case 90: /* toAttribute: KW_FORMAT  */
#line 639 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": format attribute without specification in operator mapping."); }
#line 3742 "surface.c"
    break;

  case 91: /* $@20: %empty  */
#line 640 "surface.yy"
                                                { lexerLatexMode(); }
#line 3748 "surface.c"
    break;

  case 92: /* toAttribute: KW_LATEX '(' $@20 LATEX_STRING ')'  */
#line 641 "surface.yy"
                                                { currentRenaming->setLatexMacro((yyvsp[-1].yyString)); }
#line 3754 "surface.c"
    break;

  case 93: /* toAttribute: KW_LATEX  */
#line 642 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": latex attribute without latex code in operator mapping."); }
#line 3760 "surface.c"
    break;

  case 94: /* $@21: %empty  */
#line 648 "surface.yy"
                                                { lexerIdMode(); }
#line 3766 "surface.c"
    break;

  case 95: /* $@22: %empty  */
#line 650 "surface.yy"
                        {
			  fileTable.beginModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			  interpreter.setCurrentView(new SyntacticView((yyvsp[0].yyToken), &interpreter));
			  currentSyntaxContainer = CV;
			}
#line 3776 "surface.c"
    break;

  case 96: /* view: KW_VIEW $@21 token $@22 parameters KW_FROM moduleExpr KW_TO moduleExpr expectedIs viewDecList KW_ENDV  */
#line 658 "surface.yy"
                        {
			  CV->addFrom((yyvsp[-5].yyModuleExpression));
			  CV->addTo((yyvsp[-3].yyModuleExpression));
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  bool displacedView = interpreter.insertView(((yyvsp[-9].yyToken)).code(), CV);
			  CV->finishView();
			  if (displacedView)
			    interpreter.cleanCaches();
			}
#line 3791 "surface.c"
    break;

  case 98: /* viewDecList: %empty  */
#line 671 "surface.yy"
                        {}
#line 3797 "surface.c"
    break;

  case 99: /* skipStrayArrow: KW_ARROW  */
#line 675 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": skipping " << QUOTE("->") << " in variable declaration.");
			}
#line 3805 "surface.c"
    break;

  case 100: /* skipStrayArrow: %empty  */
#line 678 "surface.yy"
                        {}
#line 3811 "surface.c"
    break;

  case 101: /* viewDeclaration: KW_SORT sortName KW_TO sortDot  */
#line 682 "surface.yy"
                        {
			  CV->addSortMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3819 "surface.c"
    break;

  case 102: /* viewDeclaration: KW_VAR varNameList ':' skipStrayArrow typeDot  */
#line 685 "surface.yy"
                                                                      {}
#line 3825 "surface.c"
    break;

  case 103: /* $@23: %empty  */
#line 687 "surface.yy"
                        {
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
#line 3833 "surface.c"
    break;

  case 106: /* viewDeclaration: KW_CLASS sortName KW_TO sortDot  */
#line 693 "surface.yy"
                        {
			  CV->addClassMapping((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 3841 "surface.c"
    break;

  case 107: /* $@24: %empty  */
#line 697 "surface.yy"
                        {
			  CV->addAttrMapping((yyvsp[0].yyToken));
			}
#line 3849 "surface.c"
    break;

  case 108: /* viewDeclaration: KW_ATTR token $@24 fromAttrSpec KW_TO token expectedDot  */
#line 701 "surface.yy"
                        {
			  CV->addAttrTarget((yyvsp[-1].yyToken));
			}
#line 3857 "surface.c"
    break;

  case 109: /* $@25: %empty  */
#line 705 "surface.yy"
                        {
			  lexBubble(BAR_COLON | BAR_TO, 1);
			}
#line 3865 "surface.c"
    break;

  case 112: /* viewDeclaration: error END_OF_INPUT  */
#line 711 "surface.yy"
                        {
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-input while parsing view " << QUOTE(CV) << ".");
			  YYABORT;  // rely on the caller to clear up view database and lexer
			}
#line 3876 "surface.c"
    break;

  case 113: /* viewDeclaration: error CHANGE_FILE  */
#line 718 "surface.yy"
                        {
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-file while parsing view " << QUOTE(CV) << ".");
			  YYABORT;  // rely on the caller to clear up view database and lexer
			}
#line 3887 "surface.c"
    break;

  case 114: /* sortDot: sortName expectedDot  */
#line 726 "surface.yy"
                                                        { (yyval.yyToken) = (yyvsp[-1].yyToken); }
#line 3893 "surface.c"
    break;

  case 116: /* $@26: %empty  */
#line 731 "surface.yy"
                        {
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
#line 3905 "surface.c"
    break;

  case 117: /* $@27: %empty  */
#line 739 "surface.yy"
                        {
			  lexBubble(END_STATEMENT, 1);
			}
#line 3913 "surface.c"
    break;

  case 118: /* viewEndOpMap: ':' $@26 typeList arrow typeName KW_TO $@27 endBubble  */
#line 743 "surface.yy"
                        {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
#line 3922 "surface.c"
    break;

  case 119: /* $@28: %empty  */
#line 748 "surface.yy"
                        {
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
#line 3936 "surface.c"
    break;

  case 120: /* viewEndOpMap: KW_TO $@28 endBubble  */
#line 758 "surface.yy"
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
#line 3960 "surface.c"
    break;

  case 121: /* $@29: %empty  */
#line 780 "surface.yy"
                        {
			  //
			  //	Specific msg->msg mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
#line 3972 "surface.c"
    break;

  case 122: /* $@30: %empty  */
#line 788 "surface.yy"
                        {
			  lexBubble(END_STATEMENT, 1);
			}
#line 3980 "surface.c"
    break;

  case 123: /* endMsgMap: ':' $@29 typeList arrow typeName KW_TO $@30 endBubble  */
#line 792 "surface.yy"
                        {
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			  CV->markAsMsg();
			}
#line 3990 "surface.c"
    break;

  case 124: /* $@31: %empty  */
#line 798 "surface.yy"
                        {
			  //
			  //	At this point we don't know if we have an msg->term mapping
			  //	or a generic msg->msg mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
#line 4004 "surface.c"
    break;

  case 125: /* endMsgMap: KW_TO $@31 endBubble  */
#line 808 "surface.yy"
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
#line 4029 "surface.c"
    break;

  case 126: /* strategyCall: stratName  */
#line 831 "surface.yy"
                        {
			  strategyCall.resize(1);
			  strategyCall[0] = (yyvsp[0].yyToken);
			}
#line 4038 "surface.c"
    break;

  case 127: /* $@32: %empty  */
#line 835 "surface.yy"
                                                        { lexBubble(BAR_RIGHT_PAREN, 1); }
#line 4044 "surface.c"
    break;

  case 128: /* strategyCall: stratName '(' $@32 ')'  */
#line 837 "surface.yy"
                        {
			  // Adds the stratName and parentheses to the lexer bubble
			  int bubbleSize = lexerBubble.length();
			  strategyCall.resize(bubbleSize + 3);
			  strategyCall[0] = (yyvsp[-3].yyToken);
			  strategyCall[1] = (yyvsp[-2].yyToken);
			  for (int i = 0; i < bubbleSize; i++)
			    strategyCall[2 + i] = lexerBubble[i];
			  strategyCall[bubbleSize + 2] = (yyvsp[0].yyToken);
			}
#line 4059 "surface.c"
    break;

  case 129: /* $@33: %empty  */
#line 849 "surface.yy"
                        {
			  CV->addStratMapping((yyvsp[0].yyToken));
			}
#line 4067 "surface.c"
    break;

  case 130: /* viewStratMap: stratName $@33 stratSignature KW_TO stratName '.'  */
#line 853 "surface.yy"
                        {
			  CV->addStratTarget((yyvsp[-1].yyToken));
			}
#line 4075 "surface.c"
    break;

  case 131: /* $@34: %empty  */
#line 857 "surface.yy"
                        {
			  lexBubble(END_STATEMENT, 1);
			}
#line 4083 "surface.c"
    break;

  case 132: /* viewStratMap: strategyCall KW_TO $@34 endBubble  */
#line 861 "surface.yy"
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
#line 4109 "surface.c"
    break;

  case 133: /* endBubble: '.'  */
#line 884 "surface.yy"
                                        {}
#line 4115 "surface.c"
    break;

  case 134: /* endBubble: tokenDot  */
#line 885 "surface.yy"
                                        { lexerBubble.append((yyvsp[0].yyToken)); }
#line 4121 "surface.c"
    break;

  case 135: /* $@35: %empty  */
#line 888 "surface.yy"
                                        { lexBubble(BAR_RIGHT_PAREN, 1); }
#line 4127 "surface.c"
    break;

  case 136: /* parenBubble: '(' $@35 ')'  */
#line 889 "surface.yy"
                                        {}
#line 4133 "surface.c"
    break;

  case 137: /* $@36: %empty  */
#line 895 "surface.yy"
                                        { lexerIdMode(); }
#line 4139 "surface.c"
    break;

  case 138: /* $@37: %empty  */
#line 897 "surface.yy"
                        {
			  interpreter.setCurrentModule(new SyntacticPreModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken), &interpreter));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule((yyvsp[-2].yyToken), (yyvsp[0].yyToken));
			}
#line 4149 "surface.c"
    break;

  case 139: /* module: KW_MOD $@36 token $@37 parameters expectedIs decList KW_ENDM  */
#line 903 "surface.yy"
                        {
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule((yyvsp[0].yyToken));
			}
#line 4159 "surface.c"
    break;

  case 140: /* dot: '.'  */
#line 910 "surface.yy"
                                        {}
#line 4165 "surface.c"
    break;

  case 141: /* dot: tokenDot  */
#line 911 "surface.yy"
                                        { tokensStore((yyvsp[0].yyToken)); }
#line 4171 "surface.c"
    break;

  case 142: /* parameters: '{' parameterList '}'  */
#line 914 "surface.yy"
                                              {}
#line 4177 "surface.c"
    break;

  case 143: /* parameters: %empty  */
#line 915 "surface.yy"
                        {}
#line 4183 "surface.c"
    break;

  case 146: /* parameter: token colon2 moduleExpr  */
#line 923 "surface.yy"
                        {
			  currentSyntaxContainer->addParameter2((yyvsp[-2].yyToken), (yyvsp[0].yyModuleExpression));
			}
#line 4191 "surface.c"
    break;

  case 147: /* colon2: KW_COLON2  */
#line 928 "surface.yy"
                                  {}
#line 4197 "surface.c"
    break;

  case 148: /* colon2: ':'  */
#line 930 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": saw " << QUOTE(':') << " instead of " << QUOTE("::") << " in parameter declaration.");
			}
#line 4205 "surface.c"
    break;

  case 149: /* badType: ENDS_IN_DOT  */
#line 936 "surface.yy"
                        {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  (yyval.yyToken) = (yyvsp[0].yyToken);  // needed for line number
			}
#line 4216 "surface.c"
    break;

  case 151: /* typeDot: badType  */
#line 945 "surface.yy"
                                {}
#line 4222 "surface.c"
    break;

  case 153: /* decList: %empty  */
#line 949 "surface.yy"
                        {}
#line 4228 "surface.c"
    break;

  case 154: /* declaration: KW_IMPORT moduleExprDot  */
#line 953 "surface.yy"
                        {
			  if ((yyvsp[0].yyModuleExpression))
			    CM->addImport((yyvsp[-1].yyToken), (yyvsp[0].yyModuleExpression));
			  else
			    {
			      IssueWarning(&((yyvsp[-1].yyToken)) << ": missing module expression after " << QUOTE((yyvsp[-1].yyToken)) << ".");
			    }
			}
#line 4241 "surface.c"
    break;

  case 155: /* $@38: %empty  */
#line 962 "surface.yy"
                                                { tokensClear(); }
#line 4247 "surface.c"
    break;

  case 156: /* declaration: KW_SORT $@38 endSortNameList  */
#line 963 "surface.yy"
                                                { CM->addSortDecl(tokenSequence); }
#line 4253 "surface.c"
    break;

  case 157: /* $@39: %empty  */
#line 965 "surface.yy"
                                                { tokensClear(); }
#line 4259 "surface.c"
    break;

  case 158: /* declaration: KW_SUBSORT $@39 endSubsortList  */
#line 966 "surface.yy"
                                                { CM->addSubsortDecl(tokenSequence); }
#line 4265 "surface.c"
    break;

  case 159: /* $@40: %empty  */
#line 968 "surface.yy"
                                                { lexBubble(BAR_COLON, 1); }
#line 4271 "surface.c"
    break;

  case 160: /* $@41: %empty  */
#line 969 "surface.yy"
                                                { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 4277 "surface.c"
    break;

  case 161: /* declaration: KW_OP $@40 ':' $@41 domainRangeAttr  */
#line 970 "surface.yy"
                                                {}
#line 4283 "surface.c"
    break;

  case 162: /* declaration: KW_OPS opNameList ':' domainRangeAttr  */
#line 972 "surface.yy"
                                                              {}
#line 4289 "surface.c"
    break;

  case 163: /* declaration: KW_VAR varNameList ':' skipStrayArrow typeDot  */
#line 974 "surface.yy"
                                                                      {}
#line 4295 "surface.c"
    break;

  case 164: /* $@42: %empty  */
#line 976 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1); }
#line 4301 "surface.c"
    break;

  case 165: /* $@43: %empty  */
#line 977 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4307 "surface.c"
    break;

  case 166: /* declaration: KW_MB $@42 ':' $@43 endBubble  */
#line 978 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4313 "surface.c"
    break;

  case 167: /* $@44: %empty  */
#line 980 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_COLON, 1);  }
#line 4319 "surface.c"
    break;

  case 168: /* $@45: %empty  */
#line 981 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 4325 "surface.c"
    break;

  case 169: /* $@46: %empty  */
#line 982 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4331 "surface.c"
    break;

  case 170: /* declaration: KW_CMB $@44 ':' $@45 KW_IF $@46 endBubble  */
#line 983 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4337 "surface.c"
    break;

  case 171: /* $@47: %empty  */
#line 985 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 4343 "surface.c"
    break;

  case 172: /* $@48: %empty  */
#line 986 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4349 "surface.c"
    break;

  case 173: /* declaration: KW_EQ $@47 '=' $@48 endBubble  */
#line 987 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4355 "surface.c"
    break;

  case 174: /* $@49: %empty  */
#line 989 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_EQUALS, 1); }
#line 4361 "surface.c"
    break;

  case 175: /* $@50: %empty  */
#line 990 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 4367 "surface.c"
    break;

  case 176: /* $@51: %empty  */
#line 991 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4373 "surface.c"
    break;

  case 177: /* declaration: KW_CEQ $@49 '=' $@50 KW_IF $@51 endBubble  */
#line 992 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4379 "surface.c"
    break;

  case 178: /* $@52: %empty  */
#line 994 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 4385 "surface.c"
    break;

  case 179: /* $@53: %empty  */
#line 995 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4391 "surface.c"
    break;

  case 180: /* declaration: KW_RL $@52 KW_ARROW2 $@53 endBubble  */
#line 996 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4397 "surface.c"
    break;

  case 181: /* $@54: %empty  */
#line 998 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_ARROW2, 1); }
#line 4403 "surface.c"
    break;

  case 182: /* $@55: %empty  */
#line 999 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 4409 "surface.c"
    break;

  case 183: /* $@56: %empty  */
#line 1000 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4415 "surface.c"
    break;

  case 184: /* declaration: KW_CRL $@54 KW_ARROW2 $@55 KW_IF $@56 endBubble  */
#line 1001 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4421 "surface.c"
    break;

  case 185: /* $@57: %empty  */
#line 1003 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_ASSIGN, 1); }
#line 4427 "surface.c"
    break;

  case 186: /* $@58: %empty  */
#line 1004 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4433 "surface.c"
    break;

  case 187: /* declaration: KW_SD $@57 KW_ASSIGN $@58 endBubble  */
#line 1005 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4439 "surface.c"
    break;

  case 188: /* $@59: %empty  */
#line 1007 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_ASSIGN, 1); }
#line 4445 "surface.c"
    break;

  case 189: /* $@60: %empty  */
#line 1008 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), BAR_IF, 1); }
#line 4451 "surface.c"
    break;

  case 190: /* $@61: %empty  */
#line 1009 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_STATEMENT, 1); }
#line 4457 "surface.c"
    break;

  case 191: /* declaration: KW_CSD $@59 KW_ASSIGN $@60 KW_IF $@61 endBubble  */
#line 1010 "surface.yy"
                                                { CM->addStatement(lexerBubble); }
#line 4463 "surface.c"
    break;

  case 192: /* $@62: %empty  */
#line 1012 "surface.yy"
                                                { tokensClear(); }
#line 4469 "surface.c"
    break;

  case 193: /* declaration: stratDeclKeyword $@62 stratIdList stratSignature stratAttributes dot  */
#line 1016 "surface.yy"
                                                {}
#line 4475 "surface.c"
    break;

  case 194: /* $@63: %empty  */
#line 1018 "surface.yy"
                                                { lexBubble(BAR_COLON, 1); }
#line 4481 "surface.c"
    break;

  case 195: /* $@64: %empty  */
#line 1019 "surface.yy"
                                                { Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
#line 4487 "surface.c"
    break;

  case 196: /* declaration: KW_MSG $@63 ':' $@64 domainRangeAttr  */
#line 1020 "surface.yy"
                                                {
						  CM->endMsg();
						}
#line 4495 "surface.c"
    break;

  case 197: /* declaration: KW_MSGS opNameList ':' domainRangeAttr  */
#line 1025 "surface.yy"
                        {
			  CM->endMsg();
			}
#line 4503 "surface.c"
    break;

  case 199: /* $@65: %empty  */
#line 1031 "surface.yy"
                                                { tokensClear(); }
#line 4509 "surface.c"
    break;

  case 200: /* declaration: KW_SUBCLASS $@65 endSubsortList  */
#line 1032 "surface.yy"
                                                { CM->addSubclassDecl(tokenSequence); }
#line 4515 "surface.c"
    break;

  case 201: /* declaration: error '.'  */
#line 1035 "surface.yy"
                        {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeDeclsConsistent();
			}
#line 4528 "surface.c"
    break;

  case 202: /* declaration: error END_OF_INPUT  */
#line 1044 "surface.yy"
                        {
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-input while parsing module " << QUOTE(CM) << ".");
			  YYABORT;  // rely on the caller to clear up module database and lexer
			}
#line 4539 "surface.c"
    break;

  case 203: /* declaration: error CHANGE_FILE  */
#line 1051 "surface.yy"
                        {
			  fileTable.endModule(lineNumber);
			  IssueWarning(LineNumber(lineNumber) <<
			  ": unexpected end-of-file while parsing module " << QUOTE(CM) << ".");
			  YYABORT;  // rely on the caller to clear up module database and lexer
			}
#line 4550 "surface.c"
    break;

  case 204: /* $@66: %empty  */
#line 1060 "surface.yy"
                        {
			  CM->addClassDecl((yyvsp[0].yyToken));
			}
#line 4558 "surface.c"
    break;

  case 205: /* classDecl: sortName $@66 classDef  */
#line 1064 "surface.yy"
                        {
			}
#line 4565 "surface.c"
    break;

  case 206: /* classDecl: tokenDot  */
#line 1067 "surface.yy"
                        {
			  CM->addClassDecl((yyvsp[0].yyToken));
			}
#line 4573 "surface.c"
    break;

  case 208: /* classDef: '|' cPairList finalPair  */
#line 1073 "surface.yy"
                                                {}
#line 4579 "surface.c"
    break;

  case 209: /* finalPair: attributeName ':' typeName1Dot  */
#line 1077 "surface.yy"
                        {
			  CM->addAttributePair((yyvsp[-2].yyToken), (yyvsp[0].yyBool), (yyvsp[0].yyBool) ? tokenSequence : singleton);
			}
#line 4587 "surface.c"
    break;

  case 210: /* finalPair: attributeName typeName1Dot  */
#line 1081 "surface.yy"
                        {
			  CM->addAttributePairNoColon((yyvsp[-1].yyToken), (yyvsp[0].yyBool), (yyvsp[0].yyBool) ? tokenSequence : singleton);
			}
#line 4595 "surface.c"
    break;

  case 213: /* cPair: attributeName ':' typeName1  */
#line 1091 "surface.yy"
                        {
			  CM->addAttributePair((yyvsp[-2].yyToken), (yyvsp[0].yyBool), (yyvsp[0].yyBool) ? tokenSequence : singleton);
			}
#line 4603 "surface.c"
    break;

  case 214: /* cPair: attributeName typeName1  */
#line 1095 "surface.yy"
                        {
			  CM->addAttributePairNoColon((yyvsp[-1].yyToken), (yyvsp[0].yyBool), (yyvsp[0].yyBool) ? tokenSequence : singleton);
			}
#line 4611 "surface.c"
    break;

  case 215: /* varNameList: varNameList tokenBarColon  */
#line 1100 "surface.yy"
                                                        { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 4617 "surface.c"
    break;

  case 216: /* varNameList: tokenBarColon  */
#line 1101 "surface.yy"
                                                        { currentSyntaxContainer->addVarDecl((yyvsp[0].yyToken)); }
#line 4623 "surface.c"
    break;

  case 219: /* simpleOpName: tokenBarColon  */
#line 1108 "surface.yy"
                                                { singleton[0] = (yyvsp[0].yyToken); CM->addOpDecl(singleton); }
#line 4629 "surface.c"
    break;

  case 220: /* simpleOpName: parenBubble  */
#line 1109 "surface.yy"
                                                { CM->addOpDecl(lexerBubble); }
#line 4635 "surface.c"
    break;

  case 223: /* domainRangeAttr: badType  */
#line 1115 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": missing " << QUOTE("->") << " in constant declaration.");
			}
#line 4643 "surface.c"
    break;

  case 228: /* stratId: stratName  */
#line 1126 "surface.yy"
                                        { CM->addStratDecl((yyvsp[0].yyToken)); }
#line 4649 "surface.c"
    break;

  case 231: /* stratAttributes: '[' stratAttrList ']'  */
#line 1137 "surface.yy"
                                                {}
#line 4655 "surface.c"
    break;

  case 232: /* stratAttributes: %empty  */
#line 1138 "surface.yy"
                        {}
#line 4661 "surface.c"
    break;

  case 233: /* stratAttrList: KW_METADATA IDENTIFIER  */
#line 1142 "surface.yy"
                        {
			  CM->setMetadata((yyvsp[0].yyToken));
			}
#line 4669 "surface.c"
    break;

  case 234: /* skipStrayColon: ':'  */
#line 1148 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": skipping stray " << QUOTE(":") << " in operator declaration.");
			}
#line 4677 "surface.c"
    break;

  case 235: /* skipStrayColon: %empty  */
#line 1151 "surface.yy"
                        {}
#line 4683 "surface.c"
    break;

  case 237: /* dra2: '.'  */
#line 1156 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 4691 "surface.c"
    break;

  case 238: /* dra2: badType  */
#line 1160 "surface.yy"
                        {
			  IssueWarning(&((yyvsp[0].yyToken)) << ": missing " << QUOTE("->") << " in operator declaration.");
			}
#line 4699 "surface.c"
    break;

  case 239: /* rangeAttr: arrow typeAttr  */
#line 1166 "surface.yy"
                        {
			  if ((yyvsp[-1].yyBool))
			    CM->convertSortsToKinds();
			}
#line 4708 "surface.c"
    break;

  case 241: /* typeAttr: badType  */
#line 1173 "surface.yy"
                                {}
#line 4714 "surface.c"
    break;

  case 242: /* arrow: KW_ARROW  */
#line 1176 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 4720 "surface.c"
    break;

  case 243: /* arrow: KW_PARTIAL  */
#line 1177 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 4726 "surface.c"
    break;

  case 245: /* typeList: %empty  */
#line 1181 "surface.yy"
                        {}
#line 4732 "surface.c"
    break;

  case 246: /* typeName1: sortName  */
#line 1185 "surface.yy"
                        {
			  singleton[0] = (yyvsp[0].yyToken);
			  (yyval.yyBool) = false;
			}
#line 4741 "surface.c"
    break;

  case 247: /* typeName1: kind  */
#line 1190 "surface.yy"
                        {
			  (yyval.yyBool) = true;
			}
#line 4749 "surface.c"
    break;

  case 248: /* typeName1Dot: sortName expectedDot  */
#line 1196 "surface.yy"
                        {
			  singleton[0] = (yyvsp[-1].yyToken);
			  (yyval.yyBool) = false;
			}
#line 4758 "surface.c"
    break;

  case 249: /* typeName1Dot: tokenDot  */
#line 1201 "surface.yy"
                        {
			  singleton[0] = (yyvsp[0].yyToken);
			  (yyval.yyBool) = false;
			}
#line 4767 "surface.c"
    break;

  case 250: /* typeName1Dot: kind expectedDot  */
#line 1206 "surface.yy"
                        {
			  (yyval.yyBool) = true;
			}
#line 4775 "surface.c"
    break;

  case 251: /* $@67: %empty  */
#line 1211 "surface.yy"
                                                { tokensClear(); }
#line 4781 "surface.c"
    break;

  case 253: /* typeName: sortName  */
#line 1216 "surface.yy"
                        {
			  singleton[0] = (yyvsp[0].yyToken);
			  currentSyntaxContainer->addType(false, singleton);
			}
#line 4790 "surface.c"
    break;

  case 254: /* $@68: %empty  */
#line 1220 "surface.yy"
                                                { tokensClear(); }
#line 4796 "surface.c"
    break;

  case 255: /* typeName: '[' $@68 sortNames ']'  */
#line 1222 "surface.yy"
                        {
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
#line 4804 "surface.c"
    break;

  case 256: /* sortNames: sortNames ',' sortName  */
#line 1227 "surface.yy"
                                                        { tokensStore((yyvsp[0].yyToken)); }
#line 4810 "surface.c"
    break;

  case 257: /* sortNames: sortName  */
#line 1228 "surface.yy"
                                                        { tokensStore((yyvsp[0].yyToken)); }
#line 4816 "surface.c"
    break;

  case 258: /* attributes: '[' attributeList ']'  */
#line 1231 "surface.yy"
                                                {}
#line 4822 "surface.c"
    break;

  case 259: /* attributes: %empty  */
#line 1232 "surface.yy"
                        {}
#line 4828 "surface.c"
    break;

  case 262: /* idKeyword: KW_ID  */
#line 1240 "surface.yy"
                        {
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
#line 4836 "surface.c"
    break;

  case 263: /* idKeyword: KW_LEFT KW_ID  */
#line 1244 "surface.yy"
                        {
			  CM->setFlag(SymbolType::LEFT_ID);
			}
#line 4844 "surface.c"
    break;

  case 264: /* idKeyword: KW_RIGHT KW_ID  */
#line 1248 "surface.yy"
                        {
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
#line 4852 "surface.c"
    break;

  case 265: /* attribute: KW_ASSOC  */
#line 1254 "surface.yy"
                        {
			  CM->setFlag(SymbolType::ASSOC);
			}
#line 4860 "surface.c"
    break;

  case 266: /* attribute: KW_COMM  */
#line 1258 "surface.yy"
                        {
			  CM->setFlag(SymbolType::COMM);
			}
#line 4868 "surface.c"
    break;

  case 267: /* $@69: %empty  */
#line 1261 "surface.yy"
                                                { lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
#line 4874 "surface.c"
    break;

  case 268: /* attribute: idKeyword $@69 identity  */
#line 1262 "surface.yy"
                                                { CM->setIdentity(lexerBubble); }
#line 4880 "surface.c"
    break;

  case 269: /* attribute: KW_IDEM  */
#line 1264 "surface.yy"
                        {
			  CM->setFlag(SymbolType::IDEM);
			}
#line 4888 "surface.c"
    break;

  case 270: /* attribute: KW_ITER  */
#line 1268 "surface.yy"
                        {
			  CM->setFlag(SymbolType::ITER);
			}
#line 4896 "surface.c"
    break;

  case 271: /* attribute: KW_PREC IDENTIFIER  */
#line 1271 "surface.yy"
                                                { CM->setPrec((yyvsp[0].yyToken)); }
#line 4902 "surface.c"
    break;

  case 272: /* attribute: KW_PREC  */
#line 1272 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": prec attribute without value in operator declaration."); }
#line 4908 "surface.c"
    break;

  case 273: /* $@70: %empty  */
#line 1273 "surface.yy"
                                                { tokensClear(); }
#line 4914 "surface.c"
    break;

  case 274: /* attribute: KW_GATHER '(' $@70 idList ')'  */
#line 1274 "surface.yy"
                                                { CM->setGather(tokenSequence); }
#line 4920 "surface.c"
    break;

  case 275: /* attribute: KW_GATHER  */
#line 1275 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": gather attribute without pattern in operator declaration."); }
#line 4926 "surface.c"
    break;

  case 276: /* $@71: %empty  */
#line 1276 "surface.yy"
                                                { tokensClear(); }
#line 4932 "surface.c"
    break;

  case 277: /* attribute: KW_FORMAT '(' $@71 idList ')'  */
#line 1277 "surface.yy"
                                                { CM->setFormat(tokenSequence); }
#line 4938 "surface.c"
    break;

  case 278: /* attribute: KW_FORMAT  */
#line 1278 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": format attribute without specification in operator declaration."); }
#line 4944 "surface.c"
    break;

  case 279: /* $@72: %empty  */
#line 1279 "surface.yy"
                                                { tokensClear(); }
#line 4950 "surface.c"
    break;

  case 280: /* attribute: KW_STRAT '(' $@72 idList ')'  */
#line 1280 "surface.yy"
                                                { CM->setStrat(tokenSequence); }
#line 4956 "surface.c"
    break;

  case 281: /* attribute: KW_STRAT  */
#line 1281 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": strat attribute without strategy in operator declaration."); }
#line 4962 "surface.c"
    break;

  case 282: /* $@73: %empty  */
#line 1282 "surface.yy"
                                                { tokensClear(); }
#line 4968 "surface.c"
    break;

  case 283: /* attribute: KW_ASTRAT '(' $@73 idList ')'  */
#line 1283 "surface.yy"
                                                { CM->setStrat(tokenSequence); }
#line 4974 "surface.c"
    break;

  case 284: /* attribute: KW_ASTRAT  */
#line 1284 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": strategy attribute without strategy in operator declaration."); }
#line 4980 "surface.c"
    break;

  case 285: /* $@74: %empty  */
#line 1285 "surface.yy"
                                                { tokensClear(); }
#line 4986 "surface.c"
    break;

  case 286: /* attribute: KW_POLY '(' $@74 idList ')'  */
#line 1286 "surface.yy"
                                                { CM->setPoly(tokenSequence); }
#line 4992 "surface.c"
    break;

  case 287: /* attribute: KW_POLY  */
#line 1287 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": poly attribute without specification in operator declaration."); }
#line 4998 "surface.c"
    break;

  case 288: /* attribute: KW_MEMO  */
#line 1289 "surface.yy"
                        {
			  CM->setFlag(SymbolType::MEMO);
			}
#line 5006 "surface.c"
    break;

  case 289: /* attribute: KW_CTOR  */
#line 1293 "surface.yy"
                        {
			  CM->setFlag(SymbolType::CTOR);
			}
#line 5014 "surface.c"
    break;

  case 290: /* attribute: KW_FROZEN  */
#line 1297 "surface.yy"
                        {
			  tokensClear();
			  CM->setFrozen(tokenSequence);
			}
#line 5023 "surface.c"
    break;

  case 291: /* $@75: %empty  */
#line 1301 "surface.yy"
                                                { tokensClear(); }
#line 5029 "surface.c"
    break;

  case 292: /* attribute: KW_FROZEN '(' $@75 idList ')'  */
#line 1302 "surface.yy"
                                                { CM->setFrozen(tokenSequence); }
#line 5035 "surface.c"
    break;

  case 293: /* attribute: KW_CONFIG  */
#line 1304 "surface.yy"
                        {
			  CM->setFlag(SymbolType::CONFIG);
			}
#line 5043 "surface.c"
    break;

  case 294: /* attribute: KW_OBJ  */
#line 1308 "surface.yy"
                        {
			  CM->setFlag(SymbolType::OBJECT);
			}
#line 5051 "surface.c"
    break;

  case 295: /* attribute: KW_MSG  */
#line 1312 "surface.yy"
                        {
			  CM->setFlag(SymbolType::MESSAGE);
			}
#line 5059 "surface.c"
    break;

  case 296: /* attribute: KW_PORTAL  */
#line 1316 "surface.yy"
                        {
			  CM->setFlag(SymbolType::PORTAL);
			}
#line 5067 "surface.c"
    break;

  case 297: /* attribute: KW_METADATA IDENTIFIER  */
#line 1320 "surface.yy"
                        {
			  CM->setMetadata((yyvsp[0].yyToken));
			}
#line 5075 "surface.c"
    break;

  case 298: /* $@76: %empty  */
#line 1323 "surface.yy"
                                                { lexerLatexMode(); }
#line 5081 "surface.c"
    break;

  case 299: /* attribute: KW_LATEX '(' $@76 LATEX_STRING ')'  */
#line 1324 "surface.yy"
                                                { CM->setLatexMacro((yyvsp[-1].yyString)); }
#line 5087 "surface.c"
    break;

  case 300: /* attribute: KW_LATEX  */
#line 1325 "surface.yy"
                                                { IssueWarning(&((yyvsp[0].yyToken)) << ": latex attribute without latex code in operator declaration."); }
#line 5093 "surface.c"
    break;

  case 301: /* attribute: KW_SPECIAL '(' hookList ')'  */
#line 1326 "surface.yy"
                                                        {}
#line 5099 "surface.c"
    break;

  case 302: /* attribute: KW_DITTO  */
#line 1328 "surface.yy"
                        {
			  CM->setFlag(SymbolType::DITTO);
			}
#line 5107 "surface.c"
    break;

  case 303: /* attribute: KW_PCONST  */
#line 1332 "surface.yy"
                        {
			  CM->setFlag(SymbolType::PCONST);
			}
#line 5115 "surface.c"
    break;

  case 305: /* identity: %empty  */
#line 1342 "surface.yy"
                        {}
#line 5121 "surface.c"
    break;

  case 306: /* idList: idList IDENTIFIER  */
#line 1345 "surface.yy"
                                                { tokensStore((yyvsp[0].yyToken)); }
#line 5127 "surface.c"
    break;

  case 307: /* idList: IDENTIFIER  */
#line 1346 "surface.yy"
                                                { tokensStore((yyvsp[0].yyToken)); }
#line 5133 "surface.c"
    break;

  case 308: /* hookList: hookList hook  */
#line 1349 "surface.yy"
                                                {}
#line 5139 "surface.c"
    break;

  case 309: /* hookList: hook  */
#line 1350 "surface.yy"
                                                {}
#line 5145 "surface.c"
    break;

  case 310: /* hook: KW_ID_HOOK token  */
#line 1353 "surface.yy"
                                                        { tokensClear(); CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[0].yyToken), tokenSequence); }
#line 5151 "surface.c"
    break;

  case 311: /* hook: KW_ID_HOOK token parenBubble  */
#line 1354 "surface.yy"
                                                        { CM->addHook(SyntacticPreModule::ID_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 5157 "surface.c"
    break;

  case 312: /* hook: KW_OP_HOOK token parenBubble  */
#line 1355 "surface.yy"
                                                        { CM->addHook(SyntacticPreModule::OP_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 5163 "surface.c"
    break;

  case 313: /* hook: KW_TERM_HOOK token parenBubble  */
#line 1356 "surface.yy"
                                                        { CM->addHook(SyntacticPreModule::TERM_HOOK, (yyvsp[-1].yyToken), lexerBubble); }
#line 5169 "surface.c"
    break;

  case 314: /* expectedIs: KW_IS  */
#line 1362 "surface.yy"
                              {}
#line 5175 "surface.c"
    break;

  case 315: /* expectedIs: %empty  */
#line 1364 "surface.yy"
                        {
			  IssueWarning(LineNumber(lineNumber) << ": missing " << QUOTE("is") << " keyword.");
			}
#line 5183 "surface.c"
    break;

  case 316: /* expectedDot: '.'  */
#line 1369 "surface.yy"
                            {}
#line 5189 "surface.c"
    break;

  case 317: /* expectedDot: %empty  */
#line 1371 "surface.yy"
                        {
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
#line 5197 "surface.c"
    break;

  case 318: /* sortNameList: sortNameList sortName  */
#line 1379 "surface.yy"
                                                { tokensStore((yyvsp[0].yyToken)); }
#line 5203 "surface.c"
    break;

  case 319: /* sortNameList: sortName  */
#line 1380 "surface.yy"
                                                { tokensStore((yyvsp[0].yyToken)); }
#line 5209 "surface.c"
    break;

  case 320: /* endSortNameList: tokenDot  */
#line 1384 "surface.yy"
                                                { tokensStore((yyvsp[0].yyToken)); }
#line 5215 "surface.c"
    break;

  case 322: /* subsortList: subsortList sortNameList '<'  */
#line 1391 "surface.yy"
                                                        { tokensStore((yyvsp[0].yyToken)); }
#line 5221 "surface.c"
    break;

  case 323: /* subsortList: sortNameList '<'  */
#line 1392 "surface.yy"
                                                        { tokensStore((yyvsp[0].yyToken)); }
#line 5227 "surface.c"
    break;

  case 325: /* sortName: sortNameFrag  */
#line 1402 "surface.yy"
                        {
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  (yyval.yyToken) = t;
			}
#line 5241 "surface.c"
    break;

  case 326: /* sortNameFrag: sortToken  */
#line 1413 "surface.yy"
                                                { fragStore((yyvsp[0].yyToken)); }
#line 5247 "surface.c"
    break;

  case 327: /* $@77: %empty  */
#line 1414 "surface.yy"
                                                { fragStore((yyvsp[0].yyToken)); }
#line 5253 "surface.c"
    break;

  case 328: /* sortNameFrag: sortNameFrag '{' $@77 sortNameFrags '}'  */
#line 1415 "surface.yy"
                                                { fragStore((yyvsp[0].yyToken)); }
#line 5259 "surface.c"
    break;

  case 329: /* $@78: %empty  */
#line 1418 "surface.yy"
                                                { fragStore((yyvsp[0].yyToken)); }
#line 5265 "surface.c"
    break;

  case 330: /* sortNameFrags: sortNameFrags ',' $@78 sortNameFrag  */
#line 1419 "surface.yy"
                                                {}
#line 5271 "surface.c"
    break;

  case 331: /* sortNameFrags: sortNameFrag  */
#line 1420 "surface.yy"
                                                {}
#line 5277 "surface.c"
    break;

  case 332: /* tokenDot: ENDS_IN_DOT  */
#line 1424 "surface.yy"
                        {
			  Token t;
			  t.dropChar((yyvsp[0].yyToken));
			  missingSpace(t);
			  (yyval.yyToken) = t;
			}
#line 5288 "surface.c"
    break;

  case 463: /* $@79: %empty  */
#line 1551 "surface.yy"
                                                { lexBubble(END_COMMAND, 1); }
#line 5294 "surface.c"
    break;

  case 464: /* command: KW_SELECT $@79 endBubble  */
#line 1553 "surface.yy"
                        {
			  interpreter.setCurrentModule(lexerBubble);
			}
#line 5302 "surface.c"
    break;

  case 465: /* $@80: %empty  */
#line 1556 "surface.yy"
                                                { lexBubble(END_COMMAND, 1); }
#line 5308 "surface.c"
    break;

  case 466: /* command: KW_DUMP $@80 endBubble  */
#line 1558 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
#line 5317 "surface.c"
    break;

  case 467: /* $@81: %empty  */
#line 1563 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5326 "surface.c"
    break;

  case 468: /* command: KW_PARSE $@81 moduleAndTerm  */
#line 1568 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}
#line 5336 "surface.c"
    break;

  case 469: /* $@82: %empty  */
#line 1575 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5345 "surface.c"
    break;

  case 470: /* command: KW_CREDUCE $@82 moduleAndTerm  */
#line 1580 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}
#line 5355 "surface.c"
    break;

  case 471: /* $@83: %empty  */
#line 1587 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5364 "surface.c"
    break;

  case 472: /* command: KW_SREDUCE $@83 moduleAndTerm  */
#line 1592 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}
#line 5374 "surface.c"
    break;

  case 473: /* $@84: %empty  */
#line 1599 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5383 "surface.c"
    break;

  case 474: /* command: optDebug KW_REDUCE $@84 moduleAndTerm  */
#line 1604 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, (yyvsp[-3].yyBool));
			}
#line 5393 "surface.c"
    break;

  case 475: /* $@85: %empty  */
#line 1611 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5403 "surface.c"
    break;

  case 476: /* command: optDebug KW_REWRITE $@85 numberModuleTerm  */
#line 1617 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 5413 "surface.c"
    break;

  case 477: /* $@86: %empty  */
#line 1623 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
#line 5424 "surface.c"
    break;

  case 478: /* command: optDebug KW_EREWRITE $@86 numbersModuleTerm  */
#line 1630 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 5434 "surface.c"
    break;

  case 479: /* $@87: %empty  */
#line 1636 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
#line 5445 "surface.c"
    break;

  case 480: /* command: optDebug KW_FREWRITE $@87 numbersModuleTerm  */
#line 1643 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, (yyvsp[-3].yyBool));
			}
#line 5455 "surface.c"
    break;

  case 481: /* $@88: %empty  */
#line 1649 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5465 "surface.c"
    break;

  case 482: /* command: optDebug KW_SREWRITE $@88 numberModuleTerm  */
#line 1655 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 5475 "surface.c"
    break;

  case 483: /* $@89: %empty  */
#line 1661 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5485 "surface.c"
    break;

  case 484: /* command: optDebug KW_DSREWRITE $@89 numberModuleTerm  */
#line 1667 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, (yyvsp[-3].yyBool), true);
			}
#line 5495 "surface.c"
    break;

  case 485: /* $@90: %empty  */
#line 1674 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5504 "surface.c"
    break;

  case 486: /* command: KW_CHECK $@90 moduleAndTerm  */
#line 1679 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.check(lexerBubble);
			}
#line 5514 "surface.c"
    break;

  case 487: /* $@91: %empty  */
#line 1686 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;
			}
#line 5525 "surface.c"
    break;

  case 488: /* command: optDebug search $@91 numbersModuleTerm  */
#line 1693 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, (yyvsp[-2].yySearchKind), (yyvsp[-3].yyBool));
			}
#line 5535 "surface.c"
    break;

  case 489: /* $@92: %empty  */
#line 1699 "surface.yy"
                        {
			  variantOptions = (yyvsp[-1].yyInt64);
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			  number2 = NONE;			  
			}
#line 5547 "surface.c"
    break;

  case 490: /* command: optDebug optOptions KW_VU_NARROW $@92 optionsNumbersModuleTerm  */
#line 1707 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, Interpreter::VU_NARROW, (yyvsp[-4].yyBool), variantOptions);
			}
#line 5557 "surface.c"
    break;

  case 491: /* $@93: %empty  */
#line 1713 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5567 "surface.c"
    break;

  case 492: /* command: match $@93 numberModuleTerm  */
#line 1719 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, (yyvsp[-2].yyBool), number);
			}
#line 5577 "surface.c"
    break;

  case 493: /* $@94: %empty  */
#line 1725 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5587 "surface.c"
    break;

  case 494: /* command: optIrredundant KW_UNIFY $@94 numberModuleTerm  */
#line 1731 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number, (yyvsp[-3].yyBool));
			}
#line 5597 "surface.c"
    break;

  case 495: /* $@95: %empty  */
#line 1737 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5607 "surface.c"
    break;

  case 496: /* command: optDebug KW_VARIANT KW_UNIFY $@95 numberModuleTerm  */
#line 1743 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, false, (yyvsp[-4].yyBool));
			}
#line 5617 "surface.c"
    break;

  case 497: /* $@96: %empty  */
#line 1749 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5627 "surface.c"
    break;

  case 498: /* command: optDebug KW_FILTERED KW_VARIANT KW_UNIFY $@96 numberModuleTerm  */
#line 1755 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, true, (yyvsp[-5].yyBool));
			}
#line 5637 "surface.c"
    break;

  case 499: /* $@97: %empty  */
#line 1761 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5647 "surface.c"
    break;

  case 500: /* command: optDebug KW_VARIANT KW_MATCH $@97 numberModuleTerm  */
#line 1767 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantMatch(lexerBubble, number, (yyvsp[-4].yyBool));
			}
#line 5657 "surface.c"
    break;

  case 501: /* $@98: %empty  */
#line 1774 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			  number = NONE;
			}
#line 5667 "surface.c"
    break;

  case 502: /* command: optDebug KW_GET optIrredundant KW_VARIANTS $@98 numberModuleTerm  */
#line 1780 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, (yyvsp[-3].yyBool), (yyvsp[-5].yyBool));
			}
#line 5677 "surface.c"
    break;

  case 503: /* command: optDebug KW_CONTINUE optNumber '.'  */
#line 1786 "surface.yy"
                        {
			  interpreter.cont((yyvsp[-1].yyInt64), (yyvsp[-3].yyBool));
			}
#line 5685 "surface.c"
    break;

  case 504: /* $@99: %empty  */
#line 1790 "surface.yy"
                        {
			  //
			  //	test is a generic command to call code with a term for development purposes.
			  //
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5697 "surface.c"
    break;

  case 505: /* command: KW_TEST $@99 moduleAndTerm  */
#line 1798 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.test(lexerBubble);
			    //interpreter.newNarrow(lexerBubble);

			}
#line 5709 "surface.c"
    break;

  case 506: /* $@100: %empty  */
#line 1806 "surface.yy"
                        {
			  lexerCmdMode();
			  moduleExpr.clear();
			}
#line 5718 "surface.c"
    break;

  case 507: /* command: KW_LOOP $@100 moduleAndTerm  */
#line 1811 "surface.yy"
                        {
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
#line 5728 "surface.c"
    break;

  case 508: /* command: parenBubble  */
#line 1817 "surface.yy"
                        {
			  moduleExpr.clear();
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
#line 5738 "surface.c"
    break;

  case 509: /* $@101: %empty  */
#line 1822 "surface.yy"
                                                { lexerCmdMode(); }
#line 5744 "surface.c"
    break;

  case 510: /* command: KW_TRACE select $@101 opSelect  */
#line 1824 "surface.yy"
                        {
			  lexerInitialMode();
			  interpreter.traceSelect((yyvsp[-2].yyBool));
			}
#line 5753 "surface.c"
    break;

  case 511: /* $@102: %empty  */
#line 1828 "surface.yy"
                                                        { lexerCmdMode(); }
#line 5759 "surface.c"
    break;

  case 512: /* command: KW_TRACE exclude $@102 opSelect  */
#line 1830 "surface.yy"
                        {
			  lexerInitialMode();
			  interpreter.traceExclude((yyvsp[-2].yyBool));
			}
#line 5768 "surface.c"
    break;

  case 513: /* $@103: %empty  */
#line 1834 "surface.yy"
                                                { lexerCmdMode(); }
#line 5774 "surface.c"
    break;

  case 514: /* command: KW_BREAK select $@103 opSelect  */
#line 1836 "surface.yy"
                        {
			  lexerInitialMode();
			  interpreter.breakSelect((yyvsp[-2].yyBool));
			}
#line 5783 "surface.c"
    break;

  case 515: /* $@104: %empty  */
#line 1840 "surface.yy"
                                                        { lexerCmdMode(); }
#line 5789 "surface.c"
    break;

  case 516: /* command: KW_PRINT conceal $@104 opSelect  */
#line 1842 "surface.yy"
                        {
			  lexerInitialMode();
			  interpreter.printConceal((yyvsp[-2].yyBool));
			}
#line 5798 "surface.c"
    break;

  case 517: /* $@105: %empty  */
#line 1846 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5804 "surface.c"
    break;

  case 518: /* command: KW_DO KW_CLEAR KW_MEMO $@105 endBubble  */
#line 1848 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->getFlatSignature()->clearMemo();
			}
#line 5813 "surface.c"
    break;

  case 519: /* $@106: %empty  */
#line 1855 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5819 "surface.c"
    break;

  case 520: /* command: KW_SHOW kw_module $@106 endBubble  */
#line 1857 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showPreModule();
			}
#line 5828 "surface.c"
    break;

  case 521: /* $@107: %empty  */
#line 1861 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5834 "surface.c"
    break;

  case 522: /* command: KW_SHOW KW_ALL $@107 endBubble  */
#line 1863 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
#line 5843 "surface.c"
    break;

  case 523: /* $@108: %empty  */
#line 1867 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5849 "surface.c"
    break;

  case 524: /* command: KW_SHOW KW_DESUGARED $@108 endBubble  */
#line 1869 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(false);
			}
#line 5858 "surface.c"
    break;

  case 525: /* $@109: %empty  */
#line 1873 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5864 "surface.c"
    break;

  case 526: /* command: KW_SHOW KW_VIEW $@109 endBubble  */
#line 1875 "surface.yy"
                        {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
#line 5873 "surface.c"
    break;

  case 527: /* $@110: %empty  */
#line 1879 "surface.yy"
                                                        { lexBubble(END_COMMAND, 0); }
#line 5879 "surface.c"
    break;

  case 528: /* command: KW_SHOW KW_PROCESSED KW_VIEW $@110 endBubble  */
#line 1881 "surface.yy"
                        {
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showProcessedView();
			}
#line 5888 "surface.c"
    break;

  case 529: /* command: KW_SHOW KW_MODULES '.'  */
#line 1886 "surface.yy"
                        {
			  interpreter.showModules(true);
			}
#line 5896 "surface.c"
    break;

  case 530: /* command: KW_SHOW KW_VIEWS '.'  */
#line 1890 "surface.yy"
                        {
			  interpreter.showViews(true);
			}
#line 5904 "surface.c"
    break;

  case 531: /* $@111: %empty  */
#line 1893 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5910 "surface.c"
    break;

  case 532: /* command: KW_SHOW KW_SORTS $@111 endBubble  */
#line 1895 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
#line 5919 "surface.c"
    break;

  case 533: /* $@112: %empty  */
#line 1899 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5925 "surface.c"
    break;

  case 534: /* command: KW_SHOW KW_OPS2 $@112 endBubble  */
#line 1901 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
#line 5934 "surface.c"
    break;

  case 535: /* $@113: %empty  */
#line 1905 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5940 "surface.c"
    break;

  case 536: /* command: KW_SHOW KW_VARS $@113 endBubble  */
#line 1907 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
#line 5949 "surface.c"
    break;

  case 537: /* $@114: %empty  */
#line 1911 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5955 "surface.c"
    break;

  case 538: /* command: KW_SHOW KW_MBS $@114 endBubble  */
#line 1913 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
#line 5964 "surface.c"
    break;

  case 539: /* $@115: %empty  */
#line 1917 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5970 "surface.c"
    break;

  case 540: /* command: KW_SHOW KW_EQS $@115 endBubble  */
#line 1919 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
#line 5979 "surface.c"
    break;

  case 541: /* $@116: %empty  */
#line 1923 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 5985 "surface.c"
    break;

  case 542: /* command: KW_SHOW KW_RLS $@116 endBubble  */
#line 1925 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
#line 5994 "surface.c"
    break;

  case 543: /* $@117: %empty  */
#line 1929 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 6000 "surface.c"
    break;

  case 544: /* command: KW_SHOW KW_STRATS $@117 endBubble  */
#line 1931 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showStrats();
			}
#line 6009 "surface.c"
    break;

  case 545: /* $@118: %empty  */
#line 1935 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 6015 "surface.c"
    break;

  case 546: /* command: KW_SHOW KW_SDS $@118 endBubble  */
#line 1937 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSds();
			}
#line 6024 "surface.c"
    break;

  case 547: /* $@119: %empty  */
#line 1941 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 6030 "surface.c"
    break;

  case 548: /* command: KW_SHOW KW_SUMMARY $@119 endBubble  */
#line 1943 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
#line 6039 "surface.c"
    break;

  case 549: /* $@120: %empty  */
#line 1947 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 6045 "surface.c"
    break;

  case 550: /* command: KW_SHOW KW_KINDS $@120 endBubble  */
#line 1949 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
#line 6054 "surface.c"
    break;

  case 551: /* command: KW_SHOW KW_PATH SIMPLE_NUMBER '.'  */
#line 1954 "surface.yy"
                        {
			  interpreter.showSearchPath((yyvsp[-1].yyInt64), true);
			}
#line 6062 "surface.c"
    break;

  case 552: /* command: KW_SHOW KW_PATH KW_STATE SIMPLE_NUMBER '.'  */
#line 1958 "surface.yy"
                        {
			  interpreter.showSearchPath((yyvsp[-1].yyInt64), false);
			}
#line 6070 "surface.c"
    break;

  case 553: /* command: KW_SHOW KW_PATH KW_LABEL SIMPLE_NUMBER '.'  */
#line 1962 "surface.yy"
                        {
			  interpreter.showSearchPathLabels((yyvsp[-1].yyInt64));
			}
#line 6078 "surface.c"
    break;

  case 554: /* command: KW_SHOW KW_SEARCH KW_GRAPH '.'  */
#line 1966 "surface.yy"
                        {
			  interpreter.showSearchGraph();
			}
#line 6086 "surface.c"
    break;

  case 555: /* $@121: %empty  */
#line 1969 "surface.yy"
                                                { lexBubble(END_COMMAND, 0); }
#line 6092 "surface.c"
    break;

  case 556: /* command: KW_SHOW KW_PROFILE $@121 endBubble  */
#line 1971 "surface.yy"
                        {
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
#line 6101 "surface.c"
    break;

  case 557: /* command: KW_SHOW KW_FRONTIER KW_STATE '.'  */
#line 1976 "surface.yy"
                        {
			  interpreter.showFrontierStates();
			}
#line 6109 "surface.c"
    break;

  case 558: /* command: KW_SHOW KW_MOST KW_GENERAL KW_STATE '.'  */
#line 1980 "surface.yy"
                        {
			  interpreter.showMostGeneralStates();
			}
#line 6117 "surface.c"
    break;

  case 559: /* command: KW_SET KW_SHOW KW_ADVISE polarityDot  */
#line 1987 "surface.yy"
                        {
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : (yyvsp[0].yyBool);
			}
#line 6125 "surface.c"
    break;

  case 560: /* command: KW_SET KW_SHOW KW_STATS polarityDot  */
#line 1991 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[0].yyBool));
			}
#line 6133 "surface.c"
    break;

  case 561: /* command: KW_SET KW_SHOW KW_LOOP KW_STATS polarityDot  */
#line 1995 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, (yyvsp[0].yyBool));
			}
#line 6141 "surface.c"
    break;

  case 562: /* command: KW_SET KW_SHOW KW_TIMING polarityDot  */
#line 1999 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_TIMING, (yyvsp[0].yyBool));
			}
#line 6149 "surface.c"
    break;

  case 563: /* command: KW_SET KW_SHOW KW_BREAKDOWN polarityDot  */
#line 2003 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, (yyvsp[0].yyBool));
			}
#line 6157 "surface.c"
    break;

  case 564: /* command: KW_SET KW_SHOW KW_LOOP KW_TIMING polarityDot  */
#line 2007 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, (yyvsp[0].yyBool));
			}
#line 6165 "surface.c"
    break;

  case 565: /* command: KW_SET KW_SHOW KW_CMD polarityDot  */
#line 2011 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, (yyvsp[0].yyBool));
			}
#line 6173 "surface.c"
    break;

  case 566: /* command: KW_SET KW_SHOW KW_GC polarityDot  */
#line 2015 "surface.yy"
                        {
			  MemoryCell::setShowGC((yyvsp[0].yyBool));
			}
#line 6181 "surface.c"
    break;

  case 567: /* command: KW_SET KW_SHOW KW_RESOURCES polarityDot  */
#line 2019 "surface.yy"
                        {
			  MemoryCell::setShowResources((yyvsp[0].yyBool));
			}
#line 6189 "surface.c"
    break;

  case 568: /* command: KW_SET KW_PRINT printOption polarityDot  */
#line 2023 "surface.yy"
                        {
			  interpreter.setPrintFlag((yyvsp[-1].yyPrintFlags), (yyvsp[0].yyBool));
			}
#line 6197 "surface.c"
    break;

  case 569: /* command: KW_SET KW_PRINT KW_ATTRIBUTE polarityDot  */
#line 2027 "surface.yy"
                        {
			  // a general flag, not a print flag, to activate print attribute
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, (yyvsp[0].yyBool));
			}
#line 6206 "surface.c"
    break;

  case 570: /* command: KW_SET KW_PRINT KW_ATTRIBUTE KW_NEWLINE polarityDot  */
#line 2032 "surface.yy"
                        {
			  // a general flag, not a print flag, to print a newline after print attribute message
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, (yyvsp[0].yyBool));
			}
#line 6215 "surface.c"
    break;

  case 571: /* command: KW_SET KW_TRACE traceOption polarityDot  */
#line 2037 "surface.yy"
                        {
			  interpreter.setFlag((yyvsp[-1].yyFlags), (yyvsp[0].yyBool));
			}
#line 6223 "surface.c"
    break;

  case 572: /* command: KW_SET KW_BREAK polarityDot  */
#line 2041 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::BREAK, (yyvsp[0].yyBool));
			}
#line 6231 "surface.c"
    break;

  case 573: /* $@122: %empty  */
#line 2044 "surface.yy"
                                                        { lexerCmdMode(); }
#line 6237 "surface.c"
    break;

  case 574: /* $@123: %empty  */
#line 2045 "surface.yy"
                                                        { lexerInitialMode(); }
#line 6243 "surface.c"
    break;

  case 575: /* command: KW_SET importMode $@122 cSimpleTokenBarDot $@123 polarityDot  */
#line 2047 "surface.yy"
                        {
			  interpreter.setAutoImport((yyvsp[-4].yyImportMode), (yyvsp[-2].yyToken), (yyvsp[0].yyBool));
			}
#line 6251 "surface.c"
    break;

  case 576: /* $@124: %empty  */
#line 2050 "surface.yy"
                                                        { lexerCmdMode(); }
#line 6257 "surface.c"
    break;

  case 577: /* $@125: %empty  */
#line 2051 "surface.yy"
                                                        { lexerInitialMode(); }
#line 6263 "surface.c"
    break;

  case 578: /* command: KW_SET KW_OO KW_INCLUDE $@124 cSimpleTokenBarDot $@125 polarityDot  */
#line 2053 "surface.yy"
                        {
			  interpreter.setOoInclude((yyvsp[-2].yyToken), (yyvsp[0].yyBool));
			}
#line 6271 "surface.c"
    break;

  case 579: /* command: KW_SET KW_VERBOSE polarityDot  */
#line 2057 "surface.yy"
                        {
			  globalVerboseFlag = (yyvsp[0].yyBool);
			}
#line 6279 "surface.c"
    break;

  case 580: /* command: KW_SET KW_CLEAR KW_MEMO polarityDot  */
#line 2061 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, (yyvsp[0].yyBool));
			}
#line 6287 "surface.c"
    break;

  case 581: /* command: KW_SET KW_CLEAR KW_RLS polarityDot  */
#line 2065 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, (yyvsp[0].yyBool));
			}
#line 6295 "surface.c"
    break;

  case 582: /* command: KW_SET KW_COMPILE KW_COUNT polarityDot  */
#line 2069 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, (yyvsp[0].yyBool));
			}
#line 6303 "surface.c"
    break;

  case 583: /* command: KW_SET KW_PROFILE polarityDot  */
#line 2073 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::PROFILE, (yyvsp[0].yyBool));
			}
#line 6311 "surface.c"
    break;

  case 584: /* command: KW_SET KW_CLEAR KW_PROFILE polarityDot  */
#line 2077 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, (yyvsp[0].yyBool));
			}
#line 6319 "surface.c"
    break;

  case 585: /* command: KW_SET KW_CLEAR kw_module KW_CACHES polarityDot  */
#line 2081 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_CACHES, (yyvsp[0].yyBool));
			}
#line 6327 "surface.c"
    break;

  case 586: /* command: KW_RESUME '.'  */
#line 2088 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
#line 6335 "surface.c"
    break;

  case 587: /* command: KW_ABORT '.'  */
#line 2092 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
#line 6343 "surface.c"
    break;

  case 588: /* command: KW_STEP '.'  */
#line 2096 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
#line 6351 "surface.c"
    break;

  case 589: /* command: KW_IMPLIED_STEP  */
#line 2100 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
#line 6359 "surface.c"
    break;

  case 590: /* command: KW_WHERE '.'  */
#line 2104 "surface.yy"
                        {
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
#line 6367 "surface.c"
    break;

  case 591: /* command: KW_SET KW_GC KW_SHOW polarityDot  */
#line 2111 "surface.yy"
                        {
			  MemoryCell::setShowGC((yyvsp[0].yyBool));
			}
#line 6375 "surface.c"
    break;

  case 592: /* command: KW_SET KW_STATS polarityDot  */
#line 2115 "surface.yy"
                        {
			  interpreter.setFlag(Interpreter::SHOW_STATS, (yyvsp[0].yyBool));
			}
#line 6383 "surface.c"
    break;

  case 593: /* $@126: %empty  */
#line 2121 "surface.yy"
                                                { lexerInitialMode(); }
#line 6389 "surface.c"
    break;

  case 597: /* printOption: KW_MIXFIX  */
#line 2134 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_MIXFIX; }
#line 6395 "surface.c"
    break;

  case 598: /* printOption: KW_FLAT  */
#line 2135 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_FLAT; }
#line 6401 "surface.c"
    break;

  case 599: /* printOption: KW_WITH KW_ALIASES  */
#line 2136 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_WITH_ALIASES; }
#line 6407 "surface.c"
    break;

  case 600: /* printOption: KW_WITH KW_PARENS  */
#line 2137 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_WITH_PARENS; }
#line 6413 "surface.c"
    break;

  case 601: /* printOption: KW_GRAPH  */
#line 2138 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_GRAPH; }
#line 6419 "surface.c"
    break;

  case 602: /* printOption: KW_CONCEAL  */
#line 2139 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_CONCEAL; }
#line 6425 "surface.c"
    break;

  case 603: /* printOption: KW_NUMBER  */
#line 2140 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_NUMBER; }
#line 6431 "surface.c"
    break;

  case 604: /* printOption: KW_RAT  */
#line 2141 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_RAT; }
#line 6437 "surface.c"
    break;

  case 605: /* printOption: KW_COLOR  */
#line 2142 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_COLOR; }
#line 6443 "surface.c"
    break;

  case 606: /* printOption: KW_FORMAT  */
#line 2143 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_FORMAT; }
#line 6449 "surface.c"
    break;

  case 607: /* printOption: KW_CONST KW_WITH KW_SORTS  */
#line 2144 "surface.yy"
                                                        { (yyval.yyPrintFlags) = PrintSettings::PRINT_DISAMBIG_CONST; }
#line 6455 "surface.c"
    break;

  case 608: /* printOption: KW_LABEL KW_ATTRIBUTE  */
#line 2145 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_LABEL_ATTRIBUTE; }
#line 6461 "surface.c"
    break;

  case 609: /* printOption: KW_HOOKS  */
#line 2146 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_HOOKS; }
#line 6467 "surface.c"
    break;

  case 610: /* printOption: KW_COMBINE KW_VARS  */
#line 2147 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_COMBINE_VARS; }
#line 6473 "surface.c"
    break;

  case 611: /* printOption: KW_LATEX  */
#line 2148 "surface.yy"
                                                { (yyval.yyPrintFlags) = PrintSettings::PRINT_LATEX; }
#line 6479 "surface.c"
    break;

  case 612: /* traceOption: %empty  */
#line 2151 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE; }
#line 6485 "surface.c"
    break;

  case 613: /* traceOption: KW_CONDITION  */
#line 2152 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_CONDITION; }
#line 6491 "surface.c"
    break;

  case 614: /* traceOption: KW_WHOLE  */
#line 2153 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_WHOLE; }
#line 6497 "surface.c"
    break;

  case 615: /* traceOption: KW_SUBSTITUTION  */
#line 2154 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_SUBSTITUTION; }
#line 6503 "surface.c"
    break;

  case 616: /* traceOption: KW_SELECT  */
#line 2155 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_SELECT; }
#line 6509 "surface.c"
    break;

  case 617: /* traceOption: KW_MBS  */
#line 2156 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_MB; }
#line 6515 "surface.c"
    break;

  case 618: /* traceOption: KW_EQS  */
#line 2157 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_EQ; }
#line 6521 "surface.c"
    break;

  case 619: /* traceOption: KW_RLS  */
#line 2158 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_RL; }
#line 6527 "surface.c"
    break;

  case 620: /* traceOption: KW_SDS  */
#line 2159 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_SD; }
#line 6533 "surface.c"
    break;

  case 621: /* traceOption: KW_REWRITE  */
#line 2160 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_REWRITE; }
#line 6539 "surface.c"
    break;

  case 622: /* traceOption: KW_BODY  */
#line 2161 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_BODY; }
#line 6545 "surface.c"
    break;

  case 623: /* traceOption: KW_BUILTIN  */
#line 2162 "surface.yy"
                                                { (yyval.yyFlags) = Interpreter::TRACE_BUILTIN; }
#line 6551 "surface.c"
    break;

  case 624: /* polarityDot: KW_ON '.'  */
#line 2165 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6557 "surface.c"
    break;

  case 625: /* polarityDot: KW_OFF '.'  */
#line 2166 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6563 "surface.c"
    break;

  case 626: /* polarityDot: KW_ON_DOT  */
#line 2168 "surface.yy"
                        {
			  IssueWarning(LineNumber(lineNumber) << ": missing space between " << QUOTE("on") << " and period.");
			  (yyval.yyBool) = true;
			}
#line 6572 "surface.c"
    break;

  case 627: /* polarityDot: KW_OFF_DOT  */
#line 2173 "surface.yy"
                        {
			  IssueWarning(LineNumber(lineNumber) << ": missing space between " << QUOTE("off") << " and period.");
			  (yyval.yyBool) = false;
			}
#line 6581 "surface.c"
    break;

  case 628: /* select: KW_SELECT  */
#line 2179 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6587 "surface.c"
    break;

  case 629: /* select: KW_DESELECT  */
#line 2180 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6593 "surface.c"
    break;

  case 630: /* exclude: KW_EXCLUDE  */
#line 2183 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6599 "surface.c"
    break;

  case 631: /* exclude: KW_INCLUDE  */
#line 2184 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6605 "surface.c"
    break;

  case 632: /* conceal: KW_CONCEAL  */
#line 2187 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6611 "surface.c"
    break;

  case 633: /* conceal: KW_REVEAL  */
#line 2188 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6617 "surface.c"
    break;

  case 634: /* search: KW_NARROW  */
#line 2193 "surface.yy"
                                                { (yyval.yySearchKind) = Interpreter::NARROW; }
#line 6623 "surface.c"
    break;

  case 635: /* search: KW_XG_NARROW  */
#line 2194 "surface.yy"
                                                { (yyval.yySearchKind) = Interpreter::XG_NARROW; }
#line 6629 "surface.c"
    break;

  case 636: /* search: KW_SEARCH  */
#line 2195 "surface.yy"
                                                { (yyval.yySearchKind) = Interpreter::SEARCH; }
#line 6635 "surface.c"
    break;

  case 637: /* search: KW_SMT_SEARCH  */
#line 2196 "surface.yy"
                                                { (yyval.yySearchKind) = Interpreter::SMT_SEARCH; }
#line 6641 "surface.c"
    break;

  case 638: /* search: KW_FVU_NARROW  */
#line 2197 "surface.yy"
                                                { (yyval.yySearchKind) = Interpreter::FVU_NARROW; }
#line 6647 "surface.c"
    break;

  case 639: /* match: KW_XMATCH  */
#line 2200 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6653 "surface.c"
    break;

  case 640: /* match: KW_MATCH  */
#line 2201 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6659 "surface.c"
    break;

  case 641: /* optDebug: KW_DEBUG  */
#line 2204 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6665 "surface.c"
    break;

  case 642: /* optDebug: %empty  */
#line 2205 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6671 "surface.c"
    break;

  case 643: /* optIrredundant: KW_IRREDUNDANT  */
#line 2208 "surface.yy"
                                                { (yyval.yyBool) = true; }
#line 6677 "surface.c"
    break;

  case 644: /* optIrredundant: %empty  */
#line 2209 "surface.yy"
                                                { (yyval.yyBool) = false; }
#line 6683 "surface.c"
    break;

  case 645: /* optNumber: SIMPLE_NUMBER  */
#line 2212 "surface.yy"
                                                { (yyval.yyInt64) = (yyvsp[0].yyInt64); }
#line 6689 "surface.c"
    break;

  case 646: /* optNumber: %empty  */
#line 2213 "surface.yy"
                                                { (yyval.yyInt64) = NONE; }
#line 6695 "surface.c"
    break;

  case 647: /* optOptions: '{' optionsList '}'  */
#line 2216 "surface.yy"
                                                { (yyval.yyInt64) = (yyvsp[-1].yyInt64); }
#line 6701 "surface.c"
    break;

  case 648: /* optOptions: %empty  */
#line 2217 "surface.yy"
                                                { (yyval.yyInt64) = 0; }
#line 6707 "surface.c"
    break;

  case 649: /* optionsList: option  */
#line 2220 "surface.yy"
                                                { (yyval.yyInt64) = (yyvsp[0].yyInt64); }
#line 6713 "surface.c"
    break;

  case 650: /* optionsList: optionsList ',' option  */
#line 2221 "surface.yy"
                                                { (yyval.yyInt64) = (yyvsp[-2].yyInt64) | (yyvsp[0].yyInt64); }
#line 6719 "surface.c"
    break;

  case 651: /* option: KW_FOLD  */
#line 2224 "surface.yy"
                                                { (yyval.yyInt64) = NarrowingSequenceSearch3::FOLD; }
#line 6725 "surface.c"
    break;

  case 652: /* option: KW_VFOLD  */
#line 2225 "surface.yy"
                                                { (yyval.yyInt64) = NarrowingSequenceSearch3::VFOLD; }
#line 6731 "surface.c"
    break;

  case 653: /* option: KW_PATH  */
#line 2226 "surface.yy"
                                                { (yyval.yyInt64) = NarrowingSequenceSearch3::KEEP_PATHS; }
#line 6737 "surface.c"
    break;

  case 654: /* importMode: KW_PROTECT  */
#line 2229 "surface.yy"
                                                { (yyval.yyImportMode) = ImportModule::PROTECTING; }
#line 6743 "surface.c"
    break;

  case 655: /* importMode: KW_EXTEND  */
#line 2230 "surface.yy"
                                                { (yyval.yyImportMode) = ImportModule::EXTENDING; }
#line 6749 "surface.c"
    break;

  case 656: /* importMode: KW_GENERATE_BY  */
#line 2231 "surface.yy"
                                                { (yyval.yyImportMode) = ImportModule::GENERATED_BY; }
#line 6755 "surface.c"
    break;

  case 657: /* importMode: KW_INCLUDE  */
#line 2232 "surface.yy"
                                                { (yyval.yyImportMode) = ImportModule::INCLUDING; }
#line 6761 "surface.c"
    break;

  case 659: /* $@127: %empty  */
#line 2242 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6767 "surface.c"
    break;

  case 661: /* $@128: %empty  */
#line 2246 "surface.yy"
                                                { moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
#line 6773 "surface.c"
    break;

  case 664: /* $@129: %empty  */
#line 2258 "surface.yy"
                                                { lexSave((yyvsp[0].yyToken)); }
#line 6779 "surface.c"
    break;

  case 667: /* $@130: %empty  */
#line 2261 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0);  }
#line 6785 "surface.c"
    break;

  case 669: /* $@131: %empty  */
#line 2266 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6791 "surface.c"
    break;

  case 671: /* $@132: %empty  */
#line 2268 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6797 "surface.c"
    break;

  case 674: /* $@133: %empty  */
#line 2274 "surface.yy"
                                                { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 6803 "surface.c"
    break;

  case 676: /* $@134: %empty  */
#line 2276 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6809 "surface.c"
    break;

  case 679: /* $@135: %empty  */
#line 2292 "surface.yy"
                                                { lexSave((yyvsp[0].yyToken)); }
#line 6815 "surface.c"
    break;

  case 681: /* $@136: %empty  */
#line 2294 "surface.yy"
                                                { lexSave((yyvsp[0].yyToken)); }
#line 6821 "surface.c"
    break;

  case 684: /* $@137: %empty  */
#line 2297 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6827 "surface.c"
    break;

  case 686: /* $@138: %empty  */
#line 2303 "surface.yy"
                        {
			  lexContinueSave((yyvsp[0].yyToken));
			  variantOptions |= VariantUnificationProblem::FILTER_VARIANT_UNIFIERS;
			}
#line 6836 "surface.c"
    break;

  case 688: /* $@139: %empty  */
#line 2309 "surface.yy"
                        {
			  lexContinueSave((yyvsp[0].yyToken));
			  variantOptions |= VariantSearch::IRREDUNDANT_MODE;
			}
#line 6845 "surface.c"
    break;

  case 690: /* $@140: %empty  */
#line 2314 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6851 "surface.c"
    break;

  case 694: /* $@141: %empty  */
#line 2322 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6857 "surface.c"
    break;

  case 696: /* $@142: %empty  */
#line 2324 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6863 "surface.c"
    break;

  case 699: /* $@143: %empty  */
#line 2333 "surface.yy"
                                                { lexSave((yyvsp[0].yyToken)); }
#line 6869 "surface.c"
    break;

  case 702: /* $@144: %empty  */
#line 2336 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6875 "surface.c"
    break;

  case 704: /* $@145: %empty  */
#line 2345 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6881 "surface.c"
    break;

  case 706: /* $@146: %empty  */
#line 2347 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6887 "surface.c"
    break;

  case 708: /* $@147: %empty  */
#line 2349 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6893 "surface.c"
    break;

  case 711: /* $@148: %empty  */
#line 2359 "surface.yy"
                                                { number = Token::codeToInt64(lexerBubble[1].code()); }
#line 6899 "surface.c"
    break;

  case 713: /* $@149: %empty  */
#line 2361 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6905 "surface.c"
    break;

  case 715: /* $@150: %empty  */
#line 2363 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6911 "surface.c"
    break;

  case 718: /* $@151: %empty  */
#line 2373 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6917 "surface.c"
    break;

  case 720: /* $@152: %empty  */
#line 2375 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6923 "surface.c"
    break;

  case 723: /* $@153: %empty  */
#line 2386 "surface.yy"
                        {
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  tokensClear();
			}
#line 6933 "surface.c"
    break;

  case 725: /* $@154: %empty  */
#line 2392 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6939 "surface.c"
    break;

  case 728: /* $@155: %empty  */
#line 2402 "surface.yy"
                                                { lexContinueSave((yyvsp[0].yyToken)); }
#line 6945 "surface.c"
    break;

  case 730: /* $@156: %empty  */
#line 2404 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6951 "surface.c"
    break;

  case 733: /* $@157: %empty  */
#line 2414 "surface.yy"
                                                { number2 = Token::codeToInt64(lexerBubble[2].code()); }
#line 6957 "surface.c"
    break;

  case 735: /* $@158: %empty  */
#line 2416 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0); }
#line 6963 "surface.c"
    break;

  case 738: /* $@159: %empty  */
#line 2421 "surface.yy"
                                                { lexContinueBubble((yyvsp[0].yyToken), END_COMMAND, 0, 1); }
#line 6969 "surface.c"
    break;

  case 741: /* $@160: %empty  */
#line 2432 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), END_COMMAND, 1, 1); }
#line 6975 "surface.c"
    break;

  case 743: /* $@161: %empty  */
#line 2434 "surface.yy"
                                                { lexBubble((yyvsp[0].yyToken), BAR_COLON | END_COMMAND, 0); }
#line 6981 "surface.c"
    break;

  case 745: /* initialEndBubble: ENDS_IN_DOT  */
#line 2437 "surface.yy"
                        {
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(lexerBubble[0]);
			}
#line 6991 "surface.c"
    break;

  case 826: /* endSelect: '.'  */
#line 2488 "surface.yy"
                                        {}
#line 6997 "surface.c"
    break;

  case 828: /* badSelect: ENDS_IN_DOT  */
#line 2493 "surface.yy"
                        {
			  singleton[0].dropChar((yyvsp[0].yyToken));
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}
#line 7007 "surface.c"
    break;

  case 831: /* cSimpleOpName: cSimpleTokenBarDot  */
#line 2504 "surface.yy"
                        {
			  singleton[0] = (yyvsp[0].yyToken);
			  interpreter.addSelected(singleton);
			}
#line 7016 "surface.c"
    break;

  case 832: /* cSimpleOpName: parenBubble  */
#line 2509 "surface.yy"
                        {
			  interpreter.addSelected(lexerBubble);
			}
#line 7024 "surface.c"
    break;


#line 7028 "surface.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (parseResult, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parseResult);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parseResult);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parseResult, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parseResult);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parseResult);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2543 "surface.yy"


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
