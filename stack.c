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
    printf("\n");
    while (i >= 0)
    {
        printf("%d\n", s->contents[i]);
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

int find_min(stack *s)
{
	int	len;
	int	min;

	len = s->top;
	min = s->contents[s->top - 1];
	while (len >= 0) 
	{
		if (s->contents[len - 1] < min) 
		{
			min = s->contents[len - 1];
		}
		len--;
	}
	return (min);
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

void find_movemintos(stack *s, stack *p)
{
    if (s->top == 1) 
    {
	    //printf("Only one number in stack!\n");
	    pb(p, s);
	    printf("pb\n");
	    return ;
    }
    int originalSize = s->top;
   // printf("Original size of stack s is %d\n", originalSize);
   // printf("Now rotating stack once.\n");
    //printf("Stack before:\n");
    //print_stack(s);
    rb(s);
    printf("rb\n");
    //printf("Stack after\n");
    //print_stack(s);
    int i = 0;
    while (i < originalSize) 
    {
        if (s->contents[s->top - 1] > s->contents[s->top - 2]) 
        {
            //printf("Top number is bigger than number below, swapping\n.");
            sb(s);
	    printf("sb\n");
        }
        //printf("Rotating again.\n");
        rb(s);
	printf("rb\n");
        i++;
    }
    //printf("Pushing from s to p.\n");
pb(p, s);
printf("pb\n");
}

int	where_is_min(stack *s)
{
	int min = find_min(s);
	int len = s->top;
	int half = len / 2;
	int position = find_min_position(s, min);
	int closer = 0;
	if (position >= half) 
	{
		//printf("%d\n is closer to end\n", min);
		return (closer = 1);
	}
	else if (position < half) 
	{
		//printf("%d\n is closer to start\n", min);
		return (closer);
	}
}

void	sort_nums(stack *s, stack *p, int min, int position)
{
	if (position == 1) 
	{
		while (s->contents[s->top - 1] != min) 
		{
			ra(s);
		}
	}
	else if (position == 0) 
	{
		while (s->contents[s->top - 1] != min) 
		{
			rra(s);
		}
	}
}

void	sort_stack(stack *s, stack *p)
{
	int	len;
	int	half;
	int	min;

	while (!is_empty(s)) 
	{
		len = s->top;
		half = len / 2;
		//print_stack(s);
		////print_stack(p);
		////printf("Length is %d\n", len);
		////printf("Half is %d\n", half);
		min = find_min(s);
		////printf("Min in stack s is %d\n", min);
		int closer = where_is_min(s);
		//printf("%d is rank %d which means it worked\n", min, closer);
		sort_nums(s, p, min, closer);
		pb(p, s);
		printf("pb\n");
		int y = p->top - 1;
		//printf("Number at top should be %d which is %d\n", min, p->contents[y]);
	}
	//print_stack(p);
	while (!is_empty(p)) 
	{
		pb(s, p);
	}
}
    
 int	main(void)
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

    push(&s, 2);
    push(&s, 1);
    push(&s, 3);
    push(&s, 6);
    push(&s, 5);
    push(&s, 8);

    printf("Unsorted stack s: \n");
    print_stack(&s);
    sort_stack(&s, &p);

    printf("Sorted stacks:\n");
    print_stack(&s);
    print_stack(&p);
    return (0);
}
