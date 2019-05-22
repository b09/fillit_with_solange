/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:35:04 by bprado         #+#    #+#                */
/*   Updated: 2019/05/21 18:04:11 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(char **map, char **ttrs, int index)
{
	int		x;
	int		y;
	int		size;

	size = ft_strlen(map[0]);
	if (ttrs[index] == NULL)
		return (1);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_tetriminoe(map, x, y, ttrs[index]))
			{
				add_tetriminoe(map, x, y, ttrs[index]);
				if (solve_map(map, ttrs, index + 1))
					return (1);
				remove_ttr(map, ttrs[index][0]);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	remove_ttr(char **map, char letter)
{
	int		size;
	int		x;
	int		y;

	size = ft_strlen(map[0]);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			++x;
		}
		++y;
	}
}

int		add_tetriminoe(char **map, int x_map, int y_map, char *ttr)
{
	int		i;
	char	letter;

	letter = ttr[0];
	i = 1;
	while (i < 9)
	{
		map[y_map + ttr[i]][x_map + ttr[i + 1]] = letter;
		i += 2;
	}
	return (1);
}

int		check_tetriminoe(char **map, int x_map, int y_map, char *ttr)
{
	int		i;
	int		size;

	i = 1;
	size = ft_strlen(map[0]);
	while (i < 9 && size > (y_map + ttr[i]) && size > (x_map + ttr[i + 1]))
	{
		if (map[y_map + ttr[i]][x_map + ttr[i + 1]] == '.')
			i += 2;
		else
			return (0);
	}
	if (i == 9)
		return (1);
	return (0);
}

void	free_ttr(char **ttrs)
{
	int		i;

	i = 0;
	while (ttrs[i] != NULL)
	{
		ft_strdel(&ttrs[i]);
		++i;
	}
}
