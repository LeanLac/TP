%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%union{
    int intVal;
    char* name;
    int token;
};


%token <token> PA
%token <token> PC
%token <token> CA
%token <token> CC
%token <token> PUN
%token <name> NOM
%token <intVal> NUM
%token <token> FIN

%right NOM
%left PA CA

%%
    
program:
    program NOM dcl FIN		{printf("%s \n", $2);}
    |
	;


dcl:
    apun dcldir
    | dcldir
    ;


dcldir:
    NOM
    | PUN dcldir           {printf("puntero a ");}
    | PA dcl PC
    | dcldir PA PC         {printf("funcion que devuelve ");}
    | dcldir CA NUM CC     {printf("arreglo %d de ", $3);}
    | dcldir CA CC         {printf("arreglo de ");}
    | dcldir PA %prec PUN dcldir
    | dcldir CA %prec PUN dcldir
    ;

apun:
    PUN             {printf("puntero a ");}
    | apun PUN      {printf("puntero a ");}
    ;


%%

int main(void){
	yyparse();
	return 0;
}

