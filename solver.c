/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:06:26 by bprado         #+#    #+#                */
/*   Updated: 2019/05/10 01:33:41 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

		// printf("check_ttr after while, letters: %d, y: %d\n\n", lttrs, y);//, grid[((gi / gs) + x)][((gi % gs) + y)]);
		// printf("x: %d  gi: %d  gs: %d  gi/gs+x: %d  gi%%gs+y: %d  letters: %d\n", x, gi, gs, (gi / gs) + x, (gi % gs) + y, lttrs);
		// printf("char: %c, string: %s\n", grid[(gi / gs) + x][(gi % gs) + y], grid[(gi / gs) + x]);
	// printf("check_ttr\n");


// int		check_helper()
// {

// }

// int		check_ttr(char **ttrs, char **grid, int gs, int gi)
// {
// 	int		x;
// 	int		y;
// 	int		lttrs;

// 	x = 0;
// 	lttrs = 0;
// 	if (gi >= (gs * gs))
// 		return (-1);
// 	while (x < 5 && lttrs < 4)
// 	{

	// 	if ((lttrs != 4 && (x == 4 || (gi / gs) + x >= gs)) || (x > 0 && ft_isa(ttrs[x - 1][y]) && ((gi % gs) + y == gs || ft_isa(grid[(gx + x - 1)][(gy + y)]))))
	// 	if
	// 		lttrs != 4
	// 			x == 4		// Last possible line of ttrs

	// 			gx + x >= gs //exceed max size on line

	// 		x > 0 
	// 			gy + y == gs // not on first line and at max char index
	// 				ft_isa(ttrs[x - 1][y]) // the tetris still has content

	// 			ft_isa(grid[(gx + x - 1)][(gy + y)] 
	// 				ft_isa(ttrs[x - 1][y])

	// 		return (0);

	// 	y = 0;
	// 	while (ttrs[x][y] != 0 && ((gi % gs) + y) < gs && (grid[((gi / gs) + x)][((gi % gs) + y)] == '.' || (ft_isa(grid[((gi / gs) + x - 1)][((gi % gs) + y)]) && !ft_isa(ttrs[x][y]))))
	// 	while 
	// 		gx + x < gsize		// within lines of grid   BUT SHOULD BE PROTECTED BY IF STATEMENT ABOVE
	// 			ttrs[x][y] != 0		// ttrs has content
	// 				gy + y < gsize 		// whithin chars of grid

	// 					grid[(gx + x)][(gy + y)] == '.'		// grid has dot
						
	// 					ft_isa(grid[(gx + x)][(gy + y)]	// grid has letter
	// 						ttrs[x][y] == '.'				// but the the checked ttr has a dot
	// 	{
	// 		lttrs += (ft_isa(ttrs[x][y])) ? 1 : 0;
	// 		++y;
	// 	}
	// 	++x;
	// }
// int		check_ttr(char **ttrs, char **grid, int gs, int gi)
// {
// 	int		x;
// 	int		y;
// 	int		lttrs;

// 	x = 0;
// 	lttrs = 0;
// 	if (gi >= (gs * gs))
// 		return (-1);
// 	while (x < 5 && lttrs < 4)
// 	{
// 		if ((x == 4 && lttrs != 4) || ((gi / gs) + x >= gs && lttrs != 4) || (x > 0 && ((gi % gs) + y == gs) && ft_isa(\
// 		ttrs[x - 1][y])) || (x > 0 && ft_isa(grid[((gi / gs) + x - 1)][((gi % gs) + y)]) && ft_isa(ttrs[x - 1][y])))
// 			return (0);
// 		y = 0;
// 		while (((((gi / gs) + x) < gs) && (((gi % gs) + y) < gs)) && ((grid[\
// 		((gi / gs) + x)][((gi % gs) + y)] == '.') || (ft_isa(grid[((gi / \
// 		gs) + x)][((gi % gs) + y)]) && (ttrs[x][y] == '.'))) && ttrs[x][y] != 0)
// 		{
// 			lttrs += (ft_isa(ttrs[x][y])) ? 1 : 0;
// 			++y;
// 		}
// 		++x;
// 	}
// 	// int i = 0;
// 	// while (i < gs)
// 	// 	printf("%s\n", grid[i++]);
// 	// printf("gi: %d\n", gi);
// 	return (add_to_grid(ttrs, grid, gi / gs, gi % gs));
// }

int		check_ttr(char **ttrs, char **grid, int gs, int gi)
{
	int		x;
	int		y;
	int		lttrs;

	x = 0;
	lttrs = 0;
	if (gi >= (gs * gs))
		return (-1);
	while (x < 5 && lttrs < 4)
	{
		while (!(ft_strlen(*ttrs)) && x == 0) // this is a possible solution to increase lines : works with test called 'valid_3'
			++ttrs;
		// printf("    ttrs[x]: %d gi: %d  ttrs: %s\n", x, gi, ttrs[x]);
		if ((lttrs != 4 && (x == 4 || (gi / gs) + x >= gs)) || (x > 0 && ft_isa\
		(ttrs[x - 1][y]) && ((gi % gs) + y == gs || ft_isa(grid[(gi / gs) + x - 1][(gi % gs) + y]))))
			return (0);
		y = 0;
		while (ttrs[x][y] != 0 && ((gi % gs) + y) < gs && (grid[((gi / gs) + x)]\
		[((gi % gs) + y)] == '.' || (ft_isa(grid[(gi / gs) + x][(gi % gs)\
		+ y]) && !ft_isa(ttrs[x][y]))))
		{
			lttrs += (ft_isa(ttrs[x][y])) ? 1 : 0;
			// printf("gs: %d y: %d gi: %d letters: %d\n\n", gs, y, gi, lttrs);
			++y;
		}
		++x;
	}
	// int i = 0;
	// while (i < gs)
	// 	printf("%s\n", grid[i++]);
	return ((lttrs == 4) ? add_to_grid(ttrs, grid, gi / gs, gi % gs) : 0);
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
		// printf("%s\n\n", grid[gx]);
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
		if (ft_isa(ttrs[x][y]))
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
