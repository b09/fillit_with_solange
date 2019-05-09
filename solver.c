/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:06:26 by bprado         #+#    #+#                */
/*   Updated: 2019/05/09 02:03:23 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_ttr(char **ttrs, char **grid, int gs, int gi)
{
	int		x;
	int		y;
	int		lttrs;

	x = 0;
	lttrs = 0;
	if (gi >= (gs * gs))
		return (-1);
	while (x < 4 && x < gs)
	{
		printf("x: %d yo\n", x);
		y = 0;
		printf("char: %c, string: %s\n", grid[(gi / gs) + x][(gi % gs) + y], grid[(gi / gs) + x]);
		while (((((gi / gs) + x) < gs) && (((gi % gs) + y) < gs)) && ((grid[\
		((gi / gs) + x)][((gi % gs) + y)] == '.') || (ft_isalpha(grid[((gi / \
		gs) + x)][((gi % gs) + y)]) && (ttrs[x][y] == '.'))) && ttrs[x][y] != 0)
		{
			lttrs += (ft_isalpha(ttrs[x][y])) ? 1 : 0;
			++y;
		}
		if ((x == 3 && lttrs != 4) || (x + 1 == gs && lttrs != 4) || (((gi % gs) + y == gs) && ft_isalpha(\
		ttrs[x][y])) || (ft_isalpha(grid[((gi / gs) + x)][((gi % gs) + y)])))// && ft_isalpha(ttrs[x][y])))
			return (0);
		++x;
	}
	// int i = 0;
	// while (i < gs)
	// 	printf("%s\n", grid[i++]);
	// printf("\n");
	return (add_to_grid(ttrs, grid, gi / gs, gi % gs));
}

int		check_entire_list(char **ttrs, char **grid, int lines, int gi)
{
	int		ret;
	int		gs;

	gs = ft_strlen(grid[0]);
	// lines should be zero
	while ((lines > 0) && (gi < (gs * gs)))
	{
		ret = check_ttr(ttrs, grid, gs, gi);
		if ((pop_ttr(grid, ttrs, gs, 1) == 'A') && ((gi + 1) >= gs * gs))
			return (0);
		ttrs += (ret == 1) ? 5 : 0;
		lines -= (ret == 1) ? 5 : 0;
		gi = (ret == 1) ? 0 : gi;
		gi += (ret == 0) ? 1 : 0;
		if (ret == -1)
		{
			ttrs -= 5;
			lines += 5;
			gi = 1 + pop_ttr(grid, ttrs, gs, 0);
		}
	}
	// printf("lines: %d, gi: %d\n", lines, gi);
	if ((lines > 0) && (gi == (gs * gs)))
		return (0);
	return (1);
}

int		pop_ttr(char **grid, char **ttrs, int gridsize, int check)
{
	char	letter;
	int		x;
	int		y;

	x = 0;
	while (ttrs[x][0] == 0 || ttrs[x][0] == '.')
		++x;
	letter = ttrs[x][0];
	if (check)
		return (letter);
	y = 1000;
	x = 0;
	while ((x + 1) <= (gridsize * gridsize))
	{
		if (grid[x / gridsize][x % gridsize] == letter)
		{
			grid[x / gridsize][x % gridsize] = '.';
			y = (x < y) ? x : y;
			if ((x % gridsize) < (y % gridsize))
				y = y - ((y % gridsize) - (x % gridsize));
		}
		++x;
	}
	return (y);
}

int		add_to_grid(char **ttrs, char **grid, int gx, int gy)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	while (x < 4 && z < 4)
	{
		while (!ft_strlen(*ttrs))
			++ttrs;
		if (ft_isalpha(ttrs[x][y]))
		{
			grid[gx + x][gy + y] = ttrs[x][y];
			++z;
		}
		++y;
		if (ttrs[x][y] == 0)
		{
			y = 0;
			x++;
		}
	}
	return (1);
}
