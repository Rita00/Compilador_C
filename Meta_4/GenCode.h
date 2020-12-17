#ifndef UNTITLED_GENCODE_H
#define UNTITLED_GENCODE_H

#include "ast.h"

void caseConvert(AST_Node node, char isStore);

void genCodeFuncBody(AST_Node node, AST_Node paramListNode);

char shouldLoad(char *codeRef, AST_Node paramListNode);

void genCode(AST_Node root);

void caseFuncDef(AST_Node node);

void caseLogical(AST_Node node, AST_Node paramListNode);

char *isRelational(AST_Node node);

void caseRelational(AST_Node node, char *arit, AST_Node paramListNode);

void genParamList(AST_Node node);

char *caseParamList(AST_Node node);

char *genLoad(AST_Node node, AST_Node paramListNode);

void caseCall(AST_Node node, AST_Node paramListNode);

void caseDeclGlobal(AST_Node node);

void caseDeclLocal(AST_Node node, AST_Node paramListNode);

char **defineType(char *type);

void caseStoreLocal(AST_Node node, AST_Node paramListNode);

int isParam(char *token, AST_Node paramListNode);

void caseCallOnStore(AST_Node node);

char *getLiteral(char *literal, AST_Node paramListNode);

char *getVarRef(int n);

char *getUnary(AST_Node node);

void caseArit(AST_Node node, char *arit, AST_Node paramListNode);

char *isArit(AST_Node node);

void genFinalReturn(AST_Node node);

void caseReturn(AST_Node node, AST_Node paramListNode);

char checkIfReturn(AST_Node node);

void freeArrayDefType(char **array);

#endif
