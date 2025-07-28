# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:47:43 by mivogel           #+#    #+#              #
#    Updated: 2025/07/27 10:29:52 by gburtin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/make/srcs.mk
include libft/make/colors.mk

TERM_WIDTH := $(shell tput cols)
SHELL = /bin/bash

vpath %.c ${SRCS_PATH}

INC = -I includes/ -I libft/includes -I mlx
LIBS = -L libft -lft

MLX = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm -lGL

OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = cc
CFLAGS += -g3
CFLAGS += -Wall -Wextra -Werror
NAME = cub3D

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
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE) "mlx       →  "${NC}"Rebuilds libmlx.a.\n"
	@	echo -ne "\r\033[2K" $(WHITE) "----------------------------------------------"${NC}"\n"
else
help:
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"all\n"${NC}" Compile the program.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"clean\n"${NC}" Removes temporary files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"fclean\n"${NC}" Deletes all generated files.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"re\n"${NC}" Rebuilds the project.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"valgrind\n"${NC}" Check for memory leaks.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"libft\n"${NC}" Rebuilds libft.\n"
	@	echo -ne "\r\033[2K" $(LIGHTPURPLE)"mlx\n"${NC}" Rebuilds libmlx.a.\n"
endif

game: ${NAME}
	@	echo -ne "\r\033[2K" $(LIGHTBLUE) "→ Run ./${NAME} maps/valid_map1.cub\n"$(NC)
	@	./${NAME} maps/valid_map1.cub

${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile includes/cub3d.h
	@	$(MAKE) --no-print-directory -s -C libft
	@	mkdir -p ${OBJS_PATH}
	@	$(COLORCOMPIL)
	@	${CC} ${CFLAGS} -c $< -o $@ ${INC}

${MLX}: 
	@	echo -ne "\r\033[2K" $(YELLOW) "→ Compiling libmlx.a..."$(NC)
	@	$(MAKE) --no-print-directory -s -C mlx 
#> /dev/null 2>&1
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ libmlx.a OK!"$(NC)"\n"
	
${NAME}: ${MLX} ${OBJS}
	@	${CC} -o ${NAME} ${OBJS} ${LIBS} ${MLX_FLAGS} ${INC}	
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ $(NAME) OK!\n"$(NC)

clean:	
	@	+$(MAKE) --no-print-directory -s -C mlx clean 
#> /dev/null 2>&1
	@ 	echo -ne "\r\033[2K" $(LIGHTRED) "→ objs cleaned\n"$(NC)
	@	rm -rf ${OBJS_PATH}


fclean:	clean
	@	+$(MAKE) --no-print-directory -s -C libft fclean
	@	echo -ne "\r\033[2K" $(LIGHTRED) "→ $(NAME) cleaned\n"$(NC)
	@	rm -f ${NAME}

re:	fclean ${NAME}

valgrind:	${NAME}
	@		echo -ne "\r\033[2K"$(LIGHTBLUE)"Valgrind ./${NAME} maps/valid_map1.cub : \n--track-fds=yes \n--leak-check=full --show-leak-kinds=all --track-origins=yes"$(NC)"\n"
	@		-valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/valid_map1.cub

libft:
	@	+$(MAKE) --no-print-directory -s -C libft re

mlx:
	@	+$(MAKE) --no-print-directory -s -C mlx re

include libft/make/colorcompil.mk

.PHONY: default all clean fclean re valgrind libft mlx