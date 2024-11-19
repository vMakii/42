# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 10:30:07 by mivogel           #+#    #+#              #
#    Updated: 2024/11/19 10:59:43 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

LIBFTDIR = libft/

SRCS = ./srcs/ft_printf.c ./srcs/ft_puthexa.c ./srcs/ft_putvoid.c ./srcs/ft_printf_fun.c

OBJS = ${SRCS:.c=.o}

GCC = cc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

$(NAME): ${OBJS} $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ ${OBJS} 

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C ${LIBFTDIR}

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f ${OBJS}

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f ${NAME}

bonus: ${OBJS}
	ar rcs ${NAME} ${OBJS}

re: fclean all

.PHONY : all clean fclean re
