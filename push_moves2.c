/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:14:50 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/03 21:27:53 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
int	rotate_a(int *st_a, int print)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = st_a[0];
	while (++i < get_last(st_a))
	{
		st_a[i] = st_a[i + 1];
	}
	st_a[i] = tmp;
	if (print){
		ft_printf("ra\n");
	int i= -1;
	while (st_a[++i])
		ft_printf("%i\tx\n", st_a[i]);}
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
int	rotate_b(int *st_b, int print)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = st_b[0];
	while (++i < get_last(st_b))
	{
		st_b[i] = st_b[i + 1];
	}
	st_b[i] = tmp;
	if (print){
		ft_printf("rb\n");
	int i= -1;
	while (st_b[++i])
		ft_printf("x\t%i\n", st_b[i]);}
	return (1);
}

//rr : ra and rb at the same time.
int	rotate_both(int *st_a, int *st_b)
{
	rotate_a(st_a, 0);
	rotate_b(st_b, 0);
	ft_printf("rr\n");
	int i= -1;
	while (st_a[++i] || st_b[i])
		ft_printf("%i\t%i\n", st_a[i], st_b[i]);
	return (1);
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */
int	rotate_back_a(int *st_a, int print)
{
	int	i;
	int	tmp;

	i = get_last(st_a);
	tmp = st_a[i];
	while (i > 0)
	{
		st_a[i] = st_a[i - 1];
		i--;
	}
	st_a[i] = tmp;
	if (print){
		ft_printf("rra\n");
	int i= -1;
	while (st_a[++i])
		ft_printf("%i\tx\n", st_a[i]);}
	return (1);
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one. */
int	rotate_back_b(int *st_b, int print)
{
	int	i;
	int	tmp;

	i = get_last(st_b);
	tmp = st_b[i];
	while (i > 0)
	{
		st_b[i] = st_b[i - 1];
		i--;
	}
	st_b[i] = tmp;
	if (print){
		ft_printf("rrb\n");
	int i= -1;
	while (st_b[++i])
		ft_printf("x\t%i\n", st_b[i]);}
	return (1);
}
