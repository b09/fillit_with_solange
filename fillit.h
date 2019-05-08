/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:29:02 by bprado         #+#    #+#                */
/*   Updated: 2019/05/08 13:41:46 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"

char			**create_grid(int size);
int				gnl_fillit(char *argv, char **ary);
int				add_to_grid(char **ttrs, char **grid, int gx, int gy);
int				ft_sqrt(int nb);
int				lnchk(char *str);
int				check_last_characters(char *argv);
int				check_lines(int lin, int chr, char **ary);
int				pop_ttr(char **grid, char **ttrs, int gridsize, int check);
int				check_ttr(char **ttrs, char **grid, int gs, int gi);
int				check_entire_list(char **ttrs, char **grid, int lines, int gi);
void			remove_excess_dots_two(char **ary, int lines, int low, int high);
void			change_to_letter(char **ary, int lines, int lines2);
void			remove_excess_dots(char **ary, int low, int high);
void			delete_grid(char **grid, int size);
void            print_grid(char **grid, int size);

#endif
