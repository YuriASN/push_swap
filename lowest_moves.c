/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:25:41 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/23 16:25:52 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_move(int *a, int *b, int *tmp)
{
	while (*a < 0 && *b < 0)
	{
		++*tmp;
		++*a;
		++*b;
	}
	while (*a > 0 && *b > 0)
	{
		++*tmp;
		--*a;
		--*b;
	}
}

static void	count_move(int *a, int *b, int *tmp)
{
	while (*a)
	{
		if (*a < 0)
			++*a;
		else
			--*a;
		++*tmp;
	}
	while (*b)
	{
		if (*b < 0)
			++*b;
		else
			--*b;
		++*tmp;
	}
}

/*	Returns the index of the best number of B to move.
	less_moves[0] saves the index while less_moves[1] saves moves.*/
int	get_lowest_moves(int **move, int b_size)
{
	int	i;
	int	tmp;
	int	less_moves[2];
	int	a;
	int	b;

	i = -1;
	less_moves[0] = 0;
	less_moves[1] = INT_MAX;
	while (++i < b_size)
	{
		tmp = 0;
		a = move[i][0];
		b = move[i][1];
		if ((a < 0 && b < 0) || (a > 0 && b > 0))
			both_move(&a, &b, &tmp);
		if (a || b)
			count_move(&a, &b, &tmp);
		if (tmp < less_moves[1])
		{
			less_moves[0] = i;
			less_moves[1] = tmp;
		}
	}
	return (less_moves[0]);
}
