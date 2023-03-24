/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:21:07 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/24 00:54:12 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (i != lis[j])
		{
			push_stk(stk_a, stk_b, 1);
		}
		else
		{
			++j;
			rotate_stk(stk_a, 1);
		}
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
}

/* Start ordering lists with 10 arguments*/
void	order_big(t_stk *stk_a, t_stk *stk_b)
{
	int	*lis;
	int	lowest_pos;

	lis = ft_calloc(stksize(stk_a->nxt), sizeof(int *));
	lowest_pos = get_lowest(stk_a->nxt);
	if (lowest_pos > 0)
		while (lowest_pos--)
			rotate_stk(stk_a, 1);
	else
		while (lowest_pos++)
			rotate_rev(stk_a, 1);
	get_lis(stk_a, lis);
	lis_on_a(stk_a, stk_b, lis);
	order_loop(stk_a);
	less_moves(stk_a, stk_b);
}
