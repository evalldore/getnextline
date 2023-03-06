/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:01:43 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/06 05:28:25 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	//int		ln;
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	//ln = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > -1)
		{

			printf("%s", get_next_line(fd));
			printf("%s", get_next_line(fd));
			if (BUFFER_SIZE > 100) {
				char *temp;
				do {
					temp = get_next_line(fd);
					free(temp);
				} while (temp != NULL);
			}
			printf("%s", get_next_line(fd));
		}
			/*printf("line(%d) : %s", ln++, get_next_line(fd));
			printf("line(%d) : %s", ln++, get_next_line(fd));
			printf("line(%d) : %s", ln++, get_next_line(fd));
			printf("line(%d) : %s", ln++, get_next_line(fd));
			printf("line(%d) : %s", ln++, get_next_line(fd));
			printf("\n");*/
			//printf("line(%d) : %s", ln++, get_next_line(fd));
			//printf("line(%d) : %s", ln++, get_next_line(fd));
	}
	return (0);
}
