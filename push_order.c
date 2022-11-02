/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/02 20:18:57 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int	check1(int *st_a, int *st_b)
{
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
} */

int	order1(int *st_a, int *st_b)
{
	//Checa se a0 é maior que aULT
	while (st_a[0] > st_a[get_last(st_a)])
		rotate_back_a(st_a, 1);
	//checo se estão trocados os dois primeiros de cada
	if (st_a[0] > st_a[1] && st_a[0] > st_b[1])
		return (swap_both(st_a, st_b));
	else if (st_a[0] > st_a[1])
		return (swap_a(st_a, 1));
	else if (st_b[0] > st_b[1])
		return (swap_b(st_b, 1));
	//checo se o a0 está entre b0 e b1.
	if (st_a[0] < st_b[0] && st_a[0] >= st_b[1])
		return (rotate_b(st_b, 1), push_b(st_a, st_b), rotate_back_b(st_b, 1));
	//checo se a0 vai para topo de b.
	else if (st_a[0] >= st_b[0])
		return (push_b(st_a, st_b));
	//checo se a0 está abaixo de bULT
	else if (st_a[0] <= st_b[get_last(st_b)])
		return (push_b(st_a, st_b), rotate_b(st_b, 1));
	//checa se está entre sULT e SPENULT
	else if (st_a[0] > st_b[get_last(st_b)] && st_a[0] <= st_b[get_last(st_b)-1])
		return (rotate_back_b(st_b, 1), push_b(st_a, st_b), rotate_b(st_b, 1));
	return (0);
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(int *stack_a, int *stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (!check_order(stack_a) || !check_order_r(stack_b))
	{
		order1(stack_a, stack_b);
	}
	b_to_a(stack_a, stack_b);
	if (check_order(stack_a) && !stack_b[0])
	{
		free (stack_a);
		free (stack_b);
		exit (0);
	}
}
