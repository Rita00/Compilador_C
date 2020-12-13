#ifndef UNTITLED_GENCODE_H
#define UNTITLED_GENCODE_H

void genCode(AST_Node root);

void caseFuncDef(AST_Node node);

void genParamList(AST_Node node);

char *caseParamList(AST_Node node);

void genCodeFuncBody(AST_Node node);

void caseDeclGlobal(AST_Node node);

void caseDeclLocal(AST_Node node);

char *defineType(char *type);

void caseStoreLocal(AST_Node node);

char* getLiteral(char *literal);

#endif
