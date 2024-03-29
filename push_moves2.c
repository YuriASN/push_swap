/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:14:50 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/18 16:27:25 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rr : Rotate both stacks at the same time.
void	rotate_both(t_stk *stk_a, t_stk *stk_b)
{
	if (!stk_b->nxt || !stk_a->nxt || !stk_a->nxt->nxt || !stk_b->nxt->nxt)
		return ;
	rotate_stk(stk_a, 0);
	rotate_stk(stk_b, 0);
	ft_printf("rr\n");
}

/* Shift down all elements of stack by 1.
The last element becomes the first.
Print decides if, 0 don't print, 1 print A, 2 print B. */
void	rotate_rev(t_stk *stack, int print)
{
	t_stk	*tmp;

	if (!stack->nxt || !stack->nxt->nxt)
		return ;
	tmp = stklast(stack);
	stack->nxt->prev = tmp;
	stack->nxt->prev->nxt = stack->nxt;
	stack->nxt = tmp;
	stack->nxt->prev->nxt = NULL;
	stack->nxt->prev = NULL;
	if (print == 1)
		ft_printf("rra\n");
	if (print == 2)
		ft_printf("rrb\n");
}

//rrr : rra and rrb at the same time.
void	rotate_rev_both(t_stk *stk_a, t_stk *stk_b)
{
	if (!stk_b->nxt || !stk_a->nxt || !stk_a->nxt->nxt || !stk_b->nxt->nxt)
		return ;
	rotate_rev(stk_a, 0);
	rotate_rev(stk_b, 0);
	ft_printf("rrr\n");
}

void	b_to_a(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_b->nxt)
		push_stk(stk_b, stk_a, 2);
}
