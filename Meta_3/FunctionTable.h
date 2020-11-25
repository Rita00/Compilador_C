#ifndef UNTITLED_FUNCTIONSTABLE_H
#define UNTITLED_FUNCTIONSTABLE_H
#include "ast.h"
typedef struct functions *functionsList;
struct functions {
    char *variable;
    char *type;
    char isParam;
    functionsList next;
};

functionsList search_locals(functionsList list, AST_Node node);
functionsList create_TableNode(char *varName, char *varType, char isParam);
functionsList addVariable(char *varName, char *varType, char isParam, functionsList list);
void freeFunctionsList(functionsList list);
void printFunctionsList(functionsList list, char *name);

#endif //UNTITLED_FUNCTIONSTABLE_H
