/*
Ana Rita Rodrigues - 2018284515
Diogo Alves Almeida - 2018282583
*/


num		[0-9]
signal	[+-]
simple char|else|while|if|int|short|double|return|void
reserved "++"|"--"|"["|"]"|auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto

%{
	void upperString(char* str);
%}

%%

{simple} {
	upperString(yytext);
	printf("%s\n", yytext);
}

{reserved} { printf("RESERVED\n"); }

"&" { printf("BITWISEAND\n"); }

"|" { printf("BITWISEOR\n"); }

"^" { printf("BITWISEXOR\n"); }

"&&" { printf("AND\n"); }

"=" { printf("ASSIGN\n"); }

"*" { printf("MUL\n"); }

"," { printf("COMMA\n"); }

"/" { printf("DIV\n"); }

"==" { printf("EQ\n"); }

">=" { printf("GE\n"); }

">" { printf("GT\n"); }

"{" { printf("LBRACE\n"); }

"<=" { printf("LE\n"); }

"(" { printf("LPAR\n"); }

"<" { printf("LT\n"); }

"-" { printf("MINUS\n"); }

"%" { printf("MOD\n"); }

"!=" { printf("NE\n"); }

"!" { printf("NOT\n"); }

"||" { printf("OR\n"); }

"+" { printf("PLUS\n"); }

"}" { printf("RBRACE\n"); }

")" { printf("RPAR\n"); }

";" { printf("SEMI\n"); }

[a-zA-z_]+({num}*|a-zA-z|_)+ {											// Sequências alfanuméricas
	printf("ID(%s)\n", yytext);
}

'[a-zA-Z]' {
	printf("CHRLIT(%s)\n", yytext);
}

{num}+ {							
	printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
}

{num}*"."{num}*([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
	printf("REALLIT(%s)\n", yytext);
}

(.|"\r"|"\n") {																		// Ignora o que não dá "match"  //todo acrescentar erros!!
	;
}								

%%

void upperString(char* str) {
	for (char *c = str; *c != '\0'; c++){
		if (*c >='a' && *c <='z'){
			*c = *c - ('a' - 'A');
		}
	}
}

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
