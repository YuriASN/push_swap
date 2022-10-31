/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:44:07 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/27 01:39:59 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Deletes and frees the given node and every
successor of that node, using the function ’del’ and free.
Finally, the pointer to the list must be set to NULL. */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!*lst || !*del)
		return ;
	while (*lst)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	lst = NULL;
}
