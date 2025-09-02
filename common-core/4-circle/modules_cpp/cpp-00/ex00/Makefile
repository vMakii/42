# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 20:37:06 by mivogel           #+#    #+#              #
#    Updated: 2025/09/02 20:37:37 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Megaphone.cpp
SRCS_PATH = ./

OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

vpath %.cpp ${SRCS_PATH}

NAME = Megaphone

all: ${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.cpp Makefile
	@	mkdir -p ${OBJS_PATH}
	@	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@	$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

clean:
	@	rm -rf ${OBJS_PATH}

fclean: clean
	@	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re