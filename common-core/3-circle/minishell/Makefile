# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 09:57:05 by mivogel           #+#    #+#              #
#    Updated: 2025/06/04 10:22:03 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a
LIBFTDIR = libft/

SRCS = main.c\
	builtin/env.c builtin/exit.c builtin/unset.c builtin/export.c \
	builtin/echo.c builtin/pwd.c \
	env/env_utils.c\
	parsing/expand.c parsing/parse.c parsing/str_utils.c parsing/tokens.c\
	utils/err_utils.c utils/utils.c utils/lst_utils.c\

OBJS_DIR = objs
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

Red='\e[0;31m'
Green='\e[0;32m'
NC='\e[0m'

all: ${NAME}

$(NAME): ${OBJS} $(LIBFT)
	@${CC} ${CFLAGS} -o $@ $(OBJS) -lreadline $(LIBFT)
	@printf "\n"
	@echo $(Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@printf "\e[0;33mCompiling: %-30s\r\e[0m" "$<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@printf "\n"
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
