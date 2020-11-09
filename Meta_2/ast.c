//
// Created by GU502GW on 08/11/2020.
//

#include "ast.h"
AST_Node create_node(char *token) { //TODO n_linha e n_coluna
    AST_Node new_node = calloc(1, sizeof(struct _ast_Node));
    new_node->token = strdup(token);
    return new_node;
}

void add_child(AST_Node target, AST_Node child) {
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
}

void free_AST(AST_Node root) {
    for (int i = 0; i < root->n_children; i++) {
        free_AST(root->children[i]);
    }
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