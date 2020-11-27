#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "symbol_table.h"

void lowerString(char* str);
//Insere um novo identificador na cauda de uma lista ligada de simbolo
//return 0 on error
char insert_el(table_element **target, char *name, char *type, int nparam, char **tparam, int isDefined, functionsList list) {
    table_element *newSymbol = (table_element *) calloc(1, sizeof(table_element));
    table_element *aux;

    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    lowerString(newSymbol->type);
    newSymbol->nparam = nparam;
    newSymbol->tparam = tparam;
    newSymbol->isDefined = isDefined;
    newSymbol->table = list;
    if(*target == NULL) {
        *target = newSymbol;
        return 1;
    }

    for(aux = *target; aux; aux = aux->next){
        if (!strcmp(aux->name, name)){
            if(is_definition_of_declared(aux, newSymbol)){
                aux->table = list;
                aux->isDefined = 1;
                free(newSymbol->name);
                free(newSymbol->type);
                for(int i = 0; i < newSymbol->nparam; i++){
                    free(newSymbol->tparam[i]);
                }
                free(newSymbol->tparam);
                return 1;
            }else{
                printf("Erro de bla bla\n");
                return 0;
            }
        }
        if(aux->next == NULL){
            aux->next = newSymbol;
            return 1;
        }
    }
    return 1;
}

char is_definition_of_declared(table_element *target, table_element *new){
    if(target->isDefined){//target tem que ser declaration
        return 0;
    }
    if(target->nparam == 0) return 0; //target tem que ser função
    if(strcmp(target->type, new->type) != 0) return 0; //target tem que devolver mesmo tipo que new
    if(target->nparam != new->nparam) return 0; //target tem que ter mesmo numero de parametros que new
    //target tem que ter parametros iguais a new
    for(int i = 0; i < target->nparam; i++){
        if(strcmp(target->tparam[i], new->tparam[i]) != 0) return 0;
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
        if (aux->isDefined){
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
    char **aux_params = calloc(sizeof(char*), 1);
    aux_params[0] = strdup("int");
    error = insert_el(&table, "putchar", "int", 1, aux_params, 0, NULL);
    aux_params = calloc(sizeof(char*), 1);
    aux_params[0] = strdup("void");
    error = insert_el(&table, "getchar", "int", 1, aux_params, 0, NULL);

    for (int i = 0; i < root->n_children; i++) {
        AST_Node FuncDe = root->children[i];
        if (strcmp(FuncDe->token, "FuncDefinition") == 0 || (strcmp(FuncDe->token, "FuncDeclaration") == 0)) {
            functionsList list = NULL;
            int isDefined;
            char *aux = FuncDe->children[1]->token;
            char *id = (char *) calloc(strlen(aux) - 3, sizeof(char));
            strncpy(id, aux + 3, strlen(aux) - 4);
            AST_Node paramlist = FuncDe->children[2];
            if (strcmp(FuncDe->token, "FuncDefinition") == 0){
                isDefined = 1;
                list = addVariable("return", FuncDe->children[0]->token, 0, list);
                for (int j = 0; j < paramlist->n_children; j++) {
                    AST_Node paramDeclaration = paramlist->children[j];
                    if (paramDeclaration->n_children > 1){
                        char *aux_variavel = paramDeclaration->children[1]->token;
                        char *id_variavel = (char *) calloc(strlen(aux_variavel) - 3, sizeof(char));
                        strncpy(id_variavel, aux_variavel + 3, strlen(aux_variavel) - 4);
                        list = addVariable(id_variavel, paramDeclaration->children[0]->token, 1, list);
                        free(id_variavel);
                    }

                }
                //TODO search for variables in function body
                list = search_locals(list, FuncDe->children[3]);
            } else{
                isDefined = 0;
            }
            char **tparams = calloc(paramlist->n_children, sizeof(char *));
            for (int j = 0; j < paramlist->n_children; j++) {
                AST_Node paramDeclaration = paramlist->children[j];
                tparams[j] = strdup(paramDeclaration->children[0]->token);
                lowerString(tparams[j]);
            }
            error = insert_el(&table, id, FuncDe->children[0]->token, paramlist->n_children, tparams, isDefined, list);
            free(id);
        } else if (strcmp(FuncDe->token, "Declaration") == 0) {
            char *aux = FuncDe->children[1]->token;
            char *id = (char *) calloc(strlen(aux) - 3, sizeof(char));
            strncpy(id, aux + 3, strlen(aux) - 4);
            error = insert_el(&table, id, root->children[i]->children[0]->token, 0, NULL, 0, NULL);
            free(id);
        }
    }
    return table;
}

void free_table(table_element *root) {
    while(root != NULL){
        free(root->type);
        free(root->name);
        for (int i = 0; i < root->nparam; i++){
            free(root->tparam[i]);
        }
        free(root->tparam);
        table_element *aux = root;
        root = root->next;
        free(aux);
    }
}

void search_for_declaration(AST_Node node, table_element *table, char*functionName){
    char *id = (char *) calloc(strlen(node->token) - 3, sizeof(char));
    strncpy(id, node->token + 3, strlen(node->token) - 4);
    node->expType = strdup("undef");
    table_element *aux;
    int found = 0;
    node->nparam = 0;
    for (aux = table; aux; aux = aux->next) {
        if(aux->isDefined){
            if(strcmp(id,aux->name)==0){
                node->expType = strdup(aux->type);
                if(aux->nparam>0){
                    node->tparam = aux->tparam;
                    node->nparam = aux->nparam;
                }
                found = 1;
            }
            if (!strcmp(aux->name,functionName)){
                functionsList aux2 = aux->table;
                while (aux2 != NULL) {
                    if(strcmp(id,aux2->variable)==0){
                            node->expType = strdup(aux2->type);
                            found = 1;
                    }
                    aux2 = aux2->next;
                }
            }
        }
        else if(strcmp(id,aux->name)==0){
            node->expType = strdup(aux->type);
            if(aux->nparam>0){
                node->tparam = aux->tparam;
                node->nparam = aux->nparam;
            }
            found = 1;
        }
        
    } 
}
void add_type_to_expressions(AST_Node node, table_element *table, char * currentFunc) {
    if(!strcmp(node->token,"FuncDefinition")){
        currentFunc = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
        strncpy(currentFunc, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
    }
    for(int i = 0; i < node->n_children; i++){
        add_type_to_expressions(node->children[i],table, currentFunc);
    }
    if(node->expType && strncmp(node->expType,"Expression",strlen("Expression"))==0){
        if(strcmp(node->expType,"ExpressionId")==0){ //procura declarations
            char *id = (char *) calloc(strlen(node->token) - 3, sizeof(char));
            strncpy(id, node->token + 3, strlen(node->token) - 4);
            search_for_declaration(node,table,currentFunc); 
        }
        else if(strcmp(node->expType,"ExpressionArit")==0){ //operacoes aritmeticas binarias (ex: int + double = double) 
            if(strcmp(node->children[0]->expType,"double")==0 || strcmp(node->children[1]->expType,"double")==0){
                node->expType = strdup("double");  
            }
            else{
                node->expType = strdup("int");  
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
    }
}


