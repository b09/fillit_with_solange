/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:25:46 by bprado         #+#    #+#                */
/*   Updated: 2019/05/21 18:17:04 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* int		main(int argc, char *argv[])
{
	char 	*ttrs[27];
	char 	**grid;
	int 	i;
	int		size;
	// int		j;
	// int		k;
	// char	**grid2;

	size = 2;
	grid = NULL;
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
		shorten_index(ttrs, 0, 1);
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
	// i = 0;
	// while (ttrs[i] != NULL)
	// {
	// 	j = 0;
	// 	while (j < 9)
	// 	{
	// 		printf(" %d", ttrs[i][j++]);
	// 		if (j % 2)
	// 			printf(",");
	// 	}
	// 	printf("\n");
	// 	printf("\n");
	// 	grid2 = create_grid(4);
	// 	add_tetriminoe(grid2, 0, 0, ttrs[i]);
	// 	k = 0;
	// 	while (grid2[k] != NULL)
	// 		printf("%s\n", grid2[k++]);
	// 	delete_grid(grid2, 4);
	// 	printf("\n");
	// 	++i;
	// }
	// printf("\n");



	// print current grid
	i = 0;
	while (grid[i] != NULL)
		printf("%s\n", grid[i++]);

	// printf("ret is (solve_map): %d\n", ret);

	return (0);
} */

int		main(int argc, char *argv[])
{
	char	*ttrs[27];
	char	**grid;
	int		i;
	int		size;

	size = 2;
	grid = NULL;
	i = 0;
	if (argc != 2)
		return (0);
	if (read_file(argv, ttrs) && \
		char_chk(ttrs) &&\
		newline_chk(ttrs) &&\
		valid_ttr(ttrs))
	{
		hash_to_letter(ttrs);
		hash_coordinates(ttrs);
		shorten_index(ttrs, 0, 1);
		grid = create_grid(size);
		while (solve_map(grid, ttrs, 0) == 0)
		{
			delete_grid(grid, size);
			++size;
			grid = create_grid(size);
		}
	}
	i = 0;
	while (grid[i] != NULL)
		printf("%s\n", grid[i++]);
	return (0);
}
