/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:24:56 by bprado         #+#    #+#                */
/*   Updated: 2019/05/09 01:57:09 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_grid(int size)
{
	int		x;
	int		y;
	char	**grid;

	x = 0;
	y = 0;
	grid = (char**)malloc(sizeof(char*) * size);
	while (x < size)
	{
		grid[x] = (char*)malloc(size + 1);
		grid[x][size] = '\0';
		y = 0;
		while (y < size)
		{
			grid[x][y] = '.';
			++y;
		}
		++x;
	}
	return (grid);
}

void	delete_grid(char **grid, int size)
{
	int		x;

	x = 0;
	while (x < size)
	{
		free(grid[x]);
		++x;
	}
	free(grid);
}

void	print_grid(char **grid, int size)
{
	int		y;

	y = 0;
	while (y < size)
	{
		ft_putstr(grid[y]);
		ft_putstr("\n");
		y++;
	}
}