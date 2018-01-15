#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Scanner.h"
#include "StackOfCharsModule.h"

int GetNextToken(Token *t){
	int tipo = getchar();
	switch(tipo){
		case Barra:
			tipo = getchar();
			if (tipo == '*')
				(*t) = ComenMultiA;
			else if (tipo == 47)
				(*t) = ComenSimple;
			else if (tipo == EOF)
				return 0;
			else (*t) = OtroToken;
            ungetc(tipo, stdin);
			break;
		case BarraInv:
			tipo = getchar();
            if (tipo == EOF)
                return 0;
			else (*t) = OtroToken;
            ungetc(tipo, stdin);
            break;
        case NuevaLinea:
            (*t) = NuevaLinea;
            break;
		case Asterisco:
			tipo = getchar();
			if (tipo == '/')
				(*t) = ComenMultiC;
			else if (tipo == EOF)
				return 0;
			else (*t) = OtroToken;
            ungetc(tipo, stdin);
			break;
		case Apostrofe:
			(*t) = Apostrofe;
			break;
		case Comillas:
			(*t) = Comillas;
			break;
		case ParenAb:
			(*t) = ParenAb;
			break;
		case ParenCe:
			(*t) = ParenCe;
			break;
		case LlaveAb:
			(*t) = LlaveAb;
			break;
		case LlaveCe:
			(*t) = LlaveCe;
			break;
		case CorcheteAb:
			(*t) = CorcheteAb;
			break;
		case CorcheteCe:
			(*t) = CorcheteCe;
			break;
		case EOF:
			return 0;
		default:
			(*t) = OtroToken;
			break;
	}
	return 1;
}
		
