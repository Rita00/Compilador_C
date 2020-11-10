%{
    #include <stdio.h>
    #include "ast.h"
    int yylex(void);
    void yyerror (const char *s);
    char error = 0;
    AST_Node root;
%}


%token BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID
%token <letters> REALLIT INTLIT RESERVED ID CHRLIT

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

FunctionDeclarator: ID LPAR ParameterList RPAR {$$ = create_node("many_children"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);}
;

ParameterList: ParameterDeclaration  {$$ = create_node("ParamList"); add_child($$, $1);}
;

ParameterDeclaration: ParameterDeclaration COMMA ParameterDeclaration {$$=create_node("many_children"); add_child($$, $1); add_child($$, $3);}
    | TypeSpec ID {$$ = create_node("ParamDeclaration"); add_child($$, $1); add_child($$, create_literal_node("Id", $2));}
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

Expr: Expr ASSIGN Expr {$$=create_node("Assign");add_child($$, $1);add_child($$, $3);}
    | Expr COMMA Expr {$$=create_node("Comma");add_child($$, $1);add_child($$, $3);}
    | Expr PLUS Expr {$$=create_node("Add");add_child($$, $1);add_child($$, $3);}
    | Expr MINUS Expr {$$=create_node("Sub");add_child($$, $1);add_child($$, $3);} 
    | Expr MUL Expr {$$=create_node("Mul");add_child($$, $1);add_child($$, $3);}
    | Expr DIV Expr {$$=create_node("Div");add_child($$, $1);add_child($$, $3);}
    | Expr MOD Expr {$$=create_node("Mod");add_child($$, $1);add_child($$, $3);}
    | Expr OR Expr {$$=create_node("Or");add_child($$, $1);add_child($$, $3);}
    | Expr AND Expr {$$=create_node("And");add_child($$, $1);add_child($$, $3);}
    | Expr BITWISEAND Expr {$$=create_node("BitWiseAnd");add_child($$, $1);add_child($$, $3);}
    | Expr BITWISEOR Expr {$$=create_node("BitWiseOr");add_child($$, $1);add_child($$, $3);}
    | Expr BITWISEXOR Expr {$$=create_node("BitWiseXor");add_child($$, $1);add_child($$, $3);}
    | Expr EQ Expr {$$=create_node("Eq");add_child($$, $1);add_child($$, $3);}
    | Expr NE Expr {$$=create_node("Ne");add_child($$, $1);add_child($$, $3);}
    | Expr LE Expr {$$=create_node("Le");add_child($$, $1);add_child($$, $3);}
    | Expr GE Expr {$$=create_node("Ge");add_child($$, $1);add_child($$, $3);}
    | Expr LT Expr {$$=create_node("Lt");add_child($$, $1);add_child($$, $3);}
    | Expr GT Expr {$$=create_node("Gt");add_child($$, $1);add_child($$, $3);}
    | PLUS Expr {$$=create_node("Plus");add_child($$, $2);}
    | MINUS Expr {$$=create_node("Minus");add_child($$, $2);}
    | NOT Expr {$$=create_node("Not");add_child($$, $2);}
    | ID LPAR RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1));}
    | ID LPAR Expr RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);}
    | ID  {$$=$$=create_literal_node("Id", $1);}
    | INTLIT {$$=create_literal_node("Intlit", $1);} 
    | CHRLIT {$$=create_literal_node("Chrlit", $1);}
    | REALLIT {$$=create_literal_node("Reallit", $1);}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call");add_child($$, NULL);}
    | LPAR error RPAR {$$=NULL;}
;

%%
