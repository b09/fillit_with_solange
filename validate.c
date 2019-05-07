/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprado <bprado@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:06:16 by bprado            #+#    #+#             */
/*   Updated: 2019/05/07 20:21:54 by bprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_lines(int lin, int chr, char **ary)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (chr > 2)
	{
		if ((*ary != 0) && (*ary)[y] == '#')
		{
			i += (((y < 3) && ((*ary)[y + 1] == '#'))) ? 1 : 0;
			i += (((y > 0) && ((*ary)[y - 1] == '#'))) ? 1 : 0;
			i += (((chr > 3) && ((*(ary + 1))[y] == '#'))) ? 1 : 0;
			i += ((chr < (4 * lin - 4)) && ((*(ary - 1))[y] == '#')) ? 1 : 0;
		}
		ary = (y == 3 || ft_strlen(*ary) < 4) ? (ary + 1) : ary;
		if ((chr % 20 == 0) && (i % 6) && (i % 8))
			return (0);
		y = ((y < 3) || (ft_strlen(*ary) < 4)) ? (y + 1) : 0;
		chr = (ft_strlen(*ary) < 4) ? (chr - 4) : (chr - 1);
	}
	change_to_letter((ary - lin + 1), lin, lin);
	return (1);
}

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
	if (((nline + 1) % 5) || !(check_lines(nline, (nline * 4) - 1, ary)) \
	|| get_next_line(openfd, &ary[nline]))
		return (0);
	close(openfd);
	if (!check_last_characters(argv))
		return (0);
	return (nline);
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

int		check_last_characters(char *argv)
{
	int		fd;
	char	buf[546];
	int		index;

	fd = open(argv, O_RDONLY);
	index = read(fd, buf, 546);
	close(fd);
	buf[index] = 0;
	if (index == 546)
		return (0);
	if (buf[index - 1] != '\n')
		return (0);
	if (buf[index - 2] != '.' && buf[index - 2] != '#')
		return (0);
	return (1);
}
