/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:18:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/14 21:13:34 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*res;
	char	*p;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*s && len--)
		*p++ = *s++;
	*p = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*p;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*p;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	p = res;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (res);
}
