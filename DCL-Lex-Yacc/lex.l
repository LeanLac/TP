%option noyywrap
%{
#include "y.tab.h"
%}

NOMBRE [a-zA-Z][a-zA-Z0-9]*

NUMERO	[0-9]+

%%
[ \t]		;
[(]		{yylval.token = atoi(yytext);
		return PA;}
[)]		{yylval.token = atoi(yytext);
		return PC;}
\[      {yylval.token = atoi(yytext);
        return CA;}
\]      {yylval.token = atoi(yytext);
        return CC;}
[*]		{yylval.token = atoi(yytext);
		return PUN;}
{NOMBRE}	{yylval.name = strdup(yytext);
		return NOM;}
{NUMERO}	{yylval.intVal = atoi(yytext);
		return NUM;}	
\n  	{yylval.token = atoi(yytext);
		return FIN;}
.		{return *yytext;}
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
