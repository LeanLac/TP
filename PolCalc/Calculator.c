#include <stdio.h>
#include "Scanner.h"
#include "StackOfDoublesModule.h"
int main(void){
	double op2;
	Token token;
	Token *t;
	t = &token;
	while(GetNextToken(t)){
	 	switch ((*t).type) {
			 case Number:
			 	push((*t).val);
			 	break;			
			 case Addition:
			 	push(pop() + pop());
			 	break;
			 case Multiplication:
			 	push(pop() * pop());
			 	break;
			 case Substraction:
				 op2 = pop();
				 push(pop() - op2);
			 	break;
			 case Division:
				 op2 = pop();
				 if (op2 != 0.0)
				 	push(pop() / op2);
				 else
				 	printf("error: divisor cero\n");
				 break;
			 case PopResult:
			 	printf("\t%.8g\n", pop());
			 	break;		
			 default:
			 	printf("error: comando desconocido\n");
			 	break;
		}
	}

	return 0;
}
