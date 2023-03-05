/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/05 12:56:41 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static void	read_file(t_fdstate *fdstate, int fd)
{
	char	chunk[BUFFER_SIZE + 1];
	char	*new;
	size_t	i;

	i = 0;
	while (i < (BUFFER_SIZE + 1))
		chunk[i++] = '\0';
	while (read(fd, chunk, BUFFER_SIZE) > 0)
	{
		new = ft_strjoin(fdstate->buff, chunk);
		free(fdstate->buff);
		fdstate->buff = new;
		if (ft_strchr(chunk, '\n'))
			break ;
	}
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

char	*get_next_line(int fd)
{
	static t_fdstate	*fdstate;
	char				*target;
	char				*end;

	if (!fdstate)
		fdstate = new_state(fd);
	read_file(fdstate, fd);
	target = &fdstate->buff[fdstate->buff_pos];
	end = ft_strchr(target, '\n');
	if (!end)
		end = ft_strchr(target, '\0');
	else
		end++;
	if (fdstate->line)
		free(fdstate->line);
	fdstate->line = malloc(end - target);
	ft_strlcpy(fdstate->line, target, (end - target) + 1);
	fdstate->buff_pos += (end - target);
	return (fdstate->line);
}
