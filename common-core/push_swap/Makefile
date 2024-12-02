# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2024/12/02 14:39:38 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

LIBFTDIR = libft/

SRCS = ft_push_swap.c ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

GREEN = '\033[0;32m'
NC = '\033[0m'

all: ${NAME}

$(NAME): ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $^ ${LIBFT}
	@echo $(GREEN) test! $(NC)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C ${LIBFTDIR}

bonus: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} -o $@ $^ ${LIBFT}

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f ${OBJS}

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
