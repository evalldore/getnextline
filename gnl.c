/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:13:57 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/11 04:39:19 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"get_next_line.h"

int	main(int argc, char	**argv)
{
	char	*line;
	int		fd1;

	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	if (argc != 2)
		return (0);
	fd1 = open(argv[1], O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	return (0);
}
