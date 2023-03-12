
#include "push_swap.h"

/*	Change reversed order on stack a. */
static void	change_order(t_stk *stk_a, t_stk *stk_b)
{
	while (stksize(stk_a->nxt) > 3)
		push_stk(stk_a, stk_b, 1);
	if (stksize(stk_a->nxt) == 3)
		swap_stk(stk_a, 1);
	rotate_rev(stk_a, 1);
	while (stk_b->nxt)
	{
		push_stk(stk_b, stk_a, 2);
		rotate_stk(stk_a, 1);
	}
	clean_quit(stk_a);
}

static void	order3a(t_stk *stk)
{
	int	low;

	low = get_lowest(stk->nxt);
	if (check_order_r(stk))
	{
		swap_stk(stk, 1);
		rotate_rev(stk, 1);
	}
	else if (stk->nxt->value < stk->nxt->nxt->nxt->value && low == 1)
		swap_stk(stk, 1);
	else if (stk->nxt->nxt->value > stk->nxt->nxt->nxt->value && low == 0)
	{
		swap_stk(stk, 1);
		rotate_stk(stk, 1);
	}
}

/* Get only stk a in order when a second stk is alredy ordered */
static void	order_a(t_stk *stk)
{
	if (stksize(stk->nxt) == 3)
		order3a(stk);
	while (!check_order(stk))
	{
		if (stk->nxt->value > stk->nxt->nxt->value && get_lowest(stk->nxt) != 1)
			swap_stk(stk, 1);
		if (order_loop(stk) && get_lowest(stk->nxt) < 0)
			while (!check_order(stk))
				rotate_rev(stk, 1);
		if (!check_order(stk))
			rotate_stk(stk, 1);
	}
}

/* Start process of what to do in different conditions.
If any changes are made it starts to check all over again. */
void	get_order(t_stk *stk_a, t_stk *stk_b)
{
	if (check_order(stk_a) && !stk_b->nxt)
		clean_quit(stk_a);
	if (order_loop(stk_a))
		clean_quit(stk_a);
	if (stksize(stk_a->nxt) > 6 || stksize(stk_a->nxt) == 5)
	{
		order_big(stk_a, stk_b);
		if (order_loop_rev(stk_a) || check_order_r(stk_a))
			change_order(stk_a, stk_b);
	}
	else
	{
		order_a(stk_a);
		clean_quit(stk_a);
	}
}
