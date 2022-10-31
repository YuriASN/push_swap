/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:17:50 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:03:06 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isascii() function tests if a given character, in the current locale,
can be represented as a valid 7–bit US-ASCII character.
Return 1 if it is ASCII
Return 0 if it isn't*/

int	ft_isascii(int x)
{
	if (x >= 0 && x <= 127)
		return (1);
	else
		return (0);
}
