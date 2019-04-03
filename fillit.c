
#include "libft/includes/libft.h"






int		lnchk(char *str)
{
	int 	cnt;

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





void	change_to_letter(char **ary, int lines)
{
	char	letter;
	int		i;
	int		x;

	i = 0;
	x = 0;
	letter = 'A';
	while (lines > 0)
	{
		if (ary[0][i] == '#')
		{
			ary[0][i] = letter;
			++x;
		}
		++i;
		ary = (i == 4) ? (ary + 1) : ary;
		lines = (i == 4) ? (lines - 1) : lines;
		i = (i == 4) ? 0 : i;
		letter = (x == 4) ? (letter + 1) : letter;
		x = (x == 4) ? 0 : x;
	}
}





int		check_tetriminoe(int lin2, int lns, char **ary)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (lns > 4)
	{
		if ((*ary != 0) && (*ary)[y] == '#')
		{
			i = (((y < 3) && ((*ary)[y + 1] == '#'))) ? (i + 1) : i;
			i = (((y > 0) && ((*ary)[y - 1] == '#'))) ? (i + 1) : i;
			i = (((lns > 0) && ((*(ary + 1))[y] == '#'))) ? (i + 1) : i;
			i = ((lns < (4 * lin2 - 3)) && ((*(ary - 1))[y] == '#')) ? (i + 1) : i;
		}
		// printf("this is string: %s, lines:%d, i:%d, division:%d\n", (*ary), lns, i, (((lns + 4) / 4) % 5));
		ary = (y == 3 || ft_strlen(*ary) < 4) ? (ary + 1) : ary;
		if (((lns / 4) % 20 == 0) && (i != 6) && (i != 8))
			return (0);
		i = ((lns / 4) % 5 == 0) ? 0 : i;
		y = ((y < 3) || (ft_strlen(*ary) < 4)) ? (y + 1) : 0;
		lns = (ft_strlen(*ary) < 4) ? (lns - 4) : (lns - 1);
	}
	change_to_letter((ary - lin2 + 1), lin2);
	return (1);
}






int		gnl_fillit(char *argv, char **ary)
{
	int			openfd;
	int			nline;
	int			chars;

	nline = 0;
	openfd = open(argv, O_RDONLY);
	while(openfd != -1 && get_next_line(openfd, &ary[nline]) && nline < 130)
	{
		if (((ft_strlen(ary[nline]) != 4) && ((nline + 1) % 5)) || \
			((ft_strlen(ary[nline]) != 0) && ((nline + 1) % 5) == 0) || \
			((lnchk(ary[nline]) < 0) && ((nline + 1) % 5)))
			return (0);
		chars += lnchk(ary[nline]);
		if ((((nline + 1) % 5) == 0) && (chars != 4))
			return (0);
		chars = (((nline + 1) % 5) == 0) ? 0 : chars ;
		++nline;
	}
	if ((((nline + 1) % 5) != 0) || \
	(check_tetriminoe(nline, (nline * 4), ary) == 0) || nline > 129)
		return (0);
	close(openfd);
	return (nline);
}
























void		remove_excess_dots(char **ary, int lines)
{
	int		boundrylow;
	int		counterlines;
	int		holder;
	char	letter;
	int		i;

	letter = 'A';
	i = 0;
	boundrylow = 4;
	counterlines = 0;

	while (lines)
	{
		while (counterlines < 5) // count from starting line
		{
			while (i < 4)
			{
				if (*ary[i] == letter)
				{
					boundrylow = (i < boundrylow) ? i: boundrylow;
					break ;
				}
				i++;
			}
			++ary;
			++counterlines;
			--lines;
		}
		if (counterlines == 5)
		{
			while (counterlines)
			{
				printf("before: %s ----", (ary - counterlines)[0]);
				ft_memmove( (ary - counterlines)[boundrylow], (ary - counterlines)[0], ft_strlen((ary - counterlines)[0]) + 1);
				--counterlines;
				printf("after: %s +++++, boundrylow = %d\n", ary[i], boundrylow);
			}
		}
		++letter;
		i = 0;
		// printf("hey, lines:%d\n", lines);
	}
}





int		main(int argc, char *argv[])
{
	char		*ary[130];
	int			lines;
	int			i = 0;
	int			lines2;


	lines = gnl_fillit(argv[1], ary);
	lines2 = lines;

	if (lines <= 0)
		printf("error\n");

	remove_excess_dots(ary, lines);

	while(lines--)
		printf("----Return: %d, String: %s\n", lines, ary[i++]);

	i = 0;
	lines = lines2;
	
	// while(lines--)
	// {
	// 	(!ft_strlen(ary[i])) ? ft_memdel((void*)&ary[i]): ary[i];
	// 	i++;
	// }
	// i = 0;
	// lines = lines2;

	// while(lines--)
	// 	printf("----Return: %d, String: %s\n", lines, ary[i++]);

	return (0);
}