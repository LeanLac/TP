#ifndef SCANNER_H
#define SCANNER_H

enum TokenType {
	Number,
	Addition='+',
	Multiplication='*',
	Substraction='-',
	Division='/',
	PopResult='\n',
	LexError
};
typedef enum TokenType TokenType;
typedef double TokenValue;
typedef struct Token{
	TokenType type;
	TokenValue val;
} Token;
int GetNextToken(Token *t); 

#endif
