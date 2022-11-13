/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/13 22:37:48 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if stack A is completely on order and returns TRUE or FALSE.
int	check_order(t_stk *stack)
{
	if (!stack->nxt || !stack->nxt->nxt)
		return (1);
	stack = stack->nxt;
	while (stack->nxt)
	{
		if (stack->value > stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

// Check if stack B is completely on reverse order and returns TRUE or FALSE.
int	check_order_r(t_stk *stack)
{
	if (!stack->nxt || !stack->nxt->nxt)
		return (1);
	stack = stack->nxt;
	while (stack->nxt)
	{
		if (stack->value < stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

int	get_lowest(t_stk *stk)
{
	int	lowest;
	int	sv;
	int	count;

	lowest = 0;
	count = 0;
	sv = stk->value;
	while (stk->nxt)
	{
		if (sv > stk->nxt->value)
		{
			sv = stk->nxt->value;
			lowest = count + 1;
printf("\033[93m\t lowest nbr = %i\t\033[m", stk->nxt->value);
		}
		stk = stk->nxt;
		++count;
	}
printf("\033[93m\tlowest rotation = %i\n\033[m", lowest);
	return (lowest);
}

/* lst: the beggining of the list.
Returns the number of nodes on the list */
int	stksize(t_stk *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->nxt;
		++count;
	}
printf("\e[0;33m\tSize of STK %i\e[0m\n", count);
	return (count);
}

/* Returns the last node of the stack.
lst: First node of the list. */
t_stk	*stklast(t_stk *lst)
{
	if (!lst)
		return (0);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
}
