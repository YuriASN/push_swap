/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:53:03 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/12 16:39:11 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements.
Print decides if, 0 don't print, 1 print A, 2 print B. */
int	swap_stk(t_stk *stack, int print)
{
printf("%sInto swap %i%s\n", RED, print, CRESET);
	int	tmp;

	tmp = stack->nxt->value;
	stack->nxt->value = stack->nxt->nxt->value;
	stack->nxt->nxt->value = tmp;
	if (print == 1)
		ft_printf("sa\n");
	if (print == 2)
		ft_printf("sb\n");
	return (1);
}

// ss : Swap 2 first elements of A and B at the same time.
int	swap_both(t_stk *stk_a, t_stk *stk_b)
{
printf("%sInto swap both%s\n", RED, CRESET);
	if (!stk_b->nxt || !stk_a->nxt || !stk_a->nxt->nxt || !stk_b->nxt->nxt)
		{printf("\t%sSwap both chamado sem 2 stacks com 2 elementos%s\n", RED, CRESET);}
	swap_stk(stk_a, 0);
	swap_stk(stk_b, 0);
	ft_printf("ss\n");
	return (1);
}

/* Push the last element of a stack OUT and put it on top of stack IN
Print decides if, 1 print A to B, 2 print B to A.*/
static int	push_last(t_stk *st_out, t_stk *st_in, int print)
{
printf("%sInto push last%s\n", RED, CRESET);
	if (st_in->nxt)
	{
		st_out->nxt->nxt = st_in->nxt;
		st_in->nxt->prev = st_out->nxt;
	}
	st_in->nxt = st_out->nxt;
	st_in->nxt->prev = NULL;
	st_out->nxt = NULL;
	if (print == 1)
		ft_printf("pb\n");
	if (print == 2)
		ft_printf("pa\n");
	return (1);
}

/* Take the first element at the top of OUT
and put it at the top of IN.
Print decides if, 1 print A to B, 2 print B to A.*/
int	push_stk(t_stk *st_out, t_stk *st_in, int print)
{
printf("%sInto push%s\n", RED, CRESET);
	t_stk	*tmp;

	if (!st_out->nxt || !st_in)
		return (0);
	if (!st_out->nxt->nxt)
		return (push_last(st_out, st_in, print));
	tmp = st_out->nxt;
	st_out->nxt = st_out->nxt->nxt;
	st_out->nxt->prev = st_out;
	tmp->prev = NULL;
	if (st_in->nxt)
	{
		tmp->nxt = st_in->nxt;
		st_in->nxt->prev = tmp;
	}
	else
		tmp->nxt = NULL;
	st_in->nxt = tmp;
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
printf("%sInto rotate%s\n", RED, CRESET);
	t_stk	*tmp;

	if (!stack->nxt || !stack->nxt->nxt){printf("\t%sMissing 2 itens to rotate%s\n", YEL, CRESET);
		return (0);}
	tmp = stack->nxt->nxt;
	stack->nxt->prev = stklast(stack);
	stack->nxt->prev->nxt = stack->nxt;
	stack->nxt->nxt = NULL;
	stack->nxt = tmp;
	if (print == 1)
		ft_printf("ra\n");
	if (print == 2)
		ft_printf("rb\n");
	return (1);
}
