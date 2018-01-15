#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Scanner.h"
#define MAXNUM 100

int GetNextToken(Token *t){
	int tipo = getchar();
    while(tipo == ' ')
        tipo = getchar();
	if(isdigit(tipo)){
		char lexeme[MAXNUM];
		int p = 0;
		lexeme[p] = tipo;
		while(isdigit(tipo = getchar()))
			lexeme[++p] = tipo;
		if(tipo == '.'){
			lexeme[p] = tipo;
			while(isdigit(tipo = getchar()))
				lexeme[++p] = tipo;
		}
		lexeme[p+1] = '\0';
		ungetc(tipo, stdin);
		(*t).type = Number;
		(*t).val = atof(lexeme);
		return 1;
	}
	else{
		switch(tipo){
			case Addition:
				(*t).type = Addition;
				break;
			case Multiplication:
				(*t).type = Multiplication;
				break;
			case Substraction:
				(*t).type = Substraction;
				break;
			case Division:
				(*t).type = Division;
				break;
			case PopResult:
				(*t).type = PopResult;
				break;
			case EOF:
				return 0;
			default:
				(*t).type = LexError;
                (*t).val = tipo;
				break;
		}
		return 1;
	}
}
