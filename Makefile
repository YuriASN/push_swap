# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 19:19:38 by ysantos-          #+#    #+#              #
#    Updated: 2022/11/03 20:36:28 by ysantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = *.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make bonus -Clibft/
	$(CC) $(FLAGS) $(SRC) -Llibft -lft -o $(NAME)

clean:
	make clean -Clibft/
	/bin/rm -f *.o

fclean: clean
	make fclean -Clibft/
	/bin/rm -f $(NAME)

re: fclean all
