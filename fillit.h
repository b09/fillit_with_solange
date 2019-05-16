/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 20:29:02 by bprado         #+#    #+#                */
/*   Updated: 2019/05/16 23:40:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>

int     read_file(char *argv[], char **ttrs);
void	populate_buff(char *buff, char **ttr);
void	delete_ttr(char **ttrs);
int 	newline_chk(char **ttrs);
int		char_chk(char **ttrs);
int		valid_ttr(char **ttrs);
void	hash_coordinates(char **ttrs);
void	shorten_index(char **ttrs);
void	hash_to_letter(char **ttrs);
int		check_tetriminoe(char **map, int x_map, int y_map, char *ttr);
int		add_tetriminoe(char **map, int x_map, int y_map, char *ttr);
char	**create_grid(int size);
void	remove_ttr(char **map, char letter);

#endif
