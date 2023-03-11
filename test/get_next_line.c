/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/10 21:18:40 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static int	append_to_line(char	**line, char	*buffer)
{
	char	*temp;
	size_t	line_len;
	size_t	buffer_len;
	char	*buffer_end;

	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(*line);
	if (buffer_len <= 0)
		return (0);
	buffer_end = ft_strchr(buffer, '\n');
	if (!buffer_end)
		buffer_end = ft_strchr(buffer, '\0');
	temp = *line;
	*line = malloc(line_len + (buffer_end - buffer) + 1);
	if (!line)
		return (0);
	ft_strlcpy(*line, temp, line_len + 1);
	ft_strlcat(*line, buffer, line_len + (buffer_end - buffer) + 1);
	ft_strlcpy(buffer, buffer_end, ft_strlen(buffer_end) + 1);
	free(temp);
	if (*buffer_end)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && !append_to_line(&line, buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
	}
	return (line);
}
