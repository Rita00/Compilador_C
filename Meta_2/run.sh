#!/bin/bash
lex uccompiler.l;yacc -d uccompiler.y;clang -o uccompiler lex.yy.c y.tab.c ast.c;./uccompiler -l;
