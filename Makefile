# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 19:43:27 by liabanzh          #+#    #+#              #
#    Updated: 2018/01/14 19:43:28 by liabanzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft_thpool.a
SRC = thpool.c
FLAGS = -Wall -Wextra -Werror

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	ar rc $(NAME) $(SRC:.c=.o)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
