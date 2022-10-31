/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/06/05 18:42:41 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*str;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (0);
	i = 1;
	str = NULL;
	while (i > 0)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			str = bufferjoin(str, buffer[fd]);
		if (has_newline(buffer[fd]))
			break ;
	}
	return (str);
}
