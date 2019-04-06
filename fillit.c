
#include "libft/includes/libft.h"



void	remove_excess_dots(char **ary, int lowbound, int highbound)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		ary[0][highbound + 1] = 0;
		ft_memmove(&ary[0][0], &ary[0][lowbound], ft_strlen(ary[0]));
		printf("lowbound: %d highbound: %d string: %s\n", lowbound, highbound, ary[0]);
		++ary;
		++count;
	}
}


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




void 	remove_excess_dots_two(char **ary, int lines)
{
	int		lowbound;
	int		highbound;
	int		i;

	lowbound = 4;
	highbound = 0;
	while (lines > 0)
	{
		i = 0;
		while (i < 4)
		{
			if ((ary[-lines][i] != '.') && (ary[-lines][i] != 0))
			{
				lowbound = (i < lowbound) ? i : lowbound;
				highbound = (i > highbound) ? i : highbound;
			}
			++i;
		}
		if (!(lines % 5))
		{
			remove_excess_dots(&ary[-(lines + 4)], lowbound, highbound);
			lowbound = 4;
			highbound = 0;
		}
		if (lines == 1)
			remove_excess_dots(&ary[-4], lowbound, highbound);
		--lines;
	}
}

void	change_to_letter(char **ary, int lines, int lines2)
{
	int		index;
	char	letter;
	int		lowbound;
	int		highbound;

	index = 0;
	letter = 'A';
	lowbound = 14;
	highbound = -10;
	while (lines > 0) // (lines > 0) this does not cause segfault but does not reach last tetrimino
	{
		// printf("char before 'ho':%c\n", ary[0][(index % 4)]);
		if ((ary[0][(index % 4)]) == '#')
		{
			ary[0][(index % 4)] = letter;
			lowbound = ((index % 4) < lowbound) ? (index % 4) : lowbound;
			highbound = ((index % 4) > highbound) ? (index % 4) : highbound;
			printf("line:%d lowbound:%d highbound:%d \n", index / 4, lowbound, highbound);
		}

		// printf("hey\n");
		// printf("loop count: %d lowbound: %d highbound: %d index: %d string: %s \n", lines, lowbound, highbound, 1 +(index / 4), ary[-4]);
		if (!((index) % 20) && (index > 1))
		{
			printf("lines: %d loop count: %d lowbound: %d highbound: %d index: %d  string: %s ---\n",lines,  index, lowbound, highbound, (index % 4), ary[-5]);
			remove_excess_dots(&ary[-5], lowbound, highbound);
			lowbound = 14;
			highbound = -10;
		}



		// INDEX NOW INCREASED
		++index;
		ary = (index % 4) ? ary : (ary + 1);
		lines = (index % 4) ? lines : (lines - 1);
		letter = (index % 20) ? letter : (letter + 1);
		// printf("lowbound will equal 4 when the following number is 0: %d\n", ((index - 1) % 20));
	}
	// remove_excess_dots_two(ary, lines2);
}


















// function assumes four characters per line and calculates chr by mulplying lines by four, though there are empty lines. 
// when empty lines are encountered, 4 is subtracted from chr count

// while the number of characters is greater than 4 (to not check the last empy line)
// 		if the string has content and the pointer of the string pointes to '#'
// 				increase the counter i if:
// 				- the index is less than 3 and the neighboring character (increased index on the str) is '#'
// 				- the index is greater than 0 and the neighboring character (decreased index on the str) is '#'
// 				- the character count is greater than 0 and character at the same index on the next line is '#'
// 				- the character count is less than the total number of characters minus 3 and character at the same index on the previous line is '#'

// 				add one to var ary if on the last index of str or if the str has no characters
// 				(each line gets check four times (for each character of the line)), therefore
// 				if the check which is divisible by 20 (5th line, 10th line, 15th line, ...) has count for var i which is not 6 or 8
// 						return (0)
// 				reset var i to zero if (not sure if correct)....
// 				increase var y plus one if at end of index or if strlen() is 0, otherwise reassign to 0
// 				subract 1 from var chr if strlen() of the str is 4, otherwise subtract 4 (four characters per line)
// 		change_to_letter(ary of pointers, number of lines);
// 		return (1);

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
			i = ((chr < (4 * lin - 3)) && ((*(ary - 1))[y] == '#')) ? (i + 1) : i;
		}
		// printf("this is string: %s, lines:%d, i:%d, division:%d\n", (*ary), chr, i, (((chr + 4) / 4) % 5));
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











// while open() has a valid return, and gnl is returning more than 0 and adding read lines to the array of pointers, and gnl only executes 130 times (130 newlines is limite of valid files)
// 		if the strlen is not 4 and the line number is not divisible by five (1,2,3,4 ,6,7,8,9 ...) or 
// 		if the strlen is not 0 and the line number is divisible by five (5, 10, 15, 20 ...) or
// 		if lnchk(str) finds a char that is not valid on the lines that are not divisible by five 
// 				return (0);

// 		add to variable chars the number of hashtags found through lnchk(str);
// 		if variable chars is not 4 when the line number is divisible by five (5th line, 10th line, 15th line, ...)
// 				return (0);

// 		if the line is divisible by five, reset the variable chars to 0
// 		increase the line number;

// if total line number is not divisible by five or a tetriminoe is not a valid type or gnl does not return 0
// 		return (0);

// return total number of lines;


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
	if (((nline + 1) % 5) || !(check_tetriminoe(nline, (nline * 4), ary)) || \
		get_next_line(openfd, &ary[nline]))
		return (0);
	close(openfd);
	return (nline);
}





// void		remove_excess_dots(char **ary, int lines)
// {
// 	int		boundrylow;
// 	int		counterlines;
// 	int		holder;
// 	char	letter;
// 	int		i;

// 	letter = 'A';
// 	i = 0;
// 	boundrylow = 4;
// 	counterlines = 0;

// 	while (lines)
// 	{
// 		while (counterlines < 5) // count from starting line
// 		{
// 			while (i < 4)
// 			{
// 				if (*ary[i] == letter)
// 				{
// 					boundrylow = (i < boundrylow) ? i: boundrylow;
// 					break ;
// 				}
// 				i++;
// 			}
// 			++ary;
// 			++counterlines;
// 			--lines;
// 		}
// 		if (counterlines == 5)
// 		{
// 			while (counterlines)
// 			{
// 				printf("before: %s ----", (ary - counterlines)[0]);
// 				ft_memmove( (ary - counterlines)[boundrylow], (ary - counterlines)[0], ft_strlen((ary - counterlines)[0]) + 1);
// 				--counterlines;
// 				printf("after: %s +++++, boundrylow = %d\n", ary[i], boundrylow);
// 			}
// 		}
// 		++letter;
// 		i = 0;
// 		// printf("hey, lines:%d\n", lines);
// 	}
// }




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

	// remove_excess_dots(ary, lines);

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