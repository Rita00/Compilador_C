//
// Created by GU502GW on 08/11/2020.
//

#ifndef UNTITLED_AST_H
#define UNTITLED_AST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _ast_Node *AST_Node;

struct _ast_Node {
    char *token;
    int n_children;
    AST_Node *children; // array dinamico que guarda os nós filhos
    AST_Node parent;
    char *expType;
    int nparam;
    char** tparam;
    int n_linha;
    int n_coluna;
};

AST_Node create_node(char *token, int n_linha, int n_coluna);

AST_Node create_literal_node(char *token, char * content, int n_linha, int n_coluna);

void add_child(AST_Node target, AST_Node child);

void prepend_child(AST_Node root, AST_Node child, int n_linha, int n_coluna);

void free_AST(AST_Node root);

void destroy_node(AST_Node root);

void print_AST(AST_Node root, int n_tabs);

void print_AST2(AST_Node root, int n_tabs);

#endif //UNTITLED_AST_H
