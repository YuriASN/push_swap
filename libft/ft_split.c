/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:38:58 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/24 03:13:17 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns an array of strings obtained by splitting ’s’
using the character ’c’ as a delimiter.
The array must end with a NULL pointer. */

#include "libft.h"

static size_t	count_strings(char const *s, char const c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s[i])
		return (count);
	while (s[i] == c && s[i])
		++i;
	while (s[i])
	{
		if (s[i] == c)
		{
			++count;
			while (s[i] == c && s[i + 1])
				++i;
		}
		++i;
	}
	if (s[i - 1] != c && !s[i])
		++count;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	str;
	size_t	i;
	size_t	save;

	if (!s)
		return (0);
	arr = (char **)malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	str = 0;
	i = 0;
	while (str < count_strings(s, c))
	{
		while (s[i] == c)
			++i;
		save = i;
		while (s[i] != c && s[i])
			i++;
		arr[str] = ft_substr(s, save, (i - save));
		++str;
	}
	arr[str] = NULL;
	return (arr);
}

/* int	main(void)
{
	char	*str = "";
	char	**result;
	int		nbr;
	int		i;
	char	c = ' ';

	nbr = count_strings(str, c);
	//printf("%d\n", nbr);
	result = ft_split(str, c);
	for(i = 0; i < nbr; ++i)
	{
		printf("String n %d = %s\n", i + 1, result[i]);
	}
	return (0);
} */
