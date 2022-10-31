/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:24:10 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/31 01:45:59 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies n characters from memory area src to memory area dest.
This function returns a pointer to destination, which is dest. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

/* int	main(void)
{
	char	*src = malloc(4);
	char		dest[50] = "";

	memset(src, 'A', 3);
	printf("original = %s\n", memcpy(NULL, src, 3));
	printf("mine = %s\n", ft_memcpy(NULL, src, 3));
	return (0);
} */
