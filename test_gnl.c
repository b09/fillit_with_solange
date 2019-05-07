/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_gnl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 17:05:49 by bprado        #+#    #+#                 */
/*   Updated: 2019/05/05 18:22:54 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		main(int argc, char *argv[])
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("line is: %s\n", line);
	}
//	printf("line is: %s\n", line);
	
	return (0);
}
