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
%type <node> ExprOnCall
%type <node> ErrorOrStatement


%%

Program: FunctionsAndDeclarations {
        root = create_node("Program"); 
        add_child(root, $1); 
        if (!error && flag == 's'){
            gtable=create_global_table(root);
            print_global_table(gtable); 
            add_type_to_expressions(root,root);
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
    | error SEMI {$$=NULL; error = 1;}
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
    | LBRACE Statlist RBRACE {$$=create_node("StatList"); add_child($$, $2); if ($$->n_children == 0){destroy_node($$); $$ = NULL;}else if($$->n_children == 1){AST_Node aux = $$->children[0]; destroy_node($$); $$ = aux;}}
    | LBRACE RBRACE {$$=NULL;}
    | IF LPAR Expr RPAR ErrorOrStatement %prec NO_ELSE  {$$=create_node("If"); add_child($$, $3); if ($5 != NULL) add_child($$, $5); else add_child($$, create_node("Null")); add_child($$, create_node("Null"));}
    | IF LPAR Expr RPAR ErrorOrStatement ELSE ErrorOrStatement {$$=create_node("If"); add_child($$, $3); if ($5 != NULL) add_child($$, $5); else add_child($$, create_node("Null")); if($7 != NULL) add_child($$, $7); else add_child($$, create_node("Null"));}
    | WHILE LPAR Expr RPAR ErrorOrStatement {$$=create_node("While"); add_child($$, $3); if($5 != NULL)add_child($$, $5); else add_child($$, create_node("Null"));}
    | RETURN Expr SEMI {$$=create_node("Return"); add_child($$, $2);}
    | RETURN SEMI {$$=create_node("Return"); add_child($$, create_node("Null"));}
    | LBRACE error RBRACE {$$=NULL; error = 1;}
;

ErrorOrStatement : Statement {$$ = $1;}
    | error SEMI {$$ = NULL; error = 1;}
;


Statlist: Statlist ErrorOrStatement {$$ = create_node("many_children"); add_child($$, $1); add_child($$, $2);}
    | ErrorOrStatement {$$ = $1;}
    ;

Expr: Expr ASSIGN Expr {$$=create_node("Store"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR");}
    | Expr COMMA Expr {$$=create_node("Comma"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionR");}
    | Expr PLUS Expr {$$=create_node("Add"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr MINUS Expr {$$=create_node("Sub"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");} 
    | Expr MUL Expr {$$=create_node("Mul"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr DIV Expr {$$=create_node("Div"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | Expr MOD Expr {$$=create_node("Mod"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr OR Expr {$$=create_node("Or"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr AND Expr {$$=create_node("And"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr BITWISEAND Expr {$$=create_node("BitWiseAnd"); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr BITWISEOR Expr {$$=create_node("BitWiseOr"); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr BITWISEXOR Expr {$$=create_node("BitWiseXor");add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | Expr EQ Expr {$$=create_node("Eq"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr NE Expr {$$=create_node("Ne"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr LE Expr {$$=create_node("Le"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr GE Expr {$$=create_node("Ge"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr LT Expr {$$=create_node("Lt"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | Expr GT Expr {$$=create_node("Gt"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | PLUS Expr %prec MAX_PREC {$$=create_node("Plus"); add_child($$, $2);$$->expType = strdup("Expression1");}
    | MINUS Expr %prec MAX_PREC {$$=create_node("Minus"); add_child($$, $2);$$->expType = strdup("Expression1");}
    | NOT Expr %prec MAX_PREC {$$=create_node("Not"); add_child($$, $2);$$->expType = strdup("int");}
    | ID LPAR RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1));$$->expType = strdup("Expression1");$$->children[0]->expType = strdup("ExpressionId");}
    | ID LPAR ExprOnCall RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);$$->expType = strdup("Expression1");$$->children[0]->expType = strdup("ExpressionId");}
    | ID  {$$=$$=create_literal_node("Id", $1);$$->expType = strdup("ExpressionId");}
    | INTLIT {$$=create_literal_node("IntLit", $1);$$->expType = strdup("int");} 
    | CHRLIT {$$=create_literal_node("ChrLit", $1);$$->expType = strdup("int");}
    | REALLIT {$$=create_literal_node("RealLit", $1);$$->expType = strdup("double");}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call"); add_child($$, create_node("Null")); error = 1;$$->expType = strdup("Expression1");}
    | LPAR error RPAR {$$=NULL; error = 1;}
;

ExprOnCall: ExprOnCall ASSIGN ExprOnCall {$$=create_node("Store"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("Expression");}
    | ExprOnCall COMMA ExprOnCall {$$=create_node("many_children"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("Expression");}
    | ExprOnCall PLUS ExprOnCall {$$=create_node("Add"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall MINUS ExprOnCall {$$=create_node("Sub"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");} 
    | ExprOnCall MUL ExprOnCall {$$=create_node("Mul"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall DIV ExprOnCall {$$=create_node("Div"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionArit");}
    | ExprOnCall MOD ExprOnCall {$$=create_node("Mod"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall OR ExprOnCall {$$=create_node("Or"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall AND ExprOnCall {$$=create_node("And"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall BITWISEAND ExprOnCall {$$=create_node("BitWiseAnd"); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall BITWISEOR ExprOnCall {$$=create_node("BitWiseOr"); add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall BITWISEXOR ExprOnCall {$$=create_node("BitWiseXor");add_child($$, $1);add_child($$, $3);$$->expType = strdup("ExpressionIntInt");}
    | ExprOnCall EQ ExprOnCall {$$=create_node("Eq"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall NE ExprOnCall {$$=create_node("Ne"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall LE ExprOnCall {$$=create_node("Le"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall GE ExprOnCall {$$=create_node("Ge"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall LT ExprOnCall {$$=create_node("Lt"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | ExprOnCall GT ExprOnCall {$$=create_node("Gt"); add_child($$, $1); add_child($$, $3);$$->expType = strdup("int");}
    | PLUS ExprOnCall %prec MAX_PREC {$$=create_node("Plus"); add_child($$, $2);$$->expType = strdup("Expression1");}
    | MINUS ExprOnCall %prec MAX_PREC {$$=create_node("Minus"); add_child($$, $2);$$->expType = strdup("Expression1");}
    | NOT ExprOnCall %prec MAX_PREC {$$=create_node("Not"); add_child($$, $2);$$->expType = strdup("int");}
    | ID LPAR RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1));$$->expType = strdup("Expression1");$$->children[0]->expType = strdup("ExpressionId");}
    | ID LPAR ExprOnCall RPAR {$$=create_node("Call"); add_child($$, create_literal_node("Id", $1)); add_child($$, $3);$$->expType = strdup("Expression1");$$->children[0]->expType = strdup("ExpressionId");}
    | ID  {$$=$$=create_literal_node("Id", $1);$$->expType = strdup("ExpressionId");}
    | INTLIT {$$=create_literal_node("IntLit", $1);$$->expType = strdup("int");} 
    | CHRLIT {$$=create_literal_node("ChrLit", $1);$$->expType = strdup("int");}
    | REALLIT {$$=create_literal_node("RealLit", $1);$$->expType = strdup("double");}
    | LPAR Expr RPAR {$$=$2;}
    | ID LPAR error RPAR {$$=create_node("Call"); add_child($$, create_node("Null")); error = 1;$$->expType = strdup("Expression1");}
    | LPAR error RPAR {$$=NULL; error = 1;}
;


%%
