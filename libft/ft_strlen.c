/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:31:38 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 19:39:28 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Count the bytes of a string. Does NOT include the null char

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

/* int	main(void)
{
	char	*str;

	str = "123456789";
	printf("%d\n", ft_strlen(str));
	return (0);
} */
