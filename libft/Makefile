# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 19:23:52 by ysantos-          #+#    #+#              #
#    Updated: 2022/11/03 20:10:22 by ysantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_printf.c printf_utils.c ft_memset.c ft_atoi.c ft_putchar_fd.c ft_bzero.c ft_putendl_fd.c \
ft_calloc.c ft_putnbr_fd.c ft_isalnum.c ft_putstr_fd.c ft_isalpha.c \
ft_split.c ft_isascii.c ft_strchr.c ft_isdigit.c ft_strdup.c ft_isprint.c \
ft_striteri.c ft_itoa.c  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_memchr.c ft_tolower.c ft_memcmp.c ft_toupper.c ft_memcpy.c libft.h ft_memmove.c

BN = ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c get_next_line_bonus.c \
get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
BNOBJ = $(BN:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	$(CC) $(FLAGS) -c $(SRC) $(BN)
	ar rcs $(NAME) $(OBJ) $(BNOBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch libft.so

re: fclean all

rebonus: fclean bonus

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRC) $(BN)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BNOBJ)
