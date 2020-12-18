#ifndef UNTITLED_GENCODE_H
#define UNTITLED_GENCODE_H

#include "ast.h"

void genCodeFuncBody(AST_Node node, AST_Node paramListNode);

void caseWhile(AST_Node node, AST_Node paramListNode);

void caseIf(AST_Node node, AST_Node paramListNode);

void treatuppernodes(AST_Node root);

void genCode(AST_Node root);

void caseDeclGlobal(AST_Node node);

void caseFuncDef(AST_Node node);

void genParamList(AST_Node node);

char *caseParamList(AST_Node node);

char *getVarRef(int n);

char shouldLoad(char *codeRef, AST_Node paramListNode);

void caseLoad(AST_Node node, AST_Node paramListNode);

char *genLoad(AST_Node node, AST_Node paramListNode);

void caseCall(AST_Node node, AST_Node paramListNode);

void caseDeclLocal(AST_Node node, AST_Node paramListNode);

void caseConvertToInt(AST_Node node);

void caseConvert(AST_Node node, char isStore);

void caseStoreLocal(AST_Node node, AST_Node paramListNode);

int isParam(char *token, AST_Node paramListNode);

int getChar(char *escape_sequence);

char *getRealLit(char *real);

char *getLiteral(char *literal, AST_Node paramListNode);

char *getDoubleFormat(AST_Node node);

void caseRelational(AST_Node node, char *arit, AST_Node paramListNode);

void caseArit(AST_Node node, char *arit, AST_Node paramListNode);

void caseLogical(AST_Node node, AST_Node paramListNode);

char *isRelational(AST_Node node);

char *isArit(AST_Node node);

char **defineType(char *type);

void genFinalReturn(AST_Node node);

void caseReturn(AST_Node node, AST_Node paramListNode);

void freeArrayDefType(char **array);

int getOctal(char *octal);

#endif
