#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	digit_error(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
			{
				exit(write(2, "Error\n", 6));
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	sizeof_atoi(int ac, t_mem *mem)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (++i < ac)
		size += 1;
	mem->size = size;
	return (size);
}

long	*ft_split_atoi(char **stock, t_mem *mem)
{
	int		i;
	int		size;
	long	*tab;

	i = 0;
	size = 0;
	while (stock[i])
	{
		size += 1;
		i++;
	}
	mem->size = size;
	i = 0;
	tab = malloc(size * sizeof(long));
	while (stock[i])
	{
		tab[i] = ft_atol(stock[i]);
		i++;
	}
	return (tab);
}

t_mem	*atoi_args(int ac, char **av, t_mem *mem)
{
	int		i;
	int		y;
	t_mem	*atoi;
	char	**stock;

	atoi = malloc(sizeof(t_mem) * 1);
	y = 0;
	if (ac == 2)
	{
		stock = ft_split(av[1], ' ');
		atoi->sorted = ft_split_atoi(stock, mem);
		atoi->size = mem->size;
	}
	else
	{
		atoi->sorted = malloc(sizeof_atoi(ac, mem) * sizeof(long));
		atoi->size = mem->size;
		i = 0;
		while (++i < ac)
		{
			atoi->sorted[y] = ft_atol(av[i]);
			y++;
		}
	}
	return (atoi);
}

void	double_error(t_mem *atoi)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < atoi->size)
	{
		while (y < atoi->size)
		{
			if (atoi->sorted[i] == atoi->sorted[y] && i != y)
				exit(write(2, "Error\n", 6));
			if (atoi->sorted[y] > 2147483647)
				exit(write(2, "Error\n", 6));
			y++;
		}
		i++;
		y = i + 1;
	}
}