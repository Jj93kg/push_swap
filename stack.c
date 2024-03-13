#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

static void terminate(const char *message)
{
    printf("You suck.\n");
    exit(EXIT_FAILURE);
}

void make_empty(stack *s)
{
    s->top = 0;
}

bool is_empty(const stack *s)
{
    return s->top == 0;
}

bool is_full(const stack *s)
{
    return s->top == STACK_SIZE;
}

void push(stack *s, int i)
{
    if (is_full(s))
    {
        terminate("Error in push: stack is full.");
    }
    else
    {
        s->contents[s->top++] = i;
    }
}

int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("Error popping: empty stack!\n");
        return -1; // Return an error code
    }
    else
    {
        return s->contents[--s->top];
    }
}

void sa(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int temp;
        temp = s->contents[s->top - 1];
        s->contents[s->top - 1] = s->contents[s->top - 2];
        s->contents[s->top - 2] = temp;
    }
}

void sb(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int temp;

        temp = s->contents[s->top - 1];
        s->contents[s->top - 1] = s->contents[s->top - 2];
        s->contents[s->top - 2] = temp;
    }
}

void ss(stack *a, stack *b)
{
    sa(a);
    sb(b);
}

void pa(stack *a, stack *b)
{
    if (!is_empty(b))
    {
        push(a, pop(b));
    }
}

void pb(stack *b, stack *a)
{
    if (!is_empty(a))
    {
        push(b, pop(a));
    }
}

void ra(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int first;
        int i;

        first = s->contents[0];
        i = 0;
        while (i < s->top - 1)
        {
            s->contents[i] = s->contents[i + 1];
            i++;
        }
        s->contents[s->top - 1] = first;
    }
}

void rb(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int first;
        int i;

        first = s->contents[0];
        i = 0;
        while (i < s->top - 1)
        {
            s->contents[i] = s->contents[i + 1];
            i++;
        }
        s->contents[s->top - 1] = first;
    }
}

void rr(stack *s, stack *p)
{
    ra(s);
    rb(p);
}

void rra(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int last = s->contents[s->top - 1];
        int i = s->top - 1;
        while (i >= 0)
        {
            s->contents[i] = s->contents[i - 1];
            i--;
        }
        s->contents[0] = last;
    }
}

void rrb(stack *s)
{
    if (s->top < 2)
    {
        return;
    }
    else
    {
        int last = s->contents[s->top - 1];
        int i = s->top - 1;
        while (i >= 0)
        {
            s->contents[i] = s->contents[i - 1];
            i--;
        }
        s->contents[0] = last;
    }
}

void rrs(stack *s, stack *p)
{
    rra(s);
    rrb(p);
}

void print_stack(const stack *s)
{
    printf("Stack contents (top to bottom): ");
    int i = s->top - 1;
    while (i >= 0)
    {
        printf("%d ", s->contents[i]);
        i--;
    }
    printf("\n");
}

int top(stack *s)
{
    if (s->top > 0)
    {
        return (s->contents[s->top - 1]);
    }
    return (-1);
}

int find_min_position(stack *s, int value)
{
    for (int j = 0; j < s->top; j++)
    {
        if (s->contents[j] == value)
        {
            return j;
        }
    }
    return -1; // Indicates the value was not found.
}

void movemintos(stack *s, stack *p)
{
    if (s->top == 1) 
    {
        printf("Only one number in stack!\n");
        pb(p, s);
        return ;
    }
    int originalSize = s->top;
    printf("Original size of stack s is %d\n", originalSize);
    printf("Now rotating stack once.\n");
    printf("Stack before:\n");
    print_stack(s);
    rb(s);
    printf("Stack after\n");
    print_stack(s);
    int i = 0;
    while (i < originalSize) 
    {
        if (s->contents[s->top - 1] > s->contents[s->top - 2]) 
        {
            printf("Top number is bigger than number below, swapping\n.");
            sb(s);
        }
        printf("Rotating again.\n");
        rb(s);
        i++;
    }
    printf("Pushing from s to p.\n");
pb(p, s);
}

void sort_stack(stack *s, stack *p)
{
    make_empty(p);
    printf("Conditions of stacks at beginning.\n");
    print_stack(s);
    print_stack(p);
    printf("-----------------------------------------------------\n");
    // Move All Elements to Stack p whilst finding min:
    
    while (!is_empty(s)) 
    {
        movemintos(s, p);
    }

    while (!is_empty(p)) 
    {
        pb(s, p);
    }
    printf("Attempt after new functions\n");
    print_stack(s);
    print_stack(p);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*int numbersMoved = 0;
    int min = INT_MAX;
    while (!is_empty(s))
    {
        int current = top(s);
        pb(p, s);
        if (current < min)
        {
            min = current;
            printf("Number min is %d\n", min);
        }
    }
    //Find where in stack min is to figure out how many times to rotate
    int position_ft = 0;
    int z = p->top - 1;
    while (z >= 0) 
    {
        if (p->contents[z] == min) 
        {
            break;
        }
        z--;
        position_ft++;
    }
    printf("Position from top is %d\n", position_ft);

    //Rotate min to top to push it to s
    int y = 0;
    while (y < position_ft) 
    {
        rra(p);
        y++;
    }
    printf("Stack after rotating min to top is\n");
    print_stack(p);
    //Actually push min to stack s
    pa(s, p);
    printf("Stack after pushing min to s is\n");
    print_stack(s);
    print_stack(p);
    
    //TO DO:
    // Now we have moved from stack s to p, found and moved smallest from p back to s. 
    // Now need to go back through p, and find smallest again to move to s.

    

    printf("Conditions of stacks after initial move from s to p are\n");
    print_stack(s);
    print_stack(p);
    printf("-----------------------------------------------------\n");
    //Move one element back to Stack s
        pa(s, p);
    printf("Conditions of stacks after moving one element from s to p are\n");
    print_stack(s);
    print_stack(p);
    printf("-----------------------------------------------------\n");
        int min = s->contents[s->top - 1];
        while (!is_empty(p))
        {
            pa(s, p);
            int newElement = s->contents[s->top - 1];
            if (min > newElement)
            {
                min = newElement;
            }
        }
       // Re-find the smallest element's position from the top
    int positionFromTop = 0;
    int i = s->top - 1;
    while (i > 0)
    {
        if (s->contents[i] == min)
        {
            break;
        }
        i--;
        positionFromTop++;
    }
    printf("Conditions of stacks after finding smallest, it's %d.\n", min);
    print_stack(s);
    print_stack(p);
    printf("-----------------------------------------------------\n");

    // Apply rra positionFromTop times to bring the smallest to the top
    printf("Conditions of stacks after moving smallest to top.\n");
    i = 0;
    while (i < positionFromTop)
    {
        rra(s);
        i++;
    }
    print_stack(s);
    print_stack(p);
    printf("-----------------------------------------------------\n");
    printf("Conditions of stacks after moving smallest to p stack.\n");
    pb(p, s);
    print_stack(s);
    print_stack(p);
        printf("-----------------------------------------------------\n");*/
}

void sort_stack2(stack *s, stack *p)
{
    make_empty(p); // Assuming you have a function like this to initialize a stack.

    while (!is_empty(s))
    { // Continue until s is empty.
        int temp = pop(s);

        // Move elements from p back to s if they are greater than temp.
        while (!is_empty(p) && p->contents[p->top - 1] > temp)
        {
            push(s, pop(p));
        }

        // Correct place for temp in p.
        push(p, temp);
    }

    // Now, p contains the sorted elements. If you need them back in s, reverse the process.
    while (!is_empty(p))
    {
        push(s, pop(p));
    }
}

int main(void)
{
    stack s; // Declare an instance of stack s
    stack p;
    make_empty(&s); // Check stack empty before filling it
    make_empty(&p);
    // printf("Stack a and b has been initialized.\n");
    printf("-------------------------------------------\n");

    /*
    // Check pushing function works
    printf("Now checking pushing function.\n");
    int i = 1;
    while (i < 6)
    {
        printf("Pushing %d\n", i);
        push(&s, i);
        i++;
    }

    // Check if full or not
    printf("-------------------------------------------\n");
    printf("Now checking is empty and is full check functions.\n");
    if (is_full(&s))
    {
        printf("The stack is full.\n");
    }
    else
    {
        printf("The stack is not full.\n");
    }

    // Check popping function
    printf("-------------------------------------------\n");
    printf("Now checking popping functions...\n");
    printf("Popping elements from the stack...\n");
    while (!is_empty(&s))
    {
        printf("Popped %d\n", pop(&s));
    }

    // This should safely report the stack is empty
    printf("-------------------------------------------\n");
    printf("Now checking pop worked successfully.\n");
    printf("Attempting to pop from an empty stack...\n");
    pop(&s);

    // Re add numbers into stack
    printf("-------------------------------------------\n");
    printf("Ok now re-adding numbers into stack a...\n");
    i = 1;
    while (i < 6)
    {
        printf("Pushing %d\n", i);
        push(&s, i);
        i++;
    }

    // Now initilialising stack p
    printf("-------------------------------------------\n");
    stack p;
    make_empty(&p);
    printf("Stack b has been initialised.\n");

    // Fill stack p
    printf("-------------------------------------------\n");
    int j = 6;
    while (j <= 10)
    {
        push(&p, j);
        printf("Pushing %d\n", j);
        j++;
    }

    // Swap first two elements of stacks
    printf("-------------------------------------------\n");
    i = 0;
    printf("Trying to swap first two elements now.\n");
    printf("Stack elements before!\n");
    print_stack(&s);
    print_stack(&p);
    printf("Now swapping first two elements \n");
    ss(&s, &p);
    printf("Stack elements after!\n");
    print_stack(&s);
    print_stack(&p);

    // Reset stacks again
    printf("-------------------------------------------\n");
    printf("Resetting stacks now.\n");
    make_empty(&s);
    make_empty(&p);
    i = 1;
    while (i < 6)
    {
        push(&s, i);
        i++;
    }
    j = 6;
    while (j <= 10)
    {
        push(&p, j);
        j++;
    }
    printf("Reset stacks.\n");
    print_stack(&s);
    print_stack(&p);

    // Attempting to move top elements from a to b and vice versa
    printf("-------------------------------------------\n");
    printf("Before pa operation:\n");
    print_stack(&s);
    print_stack(&p);

    pa(&s, &p); // Attempt to move the top element from b to a

    printf("After pa operation:\n");
    print_stack(&s);
    print_stack(&p);

    printf("Before pb operation:\n");
    print_stack(&s);
    print_stack(&p);

    pb(&p, &s); // Attempt to move the top element from a to b

    printf("After pb operation:\n");
    print_stack(&s);
    print_stack(&p);

    // Reset stacks again
    printf("-------------------------------------------\n");
    printf("Resetting stacks now.\n");
    make_empty(&s);
    make_empty(&p);
    i = 1;
    while (i < 6)
    {
        push(&s, i);
        i++;
    }
    j = 6;
    while (j <= 10)
    {
        push(&p, j);
        j++;
    }
    printf("Reset stacks.\n");
    print_stack(&s);
    print_stack(&p);

    //Test rr (rotate ra and rb at the same time)
    printf("-------------------------------------------\n");
    printf("Testing rotating each element of stacks up by one.\n");
    printf("Stacks before:\n");
    print_stack(&s);
    print_stack(&p);
    rr(&s, &p);
    printf("Stacks after:\n");
    print_stack(&s);
    print_stack(&p);

    // Reset stacks again
    printf("-------------------------------------------\n");
    printf("Resetting stacks now.\n");
    make_empty(&s);
    make_empty(&p);
    i = 1;
    while (i < 6)
    {
        push(&s, i);
        i++;
    }
    j = 6;
    while (j <= 10)
    {
        push(&p, j);
        j++;
    }
    printf("Reset stacks.\n");
    print_stack(&s);
    print_stack(&p);

    //Test rrs (rotate rra and rrb at the same time)
    printf("-------------------------------------------\n");
    printf("Testing rotating each element of stacks down by one.\n");
    printf("Stacks before:\n");
    print_stack(&s);
    print_stack(&p);
    rrs(&s, &p);
    printf("Stacks after:\n");
    print_stack(&s);
    print_stack(&p);
*/
    // Reset stacks again
    // printf("-------------------------------------------\n");
    // printf("Resetting stacks now.\n");
    make_empty(&s);
    make_empty(&p);

    // printf("Now making them randomly assigned.\n");

    push(&s, 4);
    push(&s, 1);
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);

    // printf("Unsorted stack s: \n");
    // print_stack(&s);
    sort_stack(&s, &p);

    // printf("Sorted stacks:\n");
    // print_stack(&s);
    // print_stack(&p);
    return (0);
}