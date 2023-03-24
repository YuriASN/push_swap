/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:25:45 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/24 03:01:53 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Get how many moves it needs to place B on A.
	Positive numbers are rotate moves.
	Negative numbers are reverse rotate moves. */
static void	get_a_moves(t_stk *stk_a, int b, int *moves)
{
	t_stk	*tmp_a;
	int		size_a;

	size_a = stksize(stk_a->nxt);
	tmp_a = stk_a->nxt;
	moves[0] = 0;
	if (highest_value(stk_a->nxt) < b)
	{
		moves[0] = get_highest(stk_a->nxt);
		return ;
	}
	if ((b < tmp_a->value && b > (stklast(tmp_a))->value) || size_a <= 1)
		return ;
	while (tmp_a->nxt)
	{
		moves[0]++;
		if (b > tmp_a->value && b < tmp_a->nxt->value)
			break ;
		tmp_a = tmp_a->nxt;
	}
	if (moves[0] > size_a / 2)
		moves[0] = (size_a - moves[0]) * -1;
}

/*	Start comparing B list to get moves of each number. */
static void	get_moves(t_stk *stk_a, t_stk *stk_b, int **moves)
{
	int		i;
	int		size_b;
	t_stk	*tmp_b;

	tmp_b = stk_b->nxt;
	size_b = stksize(stk_b->nxt);
	if (size_b == 1)
	{
		moves[0][1] = 0;
		get_a_moves(stk_a, tmp_b->value, moves[0]);
		return ;
	}
	i = 0;
	while (tmp_b)
	{
		get_a_moves(stk_a, tmp_b->value, moves[i]);
		tmp_b = tmp_b->nxt;
		if (i > size_b / 2)
			moves[i][1] = (size_b - i) * -1;
		else
			moves[i][1] = i;
		++i;
	}
}

static void	move_both(t_stk *stk_a, t_stk *stk_b, int *moves)
{
	while (moves[0] < 0 && moves[1] < 0)
	{
		rotate_rev_both(stk_a, stk_b);
		++moves[0];
		++moves[1];
	}
	while (moves[0] > 0 && moves[1] > 0)
	{
		rotate_both(stk_a, stk_b);
		--moves[0];
		--moves[1];
	}
}

/*	Swap best the best option from B to A */
static void	make_move(t_stk *stk_a, t_stk *stk_b, int *moves)
{
	if ((moves[0] < 0 && moves[1] < 0) || (moves[0] > 0 && moves[1] > 0))
		move_both(stk_a, stk_b, moves);
	while (moves[0] < 0)
	{
		moves[0]++;
		rotate_rev(stk_a, 1);
	}
	while (moves[0] > 0)
	{
		rotate_stk(stk_a, 1);
		--moves[0];
	}
	while (moves[1] < 0)
	{
		moves[1]++;
		rotate_rev(stk_b, 2);
	}
	while (moves[1] > 0)
	{
		rotate_stk(stk_b, 2);
		--moves[1];
	}
	push_stk(stk_b, stk_a, 2);
}

/*	Compares how many moves each of numbers from B
	has to make to find it's place on A */
void	less_moves(t_stk *stk_a, t_stk *stk_b)
{
	int	**moves;
	int	move_size;
	int	i;
	int	less_moves;

	i = -1;
	move_size = stksize(stk_b->nxt);
	moves = (int **)malloc(sizeof(int **) * move_size);
	while (++i < move_size)
		moves[i] = ft_calloc(sizeof(int *), 2);
	while (stk_b->nxt)
	{
		get_moves(stk_a, stk_b, moves);
		less_moves = get_lowest_moves(moves, stksize(stk_b->nxt));
		make_move(stk_a, stk_b, moves[less_moves]);
	}
	order_loop(stk_a);
	i = -1;
	while (++i < move_size)
		free(moves[i]);
	free(moves);
	clean_quit(stk_a);
}
