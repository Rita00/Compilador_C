#include "symbol_table.h"
#include "GenCode.h"

void treatuppernodes(AST_Node root) {
    if (strcmp(root->token, "Declaration") == 0) {
        caseDeclGlobal(root);
    } else if (strcmp(root->token, "FuncDefinition") == 0) {
        caseFuncDef(root);
        genCodeFuncBody(root->children[3], root->children[2]);
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
    char **ArrayType = defineType(node->children[0]->token);
    if (node->n_children < 3)
        printf("@%s = common global %s 0\n", id, ArrayType[0]);
    else {
        char *value = getLiteral(node->children[2]->token);
        printf("@%s = global %s %s\n", id, ArrayType[0], value);
        free(value);
    }
    free(id);
    freeArrayDefType(ArrayType);
}

void caseFuncDef(AST_Node node) {
    char *id = getLiteral(node->children[1]->token);
    char **ArrayType = defineType(node->children[0]->token);
    char *param_list = caseParamList(node->children[2]);
    if (param_list != NULL) {
        printf("Define %s @%s (%s) #0\n", ArrayType[0], id, param_list);
        genParamList(node->children[2]);
    } else printf("Define %s @%s () #0\n", ArrayType[0], id);

    freeArrayDefType(ArrayType);
    free(param_list);
    free(id);
}

void genParamList(AST_Node node) {
    char **ArrayType;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        ArrayType = defineType(paraDec->children[0]->token);
        char *id = getLiteral(paraDec->children[1]->token);
        printf("\t%%%d = alloca %s, align %s\n", i + 1, ArrayType[0], ArrayType[1]);
        printf("\tstore %s %%%s, %s* %%%d, align %s\n", ArrayType[0], id, ArrayType[0], i + 1, ArrayType[1]);
        freeArrayDefType(ArrayType);
    }
}

char *caseParamList(AST_Node node) {
    char *res = NULL;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        if (paraDec->n_children > 1) {
            char **ArrayType = defineType(paraDec->children[0]->token);
            char *id = getLiteral(paraDec->children[1]->token);
            if (i == 0) {
                res = (char *) calloc(strlen(ArrayType[0]) + strlen(id) + 2, 1);
                sprintf(res, "%s %s", ArrayType[0], id);
            } else {
                char *aux = (char *) calloc(strlen(res) + strlen(ArrayType[0]) + strlen(id) + 4, 1);
                sprintf(aux, "%s, %s %s", res, ArrayType[0], id);
                free(res);
                res = aux;
            }
            free(id);
            freeArrayDefType(ArrayType);
        } else {
            return NULL;
        }
    }
    return res;
}

void genCodeFuncBody(AST_Node node, AST_Node paramListNode) {

    for (int i = 0; i < node->n_children; i++) {
        genCodeFuncBody(node->children[i], paramListNode);
    }
    //tratar este no TODO
    if (strcmp(node->token, "Declaration") == 0) {
        caseDeclLocal(node);
    } else if (strcmp(node->token, "Store") == 0) {
        caseStoreLocal(node, paramListNode);
    }
}

void caseDeclLocal(AST_Node node) {
    char **ArrayType = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[1]->token);
    printf("\t%%%s = alloca %s, align %s\n", id, ArrayType[0], ArrayType[1]);
    if (node->n_children == 3) {
        char *value = getLiteral(node->children[2]->token);
        printf("\tstore %s %s, %s* %%%s, align %s\n", ArrayType[0], id, ArrayType[0], id, ArrayType[1]);
        free(value);
    }
    freeArrayDefType(ArrayType);
    free(id);
}

void caseStoreLocal(AST_Node node, AST_Node paramListNode) {
    char **ArrayType = defineType(node->children[0]->expType);
    char *id = getLiteral(node->children[1]->token);
    if (id != NULL) {
        int res = isParam(node->children[0], paramListNode);
        if (res)
            printf("\tstore %s %s, %s* %%%d, align %s\n", ArrayType[0], id, ArrayType[0], res, ArrayType[1]);
        else {
            char *value = getLiteral(node->children[0]->token);
            printf("\tstore %s %s, %s* %%%s, align %s\n", ArrayType[0], id, ArrayType[0], value, ArrayType[1]);
        }
        free(id);
    }
    freeArrayDefType(ArrayType);
}

int isParam(AST_Node node, AST_Node paramListNode) {
    int id;
    for (int i = 0; i < paramListNode->n_children; i++) {
        AST_Node paramDec = paramListNode->children[i];
        if (strcmp(node->token, paramDec->children[1]->token) == 0) {
            id = i + 1;
            return id;
        }
    }
    return 0;
}

char *getLiteral(char *literal) {
    int size;
    if (strncmp(literal, "IntLit", strlen("IntLit")) == 0) {
        size = strlen("IntLit");
    } else if (strncmp(literal, "ChrLit", strlen("ChrLit")) == 0) {
        size = strlen("ChrLit");
    } else if (strncmp(literal, "RealLit", strlen("RealLit")) == 0) {
        size = strlen("RealLit");
    } else if (strncmp(literal, "Id", strlen("Id")) == 0) {
        size = strlen("Id");
    } else return NULL;
    char *value = (char *) calloc(strlen(literal) - size - 1, sizeof(char));
    strncpy(value, literal + size + 1, strlen(literal) - size - 2);
    return value;
}

char **defineType(char *type) {
    char **res = calloc(sizeof(char *), 2);
    if (strcmp(type, "Double") == 0 || strcmp(type, "double") == 0) {
        res[0] = strdup("double");
        res[1] = strdup("8");
        return res;
    } else {
        res[0] = strdup("i32");
        res[1] = strdup("4");
        return res;
    }
}

void freeArrayDefType(char **array) {
    free(array[0]);
    free(array[1]);
    free(array);
}