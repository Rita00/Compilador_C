#include "symbol_table.h"
#include "GenCode.h"
#include "vector.h"

void lowerString(char *str);

vector ArrayVarLocal;
int n_var = 0;

void genCodeFuncBody(AST_Node node, AST_Node paramListNode) {
    for (int i = 0; i < node->n_children; i++) {
        genCodeFuncBody(node->children[i], paramListNode);
    }

    char *aux = isArit(node);
    //tratar este no TODO
    if (aux) {
        caseArit(node, aux, paramListNode);
        free(aux);
        return;
    }
    aux = getLiteral(node->token, paramListNode);
    if (aux) {
        node->codeRef = aux;
    } else if (strcmp(node->token, "Declaration") == 0) {
        caseDeclLocal(node, paramListNode);
    } else if (strcmp(node->token, "Store") == 0) {
        caseStoreLocal(node);
    } else if (strcmp(node->token, "Call") == 0) {
        caseCall(node, paramListNode);
    } else if (strcmp(node->token, "Return") == 0) {
        caseReturn(node, paramListNode);
    }
}

void treatuppernodes(AST_Node root) {
    if (strcmp(root->token, "Declaration") == 0) {
        caseDeclGlobal(root);
    } else if (strcmp(root->token, "FuncDefinition") == 0) {
        caseFuncDef(root);
        genCodeFuncBody(root->children[3], root->children[2]);
        genFinalReturn(root->children[0]);
        printf("}\n\n");
        freeArray(&ArrayVarLocal);
        n_var = 0;
    }
}

void genCode(AST_Node root) {
    startArray(&ArrayVarLocal);
    printf("declare i32 @getchar()\n");
    printf("declare i32 @putchar(i32)\n");
    for (int i = 0; i < root->n_children; i++) {
        treatuppernodes(root->children[i]);
    }
}

void caseDeclGlobal(AST_Node node) {
    char *id = getLiteral(node->children[1]->token, NULL);
    char **ArrayType = defineType(node->children[0]->token);
    if (node->n_children < 3) {
        if (*ArrayType[1] == '4') {
            printf("@%s = common global %s 0, align %s\n", id, ArrayType[0], ArrayType[1]);
        } else {
            printf("@%s = common global %s 0.0, align %s\n", id, ArrayType[0], ArrayType[1]);
        }
    } else {
        char *value = getLiteral(node->children[2]->token, NULL);
        printf("@%s = global %s %s, align %s\n", id, ArrayType[0], value, ArrayType[1]);
        free(value);
    }
    free(id);
    freeArrayDefType(ArrayType);
}

void caseFuncDef(AST_Node node) {
    char *id = getLiteral(node->children[1]->token, NULL);
    char **ArrayType = defineType(node->children[0]->token);
    char *param_list = caseParamList(node->children[2]);
    if (param_list != NULL) {
        printf("define %s @%s (%s) #0 {\n", ArrayType[0], id, param_list);
        genParamList(node->children[2]);
    } else printf("define %s @%s () #0 {\n", ArrayType[0], id);

    freeArrayDefType(ArrayType);
    free(param_list);
    free(id);
}

void genParamList(AST_Node node) {
    char **ArrayType;
    for (int i = 0; i < node->n_children; i++) {
        AST_Node paraDec = node->children[i];
        ArrayType = defineType(paraDec->children[0]->token);
        char *id = getLiteral(paraDec->children[1]->token, NULL);
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
            n_var++;
            char **ArrayType = defineType(paraDec->children[0]->token);
            char *id = getLiteral(paraDec->children[1]->token, NULL);
            if (i == 0) {
                res = (char *) calloc(strlen(ArrayType[0]) + strlen(id) + 3, 1);
                sprintf(res, "%s %%%s", ArrayType[0], id);
            } else {
                char *aux = (char *) calloc(strlen(res) + strlen(ArrayType[0]) + strlen(id) + 5, 1);
                sprintf(aux, "%s, %s %%%s", res, ArrayType[0], id);
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

char *getVarRef(int n) {
    char aux[10];
    sprintf(aux, "%%%d", n);
    return strdup(aux);
}

char shouldLoad(char *codeRef, AST_Node paramListNode) {
    if (codeRef[0] == '%' || codeRef[0] == '@') {
        int aux = 0;
        sscanf(codeRef, "%%%d", &aux);
        int n_args; //n_args is 0 if first arg is void
        n_args = paramListNode->children[0]->n_children == 1 ? 0 : paramListNode->n_children;
        //not a number ou number <= n_args
        if (aux == 0 || aux <= n_args) {
            return 1;
        }
    }
    return 0;
}

void caseLoad(AST_Node node, AST_Node paramListNode) {
    char **ArrayTypeChild = defineType(node->expType);
    if (shouldLoad(node->codeRef, paramListNode)) {
        n_var++;
        printf("\t%%%d = load %s, %s* %s, align %s\n", n_var, ArrayTypeChild[0], ArrayTypeChild[0], node->codeRef, ArrayTypeChild[1]);
        free(node->codeRef);
        node->codeRef = getVarRef(n_var);
        freeArrayDefType(ArrayTypeChild);
    }
}

char *genLoad(AST_Node node, AST_Node paramListNode) {
    char **ArrayTypeChild;
    char *printParam = NULL;
    for (int i = 1; i < node->n_children; i++) {
        ArrayTypeChild = defineType(node->children[i]->expType);
        caseLoad(node->children[i], paramListNode);
        if (i == 1) {
            printParam = (char *) calloc(strlen(ArrayTypeChild[0]) + strlen(node->children[i]->codeRef) + 2, 1);
            sprintf(printParam, "%s %s", ArrayTypeChild[0], node->children[i]->codeRef);
        } else {
            char *aux = (char *) calloc(strlen(printParam) + strlen(ArrayTypeChild[0]) + strlen(node->children[i]->codeRef) + 3, 1);
            sprintf(aux, "%s,%s %s", printParam, ArrayTypeChild[0], node->children[i]->codeRef);
            free(printParam);
            printParam = aux;
        }
        freeArrayDefType(ArrayTypeChild);
    }
    return printParam;
}

void caseCall(AST_Node node, AST_Node paramListNode) {
    char *printCall;
    char **ArrayType = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[0]->token, paramListNode);
    if (node->n_children > 1) {
        printCall = genLoad(node, paramListNode);
        n_var++;
        printf("\t%%%d = call %s %s(%s)\n", n_var, ArrayType[0], id, printCall);
    } else {
        n_var++;
        printf("\t%%%d = call %s %s()\n", n_var, ArrayType[0], id);
    }
    node->codeRef = getVarRef(n_var);
}

void caseDeclLocal(AST_Node node, AST_Node paramListNode) {
    char **ArrayType = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[1]->token, NULL);
    appendArray(&ArrayVarLocal, id);
    printf("\t%%%s = alloca %s, align %s\n", id, ArrayType[0], ArrayType[1]);
    if (node->n_children == 3) {
        char *value = getLiteral(node->children[2]->token, NULL);
        if (strcmp(node->children[2]->token, "Minus") == 0 || strcmp(node->children[2]->token, "Plus") == 0) {
            value = getUnary(node->children[2]);
            printf("\tstore %s %s, %s* %%%s, align %s\n", ArrayType[0], value, ArrayType[0], id, ArrayType[1]);
        } else if (isArit(node->children[2])) {
            caseArit(node->children[2], isArit(node->children[2]), paramListNode);
            free(isArit(node->children[2]));
        } else
            printf("\tstore %s %s, %s* %%%s, align %s\n", ArrayType[0], value, ArrayType[0], id, ArrayType[1]);
        free(value);
    }
    freeArrayDefType(ArrayType);
    free(id);
}

void caseStoreLocal(AST_Node node) {
    char **ArrayType;
    char *value = getLiteral(node->children[1]->token, NULL);
    ArrayType = defineType(node->children[0]->expType);
    printf("\tstore %s %s, %s* %s, align %s\n", ArrayType[0], node->children[1]->codeRef, ArrayType[0], node->children[0]->codeRef, ArrayType[1]);
    freeArrayDefType(ArrayType);
    free(value);
}


int isParam(char *token, AST_Node paramListNode) {
    int id;
    for (int i = 0; i < paramListNode->n_children; i++) {
        AST_Node paramDec = paramListNode->children[i];
        if (strcmp(token, paramDec->children[1]->token) == 0) {
            id = i + 1;
            return id;
        }
    }
    return 0;
}

void caseCallOnStore(AST_Node node) {
    char **ArrayType = defineType(node->children[0]->expType);
    char *id = getLiteral(node->parent->children[0]->token, NULL);
    printf("\tstore %s %%%d, %s* @%s, align %s\n", ArrayType[0], n_var, ArrayType[0], id, ArrayType[1]);
}

char *getLiteral(char *literal, AST_Node paramListNode) {
    int size;
    if (strncmp(literal, "IntLit", strlen("IntLit")) == 0) {
        size = strlen("IntLit");
    } else if (strncmp(literal, "ChrLit", strlen("ChrLit")) == 0) {
        char aux[10];
        sprintf(aux, "%d", literal[8]);
        return strdup(aux);
    } else if (strncmp(literal, "RealLit", strlen("RealLit")) == 0) {
        size = strlen("RealLit");
    } else if (strncmp(literal, "Id", strlen("Id")) == 0) {
        size = strlen("Id");
        if (paramListNode != NULL) {
            char *value = getLiteral(literal, NULL);
            int res = 0;
            if (paramListNode->children[0]->n_children > 1) //check if current function has parameters
                res = isParam(literal, paramListNode);
            if (res) { //left is argument
                return getVarRef(res);
            } else if (searchArray(&ArrayVarLocal, value)) { //left is local
                char aux[10];
                sprintf(aux, "%%%s", value);
                return strdup(aux);
            } else { //left is global
                char aux[10];
                sprintf(aux, "@%s", value);
                return strdup(aux);
            }
        }
    } else return NULL;
    char *value = (char *) calloc(strlen(literal) - size - 1, sizeof(char));
    strncpy(value, literal + size + 1, strlen(literal) - size - 2);
    return value;
}

char *getUnary(AST_Node node) {
    char *value = (char *) calloc(strlen(node->token) + 2, sizeof(char));
    if (strcmp(node->token, "Minus") == 0) {
        sprintf(value, "-%s", getLiteral(node->children[0]->token, NULL));
    } else if (strcmp(node->token, "Plus") == 0)
        return getLiteral(node->children[0]->token, NULL);
    return value;
}

void caseArit(AST_Node node, char *arit, AST_Node paramListNode) {
    //TODO change op types
    char **ArrayType = defineType(node->expType);
    if (strcmp(node->token, "Minus") == 0) {
        caseLoad(node->children[0], paramListNode);
        n_var++;
        printf("\t%%%d = %s %s 0, %s\n", n_var, arit, ArrayType[0], node->children[0]->codeRef);
        node->codeRef = getVarRef(n_var);
    } else {
        caseLoad(node->children[0], paramListNode);
        caseLoad(node->children[1], paramListNode);
        n_var++;
        printf("\t%%%d = %s %s %s, %s\n", n_var, arit, ArrayType[0], node->children[0]->codeRef, node->children[1]->codeRef);
        node->codeRef = getVarRef(n_var);
    }
}

char *isArit(AST_Node node) {
    char *res;
    if (strcmp(node->token, "Add") == 0)
        res = strdup("add");
    else if (strcmp(node->token, "Sub") == 0 || strcmp(node->token, "Minus") == 0)
        res = strdup("sub");
    else if (strcmp(node->token, "Mul") == 0)
        res = strdup("mul");
    else if (strcmp(node->token, "Div") == 0)
        res = strdup("sdiv");
    else if (strcmp(node->token, "Mod") == 0)
        res = strdup("srem");
    else res = NULL;
    return res;
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

void genFinalReturn(AST_Node node) { //return generated with random content just in case there is no previous return. Should not be reached
    char **ArrayType = defineType(node->token);
    if (strcmp(node->token, "Void") == 0) {
        printf("\tret void\n");
    } else {
        n_var++;
        printf("\t%%%d = alloca %s, align %s\n", n_var, ArrayType[0], ArrayType[1]);
        n_var++;
        printf("\t%%%d = load %s, %s* %%%d, align %s\n", n_var, ArrayType[0], ArrayType[0], (n_var - 1), ArrayType[1]);
        printf("\tret %s %%%d\n", ArrayType[0], n_var);
    }
}

void caseReturn(AST_Node node, AST_Node paramListNode) {
    char **ArrayTypeChild = defineType(node->children[0]->expType);
    caseLoad(node->children[0], paramListNode);
    n_var++;
    printf("\tret %s %s\n", ArrayTypeChild[0], node->children[0]->codeRef);
    freeArrayDefType(ArrayTypeChild);
}


void freeArrayDefType(char **array) {
    free(array[0]);
    free(array[1]);
    free(array);
}