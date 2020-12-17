#include "symbol_table.h"
#include "GenCode.h"
#include "vector.h"

void lowerString(char *str);

vector ArrayVarLocal;
int n_var = 0;
int n_label = 0;

void genCodeFuncBody(AST_Node node, AST_Node paramListNode, int last_label) {
    if (strcmp(node->token, "While") == 0) {
        caseWhile(node, paramListNode, last_label);
        return;
    } else if (strcmp(node->token, "If") == 0) {
        caseIf(node, paramListNode, last_label);
        return;
    }
    for (int i = 0; i < node->n_children; i++) {
        genCodeFuncBody(node->children[i], paramListNode, last_label);
    }

    char *aux = isArit(node);
    if (aux) {
        caseArit(node, aux, paramListNode);
        free(aux);
        return;
    }
    aux = isRelational(node);
    if (aux) {
        caseRelational(node, aux, paramListNode);
        free(aux);
        return;
    }
    aux = getLiteral(node->token, paramListNode);
    if (aux) {
        node->codeRef = aux;
    } else if (strcmp(node->token, "Declaration") == 0) {
        caseDeclLocal(node, paramListNode);
    } else if (strcmp(node->token, "Store") == 0) {
        caseStoreLocal(node, paramListNode);
    } else if (strcmp(node->token, "Call") == 0) {
        caseCall(node, paramListNode);
    } else if (strcmp(node->token, "Return") == 0) {
        caseReturn(node, paramListNode);
    } else if (strcmp(node->token, "Plus") == 0) {
        node->codeRef = strdup(node->children[0]->codeRef);
    } else {
        caseLogical(node, paramListNode, last_label);
    }
}

void caseWhile(AST_Node node, AST_Node paramListNode, int last_label) {
    int mylabel = n_label;
    n_label += 3;
    mylabel++;
    printf("\tbr label %%label%d\n\n", mylabel); //todo pode-se omitir

    printf("\tlabel%d:\n", mylabel);
    genCodeFuncBody(node->children[0], paramListNode, mylabel);
    caseLoad(node->children[0], paramListNode);
    n_var++;
    printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[0]->codeRef);
    printf("\tbr i1 %%%d, label %%label%d, label %%label%d\n\n", n_var, mylabel + 1, mylabel + 2);

    mylabel++;
    printf("\tlabel%d:\n", mylabel);
    genCodeFuncBody(node->children[1], paramListNode, mylabel);
    printf("\tbr label %%label%d\n\n", mylabel - 1);

    mylabel++;
    printf("\tlabel%d:\n", mylabel);
}

void caseIf(AST_Node node, AST_Node paramListNode, int last_label) {
    int mylabel = n_label;
    n_label += 3;
    genCodeFuncBody(node->children[0], paramListNode, last_label);
    caseLoad(node->children[0], paramListNode);
    n_var++;
    printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[0]->codeRef);
    printf("\tbr i1 %%%d, label %%label%d, label %%label%d\n\n", n_var, mylabel + 1, mylabel + 2);

    mylabel++;
    printf("\tlabel%d:\n", mylabel);
    genCodeFuncBody(node->children[1], paramListNode, mylabel);
    printf("\tbr label %%label%d\n\n", mylabel + 2);

    mylabel++;
    printf("\tlabel%d:\n", mylabel);
    genCodeFuncBody(node->children[2], paramListNode, mylabel);
    printf("\tbr label %%label%d\n\n", mylabel + 1);

    mylabel++;
    printf("\tlabel%d:\n", mylabel);
}

void treatuppernodes(AST_Node root) {
    if (strcmp(root->token, "Declaration") == 0) {
        caseDeclGlobal(root);
    } else if (strcmp(root->token, "FuncDefinition") == 0) {
        caseFuncDef(root);
        genCodeFuncBody(root->children[3], root->children[2], 0);
        genFinalReturn(root->children[0]);
        printf("}\n\n");
        freeArray(&ArrayVarLocal);
        n_var = 0;
        n_label = 0;
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
        if (value == NULL) { // if is null than node is minus
            char *value = getLiteral(node->children[2]->children[0]->token, NULL);
            printf("@%s = global %s -%s, align %s\n", id, ArrayType[0], value, ArrayType[1]);
            free(value);
        } else {
            printf("@%s = global %s %s, align %s\n", id, ArrayType[0], value, ArrayType[1]);
            free(value);
        }
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
    char **ArrayType = defineType(node->children[0]->expType);
    char *id = getLiteral(node->children[0]->token, paramListNode);
    if (node->n_children > 1) {
        printCall = genLoad(node, paramListNode);
        if (strcmp(ArrayType[0], "void") == 0) {
            printf("\tcall %s %s(%s)\n", ArrayType[0], id, printCall);
        } else {
            n_var++;
            printf("\t%%%d = call %s %s(%s)\n", n_var, ArrayType[0], id, printCall);
        }
    } else {
        if (strcmp(ArrayType[0], "void") == 0) {
            printf("\tcall %s %s()\n", ArrayType[0], id);
        } else {
            n_var++;
            printf("\t%%%d = call %s %s()\n", n_var, ArrayType[0], id);
        }

    }
    node->codeRef = getVarRef(n_var);
}

void caseDeclLocal(AST_Node node, AST_Node paramListNode) {
    char **ArrayType = defineType(node->children[0]->token);
    char *id = getLiteral(node->children[1]->token, NULL);
    appendArray(&ArrayVarLocal, id);
    printf("\t%%%s = alloca %s, align %s\n", id, ArrayType[0], ArrayType[1]);
    if (node->n_children == 3) {
        caseConvert(node, 2);
        printf("\tstore %s %s, %s* %%%s, align %s\n", ArrayType[0], node->children[2]->codeRef, ArrayType[0], id, ArrayType[1]);
    }
    freeArrayDefType(ArrayType);
    free(id);
}

void caseConvertToInt(AST_Node node) {
    char *aux = isRelational(node);
    if (aux != NULL || strcmp(node->token, "Not") == 0 || strcmp(node->token, "Or") == 0 || strcmp(node->token, "And") == 0) {
        if (aux != NULL) free(aux);
        n_var++;
        printf("\t%%%d = zext i1 %s to i32\n", n_var, node->codeRef);
        free(node->codeRef);
        node->codeRef = getVarRef(n_var);
    }
}

void caseConvert(AST_Node node, char isStore) {
    int skip_first = 0;
    if (isStore == 2) {
        skip_first = 1;
    }
    char **ArrayType0 = defineType(node->children[0]->token);
    if (ArrayType0 == NULL)
        ArrayType0 = defineType(node->children[0]->expType);
    char **ArrayType1 = defineType(node->children[1 + skip_first]->token);
    if (ArrayType1 == NULL)
        ArrayType1 = defineType(node->children[1 + skip_first]->expType);
    if (*ArrayType0[1] == '4') { //left is int
        if (*ArrayType1[1] == '1') {
//            n_var++;
//            printf("\t%%%d = zext i1 %s to i32\n", n_var, node->children[1 + skip_first]->codeRef);
//            free(node->children[1 + skip_first]->codeRef);
//            node->children[1 + skip_first]->codeRef = getVarRef(n_var);
        } else if (*ArrayType1[1] == '8' && !isStore) {
            n_var++;
            printf("\t%%%d = sitofp i32 %s to double\n", n_var, node->children[0]->codeRef);
            free(node->children[0]->codeRef);
            node->children[0]->codeRef = getVarRef(n_var);
        }
    } else if (*ArrayType0[1] == '8') { //left is double
        if (*ArrayType1[1] != '8') {
            n_var++;
            printf("\t%%%d = sitofp %s %s to double\n", n_var, ArrayType1[0], node->children[1 + skip_first]->codeRef);
            free(node->children[1 + skip_first]->codeRef);
            node->children[1 + skip_first]->codeRef = getVarRef(n_var);
        }
    } else if (!isStore && *ArrayType1[1] == '4') { //right is int
        if (*ArrayType0[1] == '1') {
//            n_var++;
//            printf("\t%%%d = zext i1 %s to i32\n", n_var, node->children[0]->codeRef);
//            free(node->children[0]->codeRef);
//            node->children[0]->codeRef = getVarRef(n_var);
        } else if (*ArrayType0[1] == '8') {
            n_var++;
            printf("\t%%%d = sitofp i32 %s to double\n", n_var, node->children[1 + skip_first]->codeRef);
            free(node->children[1 + skip_first]->codeRef);
            node->children[1 + skip_first]->codeRef = getVarRef(n_var);
        }
    } else if (!isStore && *ArrayType1[1] == '8') { //right is double
        if (*ArrayType0[1] != '8') {
            n_var++;
            printf("\t%%%d = sitofp %s %s to double\n", n_var, ArrayType0[0], node->children[0]->codeRef);
            free(node->children[0]->codeRef);
            node->children[0]->codeRef = getVarRef(n_var);
        }
    }


}

void caseStoreLocal(AST_Node node, AST_Node paramListNode) {
    char **ArrayType;
    char *value = getLiteral(node->children[1]->token, NULL);
    ArrayType = defineType(node->children[0]->expType);
    caseLoad(node->children[1], paramListNode);
    caseConvert(node, 1);
    printf("\tstore %s %s, %s* %s, align %s\n", ArrayType[0], node->children[1]->codeRef, ArrayType[0], node->children[0]->codeRef, ArrayType[1]);
    node->codeRef = strdup(node->children[0]->codeRef);
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

char getChar(char *escape_sequence) {
    if (strlen(escape_sequence) == 0) {
        return ' ';
    } else if (strlen(escape_sequence) == 1) {
        return escape_sequence[0];
    } else if (strlen(escape_sequence) == 2) {
        switch (escape_sequence[1]) {
            case 'n':
                return '\n';
            case 't':
                return '\t';
            case '\\':
                return '\\';
            case '\'':
                return '\'';
            case '\"':
                return '\"';
            default:
                return escape_sequence[1] - '0';
        }
    } else if (strlen(escape_sequence) == 3) {
        char c1 = escape_sequence[1] - '0'; //convert to numeric
        char c2 = escape_sequence[2] - '0';
        return (c1 << 3) + c2;
    } else {
        char c1 = escape_sequence[1] - '0'; //convert to numeric
        char c2 = escape_sequence[2] - '0';
        char c3 = escape_sequence[3] - '0';
        return (c1 << 6) + (c2 << 3) + c3;
    }

    return 0;
}

char *getLiteral(char *literal, AST_Node paramListNode) {
    int size;
    if (strncmp(literal, "IntLit", strlen("IntLit")) == 0) {
        size = strlen("IntLit");
    } else if (strncmp(literal, "ChrLit", strlen("ChrLit")) == 0) {
        char aux[10] = "\0";
        sscanf(literal, "ChrLit('%s')", aux);
        aux[strlen(aux) - 2] = '\0';
        char c = getChar(aux);
        sprintf(aux, "%d", c);
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

char *getDoubleFormat(AST_Node node) {
    if (*node->codeRef == '%' || *node->codeRef == '@') {
        char **ArrayType = defineType(node->expType);
        if (*ArrayType[1] == '4') {
            n_var++;
            printf("\t%%%d = sitofp %s %s to double\n", n_var, ArrayType[0], node->codeRef);
            free(node->codeRef);
            node->codeRef = getVarRef(n_var);
        }
        freeArrayDefType(ArrayType);
        return strdup(node->codeRef);
    }
    double var;
    sscanf(node->codeRef, "%lf", &var);
    char aux[100];
    sprintf(aux, "%lf", var);
    return strdup(aux);
}

void caseRelational(AST_Node node, char *arit, AST_Node paramListNode) {
    if (*arit != 'o') {
        caseLoad(node->children[0], paramListNode);
        caseLoad(node->children[1], paramListNode);
        caseConvert(node, 0);
        n_var++;
        printf("\t%%%d = icmp %s i32 %s, %s\n", n_var, arit, node->children[0]->codeRef, node->children[1]->codeRef);
        node->codeRef = getVarRef(n_var);
        caseConvertToInt(node);
    } else {
        caseLoad(node->children[0], paramListNode);
        caseLoad(node->children[1], paramListNode);
        caseConvert(node, 0);
        n_var++;
        printf("\t%%%d = fcmp %s double %s, %s\n", n_var, arit, node->children[0]->codeRef, node->children[1]->codeRef);
        node->codeRef = getVarRef(n_var);
        caseConvertToInt(node);
    }

}

void caseArit(AST_Node node, char *arit, AST_Node paramListNode) {
    char **ArrayType = defineType(node->expType);

    if (*arit != 'f') {
        if (strcmp(node->token, "Plus") == 0) {
            node->codeRef = strdup(node->children[0]->codeRef);
        } else if (strcmp(node->token, "Minus") == 0) {
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
    } else {
        if (strcmp(node->token, "Minus") == 0) {
            caseLoad(node->children[0], paramListNode);
            char *aux = getDoubleFormat(node->children[0]);
            n_var++;
            printf("\t%%%d = %s %s 0.0, %s\n", n_var, arit, ArrayType[0], aux);
            node->codeRef = getVarRef(n_var);
            free(aux);
        } else {
            caseLoad(node->children[0], paramListNode);
            caseLoad(node->children[1], paramListNode);
            char *aux1 = getDoubleFormat(node->children[0]);
            char *aux2 = getDoubleFormat(node->children[1]);
            n_var++;
            printf("\t%%%d = %s %s %s, %s\n", n_var, arit, ArrayType[0], aux1, aux2);
            node->codeRef = getVarRef(n_var);
            free(aux1);
            free(aux2);
        }
    }

}

void caseLogical(AST_Node node, AST_Node paramListNode, int last_label) {
    if (strcmp(node->token, "Not") == 0) {
        caseLoad(node->children[0], paramListNode);
        n_var++;
        printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[0]->codeRef);
        n_var++;
        printf("\t%%%d = xor i1 %%%d, true\n", n_var, n_var - 1);
        node->codeRef = getVarRef(n_var);
        caseConvertToInt(node);
    } else if (strcmp(node->token, "And") == 0) {
        int mylabel = n_label;
        n_label += 2;
        caseLoad(node->children[0], paramListNode);
        n_var++;
        printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[0]->codeRef);
        mylabel++;
        printf("\tbr i1 %%%d, label %%label%d, label %%label%d\n\n", n_var, mylabel, mylabel + 1);
        printf("\tlabel%d:\n", mylabel);
        caseLoad(node->children[1], paramListNode);
        n_var++;
        printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[1]->codeRef);
        printf("\tbr label %%label%d\n\n", mylabel + 1);
        mylabel++;
        printf("\tlabel%d:\n", mylabel);
        n_var++;
        if (last_label == 0) {
            printf("\t%%%d = phi i1 [false, %%0], [%%%d, %%label%d]\n", n_var, n_var - 1, mylabel - 1);
        } else {
            printf("\t%%%d = phi i1 [false, %%label%d], [%%%d, %%label%d]\n", n_var, last_label, n_var - 1, mylabel - 1);
        }
        node->codeRef = getVarRef(n_var);
        caseConvertToInt(node);
    } else if (strcmp(node->token, "Or") == 0) {
        int mylabel = n_label;
        n_label += 2;
        caseLoad(node->children[0], paramListNode);
        n_var++;
        printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[0]->codeRef);
        mylabel++;
        printf("\tbr i1 %%%d, label %%label%d, label %%label%d\n\n", n_var, mylabel + 1, mylabel);
        printf("\tlabel%d:\n", mylabel);
        caseLoad(node->children[1], paramListNode);
        n_var++;
        printf("\t%%%d = icmp ne i32 %s, 0\n", n_var, node->children[1]->codeRef);
        printf("\tbr label %%label%d\n\n", mylabel + 1);
        mylabel++;
        printf("\tlabel%d:\n", mylabel);
        n_var++;
        if (last_label == 0) {
            printf("\t%%%d = phi i1 [true, %%0], [%%%d, %%label%d]\n", n_var, n_var - 1, mylabel - 1);
        } else {
            printf("\t%%%d = phi i1 [true, %%label%d], [%%%d, %%label%d]\n", n_var, last_label, n_var - 1, mylabel - 1);
        }
        node->codeRef = getVarRef(n_var);
        caseConvertToInt(node);
    }
}


char *isRelational(AST_Node node) {
    char *res = NULL;
    if (node->n_children == 2 && node->children[0]->expType != NULL && node->children[1]->expType != NULL) {
        char **ArrayType0 = defineType(node->children[0]->expType);
        char **ArrayType1 = defineType(node->children[1]->expType);
        if (*ArrayType0[1] != '8' && *ArrayType1[1] != '8') {
            if (node->expType != NULL) {
                if (strcmp(node->token, "Eq") == 0) {
                    res = strdup("eq");
                } else if (strcmp(node->token, "Ne") == 0) {
                    res = strdup("ne");
                } else if (strcmp(node->token, "Lt") == 0) {
                    res = strdup("slt");
                } else if (strcmp(node->token, "Le") == 0) {
                    res = strdup("sle");
                } else if (strcmp(node->token, "Gt") == 0) {
                    res = strdup("sgt");
                } else if (strcmp(node->token, "Ge") == 0) {
                    res = strdup("sge");
                }
            }
        } else {
            if (node->expType != NULL) {
                if (strcmp(node->token, "Eq") == 0) {
                    res = strdup("oeq");
                } else if (strcmp(node->token, "Ne") == 0) {
                    res = strdup("one");
                } else if (strcmp(node->token, "Lt") == 0) {
                    res = strdup("olt");
                } else if (strcmp(node->token, "Le") == 0) {
                    res = strdup("ole");
                } else if (strcmp(node->token, "Gt") == 0) {
                    res = strdup("ogt");
                } else if (strcmp(node->token, "Ge") == 0) {
                    res = strdup("oge");
                }
            }
        }
        freeArrayDefType(ArrayType0);
        freeArrayDefType(ArrayType1);
    }
    return res;

}

char *isArit(AST_Node node) {
    char *res = NULL;
    if (node->expType != NULL) {
        char **ArrayType = defineType(node->expType);
        if (*ArrayType[1] == '4') {
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
            else if (strcmp(node->token, "BitWiseOr") == 0)
                res = strdup("or");
            else if (strcmp(node->token, "BitWiseAnd") == 0)
                res = strdup("and");
            else if (strcmp(node->token, "BitWiseXor") == 0)
                res = strdup("xor");
        } else {
            if (strcmp(node->token, "Add") == 0)
                res = strdup("fadd");
            else if (strcmp(node->token, "Sub") == 0 || strcmp(node->token, "Minus") == 0)
                res = strdup("fsub");
            else if (strcmp(node->token, "Mul") == 0)
                res = strdup("fmul");
            else if (strcmp(node->token, "Div") == 0)
                res = strdup("fdiv");
        }
    }

    return res;
}

char **defineType(char *type) {
    char **res = calloc(sizeof(char *), 2);
    if (strcmp(type, "And") == 0 || strcmp(type, "Or") == 0 || strcmp(type, "Not") == 0 || strcmp(type, "Eq") == 0 || strcmp(type, "Ne") == 0 || strcmp(type, "Lt") == 0 || strcmp(type, "Le") == 0 || strcmp(type, "Gt") == 0 || strcmp(type, "Ge") == 0) {
        res[0] = strdup("i1");
        res[1] = strdup("1");
        return res;
    } else if (strcmp(type, "Double") == 0 || strcmp(type, "double") == 0) {
        res[0] = strdup("double");
        res[1] = strdup("8");
        return res;
    } else if (strcmp(type, "Char") == 0 || strcmp(type, "char") == 0 || strcmp(type, "Short") == 0 || strcmp(type, "short") == 0 || strcmp(type, "Int") == 0 || strcmp(type, "int") == 0) {
        res[0] = strdup("i32");
        res[1] = strdup("4");
        return res;
    } else if (strcmp(type, "Void") == 0 || strcmp(type, "void") == 0) {
        res[0] = strdup("void");
        res[1] = strdup("0");
        return res;
    } else return NULL;
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
    if (node->children[0]->expType == NULL) {
        n_var++;
        printf("\tret void\n");
    } else {
        char **ArrayTypeChild = defineType(node->children[0]->expType);
        caseLoad(node->children[0], paramListNode);
        n_var++;
        printf("\tret %s %s\n", ArrayTypeChild[0], node->children[0]->codeRef);
        freeArrayDefType(ArrayTypeChild);
    }
}


void freeArrayDefType(char **array) {
    free(array[0]);
    free(array[1]);
    free(array);
}