#!/bin/bash
lex projeto.l;clang -o uccompiler lex.yy.c;./uccompiler;
