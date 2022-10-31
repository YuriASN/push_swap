/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:34:49 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:22 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memset() function writes len bytes of value c (converted to an
unsigned char) to the string dest.	 Undefined behaviour from memset(),
resulting from storage overflow, will occur if len	is greater than	the
length of the dest	buffer.	 The behaviour is also undefined if dest is an
invalid pointer.
*/

void	*ft_memset(void *str, int c, int bytes)
{
	int	index;

	index = 0;
	while (index < bytes)
		((unsigned char *)str)[index++] = c;
	return (str);
}

/* int	main(void)
{
	char	str[50] = "This is string.h library function";

	printf("Before: %s\n", str);
	ft_memset(str, '$', 7);
	printf("After: %s\n", str);
	return (0);
} */
