/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:38:06 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/19 16:46:49 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*update_lineptr(char *lineptr)
{
	char	*res;

	if (!(gnl_strchr(lineptr, '\n')))
		return (NULL);
	res = gnl_strdup(gnl_strchr(lineptr, '\n') + 1);
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

	if (!gnl_strchr(lineptr, '\n'))
		return (gnl_strdup(lineptr));
	res = gnl_strndup(lineptr, gnl_strchr(lineptr, '\n') - lineptr + 1);
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
	while (!gnl_strchr(lineptr, '\n') && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buf[rd] = '\0';
		tmp = gnl_strjoin(lineptr, buf);
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
	static char	*lineptr[OPEN_MAX];
	char		*res;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl_strchr(lineptr[fd], '\n'))
		lineptr[fd] = read_until_br(fd, lineptr[fd]);
	if (!lineptr[fd] || !*lineptr[fd])
		return (free(lineptr[fd]), lineptr[fd] = NULL, NULL);
	res = get_one_line(lineptr[fd]);
	if (!res)
		return (free(lineptr[fd]), lineptr[fd] = NULL, NULL);
	tmp = update_lineptr(lineptr[fd]);
	if (!tmp)
		return (free(lineptr[fd]), lineptr[fd] = NULL, res);
	free(lineptr[fd]);
	lineptr[fd] = tmp;
	return (res);
}
