/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:25:46 by bprado         #+#    #+#                */
/*   Updated: 2019/05/17 00:22:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	char 	*ttrs[27];
	// char 	**grid;
	int 	i;

	i = 0;
	if (argc != 2)
		return (0);



	// check all functions are working
	if (read_file(argv, ttrs) && char_chk(ttrs) &&\
	newline_chk(ttrs) && valid_ttr(ttrs))
	{
		hash_to_letter(ttrs);
		hash_coordinates(ttrs);
		shorten_index(ttrs);
		grid = create_grid(4);
		if (check_tetriminoe(grid, 0, 0, ttrs[17]))
		{
			add_tetriminoe(grid, 0, 0, ttrs[17]);
			remove_ttr(grid, ttrs[17][0]);
			add_tetriminoe(grid, 0, 0, ttrs[0]);
		}
	}



	// print current ttrs list
	int j;
	while (ttrs[i] != NULL)
	{
		j = 0;
		while (j < 9)
			printf("%d ", ttrs[i][j++]);
		++i;
		printf("\n");
	}
	printf("\n");



	// // print current grid
	// i = 0;
	// while (grid[i] != NULL)
	// 	printf("%s\n", grid[i++]);


	return (0);
}

