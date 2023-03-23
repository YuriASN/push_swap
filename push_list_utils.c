/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:15:55 by ysantos-          #+#    #+#             */
/*   Updated: 2023/03/23 15:40:09 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Deletes and frees the given node and every
successor of that node, using the function ’del’ and free.
Finally, the pointer to the list must be set to NULL. */
void	stkclear(t_stk *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		lst->value = 0;
		lst = lst->nxt;
	}
	lst = NULL;
}

//Free stk before quiting.
void	clean_quit(t_stk *stk)
{
	if (!stk)
		return ;
	stkclear(stk);
	exit (0);
}

/* Gets the 1st node with value of the list.
Returns the number of nodes on the list */
int	stksize(t_stk *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		lst = lst->nxt;
		++count;
	}
	return (count);
}

/* Returns the last node of the stack.
Gets the 1st node (no value) of the list. */
t_stk	*stklast(t_stk *lst)
{
	if (!lst)
		return (0);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
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
