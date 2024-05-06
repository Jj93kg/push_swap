#include "stack_tactical20.h"

void make_empty(stack *a);
bool is_empty(const stack *a);
bool is_full(const stack *a);
int num_in_stack(stack *a);
void push(stack *a, int i);
int pop(stack *a);
void sa(stack *a);
void sb(stack *a);
void ss(stack *a, stack *b);
void pa(stack *a, stack *b);
void pb(stack *b, stack *a);
void ra(stack *a);
void rb(stack *s);
void rr(stack *s, stack *p);
void rra(stack *s);
void rrb(stack *s);
void rrs(stack *s, stack *p);
void print_stack(const stack *a);
int *CMS_array(stack *s);
int *CMS_array_chunk(stack *a, int chunkSize);
int find_midpoint(int *arr, int size);
int top(stack *a);
int bottom(stack *a);
void sortTwo(stack *a);
void sortTwo_A(stack *a);
void midpoint_algo(stack *a, stack *b, int chunk, int chunks_done);
void reverse_midpoint_algo(stack *a, stack *b);
void recursive_sort(stack *a, stack *b);

int sa_count = 0;
int sb_count = 0;
int ss_count = 0;
int pa_count = 0;
int pb_count = 0;
int ra_count = 0;
int rb_count = 0;
int rr_count = 0;
int rra_count = 0;
int rrb_count = 0;
int rrr_count = 0;

void make_empty(stack *a)
{
    a->top = 0;
}

bool is_empty(const stack *a)
{
    return a->top == 0;
}

bool is_full(const stack *a)
{
    return a->top == STACK_SIZE;
}

int num_in_stack(stack *a)
{
    int i = 0;
    while (i < a->top)
    {
        i++;
    }
    return (i);
}

void push(stack *a, int i)
{
    if (is_full(a))
    {
        return;
    }
    else
    {
        a->contents[a->top++] = i;
    }
}

int pop(stack *a)
{
    if (is_empty(a))
    {
        printf("Error popping: empty stack!\n");
        return -1; // Return an error code
    }
    else
    {
        return a->contents[--a->top];
    }
}

void sa(stack *a)
{
    if (a->top < 2)
    {
        return;
    }
    else
    {
        int temp;
        temp = a->contents[a->top - 1];
        a->contents[a->top - 1] = a->contents[a->top - 2];
        a->contents[a->top - 2] = temp;
    }
}

void sb(stack *a)
{
    if (a->top < 2)
    {
        return;
    }
    else
    {
        int temp;

        temp = a->contents[a->top - 1];
        a->contents[a->top - 1] = a->contents[a->top - 2];
        a->contents[a->top - 2] = temp;
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

void ra(stack *a)
{
    if (a->top < 2)
    {
        return;
    }
    else
    {
        int last = a->contents[a->top - 1];
        int i = a->top - 1;
        while (i > 0)
        {
            a->contents[i] = a->contents[i - 1];
            i--;
        }
        a->contents[0] = last;
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

void rrb(stack *s)
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

    // Allocation
    int *arr = malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i = 0;

    // Copying
    while (i < len)
    {
        arr[i] = s->contents[len - i - 1];
        i++;
    }

    // Sorting
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

int *CMS_array_chunk(stack *a, int chunkSize)
{
    int len = chunkSize;

    // Allocation
    int *arr = malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i = 0;

    // Copying
    while (i < len)
    {
        arr[i] = a->contents[a->top - i - 1];
        i++;
    }

    // Sorting
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

int bottom(stack *a)
{
    if (a->top > 0)
    {
        return a->contents[0];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void sortTwo(stack *a)
{
    int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];

    // Case for 2 numbers
    if (top > middle)
    {
        return;
    }

    else if (top < middle)
    {
        sa(a);
        printf("sa\n");
        sa_count++;
    }
}

int find_smallest(stack *s)
{
    if (is_empty(s))
    {
        return (-1);
    }

    int smallest = s->contents[0];
    int i = 1;
    while (i < s->top)
    {
        if (s->contents[i] < smallest)
        {
            smallest = s->contents[i];
        }
        i++;
    }
    printf("Largest is %d\n", smallest);
    return (smallest);
}

int find_biggest(stack *s)
{
    if (is_empty(s))
    {
        return (-1);
    }

    int biggest = s->contents[0];
    int i = 1;
    while (i < s->top)
    {
        if (s->contents[i] > biggest)
        {
            biggest = s->contents[i];
        }
        i++;
    }
    printf("Largest is %d\n", biggest);
    return (biggest);
}

int find_index_of_element(stack *s, int target)
{
    if (is_empty(s))
    {
        return (-1);
    }
    int index = 0;
    int i = s->top - 1;
    while (i >= 0)
    {
        if (s->contents[i] == target)
        {
            index = i;
            return (index);
        }
        i--;
    }
    return (-1);
}

int find_biggest_in_chunk(stack *s, int min_val, int max_val) {
    if (is_empty(s)) {
        return -1; // Indicate an error or that the stack is empty.
    }

    int biggest = INT_MIN; // Use INT_MIN to ensure any stack value is larger.
    int biggestFound = 0; // Flag to check if we found any number in the range.

    for (int i = s->top - 1; i >= 0; i--) {
        if (s->contents[i] >= min_val && s->contents[i] <= max_val) {
            if (s->contents[i] > biggest) {
                biggest = s->contents[i];
                biggestFound = 1;
            }
        }
    }

    if (!biggestFound) {
        return -1; // Indicate no element was found within the range.
    }

    printf("Largest in range [%d, %d] is %d\n", min_val, max_val, biggest);
    printf("And %d is currently at index %d\n", biggest, find_index_of_element(s, biggest));
    printf("Entire stack has %d elements at %d is at top\n", num_in_stack(s), top(s));
    return biggest;
}


int find_index_of_smallest(stack *s)
{
    if (is_empty(s))
    {
        return (-1);
    }

    int smallest = s->contents[0];
    int index = 0;
    int i = 1;
    while (i < s->top)
    {
        if (s->contents[i] < smallest)
        {
            smallest = s->contents[i];
            index = i;
        }
        i++;
    }
    return (index);
}

int find_index_of_biggest(stack *s)
{
    if (is_empty(s))
    {
        return (-1);
    }

    int biggest = s->contents[0];
    int index = 0;
    int i = 1;
    while (i < s->top)
    {
        if (s->contents[i] > biggest)
        {
            biggest = s->contents[i];
            index = i;
        }
        i++;
    }
    printf("Largest is %d\n", biggest);
    printf("It's index is %d\n", index);
    printf("Entire index of stack is %d\n", num_in_stack(s));
    int rotationalIndex = s->top - 1 - index;
    printf("You'd need to move element either rb or rrb %d times\n", rotationalIndex);
    return (index);
}

void sortTwo_A(stack *a)
{
    int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];

    // Case for 2 numbers
    if (top < middle)
    {
        return;
    }

    else if (top > middle)
    {
        sa(a);
        printf("sa\n");
        sa_count++;
    }
}

void sortThree(stack *a)
{
    // Assuming top of the stack is the last element in the array representation
    int top = a->contents[a->top - 1];
    int middle = a->contents[a->top - 2];
    int bottom = a->contents[a->top - 3];

    // Case 2
    if (top < middle && top < bottom && middle > bottom)
    {
        ra(a);
        printf("ra\n");
        ra_count++;
        sa(a);
        printf("sa\n");
        sa_count++;
    }

    // Case 3
    else if (top > middle && top < bottom && middle < bottom)
    {
        sa(a);
        printf("sa\n");
        sa_count++;
    }

    // Case 4
    else if (top > middle && top > bottom && middle > bottom)
    {
        rra(a);
        printf("rra\n");
        rra_count++;
        sa(a);
        printf("sa\n");
        sa_count++;
    }

    // Case 5
    else if (top < middle && top > bottom && middle > bottom)
    {
        ra(a);
        printf("ra\n");
        ra_count++;
    }

    // Case 6
    else if (top > middle && top > bottom && middle < bottom)
    {
        rra(a);
        printf("rra\n");
        rra_count++;
    }

    // Case 1
    else
    {
        return;
    }
}

void sortFive(stack *a, stack *b)
{
    // Step 1: Identify and move 2 elements to stack b, typically min or max
    int i = 0;
    while (i < 2)
    {
        int max_index = find_index_of_biggest(a);
        while (a->top - 1 != max_index)
        {
            // Rotate or reverse rotate based on position of minIndex
            if (max_index < a->top / 2)
            {
                ra(a);
                printf("ra\n");
                rra_count++;
            }
            else
                rra(a);
            printf("rra\n");
            rra_count++;
        }
        pb(b, a); // Move identified element to stack b
        printf("pb\n");
        pb_count++;
        i++;
    }

    // Step 2: Sort the remaining 3 elements in stack a
    sortThree(a);
}

int find_next_eligible_number_index(stack *a, int chunk_min, int chunk_max)
{
    int topIndex = a->top - 1;             // Index of the topmost element
    int closestIndex = -1;                 // Initialize with -1 indicating no index found yet
    int shortestDistanceFromTop = INT_MAX; // Initialize with the maximum possible distance

    // Search from top to bottom
    for (int i = topIndex; i >= 0; i--)
    {
        int num = a->contents[i];
        if (num >= chunk_min && num <= chunk_max)
        {
            int distanceFromTop = topIndex - i;
            if (distanceFromTop < shortestDistanceFromTop)
            {
                shortestDistanceFromTop = distanceFromTop;
                closestIndex = i; // Save the index closer to the top
            }
            break; // Stop the search once the first eligible number is found
        }
    }
    printf("Eligible number from top is at position %d\n", closestIndex);

    // Reset shortest distance for the bottom-up search comparison
    int shortestDistanceFromBottom = INT_MAX;

    // Search from bottom to top
    for (int i = 0; i <= topIndex; i++)
    {
        int num = a->contents[i];
        if (num >= chunk_min && num <= chunk_max)
        {
            int distanceFromBottom = i;
            if (distanceFromBottom < shortestDistanceFromBottom)
            {
                shortestDistanceFromBottom = distanceFromBottom;
                printf("Num in stack is %d\n", num_in_stack(a));
                printf("Eligible number from bottom is at position %d\n", shortestDistanceFromBottom);
                // print_stack(a);
                //  Only update if this bottom-up found number is closer to the top than the top-down found number
                if (topIndex - i < shortestDistanceFromTop)
                {
                    printf("Eligible number from bottom is closer!\n");
                    closestIndex = i; // Update index to the one that's closer from the bottom
                }
            }
            break; // Stop the search once the first eligible number is found
        }
    }

    return closestIndex; // Return the index of the closest eligible number
}

int conditions_for_rr(stack *b, int chunk_min, int chunk_max)
{
    int big = find_biggest_in_chunk(b, chunk_min, chunk_max);
    printf("Biggest in top chunk is %d\n", big);
    printf("Top of B is %d\n", top(b));
    print_stack(b);
    if (top(b) != big)
    {
        printf("Biggest in B, %d isn't at top as that is %d\n", big, top(b));
        print_stack(b);
        int index = find_index_of_biggest(b);
        int rotationalIndex = b->top - index - 1;
        printf("Biggest in b is %d\n", big);
        printf("To bring Biggest number %d in B to top would take %d operations\n", big, rotationalIndex);
        return (rotationalIndex);
    }
    else 
    {
        return (0);
    }
}

void optimize_path_to_eligible_number(stack *a, stack *b, int chunk_min, int chunk_max)
{
    int index = find_next_eligible_number_index(a, chunk_min, chunk_max);
    printf("index of next eligible number are %d\n", index);
    if (index == -1)
    {
        return; // No eligible number found.
    }

    int total_elements = a->top;
    bool useRA = index > total_elements / 2;
    int rotationsNeeded = useRA ? total_elements - index - 1 : index;

    printf("Rotations needed are %d\n", rotationsNeeded);
    while (rotationsNeeded > 0)
    {
        int result = conditions_for_rr(b, chunk_min, chunk_max);
        if (useRA && result) 
        {
            printf("Conditions for rr have been met.\n");
            print_stack(a);
            print_stack(b);
            while (rotationsNeeded > 0 && result > 0)
            {
                rr(a, b);
                printf("rr\n");
                rr_count++;
                result--;
            }
        }
        else if (useRA)
        {
            ra(a); // If closer to the bottom, reverse rotate
            printf("ra\n");
            ra_count++;
        }
        else
        {
            rra(a); // If closer to the top, rotate upwards
            printf("rra\n");
            rra_count++;
        }
        rotationsNeeded--;
    }
}

void midpoint_algo(stack *a, stack *b, int chunks, int chunks_done)
{
    // int *array = CMS_array(a);
    int moved;
    int total_max = num_in_stack(a);
    int total_min = total_max - chunks;

    while (a->top > 1)
    {
        int *array = CMS_array(a);
        if (a->top >= chunks)
        {
            while (a->top >= chunks)
            {
                moved = 0;
                while (moved < chunks)
                {
                    int min_chunk = array[(chunks_done - 1) * chunks - 1];
                    int max_chunk = array[(chunks_done)*chunks - 1];
                    printf("Min Chunk: Chunks done is %d and so chunks done - 1 is %d\n which means min chunk should be %d but it is %d\n", chunks_done, chunks_done - 1, (chunks_done - 1) * chunks, min_chunk);
                    printf("Max chunk: Chunks done is %d and chunks is %d so together it should be %d but it is %d\n", chunks_done, chunks, chunks_done * chunks, max_chunk);

                    if (top(a) > chunks * chunks_done)
                    {
                        printf("Current number at top %d is too big to be considered\n", top(a));
                        optimize_path_to_eligible_number(a, b, min_chunk, max_chunk);
                        printf("New top after pathing %d is good to go!\n", top(a));
                        pb(b, a);
                        printf("pb\n");
                        pb_count++;
                        moved++;
                        if (!is_empty(b))
                        {
                            if (top(b) < b->contents[b->top - 2])
                            {
                                if (top(a) > a->contents[a->top - 2]) 
                                {
                                    ss(a, b);
                                    printf("ss\n");
                                    ss_count++;
                                }
                                else 
                                {
                                    sb(b);
                                    printf("sb\n");
                                    sb_count++;
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("%d is smallerer than chunk * chunks_done(%d)\n", top(a), chunks * chunks_done);
                        pb(b, a);
                        printf("pb\n");
                        pb_count++;
                        moved++;
                        if (!is_empty(b))
                        {
                            if (top(b) < b->contents[b->top - 2])
                            {
                                if (top(a) > a->contents[a->top - 2]) 
                                {
                                    ss(a, b);
                                    printf("ss\n");
                                    ss_count++;
                                }
                                else 
                                {
                                    sb(b);
                                    printf("sb\n");
                                    sb_count++;
                                }
                            }
                        }
                    }
                    printf("%d moved\n", moved);
                }
                chunks_done++;
            }
        }
        else
        {
            printf("Else actually hits!\n");
            printf("There are %d elements left in stack a\n", num_in_stack(a));
            int moved = 0;
            int half = a->top / 2;
            array = CMS_array(a);
            int mid = find_midpoint(array, a->top);
            while (moved < half && !is_empty(a))
            {   
                if (top(a) < mid)
                {
                    if (top(a) > a->contents[a->top - 2])
                    {
                        if (top(b) < b->contents[b->top - 2])
                        {
                            ss(a, b);
                            printf("ss\n");
                            ss_count++;
                            pb(b, a);
                            pb(b, a);
                            printf("pb\n");
                            printf("pb\n");
                            pb_count+=2; 
                            moved +=2;
                        }
                        else
                        {
                            sa(a);
                            printf("sa\n");
                            sa_count++;
                            pb(b, a);
                            pb(b, a);
                            printf("pb\n");
                            printf("pb\n");
                            pb_count+=2;
                            moved+=2;
                        }
                    }
                    else
                    {
                        printf("Element %d is less than %d\n", top(a), mid);
                        pb(b, a);
                        printf("pb\n");
                        moved++;
                        pb_count++;
                    }
                }
                else
                {
                    break;
                }
            }
            // If not moved enough, try from bottom
            if (moved < half && !is_empty(a))
            {
                while (moved < half)
                {
                    if (bottom(a) < mid)
                    {
                        printf("Element %d is less than %d\n", bottom(a), mid);
                        rra(a);
                        pb(b, a);
                        printf("rra\n");
                        printf("pb\n");
                        rra_count++;
                        pb_count++;
                        moved++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            // Again if not enough, try from top
            if (moved < half && !is_empty(a))
            {
                while (!is_empty(a) && moved < half)
                {
                    if (top(a) < mid)
                    {
                        printf("Found element less than %d, moving it.\n", mid);
                        pb(b, a);
                        printf("pb\n");
                        pb_count++;
                        moved++;
                    }
                    else
                    {
                        if (b->contents[b->top - 1] < b->contents[b->top - 2]) 
                        {
                            rr(a, b);
                            printf("rr\n");
                            rr_count++;
                        }
                        else 
                        {
                            printf("Element %d is not less than %d, rotating...\n", top(a), mid);
                            ra(a);
                            printf("ra\n");
                            ra_count++;
                        }
                    }
                }
            }
            if (top(a) > a->contents[a->top - 2])
            {
                if (top(b) < b->contents[b->top - 2] && top(a) > a->contents[a->top - 2])
                {
                    ss(a, b);
                    printf("ss\n");
                    ss_count++;
                }
                else
                {
                    sa(a);
                    printf("sa\n");
                    sa_count++;
                }
            }
            else if (top(b) < b->contents[b->top - 2]) 
            {
                if (top(b) < b->contents[b->top - 2] && top(a) > a->contents[a->top - 2])
                {
                    ss(a, b);
                    printf("ss\n");
                    ss_count++;
                }
                else 
                {
                    sb(b);
                    printf("sb\n");
                    sb_count++;
                }
            }
            printf("%d elements moved\n", moved);
            printf("Stacks after rotation are \n");
            print_stack(a);
            print_stack(b);
        }
    }
    printf("Chunks done is %d\n", chunks_done);
}

void reverse_midpoint_algo(stack *a, stack *b)
{
    while (!is_empty(b))
    {
        int half = b->top / 2;
        int biggest_element_index = find_index_of_biggest(b);
        int rotationalIndex = b->top - 1 - biggest_element_index;
        if (biggest_element_index >= half)
        {
            if (rotationalIndex == 0)
            {
                printf("No need to rotate shit, it was already top of stack as it is %d\n", top(b));
                printf("About to move %d\n", top(b));
                pa(a, b);
                printf("pa\n");
                pa_count++;
            }
            else
            {
                printf("It isn't top but it is near top of stack, it is %d elements away from top\n", rotationalIndex);
                int i = 0;
                while (i < rotationalIndex)
                {
                    rb(b);
                    printf("rb\n");
                    rb_count++;
                    i++;
                }
                printf("About to move %d\n", top(b));
                pa(a, b);
                printf("pa\n");
                pa_count++;
            }
        }
        else
        {
            if (biggest_element_index == 0)
            {
                printf("Need to rotate down once to bring it up, it was already bottom of stack as it is %d\n", bottom(b));
                rrb(b);
                rrb_count++;
                printf("rrb\n");
                printf("About to move %d\n", top(b));
                pa(a, b);
                pa_count++;
                printf("pa\n");
            }
            else
            {
                printf("It isn't top and it's near bottom of stack, it's %d elements away from bottom\n", biggest_element_index);
                int i = 0;
                while (i <= biggest_element_index)
                {
                    rrb(b);
                    printf("rrb\n");
                    rrb_count++;
                    i++;
                }
                printf("About to move %d\n", top(b));
                pa(a, b);
                printf("pa\n");
                pa_count++;
            }
        }
    }
}

void sort_stack(stack *a, stack *b)
{
    int chunks = 22;
    int chunks_done = 1;
    midpoint_algo(a, b, chunks, chunks_done);
    //printf("Chunks after moving from a to b are \n");
    //print_stack(a);
    //print_stack(b);
    reverse_midpoint_algo(a, b);
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
        push(&a, num);           // Push the number onto the stack
    }

    printf("Unsorted stacks are: \n");
    print_stack(&a);
    print_stack(&b);

    sort_stack(&a, &b);
    printf("Sorted stacks are: \n");
    print_stack(&a);
    print_stack(&b);

    printf("sa count is %d\n", sa_count);
    printf("sb count is %d\n", sb_count);
    printf("ss count is %d\n", ss_count);
    printf("pa count is %d\n", pa_count);
    printf("pb count is %d\n", pb_count);
    printf("ra count is %d\n", ra_count);
    printf("rb count is %d\n", rb_count);
    printf("rr count is %d\n", rr_count);
    printf("rra count is %d\n", rra_count);
    printf("rrb count is %d\n", rrb_count);
    printf("rrr count is %d\n", rrr_count);

    printf("Total moves is %d\n", sa_count + sb_count + ss_count + pa_count + pb_count + ra_count + rb_count + rr_count + rra_count + rrb_count + rrr_count);
    return 0;
}