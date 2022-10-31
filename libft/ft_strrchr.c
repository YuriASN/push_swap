/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:32:38 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/30 23:32:49 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* searches for the LAST occurrence of the character c (an unsigned char)
in the string pointed to, by the argument str. */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return (&((char *)s)[i]);
		--i;
	}
	return (0);
}

/* int	main(void)
{
	int			len;
	const char	str[] = "https://profile.intra.42.fr/";
	const char	ch = 'i';
	char		*ret;

	ret = ft_strrchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
} */
