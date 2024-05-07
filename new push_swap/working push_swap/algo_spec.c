#include "push_swap.h"

void	algo_2(t_mem *a)
{
	if (a->sorted[0] > a->sorted[1])
		swap(a);
}

void	algo_3(t_mem *a)
{
	int	mm[2];

	mm[0] = minimum(a);
	mm[1] = maximum(a);
	if (a->sorted[0] == mm[0])
	{
		if (a->sorted[2] == mm[1])
			return ;
		else
			rs(a);
	}
	else if (a->sorted[0] != mm[0] && a->sorted[0] != mm[1])
	{
		if (a->sorted[2] == mm[0])
			reverse_rotate(a);
		else
			swap(a);
	}
	else if (a->sorted[0] == mm[1])
	{
		if (a->sorted[2] == mm[0])
			sr(a);
		else
			rotate(a);
	}
}

void	algo_5(t_mem *a, t_mem *b)
{
	while (a->size > 3)
	{
		if (a->sorted[0] == minimum(a))
			push(a, b);
		if (a->size / 2 <= min_index(a))
			reverse_rotate(a);
		else
			rotate(a);
	}
	algo_3(a);
	while (b->size > 0)
		push(b, a);
}