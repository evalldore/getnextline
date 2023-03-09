/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:01:43 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/09 03:44:40 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > -1)
		{
			printf("file descriptor: %d\n", fd);
			printf("%s", get_next_line(fd));
			//printf("%s", get_next_line(fd));
		}
	}
}
