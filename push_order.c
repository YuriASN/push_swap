/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/10/31 22:54:29 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check1(int *st_a, int *st_b)
{
	if (!st_b[0])
		return (push_b(st_a, st_b), push_b(st_a, st_b));
	if (st_a[0] > st_a[1] && st_a[0] > st_b[1])
		return (swap_both(st_a, st_b));
	else if (st_a[0] > st_a[1])
		return (swap_a(st_a, 1));
	else if (st_b[0] > st_b[1])
		return (swap_b(st_b, 1));
	if (st_a[0] >= st_a[get_last(st_a)] && st_b[0] >= st_b[get_last(st_b)])
		return (rotate_back_both(st_a, st_b));
	else if (st_a[0] >= st_a[get_last(st_a)])
		return (rotate_back_a(st_a, 1));
	else if (st_b[0] >= st_b[get_last(st_b)])
		return (rotate_back_b(st_b, 1));
	return (0);
}

static int	check2(int *st_a, int *st_b)
{
	if (st_a[0] == st_b[0] - 1)
		return (rotate_b(st_b, 1), push_b(st_a, st_b), rotate_back_b(st_b, 1));
	else if (st_a[0] == st_b[0] + 1)
		return (push_b(st_a, st__b));
	else if (st_a[0] == st_b[get_last(st_b)] + 1)
		return (push_b(st_a, st_b), rotate_b(st_b, 1));
	else if (st_a[0] == st_b[get_last(st_b)] - 1)
	{
		rotate_back_b(st_b, 1);
		return (push_b(st_a, st_b), rotate_b(st_b, 1), rotate_b(st_b, 1));
	}
	if ((st_a[0] < st_b[get_last(st_b)]))
	{
		while ((st_a[0] < st_b[get_last(st_b)]))
		{
			push_b(st_a, st_b);
			rotate_b(st_b, 1);
		}
		return (1);
	}		
	return (0);
}

/* Start process of what todo in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(int *stack_a, int *stack_b)
{
	while (!check_order(stack_a) || !check_order_r(stack_b))
	{
		if (check1(stack_a, stack_b))
			continue ;
		if (check2(stack_a, stack_b))
			continue ;
	}
	b_to_a(stack_a, stack_b);
}
