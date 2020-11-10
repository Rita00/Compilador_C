%{
    #include <stdio.h>
    #include "ast.h"
    int yylex(void);
    void yyerror (const char *s);
    char error = 0;
    AST_Node root;
%}


%token <letters> REALLIT INTLIT RESERVED BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI CHRLIT ID CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID


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

%union {
    struct _ast_Node *node;
    char *letters;
}

%type <node> Program
%type <node> FunctionsAndDeclarations
%type <node> FunctionDefinition
%type <node> FunctionBody
%type <node> DeclarationsAndStatements
%type <node> FunctionDeclaration
%type <node> FunctionDeclarator
%type <node> ParameterList
%type <node> ParameterDeclaration
%type <node> Declaration
%type <node> TypeSpec
%type <node> Declarator
%type <node> Statement
%type <node> Expr


%%

Program: FunctionsAndDeclarations {root = create_node("Program"); add_child(root, $1); print_AST(root, 0); free_AST(root);}
;

FunctionsAndDeclarations: FunctionDefinition {$$=$1;}
    | FunctionDeclaration {$$=$1;}
    | Declaration {$$=$1;}
    | FunctionsAndDeclarations FunctionDefinition {$$=NULL;}
    | FunctionsAndDeclarations FunctionDeclaration {$$=NULL;}
    | FunctionsAndDeclarations Declaration {$$=NULL;}
;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$=create_node("FuncDefinition"); add_child($$, $1); add_child($$, $2); add_child($$, $3);}
;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$=create_node("FuncBody"); /*TODO*/}
    | LBRACE RBRACE {$$=create_node("FuncBody");}
;

DeclarationsAndStatements: Statement DeclarationsAndStatements {$$=NULL;} 
    | Declaration DeclarationsAndStatements  {$$=NULL;}
    | Statement  {$$=NULL;}
    | Declaration {$$=NULL;}
;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$=NULL;}
;

FunctionDeclarator: ID LPAR ParameterList RPAR {$$ = create_node("many_children"); add_child($$, create_literal_node("Id", yylval.letters)); add_child($$, $3);}
;

ParameterList: ParameterDeclaration  {$$ = create_node("ParamList"); add_child($$, $1);}
;

ParameterDeclaration: ParameterDeclaration COMMA ParameterDeclaration {$$=NULL;}
    | TypeSpec ID {$$ = create_node("many_children"); add_child($$, $1); add_child($$, create_literal_node("Id", yylval.letters));}
    | TypeSpec {$$=$1;}
;

Declaration: TypeSpec Declarator SEMI {$$=NULL;}
    | error SEMI {$$=NULL;}
;

TypeSpec: CHAR  {$$=create_node("Char");}
    | INT  {$$=create_node("Int");}
    | VOID  {$$=create_node("Void");}
    | SHORT  {$$=create_node("Short");}
    | DOUBLE {$$=create_node("Double");}
;

Declarator: Declarator COMMA Declarator {$$=NULL;} 
    | ID  {$$=NULL;}
    | ID ASSIGN Expr {$$=NULL;}
;

Statement: Statement Statement {$$=NULL;}
    | Expr SEMI {$$=NULL;}
    | SEMI {$$=NULL;}
    | LBRACE Statement RBRACE {$$=NULL;}
    | LBRACE RBRACE {$$=NULL;}
    | IF LPAR Expr RPAR Statement {$$=NULL;}
    | IF LPAR Expr RPAR Statement ELSE Statement {$$=NULL;}
    | WHILE LPAR Expr RPAR Statement {$$=NULL;}
    | RETURN Expr SEMI {$$=NULL;}
    | RETURN SEMI {$$=NULL;}
    | error SEMI {$$=NULL;}
    | LBRACE error RBRACE {$$=NULL;}
;

Expr: Expr ASSIGN Expr {$$=NULL;}
    | Expr COMMA Expr {$$=NULL;}
    | Expr PLUS Expr {$$=NULL;}
    | Expr MINUS Expr {$$=NULL;} 
    | Expr MUL Expr {$$=NULL;}
    | Expr DIV Expr {$$=NULL;}
    | Expr MOD Expr {$$=NULL;}
    | Expr OR Expr {$$=NULL;}
    | Expr AND Expr {$$=NULL;}
    | Expr BITWISEAND Expr {$$=NULL;}
    | Expr BITWISEOR Expr {$$=NULL;}
    | Expr BITWISEXOR Expr {$$=NULL;}
    | Expr EQ Expr {$$=NULL;}
    | Expr NE Expr {$$=NULL;}
    | Expr LE Expr {$$=NULL;}
    | Expr GE Expr {$$=NULL;}
    | Expr LT Expr {$$=NULL;}
    | Expr GT Expr {$$=NULL;}
    | PLUS Expr {$$=NULL;}
    | MINUS Expr {$$=NULL;}
    | NOT Expr {$$=NULL;}
    | ID LPAR RPAR {$$=NULL;}
    | ID LPAR Expr RPAR {$$=NULL;}
    | ID  {$$=NULL;}
    | INTLIT {$$=NULL;} 
    | CHRLIT {$$=NULL;}
    | REALLIT {$$=NULL;}
    | LPAR Expr RPAR {$$=NULL;}
    | ID LPAR error RPAR {$$=NULL;}
    | LPAR error RPAR {$$=NULL;}
;

%%


