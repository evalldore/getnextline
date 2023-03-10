/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:06:28 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/09 16:45:05 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - 1))
			*dst++ = src[i++];
		*dst = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}

ssize_t	ft_lstlen(t_list	*list)
{
	char	*end;
	ssize_t	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		end = ft_strchr(list->content, '\n');
		if (!end)
			end = ft_strchr(list->content, '\0');
		else
			end++;
		len += (end - list->content);
		list = list->next;
	}
	return (len);
}