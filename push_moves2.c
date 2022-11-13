/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:14:50 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/12 16:44:44 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rr : Rotate both stacks at the same time.
int	rotate_both(t_stk *stk_a, t_stk *stk_b)
{
printf("%sInto rotate both%s\n", RED, CRESET);
	if (!stk_b->nxt || !stk_a->nxt || !stk_a->nxt->nxt || !stk_b->nxt->nxt)
		{printf("\t%sRotate both chamado sem 2 stacks com 2 elementos%s\n", YEL, CRESET);
		return (0);}
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
printf("%sInto rotate rev%s\n", RED, CRESET);
	t_stk	*tmp;

	if (!stack->nxt || !stack->nxt->nxt){printf("\t%sMissing 2 itens to rotate REV%s\n", YEL, CRESET);
		return (0);}
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

//rrr : rra and rrb at the same time.
int	rotate_rev_both(t_stk *stk_a, t_stk *stk_b)
{
printf("%sInto rotate rev both%s\n", RED, CRESET);
	if (!stk_b->nxt || !stk_a->nxt || !stk_a->nxt->nxt || !stk_b->nxt->nxt)
		{printf("\t%sRotate REV both chamado sem 2 stacks com 2 elementos%s\n", YEL, CRESET);
		return (0);}
	rotate_rev(stk_a, 0);
	rotate_rev(stk_b, 0);
	ft_printf("rrr\n");
	return (1);
}

void	b_to_a(t_stk *stk_a, t_stk *stk_b)
{
printf("%sInto b to a%s\n", RED, CRESET);
	while (stk_b->nxt)
		push_stk(stk_b, stk_a, 2);
}
