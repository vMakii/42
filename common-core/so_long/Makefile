# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2025/02/27 11:04:46 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a
LIBFTDIR = libft/

MLX = mlx/libmlx.a
MLXDIR = mlx/

SRCS = main.c checks/check_map.c checks/parsing.c utils/map_utils.c utils/free_utils.c
OBJS_DIR = objs
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

CC = cc
MAKE = make --no-print-directory
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes -Imlx
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm -lGL

Black='\e[0;30m'
Gray='\e[0;37m'
D_Gray='\e[1;30m'
Red='\e[0;31m'
L_Red='\e[1;31m'
Green='\e[0;32m'
L_Green='\e[1;32m'
Orange='\e[0;33m'
Yellow='\e[1;33m'
Blue='\e[0;34m'
L_Blue='\e[1;34m'
Purple='\e[0;35m'
L_Purple='\e[1;35m'
Cyan='\e[0;36m'
L_Cyan='\e[1;36m'
White='\e[1;37m'
NC='\e[0m'

a: all clean

all: ${NAME}

$(NAME): ${OBJS} ${LIBFT} ${MLX}
	@${CC} -o $@ $(OBJS) ${LIBFT} ${MLX_FLAGS}
	@echo $(L_Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C ${LIBFTDIR}

$(MLX):
	@$(MAKE) -C ${MLXDIR}

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFTDIR)
	@$(MAKE) --no-print-directory clean -C $(MLXDIR)
	@rm -rf ${OBJS_DIR}
	@echo $(L_Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(L_Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : a all clean fclean
