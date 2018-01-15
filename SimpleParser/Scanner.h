#ifndef SCANNER_H
#define SCANNER_H

enum Casos {
	OtroToken,
	ComenMultiA,
	ComenMultiC,
	ComenSimple,
	NuevaLinea = 10,
	Barra = 47,
	BarraInv = 92,
	Asterisco = 42,
	Apostrofe = 39,
	Comillas = 34,
	ParenAb = 40,
	ParenCe = 41,
	LlaveAb = 123,
	LlaveCe = 125,
	CorcheteAb = 91,
	CorcheteCe = 93
};
typedef enum Casos Token;
int GetNextToken(Token *t);

#endif //SCANNER_H

