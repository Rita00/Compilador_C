/*
Ana Rita Rodrigues - 2018284515
Diogo Alves Almeida - 2018282583
*/


num		[0-9]
signal	[+-]
simple char|else|while|if|int|short|double|return|void
reserved (_[A-Z]([a-zA-Z]|{num})*)|(__+([_a-zA-Z]|{num})*)|"++"|"--"|"["|"]"|auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|inline|restrict

%{
	void upperString(char* str);
	void detect(char* text);
	char *charlit;
	int line = 1, column = 0;
	int stateinitLine, stateinitColumn;
	char flag = '\0';
%}

%X CHARINIT CHAREND COMMENTSINGLE COMMENTDOUBLE

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
	stateinitColumn = column;
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
	printf("Line <%d>, col <%d>: unterminated comment\n", stateinitLine, stateinitColumn);
	BEGIN 0;
}



"'"	{
	BEGIN CHARINIT; //entrar no modo de busca de char literal
	column++;
	stateinitColumn = column;
	stateinitLine = line;	
}

<CHARINIT>(\\n|\\t|\\\\|\\'|"\""|(\\[0-7][0-7][0-7]))	{	// procurar sequencia de escape			
	// Caso seja uma sequência de escape
	BEGIN CHAREND;
	charlit = strdup(yytext);
	column += yyleng;
}	


<CHARINIT>. { 
	// Caso seja um caracter
	BEGIN CHAREND;
	charlit = strdup(yytext);
	column++;
}

<CHAREND>"'" { //encontrou segunda plica e por isso termina o char literal
	if (flag == 'l') printf("CHRLIT('%s')\n", charlit);
	free(charlit);
	BEGIN 0;
	column++;
}

<CHAREND>[^']+' { //encontrou conteudo a mais no char literal e por isso apresenta erro
	printf("Line <%d>, col <%d>: invalid char constant ('%s%s)\n", stateinitLine, stateinitColumn, charlit, yytext);
	free(charlit);
	column += yyleng;
	BEGIN 0;
}

<CHARINIT>"\n"|"\r\n"|"\r" {
	printf("Line <%d>, col <%d>: unterminated char constant\n", stateinitLine, stateinitColumn);
	BEGIN 0;
	line++;
}

<CHAREND>"\n"|"\r\n"|"\r" {
	printf("Line <%d>, col <%d>: unterminated char constant\n", stateinitLine, stateinitColumn);
	BEGIN 0;
	line++;
}

<CHARINIT><<EOF>> {
	printf("Line <%d>, col <%d>: unterminated char constant\n", stateinitLine, stateinitColumn);
	BEGIN 0;
}

<CHAREND><<EOF>> {
	printf("Line <%d>, col <%d>: unterminated char constant\n", stateinitLine, stateinitColumn);
	BEGIN 0;
}



{simple} {
	upperString(yytext);
	detect(yytext);
}

{reserved} { detect("RESERVED");}

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



[_a-zA-Z]([a-zA-Z_]|{num})* {											// Sequências alfanuméricas
	if (flag == 'l') printf("ID(%s)\n", yytext);
	column += yyleng;
}

{num}+ {							
	if (flag == 'l') printf("INTLIT(%s)\n", yytext);										// Sequências de dígitos decimais
	column += yyleng;
}

{num}*"."{num}*([eE]{signal}?{num}+)?|{num}+[eE]{signal}?{num}+ {		// Números Reais
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
	printf("Line <%d>, col <%d>: illegal character (%s)\n", line, column, yytext); 
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
    return 1;
}
