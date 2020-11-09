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
}

{reserved} { 
	if (flag == 'l') printf("RESERVED(%s)\n", yytext);
	column+=yyleng;
}

"&" { detect("BITWISEAND"); }

"|" { detect("BITWISEOR"); }

"^" { detect("BITWISEXOR"); }

"&&" { detect("AND"); }

"=" { detect("ASSIGN"); }

"*" { detect("MUL"); }

"," { detect("COMMA"); }

"/" { detect("DIV"); }

"==" { detect("EQ"); }

">=" { detect("GE"); }

">" { detect("GT"); }

"{" { detect("LBRACE"); }

"<=" { detect("LE"); }

"(" { detect("LPAR"); }

"<" { detect("LT"); }

"-" { detect("MINUS"); }

"%" { detect("MOD"); }

"!=" { detect("NE"); }

"!" { detect("NOT"); }

"||" { detect("OR"); }

"+" { detect("PLUS"); }

"}" { detect("RBRACE"); }

")" { detect("RPAR"); }

";" { detect("SEMI"); }


\'([^\n\'\\]|\\n|\\t|\\\\|"\\\""|\\\'|\\[0-7][0-7]?[0-7]?)\' {
	if(flag == 'l') printf("CHRLIT(%s)\n", yytext); 
	column += yyleng;
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
}

{num}+ {							
	if (flag == 'l') printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
	column += yyleng;
}

(({num}+".")|({num}*"."{num}+))([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
	if (flag == 'l') printf("REALLIT(%s)\n", yytext);
	column += yyleng;
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
