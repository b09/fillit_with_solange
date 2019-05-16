/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 13:25:46 by bprado         #+#    #+#                */
/*   Updated: 2019/05/16 22:07:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	char 	*ttrs[27];
	char 	**grid;
	int 	i;
	int		ret;

	i = 0;
	
	printf("return : %d\n", read_file(argv, ttrs));
	if (argc != 2)
		return (0);

	// if (fillit(argv, ttrs) < 0)
	// 	delete_ttr(ttrs);
	hash_to_letter(ttrs);
	hash_locations(ttrs);
	shorten_index(ttrs);
	grid = create_grid(4);
	populate_grid(grid, 4);
	if ((ret = check_tetriminoe(grid, 0, 0, ttrs[0])))
		add_tetriminoe(grid, 0, 0, ttrs[0]);

	int j;
	while (ttrs[i] != NULL)
	{
		j = 0;
		while (j < 9)
			printf("%d ", ttrs[i][j++]);
		++i;
		printf("\n");
	}

	i = 0;
	while (grid[i] != NULL)
		printf("%s\n", grid[i++]);
	printf("ret is: %d\n", ret);

	// if (!valid_ttr(ttrs))
	// 	printf("not right nwlcheck\n");
	return (0);
}

// validation: 
// only '.' & '#'
// character count 

