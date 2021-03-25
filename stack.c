#include "stack.h"
#include <stdio.h>

// ==============Stack with list==============
#ifdef LIST

Stack *stack_init(){
    printf("~~INIT STACK ON LIST~~\n");
    return list_init();
}


int push(Stack *stack, double val){
    list_insert(stack, val, 0);
    return 0;
}


int pop(Stack *stack, double *val){
    list_remove(stack, 0, val);
    return 0;
}


int write(Stack *stack){
    list_write(stack);
    return 0;
}


int clear(Stack *stack){
    list_clear(stack);
    return 0;
}

#endif
// ===========================================

// ==============Stack with vector==============
#ifdef VECTOR

Stack *stack_init(){
    printf("~~INIT STACK ON VECTOR~~\n");
    return vector_init();
}


int push(Stack *stack, double val){
    vector_insert(stack, val, 0);
    return 0;
}


int pop(Stack *stack, double *val){
    vector_remove(stack, 0, val);
    return 0;
}


int write(Stack *stack){
    vector_write(stack);
    return 0;
}


int clear(Stack *stack){
    vector_clear(stack);
    return 0;
}

#endif
// =============================================
