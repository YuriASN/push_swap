
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

/* Gets the 1st node with value of the list.
Return the amount of rotates to get to the lowest number. */
int	get_lowest(t_stk *stk)
{
	int	lowest;
	int	sv;
	int	count;

	if (!stk)
		return (0);
	lowest = 0;
	count = -1;
	sv = stk->value;
	if (!stk->nxt)
		return (0);
	while (++count <= stksize(stk) / 2)
	{
		if (sv > stk->nxt->value)
		{
			sv = stk->nxt->value;
			lowest = count + 1;
		}
		stk = stk->nxt;
	}
	if (!stk)
		return (lowest);
	count = (count * -1) - 1;
	if (stksize(stk) % 2)
		--count;
	while (stk->nxt)
	{
		if (sv > stk->nxt->value)
		{
			sv = stk->nxt->value;
			lowest = count + 1;
		}
		stk = stk->nxt;
		++count;
	}
//printf("Lowest = %i, in index %i\n", sv, lowest);
	return (lowest);
}

/* Gets the 1st node with value of the list.
Return the amount of rotates or rev rotate if negative
to get to the highest number on top. */
int	get_highest(t_stk *stk)
{
	int	highest;
	int	sv;
	int	count;

	if (!stk)
		return (0);
	highest = 0;
	count = -1;
	sv = stk->value;
	if (!stk->nxt)
		return (0);
	while (++count <= stksize(stk) / 2)
	{
		if (sv < stk->nxt->value)
		{
			sv = stk->nxt->value;
			highest = count + 1;
		}
		stk = stk->nxt;
	}
	if (!stk)
		return (highest);
	count *= -1;
	if (stksize(stk) % 2)
		--count;
	while (stk->nxt)
	{
		if (sv < stk->nxt->value)
		{
			sv = stk->nxt->value;
			highest = count + 1;
		}
		stk = stk->nxt;
		++count;
	}
//printf("Highest = %i, in index %i\n", sv, highest);
	return (highest);
}

/* Gets 1st node with value and returns highest value from the stack */
int	highest_value(t_stk *stk)
{
	int	high;

	if (!stk)
		return (0);
	high = stk->value;
	while (stk->nxt)
	{
		if (high < stk->nxt->value)
			high = stk->nxt->value;
		stk = stk->nxt;
	}
	return (high);
}
