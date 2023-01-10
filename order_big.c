#include "push_swap.h"

/* Return how many ints are stored in lis */
static int	lis_size(int *lis)
{
	int	i;

	i = 1;
	while (lis[i])
		++i;
	return (i);
}

/*	Leave A only with LIS numbers. */
static void	lis_on_a(t_stk *stk_a, t_stk *stk_b, int *lis)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i <= stksize(stk_a))
	{
printf("i = %i\t lis[%i] = %i\n", i, j, lis[j]);
		if (i != lis[j] && j < lis_size(lis))
			push_stk(stk_a, stk_b, 1);
		else
		{
			++j;
			rotate_stk(stk_a, 1);
		}
printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	}
	free(lis);
}

/*	Returns array with index of Longest Increasing Subsequence numbers. */
static int	*get_lis(t_stk *stk_a, int *lis)
{
	int		i;
	int		j;
	int		sv;
	t_stk	*tmp;

	tmp = stk_a;
	i = 0;
	j = -1;
	lis[++j] = i;
	sv = tmp->nxt->value;
	while (tmp->nxt->nxt)
	{
		++i;
		if (tmp->nxt->nxt->value > sv)
		{
			if (!tmp->nxt->nxt->nxt || (tmp->nxt->nxt->nxt
					&& tmp->nxt->nxt->nxt->value > tmp->nxt->nxt->value))
			{
				lis[++j] = i;
				sv = tmp->nxt->nxt->value;
			}
		}
		tmp = tmp->nxt;
	}
printf("lis = "); int o = -1; while (++o < lis_size(lis)){printf("[%i]%i, ", o, lis[o]);} printf("\n");
	return (lis);
}

/* Start ordering lists with  5 arguments or more than 7 */
void	order_big(t_stk *stk_a, t_stk *stk_b)
{
	int	*lis;
	int	i;
	int	lowest_pos;

	i = -1;
	lis = ft_calloc(stksize(stk_a->nxt), sizeof(int *));
	lowest_pos = get_lowest(stk_a->nxt);
	while (++i != lowest_pos)
		rotate_stk(stk_a, 1);
	get_lis(stk_a, lis);
	lis_on_a(stk_a, stk_b, lis);
	less_moves(stk_a, stk_b);
}
