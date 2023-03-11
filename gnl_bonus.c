/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:13:57 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/11 16:09:46 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"get_next_line.h"

void	readandfree(int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	if (line)
		free(line);
}

int	main(int argc, char	**argv)
{
	int		fd1;

	(void)argc;
	(void)argv;
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	fd1 = open("lines", O_RDONLY);
	readandfree(1000);
	readandfree(-1);
	close(fd1);
	readandfree(fd1);
	return (0);
}
