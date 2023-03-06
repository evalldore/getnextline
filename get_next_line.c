/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/06 05:41:26 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static char	*make_chunk(void)
{
	size_t	i;
	char	*chunk;

	i = 0;
	chunk = malloc(BUFFER_SIZE + 1);
	while (i <= BUFFER_SIZE)
		chunk[i++] = '\0';
	return (chunk);
}

static ssize_t	read_file(t_fdstate *fdstate)
{
	char	*chunk;
	char	*new;
	ssize_t	bytes_read;

	bytes_read = 1;
	chunk = make_chunk();
	while (bytes_read > 0)
	{
		bytes_read = read(fdstate->fd, chunk, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		chunk[bytes_read] = '\0';
		new = ft_strjoin(fdstate->buff, chunk);
		free(fdstate->buff);
		fdstate->buff = new;
		if (ft_strchr(chunk, '\n'))
			break ;
	}
	free(chunk);
	return (bytes_read);
}

t_fdstate	*new_state(int fd)
{
	t_fdstate	*fdstate;

	fdstate = malloc(sizeof(t_fdstate));
	fdstate->fd = fd;
	fdstate->buff = malloc(sizeof(char));
	fdstate->buff[0] = '\0';
	fdstate->buff_pos = 0;
	return (fdstate);
}

char	*make_line(t_fdstate *fdstate, char	*target)
{
	char	*end;
	char	*line;

	if (!*target)
		return (NULL);
	end = ft_strchr(target, '\n');
	if (!end)
		end = ft_strchr(target, '\0');
	else
		end++;
	line = malloc((end - target) + 1);
	ft_strlcpy(line, target, (end - target) + 1);
	fdstate->buff_pos += (end - target);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdstate	*fdstate;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!fdstate)
		fdstate = new_state(fd);
	if (read_file(fdstate) >= 0)
	{
		line = make_line(fdstate, &fdstate->buff[fdstate->buff_pos]);
		if (line)
			return (line);
	}
	free(fdstate->buff);
	free(fdstate);
	fdstate = NULL;
	return (NULL);
}
