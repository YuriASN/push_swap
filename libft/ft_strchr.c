/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:51:11 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/30 23:32:29 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Find for the first character c (an unsigned char)
in the string pointed to by the argument str.
This returns a pointer to the 1st occurrence c in the string str,
or NULL if the character is not found. */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		++i;
	}
	if (str[i] == (unsigned char)c)
		return (&((char *)str)[i]);
	return (0);
}
