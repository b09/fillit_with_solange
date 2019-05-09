/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:06:47 by bprado         #+#    #+#                */
/*   Updated: 2019/05/09 01:57:14 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char		*ary[130];
	int			lines;
	char		**grid;
	int			size;
	// int			i;

	// printf("yo\n");
	lines = gnl_fillit(argv[1], ary);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	if (lines <= 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	size = 2;
	grid = create_grid(size);
	// i = 0;
	// while (i < lines)
	// 	printf("%s\n", ary[i++]);
	while (check_entire_list(ary, grid, lines, 0) == 0)
	{
		delete_grid(grid, size);
		++size;
		grid = create_grid(size);
	}
	print_grid(grid, size);
	delete_grid(grid, size);
	return (0);
}
