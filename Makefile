# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/29 17:19:55 by bprado        #+#    #+#                  #
#    Updated: 2019/01/30 17:06:21 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

FLAGS = -Wall -Wextra -Werror

SRC = 	

OBJ += $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
		gcc $(FLAGS) -c $(SRC) -I ./includes
		ar rcs $(NAME) $(OBJ)


clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
