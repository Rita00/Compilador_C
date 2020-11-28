#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "symbol_table.h"

void lowerString(char *str);

//Insere um novo identificador na cauda de uma lista ligada de simbolo
//return 0 on error
char
insert_el(table_element **target, char *name, char *type, int nparam, char **tparam, int isDefined, functionsList list,
          AST_Node node) {
    table_element *aux = search_el(*target, name) ;
    if(aux != NULL && aux->isDefined) {
        printf("Line %d, col %d: Symbol %s already defined\n", node->children[1]->n_linha, node->children[1]->n_coluna, name);
        return 0;
    }
    table_element *newSymbol = (table_element *) calloc(1, sizeof(table_element));
    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    lowerString(newSymbol->type);
    newSymbol->nparam = nparam;
    newSymbol->tparam = tparam;
    newSymbol->isDefined = isDefined;
    newSymbol->table = list;
    if (*target == NULL) {
        *target = newSymbol;
        return 1;
    }

    for (aux = *target; aux; aux = aux->next) {
        if (!strcmp(aux->name, name)) {
            if (is_definition_of_declared(aux, newSymbol, node)) {
                aux->table = list;
                aux->isDefined = 1;
                free(newSymbol->name);
                free(newSymbol->type);
                for (int i = 0; i < newSymbol->nparam; i++) {
                    free(newSymbol->tparam[i]);
                }
                free(newSymbol->tparam);
                return 1;
            } else {
                if (strcmp(aux->type, newSymbol->type) != 0) {
                    printf("Line %d, col %d: Conflicting types (got %s, expected %s)\n", node->n_linha, node->n_coluna,
                           newSymbol->type, aux->type);
                    return 0;
                }
                for (int i = 0; i < aux->nparam; i++) {
                    if (strcmp(aux->tparam[i], newSymbol->tparam[i]) != 0) {
                        printf("Line %d, col %d: Conflicting types (got %s, expected %s)\n", node->n_linha,
                               node->n_coluna, newSymbol->tparam[i], aux->tparam[i]);
                        return 0;
                    }
                }
                return 0;
            }
        }
        if (aux->next == NULL) {
            aux->next = newSymbol;
            return 1;
        }
    }
    return 1;
}

char is_definition_of_declared(table_element *target, table_element *new, AST_Node node) {
    if (target->isDefined) {//target tem que ser declaration
        return 0;
    }
    if (target->nparam == 0) return 0; //target tem que ser função
    if (strcmp(target->type, new->type) != 0) return 0; //target tem que devolver mesmo tipo que new
    if (target->nparam != new->nparam) {
        printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)", node->n_linha,
               node->n_coluna, new->name, new->nparam, target->nparam);
        return 0; //target tem que ter mesmo numero de parametros que new
    }
    //target tem que ter parametros iguais a new
    for (int i = 0; i < target->nparam; i++) {
        if (strcmp(target->tparam[i], new->tparam[i]) != 0) return 0;
    }
    return 1;
}

void print_global_table(table_element *target) {
    table_element *aux;
    printf("===== Global Symbol Table =====\n");
    for (aux = target; aux; aux = aux->next) {
        if (aux->nparam == 0) {
            printf("%s\t%s\n", aux->name, aux->type);
        } else {
            char params[32 * aux->nparam];
            strcpy(params, aux->tparam[0]);
            for (int i = 1; i < aux->nparam; i++) {
                sprintf(params, "%s,%s", params, aux->tparam[i]);
            }
            printf("%s\t%s(%s)\n", aux->name, aux->type, params);
        }
    }
    printf("\n");
    for (aux = target; aux; aux = aux->next) {
        if (aux->isDefined) {
            printFunctionsList(aux->table, aux->name);
            printf("\n");
        }
    }
}

//Procura um identificador, devolve 0 caso nao exista
table_element *search_el(table_element *target, char *str) {
    table_element *aux;
    for (aux = target; aux; aux = aux->next)
        if (strcmp(aux->name, str) == 0)
            return aux;

    return NULL;
}

table_element *create_global_table(AST_Node root) {
    table_element *table = NULL;
    char error; //verificar valor de variavel para decidir se devemos imprimir tabela
    char **aux_params = calloc(sizeof(char *), 1);
    aux_params[0] = strdup("int");
    error = insert_el(&table, "putchar", "int", 1, aux_params, 0, NULL, root);
    aux_params = calloc(sizeof(char *), 1);
    aux_params[0] = strdup("void");
    error = insert_el(&table, "getchar", "int", 1, aux_params, 0, NULL, root);

    for (int i = 0; i < root->n_children; i++) {
        AST_Node FuncDe = root->children[i];
        if (strcmp(FuncDe->token, "FuncDefinition") == 0 || (strcmp(FuncDe->token, "FuncDeclaration") == 0)) {
            functionsList list = NULL;
            int isDefined;
            char *aux = FuncDe->children[1]->token;
            char *id = (char *) calloc(strlen(aux) - 3, sizeof(char));
            strncpy(id, aux + 3, strlen(aux) - 4);
            AST_Node paramlist = FuncDe->children[2];
            if (strcmp(FuncDe->token, "FuncDefinition") == 0) {
                isDefined = 1;
                list = addVariable("return", FuncDe->children[0]->token, 0, list, FuncDe->children[0]);
                for (int j = 0; j < paramlist->n_children; j++) {
                    AST_Node paramDeclaration = paramlist->children[j];
                    if (paramDeclaration->n_children > 1) {
                        char *aux_variavel = paramDeclaration->children[1]->token;
                        char *id_variavel = (char *) calloc(strlen(aux_variavel) - 3, sizeof(char));
                        strncpy(id_variavel, aux_variavel + 3, strlen(aux_variavel) - 4);
                        list = addVariable(id_variavel, paramDeclaration->children[0]->token, 1, list, paramDeclaration->children[0]);
                        free(id_variavel);
                    }

                }
                list = search_locals(list, FuncDe->children[3]);
            } else {
                isDefined = 0;
            }
            char **tparams = calloc(paramlist->n_children, sizeof(char *));
            for (int j = 0; j < paramlist->n_children; j++) {
                AST_Node paramDeclaration = paramlist->children[j];
                tparams[j] = strdup(paramDeclaration->children[0]->token);
                lowerString(tparams[j]);
            }
            if (paramlist->n_children > 1) {
                for (int j = 0; j < paramlist->n_children; j++) {
                    if (strcmp(paramlist->children[j]->children[0]->token, "Void") == 0)
                        printf("Line %d, col %d: Invalid use of void type in declaration\n",
                               paramlist->children[j]->children[0]->n_linha,
                               paramlist->children[j]->children[0]->n_coluna);
                }
            }
            error = insert_el(&table, id, FuncDe->children[0]->token, paramlist->n_children, tparams, isDefined, list,
                              root->children[0]);
            free(id);
        } else if (strcmp(FuncDe->token, "Declaration") == 0) {
            char *aux = FuncDe->children[1]->token;
            char *id = (char *) calloc(strlen(aux) - 3, sizeof(char));
            strncpy(id, aux + 3, strlen(aux) - 4);
            error = insert_el(&table, id, root->children[i]->children[0]->token, 0, NULL, 0, NULL, root->children[i]);
            free(id);
            if (strcmp(FuncDe->children[0]->token, "Void") == 0)
                printf("Line %d, col %d: Invalid use of void type in declaration\n", FuncDe->children[0]->n_linha,
                       FuncDe->children[0]->n_coluna);

        }
    }
    return table;
}

void free_table(table_element *root) {
    while (root != NULL) {
        free(root->type);
        free(root->name);
        for (int i = 0; i < root->nparam; i++) {
            free(root->tparam[i]);
        }
        free(root->tparam);
        table_element *aux = root;
        root = root->next;
        free(aux);
    }
}

void search_for_declaration(AST_Node node, table_element *table, char *functionName) {
    char *id = (char *) calloc(strlen(node->token) - 3, sizeof(char));
    strncpy(id, node->token + 3, strlen(node->token) - 4);
    table_element *aux;
    node->nparam = 0;
    if(functionName != NULL){
        functionsList locals_table = search_el(table, functionName)->table;
        functionsList aux2 = locals_table;
        while (aux2 != NULL) {
            if (strcmp(id, aux2->variable) == 0) {
                node->expType = strdup(aux2->type);
                return;
            }
            aux2 = aux2->next;
        }
    }

    for (aux = table; aux; aux = aux->next) {
        if (strcmp(id, aux->name) == 0) { // caso id seja este nome da tabela
            node->expType = strdup(aux->type);
            if (aux->nparam > 0) {
                node->tparam = aux->tparam;
                node->nparam = aux->nparam;
            }
            return;
        }
    }
    printf("Line %d, col %d: Unknown symbol %s\n", node->n_linha, node->n_coluna, id);
    node->expType = strdup("undef");
}

void add_type_to_expressions(AST_Node node, table_element *table, char *currentFunc) {
    if (!strcmp(node->token, "FuncDefinition")) {
        if (currentFunc != NULL) free(currentFunc);
        currentFunc = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
        strncpy(currentFunc, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
    }
    for (int i = 0; i < node->n_children; i++) {
        add_type_to_expressions(node->children[i], table, currentFunc);
    }
    if (node->expType && strncmp(node->expType, "Expression", strlen("Expression")) == 0) {
        if (strcmp(node->expType, "ExpressionId") == 0) { //procura declarations
            char *id = (char *) calloc(strlen(node->token) - 3, sizeof(char));
            strncpy(id, node->token + 3, strlen(node->token) - 4);
            search_for_declaration(node, table, currentFunc);
        } else if (strcmp(node->expType, "ExpressionArit") ==
                   0) { //operacoes aritmeticas binarias (ex: int + double = double)
            node->expType = decide_highest_type(node->children[0]->expType, node->children[1]->expType);
            if (strcmp(decide_highest_type(node->children[0]->expType, node->children[1]->expType), "double") == 0) {
                    printf("Line %d, col %d: Conflicting types (got double, expected int)\n", node->n_linha, node->n_coluna);
            }
        } else if (strcmp(node->expType, "ExpressionR") ==
                   0) { //operacoes binarias que ficam com o valor da esquerda (igual e virgula)
            int index = 0;
            free(node->expType);
            if (!strcmp(node->token, "Comma")) index = 1;
            node->expType = strdup(node->children[index]->expType);
            if (index == 0 && strncmp(node->children[0]->token, "Id", strlen("Id")) != 0) { //TODO what if it is an ID, but not a declared one
                printf("Line %d, col %d: Lvalue required\n", node->children[0]->n_linha, node->children[0]->n_coluna);
            } else if (index == 0 && strcmp(node->children[0]->expType, "double") != 0 &&
                       strcmp(node->children[1]->expType, "double") == 0) { //TODO tenho duvidas
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->n_linha,
                       node->n_coluna, "=", node->children[0]->expType, node->children[1]->expType);
            } else if (strcmp(decide_highest_type(node->children[0]->expType, node->children[1]->expType), "double") ==
                       0) {
                printf("Line %d, col %d: Conflicting types (got double, expected int)\n", node->n_linha,
                       node->n_coluna);
            }
        } else if (strcmp(node->expType, "ExpressionIntInt") ==
                   0) { //operacoes binarias que so funcionam se os dois lados forem ints
            free(node->expType);
            node->expType = strdup("int");
            if (strcmp(decide_highest_type(node->children[0]->expType, node->children[1]->expType), "double") == 0)
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->n_linha,
                       node->n_coluna, decice_logical_op(node->token), node->children[0]->expType,
                       node->children[1]->expType);
            //Erro: se um dos filhos for double  
        } else if (strcmp(node->expType, "Expression1") == 0) { //operacoes so com um membro (positivo, negativo, call)
            free(node->expType);
            node->expType = strdup(node->children[0]->expType);
            if (strcmp(node->children[0]->expType, "double") == 0)
                printf("Line %d, col %d: Conflicting types (got double, expected int)\n", node->n_linha,
                       node->n_coluna);
        } else if (strcmp(node->expType, "ExpressionLogical") == 0) {
            free(node->expType);
            node->expType = strdup("int");
            if (node->n_children == 2 &&
                strcmp(decide_highest_type(node->children[0]->expType, node->children[1]->expType), "void") == 0) {
                printf("Line %d, col %d: Conflicting types (got void, expected int)\n", node->n_linha, node->n_coluna);
            }
        } else if (strcmp(node->expType, "ExpressionCall") == 0) {
            free(node->expType);
            char *id = (char *) calloc(strlen(node->children[0]->token) - 3, sizeof(char));
            strncpy(id, node->children[0]->token + 3, strlen(node->children[0]->token) - 4);
            table_element *aux = search_el(table, id);
            if (aux && aux->nparam > 0) {
                int required = aux->nparam;
                int got = node->n_children - 1;
                if (required != got && !(got == 0 && required == 1 && strcmp(aux->tparam[0], "void") == 0)) {
                    printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)\n", node->children[0]->n_linha, node->children[0]->n_coluna, id, got, required);
                }
                node->expType = strdup(aux->type);


            } else {
                printf("Line %d, col %d: Symbol %s is not a function\n", node->children[0]->n_linha,
                       node->children[0]->n_coluna, id);
                node->expType = strdup("undef");
            }
        }
    }
}


char get_type_size(char *type) {
    if (!strcmp(type, "char")) return 0;
    if (!strcmp(type, "short")) return 1;
    if (!strcmp(type, "int")) return 2;
    if (!strcmp(type, "double")) return 3;
    return 4;
}

char *decide_highest_type(char *type1, char *type2) {
    if (get_type_size(type1) > get_type_size(type2))
        return strdup(type1);
    return strdup(type2);
}

void *decice_logical_op(char *type) {
    if (strcmp(type, "Or") == 0) return strdup("||");
    if (strcmp(type, "And") == 0) return strdup("&&");
    if (strcmp(type, "Mod") == 0) return strdup("%");
    if (strcmp(type, "BitWiseAnd") == 0) return strdup("&");
    if (strcmp(type, "BitWiseOr") == 0) return strdup("|");
    if (strcmp(type, "BitWiseXor") == 0) return strdup("^");
    return NULL;
}
