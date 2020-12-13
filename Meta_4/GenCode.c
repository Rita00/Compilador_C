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
    char *id = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
    strncpy(id, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
    char *type = defineType(node->children[0]->token);
    if (node->n_children < 3)
        printf("@%s = common global %s 0\n", id, type);
    else {
        char *value = (char *) calloc(strlen(node->children[2]->token) - 7, sizeof(char));
        strncpy(value, node->children[2]->token + 7, strlen(node->children[2]->token) - 8);
        printf("@%s = global %s %s\n", id, type, value);
        free(value);
    }
    free(id);
    free(type);
}

void caseFuncDef(AST_Node node) {
    char *id = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
    strncpy(id, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
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
        char *id = (char *) calloc(strlen(paraDec->children[1]->token) - 3, sizeof(char));
        strncpy(id, paraDec->children[1]->token + 3, strlen(paraDec->children[1]->token) - 4);
        printf("\t%%%d = alloca %s, align 4\n", i + 1, type);
        printf("\tstore %s %%%s, %s* %%%d, align 4\n", type, id, type, i + 1);
    }
}

char *caseParamList(AST_Node node) {
    char *res;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        if (paraDec->n_children > 1) {
            char *type = defineType(paraDec->children[0]->token);
            char *id = (char *) calloc(strlen(paraDec->children[1]->token) - 3, sizeof(char));
            strncpy(id, paraDec->children[1]->token + 3, strlen(paraDec->children[1]->token) - 4);
            if (i == 0){
                res = (char *) calloc(strlen(res) + strlen(type), +strlen(id) + sizeof(char) + node->n_children - 1);
                sprintf(res, "%s %s", type, id);
            } else{
                char *aux = (char *) calloc(strlen(res) + strlen(type), +strlen(id) + sizeof(char) + node->n_children - 1);
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
    }
}

void caseDeclLocal(AST_Node node) {
    char *type = defineType(node->children[0]->token);
    char *id = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
    strncpy(id, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
    printf("\t%%%s = alloca %s, align 4\n", id, type);
    if (node->n_children == 3) {
        caseStoreLocal(node);
    }
    free(type);
    free(id);
}

void caseStoreLocal(AST_Node node) {
    char *type = defineType(node->children[0]->token);
    char *id = (char *) calloc(strlen(node->children[1]->token) - 3, sizeof(char));
    strncpy(id, node->children[1]->token + 3, strlen(node->children[1]->token) - 4);
    char *value = (char *) calloc(strlen(node->children[2]->token) - 7, sizeof(char));
    strncpy(value, node->children[2]->token + 7, strlen(node->children[2]->token) - 8);
    printf("\tstore %s %s, %s* %%%s, align 4\n", type, value, type, id);
    free(id);
    free(value);
    free(type);
}

char *defineType(char *type) {
    if (strcmp(type, "Double") == 0) return strdup("double");
    else return strdup("i32");
}
