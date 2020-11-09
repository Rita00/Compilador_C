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
    REALLIT = 258,
    INTLIT = 259,
    RESERVED = 260,
    BITWISEAND = 261,
    BITWISEOR = 262,
    BITWISEXOR = 263,
    AND = 264,
    ASSIGN = 265,
    COMMA = 266,
    DIV = 267,
    EQ = 268,
    GE = 269,
    GT = 270,
    LBRACE = 271,
    LE = 272,
    LPAR = 273,
    LT = 274,
    MINUS = 275,
    MOD = 276,
    NE = 277,
    NOT = 278,
    OR = 279,
    PLUS = 280,
    RBRACE = 281,
    RPAR = 282,
    SEMI = 283,
    CHRLIT = 284,
    ID = 285,
    CHAR = 286,
    ELSE = 287,
    WHILE = 288,
    IF = 289,
    INT = 290,
    SHORT = 291,
    DOUBLE = 292,
    RETURN = 293,
    VOID = 294,
    MUL = 295
  };
#endif
/* Tokens.  */
#define REALLIT 258
#define INTLIT 259
#define RESERVED 260
#define BITWISEAND 261
#define BITWISEOR 262
#define BITWISEXOR 263
#define AND 264
#define ASSIGN 265
#define COMMA 266
#define DIV 267
#define EQ 268
#define GE 269
#define GT 270
#define LBRACE 271
#define LE 272
#define LPAR 273
#define LT 274
#define MINUS 275
#define MOD 276
#define NE 277
#define NOT 278
#define OR 279
#define PLUS 280
#define RBRACE 281
#define RPAR 282
#define SEMI 283
#define CHRLIT 284
#define ID 285
#define CHAR 286
#define ELSE 287
#define WHILE 288
#define IF 289
#define INT 290
#define SHORT 291
#define DOUBLE 292
#define RETURN 293
#define VOID 294
#define MUL 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "uccompiler.y" /* yacc.c:1909  */

    struct _ast_Node *node;
    char *letters;

#line 139 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
