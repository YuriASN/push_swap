/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:35:34 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/03 23:01:16 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a string representing the integer received as an argument.
Negative numbers must be handled. */

static int	nbr_size(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * nbr_size(n) + 1);
	if (!str)
		return (0);
	i = nbr_size(n);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		--i;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* int	main(void)
{
	char	*a;
	int		x;

	x = 0;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	x = -5859;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	x = -1234;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	return (0);
} */
