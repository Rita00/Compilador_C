/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y" /* yacc.c:339  */

    #include <stdio.h>
    #include "ast.h"
    int yylex(void);
    void yyerror (char *s);
    char error = 0;
    AST_Node root;
    extern char flag;

#line 76 "uccompiler.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BITWISEAND = 258,
    BITWISEOR = 259,
    BITWISEXOR = 260,
    AND = 261,
    ASSIGN = 262,
    COMMA = 263,
    DIV = 264,
    EQ = 265,
    GE = 266,
    GT = 267,
    LBRACE = 268,
    LE = 269,
    LPAR = 270,
    LT = 271,
    MINUS = 272,
    MOD = 273,
    NE = 274,
    NOT = 275,
    OR = 276,
    PLUS = 277,
    RBRACE = 278,
    RPAR = 279,
    SEMI = 280,
    CHAR = 281,
    ELSE = 282,
    WHILE = 283,
    IF = 284,
    INT = 285,
    SHORT = 286,
    DOUBLE = 287,
    RETURN = 288,
    VOID = 289,
    REALLIT = 290,
    INTLIT = 291,
    RESERVED = 292,
    ID = 293,
    CHRLIT = 294,
    MUL = 295,
    NO_ELSE = 296,
    MAX_PREC = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "uccompiler.y" /* yacc.c:355  */

    struct _ast_Node *node;
    char *letters;

#line 161 "uccompiler.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 178 "uccompiler.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   849

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    62,    63,    64,    65,    66,    67,    70,
      73,    74,    77,    78,    79,    80,    83,    86,    89,    92,
      93,    94,    97,    98,   101,   102,   103,   104,   105,   108,
     109,   110,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   125,   126,   130,   131,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BITWISEAND", "BITWISEOR", "BITWISEXOR",
  "AND", "ASSIGN", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE",
  "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE",
  "RPAR", "SEMI", "CHAR", "ELSE", "WHILE", "IF", "INT", "SHORT", "DOUBLE",
  "RETURN", "VOID", "REALLIT", "INTLIT", "RESERVED", "ID", "CHRLIT", "MUL",
  "NO_ELSE", "MAX_PREC", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration", "Declaration", "TypeSpec", "Declarator",
  "Statement", "ErrorOrStatement", "Statlist", "Expr", "ExprOnCall", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     726,   -11,   -85,   -85,   -85,   -85,   -85,     8,   710,   -85,
     -85,   -85,   -20,   -85,   -85,   -85,   -85,   -85,    17,    -6,
      -5,   715,    -9,    95,   -85,   -85,    -8,   -85,   281,   715,
     715,   715,   -85,   -85,    12,   -85,   526,     7,    25,    -4,
     167,   -85,   -85,    20,    43,   804,   131,   -85,    -8,   -85,
     326,    52,   -85,    37,   351,   -85,   -85,   -85,   250,   715,
     715,   715,   715,   715,   715,   715,   715,   715,   715,   715,
     715,   715,   715,   715,   715,   715,   715,   -85,    -9,   -85,
     -10,   -85,   -85,   -85,   196,   715,   715,   -85,   376,   -85,
     -85,   -85,   -85,   -85,   -85,    38,   289,   810,   810,   810,
     -85,   -85,   -85,    48,   -85,   401,   752,   646,   686,   606,
     526,   526,   -85,   782,   190,   190,   190,   190,    96,   -85,
     782,   566,    96,   -85,   -85,   -85,   -85,    39,   -85,   -85,
     426,   451,   -85,   -85,    41,   476,   -85,   -85,   -85,   256,
     810,   810,   810,   810,   810,   810,   810,   810,   810,   810,
     810,   810,   810,   810,   810,   810,   810,   -85,   810,   225,
     225,   -85,   -85,    44,   -85,   501,   766,   666,   706,   626,
     546,   546,   -85,   796,   219,   219,   219,   219,    98,   -85,
     796,   586,    98,   -85,   -85,    42,   -85,   -85,   225,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    24,    25,    27,    28,    26,     0,     0,     3,
       4,     5,     0,    23,     1,     6,     7,     8,    30,     0,
       0,     0,     0,     0,    16,     9,     0,    22,     0,     0,
       0,     0,    72,    70,    69,    71,    31,     0,    18,    21,
       0,    11,    33,     0,     0,     0,     0,    15,     0,    14,
       0,    30,    29,     0,     0,    65,    66,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,    20,
       0,    35,    42,    45,     0,     0,     0,    40,     0,    10,
      13,    12,    32,    75,    73,     0,     0,     0,     0,     0,
      67,   102,   100,    99,   101,     0,    55,    56,    57,    54,
      46,    47,    51,    58,    61,    63,    60,    62,    49,    52,
      59,    53,    48,    50,    19,    41,    43,     0,    34,    44,
       0,     0,    39,    74,     0,     0,    95,    96,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,   105,   103,     0,    97,     0,    85,    86,    87,    84,
      76,    77,    81,    88,    91,    93,    90,    92,    79,    82,
      89,    83,    78,    80,    38,    36,   104,    98,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,    62,   -85,   -85,    63,   -85,   -85,    21,
      -7,   -18,    46,   -17,   -84,   -85,   -19,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    46,    10,    19,    37,    38,
      11,    12,    20,    82,    83,    84,    50,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     129,    17,    36,    26,    39,    48,    49,    23,    14,    54,
      55,    56,    57,   125,    13,   126,    47,     2,    18,    24,
      27,     3,     4,     5,    21,     6,    88,    58,    48,    91,
      51,    77,    22,    78,    79,    85,   136,   137,   138,    90,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    86,    21,
      39,    93,   133,   139,   126,   161,   130,   131,   186,   188,
      15,    16,    52,     0,     0,   184,   185,   135,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     1,   183,     0,   124,
       0,     0,     0,     0,   189,    65,     0,   146,    40,     0,
      28,     0,    29,     0,    72,    30,   153,    31,    41,     0,
      42,     2,     0,    43,    44,     3,     4,     5,    45,     6,
      32,    33,     1,    34,    35,     0,    76,     0,   158,     0,
       0,     0,     0,     0,    40,     0,    28,     0,    29,     0,
       0,    30,     0,    31,    89,     0,    42,     2,     0,    43,
      44,     3,     4,     5,    45,     6,    32,    33,    80,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,    28,     0,    29,     0,     0,    30,     0,    31,
      81,     0,    42,     0,     0,    43,    44,   127,     0,    65,
      45,     0,    32,    33,     0,    34,    35,    71,    72,    40,
       0,    28,    75,    29,     0,     0,    30,     0,    31,   128,
       0,    42,     0,     0,    43,    44,   127,     0,   146,    45,
      76,    32,    33,     0,    34,    35,   152,   153,    40,     0,
      28,   156,    29,     0,     0,    30,     0,    31,     0,     0,
      42,    95,     0,    43,    44,     0,     0,   163,    45,   158,
      32,    33,     0,    34,    35,    96,     0,    97,     0,     0,
      98,    96,    99,    97,   100,     0,    98,     0,    99,     0,
     164,     0,    53,     0,     0,   101,   102,     0,   103,   104,
     134,   101,   102,     0,   103,   104,    28,     0,    29,     0,
       0,    30,     0,    31,    28,     0,    29,     0,     0,    30,
       0,    31,     0,     0,     0,     0,    32,    33,     0,    34,
      35,     0,     0,     0,    32,    33,     0,    34,    35,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,     0,    70,    71,    72,    73,     0,    74,    75,     0,
       0,    92,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    76,    70,    71,    72,
      73,     0,    74,    75,     0,    94,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    76,    70,    71,    72,    73,     0,    74,    75,     0,
       0,   132,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,    76,   151,   152,   153,
     154,     0,   155,   156,     0,   157,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,   158,    70,    71,    72,    73,     0,    74,    75,     0,
     159,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    76,    70,    71,    72,
      73,     0,    74,    75,     0,   160,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    76,    70,    71,    72,    73,     0,    74,    75,     0,
     162,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,    76,   151,   152,   153,
     154,     0,   155,   156,     0,   187,     0,     0,     0,    59,
      60,    61,    62,    63,     0,    65,    66,    67,    68,     0,
      69,   158,    70,    71,    72,    73,     0,    74,    75,   140,
     141,   142,   143,   144,     0,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,    76,   155,   156,    59,
      60,    61,    62,     0,     0,    65,    66,    67,    68,     0,
      69,     0,    70,    71,    72,    73,   158,     0,    75,   140,
     141,   142,   143,     0,     0,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,    76,     0,   156,    59,
      60,    61,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,    70,    71,    72,    73,   158,     0,    75,   140,
     141,   142,     0,     0,     0,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,    76,     0,   156,    59,
       0,    61,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,    70,    71,    72,    73,   158,     0,    75,   140,
       0,   142,     0,     0,     0,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,    76,     0,   156,    59,
       0,     0,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,    70,    71,    72,    73,   158,     0,    75,   140,
      -2,     1,     0,     0,     0,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,    76,     1,   156,     0,
      28,     0,    29,     0,     0,    30,     2,    31,     0,     0,
       3,     4,     5,     0,     6,     0,   158,     0,     0,     0,
      32,    33,     2,    34,    35,     0,     3,     4,     5,     0,
       6,    65,    66,    67,    68,     0,    69,     0,    70,    71,
      72,    73,     0,     0,    75,   146,   147,   148,   149,     0,
     150,     0,   151,   152,   153,   154,     0,     0,   156,     0,
       0,    65,    76,    67,    68,     0,    69,     0,    70,    71,
      72,     0,     0,     0,    75,   146,   158,   148,   149,     0,
     150,     0,   151,   152,   153,     0,     0,     0,   156,    28,
       0,    29,    76,     0,    30,    96,    31,    97,     0,    87,
      98,     0,    99,     0,     0,     0,   158,     0,     0,    32,
      33,     0,    34,    35,     0,   101,   102,     0,   103,   104
};

static const yytype_int16 yycheck[] =
{
      84,     8,    21,     8,    22,    23,    23,    13,     0,    28,
      29,    30,    31,    23,    25,    25,    23,    26,    38,    25,
      25,    30,    31,    32,     7,    34,    45,    15,    46,    46,
      38,    24,    15,     8,    38,    15,    97,    98,    99,    46,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    15,     7,
      78,    24,    24,    15,    25,    24,    85,    86,    24,    27,
       8,     8,    26,    -1,    -1,   159,   160,    96,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     1,   158,    -1,    78,
      -1,    -1,    -1,    -1,   188,     9,    -1,     9,    13,    -1,
      15,    -1,    17,    -1,    18,    20,    18,    22,    23,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     1,    38,    39,    -1,    40,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    15,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    25,    -1,    -1,    28,    29,     1,    -1,     9,
      33,    -1,    35,    36,    -1,    38,    39,    17,    18,    13,
      -1,    15,    22,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    25,    -1,    -1,    28,    29,     1,    -1,     9,    33,
      40,    35,    36,    -1,    38,    39,    17,    18,    13,    -1,
      15,    22,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,
      25,     1,    -1,    28,    29,    -1,    -1,     1,    33,    40,
      35,    36,    -1,    38,    39,    15,    -1,    17,    -1,    -1,
      20,    15,    22,    17,    24,    -1,    20,    -1,    22,    -1,
      24,    -1,     1,    -1,    -1,    35,    36,    -1,    38,    39,
       1,    35,    36,    -1,    38,    39,    15,    -1,    17,    -1,
      -1,    20,    -1,    22,    15,    -1,    17,    -1,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    35,    36,    -1,    38,    39,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    40,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    40,    16,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    40,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    40,    16,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    40,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    40,    16,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    40,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    -1,
      14,    40,    16,    17,    18,    19,    -1,    21,    22,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    21,    22,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
      -1,     5,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
      -1,     5,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,    -1,    22,     3,
       0,     1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    40,     1,    22,    -1,
      15,    -1,    17,    -1,    -1,    20,    26,    22,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    40,    -1,    -1,    -1,
      35,    36,    26,    38,    39,    -1,    30,    31,    32,    -1,
      34,     9,    10,    11,    12,    -1,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,     9,    40,    11,    12,    -1,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    22,     9,    40,    11,    12,    -1,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    15,
      -1,    17,    40,    -1,    20,    15,    22,    17,    -1,    25,
      20,    -1,    22,    -1,    -1,    -1,    40,    -1,    -1,    35,
      36,    -1,    38,    39,    -1,    35,    36,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    26,    30,    31,    32,    34,    44,    45,    46,
      49,    53,    54,    25,     0,    46,    49,    53,    38,    50,
      55,     7,    15,    13,    25,    47,     8,    25,    15,    17,
      20,    22,    35,    36,    38,    39,    59,    51,    52,    54,
      13,    23,    25,    28,    29,    33,    48,    53,    54,    56,
      59,    38,    55,     1,    59,    59,    59,    59,    15,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      16,    17,    18,    19,    21,    22,    40,    24,     8,    38,
       1,    23,    56,    57,    58,    15,    15,    25,    59,    23,
      53,    56,    25,    24,    24,     1,    15,    17,    20,    22,
      24,    35,    36,    38,    39,    60,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    52,    23,    25,     1,    23,    57,
      59,    59,    25,    24,     1,    59,    60,    60,    60,    15,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      14,    16,    17,    18,    19,    21,    22,    24,    40,    24,
      24,    24,    24,     1,    24,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    57,    57,    24,    24,    27,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    45,    45,    45,    46,
      47,    47,    48,    48,    48,    48,    49,    50,    51,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     2,     2,     2,     1,     1,     3,     4,     1,     3,
       2,     1,     3,     2,     1,     1,     1,     1,     1,     3,
       1,     3,     2,     1,     3,     2,     5,     7,     5,     3,
       2,     3,     1,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     4,     1,
       1,     1,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     4,     1,
       1,     1,     1,     3,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 59 "uccompiler.y" /* yacc.c:1646  */
    {root = create_node("Program"); add_child(root, (yyvsp[0].node)); if (!error && flag == 't') print_AST(root, 0); free_AST(root);}
#line 1513 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1519 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1525 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1531 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1537 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1543 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1549 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncDefinition"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1555 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 73 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncBody"); add_child((yyval.node), (yyvsp[-1].node));}
#line 1561 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 74 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncBody");}
#line 1567 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 77 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children");add_child((yyval.node), (yyvsp[-1].node));add_child((yyval.node), (yyvsp[0].node));}
#line 1573 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 78 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1579 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 79 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1585 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 80 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1591 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncDeclaration"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[-1].node));}
#line 1597 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 86 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].letters))); add_child((yyval.node), (yyvsp[-1].node));}
#line 1603 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 89 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamList"); add_child((yyval.node), (yyvsp[0].node));}
#line 1609 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1615 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 93 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamDeclaration"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), create_literal_node("Id", (yyvsp[0].letters)));}
#line 1621 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 94 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamDeclaration"); add_child((yyval.node), (yyvsp[0].node)); }
#line 1627 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children");  add_child((yyval.node), (yyvsp[-1].node)); prepend_child((yyval.node), (yyvsp[-2].node));}
#line 1633 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 98 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 1639 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 101 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Char");}
#line 1645 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 102 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Int");}
#line 1651 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Void");}
#line 1657 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 104 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Short");}
#line 1663 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Double");}
#line 1669 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 108 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1675 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 109 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Declaration"); add_child((yyval.node), create_literal_node("Id", (yyvsp[0].letters)));}
#line 1681 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 110 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Declaration"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-2].letters))); add_child((yyval.node), (yyvsp[0].node));}
#line 1687 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 113 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1693 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 114 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1699 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 115 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("StatList"); add_child((yyval.node), (yyvsp[-1].node)); if ((yyval.node)->n_children == 0){destroy_node((yyval.node)); (yyval.node) = NULL;}else if((yyval.node)->n_children == 1){AST_Node aux = (yyval.node)->children[0]; destroy_node((yyval.node)); (yyval.node) = aux;}}
#line 1705 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 116 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1711 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 117 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("If"); add_child((yyval.node), (yyvsp[-2].node)); if ((yyvsp[0].node) != NULL) add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null")); add_child((yyval.node), create_node("Null"));}
#line 1717 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 118 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("If"); add_child((yyval.node), (yyvsp[-4].node)); if ((yyvsp[-2].node) != NULL) add_child((yyval.node), (yyvsp[-2].node)); else add_child((yyval.node), create_node("Null")); if((yyvsp[0].node) != NULL) add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null"));}
#line 1723 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 119 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("While"); add_child((yyval.node), (yyvsp[-2].node)); if((yyvsp[0].node) != NULL)add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null"));}
#line 1729 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 120 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Return"); add_child((yyval.node), (yyvsp[-1].node));}
#line 1735 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 121 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Return"); add_child((yyval.node), create_node("Null"));}
#line 1741 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 1747 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 125 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1753 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; error = 1;}
#line 1759 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 130 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children"); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1765 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1771 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 134 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Store"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1777 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 135 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Comma"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1783 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 136 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Add"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1789 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 137 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Sub"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1795 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mul"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1801 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 139 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Div"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1807 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 140 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mod"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1813 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Or"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1819 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("And"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1825 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 143 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseAnd"); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 1831 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 144 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseOr"); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 1837 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 145 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseXor");add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 1843 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 146 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Eq"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1849 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 147 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ne"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1855 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 148 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Le"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1861 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 149 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ge"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1867 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 150 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Lt"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1873 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 151 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Gt"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1879 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 152 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Plus"); add_child((yyval.node), (yyvsp[0].node));}
#line 1885 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 153 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Minus"); add_child((yyval.node), (yyvsp[0].node));}
#line 1891 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 154 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Not"); add_child((yyval.node), (yyvsp[0].node));}
#line 1897 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 155 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-2].letters)));}
#line 1903 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 156 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].letters))); add_child((yyval.node), (yyvsp[-1].node));}
#line 1909 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 157 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyval.node)=create_literal_node("Id", (yyvsp[0].letters));}
#line 1915 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 158 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("IntLit", (yyvsp[0].letters));}
#line 1921 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 159 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("ChrLit", (yyvsp[0].letters));}
#line 1927 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 160 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("RealLit", (yyvsp[0].letters));}
#line 1933 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 161 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1939 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 162 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_node("Null")); error = 1;}
#line 1945 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 163 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 1951 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 166 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Store"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1957 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 167 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1963 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 168 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Add"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1969 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 169 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Sub"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1975 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 170 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mul"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1981 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 171 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Div"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1987 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 172 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mod"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1993 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 173 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Or"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1999 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 174 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("And"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2005 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 175 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseAnd"); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 2011 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 176 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseOr"); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 2017 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 177 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseXor");add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));}
#line 2023 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 178 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Eq"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2029 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 179 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ne"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2035 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 180 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Le"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2041 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 181 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ge"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2047 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 182 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Lt"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2053 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 183 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Gt"); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 2059 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 184 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Plus"); add_child((yyval.node), (yyvsp[0].node));}
#line 2065 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 185 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Minus"); add_child((yyval.node), (yyvsp[0].node));}
#line 2071 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 186 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Not"); add_child((yyval.node), (yyvsp[0].node));}
#line 2077 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 187 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-2].letters)));}
#line 2083 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 188 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].letters))); add_child((yyval.node), (yyvsp[-1].node));}
#line 2089 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 189 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyval.node)=create_literal_node("Id", (yyvsp[0].letters));}
#line 2095 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 190 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("IntLit", (yyvsp[0].letters));}
#line 2101 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 191 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("ChrLit", (yyvsp[0].letters));}
#line 2107 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 192 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("RealLit", (yyvsp[0].letters));}
#line 2113 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 193 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2119 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 194 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call"); add_child((yyval.node), create_node("Null")); error = 1;}
#line 2125 "uccompiler.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 195 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 2131 "uccompiler.tab.c" /* yacc.c:1646  */
    break;


#line 2135 "uccompiler.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 199 "uccompiler.y" /* yacc.c:1906  */

