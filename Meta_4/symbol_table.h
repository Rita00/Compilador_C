#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "FunctionTable.h"


typedef struct _t1 {
    char *name;
    char *type;
    int nparam;
    char **tparam;
    int isDefined; //0 -> funcdeclaration	1-> definicao
    struct _t1 *next;
    functionsList table;
} table_element;

char
insert_el(table_element **target, char *name, char *type, int nparam, char **tparam, int isDefined, functionsList list,
          AST_Node node);

table_element *search_el(table_element *target, char *str);

char is_definition_of_declared(table_element *target, table_element *new, AST_Node node);

void print_global_table(table_element *target);

table_element *create_global_table(AST_Node root);

void free_table(table_element *root);

void search_for_declaration(AST_Node node, table_element *table, char *functionName);

void add_type_to_expressions(AST_Node node, table_element *table, char *currentFunc);

void fix_call(AST_Node node);

char get_type_size(char *type);

char *decide_highest_type(char *type1, char *type2);

void *decice_logical_op(char *type);

#endif
