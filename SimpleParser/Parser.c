#include <stdio.h>
#include "Scanner.h"
#include "StackOfCharsModule.h"

int main(void){
	Token token;
	Token *t;
	t = &token;
	push('$');

	Programa:{
		if(GetNextToken(t)){
			switch(*t){
				case OtroToken:
					goto Programa;
				case ComenMultiA:
					goto ComenMulti;
				case ComenMultiC:
					goto Programa;
				case ComenSimple:
					goto ComenSimple;
				case NuevaLinea:
					goto Programa;
				case Comillas:
					goto Cadena;
				case Apostrofe:
					goto Caracter;
				case ParenAb:
					push('p');
					goto Programa;
				case LlaveAb:
					push('l');
					goto Programa;
				case CorcheteAb:
					push('c');
					goto Programa;
				case ParenCe:
					if(pop() != 'p'){
						printf("error: Parentesis no alineados\n");
						goto Final;
					}
					else goto Programa;
				case LlaveCe:
					if(pop() != 'l'){
						printf("error: Llaves no alineadas\n");
						goto Final;
					}
					else goto Programa;
				case CorcheteCe:
					if(pop() != 'c'){
						printf("error: Corchetes no alineados\n");
						goto Final;
					}
					else goto Programa;
				default:
					goto Programa;
			}
        }
		else goto Final;
	}

	ComenMulti:{
		if(GetNextToken(t)){
			switch(*t){
				case ComenMultiC:
					goto Programa;
				default:
					goto ComenMulti;
			}
        }
		else goto Final;
	}

	ComenSimple:{
		if(GetNextToken(t)){
			switch(*t){
				case NuevaLinea:
					goto Programa;
				default:
					goto ComenSimple;
			}
        }
		else goto Final;
	}
	
	Cadena:{
		if(GetNextToken(t)){
			switch(*t){
				case Comillas:
					goto Programa;
				default:
					goto Cadena;
			}
        }
		else goto Final;
	}
	
	Caracter:{
		if(GetNextToken(t)){
			switch(*t){
				case Apostrofe:
					goto Programa;
				default:
					goto Caracter;
			}
        }
        else goto Final;
	}
	
	Final:{
		if(pop() == '$'){
			printf("Programa Alineado\n");
			return 0;
		}
		else{ 
			printf("Programa Desalineado\n");
			return 1;
		}
	}
}
