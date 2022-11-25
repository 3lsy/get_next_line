/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:46:25 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/25 18:50:13 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*s;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1_len > i)
	{
		s[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2_len > j)
		s[i++] = s2[j++];
	s[i] = 0;
	free(*s1);
	*s1 = NULL;
	return (s);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		lens;
	char	*cpy;

	lens = ft_strlen(src);
	cpy = malloc(sizeof(char) * (lens + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_fstrdup(char **fsrc, const char *src)
{
	int		i;
	int		lens;
	char	*cpy;

	lens = ft_strlen(src);
	cpy = malloc(sizeof(char) * (lens + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	free(*fsrc);
	*fsrc = NULL;
	return (cpy);
}
