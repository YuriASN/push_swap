/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:56:29 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/03 20:59:45 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strlcat() take the full size of the buffer (not just the length)
and guarantee to NUL-terminate the result
(as long as there is at least one byte free in dst).
#Note that a byte for the NULL should be included in size.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstlen >= dstsize)
		return (dstsize + srclen);
	ft_strlcpy(&(dst[dstlen]), src, dstsize - dstlen);
	return (dstlen + srclen);
}

/* {
	size_t	a;

	a = ft_strlen(dst);
	if (dstsize <= a + ft_strlen(src))
	{
		printf("in if\n");
		return (dstsize + ft_strlen(src));
	}
	else
	{
		printf("in else\n");
		ft_strlcpy(&dst[a], src, dstsize - a);
	}
	return (ft_strlen(dst));
} */

/* int	main(void)
{
	int		ret;
	char	*from = "the cake is a lie !\0I'm hidden lol\r\n";
	char	*to = "there is no stars in the sky";
	int		max = ft_strlen(from) + ft_strlen(to);

	ret = ft_strlcat(to, from, max);
	printf("%s\n%d\n", to, ret);
	return (0);
} */
