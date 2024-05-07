#include "push_swap.h"

void	a_to_b(t_mem *a, t_mem *b, int chunk, int chunk_done)
{
	int	count;

	while (a->size > chunk)
	{
		count = 0;
		while (count < chunk)
		{
			while (a->sorted[0] > chunk * chunk_done)
				rotate(a);
			if (a->sorted[0] < chunk * chunk_done - (chunk / 2))
				push(a, b);
			else
			{
				push(a, b);
				if (b->size > 1)
					rotate(b);
			}
			count++;
		}
		chunk_done = chunk_done + 1;
	}
}

void	b_to_a(t_mem *a, t_mem *b)
{
	int	i;

	while (a->size != 0)
		push(a, b);
	while (b->size != 0)
	{
		i = max_index(b);
		if (i <= b->size / 2)
		{
			while (i > 0)
			{
				rotate(b);
				i--;
			}
		}
		else
		{
			while (i < b->size)
			{
				reverse_rotate(b);
				i++;
			}
		}
		push(b, a);
	}
}

void	algo(t_mem *a, t_mem *b)
{
	int	chunk;
	int	chunk_done;

	chunk_done = 1;
	if (a->size <= 100)
		chunk = 20;
	else
		chunk = 70;
	a_to_b(a, b, chunk, chunk_done);
	b_to_a(a, b);
}