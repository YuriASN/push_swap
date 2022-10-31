/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:25 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/03 20:15:36 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* compares the first n bytes of memory area str1 and memory area str2.
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)str1)[index] != ((unsigned char *)str2)[index])
			return (((unsigned char *)str1)[index]
			- ((unsigned char *)str2)[index]);
		++index;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[15] = "abCdef";
	char	str2[15] = "abcdEF";
	int		ret;

	ret = ft_memcmp(str1, str2, 6);
	if (ret > 0)
		printf("str2 is less than str1\n");
	else if (ret < 0)
		printf("str1 is less than str2\n");
	else
		printf("str1 is equal to str2\n");
	return (0);
} */
