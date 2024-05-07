#include "push_swap.h"

t_mem	*error_check(int ac, char **av, t_mem *mem)
{
	t_mem	*atoi;

	digit_error(ac, av);
	atoi = atoi_args(ac, av, mem);
	double_error(atoi);
	return (atoi);
}

void	init_stack(t_list *stack, int ac, char **av)
{
	stack->a.size = 0;
	stack->a.name = 'a';
	stack->a.sorted = NULL;
	indexation(error_check(ac, av, &stack->a), &stack->a);
	is_sorted(&stack->a);
	stack->b.sorted = malloc(stack->a.size * sizeof(long));
	stack->b.name = 'b';
}

void	free_stack(t_mem *atoi, t_mem *mem)
{
	free (atoi->sorted);
	atoi->sorted = NULL;
	free (atoi);
	atoi = NULL;
	free(mem->sorted);
	mem->sorted = NULL;
}

int	main(int ac, char **av)
{
	t_list	stack;
	int		i;

	init_stack(&stack, ac, av);
	i = 0;
	while (stack.a.size > i)
	{
		stack.b.sorted[i] = -1;
		i++;
	}
	stack.b.size = 0;
	if (stack.a.size == 1)
		return (0);
	if (stack.a.size == 2)
		algo_2(&stack.a);
	if (stack.a.size == 3)
		algo_3(&stack.a);
	if (stack.a.size == 4)
		algo(&stack.a, &stack.b);
	if (stack.a.size == 5)
		algo_5(&stack.a, &stack.b);
	if (stack.a.size >= 6)
		algo(&stack.a, &stack.b);
	free_stack(error_check(ac, av, &stack.a), &stack.a);
}