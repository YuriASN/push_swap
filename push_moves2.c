/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:14:50 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/10 01:02:20 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rr : Rotate both stacks at the same time.
int	rotate_both(t_stk *stk_a, t_stk *stk_b)
{
	rotate_stk(stk_a, 0);
	rotate_stk(stk_b, 0);
	ft_printf("rr\n");
	return (1);
}

/* Shift down all elements of stack by 1.
The last element becomes the first.
Print decides if, 0 don't print, 1 print A, 2 print B. */
int	rotate_rev(t_stk *stack, int print)
{
	t_stk	*tmp;

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
	return (1);
}

/* static void	print_list(t_stk *lst){
while (lst)
{
		ft_printf("%i\n", lst->value);
		lst = lst->nxt;
}} */

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
	while (stk_b->nxt)
		push_stk(stk_b, stk_a, 2);
}
