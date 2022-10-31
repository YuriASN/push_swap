/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:57:26 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/28 22:44:25 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copy the number of bytes of dstsize from src to dst.
Note that dstsize must be the length you want +1 for the null character
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}

/* int	main(void)
{
	int		set;
	char	in[20];
	char	out[20] = {"Hello World!"};

	set = ft_strlcpy(in, out, 13);
	printf("%s\n%d\n", in, set);
	return (0);
} */
