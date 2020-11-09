/*
Ana Rita Rodrigues - 2018284515
Diogo Flórido - 2018282583
*/


num		[0-9]
signal	[+-]
simple char|else|while|if|int|short|double|return|void
reserved "++"|"--"|"["|"]"|auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|inline|restrict|_Bool|_Complex|_Imaginary

%{
	void upperString(char* str);
	void detect(char* text);
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
	if (!strcmp(yytext, "CHAR")) return CHAR;
	if (!strcmp(yytext, "ELSE")) return ELSE;
	if (!strcmp(yytext, "WHILE")) return WHILE;
	if (!strcmp(yytext, "IF")) return IF;
	if (!strcmp(yytext, "INT")) return INT;
	if (!strcmp(yytext, "SHORT")) return SHORT;
	if (!strcmp(yytext, "DOUBLE")) return DOUBLE;
	if (!strcmp(yytext, "RETURN")) return RETURN;
	if (!strcmp(yytext, "VOID")) return VOID;
}

{reserved} { 
	if (flag == 'l') printf("RESERVED(%s)\n", yytext);
	column+=yyleng;
	yylval.letters=yytext;
	return RESERVED;
}

"&" { detect("BITWISEAND"); ; return BITWISEAND; }

"|" { detect("BITWISEOR");; return BITWISEOR;}

"^" { detect("BITWISEXOR");; return BITWISEXOR;}

"&&" { detect("AND"); return AND;}

"=" { detect("ASSIGN"); return ASSIGN;}

"*" { detect("MUL"); return MUL;}

"," { detect("COMMA"); return COMMA;}

"/" { detect("DIV"); return DIV;}

"==" { detect("EQ"); return EQ;}

">=" { detect("GE"); return GE;}

">" { detect("GT"); return GT;}

"{" { detect("LBRACE"); return LBRACE;}

"<=" { detect("LE"); return LE;}

"(" { detect("LPAR"); return LPAR;}

"<" { detect("LT"); return LT;}

"-" { detect("MINUS"); return MINUS;}

"%" { detect("MOD"); return MOD;}

"!=" { detect("NE"); return NE;}

"!" { detect("NOT"); return NOT;}

"||" { detect("OR"); return OR;}

"+" { detect("PLUS"); return PLUS;}

"}" { detect("RBRACE"); return RBRACE;}

")" { detect("RPAR"); return RPAR;}

";" { detect("SEMI"); return SEMI;}


\'([^\n\'\\]|\\n|\\t|\\\\|"\\\""|\\\'|\\[0-7][0-7]?[0-7]?)\' {
	if(flag == 'l') printf("CHRLIT(%s)\n", yytext); 
	column += yyleng;
	yylval.letters=(char*)strdup(yytext);
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
	column += yyleng;
	yylval.letters=yytext;
	return ID;
}

{num}+ {							
	if (flag == 'l') printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
	column += yyleng;
	yylval.letters=(char*)strdup(yytext);
	return INTLIT;
}

(({num}+".")|({num}*"."{num}+))([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
	if (flag == 'l') printf("REALLIT(%s)\n", yytext);
	column += yyleng;
	yylval.letters=(char*)strdup(yytext);
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

void detect(char* text){
	if (flag == 'l') printf("%s\n", text);
	column += yyleng;
}

int main(int argc, char *argv[]) {
	if (argc > 1 && argv[1][0] == '-'){
		flag = argv[1][1];
	}
    yylex();
    return 0;
}

int yywrap() {
    return 1;;
}
