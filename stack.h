#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#ifdef LIST
#include "list.h"
typedef List Stack;
Stack *stack_init();
int push(Stack *stack, double val);
int pop(Stack *stack, double *val);
int write(Stack *stack);
int clear(Stack *stack);
#endif

#ifdef VECTOR
#include "vector.h"
typedef Vector Stack;
Stack *stack_init();
int push(Stack *stack, double val);
int pop(Stack *stack, double *val);
int write(Stack *stack);
int clear(Stack *stack);
#endif

#endif //LAB2_STACK_H
