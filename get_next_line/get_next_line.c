/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:33:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/14 21:15:23 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_lineptr(char *lineptr)
{
	char	*res;

	if (!(ft_strchr(lineptr, '\n')))
		return (NULL);
	res = ft_strdup(ft_strchr(lineptr, '\n') + 1);
	if (!res)
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}
	return (res);
}

static char	*get_one_line(char *lineptr)
{
	char	*res;

	if (!ft_strchr(lineptr, '\n'))
		return (ft_strdup(lineptr));
	res = ft_strndup(lineptr, ft_strchr(lineptr, '\n') - lineptr + 1);
	if (!res)
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}
	return (res);
}

static char	*read_until_br(int fd, char *lineptr)
{
	char	*buf;
	int		rd;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr(lineptr, '\n') && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buf[rd] = '\0';
		tmp = ft_strjoin(lineptr, buf);
		if (!tmp)
			return (free(lineptr), free(buf), lineptr = NULL, NULL);
		free(lineptr);
		lineptr = tmp;
	}
	free(buf);
	if (rd < 0)
		return (free(lineptr), lineptr = NULL, NULL);
	return (lineptr);
}

char	*get_next_line(int fd)
{
	static char	*lineptr;
	char		*res;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(lineptr, '\n'))
		lineptr = read_until_br(fd, lineptr);
	if (!lineptr || !*lineptr)
		return (free(lineptr), lineptr = NULL, NULL);
	res = get_one_line(lineptr);
	if (!res)
		return (free(lineptr), lineptr = NULL, NULL);
	tmp = update_lineptr(lineptr);
	if (!tmp)
		return (free(lineptr), lineptr = NULL, res);
	free(lineptr);
	lineptr = tmp;
	return (res);
}
