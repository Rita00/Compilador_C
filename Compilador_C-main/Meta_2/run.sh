lex uccompiler.l
yacc -d uccompiler.y
cc -o uccompiler y.tab.c lex.yy.c
./uccompiler
