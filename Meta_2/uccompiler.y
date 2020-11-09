%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#define NSYMS 9999

symtab tab[NSYMS];

symtab *symlook(char *varname);
%}
%token <realnum> REALLIT
%token <intnum> INTLIT
%token <letters> SIMPLE RESERVED BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI CHRLIT ID
%type <value> expression
%union{
double realnum;
int intnum;
char* letters;
}
%right LBRACE 
%right EQ NE GE GT LE LT 
%right LPAR 
%right ASSIGN 
%right NOT
%left COMMA 
%left RBRACE 
%left SEMI 
%left BITWISEOR OR 
%left BITWISEXOR 
%left BITWISEAND AND 
%left PLUS MINUS 
%left MUL DIV MOD 
%left RPAR

%%
FunctionsAndDeclarations:
	FunctionDefinition	{}
|	FunctionDeclaration	{}
|	Declaration	{}
|	FunctionsAndDeclarations FunctionDefinition	{}
|	FunctionsAndDeclarations FunctionDeclaration	{}
|	FunctionsAndDeclarations Declaration	{}
;
FunctionDefinition:
	TypeSpec FunctionDeclarator FunctionBody	{}
; 
FunctionBody:
	LBRACE DeclarationsAndStatements RBRACE	{}
	LBRACE RBRACE	{}
;
DeclarationsAndStatements:
	Statement DeclarationsAndStatements	{}
|	Declaration DeclarationsAndStatements	{}
|	Statement	{}
|	Declaration	{}
;
FunctionDeclaration:
	TypeSpec FunctionDeclarator SEMI	{}
;
FunctionDeclarator:
	ID LPAR ParameterList RPAR	{}
;
ParameterList:
ParameterDeclaration COMMA ParameterDeclaration
;
ParameterDeclaration:
	TypeSpec ID	{}
|	TypeSpec	{}
;
Declaration:
	TypeSpec Declarator COMMA Declarator SEMI	{}
;
TypeSpec:
	CHAR	{}
|	INT	{}
|	SIMPLE	{}	//void, short, double
;
Declarator:
	ID	{}
|	ID ASSIGN Expr	{}
|	ID COMMA ID 	{}	//suponho que isto se verifique
;
Statement:
	RETURN SEMI	{}
|	RETURN Expr SEMI	{}
|	WHILE LPAR Expr RPAR Statement	{}
|	IF LPAR Expr RPAR Statement	{}
|	IF LPAR Expr RPAR Statement ELSE Statement	{}
|	LBRACE Statement RBRACE	{}
|	Statement Statement	{}	//suponho que isto se verifique
|	SEMI
|	Expr SEMI	{}
;
Expr:
	ID	{}
|	INTLIT	{}
|	CHRLIT	{}
|	REALLIT	{}	
| 	LPAR Expr RPAR	{}
|	ID LPAR RPAR	{}
|	ID LPAR Expr COMMA EXPR RPAR {}
|	PLUS Expr	{}
|	MINUS Expr	{}
|	NOT Expr	{}
|	Expr EQ Expr	{}
|	Expr NE Expr	{}
|	Expr LE Expr	{}
|	Expr GE Expr	{}
|	Expr LT Expr	{}
|	Expr GT Expr 	{}
|	Expr OR Expr	{}
| 	Expr AND Expr	{}
| 	Expr BITWISEAND Expr	{}
|	Expr BITWISEOR Expr	{} 
|	Expr BITWISEXOR Expr	{}
|	Expr PLUS Expr	{}
|	Expr MINUS Expr {}
| 	Expr MUL Expr	{}
|	Expr DIV Expr {}
| 	Expr MOD Expr	{}
|	Expr ASSIGN Expr	{}
|	Expr COMMA Expr	{}
;

%%
int main()
{
yyparse();
return 0;
}
symtab *symlook(char *varname)
{
int i;
  
for(i=0; i<NSYMS; i++)
 {
        if(tab[i].name && strcmp(varname, tab[i].name)==0)   
                return &tab[i];
        if(!tab[i].name)
        {
                tab[i].name=varname;
                return &tab[i];
        }
 }
yyerror("variaveis a mais...");
    exit(1);
}


