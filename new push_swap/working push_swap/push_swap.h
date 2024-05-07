#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include   <limits.h>
# include   <unistd.h>
# include   <stdio.h>
# include   <stdlib.h>

typedef struct s_mem
{
	int		size;
	long	*sorted;
	char	name;
}				t_mem;

typedef struct s_list
{
	t_mem	a;
	t_mem	b;
}				t_list;

////////////////////////////////////////////////////////////////////////

/*  @fn  libft_1  */
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/*  @fn  libft_2  */
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);

////////////////////////////////////////////////////////////////////////

/*  @fn  error_check.c    */
t_mem	*error_check(int ac, char **av, t_mem *mem);

/*  includes */
void	digit_error(int ac, char **av);
t_mem	*atoi_args(int ac, char **av, t_mem *mem);
void	double_error(t_mem *atoi);
int		sizeof_atoi(int ac, t_mem *mem);

////////////////////////////////////////////////////////////////////////

/*  @fn  index.c  */
int		*indexation(t_mem *atoi, t_mem *mem);
int		min_index(t_mem *atoi);
int		max_index(t_mem *atoi);
int		is_sorted(t_mem *stack);

////////////////////////////////////////////////////////////////////////

/*  @fn  operation.c  */
void	push(t_mem *give, t_mem *receive);
void	swap(t_mem *solo_stack);
void	rotate(t_mem *solo_stack);
void	reverse_rotate(t_mem *solo_stack);

////////////////////////////////////////////////////////////////////////

/*  @fn  algo_spec.c  */
void	algo_3(t_mem *a);
void	algo_2(t_mem *a);
void	algo_4(t_mem *a, t_mem *b);
void	algo_5(t_mem *a, t_mem *b);

/*  @fn  algo_utils.c */
int		minimum(t_mem *a);
int		maximum(t_mem *a);
void	rs(t_mem *a);
void	sr(t_mem *a);

/*  @fn  algo.c   */
void	a_to_b(t_mem *a, t_mem *b, int chunk, int chunk_done);
void	b_to_a(t_mem *a, t_mem *b);
void	algo(t_mem *a, t_mem *b);

#endif