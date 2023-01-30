#include "push_swap.h"

/*	Get how many moves it needs to place B on A.
	Positive numbers are rotate moves.
	Negative numbers are reverse rotate moves. */
static void	get_a_moves(t_stk *stk_a, int b, int *moves)
{
	t_stk	*tmp_a;
	int		size_a;
	int		sv;

	size_a = stksize(stk_a->nxt);
	tmp_a = stk_a->nxt;
	moves[0] = 0;
	if ((b < tmp_a->value && b > (stklast(tmp_a))->value) || size_a <= 1)
		return ;
//printf("%spassou no b %i%s\n", RED, b, CRESET);
	while (++moves[0] <= size_a / 2)
	{
		if (b > tmp_a->value && b < tmp_a->nxt->value)
			return ;
		sv = tmp_a->value;
		tmp_a = tmp_a->nxt;
	}
	if (!tmp_a)
		return ;
	moves[0] = 0;
	tmp_a = stklast(tmp_a);
	while (tmp_a->value != sv)
	{
		--moves[0];
		if (b < tmp_a->value && b > tmp_a->prev->value)
			return ;
		tmp_a = tmp_a->prev;
	}
	moves[0] = get_highest(stk_a->nxt) + 1;
}

/*	Start comparing B list to get moves of each number. */
static void	get_moves(t_stk *stk_a, t_stk *stk_b, int **moves)
{
	int		i;
	int		size_b;
	int		sv;
	t_stk	*tmp_b;

	tmp_b = stk_b->nxt;
	size_b = stksize(stk_b->nxt);
	i = -1;
	while (++i <= size_b / 2)
	{
//printf("i = %i\t", i);
		get_a_moves(stk_a, tmp_b->value, moves[i]);
		sv = tmp_b->value;
		tmp_b = tmp_b->nxt;
		moves[i][1] = i;
//printf("move %i is %i, %i\n", i, moves[i][0], moves[i][1]);
	}
	if (!tmp_b)
		return ;
	moves[i][1] = 0;
	tmp_b = stklast(tmp_b);
	i = size_b - 1;
	while (tmp_b->value != sv)
	{
//printf("i = %i\t", i);
		get_a_moves(stk_a, tmp_b->value, moves[i]);
		tmp_b = tmp_b->prev;
		moves[i][1] = i - size_b;
//printf("move %i is %i, %i\n", i, moves[i][0], moves[i][1]);
		--i;
	}
//i = -1;	while (++i < size_b){printf("Move %i is %i, %i.\n", i, moves[i][0], moves[i][1]);}
}

/*	Returns the index of the best number of B to move */
static int	get_lowest_moves(int **move, int b_size)
{
	int	i;
	int	tmp;
	int	less_moves[2];
	int	a;
	int	b;
//printf("b size = %i\n", b_size);
	if (move[0][0] == 0 && move[0][1] == 0)
		return (0);
	i = -1;
	less_moves[0] = 0;
	less_moves[1] = INT_MAX;
	while (++i < b_size)
	{
		tmp = 0;
		a = move[i][0];
		b = move[i][1];
		while (a < 0 && b < 0)
		{
			++tmp;
			++a;
			++b;
		}
		while (a > 0 && b > 0)
		{
			++tmp;
			--a;
			--b;
		}
		while (a)
		{
			if (a < 0)
				++a;
			else
				--a;
			++tmp;
		}
		while (b)
		{
			if (b < 0)
				++b;
			else
				--b;
			++tmp;
		}
		if (tmp < less_moves[1])
		{
			less_moves[0] = i;
			less_moves[1] = tmp;
		}
	}
	return (less_moves[0]);
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
	moves = (int **)malloc(sizeof(int **) * move_size);
	while (++i < move_size)
		moves[i] = ft_calloc(sizeof(int *), 2);
	while (stk_b->nxt)
	{
//getchar();
		get_moves(stk_a, stk_b, moves);
		less_moves = get_lowest_moves(moves, stksize(stk_b->nxt));
//printf("less moves = %i\t stk a move %i, stk b move %i\n%slist a:%s\n", less_moves, moves[less_moves][0], moves[less_moves][1], BLU, CRESET); print_list(stk_a);	printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);  getchar();
		make_move(stk_a, stk_b, moves[less_moves]);
	}
	order_loop(stk_a);
//printf("FIM \n\n%slist a:%s\n", CYN, CRESET); 	print_list(stk_a);		printf("%slist b:%s\n", CYN, CRESET);	print_list(stk_b);
/* int lowest_pos = get_lowest(stk_a->nxt);
printf("lowest_pos = %i\n", lowest_pos);
if (lowest_pos > 0)
	{while (lowest_pos--)
		rotate_stk(stk_a, 1);}
else
	{while (lowest_pos++)
		rotate_rev(stk_a, 1);} */
	i = -1;
	while (++i < move_size)
		free(moves[i]);
	free(moves);
	clean_quit(stk_a);
}
