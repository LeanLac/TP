%option noyywrap
%{
#include "y.tab.h"
%}

IDENT [a-zA-Z][a-zA-Z0-9]*
NUMERO	[0-9]+


%%
[ \t]		;
\{		{yylval.token = atoi(yytext);
		return LLA;}
\}		{yylval.token = atoi(yytext);
		return LLC;}
struct  {yylval.token = atoi(yytext);
        return STR;}
\;      {yylval.token = atoi(yytext);
        return PYC;}
\*  	{yylval.token = atoi(yytext);
		return PUN;}
{IDENT}	{yylval.str = strdup(yytext);
		return ID;}
{NUMERO}    {yylval.str = strdup(yytext);
		return INT;}
.		{return *yytext;}
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
