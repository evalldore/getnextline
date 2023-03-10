/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:01:43 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/09 23:28:09 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
	}
}
