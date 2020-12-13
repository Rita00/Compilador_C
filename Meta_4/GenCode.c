#include "symbol_table.h"
#include "GenCode.h"


void treatuppernodes(AST_Node root) {
    if (strcmp(root->token, "Declaration") == 0) {
        caseDeclGlobal(root);
    } else if (strcmp(root->token, "FuncDefinition") == 0) {
        caseFuncDef(root);
        genCodeFuncBody(root->children[3]);
    }
}

void genCode(AST_Node root) {
    printf("declare i32 @getchar()\n");
    printf("declare i32 @putchar(i32)\n");
    for (int i = 0; i < root->n_children; i++) {
        treatuppernodes(root->children[i]);
    }
}

void caseDeclGlobal(AST_Node node) {
    char *id = getLiteral(node->children[1]->token);
    char *type = defineType(node->children[0]->token);
    if (node->n_children < 3)
        printf("@%s = common global %s 0\n", id, type);
    else {
        char *value = getLiteral(node->children[2]->token);
        printf("@%s = global %s %s\n", id, type, value);
        free(value);
    }
    free(id);
    free(type);
}

void caseFuncDef(AST_Node node) {
    char *id = getLiteral(node->children[1]->token);
    char *type = defineType(node->children[0]->token);
    char *param_list = caseParamList(node->children[2]);
    if (param_list != NULL) {
        printf("Define %s @%s (%s) #0\n", type, id, param_list);
        genParamList(node->children[2]);
    } else printf("Define %s @%s () #0\n", type, id);

    free(type);
    free(param_list);
    free(id);
}

void genParamList(AST_Node node) {
    char *type;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        type = defineType(paraDec->children[0]->token);
        char *id = getLiteral(paraDec->children[1]->token);
        printf("\t%%%d = alloca %s, align 4\n", i + 1, type);
        printf("\tstore %s %%%s, %s* %%%d, align 4\n", type, id, type, i + 1);
    }
}

char *caseParamList(AST_Node node) {
    char *res = NULL;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        if (paraDec->n_children > 1) {
            char *type = defineType(paraDec->children[0]->token);
            char *id = getLiteral(paraDec->children[1]->token);
            if (i == 0){
                res = (char *) calloc(strlen(type) + strlen(id) + 1, 1);
                sprintf(res, "%s %s", type, id);
            } else{
                char *aux = (char *) calloc(strlen(res) + strlen(type) + strlen(id) + 3, 1);
                sprintf(aux, "%s, %s %s", res, type, id);
                free(res);
                res = aux;
            }
            free(id);
            free(type);
        } else {
            return NULL;
        }
    }
    return res;
}

void genCodeFuncBody(AST_Node node) {

    for (int i = 0; i < node->n_children; i++) {
        genCodeFuncBody(node->children[i]);
    }
    //tratar este no TODO
    if (strcmp(node->token, "Declaration") == 0) {
        caseDeclLocal(node);
    } else if (strcmp(node->token, "Store") == 0) {
        //caseStoreLocal(node);
    }
}

void caseDeclLocal(AST_Node node) {
    char *type = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[1]->token);
    printf("\t%%%s = alloca %s, align 4\n", id, type);
    if (node->n_children == 3) {
        char *value = getLiteral(node->children[2]->token);
        printf("\tstore %s %s, %s* %%%s, align 4\n", type, value, type, id); // TODO Verificar se align é 4 ou 8
        free(value);
    }
    free(type);
    free(id);
}

void caseStoreLocal(AST_Node node) {
    char *type = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[1]->token);
    char *value = getLiteral(node->children[2]->token);
    printf("\tstore %s %s, %s* %%%s, align 4\n", type, value, type, id); // TODO Verificar se align é 4 ou 8
    free(id);
    free(value);
    free(type);
}

char* getLiteral(char *literal) {
    int size;
    if (strncmp(literal, "IntLit", strlen("IntLit")) == 0) {
        size = strlen("IntLit");
    } else if (strncmp(literal, "ChrLit", strlen("ChrLit")) == 0) {
        size = strlen("ChrLit");
    } else if (strncmp(literal, "RealLit", strlen("RealLit")) == 0) {
        size = strlen("RealLit");
    } else {
        size = strlen("Id");
    }
    char *value = (char *) calloc(strlen(literal) - size - 1, sizeof(char));
    strncpy(value, literal + size + 1, strlen(literal) - size - 2);
    return value;
}



char *defineType(char *type) {
    if (strcmp(type, "Double") == 0 || strcmp(type, "double") == 0) return strdup("double");
    else return strdup("i32");
}
