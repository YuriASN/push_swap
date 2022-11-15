/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/15 20:51:11 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Choose where the A has to pushed at B. */
static void	push_where(t_stk *stk_a, t_stk *stk_b)
{
//printf("\tno push where%s\n", CRESET);getchar();
	if (stk_a->nxt->value < stk_b->nxt->value
		&& stk_a->nxt->value >= stk_b->nxt->nxt->value)
	{
		rotate_stk(stk_b, 2);
		push_stk(stk_a, stk_b, 1);
		rotate_rev(stk_b, 2);
	}
	else if (stk_a->nxt->value >= stk_b->nxt->value)
		push_stk(stk_a, stk_b, 1);
	else if (stk_a->nxt->value <= stklast(stk_b)->value)
	{
		push_stk(stk_a, stk_b, 1);
		rotate_stk(stk_b, 2);
	}
	else if (stk_a->nxt->value > stklast(stk_b)->value
		&& stk_a->nxt->value <= stklast(stk_a)->prev->value)
	{
		rotate_rev(stk_b, 2);
		push_stk(stk_a, stk_b, 2);
		rotate_stk(stk_b, 2);
	}
}

static int	order1(t_stk *stk_a, t_stk *stk_b)
{
//printf("%sStart Order1%s\n", YEL, CRESET); getchar();
	while (stk_a->nxt->value > (stklast(stk_a))->value)
		rotate_rev(stk_a, 1);
	if (stk_a->nxt->value > stk_a->nxt->nxt->value && stk_b->nxt->value < stk_b->nxt->nxt->value)
		swap_both(stk_a, stk_b);
	else if (stk_a->nxt->value > stk_a->nxt->nxt->value)
		swap_stk(stk_a, 1);
	else if (stk_b->nxt->value < stk_b->nxt->nxt->value)
		swap_stk(stk_b, 2);
	else
	{	//printf("\t%sOrder1 did nothing%s\n", RED, CRESET);
		push_where(stk_a, stk_b);}
	return (0);
}

/* Get only stack a in order when a second stack is alredy ordered */
static void	order_a(t_stk *stack)
{
//printf("%sinto order A\n%s", YEL, CRESET);
	while (!check_order(stack))
	{
		if (stack->nxt->value > stack->nxt->nxt->value && get_lowest(stack->nxt) != 1)
			swap_stk(stack, 1);
		rotate_stk(stack, 1);
//print_list(stack);
//getchar();
	}
}

/* **************************************************  FIX IT!  ************************************************** */
/* Get only stack b in order when a second stack is alredy ordered */
static void	order_b(t_stk *stack)
{
//printf("%s\tinto order B\n%s", YEL, CRESET);
	while (!check_order_r(stack))
	{
		if (stack->nxt->value < stack->nxt->nxt->value && get_lowest(stack->nxt) < stksize(stack->nxt))
			swap_stk(stack, 2);
		rotate_stk(stack, 2);
//getchar();
	}
}
/* *************************************************************************************************************** */

/* Put lowest number at first to be pushed to b. */
static void	start_stka(t_stk *stk_a)
{
	int	z;

	z = get_lowest(stk_a->nxt);
	if (z >= stksize(stk_a->nxt) / 2)
	{
		while (++z < stksize(stk_a->nxt))
			rotate_rev(stk_a, 1);
	}
	else if (z < stksize(stk_a->nxt) / 2)
	{
		while (++z < stksize(stk_a->nxt) / 2)
			rotate_stk(stk_a, 1);
	}
	else if (z == stksize(stk_a->nxt) / 2)
		while (z-- != 0)
			rotate_stk(stk_a, 1);
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
//printf("%sGet order\n%slist a:%s\n", YEL, CYN, CRESET); 	print_list(stk_a);		//printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	if (check_order(stk_a) && check_order_r(stk_b))
	{
		if (stk_b->nxt)
			b_to_a(stk_a, stk_b);
		exit (0);
	}
	if (stksize(stk_a->nxt) > 7)
	{
		start_stka(stk_a);
		push_stk(stk_a, stk_b, 1);
		push_stk(stk_a, stk_b, 1);
	}
	else
	{
		order_a(stk_a);
		exit (0);
	}
	while ((!check_order(stk_a) || !check_order_r(stk_b)) || stk_a->nxt->value < stk_b->nxt->value)
	{
//printf("\t\t\t%sWhile no order%s\nlist a:%s\n", RED, CYN, CRESET);// 	print_list(stk_a);		//printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
//getchar();
		order1(stk_a, stk_b);
		if (stksize(stk_a->nxt) < 8 && !check_order(stk_a))
			{order_a(stk_a); print_list(stk_a);}
		if (!check_order_r(stk_b))
			order_b(stk_b);
		if (stk_a->nxt->value < stk_b->nxt->value && stksize(stk_a->nxt) > 4)
			push_stk(stk_a, stk_b, 1);
		else if (stksize(stk_a->nxt) < 3)
			push_stk(stk_b, stk_a, 2);
	}
//printf("%sSaiu do check order\n%slist a:%s\n", YEL, CYN, CRESET); 	print_list(stk_a);		//printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	if (stk_b->nxt)
		b_to_a(stk_a, stk_b);
	if (check_order(stk_a) && !stk_b->nxt){//printf("\t\t\e[0;32mEND WITHOUT LEAKS!\e[0m\n"); //printf("%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		//printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
		exit (0);	}
}


//Change all exit for a funtion that free the stack and exit