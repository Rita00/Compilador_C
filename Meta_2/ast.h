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
    //TODO n_linha e n_coluna
};

AST_Node create_node(char *token);

void add_child(AST_Node target, AST_Node child);

void free_AST(AST_Node root);

void print_AST(AST_Node root, int n_tabs);

#endif //UNTITLED_AST_H