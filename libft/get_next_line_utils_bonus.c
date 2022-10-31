/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:17:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/06/05 18:42:34 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_newline(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i])
	{
		if (j >= 0)
			buffer[j++] = buffer[i];
		if (j == -1 && buffer[i] == '\n')
			j = 0;
		buffer[i++] = 0;
	}
	return (j >= 0);
}

static int	part_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*bufferjoin(char *str, char *buffer)
{
	int		j;
	char	*temp;

	j = 0;
	temp = malloc(part_str(buffer) + part_str(str) + 1);
	if (!temp)
		return (NULL);
	while (str && str[j])
	{
		temp[j] = str[j];
		j++;
	}
	while (*buffer)
	{
		temp[j++] = *buffer;
		if (*buffer++ == '\n')
			break ;
	}
	temp[j] = 0;
	if (str)
		free(str);
	return (temp);
}
