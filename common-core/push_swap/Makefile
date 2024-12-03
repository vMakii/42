# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2024/12/03 15:03:58 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

LIBFTDIR = libft/

SRCS = ft_push_swap.c ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

RED = '\033[0;31m'
GREEN = '\033[0;32m'
NC = '\033[0m'

all: ${NAME}

$(NAME): ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS) ${LIBFT}
	@echo $(GREEN)✅$@ compiled! $(NC)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) bonus -C ${LIBFTDIR}

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -f ${OBJS}
	@echo $(RED)🗑️ *.o deleted! $(NC)
fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(RED)🗑️ $(NAME) deleted! $(NC)
re: fclean all

.PHONY : all clean fclean re
