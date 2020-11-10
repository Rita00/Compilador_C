%{
    #include <stdio.h>
    #include "ast.h"
    int yylex(void);
    void yyerror (char *s);
    char error = 0;
    AST_Node root;
    extern char flag;
%}


%token BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID
%token <letters> REALLIT INTLIT RESERVED ID CHRLIT


%left SEMI
%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc NO_ELSE
%nonassoc ELSE
%left MAX_PREC

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
%type <node> Statlist
%type <node> Expr


%%

Program: FunctionsAndDeclarations {root = create_node("Program"); add_child(root, $1); if (!error && flag == 't') print_AST(root, 0); free_AST(root);}
;

FunctionsAndDeclarations: FunctionDefinition {$$=$1;}
    | FunctionDeclaration {$$=$1;}
    | Declaration {$$=$1;}
    | FunctionsAndDeclarations FunctionDefinition {$$ = create_node("many_children"); add_child($$, $1); add_child($$, $2);}
    | FunctionsAndDeclarations FunctionDeclaration {$$ = create_node("many_children"); add_child($$, $1); add_child($$, $2);}
    | FunctionsAndDeclarations Declaration {$$ = create_node("many_children"); add_child($$, $1); add_child($$, $2);}
;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$=create_node("FuncDefinition"); add_child($$, $1); add_child($$, $2); add_child($$, $3);}
;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$=create_node("FuncBody"); add_child($$, $2);}
    | LBRACE RBRACE {$$=create_node("FuncBody");}
;

DeclarationsAndStatements: DeclarationsAndStatements Statement {$$=create_node("many_children");add_child($$, $1);add_child($$, $2);} 
    | DeclarationsAndStatements Declaration {$$=create_node("many_children"); add_child($$, $1); add_child($$, $2);}
    | Statement  {$$=$1;}
    | Declaration {$$=$1;}  
;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$=create_node("FuncDeclaration"); add_child($$, $1); add_child($$, $2);}
;

FunctionDeclarator: ID LPAR ParameterList RPAR {$$ = create_node("many_children"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);}
;

ParameterList: ParameterDeclaration  {$$ = create_node("ParamList"); add_child($$, $1);}
;

ParameterDeclaration: ParameterDeclaration COMMA ParameterDeclaration {$$=create_node("many_children"); add_child($$, $1); add_child($$, $3);}
    | TypeSpec ID {$$ = create_node("ParamDeclaration"); add_child($$, $1); add_child($$, create_literal_node("Id", $2));}
    | TypeSpec {$$ = create_node("ParamDeclaration"); add_child($$, $1); }
;

Declaration: TypeSpec Declarator SEMI {$$=create_node("many_children");  add_child($$, $2); prepend_child($$, $1);}
    | error SEMI {$$=create_node("Null"); error = 1;}
;

TypeSpec: CHAR  {$$=create_node("Char");}
    | INT  {$$=create_node("Int");}
    | VOID  {$$=create_node("Void");}
    | SHORT  {$$=create_node("Short");}
    | DOUBLE {$$=create_node("Double");}
;

Declarator: Declarator COMMA Declarator {$$=create_node("many_children"); add_child($$, $1); add_child($$, $3);} 
    | ID  {$$=create_node("Declaration"); add_child($$, create_literal_node("Id", $1));}
    | ID ASSIGN Expr {$$=create_node("Declaration"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);}
;

Statement: Expr SEMI {$$=$1;}
    | SEMI {$$=NULL;}
    | LBRACE Statlist Statement RBRACE {$$=create_node("StatList"); add_child($$, $2); add_child($$, $3); if ($$->n_children == 0){destroy_node($$); $$ = NULL;}else if($$->n_children == 1){AST_Node aux = $$->children[0]; destroy_node($$); $$ = aux;}}
    | LBRACE Statement RBRACE {$$=$2;}
    | LBRACE RBRACE {$$=NULL;}
    | IF LPAR Expr RPAR Statement %prec NO_ELSE  {$$=create_node("If");add_child($$, $3); add_child($$, $5); add_child($$, create_node("Null"));}
    | IF LPAR Expr RPAR Statement ELSE Statement {$$=create_node("If"); add_child($$, $3); add_child($$, $5); add_child($$, $7);}
    | WHILE LPAR Expr RPAR Statement {$$=create_node("While");add_child($$, $3); add_child($$, $5);}
    | RETURN Expr SEMI {$$=create_node("Return");add_child($$, $2);}
    | RETURN SEMI {$$=create_node("Return"); add_child($$, create_node("Null"));}
    | LBRACE error RBRACE {$$=NULL; error = 1;}
;

Statlist: Statlist Statement {$$ = create_node("many_children"); add_child($$, $1); add_child($$, $2);}
    | Statement {$$=$1;}
    | error SEMI {$$=NULL; error = 1;}
    ;

Expr: Expr ASSIGN Expr {$$=create_node("Store");add_child($$, $1);add_child($$, $3);}
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
    | PLUS Expr %prec MAX_PREC {$$=create_node("Plus");add_child($$, $2);}
    | MINUS Expr %prec MAX_PREC {$$=create_node("Minus");add_child($$, $2);}
    | NOT Expr %prec MAX_PREC {$$=create_node("Not");add_child($$, $2);}
    | ID LPAR RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1));}
    | ID LPAR Expr RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1)); add_child($$, remove_commas($3));}
    | ID  {$$=$$=create_literal_node("Id", $1);}
    | INTLIT {$$=create_literal_node("IntLit", $1);} 
    | CHRLIT {$$=create_literal_node("ChrLit", $1);}
    | REALLIT {$$=create_literal_node("RealLit", $1);}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call");add_child($$, create_node("Null")); error = 1;}
    | LPAR error RPAR {$$=NULL; error = 1;}
;


%%
