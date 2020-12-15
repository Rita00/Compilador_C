#ifndef UNTITLED_GENCODE_H
#define UNTITLED_GENCODE_H

void genCode(AST_Node root);

void caseFuncDef(AST_Node node);

void genParamList(AST_Node node);

char *caseParamList(AST_Node node);

void genCodeFuncBody(AST_Node node, AST_Node paramListNode);

char* genLoad(AST_Node node, AST_Node paramListNode);

void caseCall(AST_Node node, AST_Node paramListNode);

void caseDeclGlobal(AST_Node node);

void caseDeclLocal(AST_Node node);

char **defineType(char *type);

void caseStoreLocal(AST_Node node, AST_Node paramListNode);

int isParam(AST_Node node, AST_Node paramListNode);

void caseCallOnStore(AST_Node node);

char* getLiteral(char *literal);

char* getUnary(AST_Node node);

void caseArit(AST_Node node, char *arit);

char* isArit(AST_Node node);

void genReturn(AST_Node node);

void freeArrayDefType(char **array);

#endif
