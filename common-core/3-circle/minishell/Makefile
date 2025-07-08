# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 09:57:05 by mivogel           #+#    #+#              #
#    Updated: 2025/07/08 15:55:48 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/make/srcs.mk
include libft/make/colors.mk

TERM_WIDTH := $(shell tput cols)
SHELL = /bin/bash

vpath %.c ${SRCS_PATH}

INC = -I includes/ -I libft/includes
LIBS = -L libft -lft -lreadline

OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = cc
CFLAGS += -g3
CFLAGS += -Wall -Wextra -Werror
NAME = minishell

default:	help
	@	${MAKE} --no-print-directory ${NAME}

all: ${NAME}

ifeq ($(shell test $(TERM_WIDTH) -gt 50; echo $$?), 0)
help:
	@	echo -ne "\r\033[2K" $(WHITE) "----------------------------------------------"${NC}"\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "all       →  "${NC}"Compile the program.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "clean     →  "${NC}"Removes temporary files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "fclean    →  "${NC}"Deletes all generated files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "re        →  "${NC}"Rebuilds the project.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "valgrind  →  "${NC}"Check for memory leaks.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "libft     →  "${NC}"Rebuilds libft.\n"
	@	echo -ne "\r\033[2K" $(WHITE) "----------------------------------------------"${NC}"\n"
else
help:
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"all\n"${NC}" Compile the program.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"clean\n"${NC}" Removes temporary files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"fclean\n"${NC}" Deletes all generated files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"re\n"${NC}" Rebuilds the project.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"valgrind\n"${NC}" Check for memory leaks.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"libft\n"${NC}" Rebuilds libft.\n"
endif

${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile includes/minishell.h
	@	$(MAKE) --no-print-directory -s -C libft
	@	mkdir -p ${OBJS_PATH}
	@	$(COLORCOMPIL)
	@	${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:  ${OBJS}
	@	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${INC}	
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ $(NAME) OK!\n"$(NC)

clean:	
	@	+$(MAKE) --no-print-directory -s -C libft clean
	@ 	echo -ne "\r\033[2K" $(LIGHTRED) "→ objs cleaned\n"$(NC)
	@	rm -rf readline_leaks.supp
	@	rm -rf ${OBJS_PATH}


fclean:	clean;
	@	+$(MAKE) --no-print-directory -s -C libft fclean
	@	echo -ne "\r\033[2K" $(LIGHTRED) "→ $(NAME) cleaned\n"$(NC)
	@	rm -f ${NAME}

re:	fclean ${NAME}

valgrind:	${NAME}
	@	echo -ne \
		"{\n" \
		"	readline_leaks\n" \
		"	Memcheck:Leak\n" \
		"	...\n" \
		"	fun:readline\n" \
		"}\n" \
		"{\n" \
		"	readline_leaks\n" \
		"	Memcheck:Leak\n" \
		"	...\n" \
		"	fun:add_history\n" \
		"}\n" > readline_leaks.supp
	@		echo -ne "\r\033[2K"$(LIGHTBLUE)"Valgrind ./${NAME}: \n--track-fds=yes \n--suppressions=readline_leaks.supp \n--leak-check=full --show-leak-kinds=all"$(NC)"\n"
	@		-valgrind --track-fds=yes --suppressions=readline_leaks.supp --leak-check=full --show-leak-kinds=all ./${NAME}

libft:
	@	+$(MAKE) --no-print-directory -s -C libft re

include libft/make/colorcompil.mk

.PHONY: default all clean fclean re valgrind libft 