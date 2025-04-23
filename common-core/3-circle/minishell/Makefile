# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 09:57:05 by mivogel           #+#    #+#              #
#    Updated: 2025/04/16 09:57:56 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c

OBJS_DIR = objs
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

Red='\e[1;31m'
Green='\e[1;32m'
NC='\e[0m'

all: ${NAME}

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} -o $@ $(OBJS)
	@echo $(Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJS_DIR}
	@echo $(Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@rm -f ${NAME} ${BONUS}
	@echo $(Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all bonus clean fclean