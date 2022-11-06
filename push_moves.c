/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:53:03 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 18:38:18 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements.
Print decides if, 0 don't print, 1 print A, 2 print B. */
int	swap_stk(t_stk *stack, int print)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->nxt->value;
	stack->nxt->value = tmp;
	if (print == 1)
		ft_printf("sa\n");
	if (print == 2)
		ft_printf("sb\n");
	return (1);
}

// ss : Swap 2 first elements of A and B at the same time.
int	swap_both(t_stk *stk_a, t_stk *stk_b)
{
	swap_stk(stk_a, 0);
	swap_stk(stk_b, 0);
	ft_printf("ss\n");
	return (1);
}

/* Take the first element at the top of OUT
and put it at the top of IN.
Print decides if, 1 print A to B, 2 print B to A.*/
int	push_stk(t_stk *st_out, t_stk *st_in, int print)
{
	t_stk	*tmp;

	tmp = st_out->nxt;
	if (st_in)
	{
		st_in->prev = st_out;
		st_out->nxt = st_in;
	}
	else
	{
		st_out = st_in;
		st_in->nxt = NULL;
	}
	tmp->prev = NULL;
	st_in = tmp;
	if (print == 1)
		ft_printf("pb\n");
	if (print == 2)
		ft_printf("pa\n");
	return (1);
}

/* Shift up all elements of stack by 1.
The first element becomes the last.
Print decides if, 0 don't print, 1 print A, 2 print B. */
int	rotate_stk(t_stk *stack, int print)
{
	t_stk	*tmp;

	tmp = stack->nxt;
	stack->prev = stklast(stack);
	stack->prev->nxt = stack;
	stack->nxt->prev = NULL;
	stack->nxt = NULL;
	stack = tmp;
	if (print == 1)
		ft_printf("ra\n");
	if (print == 2)
		ft_printf("rb\n");
	return (1);
}

//rr : Rotate both stacks at the same time.
int	rotate_both(t_stk *stk_a, t_stk *stk_b)
{
	rotate_stk(stk_a, 0);
	rotate_stk(stk_b, 0);
	ft_printf("rr\n");
	return (1);
}
