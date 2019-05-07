#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"

int		gnl_fillit(char *argv, char **ary);
char	**create_grid(int size);
int		add_to_grid(char **ttrs, char **grid, int gx, int gy);
int		ft_sqrt(int nb);
void	remove_excess_dots(char **ary, int low, int high);
void	remove_excess_dots_two(char **ary, int lines, int low, int high);
int		lnchk(char *str);
void	change_to_letter(char **ary, int lines, int lines2);
int		check_last_characters(char *argv); 
int		check_tetriminoe(int lin, int chr, char **ary);
int		pop_ttr(char **grid, char **ttrs, int gridsize, int check);
int		check_tetrimino(char **ttrs, char **grid, int gs, int gi);
int		check_entire_list(char **ttrs, char **grid, int lines, int gi);
void	delete_grid(char **grid, int size);
#endif 