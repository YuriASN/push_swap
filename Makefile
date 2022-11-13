# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 19:19:38 by ysantos-          #+#    #+#              #
#    Updated: 2022/11/12 10:08:53 by ysantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = *.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make bonus -Clibft/ --no-print-directory
	@$(CC) $(FLAGS) $(SRC) -Llibft -lft -o $(NAME)
	@echo "\033[92mProgram compiled!\033[m"
	
clean:
	@make clean -Clibft/ --no-print-directory
	@/bin/rm -f *.o
	@echo "\033[91mclean done for all.\033[m"
fclean: clean
	@make fclean -Clibft/ --no-print-directory
	@/bin/rm -f $(NAME)
	@echo "\033[91mfclean done for all.\033[m"

re: fclean all
