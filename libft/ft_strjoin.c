/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:33:34 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/24 02:40:26 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, ft_strlen(newstr) + ft_strlen(s2) + 1);
	return (newstr);
}

/* int	main(void)
{
	char	str1[30] = "Hello, ";
	char	str2[30] = "my name is Dude.";

	printf("str1 = %s\nStr2 = %s\nstrjoin = %s\n", str1,
	str2, ft_strjoin(str1, str2));
	return (0);
} */
