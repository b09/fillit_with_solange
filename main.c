/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:25:46 by bprado         #+#    #+#                */
/*   Updated: 2019/05/18 01:19:47 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	char 	*ttrs[27];
	char 	**grid;
	int 	i;
	int		j;
	int		size;

	size = 2;
	i = 0;
	if (argc != 2)
		return (0);
	

	// check all functions are working
	if (read_file(argv, ttrs) && \
		char_chk(ttrs) &&\
		newline_chk(ttrs) &&\
		valid_ttr(ttrs))
	{
		hash_to_letter(ttrs);
		hash_coordinates(ttrs);
		shorten_index(ttrs);
		grid = create_grid(size);
		// grid = create_grid(4);
		// if (check_tetriminoe(grid, 0, 0, ttrs[17]))
		// {
		// 	add_tetriminoe(grid, 0, 0, ttrs[17]);
		// 	remove_ttr(grid, ttrs[17][0]);
		// 	add_tetriminoe(grid, 0, 0, ttrs[0]);
		// }
		while (solve_map(grid, ttrs, 0) == 0)
		{
			delete_grid(grid, size);
			++size;
			grid = create_grid(size);
		}
	}




	// print current ttrs list
	i = 0;
	while (ttrs[i] != NULL)
	{
		j = 0;
		while (j < 9)
		{
			printf(" %d", ttrs[i][j++]);
			if (j % 2)
				printf(",");
		}
		++i;
		printf("\n");
	}
	printf("\n");



	// print current grid
	i = 0;
	while (grid[i] != NULL)
		printf("%s\n", grid[i++]);

	// printf("ret is (solve_map): %d\n", ret);

	return (0);
}

