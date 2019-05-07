/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:24:56 by bprado         #+#    #+#                */
/*   Updated: 2019/05/07 19:05:08 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		gnl_fillit(char *argv, char **ary)
{
	int		openfd;
	int		nline;
	int		chars;

	nline = 0;
	openfd = open(argv, O_RDONLY);
	while (openfd != -1 && get_next_line(openfd, &ary[nline]) && nline < 130)
	{
		if (((ft_strlen(ary[nline]) != 4) && ((nline + 1) % 5)) || \
			((ft_strlen(ary[nline]) != 0) && ((nline + 1) % 5) == 0) || \
			((lnchk(ary[nline]) < 0) && ((nline + 1) % 5)))
			return (0);
		chars += lnchk(ary[nline]);
		if ((((nline + 1) % 5) == 0) && (chars != 4))
			return (0);
		chars = (((nline + 1) % 5) == 0) ? 0 : chars;
		++nline;
	}
	if (((nline + 1) % 5) || !(check_tetriminoe(nline, (nline * 4) - 1, ary)) \
	|| get_next_line(openfd, &ary[nline]))
		return (0);
	close(openfd);
	if (!check_last_characters(argv))
		return (0);
	return (nline);
}

char	**create_grid(int size)
{
	int		x;
	int		y;
	char 	**grid;

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

int		add_to_grid(char **ttrs, char **grid, int gx, int gy)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		if (ft_isalpha(ttrs[x][y]))
			grid[gx + x][gy + y] = ttrs[x][y];
		++y;
		if (ttrs[x][y] == 0)
		{
			y = 0;
			x++;
		}
	}
	return (1);
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
