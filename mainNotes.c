#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char *argv[])
{
	int openfd;
	char *line;
	int i;
	char buf[26];

	if (argc != 2)
		return (0);
	openfd = open(argv[1], O_RDONLY);

	if (openfd != -1)
	{
		i = read(openfd, buf, 26);
		while(i)
		{
			printf("%s\n", buf);
			i = read(openfd, buf, 26);
		}
	}
	close(openfd);
	return (0);
}

check number of lines
check number of tetriminos
check last line 

characters to recognize are ". # \n \0 "

4n4n4n4nn 4n4n4n4nn 4n4n4n4n0

...#n...#n...#n...#nn 
...#n...#n...#n...#n0

// while the length of the string divided by 5 is 0, good, otherwise exit
ft_strlen(str) % 5

while(str[i])
{
	
}

newlines:
4 or 9 or 14

while number of newlines (plus one) is divisible by 5, good : bad ; 


bool	validate_newlines(char *str)
{
	int	newlines;

	newlines = 1;
	while (*str != '\0')
	{
		(*str == '\n') ? ++newlines : newline;
		++str;
	}
	return (newlines % 5 == 0) ? TRUE : FALSE;
}

the order of operations should be:
read file
if *str != '.' || *str != '#'
	return false;

as i read


---------------vesion as of march 31--------------------------

int		check_char(char *str)
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
	return (cnt);
}

int		check_tetriminoe(int lin2, int lns, char **ary)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	lns *= 4;
	while (lns > 4)
	{

		i = (((*ary)[y] == '#') && ((y < 3) && ((*ary)[y + 1] == '#'))) ? (i + 1) : i;
		i = (((*ary)[y] == '#') && ((y > 0) && ((*ary)[y - 1] == '#'))) ? (i + 1) : i;
		i = (((*ary)[y] == '#') && ((lns > 0) && ((*(ary + 1))[y] == '#'))) ? (i + 1) : i;
		i = (((*ary)[y] == '#') && ((lns < (4 * lin2 - 3)) && ((*(ary - 1))[y] == '#'))) ? (i + 1) : i;


		// i = (((*ary)[y] == '#') && ((y < 3) && ((*ary)[y + 1] == '#'))) ? (i + 1) : i;
		// printf("ahead: %c--", ((y < 3) ? (*ary)[y + 1] : 'N'));
		// (((*ary)[y] == '#') && ((y < 3) && ((*ary)[y + 1] == '#'))) ? printf("TRUE 1, ") : printf("false 1, ");

		// i = (((*ary)[y] == '#') && ((y > 0) && ((*ary)[y - 1] == '#'))) ? (i + 1) : i;
		// printf("behind: %c--", ((y > 0) ? (*ary)[y - 1] : 'N'));
		// (((*ary)[y] == '#') && ((y > 0) && ((*ary)[y - 1] == '#'))) ? printf("TRUE 2, ") : printf("false 2, ");

		// i = (((*ary)[y] == '#') && ((lns > 0) && ((*(ary + 1))[y] == '#'))) ? (i + 1) : i;
		// printf("below: %c--", ((lns > 0) ? (*(ary + 1))[y] : 'N'));
		// (((*ary)[y] == '#') && ((lns > 0) && ((*(ary + 1))[y] == '#'))) ? printf("TRUE 3, ") : printf("false 3, ");

		// i = (((*ary)[y] == '#') && ((lns < (4 * lin2 - 3)) && ((*(ary - 1))[y] == '#'))) ? (i + 1) : i;
		// printf("above: %c--", ((lns < (4 * lin2 - 3)) ? (*(ary - 1))[y] : 'N'));
		// (((*ary)[y] == '#') && ((lns < ((4 * lin2) - 3)) && ((*(ary - 1))[y] == '#'))) ? printf("TRUE 4\t") : printf("false 4\t");


		printf("current index: %d char: %c in line: %s i is: %d\n", y, (*ary)[y], *ary, i);

		
		ary = ((y == 3) || (ft_strlen(*ary) < 4)) ? (ary + 1) : ary;
		if ((ft_strlen(*ary) < 4) && (i != 6) && (i != 8))
			return (0);
		i = (ft_strlen(*ary) < 4) ? 0 : i;
		y = ((y < 3) || (ft_strlen(*ary) < 4)) ? (y + 1) : 0;

		lns = (ft_strlen(*ary) < 4) ? (lns - 4) : (lns - 1);
	}
	return (1);
}

// gnl_fillit checks for correct number of newlines by checking the newline's count divisibility by 5
// checks number of hashtags
// checks if character is anything other than a period or hashtag
// ensures the length of the lines that separate each tetriminoe is 0

// needs to:
//			confirm validity of tetriminoes
//			ensure there is a newline at the end of the file
//			

int		gnl_fillit(char *argv, char **ary)
{
	int			openfd;
	int			nline;
	int			chars;

	nline = 0;
	openfd = open(argv, O_RDONLY);
	while(openfd != -1 && get_next_line(openfd, &ary[nline]))
	{
		if (((ft_strlen(ary[nline]) != 4) && ((nline + 1) % 5)) || \
			((ft_strlen(ary[nline]) != 0) && ((nline + 1) % 5) == 0) || \
			((check_char(ary[nline]) < 0) && ((nline + 1) % 5) == 0))
			return (0);
		chars += check_char(ary[nline]);
		if ((((nline + 1) % 5) == 0) && (chars != 4))
			return (0);
		chars = (((nline + 1) % 5) == 0) ? 0 : chars ;
		++nline;
	}
	if ((((nline + 1) % 5) != 0) || (check_tetriminoe(nline, nline, ary) == 0))
		return (0);
	close(openfd);
	return (nline);
}

int		main(int argc, char *argv[])
{
	char		*ary[130];
	int			lines;
	int			i = 0;

	lines = gnl_fillit(argv[1], ary);

	if (lines <= 0)
		printf("error\n");

	while(lines--)
		printf("----Return: %d, String: %s\n", i, ary[i++]);

	return (0);
}

--------------------------------------