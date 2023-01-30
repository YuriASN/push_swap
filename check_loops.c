#include "push_swap.h"

/*	Rotate stack A until it gets on order if rev = FALSE
	or until gets on reverse order if rev = TRUE
	Always return true.*/
int	fix_loop(t_stk *stk, int rev)
{
	if (rev == 0)
	{
		if (get_lowest(stk) >= 0)
			while (!check_order(stk))
				rotate_stk(stk, 1);
		else
			while (!check_order(stk))
				rotate_rev(stk, 1);
	}
	if (rev == 1)
	{
		if (get_lowest(stk->nxt) >= 0)
			while (!check_order_r(stk))
				rotate_stk(stk, 1);
		else
			while (!check_order_r(stk))
				rotate_rev(stk, 1);
	}
	return (1);
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
				return (fix_loop(stk, 0));
			s = stk->nxt;
		}
		if (s->nxt->value == high)
			return (fix_loop(stk, 0));
		if (s->value > s->nxt->value && s->value != high)
			return (0);
		s = s->nxt;
	}
	return (0);
}

/* Check if stack is on order but allowing the search to loop
	If it's on loop it already changes to order.
Return "0" if isn't and "1" if it was */
int	order_loop(t_stk *stk)
{
	t_stk	*s;
	int		high;

	s = stk->nxt;
	high = s->value;
	while (s->nxt)
	{
		if (high < s->nxt->value)
			high = s->nxt->value;
		s = s->nxt;
	}
	s = stk->nxt;
	while (s->value != high)
		s = s->nxt;
	return (order_loop_cont(s, stk, high));
}

/* Continues order_loop function. */
static int	order_loop_rev_cont(t_stk *s, t_stk *stk, int low)
{
	while (s)
	{
		if (!s->nxt)
		{
			if (s->value < stk->nxt->value && stk->nxt->value != low)
				return (0);
			if (stk->nxt->value == low)
				return (fix_loop(stk, 1));
			s = stk->nxt;
		}
		if (s->nxt->value == low)
			return (fix_loop(stk, 1));
		if (s->value < s->nxt->value && s->value != low)
			return (0);
		s = s->nxt;
	}
	return (0);
}

/* Check if stack is on rev order but allowing the search to loop
If it's on loop it already changes to reverse order.
Return "0" if isn't and "1" if it was */
int	order_loop_rev(t_stk *stk)
{
	t_stk	*s;
	int		low;

	s = stk->nxt;
	low = s->value;
	while (s->nxt)
	{
		if (low > s->nxt->value)
			low = s->nxt->value;
		s = s->nxt;
	}
	s = stk->nxt;
	while (s->value != low)
		s = s->nxt;
	return (order_loop_rev_cont(s, stk, low));
}
