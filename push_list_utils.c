/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:07:07 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/13 21:09:28 by ysantos-         ###   ########.fr       */
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

void	print_list(t_stk *lst){
	if (!lst->nxt)
		return ;
	while (lst->nxt)
	{
		ft_printf("%i\n", lst->nxt->value);
		lst = lst->nxt;
	}
	printf("\n");
}
