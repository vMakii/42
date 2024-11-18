# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 10:30:07 by mivogel           #+#    #+#              #
#    Updated: 2024/11/18 10:05:52 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ./srcs/ft_printf.c ./srcs/ft_puthexa.c ./srcs/ft_putvoid.c ./srcs/ft_printf_fun.c

OBJS = ${SRCS:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs $@ $^

$(LIBFT): 

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re
