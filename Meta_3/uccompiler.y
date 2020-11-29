%{
    #include <stdio.h>
    #include "symbol_table.h"
    #include "ast.h"
    int yylex(void);
    void yyerror (char *s);
    char error = 0;
    AST_Node root;
    table_element* gtable;
    extern char flag;
%}


%token <data> MUL BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID
%token <data> REALLIT INTLIT RESERVED ID CHRLIT


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
    struct {
        int linha, coluna;
        char *letters;
    } data;
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
%type <node> ExprOnCall
%type <node> ErrorOrStatement


%%

Program: FunctionsAndDeclarations {
        root = create_node("Program", 0, 0); 
        add_child(root, $1); 
        if (!error && flag == 's'){
            gtable=create_global_table(root);
            print_global_table(gtable); 
            print_AST2(root,0);
            free_table(gtable);
        }
        if (!error && (flag == 't' )){//|| flag == 's')){
            print_AST(root, 0);
        }
        free_AST(root); 
    }
;

FunctionsAndDeclarations: FunctionDefinition {$$=$1;}
    | FunctionDeclaration {$$=$1;}
    | Declaration {$$=$1;}
    | FunctionsAndDeclarations FunctionDefinition {$$ = create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $2);}
    | FunctionsAndDeclarations FunctionDeclaration {$$ = create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $2);}
    | FunctionsAndDeclarations Declaration {$$ = create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $2);}
;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$=create_node("FuncDefinition", 0, 0); add_child($$, $1); add_child($$, $2); add_child($$, $3);}
;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$=create_node("FuncBody", 0, 0); add_child($$, $2);}
    | LBRACE RBRACE {$$=create_node("FuncBody", 0, 0);}
;

DeclarationsAndStatements: DeclarationsAndStatements Statement {$$=create_node("many_children", 0, 0);add_child($$, $1);add_child($$, $2);} 
    | DeclarationsAndStatements Declaration {$$=create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $2);}
    | Statement  {$$=$1;}
    | Declaration {$$=$1;}  
;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$=create_node("FuncDeclaration", 0, 0); add_child($$, $1); add_child($$, $2);}
;

FunctionDeclarator: ID LPAR ParameterList RPAR {$$ = create_node("many_children", 0, 0); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna)); add_child($$, $3);}
;

ParameterList: ParameterDeclaration  {$$ = create_node("ParamList", 0, 0); add_child($$, $1);}
;

ParameterDeclaration: ParameterDeclaration COMMA ParameterDeclaration {$$=create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $3);}
    | TypeSpec ID {$$ = create_node("ParamDeclaration", 0, 0); add_child($$, $1); add_child($$, create_literal_node("Id", $2.letters, $2.linha, $2.coluna));}
    | TypeSpec {$$ = create_node("ParamDeclaration", 0, 0); add_child($$, $1); }
;

Declaration: TypeSpec Declarator SEMI {$$=create_node("many_children", 0, 0);  add_child($$, $2); prepend_child($$, $1, $1->n_linha, $1->n_coluna);}
    | error SEMI {$$=NULL; error = 1;}
;

TypeSpec: CHAR  {$$=create_node("Char", $1.linha, $1.coluna);}
    | INT  {$$=create_node("Int", $1.linha, $1.coluna);}
    | VOID  {$$=create_node("Void", $1.linha, $1.coluna);}
    | SHORT  {$$=create_node("Short", $1.linha, $1.coluna);}
    | DOUBLE {$$=create_node("Double", $1.linha, $1.coluna);}
;

Declarator: Declarator COMMA Declarator {$$=create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $3);} 
    | ID  {$$=create_node("Declaration", 0, 0); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna));}
    | ID ASSIGN Expr {$$=create_node("Declaration", 0, 0); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna)); add_child($$, $3);}
;

Statement: Expr SEMI {$$=$1;}
    | SEMI {$$=NULL;}
    | LBRACE Statlist RBRACE {$$=create_node("StatList", 0, 0); add_child($$, $2); if ($$->n_children == 0){destroy_node($$); $$ = NULL;}else if($$->n_children == 1){AST_Node aux = $$->children[0]; destroy_node($$); $$ = aux;}}
    | LBRACE RBRACE {$$=NULL;}
    | IF LPAR Expr RPAR ErrorOrStatement %prec NO_ELSE  {$$=create_node("If", $1.linha, $1.coluna); add_child($$, $3); if ($5 != NULL) add_child($$, $5); else add_child($$, create_node("Null", 0, 0)); add_child($$, create_node("Null", 0, 0));}
    | IF LPAR Expr RPAR ErrorOrStatement ELSE ErrorOrStatement {$$=create_node("If", $1.linha, $1.coluna); add_child($$, $3); if ($5 != NULL) add_child($$, $5); else add_child($$, create_node("Null", 0, 0)); if($7 != NULL) add_child($$, $7); else add_child($$, create_node("Null", 0, 0));}
    | WHILE LPAR Expr RPAR ErrorOrStatement {$$=create_node("While", $1.linha, $1.coluna); add_child($$, $3); if($5 != NULL)add_child($$, $5); else add_child($$, create_node("Null", 0, 0));}
    | RETURN Expr SEMI {$$=create_node("Return", $1.linha, $1.coluna); add_child($$, $2);}
    | RETURN SEMI {$$=create_node("Return", $1.linha, $1.coluna); add_child($$, create_node("Null", 0, 0));}
    | LBRACE error RBRACE {$$=NULL; error = 1;}
;

ErrorOrStatement : Statement {$$ = $1;}
    | error SEMI {$$ = NULL; error = 1;}
;


Statlist: Statlist ErrorOrStatement {$$ = create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $2);}
    | ErrorOrStatement {$$ = $1;}
    ;

Expr: Expr ASSIGN Expr {$$=create_node("Store", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR"); $$->n_linha = $2.linha;}
    | Expr COMMA Expr {$$=create_node("Comma", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR");}
    | Expr PLUS Expr {$$=create_node("Add", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr MINUS Expr {$$=create_node("Sub", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");} 
    | Expr MUL Expr {$$=create_node("Mul", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr DIV Expr {$$=create_node("Div", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr MOD Expr {$$=create_node("Mod", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr OR Expr {$$=create_node("Or", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr AND Expr {$$=create_node("And", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr BITWISEAND Expr {$$=create_node("BitWiseAnd", $2.linha, $2.coluna); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr BITWISEOR Expr {$$=create_node("BitWiseOr", $2.linha, $2.coluna); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr BITWISEXOR Expr {$$=create_node("BitWiseXor", $2.linha, $2.coluna);add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr EQ Expr {$$=create_node("Eq", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | Expr NE Expr {$$=create_node("Ne", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | Expr LE Expr {$$=create_node("Le", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | Expr GE Expr {$$=create_node("Ge", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | Expr LT Expr {$$=create_node("Lt", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | Expr GT Expr {$$=create_node("Gt", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | PLUS Expr %prec MAX_PREC {$$=create_node("Plus", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("Expression1");}
    | MINUS Expr %prec MAX_PREC {$$=create_node("Minus", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("Expression1");}
    | NOT Expr %prec MAX_PREC {$$=create_node("Not", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("ExpressionLogical");}
    | ID LPAR RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna));$$->expType = strdup("ExpressionCall");$$->children[0]->expType = strdup("ExpressionId");}
    | ID LPAR ExprOnCall RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna)); add_child($$, $3);$$->expType = strdup("ExpressionCall");$$->children[0]->expType = strdup("ExpressionId");}
    | ID  {$$=$$=create_literal_node("Id", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("ExpressionId");}
    | INTLIT {$$=create_literal_node("IntLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("int");} 
    | CHRLIT {$$=create_literal_node("ChrLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("int");}
    | REALLIT {$$=create_literal_node("RealLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("double");}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_node("Null", 0, 0)); error = 1;$$->expType = strdup("Expression1");}
    | LPAR error RPAR {$$=NULL; error = 1;}
;

ExprOnCall: ExprOnCall ASSIGN ExprOnCall { $$=create_node("Store", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR");}
    | ExprOnCall COMMA ExprOnCall {$$=create_node("many_children", 0, 0); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR");}
    | ExprOnCall PLUS ExprOnCall {$$=create_node("Add", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall MINUS ExprOnCall {$$=create_node("Sub", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");} 
    | ExprOnCall MUL ExprOnCall {$$=create_node("Mul", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall DIV ExprOnCall {$$=create_node("Div", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall MOD ExprOnCall {$$=create_node("Mod", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall OR ExprOnCall {$$=create_node("Or", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall AND ExprOnCall {$$=create_node("And", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall BITWISEAND ExprOnCall {$$=create_node("BitWiseAnd", $2.linha, $2.coluna); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall BITWISEOR ExprOnCall {$$=create_node("BitWiseOr", $2.linha, $2.coluna); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall BITWISEXOR ExprOnCall {$$=create_node("BitWiseXor", $2.linha, $2.coluna);add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall EQ ExprOnCall {$$=create_node("Eq", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | ExprOnCall NE ExprOnCall {$$=create_node("Ne", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | ExprOnCall LE ExprOnCall {$$=create_node("Le", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | ExprOnCall GE ExprOnCall {$$=create_node("Ge", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | ExprOnCall LT ExprOnCall {$$=create_node("Lt", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | ExprOnCall GT ExprOnCall {$$=create_node("Gt", $2.linha, $2.coluna); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionLogical");}
    | PLUS ExprOnCall %prec MAX_PREC {$$=create_node("Plus", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("Expression1");}
    | MINUS ExprOnCall %prec MAX_PREC {$$=create_node("Minus", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("Expression1");}
    | NOT ExprOnCall %prec MAX_PREC {$$=create_node("Not", $1.linha, $1.coluna); add_child($$, $2);$$->expType = strdup("ExpressionLogical");}
    | ID LPAR RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_literal_node("Id",  $1.letters, $1.linha, $1.coluna));$$->expType = strdup("ExpressionCall");$$->children[0]->expType = strdup("ExpressionId");}
    | ID LPAR ExprOnCall RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_literal_node("Id", $1.letters, $1.linha, $1.coluna)); add_child($$, $3);$$->expType = strdup("ExpressionCall");$$->children[0]->expType = strdup("ExpressionId");}
    | ID  {$$=$$=create_literal_node("Id", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("ExpressionId");}
    | INTLIT {$$=create_literal_node("IntLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("int");} 
    | CHRLIT {$$=create_literal_node("ChrLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("int");}
    | REALLIT {$$=create_literal_node("RealLit", $1.letters, $1.linha, $1.coluna);$$->expType = strdup("double");}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call", $1.linha, $1.coluna); add_child($$, create_node("Null", 0, 0)); error = 1;$$->expType = strdup("Expression1");}
    | LPAR error RPAR {$$=NULL; error = 1;}
;


%%
