/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:53:03 by ysantos-          #+#    #+#             */
/*   Updated: 2022/10/31 16:16:20 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
int	swap_a(int **st_a, int print)
{
	int	tmp;

	tmp = *st_a[1];
	*st_a[1] = *st_a[0];
	*st_a[0] = *st_a[1];
	if (print)
		ft_printf("sa\n");
	return (1);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
int	swap_b(int **st_b, int print)
{
	int	tmp;

	tmp = *st_b[1];
	*st_b[1] = *st_b[0];
	*st_b[0] = *st_b[1];
	if (print)
		ft_printf("sb\n");
	return (1);
}

// ss : sa and sb at the same time.
int	swap_both(int **st_a, int **st_b)
{
	swap_a(st_a, 0);
	swap_b(st_b, 0);
	ft_printf("ss\n");
	return (1);
}

/* pa (push a): Take the first element at the top of b
and put it at the top of a. Do nothing if b is empty. */
int	push_a(int **st_a, int **st_b)
{
	int	i;

	i = get_last(st_a) + 1;
	while (--i >= 0)
	{
		*st_a[i + 1] = *st_a[i];
	}
	*st_a[0] = *st_b[0];
	while (++i <= get_last(st_b))
	{
		*st_b[i] = st_b[i + 1];
	}
	ft_printf("pa\n");
	return (1);
}

/* pb (push b): Take the first element at the top of a
and put it at the top of b. Do nothing if a is empty. */
int	push_b(int **st_a, int **st_b)
{
	int	i;

	i = get_last(st_a) + 1;
	while (--i >= 0)
	{
		*st_b[i + 1] = *st_b[i];
	}
	*st_b[0] = *st_a[0];
	while (++i <= get_last(st_b))
	{
		*st_a[i] = st_a[i + 1];
	}
	ft_printf("pb\n");
	return (1);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
int	rotate_a(int **st_a, int print)
{

	if (print)
		ft_printf("ra\n");
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
int	rotate_b(int **st_b, int print)
{

	if (print)
		ft_printf("rb\n");
	return (1);
}

//rr : ra and rb at the same time.
int	rotate_both(int **st_a, int **st_b)
{
	rotate_a(st_a, 0);
	rotate_b(st_b, 0);
	ft_printf("rr\n");
	return (1);
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */
int	rotate_back_a(int **st_a, int print)
{

	if (print)
		ft_printf("rra\n");
	return (1);
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one. */
int	rotate_back_b(int **st_b, int print)
{
	if (print)
		ft_printf("rrb\n");
	return (1);
}

//rrr : rra and rrb at the same time.
int	rotate_back_both(int **st_a, int **st_b)
{
	rotate_back_a(st_a, 0);
	rotate_back_b(st_b, 0);
	ft_printf("rrr\n");
	return (1);
}
