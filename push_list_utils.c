/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:07:07 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/06 13:52:14 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Link the given argument as last on the stack.
t_stk	*get_stack(t_stk **stack, int value)
{
	t_stk	*new;

	new = (t_stk *)malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->value = value;
	new->nxt = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		ft_lstadd_back(stack, new);
		new->prev = ft_lstlast(*stack);
	}
	return (new);
}

//Set value of data to 0 avoiding data leak.
void	del_data(void *data)
{
	data = 0;
}
