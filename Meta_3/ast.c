

#include "ast.h"
#include "symbol_table.h"
AST_Node create_node(char *token) { //TODO n_linha e n_coluna
    AST_Node new_node = calloc(1, sizeof(struct _ast_Node));
    new_node->token = strdup(token);
    return new_node;
}

AST_Node create_literal_node(char *token, char * content){
    char aux[10000];
    sprintf(aux, "%s(%s)", token, content);
    free(content);
    return create_node(aux);
}

void add_child(AST_Node target, AST_Node child) {
    if(child == NULL) return;
    if (strcmp(child->token, "many_children")){
        child->parent = target;
        //criar novo array
        AST_Node *new_array = calloc(target->n_children + 1, sizeof(AST_Node));
        // copiar conteudos do antigo array para o novo
        memcpy(new_array, target->children, target->n_children*sizeof(AST_Node));
        //Adicionar child ao novo array
        new_array[target->n_children] = child;
        // trocar array antigo por novo
        target->n_children++;
        free(target->children);
        target->children = new_array;
    }else{
        //criar novo array
        AST_Node *new_array = calloc(target->n_children + child->n_children, sizeof(AST_Node));
        memcpy(new_array, target->children, target->n_children*sizeof(AST_Node));
        for (int i = 0; i < child->n_children; i++) {
            child->children[i]->parent = target;
            new_array[target->n_children+i] = child->children[i];
        }
        target->n_children += child->n_children;
        free(target->children);
        destroy_node(child);
        target->children = new_array;
    }
    
}

void prepend_child(AST_Node root, AST_Node child){ //resolver frees
     for(int i = 0; i < root->n_children; i++) {
        AST_Node new_child = create_node(child->token);
        new_child->parent = root->children[i];
        AST_Node *new_array = calloc(root->children[i]->n_children + 1, sizeof(AST_Node));
        memcpy(new_array+1, root->children[i]->children, root->children[i]->n_children*sizeof(AST_Node));
        new_array[0] = new_child;
        free(root->children[i]->children);
        root->children[i]->children = new_array;
        root->children[i]->n_children++;
    }
    destroy_node(child);
}

void destroy_node(AST_Node root){
    free(root->token);
    free(root->children);
    free(root);
}

void free_AST(AST_Node root) {
    for (int i = 0; i < root->n_children; i++) {
        free_AST(root->children[i]);
    }
    free(root->children);
    free(root);
}

void print_AST(AST_Node root, int n_tabs) {
    for (int i = 0; i < n_tabs; i++) {
        printf("..");
    }
    printf("%s\n", root->token);
    for (int i = 0; i < root->n_children; i++) {
        print_AST(root->children[i], n_tabs + 1);
    }
}

void print_AST2(AST_Node root, int n_tabs) { //anotada
    for (int i = 0; i < n_tabs; i++) {
        printf("..");
    }
    if(root->expType){
        printf("%s - %s\n", root->token, root->expType);
    }
    else{
      printf("%s\n", root->token);  
    }
    for (int i = 0; i < root->n_children; i++) {
        print_AST(root->children[i], n_tabs + 1);
    }
}

void add_type_to_expressions(AST_Node node, table_element *table) {
    table_element *aux;

    if (node->expType && strlen(node->expType)>3 && strncmp(node->expType, "Expression",strlen("Expression")) == 0) {
        for(int i = 0; i<node->n_children;i++){
            add_type_to_expressions(node->children[i],table); //Para comecar pelas folhas caso a expression tenha filhos expressions
        }
        if(strcmp(node->token,"Id")==0){ //procura declarations
            int found = 0;
            for (aux = table; aux; aux = aux->next) {
                if (aux->isDefined){
                    while (aux->table != NULL) {
                        if(strcmp(node->token,aux->table->variable)==0){
                            node->expType = strdup(aux->table->type);
                            found = 1;
                        }
                        aux->table = aux->table->next;
                    }
                }
                else if(strcmp(node->token,aux->name)==0){
                    node->expType = strdup(aux->table->type);
                    found = 1;
                }
            } //Erro: 1. Se encontrar mais q uma declaration 
              //Erro: 2. Se nao encontrar declaration nenhuma
            //Problema: isto corre quando a table ja esta feita
        }
        else if(strcmp(node->expType,"ExpressionArit")==0){ //operacoes aritmeticas binarias (ex: int + double = double) 
            if(strcmp(node->children[0]->expType,"double") || strcmp(node->children[1]->expType,"double")){
                node->expType = strdup("double");  
            }
            else{
                node->expType = strdup(node->children[0]->expType);  
            }
        }
        else if(strcmp(node->expType,"ExpressionR")==0){ //operacoes binarias que ficam com o valor da direita (igual e virgula) 
            node->expType = strdup(node->children[1]->expType);  
        }
        else if(strcmp(node->expType,"ExpressionIntInt")==0){ //operacoes binarias que so funcionam se os dois lados forem ints
            node->expType = strdup("int");
            //Erro: se um dos filhos for double  
        }
        else if(strcmp(node->expType,"Expression1")==0){ //operacoes so com um membro (positivo, negativo, call)
            node->expType = strdup(node->children[0]->expType);  
        }

    } else {
        for(int i = 0; i < node->n_children; i++){
            add_type_to_expressions(node->children[i],table);
        }
    }
}