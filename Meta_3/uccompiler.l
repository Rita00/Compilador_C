/*
Ana Rita Rodrigues - 2018284515
Diogo Flórido - 2018282583
*/


num		[0-9]
signal	[+-]
simple char|else|while|if|int|short|double|return|void
reserved "++"|"--"|"["|"]"|auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|inline|restrict|_Bool|_Complex|_Imaginary

%{
	#include "y.tab.h"
	void upperString(char* str);
	void lowerString(char* str);
	void detect(char* text);
	void store_data(char store_letters);
	char *charlit;
	int line = 1, column = 0;
	int stateinitLine, stateinitColumn;
	char flag = '\0';
%}

%X COMMENTSINGLE COMMENTDOUBLE

%%

"//" {
	BEGIN COMMENTSINGLE;	
	column+=2;
}

<COMMENTSINGLE>. {
	column++;
}

<COMMENTSINGLE>"\n"|"\r\n"|"\r" {
	column = 0;
	line++;
	BEGIN 0;
}

"/*" {
	BEGIN COMMENTDOUBLE;	
	column+=2;
	stateinitColumn = column - 1;
	stateinitLine = line;
}

<COMMENTDOUBLE>. {
	column++;
}

<COMMENTDOUBLE>"\n"|"\r\n"|"\r" {
	column = 0;
	line++;
}

<COMMENTDOUBLE>"*/" {
	column+=2;
	BEGIN 0;
}

<COMMENTDOUBLE><<EOF>> {
	printf("Line %d, col %d: unterminated comment\n", stateinitLine, stateinitColumn);
	BEGIN 0;
}

{simple} {
	upperString(yytext);
	detect(yytext);
	lowerString(yytext);
	if (flag != 'l' && flag != '1'){
		if (!strcmp(yytext, "char")) return CHAR;
		if (!strcmp(yytext, "else")) return ELSE;
		if (!strcmp(yytext, "while")) return WHILE;
		if (!strcmp(yytext, "if")) return IF;
		if (!strcmp(yytext, "int")) return INT;
		if (!strcmp(yytext, "short")) return SHORT;
		if (!strcmp(yytext, "double")) return DOUBLE;
		if (!strcmp(yytext, "return")) return RETURN;
		if (!strcmp(yytext, "void")) return VOID;
	}
}

{reserved} { 
	if (flag == 'l') printf("RESERVED(%s)\n", yytext);
	column+=yyleng;
	store_data(1);
	if (flag != 'l' && flag != '1')
		return RESERVED;
}



"&" { detect("BITWISEAND");if (flag != 'l' && flag != '1') return BITWISEAND;}

"|" { detect("BITWISEOR"); if (flag != 'l' && flag != '1') return BITWISEOR;}

"^" { detect("BITWISEXOR"); if (flag != 'l' && flag != '1') return BITWISEXOR;}

"&&" { detect("AND"); if (flag != 'l' && flag != '1') return AND;}

"=" { detect("ASSIGN"); if (flag != 'l' && flag != '1') return ASSIGN;}

"*" { detect("MUL"); if (flag != 'l' && flag != '1') return MUL;}

"," { detect("COMMA"); if (flag != 'l' && flag != '1') return COMMA;}

"/" { detect("DIV"); if (flag != 'l' && flag != '1') return DIV;}

"==" { detect("EQ"); if (flag != 'l' && flag != '1') return EQ;}

">=" { detect("GE"); if (flag != 'l' && flag != '1') return GE;}

">" { detect("GT"); if (flag != 'l' && flag != '1') return GT;}

"{" { detect("LBRACE"); if (flag != 'l' && flag != '1') return LBRACE;}

"<=" { detect("LE"); if (flag != 'l' && flag != '1') return LE;}

"(" { detect("LPAR"); if (flag != 'l' && flag != '1') return LPAR;}

"<" { detect("LT"); if (flag != 'l' && flag != '1') return LT;}

"-" { detect("MINUS"); if (flag != 'l' && flag != '1') return MINUS;}

"%" { detect("MOD"); if (flag != 'l' && flag != '1') return MOD;}

"!=" { detect("NE"); if (flag != 'l' && flag != '1') return NE;}

"!" { detect("NOT"); if (flag != 'l' && flag != '1') return NOT;}

"||" { detect("OR"); if (flag != 'l' && flag != '1') return OR;}

"+" { detect("PLUS"); if (flag != 'l' && flag != '1') return PLUS;}

"}" { detect("RBRACE"); if (flag != 'l' && flag != '1') return RBRACE;}

")" { detect("RPAR"); if (flag != 'l' && flag != '1') return RPAR;}

";" { detect("SEMI"); if (flag != 'l' && flag != '1') return SEMI;}


\'([^\n\'\\]|\\n|\\t|\\\\|"\\\""|\\\'|\\[0-7][0-7]?[0-7]?)\' {
	if(flag == 'l') printf("CHRLIT(%s)\n", yytext); 
	store_data(1);
	column += yyleng;
	if (flag != 'l' && flag != '1')
		return CHRLIT;
}

\'([^\n\'\\]|\\.)*\' {
	printf("Line %d, col %d: invalid char constant (%s)\n", line, column+1, yytext); 
	column += yyleng;
}

\'([^\n\'\\]|\\.)*(\\)? {
	printf("Line %d, col %d: unterminated char constant\n", line, column+1);
	column += yyleng;
}

[_a-zA-Z]([a-zA-Z_]|{num})* {											// Sequências alfanuméricas
	if (flag == 'l') printf("ID(%s)\n", yytext);
	store_data(1);
	column += yyleng;
	if (flag != 'l' && flag != '1')
		return ID;
}

{num}+ {							
	if (flag == 'l') printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
	store_data(1);	
	column += yyleng;
	if (flag != 'l' && flag != '1')
		return INTLIT;
}

(({num}+".")|({num}*"."{num}+))([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
	if (flag == 'l') printf("REALLIT(%s)\n", yytext);
	store_data(1);
	column += yyleng;
	if (flag != 'l' && flag != '1')
		return REALLIT;
}

"\n"|"\r\n"|"\r" {
	column = 0;
	line++;
}

" "|"\t" {
	column++;
}

. {	
	column++;
	printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext); 
}


%%

void upperString(char* str) {
	for (char *c = str; *c != '\0'; c++){
		if (*c >='a' && *c <='z'){
			*c = *c - ('a' - 'A');
		}
	}
}

void lowerString(char* str) {
	for (char *c = str; *c != '\0'; c++){
		if (*c >='A' && *c <='Z'){
			*c = *c + ('a' - 'A');
		}
	}
}

void detect(char* text){
	if (flag == 'l') printf("%s\n", text);
	store_data(0);
	column += yyleng;
}

int main(int argc, char *argv[]) {
	if (argc > 1 && argv[1][0] == '-'){
		flag = argv[1][1];
		if (flag == 'e') {
			flag = argv[1][2];
		}
	}
	if(flag == 'l' || flag == '1'){
		yylex();
	}else {
	    yyparse();
	    yylex_destroy();
	}
    return 0;
}



void yyerror (char *s) {
    printf("Line %d, col %d: %s: %s\n", line, column - (int)strlen(yytext) + 1, s, yytext);
}

int yywrap() {
    return 1;;
}

void store_data(char store_letters){
	if (store_letters)
		yylval.data.letters = strdup(yytext);
	yylval.data.linha = line;
	yylval.data.coluna = column + 1	;
}
