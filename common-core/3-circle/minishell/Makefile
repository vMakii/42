# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 09:57:05 by mivogel           #+#    #+#              #
#    Updated: 2025/05/05 15:17:26 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a
LIBFTDIR = libft/

SRCS = main.c env/env_utils.c \

OBJS_DIR = objs
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

Red='\e[1;31m'
Green='\e[1;32m'
NC='\e[0m'

all: ${NAME}

$(NAME): ${OBJS} $(LIBFT)
	@${CC} ${CFLAGS} -o $@ $(OBJS) -lreadline $(LIBFT)
	@echo $(Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) --no-print-directory -C ${LIBFTDIR}

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFTDIR)
	@rm -rf ${OBJS_DIR}
	@echo $(Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all clean fclean