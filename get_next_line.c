/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:43 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/25 18:54:29 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_buffer(char **buffer, int fd)
{
	char	buffy[BUFFER_SIZE + 1];
	int		end;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffy, 0))
		return (0);
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	while (ft_strchr(*buffer, '\n') == -1)
	{
		end = read(fd, buffy, BUFFER_SIZE);
		if (end == 0)
			break ;
		if (end < 0)
			return (0);
		buffy[end] = 0;
		*buffer = ft_strjoin(buffer, buffy);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			enter;

	if (!fill_buffer(&buffer, fd))
	{
		free(buffer);
		return (NULL);
	}
	enter = ft_strchr(buffer, '\n');
	if (enter >= 0)
	{
		line = ft_strdup(buffer);
		line[enter + 1] = 0;
		buffer = ft_fstrdup(&buffer, &buffer[enter + 1]);
		return (ft_fstrdup(&line, line));
	}
	if (buffer[0] == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (ft_fstrdup(&buffer, buffer));
}
