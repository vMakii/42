# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2024/12/18 11:33:19 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

LIBFTDIR = libft/

SRCS = ft_push_swap.c lst_utils.c ft_sorting.c ft_checks.c ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

RED = '\033[0;31m'
GREEN = '\033[0;32m'
RESET = '\033[0m'

all: ${NAME}

$(NAME): ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS) ${LIBFT}
	@echo $(GREEN)✅$@ compiled! $(RESET)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

a: all clean

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C ${LIBFTDIR}

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -f ${OBJS}
	@echo $(RED)🗑️ *.o deleted! $(RESET)
fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(RED)🗑️ $(NAME) deleted! $(RESET)
re: fclean all

.PHONY : all clean fclean re
