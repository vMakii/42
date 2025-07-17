# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 12:51:46 by mivogel           #+#    #+#              #
#    Updated: 2025/07/17 14:23:53 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = tests.cpp Account.cpp
SRCS_PATH = ./srcs/

OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = c++
INC = -I includes/
CFLAGS = -Wall -Wextra -Werror -std=c++98

vpath %.cpp ${SRCS_PATH}

NAME = Account

all: ${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.cpp Makefile
	@	mkdir -p ${OBJS_PATH}
	@	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

${NAME}: ${OBJS}
	@	$(CC) $(CFLAGS) -o ${NAME} ${OBJS} $(INC)

clean:
	@	rm -rf ${OBJS_PATH}

fclean: clean
	@	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re