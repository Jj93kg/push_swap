#ifndef STACK_H
#define STACK_H

#include <stdbool.h> /* C99 only */

#define STACK_SIZE 100

typedef struct 
{
    int contents[STACK_SIZE];
    int top;
} stack;

void make_empty(stack *s); 
bool is_empty(const stack *s); 
bool is_full(const stack *s); 
void push(stack *s, int i); 
int pop(stack *s);

#endif
