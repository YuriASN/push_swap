/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:55:03 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/24 07:59:09 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order3a(t_stk *stk)
{
	int	low;

	low = lowest_value(stk->nxt);
	order_loop(stk);
	if (check_order_r(stk))
	{
		swap_stk(stk, 1);
		rotate_rev(stk, 1);
	}
	else if (stk->nxt->value < stk->nxt->nxt->nxt->value
		&& low == stk->nxt->nxt->value)
		swap_stk(stk, 1);
	else if (stk->nxt->nxt->value > stk->nxt->nxt->nxt->value
		&& low == stk->nxt->value)
	{
		swap_stk(stk, 1);
		rotate_stk(stk, 1);
	}
}

/* Order stack when it's size is below 9 */
static void	order_a(t_stk *stk)
{
	if (stksize(stk->nxt) == 3)
		order3a(stk);
	while (!check_order(stk))
	{
		if (stk->nxt->value > stk->nxt->nxt->value && get_lowest(stk->nxt) != 1)
			swap_stk(stk, 1);
		if (order_loop(stk) && get_lowest(stk->nxt) < 0)
			while (!check_order(stk))
				rotate_rev(stk, 1);
		if (!check_order(stk))
			rotate_stk(stk, 1);
	}
}

/*	Choose lower and higher arguments must be
	pushed out of stack a to reduce moves */
static void	choose_push(t_stk *stk, t_stk *stk_b)
{
	while (stksize(stk_b->nxt) != 2)
	{
		if (stk->nxt->value == lowest_value(stk->nxt)
			|| stk->nxt->value == highest_value(stk->nxt))
			push_stk(stk, stk_b, 1);
		else if ((stklast(stk))->value == lowest_value(stk->nxt)
			|| (stklast(stk))->value == highest_value(stk->nxt))
		{
			rotate_rev(stk, 1);
			push_stk(stk, stk_b, 1);
		}
		else if (stk->nxt->nxt->value == lowest_value(stk->nxt)
			|| stk->nxt->nxt->value == highest_value(stk->nxt))
		{
			rotate_stk(stk, 1);
			push_stk(stk, stk_b, 1);
		}
		else if ((stklast(stk))->prev->value == lowest_value(stk->nxt)
			|| (stklast(stk))->prev->value == highest_value(stk->nxt))
		{
			rotate_rev(stk, 1);
			rotate_rev(stk, 1);
			push_stk(stk, stk_b, 1);
		}
	}
}

/* Get a list of 5 arguments in order */
static void	five_arg(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_b->nxt)
	{
		if (stk_b->nxt->value < stk_a->nxt->value)
			push_stk(stk_b, stk_a, 2);
		else if (stk_b->nxt->value > (stklast(stk_a))->value)
			push_stk(stk_b, stk_a, 2);
		else if (stk_b->nxt->value > stk_a->nxt->value
			&& stk_b->nxt->value < stk_a->nxt->nxt->value)
		{
			rotate_stk(stk_a, 1);
			push_stk(stk_b, stk_a, 2);
		}
		else if (stk_b->nxt->value > (stklast(stk_a))->prev->value
			&& stk_b->nxt->value < (stklast(stk_a))->value)
		{
			rotate_rev(stk_a, 1);
			push_stk(stk_b, stk_a, 2);
		}
		order_loop(stk_a);
	}
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
	if (check_order(stk_a) && !stk_b->nxt)
		clean_quit(stk_a);
	if (order_loop(stk_a))
		clean_quit(stk_a);
	if (stksize(stk_a->nxt) == 5)
	{
		choose_push(stk_a, stk_b);
		order3a(stk_a);
		five_arg(stk_a, stk_b);
		order_loop(stk_a);
		clean_quit(stk_a);
	}
	if (stksize(stk_a->nxt) > 9)
		order_big(stk_a, stk_b);
	else
	{
		order_a(stk_a);
		clean_quit(stk_a);
	}
}
