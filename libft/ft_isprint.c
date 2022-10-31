/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:22:10 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:05:25 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isprint() function checks whether a
character is a printable character or not.
Return 1 if it is.
Return 0 if it isn't. */

int	ft_isprint(int x)
{
	if (x >= 32 && x <= 126)
		return (1);
	else
		return (0);
}
