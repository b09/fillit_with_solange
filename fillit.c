/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:35:04 by bprado         #+#    #+#                */
/*   Updated: 2019/05/17 00:22:22 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int		solve_map(char **map, char **ttrs, int index) 
// {
// 	int x;
// 	int y;
	
// 	i = 0;
// 	if (ttr[0] == NULL)
// 		return (1);
// 	y = 0;
// 	while (y < size)
// 	{
// 		x = 0;
// 		while (x < size)
// 		{
// 			//starts from right column and row to add each ttr
// 			if (check_tetriminoe(map, x, y, ttrs[index]))
// 			{
// 				add_tetriminoe(map + y, x, ttrs[index]); 		 
// 				if (solve_map(map, ttrs, size, index + 1))
// 					return (1);
// 				delete_ttr(map + y, x, ttrs[index]);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }


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

// all content, such as '.', '\0' and NULL are added to the grid.
char	**create_grid(int size)
{
	char 	**grid;
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
		while(j < size)
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

// a single ttr is added to the grid
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

// a single ttr is checked against the grid.
int		check_tetriminoe(char **map, int x_map, int y_map, char *ttr)
{
	int 	i;
	int		size;

	i = 1;
	size = ft_strlen(map[0]);
	while (i < 9 && (size > ((y_map + ttr[i]) && (x_map + ttr[i + 1]))))
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

// all '#' are transformed into a letter according to their position in the file
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

// ttrs[0] == 65, 0 3, 1 3, 2 3, 3 3  is transformed into
// ttrs[0] == 65, 0 0, 1 0, 2 0, 3 0
void	shorten_index(char **ttrs)
{
	int		y_low;
	int		x_low;
	int		y;
	int		x;

	y = 0;
	while (ttrs[y] != NULL)
	{
		y_low = 1000;
		x_low = 1000;
		x = 1;
		while (x < 9)
		{
			y_low = (ttrs[y][x] < y_low) ? ttrs[y][x] : y_low;
			x++;
			x_low = (ttrs[y][x] < x_low) ? ttrs[y][x] % 5 : x_low;
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

// reassign ttrs lines (each ttrs[i] was ...#\n...#\n...#\n...#\n\0) into
// x and y coordinates. the first value is the letter, following four pairs of coords.
// the above example for ttr of letter 'A' would be ttrs[0] == 65, 0 3, 1 3, 2 3, 3 3.
// something odd about this code is that the contents of buf[z] need to be increased 
// by one to ensure that ft_strcpy works, and it's great because shorten_index() 
// is called right after with the contents of buf now copied back to ttr, and the 
// the second while loop would have needed to subract y_low and x_low by one, like this
// ttrs[y][x] -= (y_low - 1);		but now there's no need
void	hash_coordinates(char **ttrs)
{
	int y;
	int x;
	int	z;
	char buf[21];

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

// check if valid tetrimino shape appears of ttrs file
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

// check if valid newlines appear in ttrs file
int 	newline_chk(char **ttrs)
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

// check if valid characters appear in ttrs file
int		char_chk(char **ttrs)
{
	int y;
	int x;
	char *str;

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

void	populate_buff(char *buff, char **ttr)
{
	*ttr = ft_strnew(21);
	ft_strcpy(*ttr, buff);
}

int		read_file(char *argv[], char **ttrs)
{
	int		fd;
	char	buff[22];
	int 	ret;
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
		ttrs[i++] = NULL; // make sure i is increased
		return (-i);
	}
	if (ret == 20)
		populate_buff(buff, &ttrs[i]);
	ttrs[++i] = NULL;
	close(fd);
	return (i);
}

