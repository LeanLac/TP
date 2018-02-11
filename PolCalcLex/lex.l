%option noyywrap
%{
#include "y.tab.h"
%}

INT     -?[0-9]+
FLOAT  -?[0-9]*[.][0-9]+

%%
[ \t]		;
[+]		{yylval = yytext;
		return SUMA;}
[-]		{yylval = yytext;
		return RESTA;}
[*]		{yylval = yytext;
		return PROD;}
[/]		{yylval = yytext;
		return DIV;}
{FLOAT}  {yylval = atof(yytext);
		return FLOAT;}
{INT}   {yylval = atoi(yytext);
        return INT;}
\n 		{yylval = yytext;
		return RES;}
[(]		{yylval = yytext;
        return PA;}
[)]		{yylval = yytext;
        return PC;}
.		{return *yytext;}
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
