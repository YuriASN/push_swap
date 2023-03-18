
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
Return the amount of rotates to get to the lowest number on top. */
int	get_lowest(t_stk *stk)
{
	int	lowest;
	int	sv;
	int	count;
	int	size;

	if (!stk || !stk->nxt)
		return (0);
	lowest = 0;
	count = -1;
	size = stksize(stk);
	sv = stk->value;
	while (++count < size / 2 && stk->nxt)
	{
		if (sv > stk->nxt->value)
		{
			sv = stk->nxt->value;
			lowest = count + 1;
		}
		stk = stk->nxt;
	}
	if (!stk->nxt)
		return (lowest);
	if (size % 2)
		++count;
	count *= -1;
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
	return (lowest);
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
//fprintf(stderr, "highest nbr = %i\t in index to bottom %i\n", highest, count);
	return (count);
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
