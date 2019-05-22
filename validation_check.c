/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_check.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:43:17 by bprado         #+#    #+#                */
/*   Updated: 2019/05/21 18:06:14 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_ttr(char **ttrs)
{
	int y;
	int x;
	int nbr;

	y = 0;
	x = 0;
	nbr = 0;
	while (ttrs[y] != NULL && ttrs[y][x] != 0)
	{
		if (ttrs[y][x] == '#')
		{
			nbr += (x > 0 && ttrs[y][x - 1] == '#') ? 1 : 0;
			nbr += (x < 20 && ttrs[y][x + 1] == '#') ? 1 : 0;
			nbr += (x < 15 && ttrs[y][x + 5] == '#') ? 1 : 0;
			nbr += (x > 4 && ttrs[y][x - 5] == '#') ? 1 : 0;
		}
		x = (x < 20) ? (x + 1) : 0;
		y += (x == 0) ? 1 : 0;
		if (x == 0 && nbr != 6 && nbr != 8)
			return (0);
		nbr = (x == 0) ? 0 : nbr;
	}
	return (1);
}

int		newline_chk(char **ttrs)
{
	int y;
	int x;
	int nwl;

	y = 0;
	while (ttrs[y] != NULL)
	{
		x = 0;
		nwl = 0;
		while (ttrs[y][x] != 0)
		{
			nwl += ttrs[y][x] == '\n' ? 1 : 0;
			x++;
			if ((ttrs[y][x - 1] != '\n') && (x % 5 == 0 || x % 21 == 0))
				return (0);
		}
		if (nwl != 5)
		{
			if (nwl == 4 && ttrs[y + 1] == NULL)
				break ;
			return (0);
		}
		y++;
	}
	return (1);
}

int		char_chk(char **ttrs)
{
	int		y;
	int		x;
	char	*str;

	str = ".#\n";
	y = 0;
	x = 0;
	while (ttrs[y] != NULL)
	{
		x = 0;
		while (ttrs[y][x] != 0)
		{
			if (!ft_strchr(str, ttrs[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	populate_buff(char *buff, char **ttr)
{
	*ttr = ft_strnew(21);
	ft_strcpy(*ttr, buff);
}

int		read_file(char *argv[], char **ttrs)
{
	int		fd;
	char	buff[22];
	int		ret;
	int		i;

	i = 0;
	ft_bzero(buff, 22);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buff, 21);
	while ((ret == 21) && (i < 27))
	{
		populate_buff(buff, &ttrs[i]);
		ret = read(fd, buff, 21);
		i++;
	}
	if (i == 27 || ret != 20)
	{
		ttrs[i++] = NULL;
		return (-i);
	}
	if (ret == 20)
		populate_buff(buff, &ttrs[i]);
	ttrs[++i] = NULL;
	close(fd);
	return (i);
}
