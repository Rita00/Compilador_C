
#!/bin/bash
lex uccompiler.l;yacc -d uccompiler.y;clang -o uccompiler -g lex.yy.c y.tab.c ast.c symbol_table.c FunctionTable.c;./uccompiler -s;
