#include "push_swap.h"

/*	Leave A only with LIS numbers. */
static void	lis_on_a(t_stk *stk_a, t_stk *stk_b, int *lis, int lis_size)
{
	int	i;
	int	j;
	int	size_a;

	i = -1;
	j = 0;
	size_a = stksize(stk_a->nxt);
	while (++i < size_a)
	{
printf("i = %i\t lis[%i] = %i\n", i, j, lis[j]);
		if (j <= lis_size && i != lis[j])
		{
			push_stk(stk_a, stk_b, 1);
		}
		else
		{
			++j;
			rotate_stk(stk_a, 1);
		}
printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	}
	free(lis);
}

/*	Returns array with index of Longest Increasing Subsequence numbers.
	And attributes the size to lis_size */
static int	*get_lis(t_stk *stk_a, int *lis, int *lis_size)
{
	int		i;
	int		sv;
	t_stk	*tmp;

	tmp = stk_a->nxt;
	i = 0;
	lis[++*lis_size] = i;
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
			lis[++*lis_size] = i;
			sv = tmp->nxt->value;
		}
		tmp = tmp->nxt;
	}
printf("lis_size = %i\n", *lis_size); printf("lis = "); int o = -1;  while (++o <= *lis_size){printf("[%i]%i, ", o, lis[o]);} printf("\n\n");
	return (lis);
}

/* Start ordering lists with  5 arguments or more than 7 */
void	order_big(t_stk *stk_a, t_stk *stk_b)
{
	int	*lis;
	int	i;
	int	lowest_pos;
	int	lis_size;

	i = -1;
	lis_size = -1;
	lis = ft_calloc(stksize(stk_a->nxt), sizeof(int *));
	lowest_pos = get_lowest(stk_a->nxt);
printf("lowest_pos = %i\n", lowest_pos);
	if (lowest_pos <= stksize(stk_a->nxt) / 2)
		while (++i != lowest_pos)
			rotate_stk(stk_a, 1);
	else
		while (lowest_pos++ != stksize(stk_a->nxt))
			rotate_rev(stk_a, 1);
printf("\nBefore LIS\n%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	get_lis(stk_a, lis, &lis_size);
	lis_on_a(stk_a, stk_b, lis, lis_size);
printf("\nafter LIS\n%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	less_moves(stk_a, stk_b);
}
