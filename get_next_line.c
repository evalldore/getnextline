/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/03 05:16:35 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static char	*cpy_buff(const char *buff)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = malloc(sizeof(char) * BUFFER_SIZE);
	while (i < BUFFER_SIZE)
	{
		dest[i] = buff[i];
		i++;
	}
	return (dest);
}

static void	read_line(t_list **lst, int fd)
{
	t_list	*temp;
	t_list	*new;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buff, BUFFER_SIZE))
	{
		new = malloc(sizeof(t_list));
		new->content = cpy_buff(buff);
		new->next = NULL;
		if (!*lst)
			*lst = new;
		else
		{
			if (!temp)
				temp = *lst;
			temp->next = new;
		}
		temp = new;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
}

static size_t	list_len(t_list *lst)
{
	size_t	len;
	char	*buff;

	len = 0;
	while (lst)
	{
		buff = lst->content;
		while (*buff++)
			len++;
		lst = lst->next;
	}
	return (len);
}

static char	*make_line(t_list **lst)
{
	size_t	i;
	t_list	*temp;
	char	*buff;
	char	*line;

	line = malloc(sizeof(char) * list_len(*lst));
	temp = *lst;
	i = 0;
	while (temp)
	{
		buff = temp->content;
		while (*buff)
		{
			line[i] = *buff++;
			i++;
		}
		temp = temp->next;
	}
	*lst = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;

	read_line(&lst, fd);
	return (make_line(&lst));
}
