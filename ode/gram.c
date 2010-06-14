
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gram.y"

/* Copyright Nicholas B. Tufillaro, 1982-1994. All rights reserved.
 *
 * GNU enhancements Copyright (C) 1996, 1999, 2005, Free Software 
 * Foundation, Inc.
 */
/*
 * Grammar for ode:
 * Most things are self-explanatory.
 * When you're done with a lexptr-type object
 * you should free it with lfree.  They are
 * used for passing constants around while parsing
 * (computing the value of) a cexpr.  The macros
 * for evaluating operators and functions are the
 * most important thing to be familiar with before
 * toying with the semantics.
 */
#include "sys-defines.h"
#include "ode.h"
#include "extern.h"

/*
 * Value is true iff operands pass ONECON.
 */
#define TWOCON(x,y) (ONECON(x) && ONECON(y))
#define THREECON(x,y,z) (ONECON(x) && ONECON(y) && ONECON(z))
/*
 * Value must be a (struct expr *).  Returns true if its arg, when
 * evaluated, would put a constant on the stack.
 */
#define ONECON(x) (x->ex_oper == O_CONST && x->ex_next == NULL)
/*
 * Performs ordinary binary arithmetic, when there are two constants in an
 * expr (`op' is a C operator that includes an assignment, e.g., +=).
 */
#define COMBINE(x,y,r,op) {x->ex_value op y->ex_value; efree(y); r = x;}
/*
 * Generates stack code for a binary operation, as for a dyadic operator in
 * an expression.  E.g., op = O_PLUS.
 */
#define BINARY(x,y,r,op) {struct expr *ep=ealloc();\
                ep->ex_oper = op;\
                concat(y,ep);\
                concat(r=x,y);}
/*
 * Generates stack code for a ternary operation, as for a triadic operator in
 * an expression.  E.g., op = O_IBETA.
 */
#define TERNARY(x,y,z,r,op) {struct expr *ep=ealloc();\
                ep->ex_oper = op;\
                concat(z,ep);\
                concat(y,z);\
                concat(r=x,y);}
/*
 * Performs ordinary unary arithmetic, when there is a constant in an expr.
 * "-" seems to work as a monadic operator.
 */
#define CONFUNC(x,r,f) {x->ex_value = f(x->ex_value); r = x;}
/*
 * Generates stack code for a unary operation, as for a monadic operator in
 * an expression.
 */
#define UNARY(oprnd,r,op) {struct expr *ep=ealloc();\
                ep->ex_oper = op;\
                concat(r=oprnd,ep);}
/*
 * Performs binary arithmetic in a cexpr (`op' is a C operator that
 * includes an assignment, e.g. +=).
 */
#define CEXOP(x,y,r,op) {x->lx_u.lxu_value op y->lx_u.lxu_value;\
                lfree(y);\
                r = x;}
/*
 * Performs unary arithmetic in a cexpr.
 */
#define CEXFUNC(x,r,f) {x->lx_u.lxu_value = f(x->lx_u.lxu_value); r=x;}

/*
 * A hook for future upgrades in error reporting
 */
static  char    *errmess = NULL;

bool erritem;


/* Line 189 of yacc.c  */
#line 159 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     IDENT = 259,
     SEP = 260,
     ABS = 261,
     SQRT = 262,
     EXP = 263,
     LOG = 264,
     LOG10 = 265,
     SIN = 266,
     COS = 267,
     TAN = 268,
     ASIN = 269,
     ACOS = 270,
     ATAN = 271,
     SINH = 272,
     COSH = 273,
     TANH = 274,
     ASINH = 275,
     ACOSH = 276,
     ATANH = 277,
     FLOOR = 278,
     CEIL = 279,
     J0 = 280,
     J1 = 281,
     Y0 = 282,
     Y1 = 283,
     LGAMMA = 284,
     GAMMA = 285,
     ERF = 286,
     ERFC = 287,
     INVERF = 288,
     NORM = 289,
     INVNORM = 290,
     IGAMMA = 291,
     IBETA = 292,
     EVERY = 293,
     FROM = 294,
     PRINT = 295,
     STEP = 296,
     EXAM = 297,
     SYMTAB = 298,
     UMINUS = 299
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENT 259
#define SEP 260
#define ABS 261
#define SQRT 262
#define EXP 263
#define LOG 264
#define LOG10 265
#define SIN 266
#define COS 267
#define TAN 268
#define ASIN 269
#define ACOS 270
#define ATAN 271
#define SINH 272
#define COSH 273
#define TANH 274
#define ASINH 275
#define ACOSH 276
#define ATANH 277
#define FLOOR 278
#define CEIL 279
#define J0 280
#define J1 281
#define Y0 282
#define Y1 283
#define LGAMMA 284
#define GAMMA 285
#define ERF 286
#define ERFC 287
#define INVERF 288
#define NORM 289
#define INVNORM 290
#define IGAMMA 291
#define IBETA 292
#define EVERY 293
#define FROM 294
#define PRINT 295
#define STEP 296
#define EXAM 297
#define SYMTAB 298
#define UMINUS 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 85 "gram.y"

        struct  lex     *lexptr;
        struct  sym     *symptr;
        struct  expr    *exprptr;
        struct  prt     *prtptr;
        int     simple;



/* Line 214 of yacc.c  */
#line 293 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 305 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   984

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  365

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,     2,     2,    51,
      52,    53,    47,    45,    54,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    55,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    15,    18,    24,    32,
      38,    44,    52,    56,    59,    61,    62,    64,    68,    70,
      74,    77,    79,    80,    82,    84,    86,    88,    89,    92,
      93,    96,   100,   104,   108,   112,   116,   120,   125,   130,
     135,   140,   145,   150,   155,   160,   165,   170,   175,   180,
     185,   190,   195,   200,   205,   210,   215,   220,   225,   230,
     235,   240,   245,   250,   255,   260,   265,   270,   277,   286,
     289,   291,   295,   299,   303,   307,   311,   315,   320,   325,
     330,   335,   340,   345,   350,   355,   360,   365,   370,   375,
     380,   385,   390,   395,   400,   405,   410,   415,   420,   425,
     430,   435,   440,   445,   450,   455,   460,   465,   472,   481,
     484,   486,   488,   493,   494,   496
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    59,    60,    -1,     5,    -1,
       4,    44,    69,     5,    -1,     1,     5,    -1,     4,    51,
      44,    69,     5,    -1,     4,    52,    62,    53,    44,    69,
       5,    -1,    40,    63,    66,    67,     5,    -1,    41,    68,
      54,    68,     5,    -1,    41,    68,    54,    68,    54,    68,
       5,    -1,    42,     4,     5,    -1,    43,     5,    -1,     4,
      -1,    -1,    61,    -1,    62,    54,    61,    -1,    64,    -1,
      63,    54,    64,    -1,     4,    65,    -1,    69,    -1,    -1,
      51,    -1,    55,    -1,    56,    -1,    57,    -1,    -1,    38,
      68,    -1,    -1,    39,    68,    -1,    52,    68,    53,    -1,
      68,    45,    68,    -1,    68,    46,    68,    -1,    68,    47,
      68,    -1,    68,    48,    68,    -1,    68,    49,    68,    -1,
       7,    52,    68,    53,    -1,     6,    52,    68,    53,    -1,
       8,    52,    68,    53,    -1,     9,    52,    68,    53,    -1,
      10,    52,    68,    53,    -1,    11,    52,    68,    53,    -1,
      12,    52,    68,    53,    -1,    13,    52,    68,    53,    -1,
      20,    52,    68,    53,    -1,    21,    52,    68,    53,    -1,
      22,    52,    68,    53,    -1,    14,    52,    68,    53,    -1,
      15,    52,    68,    53,    -1,    16,    52,    68,    53,    -1,
      17,    52,    68,    53,    -1,    18,    52,    68,    53,    -1,
      19,    52,    68,    53,    -1,    23,    52,    68,    53,    -1,
      24,    52,    68,    53,    -1,    25,    52,    68,    53,    -1,
      26,    52,    68,    53,    -1,    27,    52,    68,    53,    -1,
      28,    52,    68,    53,    -1,    32,    52,    68,    53,    -1,
      31,    52,    68,    53,    -1,    33,    52,    68,    53,    -1,
      29,    52,    68,    53,    -1,    30,    52,    68,    53,    -1,
      34,    52,    68,    53,    -1,    35,    52,    68,    53,    -1,
      36,    52,    68,    54,    68,    53,    -1,    37,    52,    68,
      54,    68,    54,    68,    53,    -1,    46,    68,    -1,     3,
      -1,    52,    69,    53,    -1,    69,    45,    69,    -1,    69,
      46,    69,    -1,    69,    47,    69,    -1,    69,    48,    69,
      -1,    69,    49,    69,    -1,     7,    52,    69,    53,    -1,
       6,    52,    69,    53,    -1,     8,    52,    69,    53,    -1,
       9,    52,    69,    53,    -1,    10,    52,    69,    53,    -1,
      11,    52,    69,    53,    -1,    12,    52,    69,    53,    -1,
      13,    52,    69,    53,    -1,    20,    52,    69,    53,    -1,
      21,    52,    69,    53,    -1,    22,    52,    69,    53,    -1,
      14,    52,    69,    53,    -1,    15,    52,    69,    53,    -1,
      16,    52,    69,    53,    -1,    17,    52,    69,    53,    -1,
      18,    52,    69,    53,    -1,    19,    52,    69,    53,    -1,
      23,    52,    69,    53,    -1,    24,    52,    69,    53,    -1,
      25,    52,    69,    53,    -1,    26,    52,    69,    53,    -1,
      27,    52,    69,    53,    -1,    28,    52,    69,    53,    -1,
      29,    52,    69,    53,    -1,    30,    52,    69,    53,    -1,
      32,    52,    69,    53,    -1,    31,    52,    69,    53,    -1,
      33,    52,    69,    53,    -1,    34,    52,    69,    53,    -1,
      35,    52,    69,    53,    -1,    36,    52,    69,    54,    69,
      53,    -1,    37,    52,    69,    54,    69,    54,    69,    53,
      -1,    46,    69,    -1,     3,    -1,     4,    -1,     4,    52,
      70,    53,    -1,    -1,    69,    -1,    70,    54,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   114,   117,   119,   131,   143,   173,   201,
     208,   220,   240,   280,   293,   303,   304,   308,   321,   326,
     336,   349,   363,   364,   366,   371,   376,   384,   385,   394,
     395,   403,   407,   411,   415,   419,   423,   430,   434,   440,
     444,   448,   452,   456,   460,   464,   468,   472,   476,   480,
     484,   488,   492,   496,   500,   504,   508,   512,   516,   520,
     524,   528,   532,   536,   540,   544,   548,   552,   559,   567,
     571,   575,   577,   584,   591,   598,   611,   698,   705,   716,
     723,   730,   737,   744,   751,   758,   765,   772,   779,   786,
     793,   800,   807,   814,   821,   828,   835,   842,   849,   856,
     863,   870,   877,   884,   891,   898,   905,   912,   924,   937,
     944,   951,   959,   974,   975,   976
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "SEP", "ABS", "SQRT",
  "EXP", "LOG", "LOG10", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN",
  "SINH", "COSH", "TANH", "ASINH", "ACOSH", "ATANH", "FLOOR", "CEIL", "J0",
  "J1", "Y0", "Y1", "LGAMMA", "GAMMA", "ERF", "ERFC", "INVERF", "NORM",
  "INVNORM", "IGAMMA", "IBETA", "EVERY", "FROM", "PRINT", "STEP", "EXAM",
  "SYMTAB", "'='", "'+'", "'-'", "'*'", "'/'", "'^'", "UMINUS", "'\\''",
  "'('", "')'", "','", "'~'", "'!'", "'?'", "$accept", "program", "stat",
  "fargsitem", "formalargs", "prtlist", "prtitem", "prttag", "optevery",
  "optfrom", "cexpr", "expr", "fargs", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    61,    43,    45,    42,    47,    94,
     299,    39,    40,    41,    44,   126,    33,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     2,     5,     7,     5,
       5,     7,     3,     2,     1,     0,     1,     3,     1,     3,
       2,     1,     0,     1,     1,     1,     1,     0,     2,     0,
       2,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     8,     2,
       1,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     8,     2,
       1,     1,     4,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     0,     0,     0,     0,     2,
       6,     0,     0,    15,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    18,    21,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     1,     3,   111,     0,     0,    14,    16,     0,    23,
     113,    24,    25,    26,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,    12,     5,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    28,    19,     0,
       0,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     7,     0,    17,   112,     0,
      78,    77,    79,    80,    81,    82,    83,    84,    88,    89,
      90,    91,    92,    93,    85,    86,    87,    94,    95,    96,
      97,    98,    99,   100,   101,   103,   102,   104,   105,   106,
       0,     0,    30,     9,    38,    37,    39,    40,    41,    42,
      43,    44,    48,    49,    50,    51,    52,    53,    45,    46,
      47,    54,    55,    56,    57,    58,    59,    63,    64,    61,
      60,    62,    65,    66,     0,     0,    10,     0,     0,   115,
       0,     0,     0,     0,     0,     8,   107,     0,    67,     0,
      11,     0,     0,   108,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    97,    98,    50,    51,   104,   141,   230,
      88,    52,   193
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     347,     4,   -34,   -43,   174,   295,    26,    18,   338,   -43,
     -43,   221,   -16,    27,   -43,    -4,   -20,   -19,   -12,     7,
       8,    10,    22,    23,    33,    35,    36,    38,    39,    40,
      41,    74,    75,    76,    78,    84,   117,   118,   127,   165,
     166,   170,   171,   207,   214,   218,   219,   220,   221,   221,
     -35,   -43,   328,   -43,   227,   228,   230,   237,   238,   240,
     242,   243,   244,   245,   281,   284,   288,   292,   293,   298,
     306,   307,   309,   316,   317,   319,   344,   345,   353,   354,
     362,   363,   371,   372,   380,   381,   295,   295,   -41,    31,
     -43,   -43,   -43,   389,    -3,   221,   -43,   -43,   -42,   -43,
     221,   -43,   -43,   -43,   -43,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   -43,   346,   295,
     174,     2,   221,   221,   221,   221,   221,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   -43,
     355,   295,   295,   295,   295,   295,   295,   -43,   -43,    19,
       5,    27,   328,   -38,   364,   373,   382,   391,   400,   409,
     418,   427,   436,   445,   454,   463,   472,   481,   490,   499,
     508,   517,   526,   535,   544,   553,   562,   571,   580,   589,
     598,   607,   616,   625,   167,   215,   -43,   337,   -43,   295,
      56,   -27,   -27,    29,    29,    29,   634,   643,   652,   661,
     670,   679,   688,   697,   706,   715,   724,   733,   742,   751,
     760,   769,   778,   787,   796,   805,   814,   823,   832,   841,
     850,   859,   868,   877,   886,   895,   229,   239,   -43,   -22,
     -22,    37,    37,    37,     9,   -43,   221,   -43,   -43,   221,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     221,   221,   337,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   295,   295,   -43,   295,    24,   328,
     904,   308,   913,   318,    34,   -43,   -43,   221,   -43,   295,
     -43,   922,   931,   -43,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   273,   100,   -43,   -43,   258,   -43,   -43,   -43,
     -10,   -11,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -23
static const yytype_int16 yytable[] =
{
      94,   -22,   188,   139,   181,   182,   183,   184,   185,    10,
      11,   190,   191,   186,   346,   278,   279,    12,    13,   140,
     144,   145,   146,    90,   275,   183,   184,   185,    95,   355,
      89,    96,   105,   106,   -22,   -22,   187,   137,   138,   360,
     107,   229,   142,   143,   144,   145,   146,    99,   100,   276,
     -22,   101,   102,   103,   181,   182,   183,   184,   185,   108,
     109,   313,   110,   347,   142,   143,   144,   145,   146,   142,
     143,   144,   145,   146,   111,   112,   179,   180,   146,   181,
     182,   183,   184,   185,   189,   113,   185,   114,   115,   192,
     116,   117,   118,   119,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   120,   121,   122,   227,
     123,   231,   232,   233,   234,   235,   124,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   125,
     126,   269,   270,   271,   272,   273,   274,    14,    15,   127,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   142,   143,   144,   145,   146,   128,   129,   312,
      48,   310,   130,   131,    14,    93,    49,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   132,
     142,   143,   144,   145,   146,   348,   133,    48,   349,   311,
     134,   135,   136,    49,   181,   182,   183,   184,   185,   147,
     148,    92,   149,   344,   181,   182,   183,   184,   185,   150,
     151,   277,   152,   345,   153,   154,   155,   156,    53,   350,
     351,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,   157,   352,   353,   158,   354,    91,     1,
     159,    86,     2,     3,   160,   161,   361,    87,     1,   362,
     162,     2,     3,   142,   143,   144,   145,   146,   163,   164,
       0,   165,   357,   181,   182,   183,   184,   185,   166,   167,
       0,   168,   359,   142,   143,   144,   145,   146,     4,     5,
       6,     7,   181,   182,   183,   184,   185,     4,     5,     6,
       7,   142,   143,   144,   145,   146,   169,   170,   228,   226,
     181,   182,   183,   184,   185,   171,   172,     0,   268,   142,
     143,   144,   145,   146,   173,   174,     0,   280,   142,   143,
     144,   145,   146,   175,   176,     0,   281,   142,   143,   144,
     145,   146,   177,   178,     0,   282,   142,   143,   144,   145,
     146,   100,     0,     0,   283,   142,   143,   144,   145,   146,
       0,     0,     0,   284,   142,   143,   144,   145,   146,     0,
       0,     0,   285,   142,   143,   144,   145,   146,     0,     0,
       0,   286,   142,   143,   144,   145,   146,     0,     0,     0,
     287,   142,   143,   144,   145,   146,     0,     0,     0,   288,
     142,   143,   144,   145,   146,     0,     0,     0,   289,   142,
     143,   144,   145,   146,     0,     0,     0,   290,   142,   143,
     144,   145,   146,     0,     0,     0,   291,   142,   143,   144,
     145,   146,     0,     0,     0,   292,   142,   143,   144,   145,
     146,     0,     0,     0,   293,   142,   143,   144,   145,   146,
       0,     0,     0,   294,   142,   143,   144,   145,   146,     0,
       0,     0,   295,   142,   143,   144,   145,   146,     0,     0,
       0,   296,   142,   143,   144,   145,   146,     0,     0,     0,
     297,   142,   143,   144,   145,   146,     0,     0,     0,   298,
     142,   143,   144,   145,   146,     0,     0,     0,   299,   142,
     143,   144,   145,   146,     0,     0,     0,   300,   142,   143,
     144,   145,   146,     0,     0,     0,   301,   142,   143,   144,
     145,   146,     0,     0,     0,   302,   142,   143,   144,   145,
     146,     0,     0,     0,   303,   142,   143,   144,   145,   146,
       0,     0,     0,   304,   142,   143,   144,   145,   146,     0,
       0,     0,   305,   142,   143,   144,   145,   146,     0,     0,
       0,   306,   142,   143,   144,   145,   146,     0,     0,     0,
     307,   142,   143,   144,   145,   146,     0,     0,     0,   308,
     142,   143,   144,   145,   146,     0,     0,     0,   309,   181,
     182,   183,   184,   185,     0,     0,     0,   314,   181,   182,
     183,   184,   185,     0,     0,     0,   315,   181,   182,   183,
     184,   185,     0,     0,     0,   316,   181,   182,   183,   184,
     185,     0,     0,     0,   317,   181,   182,   183,   184,   185,
       0,     0,     0,   318,   181,   182,   183,   184,   185,     0,
       0,     0,   319,   181,   182,   183,   184,   185,     0,     0,
       0,   320,   181,   182,   183,   184,   185,     0,     0,     0,
     321,   181,   182,   183,   184,   185,     0,     0,     0,   322,
     181,   182,   183,   184,   185,     0,     0,     0,   323,   181,
     182,   183,   184,   185,     0,     0,     0,   324,   181,   182,
     183,   184,   185,     0,     0,     0,   325,   181,   182,   183,
     184,   185,     0,     0,     0,   326,   181,   182,   183,   184,
     185,     0,     0,     0,   327,   181,   182,   183,   184,   185,
       0,     0,     0,   328,   181,   182,   183,   184,   185,     0,
       0,     0,   329,   181,   182,   183,   184,   185,     0,     0,
       0,   330,   181,   182,   183,   184,   185,     0,     0,     0,
     331,   181,   182,   183,   184,   185,     0,     0,     0,   332,
     181,   182,   183,   184,   185,     0,     0,     0,   333,   181,
     182,   183,   184,   185,     0,     0,     0,   334,   181,   182,
     183,   184,   185,     0,     0,     0,   335,   181,   182,   183,
     184,   185,     0,     0,     0,   336,   181,   182,   183,   184,
     185,     0,     0,     0,   337,   181,   182,   183,   184,   185,
       0,     0,     0,   338,   181,   182,   183,   184,   185,     0,
       0,     0,   339,   181,   182,   183,   184,   185,     0,     0,
       0,   340,   181,   182,   183,   184,   185,     0,     0,     0,
     341,   181,   182,   183,   184,   185,     0,     0,     0,   342,
     181,   182,   183,   184,   185,     0,     0,     0,   343,   142,
     143,   144,   145,   146,     0,     0,     0,   356,   181,   182,
     183,   184,   185,     0,     0,     0,   358,   142,   143,   144,
     145,   146,     0,     0,     0,   363,   181,   182,   183,   184,
     185,     0,     0,     0,   364
};

static const yytype_int16 yycheck[] =
{
      11,     5,     5,    38,    45,    46,    47,    48,    49,     5,
      44,    53,    54,    54,     5,    53,    54,    51,    52,    54,
      47,    48,    49,     5,     5,    47,    48,    49,    44,     5,
       4,     4,    52,    52,    38,    39,     5,    48,    49,     5,
      52,    39,    45,    46,    47,    48,    49,    51,    52,    44,
      54,    55,    56,    57,    45,    46,    47,    48,    49,    52,
      52,     5,    52,    54,    45,    46,    47,    48,    49,    45,
      46,    47,    48,    49,    52,    52,    86,    87,    49,    45,
      46,    47,    48,    49,    95,    52,    49,    52,    52,   100,
      52,    52,    52,    52,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    52,    52,    52,   139,
      52,   142,   143,   144,   145,   146,    52,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    52,
      52,   181,   182,   183,   184,   185,   186,     3,     4,    52,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    45,    46,    47,    48,    49,    52,    52,   229,
      46,    54,    52,    52,     3,     4,    52,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    52,
      45,    46,    47,    48,    49,   276,    52,    46,   279,    54,
      52,    52,    52,    52,    45,    46,    47,    48,    49,    52,
      52,     8,    52,    54,    45,    46,    47,    48,    49,    52,
      52,   191,    52,    54,    52,    52,    52,    52,     3,   310,
     311,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    52,   344,   345,    52,   347,     0,     1,
      52,    46,     4,     5,    52,    52,   357,    52,     1,   359,
      52,     4,     5,    45,    46,    47,    48,    49,    52,    52,
      -1,    52,    54,    45,    46,    47,    48,    49,    52,    52,
      -1,    52,    54,    45,    46,    47,    48,    49,    40,    41,
      42,    43,    45,    46,    47,    48,    49,    40,    41,    42,
      43,    45,    46,    47,    48,    49,    52,    52,   140,    53,
      45,    46,    47,    48,    49,    52,    52,    -1,    53,    45,
      46,    47,    48,    49,    52,    52,    -1,    53,    45,    46,
      47,    48,    49,    52,    52,    -1,    53,    45,    46,    47,
      48,    49,    52,    52,    -1,    53,    45,    46,    47,    48,
      49,    52,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,    40,    41,    42,    43,    59,    60,
       5,    44,    51,    52,     3,     4,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    46,    52,
      63,    64,    69,     3,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    46,    52,    68,     4,
       5,     0,    60,     4,    69,    44,     4,    61,    62,    51,
      52,    55,    56,    57,    65,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    69,    69,    38,
      54,    66,    45,    46,    47,    48,    49,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    68,
      68,    45,    46,    47,    48,    49,    54,     5,     5,    69,
      53,    54,    69,    70,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    53,    68,    64,    39,
      67,    69,    69,    69,    69,    69,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    53,    68,
      68,    68,    68,    68,    68,     5,    44,    61,    53,    54,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    68,     5,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,     5,    54,    69,    69,
      69,    69,    68,    68,    68,     5,    53,    54,    53,    54,
       5,    69,    68,    53,    53
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 118 "gram.y"
    { lfree((yyvsp[(1) - (1)].lexptr)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 120 "gram.y"
    {
			  struct sym *sp;
			  
			  sp = lookup((yyvsp[(1) - (4)].lexptr)->lx_u.lxu_name);
			  sp->sy_value = eval((yyvsp[(3) - (4)].exprptr));
			  sp->sy_flags |= SF_INIT;

			  lfree((yyvsp[(1) - (4)].lexptr));
			  efree((yyvsp[(3) - (4)].exprptr));
			  lfree((yyvsp[(4) - (4)].lexptr));
                        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 132 "gram.y"
    {
			  if (errmess == NULL)
			    errmess = "syntax error";
			  fprintf (stderr, "%s:%s:%d: %s\n", 
				   progname, filename,
				   ((yyvsp[(2) - (2)].lexptr)->lx_lino), errmess);
			  errmess = NULL;
			  lfree((yyvsp[(2) - (2)].lexptr));
			  yyerrok;
			  yyclearin;
                        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 144 "gram.y"
    {
			  struct sym *sp;
			  struct prt *pp, *qp;
			  
			  sp = lookup((yyvsp[(1) - (5)].lexptr)->lx_u.lxu_name);
			  efree(sp->sy_expr);
			  sp->sy_expr = (yyvsp[(4) - (5)].exprptr);
			  sp->sy_flags |= SF_ISEQN;
			  if (!sawprint) 
			    {
			      for (pp=pqueue; pp!=NULL; pp=pp->pr_link)
				if (pp->pr_sym == sp)
				  goto found;
			      pp = palloc();
			      pp->pr_sym = sp;
			      if (pqueue == NULL)
				pqueue = pp;
			      else 
				{
				  for (qp=pqueue; qp->pr_link!=NULL; )
				    qp = qp->pr_link;
				  qp->pr_link = pp;
                                }
			    }
			found:
			  lfree((yyvsp[(1) - (5)].lexptr));
			  lfree((yyvsp[(5) - (5)].lexptr));
                        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 174 "gram.y"
    {
			  struct sym *sp;
			  sp = lookup((yyvsp[(1) - (7)].lexptr)->lx_u.lxu_name);
			  // delete previously defined function:
			  //  1. free arglist, because it is not in symtab and will be lost otherwise.
			  //  2. free function body.
			  if(sp->sy_flags & SF_ISFUNC)
				{
					sqfree(sp->sy_expr->ex_sym);
					efree(sp->sy_expr);
				}
			  struct expr *e1=ealloc(), *e2=ealloc();

			  e1->ex_sym  = (yyvsp[(3) - (7)].symptr);
			  e1->ex_oper = O_STARTFUN;
			  e2->ex_oper = O_ENDFUN;


			  concat(e1, (yyvsp[(6) - (7)].exprptr));
			  concat((yyvsp[(6) - (7)].exprptr), e2);
			  
			  sp->sy_flags = SF_ISFUNC;
			  sp->sy_expr  = e1;

			  lfree((yyvsp[(1) - (7)].lexptr));
			  lfree((yyvsp[(7) - (7)].lexptr));
			}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 202 "gram.y"
    {
			  sawprint = true;
			  prerr = erritem;
			  erritem = false;
			  lfree((yyvsp[(5) - (5)].lexptr));
                        }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 209 "gram.y"
    {
			  lfree((yyvsp[(5) - (5)].lexptr));
			  tstart = (yyvsp[(2) - (5)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(2) - (5)].lexptr));
			  tstop = (yyvsp[(4) - (5)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(4) - (5)].lexptr));
			  if (!conflag)
			    startstep();
			  solve();
			  sawstep = true;
                        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 221 "gram.y"
    {
			  double savstep;
			  bool savconflag;
			  
			  lfree((yyvsp[(7) - (7)].lexptr));
			  tstart = (yyvsp[(2) - (7)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(2) - (7)].lexptr));
			  tstop = (yyvsp[(4) - (7)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(4) - (7)].lexptr));
			  savstep = tstep;
			  tstep = (yyvsp[(6) - (7)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(6) - (7)].lexptr));
			  savconflag = conflag;
			  conflag = true;
			  solve();
			  tstep = savstep;
			  conflag = savconflag;
			  sawstep = true;
                        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 241 "gram.y"
    {
			  struct sym *sp;
			  lfree((yyvsp[(3) - (3)].lexptr));
			  sp = lookup((yyvsp[(2) - (3)].lexptr)->lx_u.lxu_name);
			  lfree((yyvsp[(2) - (3)].lexptr));
			  printf ("\"%.*s\" is ",NAMMAX,sp->sy_name);
			  switch (sp->sy_flags & (SF_DEPV|SF_ISFUNC))
			    {
			    case SF_ISFUNC:
			      printf ("a function\n");
			      break;
			    case SF_DEPV:
			    case SF_ISEQN:
			      printf ("a dynamic variable\n");
			      break;
			    case SF_INIT:
			      printf ("an initialized constant\n");
			      break;
			    case 0:
			      printf ("an uninitialized constant\n");
			      break;
			    default:
			      panicn ("impossible (%d) in EXAM action",
				      sp->sy_flags);
			    }
			  printf ("value:");
			  prval (sp->sy_value);
			  printf ("\nprime:");
			  prval (sp->sy_prime);
			  printf ("\nsserr:");
			  prval (sp->sy_sserr);
			  printf ("\naberr:");
			  prval (sp->sy_aberr);
			  printf ("\nacerr:");
			  prval (sp->sy_acerr);
			  putchar ('\n');
			  prexq(sp->sy_expr);
			  fflush(stdout);
                        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 281 "gram.y"
    {
			  // XODE: For debugging
			  struct sym* sp;
			  printf("addr\t\tname\tvalue\t\tflags\n");
			  for(sp = symtab; sp; sp=sp->sy_link)
				printf("(%p)\t%s\t%-9.6g\t%d\n",
					sp, sp->sy_name, sp->sy_value, sp->sy_flags);
			  
			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 294 "gram.y"
    {
			  struct sym *sp;
			  sp = calloc(1, sizeof(struct sym));
			  strncpy( sp->sy_name, (yyvsp[(1) - (1)].lexptr)->lx_u.lxu_name, NAMMAX);
			  sp->sy_flags = SF_ISFARG;
			  lfree((yyvsp[(1) - (1)].lexptr));
			  (yyval.symptr) = sp;
		}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 303 "gram.y"
    { (yyval.symptr) = NULL; }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 305 "gram.y"
    {
				(yyval.symptr) = (yyvsp[(1) - (1)].symptr);
			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 309 "gram.y"
    {
			  struct sym *sp;
			  
			  for (sp=(yyvsp[(1) - (3)].symptr); sp->sy_link!=NULL; sp=sp->sy_link)
			    if( strncmp(sp->sy_name, (yyvsp[(3) - (3)].symptr)->sy_name, NAMMAX) == 0 ) // f(x,y,x) -- BAD
				panic("duplicate formal argument");
			  if( strncmp(sp->sy_name, (yyvsp[(3) - (3)].symptr)->sy_name, NAMMAX) == 0 )
			    panic("duplicate formal argument");

			  sp->sy_link = (yyvsp[(3) - (3)].symptr);
			}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 322 "gram.y"
    {
			  pfree(pqueue);
			  pqueue = (yyvsp[(1) - (1)].prtptr);
                        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 327 "gram.y"
    {
			  struct prt *pp;
			  
			  for (pp=pqueue; pp->pr_link!=NULL; pp=pp->pr_link)
			    ;
			  pp->pr_link = (yyvsp[(3) - (3)].prtptr);
                        }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 337 "gram.y"
    {
			  struct prt *pp;
			  
			  pp = palloc();
			  pp->pr_sym = lookup((yyvsp[(1) - (2)].lexptr)->lx_u.lxu_name);
			  pp->pr_which = (ent_cell)((yyvsp[(2) - (2)].simple));
			  lfree((yyvsp[(1) - (2)].lexptr));
			  (yyval.prtptr) = pp;
                        }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 350 "gram.y"
    {
			  struct prt *pp;
			  struct sym *sp = (struct sym*) xmalloc(sizeof(struct sym));
			  
			  sp->sy_expr = (yyvsp[(1) - (1)].exprptr);
			  pp = palloc();
			  pp->pr_sym = sp;
			  pp->pr_which = P_EXPR;
			  (yyval.prtptr) = pp;
			}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 363 "gram.y"
    { (yyval.simple) = P_VALUE; }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 365 "gram.y"
    { (yyval.simple) = P_PRIME; }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 367 "gram.y"
    {
			  (yyval.simple) = P_ACERR;
			  erritem = true;
                        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 372 "gram.y"
    {
			  (yyval.simple) = P_ABERR;
			  erritem = true;
                        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 377 "gram.y"
    {
			  (yyval.simple) = P_SSERR;
			  erritem = true;
                        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 384 "gram.y"
    { sawevery = false; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 386 "gram.y"
    {
                        sawevery = true;
                        tevery = IROUND((yyvsp[(2) - (2)].lexptr)->lx_u.lxu_value);
                        lfree((yyvsp[(2) - (2)].lexptr));
                        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 394 "gram.y"
    { sawfrom = false; }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 396 "gram.y"
    {
			  sawfrom = true;
			  tfrom = (yyvsp[(2) - (2)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(2) - (2)].lexptr));
                        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 404 "gram.y"
    {
			  (yyval.lexptr) = (yyvsp[(2) - (3)].lexptr);
                        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 408 "gram.y"
    {
			  CEXOP((yyvsp[(1) - (3)].lexptr),(yyvsp[(3) - (3)].lexptr),(yyval.lexptr),+=)
                        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 412 "gram.y"
    {
			  CEXOP((yyvsp[(1) - (3)].lexptr),(yyvsp[(3) - (3)].lexptr),(yyval.lexptr),-=)
                        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 416 "gram.y"
    {
			  CEXOP((yyvsp[(1) - (3)].lexptr),(yyvsp[(3) - (3)].lexptr),(yyval.lexptr),*=)
                        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 420 "gram.y"
    {
			  CEXOP((yyvsp[(1) - (3)].lexptr),(yyvsp[(3) - (3)].lexptr),(yyval.lexptr),/=)
                        }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 424 "gram.y"
    {
			  (yyvsp[(1) - (3)].lexptr)->lx_u.lxu_value =
			    pow((yyvsp[(1) - (3)].lexptr)->lx_u.lxu_value,(yyvsp[(3) - (3)].lexptr)->lx_u.lxu_value);
			  lfree((yyvsp[(3) - (3)].lexptr));
			  (yyval.lexptr) = (yyvsp[(1) - (3)].lexptr);
                        }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 431 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),sqrt)
                        }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 435 "gram.y"
    {
			  if ((yyvsp[(3) - (4)].lexptr)->lx_u.lxu_value < 0)
			    (yyvsp[(3) - (4)].lexptr)->lx_u.lxu_value = -((yyvsp[(3) - (4)].lexptr)->lx_u.lxu_value);
			  (yyval.lexptr) = (yyvsp[(3) - (4)].lexptr);
                        }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 441 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),exp)
                        }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 445 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),log)
                        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 449 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),log10)
                        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 453 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),sin)
                        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 457 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),cos)
                        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 461 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),tan)
                        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 465 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),asinh)
                        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 469 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),acosh)
                        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 473 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),atanh)
                        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 477 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),asin)
                        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 481 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),acos)
                        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 485 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),atan)
                        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 489 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),sinh)
                        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 493 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),cosh)
                        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 497 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),tanh)
                        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 501 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),floor)
                        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 505 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),ceil)
                        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 509 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),j0)
                        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 513 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),j1)
                        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 517 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),y0)
                        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 521 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),y1)
                        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 525 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),erfc)
                        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 529 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),erf)
                        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 533 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),inverf)
                        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 537 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),F_LGAMMA)
                        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 541 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),f_gamma)
                        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 545 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),norm)
                        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 549 "gram.y"
    {
			  CEXFUNC((yyvsp[(3) - (4)].lexptr),(yyval.lexptr),invnorm)
                        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 553 "gram.y"
    {
			  (yyvsp[(3) - (6)].lexptr)->lx_u.lxu_value =
			    igamma((yyvsp[(3) - (6)].lexptr)->lx_u.lxu_value,(yyvsp[(5) - (6)].lexptr)->lx_u.lxu_value);
			  lfree((yyvsp[(5) - (6)].lexptr));
			  (yyval.lexptr) = (yyvsp[(3) - (6)].lexptr);
                        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 560 "gram.y"
    {
			  (yyvsp[(3) - (8)].lexptr)->lx_u.lxu_value =
			    ibeta((yyvsp[(3) - (8)].lexptr)->lx_u.lxu_value,(yyvsp[(5) - (8)].lexptr)->lx_u.lxu_value,(yyvsp[(7) - (8)].lexptr)->lx_u.lxu_value);
			  lfree((yyvsp[(5) - (8)].lexptr));
			  lfree((yyvsp[(7) - (8)].lexptr));
			  (yyval.lexptr) = (yyvsp[(3) - (8)].lexptr);
                        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 568 "gram.y"
    {
			  CEXFUNC((yyvsp[(2) - (2)].lexptr),(yyval.lexptr),-)
                        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 572 "gram.y"
    { (yyval.lexptr) = (yyvsp[(1) - (1)].lexptr); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 576 "gram.y"
    { (yyval.exprptr) = (yyvsp[(2) - (3)].exprptr); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 578 "gram.y"
    {
			  if (TWOCON((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr)))
			    COMBINE((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),+=)
			  else
			    BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_PLUS);
                        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 585 "gram.y"
    {
			  if (TWOCON((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr)))
			    COMBINE((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),-=)
			  else
			    BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_MINUS);
                        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 592 "gram.y"
    {
			  if (TWOCON((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr)))
			    COMBINE((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),*=)
			  else
			    BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_MULT);
                        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 599 "gram.y"
    {
			  if (TWOCON((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr)))
			    COMBINE((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),/=)
			  else if (ONECON((yyvsp[(3) - (3)].exprptr)) && (yyvsp[(3) - (3)].exprptr)->ex_value!=0.) 
			    {
			      /* division by constant */
			      (yyvsp[(3) - (3)].exprptr)->ex_value = 1./(yyvsp[(3) - (3)].exprptr)->ex_value;
			      BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_MULT);
			    } 
			  else
			    BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_DIV);
                        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 612 "gram.y"
    {
			  double f;
			  bool invert = false;
			  
			  if (TWOCON((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr))) 
			    {
			      /* case const ^ const */
			      (yyvsp[(1) - (3)].exprptr)->ex_value = pow((yyvsp[(1) - (3)].exprptr)->ex_value,(yyvsp[(3) - (3)].exprptr)->ex_value);
			      efree((yyvsp[(3) - (3)].exprptr));
			    } 
			  else if (ONECON((yyvsp[(1) - (3)].exprptr))) 
			    {
			      if ((yyvsp[(1) - (3)].exprptr)->ex_value == 1.)
				{
				  /* case 1 ^ x */
				  efree((yyvsp[(3) - (3)].exprptr));
				  (yyval.exprptr) = (yyvsp[(1) - (3)].exprptr);
                                }
			      else
				goto other;
			    }
			  else if (!ONECON((yyvsp[(3) - (3)].exprptr)))
			    goto other;
			  else 
			    {
			      f = (yyvsp[(3) - (3)].exprptr)->ex_value;
			      if (f < 0.) 
				{
				  /*
				   * negative exponent means
				   * to append an invert cmd
				   */
				  f = -f;
				  invert = true;
                                }
			      if (f == 2.) 
				{
				  /* case x ^ 2 */
				  (yyvsp[(3) - (3)].exprptr)->ex_oper = O_SQAR;
				  concat((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr));
				  (yyval.exprptr) = (yyvsp[(1) - (3)].exprptr);
                                }
			      else if (f == 3.) 
				{
				  /* case x ^ 3 */
				  (yyvsp[(3) - (3)].exprptr)->ex_oper = O_CUBE;
				  concat((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr));
				  (yyval.exprptr) = (yyvsp[(1) - (3)].exprptr);
                                }
			      else if (f == 0.5) 
				{
				  /* case x ^ .5 */
				  (yyvsp[(3) - (3)].exprptr)->ex_oper = O_SQRT;
				  concat((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr));
				  (yyval.exprptr) = (yyvsp[(1) - (3)].exprptr);
                                }
			      else if (f == 1.5) 
				{
				  /* case x ^ 1.5 */
				  (yyvsp[(3) - (3)].exprptr)->ex_oper = O_CUBE;
				  BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_SQRT);
                                }
			      else if (f == 1.) 
				{
				  /* case x ^ 1 */
				  efree((yyvsp[(3) - (3)].exprptr));
				  (yyval.exprptr) = (yyvsp[(1) - (3)].exprptr);
                                }
			      else if (f == 0.) 
				{
				  /* case x ^ 0 */
				  efree((yyvsp[(1) - (3)].exprptr));
				  (yyvsp[(3) - (3)].exprptr)->ex_value = 1.;
				  (yyval.exprptr) = (yyvsp[(3) - (3)].exprptr);
                                } 
			      else 
				{
				other:
				  /* default */
				  invert = false;
				  BINARY((yyvsp[(1) - (3)].exprptr),(yyvsp[(3) - (3)].exprptr),(yyval.exprptr),O_POWER);
                                }
			      if (invert)
				UNARY((yyval.exprptr),(yyval.exprptr),O_INV)
			    }
                        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 699 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),sqrt)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_SQRT);
                        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 706 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr))) 
			    {
			      if ((yyvsp[(3) - (4)].exprptr)->ex_value < 0)
				(yyvsp[(3) - (4)].exprptr)->ex_value = -((yyvsp[(3) - (4)].exprptr)->ex_value);
			      (yyval.exprptr) = (yyvsp[(3) - (4)].exprptr);
			  } 
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ABS);
                        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 717 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),exp)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_EXP);
                        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 724 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),log)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_LOG);
                        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 731 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),log10)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_LOG10);
                        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 738 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),sin)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_SIN);
                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 745 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),cos)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_COS);
                        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 752 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),tan)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_TAN);
                        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 759 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),asinh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ASINH);
                        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 766 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),acosh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ACOSH);
                        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 773 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),atanh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ATANH);
                        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 780 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),asin)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ASIN);
                        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 787 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),acos)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ACOS);
                        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 794 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),atan)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ATAN);
                        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 801 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),sinh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_SINH);
                        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 808 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),cosh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_COSH);
                        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 815 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),tanh)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_TANH);
                        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 822 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),floor)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_FLOOR);
                        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 829 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),ceil)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_CEIL);
                        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 836 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),j0)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_J0);
                        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 843 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),j1)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_J1);
                        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 850 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),y0)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_Y0);
                        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 857 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),y1)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_Y1);
                        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 864 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),F_LGAMMA)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_LGAMMA);
                        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 871 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),f_gamma)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_GAMMA);
                        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 878 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),erfc)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ERFC);
                        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 885 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),erf)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_ERF);
                        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 892 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),inverf)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_INVERF);
                        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 899 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),norm)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_NORM);
                        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 906 "gram.y"
    {
			  if (ONECON((yyvsp[(3) - (4)].exprptr)))
			    CONFUNC((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),invnorm)
			  else
			    UNARY((yyvsp[(3) - (4)].exprptr),(yyval.exprptr),O_INVNORM);
                        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 913 "gram.y"
    {
			  if (TWOCON((yyvsp[(3) - (6)].exprptr),(yyvsp[(5) - (6)].exprptr))) 
			    {
			      (yyvsp[(3) - (6)].exprptr)->ex_value = 
				igamma((yyvsp[(3) - (6)].exprptr)->ex_value,(yyvsp[(5) - (6)].exprptr)->ex_value);
			      efree((yyvsp[(5) - (6)].exprptr));
			      (yyval.exprptr) = (yyvsp[(3) - (6)].exprptr);
			    }
			  else 
			    BINARY((yyvsp[(3) - (6)].exprptr),(yyvsp[(5) - (6)].exprptr),(yyval.exprptr),O_IGAMMA);
		        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 925 "gram.y"
    {
			  if (THREECON((yyvsp[(3) - (8)].exprptr),(yyvsp[(5) - (8)].exprptr),(yyvsp[(7) - (8)].exprptr))) 
			    {
			      (yyvsp[(3) - (8)].exprptr)->ex_value = 
				ibeta((yyvsp[(3) - (8)].exprptr)->ex_value,(yyvsp[(5) - (8)].exprptr)->ex_value,(yyvsp[(7) - (8)].exprptr)->ex_value);
			      efree((yyvsp[(5) - (8)].exprptr));
			      efree((yyvsp[(7) - (8)].exprptr));
			      (yyval.exprptr) = (yyvsp[(3) - (8)].exprptr);
			    }
			  else 
			    TERNARY((yyvsp[(3) - (8)].exprptr),(yyvsp[(5) - (8)].exprptr),(yyvsp[(7) - (8)].exprptr),(yyval.exprptr),O_IBETA);
		        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 938 "gram.y"
    {
			  if (ONECON((yyvsp[(2) - (2)].exprptr)))
			    CONFUNC((yyvsp[(2) - (2)].exprptr),(yyval.exprptr),-)
			  else
			    UNARY((yyvsp[(2) - (2)].exprptr),(yyval.exprptr),O_NEG);
                        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 945 "gram.y"
    {
			  (yyval.exprptr) = ealloc();
			  (yyval.exprptr)->ex_oper = O_CONST;
			  (yyval.exprptr)->ex_value = (yyvsp[(1) - (1)].lexptr)->lx_u.lxu_value;
			  lfree((yyvsp[(1) - (1)].lexptr));
                        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 952 "gram.y"
    {
			  (yyval.exprptr) = ealloc();
			  (yyval.exprptr)->ex_oper = O_IDENT;
			  (yyval.exprptr)->ex_sym = lookup((yyvsp[(1) - (1)].lexptr)->lx_u.lxu_name);
			  lfree((yyvsp[(1) - (1)].lexptr));
                        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 960 "gram.y"
    {
			  struct sym *sp;
			  struct expr *call;
			  sp = lookup((yyvsp[(1) - (4)].lexptr)->lx_u.lxu_name);
			  call = ealloc();
			  call->ex_oper = O_CALL; 
			  call->ex_sym  = sp;
			  if ((yyvsp[(3) - (4)].exprptr) != NULL )
				concat((yyval.exprptr)=(yyvsp[(3) - (4)].exprptr), call);
			  else (yyval.exprptr) = call;
			  lfree((yyvsp[(1) - (4)].lexptr));
                        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 974 "gram.y"
    { (yyval.exprptr)=NULL; }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 975 "gram.y"
    { (yyval.exprptr) = (yyvsp[(1) - (1)].exprptr); }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 976 "gram.y"
    { (yyval.exprptr) = (yyvsp[(3) - (3)].exprptr); concat((yyval.exprptr), (yyvsp[(1) - (3)].exprptr)); }
    break;



/* Line 1455 of yacc.c  */
#line 3297 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 977 "gram.y"


int
yyerror (const char *s)
{
  return 0;
}

/*
 * tack two queues of stack code together
 * e1 is connected on the tail of e0
 * There is no good way to test for circular
 * lists, hence the silly count.
 */
void
concat (struct expr *e0, struct expr *e1)
{
  int count;
  
  if (e0 == NULL || e1 == NULL) 
    panic ("NULL expression queue");

  for (count = 0; e0->ex_next != NULL; e0 = e0->ex_next)
    if (++count > 10000) 
      panic ("circular expression queue");

  e0->ex_next = e1;
}

/*
 * print an expression queue
 * called when EXAMINE is invoked on a variable (see above)
 */
void
prexq (const struct expr *ep)
{
  const char *s;
  struct sym *var;
  
  printf (" code:");
  if (ep == NULL)
    putchar ('\n');

  for (; ep != NULL; ep = ep->ex_next) 
    {
      switch (ep->ex_oper) 
	{
	case O_PLUS: s = "add"; break;
	case O_MINUS: s = "subtract"; break;
	case O_MULT: s = "multiply"; break;
	case O_DIV: s = "divide"; break;
	case O_POWER: s = "power"; break;
	case O_SQRT: s = "sqrt"; break;
	case O_EXP: s = "exp"; break;
	case O_LOG: s = "log"; break;
	case O_LOG10: s = "log10"; break;
	case O_SIN: s = "sin"; break;
	case O_COS: s = "cos"; break;
	case O_TAN: s = "cos"; break;
	case O_ASIN: s = "sin"; break;
	case O_ACOS: s = "cos"; break;
	case O_ATAN: s = "cos"; break;
	case O_NEG: s = "negate"; break;
	case O_ABS: s = "abs"; break;
	case O_SINH: s = "sinh"; break;
	case O_COSH: s = "cosh"; break;
	case O_TANH: s = "tanh"; break;
	case O_ASINH: s = "asinh"; break;
	case O_ACOSH: s = "acosh"; break;
	case O_ATANH: s = "atanh"; break;
	case O_SQAR: s = "square"; break;
	case O_CUBE: s = "cube"; break;
	case O_INV: s = "invert"; break;
	case O_FLOOR: s = "floor"; break;
	case O_CEIL: s = "ceil"; break;
	case O_J0: s = "besj0"; break;
	case O_J1: s = "besj1"; break;
	case O_Y0: s = "besy0"; break;
	case O_Y1: s = "besy1"; break;
	case O_ERF: s = "erf"; break;
	case O_ERFC: s = "erfc"; break;
	case O_INVERF: s = "inverf"; break;
	case O_LGAMMA: s = "lgamma"; break;
	case O_GAMMA: s = "gamma"; break;
	case O_NORM: s = "norm"; break;
	case O_INVNORM: s = "invnorm"; break;
	case O_IGAMMA: s = "igamma"; break;
	case O_IBETA: s = "ibeta"; break;
	case O_CONST:
	  printf ("\tpush ");
	  prval (ep->ex_value);
	  putchar ('\n');
	  s = NULL;
	  break;
	case O_IDENT:
	  printf ("\tpush \"%.*s\"\n",
		 NAMMAX, ep->ex_sym->sy_name);
	  s = NULL;
	  break;
	case O_ENDFUN: s = "restore symtab\n\trestore return\n\tjump"; break;
	case O_STARTFUN:
	  printf ("\tsave symtab\n");
	  for(var = ep->ex_sym; var; var=var->sy_link)
		{
		  printf ("\tpop \"%s\"\n", var->sy_name);
		}
	  s = NULL;
	  break;
	case O_CALL:
	  printf ("\tcall %s\n", ep->ex_sym->sy_name);
	  s = NULL;
	  break;
	default: s = "unknown!";
	}

      if (s != NULL)
	printf ("\t%s\n",s);
    }
}

