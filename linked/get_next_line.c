/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/09 18:08:20 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

static t_list	*new_node(int fd)
{
	t_list	*new;
	char	*content;
	ssize_t	bytes_read;

	content = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	bytes_read = read(fd, content, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(content);
		return (NULL);
	}
	content[bytes_read] = '\0';
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(content);
		return (NULL);
	}
	new->content = content;
	new->bytes = bytes_read;
	new->next = NULL;
	return (new);
}

static void	read_file(t_list **list, int fd)
{
	t_list	*new;
	t_list	*node;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		new = new_node(fd);
		if (!new)
			return ;
		if (!*list)
			*list = new;
		else
		{
			node = *list;
			while (node->next)
				node = node->next;
			node->next = new;
		}
		bytes_read = new->bytes;
		if (ft_strchr(new->content, '\n'))
			break ;
	}
}

static ssize_t	allocate_line(t_list *list, char	**line)
{
	ssize_t	list_len;

	list_len = ft_lstlen(list);
	if (list_len < 0)
		return (-1);
	*line = malloc(sizeof(char) * (list_len + 1));
	if (!*line)
		return (-1);
	(*line)[list_len] = '\0';
	return (list_len);
}

static char	*make_line(t_list	**list)
{
	t_list	*node;
	char	*line;
	char	*content;
	ssize_t	i;
	ssize_t	len;

	len = allocate_line(*list, &line);
	if (!line)
		return (NULL);
	i = 0;
	while (*list)
	{
		node = *list;
		content = node->content;
		while (*content && *content != '\n' && len--)
			line[i++] = *content++;
		if (*content == '\n')
		{
			line[i] = '\n';
			return (line);
		}
		free(node->content);
		*list = node->next;
		free(node);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	char			*content;
	char			*newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	read_file(&list, fd);
	if (list)
	{
		line = make_line(&list);
		newline = ft_strchr(list->content, '\n');
		content = list->content;
		if (newline++ && *newline)
			list->content = ft_substr(newline, 0, ft_strlen(newline));
		else
		{
			free(list);
			list = NULL;
		}
		free(content);
		return (line);
	}
	return (NULL);
}
