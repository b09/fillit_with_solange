/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:24:56 by bprado         #+#    #+#                */
/*   Updated: 2019/05/08 12:16:48 by svan-der      ########   odam.nl         */
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
		y = 0;
		while (y < size)
		{
			grid[x][y] = '.';
			++y;
			if (y == size)
				grid[x][y] = '\0';
		}
		++x;
	}
	return (grid);
}

int		ft_sqrt(int nb)
{
	int		i;

	i = 2;
	if (nb < 1)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i >= nb)
		return (i);
	else
		return (0);
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
