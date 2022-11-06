/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 14:46:53 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if stack A is completely on order and returns TRUE or FALSE.
int	check_order(t_stk *stack)
{
	while (stack->nxt)
	{
		if (stack->value > stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
ft_printf("order a OK\n");
	return (1);
}

// Check if stack B is completely on reverse order and returns TRUE or FALSE.
int	check_order_r(t_stk *stack)
{
	while (stack->nxt)
	{
		if (stack->value < stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
ft_printf("order b OK\n");
	return (1);
}

int	*get_lowest(t_stk *stk_a)
{
	t_stk	*tmp;
	int		count;

	count = 1;
	while (stk_a->nxt)
	{
		if (stk_a->value > stk_a->nxt->value)
			tmp = stk_a->nxt;
		stk_a = stk_a->nxt;
		++count;
	}
	return (count);
}
