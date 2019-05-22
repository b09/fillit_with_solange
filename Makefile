# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/29 17:19:55 by bprado         #+#    #+#                 #
#    Updated: 2019/05/21 17:50:58 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -g

SRC = fillit.c main.c grid.c tetrimino_transformation.c validation_check.c

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
