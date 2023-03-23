
#include "push_swap.h"

/* Gets the 1st node (no value) of the list.
Check if stack A is completely on order and returns TRUE or FALSE. */
int	check_order(t_stk *stack)
{
	if (!stack)
		return (0);
	if (!stack->nxt || !stack->nxt->nxt)
		return (1);
	stack = stack->nxt;
	while (stack->nxt)
	{
		if (stack->value > stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

/* Gets the 1st node (no value) of the list.
Check if stack B is completely on reverse order and returns TRUE or FALSE. */
int	check_order_r(t_stk *stack)
{
	if (!stack)
		return (0);
	if (!stack->nxt || !stack->nxt->nxt)
		return (1);
	stack = stack->nxt;
	while (stack->nxt)
	{
		if (stack->value < stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

/* Gets 1st node with value and returns lowest value from the stack */
static int	lowest_value(t_stk *stk)
{
	int	low;

	if (!stk)
		return (0);
	low = stk->value;
	while (stk->nxt)
	{
		if (low > stk->nxt->value)
			low = stk->nxt->value;
		stk = stk->nxt;
	}
	return (low);
}

int	get_lowest(t_stk *stk)
{
	int	lowest;
	int	count;
	int	size;

	if (!stk || !stk->nxt)
		return (0);
	lowest = lowest_value(stk);
	count = 0;
	size = stksize(stk);
	while (stk)
	{
		++count;
		if (stk->value == lowest)
			break ;
		stk = stk->nxt;
	}
	if (count > size / 2)
		count = (size - count) * -1;
	return (count - 1);
}

/* Gets the 1st node with value of the list.
Return the amount of rotates or rev rotate if negative
to get to the highest number on bottom. */
int	get_highest(t_stk *stk)
{
	int	highest;
	int	first;
	int	count;
	int	size;

	if (!stk || !stk->nxt)
		return (0);
	size = stksize(stk);
	first = stk->value;
	count = 0;
	highest = highest_value(stk);
	stk = stklast(stk);
	if (highest == first)
		return (1);
	while (stk->value != first)
	{
		if (stk->value == highest)
			break ;
		--count;
		stk = stk->prev;
	}
	if ((count * -1) > size / 2)
		count = size - (count * -1);
	return (count);
}
