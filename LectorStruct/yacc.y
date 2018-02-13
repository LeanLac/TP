%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(char *);

char text[1000];
%}

%union{
    char* str;
    int token;
};



%token <token> LLA
%token <token> LLC
%token <token> STR
%token <token> PYC
%token <token> PUN
%token <str> ID
%token <str> INT


%%

prog:
    prog struct
    |
    ;

struct:
    STR ID LLA dcls LLC PYC {printf("%s es una estructura compuesta por: %s\n", $2, text);
                             text[0] = '\0';}
    ;

dcls:
    dcls dcl
    | dcl
    ;

dcl:
    ID ID PYC   {strcat(text, "\n - ");
                 strcat(text, $2);
                 strcat(text, ": variable del tipo ");
                 strcat(text, $1);}
    | ID PUN ID PYC {strcat(text, "\n - ");
                     strcat(text, $3);
                     strcat(text, ": puntero a ");
                     strcat(text, $1);}
    | ID ID '[' INT ']' PYC {strcat(text, "\n - ");
                             strcat(text, $2);
                             strcat(text, ": arreglo ");
                             strcat(text, $4);
                             strcat(text, " de ");
                             strcat(text, $1);}
    ;


%%

int main(void){
	yyparse();
	return 0;
}

