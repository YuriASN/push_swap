/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/13 18:33:00 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Choose where the A has to pushed at B. */
static int	push_where(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->nxt->value < stk_b->nxt->value && stk_a->nxt->value >= stk_b->nxt->nxt->value)
	{
		rotate_stk(stk_b, 2);
		return (push_stk(stk_a, stk_b, 1), rotate_rev(stk_b, 2));
	}
	else if (stk_a->nxt->value >= stk_b->nxt->value)
		return (push_stk(stk_a, stk_b, 1));
	else if (stk_a->nxt->value <= stklast(stk_b)->value)
		return (push_stk(stk_a, stk_b, 1), rotate_stk(stk_b, 2));
	else if (stk_a->nxt->value > stklast(stk_b)->value && stk_a->nxt->value <= stklast(stk_a)->prev->value)
		return (rotate_rev(stk_b, 2), push_stk(stk_a, stk_b, 2), rotate_stk(stk_b, 2));
printf("\t%sPush where did nothing%s\n", RED, CRESET);
	return (0);
}
		
static int	order1(t_stk *stk_a, t_stk *stk_b)
{
printf("%sStart Order1%s\n", YEL, CRESET); 
	while (stk_a->nxt->value > (stklast(stk_a))->value)
		rotate_rev(stk_a, 1);
	if (stk_a->nxt->value > stk_a->nxt->nxt->value && stk_b->nxt->value < stk_b->nxt->nxt->value)
		return (swap_both(stk_a, stk_b));
	else if (stk_a->nxt->value > stk_a->nxt->nxt->value)
		return (swap_stk(stk_a, 1));
	else if (stk_b->nxt->value < stk_b->nxt->nxt->value)
		return (swap_stk(stk_b, 2));
	else
		return (push_where(stk_a, stk_b));
printf("\t%sOrder1 did nothing%s\n", RED, CRESET);
	return (0);
}

/* Get only stack a in order when a second stack is alredy ordered */
/* static void	order_a(t_stk *stack)
{
printf("%sinto order A\n%s", YEL, CRESET);
	int	z;

	z = get_lowest(stack->nxt) + 1;
	while (--z > 0)
	{
		if (stack->nxt->value > stack->nxt->nxt->value)
			swap_stk(stack, 1);
		rotate_stk(stack, 1);
	}
} */

/* Get only stack b in order when a second stack is alredy ordered */
static void	order_b(t_stk *stack)
{
printf("%s\tinto order B\n%s", YEL, CRESET);
	while (!check_order_r(stack))
	{
		if (stack->nxt->value < (stklast(stack->nxt))->value)
			rotate_rev(stack, 2);
		else if (stack->nxt->value < stack->nxt->nxt->value)
			swap_stk(stack, 2);
		else
			rotate_stk(stack, 2);
	}
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
printf("%sGet order\n%slist a:%s\n", YEL, CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	int	z;

	if (check_order(stk_a) && check_order_r(stk_b))
	{
printf("\n\nAlready on order\n");
		if (stk_b->nxt)
			b_to_a(stk_a, stk_b);
		exit (0);
	}
	z = 0;
	if (stksize(stk_a->nxt) > 3)
	{
printf("\tno if\033\n");
		z = get_lowest(stk_a->nxt);
		if (z >= stksize(stk_a->nxt) / 2)
{printf("\033[93mz maior que meio\033[m\n");
			while (z++ < stksize(stk_a->nxt))
				rotate_rev(stk_a, 1);
}
		else if (z < stksize(stk_a->nxt) / 2)
			while (z++ < stksize(stk_a->nxt) / 2)
				rotate_stk(stk_a, 1);
		else if (z == stksize(stk_a->nxt) / 2)
			while (z-- != 0)
				rotate_stk(stk_a, 1);
		push_stk(stk_a, stk_b, 1);
		push_stk(stk_a, stk_b, 1);
	}
printf("\e[93m\tout of if\033[m\n");
	while ((!check_order(stk_a) || !check_order_r(stk_b)))
	{
printf("\t\t\t%sWhile no order%s\nlist a:%s\n", RED, CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
getchar();
		if (check_order(stk_a) && stk_b->nxt)
			order_b(stk_b);
		/* else if ((check_order_r(stk_b) && stk_a->nxt->nxt) || stksize(stk_a->nxt) < 6)
			order_a(stk_a); */
		else
			order1(stk_a, stk_b);
	}
printf("%sSaiu do check order\n%slist a:%s\n", YEL, CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	if (stk_b->nxt->value)
		b_to_a(stk_a, stk_b);
	if (check_order(stk_a) && check_order_r(stk_b)){printf("\t\t\e[0;32mEND WITHOUT LEAKS!\e[0m\n"); printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
		exit (0);			}
}
