
#!/bin/bash
lex uccompiler.l;yacc -d uccompiler.y;clang-3.9 -o uccompiler lex.yy.c y.tab.c ast.c symbol_table.c;./uccompiler -t;
