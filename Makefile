# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bprado <bprado@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 17:19:55 by bprado            #+#    #+#              #
#    Updated: 2019/05/07 20:15:24 by bprado           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = validate.c solver.c helpers.c transform_tetri.c main.c 

LIB = ./libft

HDR = ./fillit.h

OBJ += $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
		make -C $(LIB)
		gcc -o $(NAME) $(SRC) -I $(HDR) $(LIB)/libft.a $(FLAGS)
		
clean:
		rm -f $(OBJ)
		make -C $(LIB) clean
	
fclean: clean	
		rm -rf $(NAME)
		make -C $(LIB) fclean

re: fclean all
