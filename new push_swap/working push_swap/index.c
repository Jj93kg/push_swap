#include "push_swap.h"

int	max_index(t_mem *atoi)
{
	int	max;
	int	i;
	int	index_max;

	max = atoi->sorted[0];
	index_max = 0;
	i = -1;
	while (++i < atoi->size)
	{
		if (atoi->sorted[i] > max)
		{
			max = atoi->sorted[i];
			index_max = i;
		}
	}
	return (index_max);
}

int	min_index(t_mem *atoi)
{
	int	min;
	int	index_min;
	int	i;

	i = -1;
	index_min = 0;
	min = atoi->sorted[0];
	while (++i < atoi->size)
	{
		if (atoi->sorted[i] < min)
		{
			min = atoi->sorted[i];
			index_min = i;
		}
	}
	return (index_min);
}

int	*indexation(t_mem *atoi, t_mem *mem)
{
	int	i;
	int	min_to_max;

	mem->sorted = malloc(mem->size * sizeof(long));
	i = -1;
	min_to_max = 0;
	while (++i < mem->size)
	{
		mem->sorted[min_index(atoi)] = min_to_max;
		atoi->sorted[min_index(atoi)] = INT_MAX;
		min_to_max++;
	}
	return (0);
}

int	is_sorted(t_mem *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->sorted[i] > stack->sorted[i + 1])
			return (0);
		else
			i++;
	}
	exit(0);
}