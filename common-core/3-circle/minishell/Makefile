# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 09:57:05 by mivogel           #+#    #+#              #
#    Updated: 2025/07/03 14:51:24 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a
LIBFTDIR = libft/

SRCS = main.c\
	builtin/cd.c builtin/env.c builtin/exit.c builtin/unset.c \
	builtin/export.c builtin/echo.c builtin/pwd.c\
	exec/exec.c exec/get_command_path.c exec/heredoc.c exec/readline.c exec/exec_utils.c \
	exec/exec_utils_2.c \
	parsing/expand.c parsing/parse.c parsing/str_utils.c parsing/tokens.c\
	signals/handler.c signals/signals.c\
	utils/cd_utils.c utils/env_utils.c utils/err_utils.c utils/export_utils.c utils/lst_utils.c\

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

valgrind: ${NAME}
	@valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes ./${NAME}

noenv: ${NAME}
	@valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes env -i ./${NAME}

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFTDIR)
	@rm -rf ${OBJS_DIR}
	@echo $(Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all noenv clean fclean
