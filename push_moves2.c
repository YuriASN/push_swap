/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:14:50 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 16:55:33 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* Shift down all elements of stack by 1.
The last element becomes the first.
Print decides if, 0 don't print, 1 print A, 2 print B. */
int	rotate_rev(t_stk *stack, int print)
{
	int	tmp;

	stack->prev = ft_stklast(stack);
	tmp = &stack->prev;
	stack->prev->nxt = stack;
	stack = tmp;
	stack->prev->nxt = NULL;
	stack->prev = NULL;
	if (print == 1)
		ft_printf("rra\n");
	if (print == 2)
		ft_printf("rrb\n");
	return (1);
}

//rrr : rra and rrb at the same time.
int	rotate_rev_both(t_stk *stk_a, t_stk *stk_b)
{
	rotate_rev(stk_a, 0);
	rotate_rev(stk_b, 0);
	ft_printf("rrr\n");
	return (1);
}

void	b_to_a(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_b)
		push_stk(stk_b, stk_a, 2);
}
