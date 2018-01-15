#ifndef STACKOFCHARSMODULE_H
#define STACKOFCHARSMODULE_H

typedef char StackItem;
StackItem pop(void);
void push(StackItem);
void pushString(char*);
int isEmpty(void);
int isFull(void);

#endif // STACKOFCHARSMODULE_H
