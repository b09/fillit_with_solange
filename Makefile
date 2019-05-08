# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/29 17:19:55 by bprado         #+#    #+#                 #
#    Updated: 2019/05/08 11:52:13 by svan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = validate.c solver.c grid.c transform_tetri.c main.c 

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
