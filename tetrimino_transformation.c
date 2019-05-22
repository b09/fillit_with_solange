/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrimino_transformation.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:45:34 by bprado         #+#    #+#                */
/*   Updated: 2019/05/21 18:03:42 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	hash_to_letter(char **ttrs)
{
	int		y;
	int		x;
	char	letter;

	y = 0;
	x = 0;
	letter = 'A';
	while (ttrs[y] != NULL)
	{
		if (ttrs[y][x] == '#')
			ttrs[y][x] = letter;
		x = (x < 20) ? (x + 1) : 0;
		y += (x == 0) ? 1 : 0;
		letter += (x == 0) ? 1 : 0;
	}
}

void	shorten_index(char **ttrs, int y, int x)
{
	int		y_low;
	int		x_low;

	while (ttrs[y] != NULL)
	{
		y_low = 1000;
		x_low = 1000;
		while (x < 9)
		{
			y_low = (ttrs[y][x] < y_low) ? ttrs[y][x] : y_low;
			x++;
			x_low = (ttrs[y][x] < x_low) ? ttrs[y][x] : x_low;
			x++;
		}
		x = 1;
		while (x < 9)
		{
			ttrs[y][x] -= y_low;
			x++;
			ttrs[y][x] -= x_low;
			x++;
		}
		++y;
	}
}

void	hash_coordinates(char **ttrs)
{
	int		y;
	int		x;
	int		z;
	char	buf[21];

	y = 0;
	while (ttrs[y] != NULL)
	{
		x = 0;
		ft_bzero(buf, 20);
		z = 0;
		while (ttrs[y][x] != 0 && z < 9)
		{
			if (ft_isa(ttrs[y][x]))
			{
				if (z == 0)
					buf[z++] = ttrs[y][x];
				buf[z++] = (x / 5) + 1;
				buf[z++] = (x % 5) + 1;
			}
			++x;
		}
		ft_strcpy(ttrs[y], buf);
		++y;
	}
}
