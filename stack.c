#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

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
    while (i < size)
    {
        if (top(a) < mid)
        {
            pb(b, a);
            moved++;
        }
        else if (top(a) >= mid)
        {
            ra(a);
        }
        i++;
    }
    return (moved);
}

void sortThree(stack *a) 
{
    // Assuming top of the stack is the last element in the array representation
    int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];
    int bottom = a->contents[a->top - 3];
    int move = 0;

    // Case 1
    if (top > middle && top < bottom && middle < bottom) 
    {
        sa(a);
        printf("sa\n");
        move++;
    }

    //Case 2
    else if (top > middle && top > bottom && middle < bottom) 
    {
        sa(a);
        rra(a);
        printf("sa\n");
        printf("rra\n");
        move+=2;
    }

    //Case 3
    else if (top > middle && top > bottom && middle < bottom) 
    {
        ra(a);
        printf("ra\n");
        move++;
    }

    //Case 4
    else if (top < middle && top < bottom && middle > bottom) 
    {
        sa(a);
        ra(a);
        printf("sa\n");
        printf("ra\n");
        move +=2;
    }

    //Case 5
    else if (top < middle && top > bottom && middle > bottom) 
    {
        rra(a);
        printf("rra\n");
        move++;
    }

    else 
    {
        return ;
    }
    printf("Moves taken: %d\n", move);
}

// Assuming sortThree and other stack operations are already defined

// Function to analyze stack and partition based on midpoint
void sortAndPartition(stack *a, stack *b) 
{
    int size = a->top;
    int *arr = CMS_array(a); // Combine create & sort array into one function
    int mid = find_midpoint(arr, size);
    
    // Free array if you're done with it
    free(arr);
    
    // Partition elements below the midpoint to B
    partition_BOM(a, b, mid);
    
    // If A has 3 elements left, sort them
    if (a->top <= 3) 
    {
        sortThree(a);
    }

    int biggest = top(a);
    
    while (!is_empty(b)) 
    {
        pa(a, b);
        printf("pa\n");
    }

    while (top(a) != biggest) 
    {
        rra(a);
        printf("rra\n");
    }
  
        /*ra(a);
        printf("ra\n");
        ra(a);
        printf("ra\n");
    }*/
    // Additional logic to handle elements in B and possibly move them back to A
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

int main(void)
{
    stack a;
    stack b;
    make_empty(&a);
    make_empty(&b);

    push(&a, 4);
    push(&a, 5);
    push(&a, 1);
    push(&a, 3);
    push(&a, 2);
    
    printf("Before\n");
    print_stack(&a);

    sortAndPartition(&a, &b);

    printf("After\n");
    print_stack(&a);
    print_stack(&b);
    return (0);
}


































/*int *move_array(stack *s)
{
    int len = s->top;
    int *arr = malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i = 0;

    while (i < len)
    {
        arr[i] = s->contents[len - i - 1];
        i++;
    }
    return arr;
}

void sort_array(int *arr, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - 1 - i)
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
}

int find_midpoint(int *arr, int size)
{
    int mid = size / 2;
    int mid_element = arr[mid];
    return (mid_element);
}

int top(stack *s)
{
    return (s->contents[s->top - 1]);
}

int partition_stack(stack *s, stack *b, int mid)
{
    int moved = 0;
    int size = s->top;
    int i = 0;
    while (i < size)
    {
        if (top(s) < mid)
        {
            pb(b, s);
            moved++;
        }
        else if (top(s) >= mid)
        {
            ra(s);
        }
        i++;
    }
    return (moved);
}

void recursive_sort_stack(stack *s, stack *p, int size)
{
    if (size <= 1)
    {
        return;
    }

    int *arr = move_array(s);
    sort_array(arr, size);
    
    int mid = find_midpoint(arr, size);
    free(arr);

    int moved = partition_stack(s, p, mid);

    //recursive_sort_stack(p, s, moved);
    
   //recursive_sort_stack(s, p, moved);
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

int main(void)
{
    stack s;
    make_empty(&s); // Initialize the stack to ensure 'top' is correctly set.

    stack p;
    make_empty(&p);

    push(&s, 2);
    push(&s, 3);
    push(&s, 5);
    push(&s, 12);
    push(&s, 10);
    push(&s, 6);
    push(&s, 9);
    push(&s, 7);
    push(&s, 4);
    push(&s, 1);
    push(&s, 8);
    push(&s, 11);

    int size = s.top;

    printf("Stack a contents before:\n");
    print_stack(&s);
        printf("Stack b contents before:\n");
    print_stack(&p);

    recursive_sort_stack(&s, &p, 5);

        printf("Stack a contents after:\n");
    print_stack(&s);
    printf("Stack b contents after:\n");
    print_stack(&p);

    return (0);
}

int find_min(stack *s)
{
    int	len;
    int	min;

    len = s->top;
    min = s->contents[s->top - 1];
    while (len > 0)
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
    int j = 0;
    while (j < s->top)
    {
        if (s->contents[j] == value)
        {
            return (j);
        }
        j++;
    }
    return (-1);
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
        return (closer = 1);
    }
    else
    {
        return (closer = 0);
    }
}

void	sort_nums(stack *s, int min, int position)
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

void	sort_stack(stack *s)
{
    int	min;
    int count = 0;
    stack p;

    while (!is_empty(s))
    {
        min = find_min(s);
        int closer = where_is_min(s);
        sort_nums(s, min, closer);
        pb(&p, s);
        count++;
        printf("pb\n");
        printf("Number of steps: %d\n", count);
    }
    while (!is_empty(&p))
    {
        pa(s, &p);
        printf("pa\n");
        printf("Number of steps: %d\n", count);
        count++;
    }
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

int	main(int argc, char **argv)
{
    if (argc != 2)
    {
        return (-1);
    }
    stack s;
    stack p;
    make_empty(&s);
    make_empty(&p);

    int i = 0;
    int num = 0;
    while (argv[1][i] != '\0')
    {
        num = argv[1][i] - '0';
        if (num >= 0 && num <= 9)
        {
            push(&s, num);
        }
        else
        {
            printf("Invalid number!\n");
            return (-1);
        }
        i++;
        num = 0;
    }

    printf("Unsorted stack s: \n");
    print_stack(&s);
    sort_stack(&s);

    printf("Sorted stacks:\n");
    print_stack(&s);
    return (0);
}*/