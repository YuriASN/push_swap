/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:53:03 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/02 20:18:05 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
int	swap_a(int *st_a, int print)
{
	int	tmp;

	tmp = st_a[1];
	st_a[1] = st_a[0];
	st_a[0] = tmp;
	if (print)
		ft_printf("sa\n");
	return (1);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
int	swap_b(int *st_b, int print)
{
	int	tmp;

	tmp = st_b[1];
	st_b[1] = st_b[0];
	st_b[0] = tmp;
	if (print)
		ft_printf("sb\n");
	return (1);
}

// ss : sa and sb at the same time.
int	swap_both(int *st_a, int *st_b)
{
	swap_a(st_a, 0);
	swap_b(st_b, 0);
	ft_printf("ss\n");
	return (1);
}

/* pa (push a): Take the first element at the top of b
and put it at the top of a. Do nothing if b is empty. */
int	push_a(int *st_a, int *st_b)
{
	int	i;

	i = get_last(st_a) + 1;
	while (--i >= 0)
	{
		st_a[i + 1] = st_a[i];
	}
	st_a[0] = st_b[0];
	while (++i <= get_last(st_b))
	{
		st_b[i] = st_b[i + 1];
	}
	ft_printf("pa\n");
	return (1);
}

/* pb (push b): Take the first element at the top of a
and put it at the top of b. Do nothing if a is empty. */
int	push_b(int *st_a, int *st_b)
{
	int	i;

	i = get_last(st_a) + 1;
	while (--i >= 0)
	{
		st_b[i + 1] = st_b[i];
	}
	st_b[0] = st_a[0];
	while (++i <= get_last(st_b))
	{
		st_a[i] = st_a[i + 1];
	}
	ft_printf("pb\n");
	return (1);
}
