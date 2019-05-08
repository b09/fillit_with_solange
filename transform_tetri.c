/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_tetri.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:06:26 by bprado         #+#    #+#                */
/*   Updated: 2019/05/08 18:12:56 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_to_letter(char **ary, int lines, int lines2)
{
	int		index;
	char	letter;

	index = 0;
	letter = 'A';
	while (lines > 1)
	{
		if ((ary[0][(index % 4)]) == '#')
			ary[0][(index % 4)] = letter;
		index += (ft_strlen(*ary)) ? 1 : 4;
		ary = (index % 4) ? ary : (ary + 1);
		lines = (index % 4) ? lines : (lines - 1);
		letter = (index % 20) ? letter : (letter + 1);
	}
	remove_excess_dots_two(ary, lines2 - 1, 4, 0);
}

void	remove_excess_dots_two(char **ary, int lines, int low, int high)
{
	int		i;

	while (lines > 0)
	{
		i = 0;
		while (i < 4)
		{
			if ((ary[-lines][i] != 0) && (ary[-lines][i] != '.'))
			{
				low = (i < low) ? i : low;
				high = (i > high) ? i : high;
			}
			++i;
		}
		if (!(lines % 5))
		{
			remove_excess_dots(&ary[-(lines + 3)], low, high);
			low = 4;
			high = 0;
		}
		if (lines == 1)
			remove_excess_dots(&ary[-4], low, high);
		--lines;
	}
}

void	remove_excess_dots(char **ary, int low, int high)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		if (ft_strlen(*ary))
		{
			ary[0][high + 1] = 0;
			ft_memmove(&ary[0][0], &ary[0][low], ft_strlen(ary[0]));
		}
		++ary;
		++count;
	}
}
