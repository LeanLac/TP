%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token SUMA
%token RESTA
%token PROD
%token DIV
%token INT
%token FLOAT
%token RES
%token PA
%token PC

%%

program:
	program expr RES	{printf("%d\n", $2);}
	|
	;

expr:
	num			        {$$ = $1;}
	| expr expr SUMA	{$$ = $1 + $2;}
	| expr expr RESTA	{$$ = $1 - $2;}
	| expr expr PROD	{$$ = $1 * $2;}
	| expr expr DIV		{$$ = $1 / $2;}
	| PA expr PC		{$$ = $2;}
	;

num:
    FLOAT
    | INT
    ;

%%


int main(void){
	yyparse();
	return 0;
}

