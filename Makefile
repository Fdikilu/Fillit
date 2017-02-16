# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 20:29:49 by fdikilu           #+#    #+#              #
#    Updated: 2017/02/16 13:16:12 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

GFLAG = -Wall -Wextra -Werror

HEADER = -Iincludes

LIBFT_DIR = libft

LIB = $(LIBFT_DIR)/libft.a

SRC =	libft/ft_putchar.c \
		libft/ft_putstr.c \
		libft/ft_strlen.c \
		libft/ft_memset.c \
		libft/ft_memcpy.c \
		libft/ft_lstnew.c \
		libft/ft_lstadd.c \
		libft/ft_lstclr.c \
		file_check.c \
		nb_tetriminos.c \
		parsing.c \
		solve.c \
		create_soluce.c \
		main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $? -o $@ -g

%.o : %.c
	$(CC) $(GFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
