
#include "push_swap.h"

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
	else if (low == 0)
	{
		rotate_stk(stk, 1);
		swap_stk(stk, 1);
		rotate_rev(stk, 1);
	}
}

/* Continues order_loop function. */
static int	order_loop_cont(t_stk *s, t_stk *stk, int high)
{
	while (s)
	{
		if (!s->nxt)
		{
			if (s->value > stk->nxt->value && stk->nxt->value != high)
				return (0);
			if (stk->nxt->value == high)
				return (1);
			s = stk->nxt;
		}
		if (s->nxt->value == high)
			return (1);
		if (s->value > s->nxt->value)
			return (0);
		s = s->nxt;
	}
	return (0);
}

/* Check if stack is in order but allowing the search to loop
Return "0" if isn't and "1" if it's */
static int	order_loop(t_stk *stk)
{
	t_stk	*s;
	int		high;

	s = stk->nxt;
	high = s->value;
	while (s->nxt)
	{
		if (high > s->nxt->value)
			high = s->nxt->value;
		s = s->nxt;
	}
	s = stk->nxt;
	while (s->value != high)
		s = s->nxt;
	return (order_loop_cont(s, stk, high));
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
		if (order_loop(stk) && get_lowest(stk->nxt) > (stksize(stk->nxt)) / 2)
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
	if (stksize(stk_a->nxt) > 30 || stksize(stk_a->nxt) == 5)
		order_big(stk_a, stk_b);
	else
	{
		order_a(stk_a);
		clean_quit(stk_a);
	}
}
