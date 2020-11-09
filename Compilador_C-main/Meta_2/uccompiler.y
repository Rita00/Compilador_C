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
%right '='
%left '+' '-'
%left '*' '/'

%%
FunctionsAndDeclarations:
;
FunctionDefinition:
;
FunctionBody:
;
DeclarationsAndStatements:
;
FunctionDeclaration:
;
FunctionDeclarator:
;
ParameterList:
;
ParameterDeclaration:
;
Declaration:
;
TypeSpec:
;
Declarator:
;
Statement:
;
Expr:
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


