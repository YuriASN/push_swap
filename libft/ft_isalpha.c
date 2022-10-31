/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:04:03 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:01:11 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalpha() function checks whether a character is an alphabet or not.
Return 0 if isn't a letter
return 1 for uppercase letter and 2 for lowercase letters*/

int	ft_isalpha(int x)
{
	if (x >= 'a' && x <= 'z')
		return (2);
	else if (x >= 'A' && x <= 'Z')
		return (1);
	else
		return (0);
}
