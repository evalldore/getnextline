/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/05 20:43:31 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static char	*check_chunk(char	*chunk)
{
	size_t	i;

	i = 0;
	if (!chunk)
	{
		chunk = malloc(BUFFER_SIZE + 1);
		while (i <= BUFFER_SIZE)
			chunk[i++] = '\0';
	}
	return (chunk);
}

static void	read_file(t_fdstate *fdstate)
{
	char	*chunk;
	char	*new;
	ssize_t	bytes_read;

	bytes_read = 1;
	chunk = NULL;
	while (bytes_read > 0)
	{
		chunk = check_chunk(chunk);
		bytes_read = read(fdstate->fd, chunk, BUFFER_SIZE);
		chunk[bytes_read] = '\0';
		fdstate->bytes += bytes_read;
		new = ft_strjoin(fdstate->buff, chunk);
		free(fdstate->buff);
		fdstate->buff = new;
		if (ft_strchr(chunk, '\n'))
			break ;
	}
	free(chunk);
}

t_fdstate	*new_state(int fd)
{
	t_fdstate	*fdstate;

	fdstate = malloc(sizeof(t_fdstate));
	fdstate->fd = fd;
	fdstate->buff = malloc(sizeof(char));
	fdstate->buff[0] = '\0';
	fdstate->buff_pos = 0;
	fdstate->bytes = 0;
	return (fdstate);
}

char	*get_next_line(int fd)
{
	static t_fdstate	*fdstate;
	char				*target;
	char				*end;
	char				*line;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!fdstate)
		fdstate = new_state(fd);
	read_file(fdstate);
	target = &fdstate->buff[fdstate->buff_pos];
	if (!*target)
		return (NULL);
	end = ft_strchr(target, '\n');
	if (!end)
		end = ft_strchr(target, '\0');
	else
		end++;
	line = malloc(end - target);
	ft_strlcpy(line, target, (end - target) + 1);
	fdstate->buff_pos += (end - target);
	return (line);
}
