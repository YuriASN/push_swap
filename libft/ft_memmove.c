/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:49:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/03 21:51:59 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	if ((unsigned char *)src < (unsigned char *)dest)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			--n;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}

/* int	main(void)
{
	const char	src[50] = "https://profile.intra.42.fr/";
	char		dest[50] = "Heloooo!!";

	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, ft_strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	return (0);
} */
/* int	main(void)
{
	char str1[50] = "I am going from Delhi to Gorakhpur";
	char str2[50] = "I am going from Delhi to Gorakhpur";
//Use of memmove
	printf("Function:\tft_memmove with overlap\n");
	printf("Orignal :\t%s\n",str1);
	printf("Source:\t\t%s\n", str1 + 5);
	printf("Destination:\t%s\n", str1 + 11);
	ft_memmove(str1 + 11, str1 + 5, 29);
	printf("Result:\t\t%s\n", str1);
	printf("Length:\t\t%ld characters\n\n", ft_strlen(str1));
//Use of ft_memcpy
	printf("Function:\tft_memcpy with overlap\n" );
	printf("Orignal :\t%s\n",str2);
	printf("Source:\t\t%s\n", str2 + 5);
	printf("Destination:\t%s\n", str2 + 11);
	ft_memcpy(str2 + 11, str2 + 5, 29);
	printf("Result:\t\t%s\n", str2);
	printf("Length:\t\t%ld characters\n\n", ft_strlen(str2));
	return (0);
} */
