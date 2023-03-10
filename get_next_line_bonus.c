/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/09 23:28:57 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line_bonus.h"

static char	*make_chunk(void)
{
	size_t	i;
	char	*chunk;

	i = 0;
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chunk)
		return (NULL);
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
	if (!chunk)
		return (-1);
	while (bytes_read > 0 && !ft_strchr(chunk, '\n'))
	{
		bytes_read = read(fdstate->fd, chunk, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		chunk[bytes_read] = '\0';
		new = ft_strjoin(fdstate->buff, chunk);
		if (!new)
		{
			bytes_read = -1;
			break ;
		}
		free(fdstate->buff);
		fdstate->buff = new;
	}
	free(chunk);
	return (bytes_read);
}

t_fdstate	*new_state(int fd)
{
	t_fdstate	*fdstate;

	fdstate = malloc(sizeof(t_fdstate));
	if (fdstate)
	{
		fdstate->fd = fd;
		fdstate->buff = malloc(sizeof(char));
		if (!fdstate->buff)
		{
			free(fdstate);
			return (NULL);
		}
		fdstate->buff[0] = '\0';
		fdstate->buff_pos = 0;
	}
	return (fdstate);
}

char	*make_line(t_fdstate *fdstate)
{
	char	*end;
	char	*line;
	char	*target;

	target = &fdstate->buff[fdstate->buff_pos];
	if (!*target)
		return (NULL);
	end = ft_strchr(target, '\n');
	if (!end)
		end = ft_strchr(target, '\0');
	else
		end++;
	line = malloc((end - target) + 1);
	if (line)
	{
		ft_strlcpy(line, target, (end - target) + 1);
		fdstate->buff_pos += (end - target);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdstate	*states[MAX_OPEN];
	t_fdstate			*fdstate;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fdstate = states[fd];
	if (!fdstate)
	{
		fdstate = new_state(fd);
		states[fd] = fdstate;
	}	
	if (fdstate)
	{
		if (read_file(fdstate) >= 0)
		{
			line = make_line(fdstate);
			if (line)
				return (line);
		}
		free(fdstate->buff);
		free(fdstate);
		states[fd] = NULL;
	}
	return (NULL);
}
