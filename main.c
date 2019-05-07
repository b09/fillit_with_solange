/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprado <bprado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:06:47 by bprado            #+#    #+#             */
/*   Updated: 2019/05/07 20:06:52 by bprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char		*ary[130];
	int			lines;
	int			i;
	char		**grid;
	int			size;

	lines = gnl_fillit(argv[1], ary);
    if (argc != 2)
		ft_putstr("usage: ./fillit input_file\n");
	if (lines <= 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	size = 4 * (lines / 5) + 1;
	size = ft_sqrt(size);
	grid = create_grid(size + 2);
	// i = 0;
	// while (i < size)
	// 	printf("----i: %d, String: %s\n", i, grid[i++]);
	while (check_entire_list(ary, grid, lines, 0) == 0)
	{
		delete_grid(grid, size);
		++size;
		grid = create_grid(size);
	}
	i = 0;
	while (i < size)
    {
		printf("----i: %d, String: %s\n", i, grid[i]);
        i++;
    }
	printf("lines outout: %d\n", lines);
	i = 0;
	while (lines--)
    {
		printf("----Return: %d, String: %s\n", lines, ary[i]);
		i++;
	}
	return (0);
}
