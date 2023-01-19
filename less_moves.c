#include "push_swap.h"

/*	Get how many moves it needs to place B on A.
	Positive numbers are rotate moves.
	Negative numbers are reverse rotate moves. */
static void	get_a_moves(t_stk *stk_a, int b, int *moves)
{
	t_stk	*tmp_a;
	int		size_a;

	size_a = stksize(stk_a->nxt);
	tmp_a = stk_a;
	moves[0] = -1;
	while (tmp_a->nxt)
	{
		tmp_a = tmp_a->nxt;
		while (moves[0] <= size_a / 2)
		{
			if (b < tmp_a->value)
				return ;
			++moves[0];
			tmp_a = tmp_a->nxt;
		}
		moves[0] *= -1;
		++moves[0];
		while (moves[0] != 0)
		{
			if (b < tmp_a->value && b > stklast(tmp_a)->value)
				return ;
			tmp_a = tmp_a->nxt;
			++moves[0];
		}
	}
}

/*	Start comparing B list to get moves of each number. */
static void	get_moves(t_stk *stk_a, t_stk *stk_b, int **moves)
{
	int		i;
	int		size_b;
	t_stk	*tmp_b;

	tmp_b = stk_b->nxt;
	size_b = stksize(stk_b->nxt);
	i = -1;
	while (++i <= size_b / 2)
	{
		get_a_moves(stk_a, tmp_b->value, moves[i]);
		tmp_b = tmp_b->nxt;
		++moves[i][1];
	}
	moves[i][1] *= -1;
	while (++i < size_b)
	{
		get_a_moves(stk_a, tmp_b->value, moves[i]);
		tmp_b = tmp_b->nxt;
		++moves[i][1];
	}
}

/*	Returns the index of the best number of B to move */
static int	get_lowest_moves(int **mv, int b_size)
{
	int	i;
	int	tmp;
	int	less_moves;
	int	**moves;

	moves = mv;
	if (moves[0][0] == 0 && moves[0][1] == 0)
		return (0);
	i = -1;
	less_moves = INT_MAX;
	while (++i < b_size)
	{
		tmp = 0;
		while (moves[i][0] < 0 && moves[i][1] < 0)
		{
			++tmp;
			++moves[i][0];
			++moves[i][1];
		}
		while (moves[i][0] > 0 && moves[i][1] > 0)
		{
			++tmp;
			--moves[i][0];
			--moves[i][1];
		}
		while (moves[i][0])
		{
			if (moves[i][0] < 0)
				++moves[i][0];
			else
				--moves[i][0];
			++tmp;
		}
		while (moves[i][1])
		{
			if (moves[i][1] < 0)
				++moves[i][1];
			else
				--moves[i][1];
			++tmp;
		}
		if (tmp < less_moves)
		{
			less_moves = tmp;
		}
	}
	return (less_moves);
}

/*	Swap best the best option from B to A */
static void	make_move(t_stk *stk_a, t_stk *stk_b, int *moves)
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
	while (moves[0])
	{
		if (moves[0] < 0)
		{
			rotate_rev(stk_a, 1);
			++moves[0];
		}
		else
		{
			rotate_stk(stk_a, 1);
			--moves[0];
		}
	}
	while (moves[1])
	{
		if (moves[1] < 0)
		{
			rotate_rev(stk_b, 2);
			++moves[1];
		}
		else
		{
			rotate_stk(stk_b, 2);
			--moves[1];
		}
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
	move_size = stksize(stk_b);
	moves = malloc(sizeof(int **) * move_size);
	while (++i < move_size)
		moves[i] = ft_calloc(sizeof(int *), 2);
	while (stk_b->nxt)
	{
		get_moves(stk_a, stk_b, moves);
		less_moves = get_lowest_moves(moves, stksize(stk_b));
		get_moves(stk_a, stk_b, moves);
printf("less moves = %i\t stk a move %i, stk b move %i\n", less_moves, moves[less_moves][0], moves[less_moves][1]);
		make_move(stk_a, stk_b, moves[less_moves]);
	}
printf("FIM \n\n%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
	i = -1;
	while (++i < move_size)
		free(moves[i]);
	free(moves);
	clean_quit(stk_a);
}
