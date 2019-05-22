/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:47:02 by bprado         #+#    #+#                */
/*   Updated: 2019/05/21 17:58:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_grid(char **grid, int size)
{
	int		i;

	i = size;
	while (i)
		ft_strdel(&grid[i--]);
	ft_strdel(grid);
}

char	**create_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	grid = (char **)malloc(sizeof(char*) * size + 1);
	while (i < size)
		grid[i++] = (char*)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			++j;
		}
		grid[i][j] = 0;
		++i;
	}
	grid[i] = NULL;
	return (grid);
}
