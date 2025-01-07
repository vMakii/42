# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2025/01/07 10:20:10 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
LIBFTDIR = libft/

SERVER = server
SRCS_S = server.c
OBJS_S = $(addprefix srcs/, ${SRCS_S:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

RED = '\033[0;31m'
GREEN = '\033[0;32m'
RESET = '\033[0m'

all: ${SERVER}

$(SERVER): ${OBJS_S} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS_S) ${LIBFT}
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
