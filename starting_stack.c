#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int	stack[256];
int	count = 0;

void push(int x)
{
	if (count == 256) 
	{
		printf("No space\n");
		return ;
	}
	stack[count] = x;
	count++;
}

int	pop() 
{
	if (count == 0) 
	{
		printf("Nothing to take\n");
		return 0;
	}
	int	res;

	res = stack[count - 1];
	count--;
	return (res);
}

bool	is_full(void)
{
	if (stack[count + 1] > 256) 
	{
		printf("Stack is full!");
		return (0);
	}
}

int	main(void)
{
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);

	int i;

	i = 0;
	while (i < 4) 
	{
		printf("%d\n", pop());
		i++;
	}
	return (0);
}
