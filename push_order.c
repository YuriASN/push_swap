/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/10 03:41:00 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order1(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_a->value > (stklast(stk_a))->value)
		rotate_rev(stk_a, 1);
	if (stk_a->value > stk_a->nxt->value && stk_b->value < stk_b->nxt->value)
		return (swap_both(stk_a, stk_b));
	else if (stk_a->value > stk_a->nxt->value)
		return (swap_stk(stk_a, 1));
	else if (stk_b->value < stk_b->nxt->value)
		return (swap_stk(stk_b, 2));
	if (stk_a->value < stk_b->value && stk_a->value >= stk_b->nxt->value)
	{
		rotate_stk(stk_b, 2);
		return (push_stk(stk_a, stk_b, 1), rotate_rev(stk_b, 2));
	}
	else if (stk_a->value >= stk_b->value)
		return (push_stk(stk_a, stk_b, 1));
	else if (stk_a->value <= stklast(stk_b)->value)
		return (push_stk(stk_a, stk_b, 1), rotate_stk(stk_b, 2));
	else if (stk_a->value > stklast(stk_b)->value && stk_a->value <= stklast(stk_a)->prev->value)
		return (rotate_rev(stk_b, 2), push_stk(stk_a, stk_b, 2), rotate_stk(stk_b, 2));
	return (0);
}


static void	print_list(t_stk *lst){
	while (lst->nxt)
	{
		ft_printf("%i\n", lst->nxt->value);
		lst = lst->nxt;
	}
	printf("\n");
}


/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
	int	z;

	z = 0;
//printf("get order\tlist a:\n"); 	print_list(stk_a);		printf("list b:\n");	print_list(stk_b);
	if (stksize(stk_a) > 3)
	{
printf("\tno if\033\n");
		z = get_lowest(stk_a->nxt);
		if (z > stksize(stk_a->nxt) / 2){printf("\033[93mz maior que meio\033[m\n");
			while (z++ < stksize(stk_a->nxt))
				rotate_rev(stk_a, 1);}
		else if (z < stksize(stk_a->nxt) / 2){printf("\033[93mz menor que meio\033[m\n");
			while (z++ < stksize(stk_a->nxt) / 2)
				rotate_stk(stk_a, 1);}
		else if (z == stksize(stk_a->nxt) / 2)
			while (z-- != 0)
				rotate_stk(stk_a, 1);
		push_stk(stk_a, stk_b, 1);
		push_stk(stk_a, stk_b, 1);
	}
printf("\033[93m\tout of if\033[m\n");
//printf("list a:\n"); 	print_list(stk_a);		printf("list b:\n");	print_list(stk_b);
	while ((!check_order(stk_a->nxt) || !check_order_r(stk_b->nxt)))
	{
		order1(stk_a, stk_b);
	}
printf("\033[93msaiu do check order\033[m"); 	print_list(stk_a);		printf("list b:\n");	print_list(stk_b);
	if (stk_b->nxt->value)
		b_to_a(stk_a, stk_b);
//printf("list a:\n"); 	print_list(stk_a);		printf("list b:\n");	print_list(stk_b);
	if (check_order(stk_a) && !stk_b->nxt->value)
		exit (0);
}
