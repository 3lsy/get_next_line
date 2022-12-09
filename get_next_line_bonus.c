/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:03:01 by echavez-          #+#    #+#             */
/*   Updated: 2022/12/09 16:15:11 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	fill_buffer(char **buffer, int fd)
{
	char	*buffy;
	int		end;

	buffy = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffy || BUFFER_SIZE < 1)
	{
		free(buffy);
		return (0);
	}
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	buffy[0] = 0;
	while (ft_strchr(buffy, '\n') == -1)
	{
		end = read(fd, buffy, BUFFER_SIZE);
		if (end <= 0)
			break ;
		buffy[end] = 0;
		*buffer = ft_strjoin(buffer, buffy);
	}
	free(buffy);
	if (end < 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX] = {NULL};
	char		*line;
	int			enter;

	if (fd >= FOPEN_MAX || fd < 0)
		return (NULL);
	if (!fill_buffer(&buffer[fd], fd))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	enter = ft_strchr(buffer[fd], '\n');
	if (enter >= 0)
	{
		line = ft_strdup(buffer[fd]);
		line[enter + 1] = 0;
		buffer[fd] = ft_fstrdup(&buffer[fd], &buffer[fd][enter + 1]);
		return (ft_fstrdup(&line, line));
	}
	if (buffer[fd][0] != 0)
		return (ft_fstrdup(&buffer[fd], buffer[fd]));
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (NULL);
}
