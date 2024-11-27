# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 10:30:07 by mivogel           #+#    #+#              #
#    Updated: 2024/11/27 12:25:58 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = ./srcs/ft_printf.c ./srcs/ft_printf_fun.c ./srcs/ft_puthexa.c ./srcs/ft_putvoid.c

OBJS = ${SRCS:.c=.o}

GCC = cc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs $@ ${OBJS} 

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
