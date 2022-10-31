/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:21 by ysantos-          #+#    #+#             */
/*   Updated: 2022/10/31 15:42:10 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check1(int **st_a, int **st_b)
{
	if (!st_b[0])
		ft_printf("pb\npb\n");
	if (st_a[0] > st_a[1] && st_a[0] > st_b[1])
		return (ft_printf("ss\n"));
	else if (st_a[0] > st_a[1])
		return (ft_printf("sa\n"));
	else if (st_b[0] > st_b[1])
		return (ft_printf("sb\n"));
	if (st_a[0] >= st_a[get_last(st_a)] && st_b[0] >= st_b[get_last(st_b)])
		return (ft_printf("rrr\n"));
	else if (st_a[0] >= st_a[get_last(st_a)])
		return (ft_printf("rra\n"));
	else if (st_b[0] >= st_b[get_last(st_b)])
		return (ft_printf("rrb\n"));
	return (0);
}

static int	check2(int **st_a, int **st_b)
{
	if (st_a[0] == st_b[0] - 1)
		return (ft_printf("rb\npb\nrrb\n"));
	else if (st_a[0] == st_b[0] + 1)
		return (ft_printf("pb\n"));
	else if (st_a[0] == st_b[get_last(st_b)] + 1)
		return (ft_printf("pb\nrb\n"));
	else if (st_a[0] == st_b[get_last(st_b)] - 1)
		return (ft_printf("rrb\npb\nrb\nrb\n"));
	while ((st_a[0] < st_b[get_last(st_b)]))
		return (ft_printf("pb\nrb\n"));
	return (0);
}

void	get_order(int **stack_a, int **stack_b)
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
