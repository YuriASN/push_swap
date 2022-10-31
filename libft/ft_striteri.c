/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:47:13 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/24 02:35:26 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function 'f' on each char of the string passed as argument,
passing its index as 1st argument.
Each char is passed by address to 'f' to be modified if necessary. */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}
