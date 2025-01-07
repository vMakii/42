# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2025/01/07 12:13:50 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
LIBFTDIR = libft/

NAME = ${SERVER} ${CLIENT}

SERVER = server
SRCS_S = server.c
OBJS_S = $(addprefix srcs/, ${SRCS_S:.c=.o})

CLIENT = client
SRCS_C = client.c
OBJS_C = $(addprefix srcs/, ${SRCS_C:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

Black='\e[0;30m'
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
L_Gray='\e[0;37m'
White='\e[1;37m'
NC='\e[0m'

all: ${SERVER} ${CLIENT}

$(SERVER): ${OBJS_S} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS_S) ${LIBFT}
	@echo $(Green)✅$@ compiled! $(NC)

$(CLIENT): ${OBJS_C} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS_C) ${LIBFT}
	@echo $(Green)✅$@ compiled! $(NC)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

a: all clean

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C ${LIBFTDIR}

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@rm -f ${OBJS}
	@echo $(Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all clean fclean re
