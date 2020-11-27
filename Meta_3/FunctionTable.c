#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "FunctionTable.h"

void lowerString(char *str);

functionsList search_locals(functionsList list, AST_Node node) {
    if (strcmp(node->token, "Declaration") == 0) {
        char *aux_variavel = node->children[1]->token;
        char *id_variavel = (char *) calloc(strlen(aux_variavel) - 3, sizeof(char));
        strncpy(id_variavel, aux_variavel + 3, strlen(aux_variavel) - 4);
        list = addVariable(id_variavel, node->children[0]->token, 0, list);
    } else {
        for(int i = 0; i < node->n_children; i++){
            list = search_locals(list, node->children[i]);
        }
    }
    return list;
}

functionsList create_TableNode(char *varName, char *varType, char isParam) {
    functionsList new_node = calloc(1, sizeof(struct functions));
    new_node->variable = strdup(varName);
    new_node->type = strdup(varType);
    lowerString(new_node->type);
    new_node->isParam = isParam;
    return new_node;
}

functionsList addVariable(char *varName, char *varType, char isParam, functionsList list) {
    functionsList aux;
    if (list == NULL) {
        list = create_TableNode(varName, varType, isParam);
    } else {
        aux = list;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = create_TableNode(varName, varType, isParam);
    }
    return list;
}

void freeFunctionsList(functionsList list) {
    functionsList aux;
    while (list != NULL) {
        free(list->variable);
        free(list->type);
        aux = list;
        list = list->next;
        free(aux);
    }
}

void printFunctionsList(functionsList list, char *name) {
    printf("===== Function %s Symbol Table =====\n", name);
    while (list != NULL) {
        if (list->isParam) {
            printf("%s\t%s\tparam\n", list->variable, list->type);
        } else {
            printf("%s\t%s\n", list->variable, list->type);
        }
        list = list->next;
    }
}