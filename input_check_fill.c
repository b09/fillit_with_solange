#include "fillit.h"

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
	//int		low;
	//int		high;

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