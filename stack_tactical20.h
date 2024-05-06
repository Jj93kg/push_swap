#ifndef STACK_H
#define STACK_H

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_SIZE 500

typedef struct 
{
    int contents[STACK_SIZE];
    int top;
} stack;

#define MAX_CHUNKS 500

/*************************************/
/*Name: make_empty                   *
**Function: Empties stack            *
**************************************/
void make_empty(stack *a);

/*************************************/
/*Name: is_empty                      *
**Function: Checks if stack is empty  *
**************************************/
bool is_empty( const stack *a);

/*************************************/
/*Name: is_full                      *
**Function: Checks if stack is full  *
**************************************/
bool is_full(const stack *a);

/*************************************/
/*Name: num_in_stack                  *
**Function: Finds size of stack       *
**************************************/
int	num_in_stack(stack *a);

/*************************************/
/*Name: Push                          *
**Function: Pushes element onto stack *
**************************************/
void push(stack *a, int i);

/*************************************/
/*Name: Pop                           *
**Function: Pops top from stack       *
**************************************/
int pop(stack *a);

/*************************************/
/*Name: sa                            *
**Function: swaps top 2 elements of A *
**************************************/
void sa(stack *a);

/*************************************/
/*Name: sb                            *
**Function: swaps top 2 elements of B *
**************************************/
void sb(stack *a);

/*************************************/
/*Name: ss                            *
**Function: Does sa and sb            *
**************************************/
void ss(stack *a, stack *b);

/*************************************/
/*Name: pa                            *
**Function: pops top of B onto A      *
**************************************/
void pa(stack *a, stack *b);

/*************************************/
/*Name: pb                            *
**Function: pops top of A onto B      *
**************************************/
void pb(stack *b, stack *a);

/*************************************/
/*Name: ra                            *
**Function: Rotates stack up one      *
**************************************/
void ra(stack *a);

/*************************************/
/*Name: rb                            *
**Function: Rotates stack up one      *
**************************************/
void rb(stack *s);

/*************************************/
/*Name: rr                            *
**Function: Does ra and rb            *
**************************************/
void rr(stack *s, stack *p);

/*************************************/
/*Name: rra                           *
**Function: Rotates stack down one    *
**************************************/
void rra(stack *s);

/*************************************/
/*Name: rrb                           *
**Function: Rotates stack down one    *
**************************************/
void rrb(stack *s);

/*************************************/
/*Name: rrs                           *
**Function: Does rra and rrb          *
**************************************/
void rrs(stack *s, stack *p);

/*************************************/
/*Name: print_stack                   *
**Function: prints stack elements     *
**************************************/
void print_stack(const stack *a);

/*************************************/
/*Name: CMS_array                     *
**Function: 1. creates array,         *
            2. stores stack elements  *
            3. sorts them in order    *
**************************************/
int *CMS_array(stack *s);

/*************************************/
/*Name: CMS_array_chunk               *
**Function: 1. creates array,         *
            2. stores chunk elements  *
            3. sorts them in order    *
**************************************/
int *CMS_array_chunk(stack *a, int chunkSize);

/*************************************/
/*Name: find_midpoint                 *
**Function: Finds midpoint of array   *
**************************************/
int find_midpoint(int *arr, int size);

/*************************************/
/*Name: top                           *
**Function: retrieves top of a        *
**************************************/
int top(stack *a);

/*************************************/
/*Name: bottom                        *
**Function: retrieves bottom of a     *
**************************************/
int bottom(stack *a);

/*************************************/
/*Name: sortTwo                       *
**Function: Sorts two numbers         *
**************************************/
void sortTwo(stack *a);

/*************************************/
/*Name: sortTwo_A                     *
**Function: Sorts remainder of A      *
**************************************/
void sortTwo_A(stack *a);

/*************************************/
/*Name: midpoint_algo                 *
**Function: Sorts numbers from A to B *
**************************************/
void  midpoint_algo(stack *a, stack *b, int chunk, int chunks_done);

/*************************************/
/*Name: reverse_midpoint_algo         *
**Function: Sorts numbers from B to A *
**************************************/
void reverse_midpoint_algo(stack *a, stack *b);

/*************************************/
/*Name: Sort_stack                    *
**Function: Sorting function          *
**************************************/ 
void sort_stack(stack *a, stack *b);

#endif
