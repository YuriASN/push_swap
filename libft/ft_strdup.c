/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:49:42 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/29 21:46:55 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function returns a pointer to a null-terminated byte string,
which is a duplicate of the string pointed to by str.
The memory obtained is done using malloc and hence it can be freed using free(). 
It returns a pointer to the duplicated string s. */

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!cpy || !str)
		return (0);
	while (str[i])
	{
		cpy[i] = str[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}

/* int	main(void)
{
	char	source[] = "GeeksForGeeks";
	char	*target = ft_strdup(source);

	printf("Source: %s\nTarget: %s\n", source, target);
	return (0);
} */
