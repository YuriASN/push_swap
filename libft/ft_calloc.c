/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:28:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/28 21:36:52 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function allocates space for number of objects, each size
bytes in length. The result is identical to calling malloc() with an
argument of number * size, with the exception that the allocated memory
is explicitly initialized to zero bytes.
*/

void	*ft_calloc(size_t number, size_t size)
{
	void	*a;

	a = malloc(number * size);
	if (!a)
		return (0);
	ft_memset(a, 0, (number * size));
	return (a);
}
