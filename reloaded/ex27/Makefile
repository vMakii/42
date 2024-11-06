# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:40:24 by mivogel           #+#    #+#              #
#    Updated: 2024/11/06 10:14:38 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS = ft_display_file.c ft_putstr.c ft_putchar.c
OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: ${NAME}

${NAME}:	${OBJS}
	${CC} ${FLAGS)} $^ -o $@
 
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

.PHONY : all clean fclean
