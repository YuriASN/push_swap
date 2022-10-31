/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:13:24 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/27 19:20:59 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* erases the data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes
containing '\0') to that area. */

void	ft_bzero(void *s, size_t bytes)
{
	size_t	index;

	index = 0;
	while (index < bytes)
		((unsigned char *)s)[index++] = '\0';
}
