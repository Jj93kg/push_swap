#include "push_swap.h"

void	print_instruction(t_mem *stack, char *param)
{
	ft_putstr_fd(param, 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
}

void	push(t_mem *give, t_mem *recep)
{
	int	i;

	if (give->size <= 0)
	{
		ft_putendl_fd("Error push impossible : tableau vide\n", 2);
		return ;
	}
	i = 0;
	while (i < recep->size)
	{
		recep->sorted[recep->size - i] = recep->sorted[recep->size - 1 - i];
		i++;
	}
	recep->sorted[0] = give->sorted[0];
	i = 0;
	while (i < give->size - 1)
	{
		give->sorted[i] = give->sorted[i + 1];
		i++;
	}
	give->sorted[give->size - 1] = -1;
	give->size -= 1;
	recep->size += 1;
	print_instruction(recep, "p");
}

void	swap(t_mem *solo_stack)
{
	int	temp;

	if (solo_stack->size <= 1)
	{
		ft_putendl_fd("Error SWAP impossible : tableau vide\n", 2);
		return ;
	}
	temp = solo_stack->sorted[0];
	solo_stack->sorted[0] = solo_stack->sorted[1];
	solo_stack->sorted[1] = temp;
	print_instruction(solo_stack, "s");
}

void	rotate(t_mem *solo_stack)
{
	int	temp;
	int	i;

	if (solo_stack->size <= 1)
	{
		ft_putendl_fd("Error ROTATE impossible : tableau vide\n", 2);
		return ;
	}
	temp = solo_stack->sorted[0];
	i = 0;
	while (i < solo_stack->size - 1)
	{
		solo_stack->sorted[i] = solo_stack->sorted[i + 1];
		i++;
	}
	solo_stack->sorted[solo_stack->size - 1] = temp;
	print_instruction(solo_stack, "r");
}

void	reverse_rotate(t_mem *solo_stack)
{
	int	temp;
	int	i;
	int	y;

	if (solo_stack->size <= 1)
	{
		ft_putendl_fd("Error REVERSE_ROTATE impossible : tableau vide\n", 2);
		return ;
	}
	temp = solo_stack->sorted[solo_stack->size - 1];
	i = 0;
	y = solo_stack->size;
	while (i < solo_stack->size - 1)
	{
		solo_stack->sorted[y - 1] = solo_stack->sorted[y - 2];
		y--;
		i++;
	}
	solo_stack->sorted[0] = temp;
	print_instruction(solo_stack, "rr");
}