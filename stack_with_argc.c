
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void sortTwo(stack *a);
void sortThree(stack *a);

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
        return;
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

void print_stack(const stack *a)
{
    printf("Stack contents (top to bottom): ");
    int i = a->top - 1;
    printf("\n");
    while (i >= 0)
    {
        printf("%d\n", a->contents[i]);
        i--;
    }
    printf("\n");
}

int *CMS_array(stack *s)
{
    int len = s->top;

    //Allocation
    int *arr = malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    int i = 0;

    //Copying
    while (i < len)
    {
        arr[i] = s->contents[len - i - 1];
        i++;
    }

    //Sorting
    i = 0;
    while (i < len - 1)
    {
        int j = 0;
        while (j < len - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }

    return arr;
}

int find_midpoint(int *arr, int size)
{
    int mid = size / 2;
    int mid_element = arr[mid];
    return (mid_element);
}

int top(stack *a)
{
    return (a->contents[a->top - 1]);
}

int partition_BOM(stack *a, stack *b, int mid)
{
    int moved = 0;
    int size = a->top;
    int i = 0;
    int biggest = 0;
    int hugest = 0;
    while (i < size)
    {
        if (top(a) < mid)
        {
            pb(b, a);
	    printf("pb\n");
	    moved++;
	    if (top(b) > biggest) 
	    {
		    biggest = top(b);
		    printf("Biggest is now %d\n", biggest);
	    } 
        }
        else if (top(a) >= mid)
        {
		ra(a);
		printf("ra\n");
		moved++;
        }
        i++;
    }
    printf("Stacks after partitioning to a and b and sorting b\n");
    print_stack(a);
    print_stack(b);
    while (!is_empty(a) && a->top != 3) 
    {
	    pb(b, a);
	    printf("pb\n");
	    moved++;
    }
    printf("Stacks after moving unsorted a to sorted b\n");
    print_stack(a);
    print_stack(b);

    sortThree(a);
    printf("Stacks after sorting what's left in stack a and rest in b\n");
    print_stack(a);
    print_stack(b);

    while (!is_empty(a)) 
    {
	    pb(b, a);
	    printf("pb\n");
	    moved++;
    }
    printf("Stacks after moving sorted 3 elements a to stack b\n");
    print_stack(a);
    print_stack(b);
    return (moved);
}

int	num_in_stack(stack *s)
{
	int i = 0;
	while (i < s->top) 
	{
		i++;
	}
	return (i);
}

void sortTwo(stack *a)
{
	  int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];

	// Case for 2 numbers
    if (top < middle)
    {
            return ;
    }

    else if (top > middle)
    {
            sa(a);
    }
}

void sortThree(stack *a) 
{
    // Assuming top of the stack is the last element in the array representation
    int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];
    int bottom = a->contents[a->top - 3];
    int move = 0;

    //Case 2
    if (top < middle && top < bottom && middle > bottom) 
    {
	    ra(a);
	    printf("ra\n");
	    sa(a);
	    printf("sa\n");
	    move += 2;
    }

    //Case 3
    else if (top > middle && top < bottom && middle < bottom) 
    {
	    sa(a);
	    printf("sa\n");
	    move++;
    }

    //Case 4
    else if (top > middle && top > bottom && middle > bottom) 
    {
	    rra(a);
	    printf("rra\n");
	    sa(a);
	    printf("sa\n");
	    move+=2;
    }

    //Case 5
    else if (top < middle && top > bottom && middle > bottom) 
    {
        ra(a);
	printf("ra\n");
        move++;
    }
    
    // Case 6
    else if (top > middle && top > bottom && middle < bottom)
    {
            rra(a);
	    printf("rra\n");
	    move++;
    }
    
    //Case 1
    else 
    {
	    printf("Moves taken to sort stack: %d\n", move);
        return ;
    }
    printf("Moves taken to sort stack: %d\n", move);
}

int main(int argc, char **argv)
{
    // Remove the check that forces exactly one additional argument
    stack a;
    stack b;
    make_empty(&a);
    make_empty(&b);

    // Start from i = 1 to skip the program name
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]); // Convert each argument to an integer
        push(&a, num); // Push the number onto the stack
    }

    printf("Unsorted stack a: \n");
    print_stack(&a);




    // Your sorting logic goes here...
    int	*array = CMS_array(&a);
    int y = 0;
    int len = a.top;
    printf("Length is %d\n", len);
    while (y < len) 
    {
	    printf("%d ", array[y]);
	    y++;
    }
    int mid = find_midpoint(array, len);
    printf("Midpoint is %d\n", mid);
    int moved = partition_BOM(&a, &b, mid);
    printf("Sorted stack a: \n");
    print_stack(&a);
    printf("Took %d many moves\n", moved);

    return 0;
}
