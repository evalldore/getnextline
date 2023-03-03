/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:54:45 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/02 21:27:11 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	t_list	*lst;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, buff, BUFFER_SIZE))
	{
		if ()
		//ft_lstadd_front(&lst, ft_lstnew(buff));
	}
}

char	*get_next_line(int fd)
{
	t_list	*lst;
	char	*buff;

	lst = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	while (read(fd, buff, BUFFER_SIZE))
	{
		if ()
		//ft_lstadd_front(&lst, ft_lstnew(buff));
	}
}
