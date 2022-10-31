/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:49:37 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/24 02:56:09 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

static int	is_equal(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[0] == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*newstr;

	if (!s1)
		return (0);
	i = 0;
	j = 0;
	while (is_equal(&(s1[i]), set))
		++i;
	j = ft_strlen(s1) - 1;
	while (is_equal(&(s1[j]), set))
		--j;
	if ((j - i) < 0)
	{
		newstr = ft_substr(s1, 0, 0);
		return (newstr);
	}
	newstr = ft_substr(s1, i, j - i + 1);
	return (newstr);
}

/* int	main(void)
{
	char	*str = "\t   \n\n\n  \n\n\t \t\t\t\n  \t\t\t\t  ";
	char	*set = " \n\t";
	printf("A str antiga e': %s\nA str nova e': %s\n", str, ft_strtrim(str, set));
	
	str = "abcdba";
	set = "abc";
	printf("A str antiga e': %s\nA str nova e': %s\n", str, ft_strtrim(str, set));
	
	str = "   xxxtripouille   xxx";
	set = " x";
	printf("A str antiga e': %s\nA str nova e': %s\n", str, ft_strtrim(str, set));
	
	return (0);
} */
