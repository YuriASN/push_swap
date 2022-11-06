/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 18:45:32 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order1(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_a->value > (stklast(stk_a))->value)
		rotate_rev(stk_a, 1);
	if (stk_a->value > stk_a->nxt->value && stk_b->value < stk_b->nxt->value)
		return (swap_both(stk_a, stk_b));
	else if (stk_a->value > stk_a->nxt->value)
		return (swap_stk(stk_a, 1));
	else if (stk_b->value < stk_b->nxt->value)
		return (swap_stk(stk_b, 2));
	if (stk_a->value < stk_b->value && stk_a->value >= stk_b->nxt->value)
	{
		rotate_stk(stk_b, 2);
		return (push_stk(stk_a, stk_b, 1), rotate_rev(stk_b, 2));
	}
	else if (stk_a->value >= stk_b->value)
		return (push_stk(stk_a, stk_b, 1));
	else if (stk_a->value <= stklast(stk_b)->value)
		return (push_stk(stk_a, stk_b, 1), rotate_stk(stk_b, 2));
	else if (stk_a->value > stklast(stk_b)->value && stk_a->value <= stklast(stk_a)->prev->value)
		return (rotate_rev(stk_b, 2), push_stk(stk_a, stk_b, 2), rotate_stk(stk_b, 2));
	return (0);
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a)
{
	t_stk	*stk_b;
	int		x;

	x = -1;
	stk_b = (t_stk *)malloc(sizeof(t_stk));
	if (stksize(stk_a) > 3)
	{
		while (++x < get_lowest(stk_a))
			rotate_stk(stk_a, 1);
		push_stk(stk_a, stk_b, 1);
		push_stk(stk_a, stk_b, 1);
	}
	while ((!check_order(stk_a) || !check_order_r(stk_b)))
	{
		order1(stk_a, stk_b);
	}
	if (stk_b->value)
		b_to_a(stk_a, stk_b);
	if (check_order(stk_a) && !stk_b->value)
	{
		free (stk_a);
		free (stk_b);
		exit (0);
	}
}
