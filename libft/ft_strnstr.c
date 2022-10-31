/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:30:07 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:18:23 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function locates the	first occurrence of the SRC in the
string CMP, where not more than	LEN characters in CMP are searched.
Characters that appear after a `\0'	character are not searched.
If	SRC is an empty string, CMP is returned; if SRC occurs nowhere
in	CMP, NULL is returned; otherwise a pointer to the first	character of
the first occurrence of SRC is returned.*/

char	*ft_strnstr(const char	*cmp, const char *src, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	if (src[0] == '\0')
		return ((char *)cmp);
	while (cmp[a] && a < len)
	{
		b = 0;
		c = a;
		while (src[b] == cmp[c] && src[b] && c < len && cmp[c])
		{
			if (src[b + 1] == '\0')
				return (&((char *)cmp)[a]);
			++c;
			++b;
		}
		++a;
	}
	return (0);
}

/* int	main(void)
{
	const char	*cmp = "Foo Bar Baz Bar Love";
	const char	*src = "Bar";
	char		*ptr;

	ptr = ft_strnstr(cmp, src, 20);
	printf("cmp = %s\nptr = %s\n", cmp, ptr);
	return (0);
} */
