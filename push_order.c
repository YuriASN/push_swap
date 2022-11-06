/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 15:28:08 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order1(t_stk *stk_a, t_stk *stk_b)
{
	//Checa se a0 é maior que aULT
	while (stk_a->value > (ft_stklast(stk_a))->value)
		rotate_back_a(stk_a, 1);
	//checo se estão trocados os dois primeiros de cada
	if (stk_a->value > stk_a->nxt->value && stk_b->value < stk_b->nxt->value)
		return (swap_both(stk_a, stk_b));
	else if (stk_a->value > stk_a->nxt->value)
		return (swap_a(stk_a, 1));
	else if (stk_b->value < stk_b->nxt->value)
		return (swap_b(stk_b, 1));
	//checo se o a0 está entre b0 e b1.
	if (stk_a->value < stk_b->value && stk_a->value >= stk_b->nxt->value)
	{
		rotate_b(stk_b, 1);
		return (push_b(stk_a, stk_b), rotate_back_b(stk_b, 1));
	}
	//checo se a0 vai para topo de b.
	else if (stk_a->value >= stk_b->value)
		return (push_b(stk_a, stk_b));
	//checo se a0 está abaixo de bULT
	else if (stk_a->value <= ft_stklast(stk_b)->value)
		return (push_b(stk_a, stk_b), rotate_b(stk_b, 1));
	//checa se está entre sULT e SPENULT
	else if (stk_a->value > ft_stklast(stk_b)->value)
	{
		if (stk_a->value <= ft_stklast(stk_a)->prev->value)
		{
			rotate_back_b(stk_b, 1);
			return (push_b(stk_a, stk_b), rotate_b(stk_b, 1));
		}
	}
	return (0);
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
while (stk_a->value || stk_b->value)
	ft_printf("%i\t%i\n", stk_a->value, stk_b->value);
	int	x;

	x = -1;
	if (ft_lstsize(stk_a) > 3)
	{
		while (++x < get_lowest(stk_a))
			rotate_a(stk_a, 1);
		push_b(stk_a, stk_b);
		push_b(stk_a, stk_b);
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
