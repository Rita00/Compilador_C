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
    #include "symbol_table.h"
    #include "ast.h"
    int yylex(void);
    void yyerror (char *s);
    char error = 0;
    AST_Node root;
    table_element* gtable;
    extern char flag;

#line 78 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MUL = 258,
    BITWISEAND = 259,
    BITWISEOR = 260,
    BITWISEXOR = 261,
    AND = 262,
    ASSIGN = 263,
    COMMA = 264,
    DIV = 265,
    EQ = 266,
    GE = 267,
    GT = 268,
    LBRACE = 269,
    LE = 270,
    LPAR = 271,
    LT = 272,
    MINUS = 273,
    MOD = 274,
    NE = 275,
    NOT = 276,
    OR = 277,
    PLUS = 278,
    RBRACE = 279,
    RPAR = 280,
    SEMI = 281,
    CHAR = 282,
    ELSE = 283,
    WHILE = 284,
    IF = 285,
    INT = 286,
    SHORT = 287,
    DOUBLE = 288,
    RETURN = 289,
    VOID = 290,
    REALLIT = 291,
    INTLIT = 292,
    RESERVED = 293,
    ID = 294,
    CHRLIT = 295,
    NO_ELSE = 296,
    MAX_PREC = 297
  };
#endif
/* Tokens.  */
#define MUL 258
#define BITWISEAND 259
#define BITWISEOR 260
#define BITWISEXOR 261
#define AND 262
#define ASSIGN 263
#define COMMA 264
#define DIV 265
#define EQ 266
#define GE 267
#define GT 268
#define LBRACE 269
#define LE 270
#define LPAR 271
#define LT 272
#define MINUS 273
#define MOD 274
#define NE 275
#define NOT 276
#define OR 277
#define PLUS 278
#define RBRACE 279
#define RPAR 280
#define SEMI 281
#define CHAR 282
#define ELSE 283
#define WHILE 284
#define IF 285
#define INT 286
#define SHORT 287
#define DOUBLE 288
#define RETURN 289
#define VOID 290
#define REALLIT 291
#define INTLIT 292
#define RESERVED 293
#define ID 294
#define CHRLIT 295
#define NO_ELSE 296
#define MAX_PREC 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "uccompiler.y" /* yacc.c:355  */

    struct _ast_Node *node;
    struct {
        int linha, coluna;
        char *letters;
    } data;

#line 210 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   818

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
       0,    64,    64,    81,    82,    83,    84,    85,    86,    89,
      92,    93,    96,    97,    98,    99,   102,   105,   108,   111,
     112,   113,   116,   117,   120,   121,   122,   123,   124,   127,
     128,   129,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   144,   145,   149,   150,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MUL", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "CHAR", "ELSE", "WHILE", "IF", "INT", "SHORT",
  "DOUBLE", "RETURN", "VOID", "REALLIT", "INTLIT", "RESERVED", "ID",
  "CHRLIT", "NO_ELSE", "MAX_PREC", "$accept", "Program",
  "FunctionsAndDeclarations", "FunctionDefinition", "FunctionBody",
  "DeclarationsAndStatements", "FunctionDeclaration", "FunctionDeclarator",
  "ParameterList", "ParameterDeclaration", "Declaration", "TypeSpec",
  "Declarator", "Statement", "ErrorOrStatement", "Statlist", "Expr",
  "ExprOnCall", YY_NULLPTR
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
     293,   -13,   -85,   -85,   -85,   -85,   -85,    17,   286,   -85,
     -85,   -85,   -20,   -85,   -85,   -85,   -85,   -85,    55,     7,
      -6,   317,    37,    96,   -85,   -85,    -8,   -85,   261,   317,
     317,   317,   -85,   -85,    19,   -85,   547,    33,    50,    22,
     150,   -85,   -85,    46,    49,   311,   123,   -85,    -8,   -85,
     361,    65,   -85,    73,   409,   -85,   -85,   -85,   230,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   -85,    37,   -85,
       6,   -85,   -85,   -85,   177,   317,   317,   -85,   385,   -85,
     -85,   -85,   -85,   -85,   -85,    74,   267,   323,   323,   323,
     -85,   -85,   -85,    58,   -85,   432,   -85,   742,   670,   706,
     631,   547,   547,   -85,   778,     4,     4,     4,     4,     5,
     -85,   778,   589,     5,   -85,   -85,   -85,    75,   -85,   -85,
     455,   478,   -85,   -85,    77,   501,   -85,   -85,   -85,   236,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   -85,   204,
     204,   -85,   -85,    78,   -85,   524,   -85,   760,   688,   724,
     652,   568,   568,   -85,   795,   205,   205,   205,   205,    15,
     -85,   795,   610,    15,   -85,    72,   -85,   -85,   204,   -85
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
      67,   102,   100,    99,   101,     0,    50,    55,    56,    57,
      54,    46,    47,    51,    58,    61,    63,    60,    62,    49,
      52,    59,    53,    48,    19,    41,    43,     0,    34,    44,
       0,     0,    39,    74,     0,     0,    95,    96,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,   105,   103,     0,    97,     0,    80,    85,    86,    87,
      84,    76,    77,    81,    88,    91,    93,    90,    92,    79,
      82,    89,    83,    78,    38,    36,   104,    98,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,    97,   -85,   -85,    98,   -85,   -85,    29,
      -7,   -18,    82,   -17,   -84,   -85,   -19,   -61
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
     129,    17,    36,    26,    39,    48,    49,    59,    59,    54,
      55,    56,    57,    13,    66,    66,    47,    14,   140,    18,
      27,    23,    72,    73,    73,   147,    88,    76,    48,    91,
     125,    51,   126,    24,   154,    58,   136,   137,   138,    90,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    77,    78,
      39,    79,    85,    21,     2,    86,   130,   131,     3,     4,
       5,    22,     6,    21,   139,   184,   185,   135,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     1,    93,   133,
     188,   126,   161,   186,   189,    15,    16,   124,    52,     0,
      40,     0,    28,     0,    29,     0,     0,    30,     0,    31,
      41,     0,    42,     2,     1,    43,    44,     3,     4,     5,
      45,     6,    32,    33,     0,    34,    35,    40,     0,    28,
       0,    29,     0,     0,    30,     0,    31,    89,     0,    42,
       2,    80,    43,    44,     3,     4,     5,    45,     6,    32,
      33,     0,    34,    35,    40,     0,    28,     0,    29,     0,
       0,    30,     0,    31,    81,     0,    42,     0,   127,    43,
      44,     0,     0,     0,    45,     0,    32,    33,     0,    34,
      35,    40,     0,    28,     0,    29,     0,     0,    30,     0,
      31,   128,     0,    42,     0,   127,    43,    44,   140,     0,
       0,    45,     0,    32,    33,   147,    34,    35,    40,     0,
      28,     0,    29,   153,   154,    30,     0,    31,   157,     0,
      42,    95,     0,    43,    44,     0,     0,   163,    45,     0,
      32,    33,     0,    34,    35,     0,    96,     0,    97,     0,
       0,    98,    96,    99,    97,   100,     0,    98,     0,    99,
       0,   164,    53,     0,     0,     0,   101,   102,   134,   103,
     104,     0,   101,   102,     0,   103,   104,    28,     0,    29,
       0,     0,    30,    28,    31,    29,    -2,     1,    30,     0,
      31,     0,     0,     0,     1,     0,     0,    32,    33,     0,
      34,    35,     0,    32,    33,     0,    34,    35,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     3,     4,     5,
       2,     6,     0,     0,     3,     4,     5,    28,     6,    29,
       0,     0,    30,    28,    31,    29,     0,    87,    30,    96,
      31,    97,     0,     0,    98,     0,    99,    32,    33,     0,
      34,    35,     0,    32,    33,     0,    34,    35,     0,   101,
     102,     0,   103,   104,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,     0,    71,    72,
      73,    74,     0,    75,    76,     0,     0,    92,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,     0,    71,    72,    73,    74,     0,    75,    76,     0,
       0,   132,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,     0,    71,    72,    73,    74,
       0,    75,    76,     0,    94,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,   151,     0,   152,
     153,   154,   155,     0,   156,   157,     0,   158,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,     0,    71,    72,    73,    74,     0,    75,    76,     0,
     159,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,     0,    71,    72,    73,    74,     0,
      75,    76,     0,   160,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,     0,    71,    72,
      73,    74,     0,    75,    76,     0,   162,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
       0,   152,   153,   154,   155,     0,   156,   157,     0,   187,
      59,    60,    61,    62,    63,    64,     0,    66,    67,    68,
      69,     0,    70,     0,    71,    72,    73,    74,     0,    75,
      76,   140,   141,   142,   143,   144,   145,     0,   147,   148,
     149,   150,     0,   151,     0,   152,   153,   154,   155,     0,
     156,   157,    59,    60,    61,    62,    63,     0,     0,    66,
      67,    68,    69,     0,    70,     0,    71,    72,    73,    74,
       0,     0,    76,   140,   141,   142,   143,   144,     0,     0,
     147,   148,   149,   150,     0,   151,     0,   152,   153,   154,
     155,     0,     0,   157,    59,    60,    61,    62,     0,     0,
       0,    66,    67,    68,    69,     0,    70,     0,    71,    72,
      73,    74,     0,     0,    76,   140,   141,   142,   143,     0,
       0,     0,   147,   148,   149,   150,     0,   151,     0,   152,
     153,   154,   155,    59,    60,   157,    62,     0,     0,     0,
      66,    67,    68,    69,     0,    70,     0,    71,    72,    73,
      74,   140,   141,    76,   143,     0,     0,     0,   147,   148,
     149,   150,     0,   151,     0,   152,   153,   154,   155,    59,
      60,   157,     0,     0,     0,     0,    66,    67,    68,    69,
       0,    70,     0,    71,    72,    73,    74,   140,   141,    76,
       0,     0,     0,     0,   147,   148,   149,   150,     0,   151,
       0,   152,   153,   154,   155,    59,     0,   157,     0,     0,
       0,     0,    66,    67,    68,    69,     0,    70,     0,    71,
      72,    73,    74,   140,     0,    76,     0,     0,     0,     0,
     147,   148,   149,   150,     0,   151,     0,   152,   153,   154,
     155,    59,     0,   157,     0,     0,     0,     0,    66,     0,
      68,    69,     0,    70,     0,    71,    72,    73,   140,     0,
       0,    76,     0,     0,     0,   147,     0,   149,   150,     0,
     151,     0,   152,   153,   154,     0,     0,     0,   157
};

static const yytype_int16 yycheck[] =
{
      84,     8,    21,     9,    22,    23,    23,     3,     3,    28,
      29,    30,    31,    26,    10,    10,    23,     0,     3,    39,
      26,    14,    18,    19,    19,    10,    45,    23,    46,    46,
      24,    39,    26,    26,    19,    16,    97,    98,    99,    46,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    25,     9,
      78,    39,    16,     8,    27,    16,    85,    86,    31,    32,
      33,    16,    35,     8,    16,   159,   160,    96,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     1,    25,    25,
      28,    26,    25,    25,   188,     8,     8,    78,    26,    -1,
      14,    -1,    16,    -1,    18,    -1,    -1,    21,    -1,    23,
      24,    -1,    26,    27,     1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    14,    -1,    16,
      -1,    18,    -1,    -1,    21,    -1,    23,    24,    -1,    26,
      27,     1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    14,    -1,    16,    -1,    18,    -1,
      -1,    21,    -1,    23,    24,    -1,    26,    -1,     1,    29,
      30,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    39,
      40,    14,    -1,    16,    -1,    18,    -1,    -1,    21,    -1,
      23,    24,    -1,    26,    -1,     1,    29,    30,     3,    -1,
      -1,    34,    -1,    36,    37,    10,    39,    40,    14,    -1,
      16,    -1,    18,    18,    19,    21,    -1,    23,    23,    -1,
      26,     1,    -1,    29,    30,    -1,    -1,     1,    34,    -1,
      36,    37,    -1,    39,    40,    -1,    16,    -1,    18,    -1,
      -1,    21,    16,    23,    18,    25,    -1,    21,    -1,    23,
      -1,    25,     1,    -1,    -1,    -1,    36,    37,     1,    39,
      40,    -1,    36,    37,    -1,    39,    40,    16,    -1,    18,
      -1,    -1,    21,    16,    23,    18,     0,     1,    21,    -1,
      23,    -1,    -1,    -1,     1,    -1,    -1,    36,    37,    -1,
      39,    40,    -1,    36,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      27,    35,    -1,    -1,    31,    32,    33,    16,    35,    18,
      -1,    -1,    21,    16,    23,    18,    -1,    26,    21,    16,
      23,    18,    -1,    -1,    21,    -1,    23,    36,    37,    -1,
      39,    40,    -1,    36,    37,    -1,    39,    40,    -1,    36,
      37,    -1,    39,    40,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    -1,    26,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      -1,    26,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    22,    23,    -1,    25,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      22,    23,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    23,     3,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,    -1,    -1,    23,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    -1,    -1,    23,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,     3,     4,    23,     6,    -1,    -1,    -1,
      10,    11,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,     3,     4,    23,     6,    -1,    -1,    -1,    10,    11,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,     3,
       4,    23,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      -1,    15,    -1,    17,    18,    19,    20,     3,     4,    23,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,     3,    -1,    23,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,     3,    -1,    23,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,     3,    -1,    23,    -1,    -1,    -1,    -1,    10,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,     3,    -1,
      -1,    23,    -1,    -1,    -1,    10,    -1,    12,    13,    -1,
      15,    -1,    17,    18,    19,    -1,    -1,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    31,    32,    33,    35,    44,    45,    46,
      49,    53,    54,    26,     0,    46,    49,    53,    39,    50,
      55,     8,    16,    14,    26,    47,     9,    26,    16,    18,
      21,    23,    36,    37,    39,    40,    59,    51,    52,    54,
      14,    24,    26,    29,    30,    34,    48,    53,    54,    56,
      59,    39,    55,     1,    59,    59,    59,    59,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      15,    17,    18,    19,    20,    22,    23,    25,     9,    39,
       1,    24,    56,    57,    58,    16,    16,    26,    59,    24,
      53,    56,    26,    25,    25,     1,    16,    18,    21,    23,
      25,    36,    37,    39,    40,    60,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    52,    24,    26,     1,    24,    57,
      59,    59,    26,    25,     1,    59,    60,    60,    60,    16,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    15,    17,    18,    19,    20,    22,    23,    25,    25,
      25,    25,    25,     1,    25,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    57,    57,    25,    25,    28,    57
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
#line 64 "uccompiler.y" /* yacc.c:1646  */
    {
        root = create_node("Program", 0, 0); 
        add_child(root, (yyvsp[0].node)); 
        if (!error && flag == 's'){
            gtable=create_global_table(root);
            add_type_to_expressions(root,gtable,NULL);
            print_global_table(gtable); 
            print_AST2(root,0);
            free_table(gtable);
        }
        if (!error && (flag == 't' )){//|| flag == 's')){
            print_AST(root, 0);
        }
        free_AST(root); 
    }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncDefinition", 0, 0); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncBody", 0, 0); add_child((yyval.node), (yyvsp[-1].node));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncBody", 0, 0);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0);add_child((yyval.node), (yyvsp[-1].node));add_child((yyval.node), (yyvsp[0].node));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 102 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("FuncDeclaration", 0, 0); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[-1].node));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children", 0, 0); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].data).letters, (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna)); add_child((yyval.node), (yyvsp[-1].node));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 108 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamList", 0, 0); add_child((yyval.node), (yyvsp[0].node));}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamDeclaration", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), create_literal_node("Id", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna));}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("ParamDeclaration", 0, 0); add_child((yyval.node), (yyvsp[0].node)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0);  add_child((yyval.node), (yyvsp[-1].node)); prepend_child((yyval.node), (yyvsp[-2].node), (yyvsp[-2].node)->n_linha, (yyvsp[-2].node)->n_coluna);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Char", (yyvsp[0].data).linha, (yyvsp[0].data).coluna);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Int", (yyvsp[0].data).linha, (yyvsp[0].data).coluna);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Void", (yyvsp[0].data).linha, (yyvsp[0].data).coluna);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Short", (yyvsp[0].data).linha, (yyvsp[0].data).coluna);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Double", (yyvsp[0].data).linha, (yyvsp[0].data).coluna);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 127 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Declaration", 0, 0); add_child((yyval.node), create_literal_node("Id", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna));}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 129 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Declaration", 0, 0); add_child((yyval.node), create_literal_node("Id", (yyvsp[-2].data).letters, (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna)); add_child((yyval.node), (yyvsp[0].node));}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 132 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 133 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("StatList", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); if ((yyval.node)->n_children == 0){destroy_node((yyval.node)); (yyval.node) = NULL;}else if((yyval.node)->n_children == 1){AST_Node aux = (yyval.node)->children[0]; destroy_node((yyval.node)); (yyval.node) = aux;}}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("If", (yyvsp[-4].data).linha, (yyvsp[-4].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); if ((yyvsp[0].node) != NULL) add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null", 0, 0)); add_child((yyval.node), create_node("Null", 0, 0));}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("If", (yyvsp[-6].data).linha, (yyvsp[-6].data).coluna); add_child((yyval.node), (yyvsp[-4].node)); if ((yyvsp[-2].node) != NULL) add_child((yyval.node), (yyvsp[-2].node)); else add_child((yyval.node), create_node("Null", 0, 0)); if((yyvsp[0].node) != NULL) add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null", 0, 0));}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 138 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("While", (yyvsp[-4].data).linha, (yyvsp[-4].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); if((yyvsp[0].node) != NULL)add_child((yyval.node), (yyvsp[0].node)); else add_child((yyval.node), create_node("Null", 0, 0));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 139 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Return", (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna); add_child((yyval.node), (yyvsp[-1].node));}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 140 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Return", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), create_node("Null", 0, 0));}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 141 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 144 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 145 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; error = 1;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 149 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-1].node)); add_child((yyval.node), (yyvsp[0].node));}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 150 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 153 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Store", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionR"); (yyval.node)->n_linha = (yyvsp[-1].data).linha;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 154 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Comma", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionR");}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 155 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Add", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 156 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Sub", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 157 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mul", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Div", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mod", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Or", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("And", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 162 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseAnd", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 163 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseOr", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 164 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseXor", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna);add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 165 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Eq", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 166 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ne", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 167 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Le", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 168 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ge", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 169 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Lt", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Gt", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Plus", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression1");}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 172 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Minus", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression1");}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 173 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Not", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 174 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna); add_child((yyval.node), create_literal_node("Id", (yyvsp[-2].data).letters, (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna));(yyval.node)->expType = strdup("ExpressionCall");(yyval.node)->children[0]->expType = strdup("ExpressionId");}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 175 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].data).letters, (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna)); add_child((yyval.node), (yyvsp[-1].node));(yyval.node)->expType = strdup("ExpressionCall");(yyval.node)->children[0]->expType = strdup("ExpressionId");}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 176 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyval.node)=create_literal_node("Id", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("ExpressionId");}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 177 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("IntLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("int");}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 178 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("ChrLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("int");}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 179 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("RealLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("double");}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 180 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 181 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna); add_child((yyval.node), create_node("Null", 0, 0)); error = 1;(yyval.node)->expType = strdup("Expression1");}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 182 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 185 "uccompiler.y" /* yacc.c:1646  */
    { (yyval.node)=create_node("Store", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression");}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 186 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("many_children", 0, 0); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression");}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 187 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Add", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 188 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Sub", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 189 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mul", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 190 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Div", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionArit");}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 191 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Mod", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 192 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Or", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 193 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("And", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 194 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseAnd", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 195 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseOr", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 196 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("BitWiseXor", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna);add_child((yyval.node), (yyvsp[-2].node));add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionIntInt");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 197 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Eq", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 198 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ne", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 199 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Le", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 200 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Ge", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 201 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Lt", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 202 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Gt", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 203 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Plus", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression1");}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 204 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Minus", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("Expression1");}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 205 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Not", (yyvsp[-1].data).linha, (yyvsp[-1].data).coluna); add_child((yyval.node), (yyvsp[0].node));(yyval.node)->expType = strdup("ExpressionLogical");}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 206 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna); add_child((yyval.node), create_literal_node("Id",  (yyvsp[-2].data).letters, (yyvsp[-2].data).linha, (yyvsp[-2].data).coluna));(yyval.node)->expType = strdup("ExpressionCall");(yyval.node)->children[0]->expType = strdup("ExpressionId");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 207 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna); add_child((yyval.node), create_literal_node("Id", (yyvsp[-3].data).letters, (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna)); add_child((yyval.node), (yyvsp[-1].node));(yyval.node)->expType = strdup("ExpressionCall");(yyval.node)->children[0]->expType = strdup("ExpressionId");}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 208 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyval.node)=create_literal_node("Id", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("ExpressionId");}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 209 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("IntLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("int");}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 210 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("ChrLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("int");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 211 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_literal_node("RealLit", (yyvsp[0].data).letters, (yyvsp[0].data).linha, (yyvsp[0].data).coluna);(yyval.node)->expType = strdup("double");}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 212 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 213 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=create_node("Call", (yyvsp[-3].data).linha, (yyvsp[-3].data).coluna); add_child((yyval.node), create_node("Null", 0, 0)); error = 1;(yyval.node)->expType = strdup("Expression1");}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 214 "uccompiler.y" /* yacc.c:1646  */
    {(yyval.node)=NULL; error = 1;}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2193 "y.tab.c" /* yacc.c:1646  */
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
#line 218 "uccompiler.y" /* yacc.c:1906  */

