# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 11:05:59 by mivogel           #+#    #+#              #
#    Updated: 2024/11/27 13:07:40 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT = libft/libft.a

PRINTF = ft_printf/ft_printf.a

LIBFTDIR = libft/

PRINTFDIR = ft_printf/

SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

GCC = cc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

$(NAME): ${OBJS} $(LIBFT) $(PRINTF)
	cp $(LIBFT) $(NAME)
	cp $(PRINTF) $(NAME)
	ar rcs $@ ${OBJS}

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C ${LIBFTDIR}

$(PRINTF): $(PRINTFDIR)
	$(MAKE) -C ${PRINTFDIR}

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(PRINTFDIR)
	rm -f ${OBJS}

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) fclean -C $(PRINTFDIR)
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
