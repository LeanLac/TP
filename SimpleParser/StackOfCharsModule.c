#include <stdio.h>
#include "StackOfCharsModule.h"
#define MAXPILA 100

int pp = 0;
StackItem pila[MAXPILA]; 

void push(StackItem item){
	if (isFull())
		printf("error: pila llena, no puede efectuar push\n");
	else
		pila[pp++] = item;
}

StackItem pop(void){
	if(isEmpty()){
	    	printf("error: pila vacia, no se puede efectuar el pop\n");
		return '$';
	}
	else
		return pila[--pp];
}


void pushString(char* s){
	for( ; *s; ++s)
		push(*s);
}


int isEmpty(void){
	return (pp == '$');
}


int isFull(void){
	return (pp == MAXPILA);
}
