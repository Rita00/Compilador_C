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
	yylval.letters=(char*)strdup(yytext);
	return SIMPLE;
}

{reserved} { 
	if (flag == 'l') printf("RESERVED(%s)\n", yytext);
	column+=yyleng;
	yylval.letters=(char*)strdup(yytext);
	return RESERVED;
}

"&" { detect("BITWISEAND"); yylval.letters=(char*)strdup(yytext); return BITWISEAND; }

"|" { detect("BITWISEOR");yylval.letters=(char*)strdup(yytext); return BITWISEOR;}

"^" { detect("BITWISEXOR");yylval.letters=(char*)strdup(yytext); return BITWISEXOR;}

"&&" { detect("AND");yylval.letters=(char*)strdup(yytext); return AND;}

"=" { detect("ASSIGN");yylval.letters=(char*)strdup(yytext); return ASSIGN;}

"*" { detect("MUL");yylval.letters=(char*)strdup(yytext); return MUL;}

"," { detect("COMMA");yylval.letters=(char*)strdup(yytext); return COMMA;}

"/" { detect("DIV");yylval.letters=(char*)strdup(yytext); return DIV;}

"==" { detect("EQ");yylval.letters=(char*)strdup(yytext); return EQ;}

">=" { detect("GE");yylval.letters=(char*)strdup(yytext); return GE;}

">" { detect("GT");yylval.letters=(char*)strdup(yytext); return GT;}

"{" { detect("LBRACE");yylval.letters=(char*)strdup(yytext); return LBRACE;}

"<=" { detect("LE");yylval.letters=(char*)strdup(yytext); return LE;}

"(" { detect("LPAR");yylval.letters=(char*)strdup(yytext); return LPAR;}

"<" { detect("LT");yylval.letters=(char*)strdup(yytext); return LT;}

"-" { detect("MINUS");yylval.letters=(char*)strdup(yytext); return MINUS;}

"%" { detect("MOD");yylval.letters=(char*)strdup(yytext); return MOD;}

"!=" { detect("NE");yylval.letters=(char*)strdup(yytext); return NE;}

"!" { detect("NOT");yylval.letters=(char*)strdup(yytext); return NOT;}

"||" { detect("OR");yylval.letters=(char*)strdup(yytext); return OR;}

"+" { detect("PLUS");yylval.letters=(char*)strdup(yytext); return PLUS;}

"}" { detect("RBRACE");yylval.letters=(char*)strdup(yytext); return RBRACE;}

")" { detect("RPAR");yylval.letters=(char*)strdup(yytext); return RPAR;}

";" { detect("SEMI");yylval.letters=(char*)strdup(yytext); return SEMI;}


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
	yylval.letters=(char*)strdup(yytext);
	return ID;
}

{num}+ {							
	if (flag == 'l') printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
	column += yyleng;
	yylval.intnum=atoi(yytext);
	return INTLIT;
}

(({num}+".")|({num}*"."{num}+))([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
	if (flag == 'l') printf("REALLIT(%s)\n", yytext);
	column += yyleng;
	yylval.realnum=strtod(yytext,*(yytext+sizeof(yytext));
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
