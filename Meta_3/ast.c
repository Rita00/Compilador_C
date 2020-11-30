#include "ast.h"
AST_Node create_node(char *token, int n_linha, int n_coluna) {
    AST_Node new_node = calloc(1, sizeof(struct _ast_Node));
    new_node->token = strdup(token);
    new_node->n_linha = n_linha;
    new_node->n_coluna = n_coluna;
    return new_node;
}

AST_Node create_literal_node(char *token, char * content, int n_linha, int n_coluna){
    char aux[10000];
    sprintf(aux, "%s(%s)", token, content);
    free(content);
    return create_node(aux, n_linha, n_coluna);
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

void prepend_child(AST_Node root, AST_Node child, int n_linha, int n_coluna){ //resolver frees
     for(int i = 0; i < root->n_children; i++) {
        AST_Node new_child = create_node(child->token, n_linha, n_coluna);
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
    //TODO fix this
    for (int i = 0; i < root->n_children; i++) {
        free_AST(root->children[i]);
    }
    free(root->expType);
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
    if(root->expType && root->expType != NULL){
        if(root->nparam==0){
            printf("%s - %s\n", root->token, root->expType);
        }
        else{
            char params[32 * root->nparam];
            strcpy(params, root->tparam[0]);
            for (int i = 1; i < root->nparam; i++) {
                sprintf(params, "%s,%s", params, root->tparam[i]);
            }
            printf("%s - %s(%s)\n", root->token, root->expType, params);
        }
    }
    else{
      printf("%s\n", root->token);  
    }
    for (int i = 0; i < root->n_children; i++) {
        print_AST2(root->children[i], n_tabs + 1);
    }
}