#include "push_swap.h"

int	minimum(t_mem *a)
{
	int	i;
	int	min;

	min = a->sorted[0];
	i = 0;
	while (i < a->size)
	{
		if (a->sorted[i] < min)
		{
			min = a->sorted[i];
		}
		i++;
	}
	return (min);
}

int	maximum(t_mem *a)
{
	int	i;
	int	max;

	max = a->sorted[0];
	i = 0;
	while (i < a->size)
	{
		if (a->sorted[i] > max)
		{
			max = a->sorted[i];
		}
		i++;
	}
	return (max);
}

void	rs(t_mem *a)
{
	reverse_rotate(a);
	swap(a);
}

void	sr(t_mem *a)
{
	swap(a);
	reverse_rotate(a);
}