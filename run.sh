#!/bin/bash
lex uccompiler.l;clang -o uccompiler lex.yy.c;./uccompiler -l;
