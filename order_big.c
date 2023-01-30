#include "push_swap.h"

/*	Leave A only with LIS numbers. */
static void	lis_on_a(t_stk *stk_a, t_stk *stk_b, int *lis)
{
	int	i;
	int	j;
	int	size_a;

	i = -1;
	j = 0;
	size_a = stksize(stk_a->nxt);
	while (++i < size_a)
	{
//printf("i = %i\t lis[%i] = %i\t", i, j, lis[j]);
		if (i != lis[j])
		{
			push_stk(stk_a, stk_b, 1);
		}
		else
		{
			++j;
			rotate_stk(stk_a, 1);
		}
//printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	}
	free(lis);
}

/*	Returns array with index of Longest Increasing Subsequence numbers. */
static void	get_lis(t_stk *stk_a, int *lis)
{
	int		i;
	int		sv;
	int		lis_i;
	t_stk	*tmp;

	tmp = stk_a->nxt;
	i = 0;
	lis_i = -1;
	lis[++lis_i] = i;
	sv = tmp->value;
	while (tmp->nxt)
	{
		++i;
		if (tmp->nxt->value > sv)
		{
			if (tmp->nxt->nxt && tmp->nxt->nxt->value < tmp->nxt->value)
			{
				tmp = tmp->nxt;
				continue ;
			}
			lis[++lis_i] = i;
			sv = tmp->nxt->value;
		}
		tmp = tmp->nxt;
	}
//printf("lis_size = %i\n", lis_i); printf("lis = "); int o = -1;  while (++o <= lis_i){printf("[%i]%i, ", o, lis[o]);} printf("\n\n");
}

/* Start ordering lists with  5 arguments or more than 7 */
void	order_big(t_stk *stk_a, t_stk *stk_b)
{
//printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);
	int	*lis;
	int	lowest_pos;

	lis = ft_calloc(stksize(stk_a->nxt), sizeof(int *));
	lowest_pos = get_lowest(stk_a->nxt);
//printf("lowest_pos = %i\n", lowest_pos);
	if (lowest_pos > 0)
		while (lowest_pos--)
			rotate_stk(stk_a, 1);
	else
		while (lowest_pos++)
			rotate_rev(stk_a, 1);
//printf("\nBefore LIS\n%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);	getchar();
	get_lis(stk_a, lis);
	lis_on_a(stk_a, stk_b, lis);
	order_loop(stk_a);
//printf("\nafter LIS\n%slist a:\n", CYN); 	print_list(stk_a);		printf("%slist b:\n", BLU);	print_list(stk_b);
	less_moves(stk_a, stk_b);
}
