#include <stdio.h>
#include "StackOfDoublesModule.h"
#define MAXPILA 100

int pp = 0;
StackItem pila[MAXPILA];

void push(StackItem item){
	if (isFull())
		printf("error: pila llena, no puede efectuar push %g\n", item);
	else 
		pila[pp++] = item;
}

StackItem pop(void){
	if (isEmpty()){
		printf("error: pila vacia\n");
		return 0.0;
	}
	else
		return pila[--pp];
	
}

int isEmpty(void){
	return (pp == 0);
}

int isFull(void){
	return (pp == MAXPILA);
}
