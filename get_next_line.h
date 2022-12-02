/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:56 by echavez-          #+#    #+#             */
/*   Updated: 2022/12/02 18:20:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

/*
**	Utils
*/

int		ft_strchr(char *str, char c);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_fstrdup(char **fsrc, const char *src);

#endif
