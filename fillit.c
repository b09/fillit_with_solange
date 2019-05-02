/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:24:56 by bprado        #+#    #+#                 */
/*   Updated: 2019/04/25 14:25:01 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void	remove_excess_dots(char **ary, int low, int high)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		ary[0][high + 1] = 0;
		ft_memmove(&ary[0][0], &ary[0][low], ft_strlen(ary[0]));
		++ary;
		++count;
	}
}

int		lnchk(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str != 0)
	{
		if ((*str != '.') && (*str != '#'))
			return (-1);
		if (*str == '#')
			++cnt;
		++str;
	}
	if ((*str == 0) && (cnt == 0))
		ft_bzero((str - 4), 4);
	return (cnt);
}

void	remove_excess_dots_two(char **ary, int lines, int low, int high)
{
	int		i;

	while (lines > 0)
	{
		i = 0;
		while (i < 4)
		{
			if ((ary[-lines][i] != '.') && (ary[-lines][i] != 0))
			{
				low = (i < low) ? i : low;
				high = (i > high) ? i : high;
			}
			++i;
		}
		if (!(lines % 5))
		{
			remove_excess_dots(&ary[-(lines + 4)], low, high);
			low = 4;
			high = 0;
		}
		if (lines == 1)
			remove_excess_dots(&ary[-4], low, high);
		--lines;
	}
}

void	change_to_letter(char **ary, int lines, int lines2)
{
	int		index;
	char	letter;
	int		low;
	int		high;

	index = 0;
	letter = 'A';
	while (lines > 0)
	{
		if ((ary[0][(index % 4)]) == '#')
			ary[0][(index % 4)] = letter;
		++index;
		ary = (index % 4) ? ary : (ary + 1);
		lines = (index % 4) ? lines : (lines - 1);
		letter = (index % 20) ? letter : (letter + 1);
	}
	remove_excess_dots_two(ary, lines2, 4, 0);
}

int		check_tetriminoe(int lin, int chr, char **ary)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (chr > 4)
	{
		if ((*ary != 0) && (*ary)[y] == '#')
		{
			i = (((y < 3) && ((*ary)[y + 1] == '#'))) ? (i + 1) : i;
			i = (((y > 0) && ((*ary)[y - 1] == '#'))) ? (i + 1) : i;
			i = (((chr > 0) && ((*(ary + 1))[y] == '#'))) ? (i + 1) : i;
			i = ((chr < (4 * lin - 3)) && ((*(ary - 1))[y] == '#')) ? i + 1 : i;
		}
		ary = (y == 3 || ft_strlen(*ary) < 4) ? (ary + 1) : ary;
		if (((chr / 4) % 20 == 0) && (i != 6) && (i != 8))
			return (0);
		i = ((chr / 4) % 5 == 0) ? 0 : i;
		y = ((y < 3) || (ft_strlen(*ary) < 4)) ? (y + 1) : 0;
		chr = (ft_strlen(*ary) < 4) ? (chr - 4) : (chr - 1);
	}
	change_to_letter((ary - lin + 1), lin, lin);
	return (1);
}

int		gnl_fillit(char *argv, char **ary)
{
	int			openfd;
	int			nline;
	int			chars;

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
	if (((nline + 1) % 5) || !(check_tetriminoe(nline, (nline * 4), ary)) || \
		get_next_line(openfd, &ary[nline]))
		return (0);
	close(openfd);
	return (nline);
}








////************************************************ check all functions above line




char	**create_grid(char **grid, int size)
{
	int		x;
	int		y;

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

int		check_tetrimino(char **ttrs, char **grid, int gsize, int gindx)
{
	int		x;
	int		y;
	int		lettercheck;

	x = 0;
	lettercheck = 0;
	if ((gindx + 1) == (gsize * gsize))
		return (-1);
	while (x < 4)
	{
		y = 0;
		while (((((gindx / gsize) + x) < gsize) && (((gindx % gsize) \
		+ y) < gsize)) && ((grid[((gindx / gsize) + x)][((gindx % \
		gsize) + y)] == '.') || (ft_isalpha(grid[((gindx / gsize) + x)]\
		[((gindx % gsize) + y)]) && (ttrs[x][y] == '.' ))) && (ttrs[x][y] != 0))
		{
			lettercheck += (ft_isalpha(ttrs[x][y])) ? 1 : 0;
			++y;
			if (((gindx % gsize) + y) >= gsize)
				break ;
		}
		if ((x == 3 && lettercheck != 4) || (((gindx % gsize) + y) == gsize \
		&& ft_isalpha(ttrs[x][y - 1]) && grid[((gindx / gsize) + x)][((gindx \
		% gsize) + y) - 1] != '.'))
			return (0);
		++x;
	}
	return (add_to_grid(ttrs, grid, gindx / gsize, gindx % gsize));
}

int		pop_ttr(char **grid, char **ttrs, int gridsize, int check)
{
	char	letter;
	int		x;
	int		y;

	x = 0;
	y = 1000;
	while (ttrs[x][0] == 0)
		++x;
	if (ft_isalpha(ttrs[x][0]))
	{
		letter = ttrs[x][0];
		if (check)
			return (letter);
		x = 0;
		while ((x + 1) <= (gridsize * gridsize))
		{
			if (grid[x / gridsize][x % gridsize] == letter)
			{
				grid[x / gridsize][x % gridsize] = '.';
				y = (x < y) ? x : y;
			}
			++x;
		}
	}
	return (y);
}

int		check_entire_list(char **ttrs, char **grid, int lines, int gindx)
{
	int		ret;
	int		gsize;

	gsize = ft_strlen(grid[0]);
	if (lines < 1)
		return (1);
	if ((pop_ttr(grid, ttrs, gsize, 1) == 'A') && (gindx >= gsize * gsize))
		return (0);
	while (lines > 1 && (gindx < gsize * gsize))
	{
		ret = check_tetrimino(ttrs, grid, gsize, gindx);
		ttrs += (ret == 1) ? 5 : 0;
		lines -= (ret == 1) ? 5 : 0;
		gindx = (ret == 1) ? 0 : gindx;
		gindx += (ret == 0) ? 1 : 0;
		if (ret == -1)
		{
			ttrs -= 5;
			lines += 5;
			gindx = 1 + pop_ttr(grid, ttrs, gsize, 0);
		}
	}
	return(check_entire_list(ttrs, grid, lines, gindx));
}

int		ft_sqrt(int nb)
{
	int i;

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
	int 	x;

	x = 0;
	while (x < size)
	{
		free(grid[x]);
		++x;
	}
}

int		main(int argc, char *argv[])
{
	char		*ary[130];
	int			lines = gnl_fillit(argv[1], ary);
	int			i = 0;
	char		**grid;
	int			lines2 = lines;
	int			size;

	if (lines > 0)
	{
		size = 4 * (lines / 5) + 1;
		size = ft_sqrt(size);
		grid = create_grid(grid, size);
		i = 0;
		while (i < size)
			printf("----i: %d, String: %s\n", i, grid[i++]);
		while (check_entire_list(ary, grid, lines2, 0) == 0)
		{
			delete_grid(grid, size);
			++size;
			grid = create_grid(grid, size);
		}
		i = 0;
		while (i < size)
			printf("----i: %d, String: %s\n", i, grid[i++]);
	}
	if (lines <= 0)
	{
		printf("error\n");
		return (0);
	}
	printf("lines outout: %d\n", lines);
	while (lines--)
		printf("----Return: %d, String: %s\n", lines, ary[i++]);
	return (0);
}
