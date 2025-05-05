# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:05:51 by mivogel           #+#    #+#              #
#    Updated: 2025/05/05 15:18:04 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_free.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tablen.c ft_tolower.c ft_toupper.c \
	   ft_printf.c ft_printf_fun.c ft_puthexa.c ft_putvoid.c \
	   get_next_line.c get_next_line_utils.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free.c \
			 get_next_line_bonus.c

OBJS_DIR = objs
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})
BONUS_OBJS = $(addprefix ${OBJS_DIR}/, ${BONUS_SRCS:.c=.o})

NAME = libft.a
BONUS = libftbonus.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

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

all: ${NAME}

bonus: $(BONUS)

$(NAME): ${OBJS}
	@ar rcs $@ $^
	@echo $(L_Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS): ${OBJS} ${BONUS_OBJS}
	@ar rcs $@ ${BONUS_OBJS} ${OBJS}
	@echo $(L_Green)✅$@ compiled! $(NC)
clean:
	@rm -rf ${OBJS_DIR} 
	@echo $(L_Red)🗑️ *.o deleted! $(NC)

fclean:
	@rm -f ${NAME} $(BONUS)
	@echo $(L_Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all bonus clean fclean re
