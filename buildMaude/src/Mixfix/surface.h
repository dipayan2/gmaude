/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SURFACE_H_INCLUDED
# define YY_YY_SURFACE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FILE_NAME_STRING = 258,        /* FILE_NAME_STRING  */
    UNINTERPRETED_STRING = 259,    /* UNINTERPRETED_STRING  */
    LATEX_STRING = 260,            /* LATEX_STRING  */
    KW_MOD = 261,                  /* KW_MOD  */
    KW_VIEW = 262,                 /* KW_VIEW  */
    KW_PARSE = 263,                /* KW_PARSE  */
    KW_NORMALIZE = 264,            /* KW_NORMALIZE  */
    KW_REDUCE = 265,               /* KW_REDUCE  */
    KW_REWRITE = 266,              /* KW_REWRITE  */
    KW_OO = 267,                   /* KW_OO  */
    KW_LOOP = 268,                 /* KW_LOOP  */
    KW_NARROW = 269,               /* KW_NARROW  */
    KW_XG_NARROW = 270,            /* KW_XG_NARROW  */
    KW_MATCH = 271,                /* KW_MATCH  */
    KW_XMATCH = 272,               /* KW_XMATCH  */
    KW_UNIFY = 273,                /* KW_UNIFY  */
    KW_CHECK = 274,                /* KW_CHECK  */
    KW_GET = 275,                  /* KW_GET  */
    KW_VARIANTS = 276,             /* KW_VARIANTS  */
    KW_VARIANT = 277,              /* KW_VARIANT  */
    KW_EREWRITE = 278,             /* KW_EREWRITE  */
    KW_FREWRITE = 279,             /* KW_FREWRITE  */
    KW_SREWRITE = 280,             /* KW_SREWRITE  */
    KW_DSREWRITE = 281,            /* KW_DSREWRITE  */
    KW_CONTINUE = 282,             /* KW_CONTINUE  */
    KW_SEARCH = 283,               /* KW_SEARCH  */
    KW_SET = 284,                  /* KW_SET  */
    KW_SHOW = 285,                 /* KW_SHOW  */
    KW_ON = 286,                   /* KW_ON  */
    KW_OFF = 287,                  /* KW_OFF  */
    KW_ON_DOT = 288,               /* KW_ON_DOT  */
    KW_OFF_DOT = 289,              /* KW_OFF_DOT  */
    KW_TRACE = 290,                /* KW_TRACE  */
    KW_BODY = 291,                 /* KW_BODY  */
    KW_BUILTIN = 292,              /* KW_BUILTIN  */
    KW_WHOLE = 293,                /* KW_WHOLE  */
    KW_SELECT = 294,               /* KW_SELECT  */
    KW_DESELECT = 295,             /* KW_DESELECT  */
    KW_CONDITION = 296,            /* KW_CONDITION  */
    KW_SUBSTITUTION = 297,         /* KW_SUBSTITUTION  */
    KW_PRINT = 298,                /* KW_PRINT  */
    KW_GRAPH = 299,                /* KW_GRAPH  */
    KW_MIXFIX = 300,               /* KW_MIXFIX  */
    KW_FLAT = 301,                 /* KW_FLAT  */
    KW_ATTRIBUTE = 302,            /* KW_ATTRIBUTE  */
    KW_NEWLINE = 303,              /* KW_NEWLINE  */
    KW_WITH = 304,                 /* KW_WITH  */
    KW_PARENS = 305,               /* KW_PARENS  */
    KW_ALIASES = 306,              /* KW_ALIASES  */
    KW_GC = 307,                   /* KW_GC  */
    KW_RESOURCES = 308,            /* KW_RESOURCES  */
    KW_TIME = 309,                 /* KW_TIME  */
    KW_STATS = 310,                /* KW_STATS  */
    KW_TIMING = 311,               /* KW_TIMING  */
    KW_CMD = 312,                  /* KW_CMD  */
    KW_BREAKDOWN = 313,            /* KW_BREAKDOWN  */
    KW_BREAK = 314,                /* KW_BREAK  */
    KW_PATH = 315,                 /* KW_PATH  */
    KW_STATE = 316,                /* KW_STATE  */
    KW_CONST = 317,                /* KW_CONST  */
    KW_MODULE = 318,               /* KW_MODULE  */
    KW_MODULES = 319,              /* KW_MODULES  */
    KW_VIEWS = 320,                /* KW_VIEWS  */
    KW_ALL = 321,                  /* KW_ALL  */
    KW_SORTS = 322,                /* KW_SORTS  */
    KW_OPS2 = 323,                 /* KW_OPS2  */
    KW_VARS = 324,                 /* KW_VARS  */
    KW_MBS = 325,                  /* KW_MBS  */
    KW_EQS = 326,                  /* KW_EQS  */
    KW_RLS = 327,                  /* KW_RLS  */
    KW_STRATS = 328,               /* KW_STRATS  */
    KW_SDS = 329,                  /* KW_SDS  */
    KW_SUMMARY = 330,              /* KW_SUMMARY  */
    KW_KINDS = 331,                /* KW_KINDS  */
    KW_ADVISE = 332,               /* KW_ADVISE  */
    KW_VERBOSE = 333,              /* KW_VERBOSE  */
    KW_DO = 334,                   /* KW_DO  */
    KW_CLEAR = 335,                /* KW_CLEAR  */
    KW_CACHES = 336,               /* KW_CACHES  */
    KW_HOOKS = 337,                /* KW_HOOKS  */
    KW_COMBINE = 338,              /* KW_COMBINE  */
    KW_PROTECT = 339,              /* KW_PROTECT  */
    KW_EXTEND = 340,               /* KW_EXTEND  */
    KW_GENERATE_BY = 341,          /* KW_GENERATE_BY  */
    KW_INCLUDE = 342,              /* KW_INCLUDE  */
    KW_EXCLUDE = 343,              /* KW_EXCLUDE  */
    KW_CONCEAL = 344,              /* KW_CONCEAL  */
    KW_REVEAL = 345,               /* KW_REVEAL  */
    KW_COMPILE = 346,              /* KW_COMPILE  */
    KW_COUNT = 347,                /* KW_COUNT  */
    KW_DEBUG = 348,                /* KW_DEBUG  */
    KW_IRREDUNDANT = 349,          /* KW_IRREDUNDANT  */
    KW_FILTERED = 350,             /* KW_FILTERED  */
    KW_RESUME = 351,               /* KW_RESUME  */
    KW_ABORT = 352,                /* KW_ABORT  */
    KW_STEP = 353,                 /* KW_STEP  */
    KW_WHERE = 354,                /* KW_WHERE  */
    KW_CREDUCE = 355,              /* KW_CREDUCE  */
    KW_SREDUCE = 356,              /* KW_SREDUCE  */
    KW_DUMP = 357,                 /* KW_DUMP  */
    KW_PROFILE = 358,              /* KW_PROFILE  */
    KW_NUMBER = 359,               /* KW_NUMBER  */
    KW_RAT = 360,                  /* KW_RAT  */
    KW_COLOR = 361,                /* KW_COLOR  */
    KW_IMPLIED_STEP = 362,         /* KW_IMPLIED_STEP  */
    SIMPLE_NUMBER = 363,           /* SIMPLE_NUMBER  */
    KW_PWD = 364,                  /* KW_PWD  */
    KW_CD = 365,                   /* KW_CD  */
    KW_PUSHD = 366,                /* KW_PUSHD  */
    KW_POPD = 367,                 /* KW_POPD  */
    KW_LS = 368,                   /* KW_LS  */
    KW_LL = 369,                   /* KW_LL  */
    KW_LOAD = 370,                 /* KW_LOAD  */
    KW_SLOAD = 371,                /* KW_SLOAD  */
    KW_QUIT = 372,                 /* KW_QUIT  */
    KW_EOF = 373,                  /* KW_EOF  */
    KW_TEST = 374,                 /* KW_TEST  */
    KW_SMT_SEARCH = 375,           /* KW_SMT_SEARCH  */
    KW_VU_NARROW = 376,            /* KW_VU_NARROW  */
    KW_FVU_NARROW = 377,           /* KW_FVU_NARROW  */
    KW_FOLD = 378,                 /* KW_FOLD  */
    KW_VFOLD = 379,                /* KW_VFOLD  */
    KW_DESUGARED = 380,            /* KW_DESUGARED  */
    KW_PROCESSED = 381,            /* KW_PROCESSED  */
    KW_FRONTIER = 382,             /* KW_FRONTIER  */
    KW_MOST = 383,                 /* KW_MOST  */
    KW_GENERAL = 384,              /* KW_GENERAL  */
    KW_ENDM = 385,                 /* KW_ENDM  */
    KW_IMPORT = 386,               /* KW_IMPORT  */
    KW_ENDV = 387,                 /* KW_ENDV  */
    KW_SORT = 388,                 /* KW_SORT  */
    KW_SUBSORT = 389,              /* KW_SUBSORT  */
    KW_OP = 390,                   /* KW_OP  */
    KW_OPS = 391,                  /* KW_OPS  */
    KW_MSGS = 392,                 /* KW_MSGS  */
    KW_VAR = 393,                  /* KW_VAR  */
    KW_CLASS = 394,                /* KW_CLASS  */
    KW_SUBCLASS = 395,             /* KW_SUBCLASS  */
    KW_DSTRAT = 396,               /* KW_DSTRAT  */
    KW_MB = 397,                   /* KW_MB  */
    KW_CMB = 398,                  /* KW_CMB  */
    KW_EQ = 399,                   /* KW_EQ  */
    KW_CEQ = 400,                  /* KW_CEQ  */
    KW_RL = 401,                   /* KW_RL  */
    KW_CRL = 402,                  /* KW_CRL  */
    KW_SD = 403,                   /* KW_SD  */
    KW_CSD = 404,                  /* KW_CSD  */
    KW_ATTR = 405,                 /* KW_ATTR  */
    KW_IS = 406,                   /* KW_IS  */
    KW_FROM = 407,                 /* KW_FROM  */
    KW_ARROW = 408,                /* KW_ARROW  */
    KW_ARROW2 = 409,               /* KW_ARROW2  */
    KW_PARTIAL = 410,              /* KW_PARTIAL  */
    KW_IF = 411,                   /* KW_IF  */
    KW_ASSIGN = 412,               /* KW_ASSIGN  */
    KW_LABEL = 413,                /* KW_LABEL  */
    KW_TO = 414,                   /* KW_TO  */
    KW_COLON2 = 415,               /* KW_COLON2  */
    KW_ASSOC = 416,                /* KW_ASSOC  */
    KW_COMM = 417,                 /* KW_COMM  */
    KW_ID = 418,                   /* KW_ID  */
    KW_IDEM = 419,                 /* KW_IDEM  */
    KW_ITER = 420,                 /* KW_ITER  */
    KW_PCONST = 421,               /* KW_PCONST  */
    KW_LEFT = 422,                 /* KW_LEFT  */
    KW_RIGHT = 423,                /* KW_RIGHT  */
    KW_PREC = 424,                 /* KW_PREC  */
    KW_GATHER = 425,               /* KW_GATHER  */
    KW_METADATA = 426,             /* KW_METADATA  */
    KW_STRAT = 427,                /* KW_STRAT  */
    KW_ASTRAT = 428,               /* KW_ASTRAT  */
    KW_POLY = 429,                 /* KW_POLY  */
    KW_MEMO = 430,                 /* KW_MEMO  */
    KW_FROZEN = 431,               /* KW_FROZEN  */
    KW_CTOR = 432,                 /* KW_CTOR  */
    KW_LATEX = 433,                /* KW_LATEX  */
    KW_SPECIAL = 434,              /* KW_SPECIAL  */
    KW_CONFIG = 435,               /* KW_CONFIG  */
    KW_OBJ = 436,                  /* KW_OBJ  */
    KW_MSG = 437,                  /* KW_MSG  */
    KW_PORTAL = 438,               /* KW_PORTAL  */
    KW_DITTO = 439,                /* KW_DITTO  */
    KW_FORMAT = 440,               /* KW_FORMAT  */
    KW_ID_HOOK = 441,              /* KW_ID_HOOK  */
    KW_OP_HOOK = 442,              /* KW_OP_HOOK  */
    KW_TERM_HOOK = 443,            /* KW_TERM_HOOK  */
    KW_IN = 444,                   /* KW_IN  */
    KW_FILTER = 445,               /* KW_FILTER  */
    KW_DELAY = 446,                /* KW_DELAY  */
    IDENTIFIER = 447,              /* IDENTIFIER  */
    NUMERIC_ID = 448,              /* NUMERIC_ID  */
    ENDS_IN_DOT = 449,             /* ENDS_IN_DOT  */
    FORCE_LOOKAHEAD = 450,         /* FORCE_LOOKAHEAD  */
    CHANGE_FILE = 451,             /* CHANGE_FILE  */
    END_OF_INPUT = 452             /* END_OF_INPUT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 123 "surface.yy"

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

#line 275 "surface.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (UserLevelRewritingContext::ParseResult* parseResult);


#endif /* !YY_YY_SURFACE_H_INCLUDED  */
