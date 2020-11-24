#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
typedef struct _ast_Node *AST_Node;


typedef struct _t1{
	char name[32];
	char type[32];
	int nparam;
	char **tparam;
	struct _t1 *next;
} table_element;

table_element *insert_el(table_element * target, char *str, char* t, int nparam, char** taparam);
table_element *search_el(table_element * target, char *str);
void print_global_table(table_element *target);
table_element *create_global_table(AST_Node root);
void free_table(table_element* root);
#endif
