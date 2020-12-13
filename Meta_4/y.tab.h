/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 36 "uccompiler.y" /* yacc.c:1909  */

    struct _ast_Node *node;
    struct {
        int linha, coluna;
        char *letters;
    } data;

#line 146 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
