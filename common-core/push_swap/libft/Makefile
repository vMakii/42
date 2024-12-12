# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:05:51 by mivogel           #+#    #+#              #
#    Updated: 2024/12/12 14:39:48 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	   ft_printf.c ft_printf_fun.c ft_puthexa.c ft_putvoid.c \
	   get_next_line.c get_next_line_utils.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free.c \
			 get_next_line_bonus.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})
BONUS_OBJS = $(addprefix srcs/, ${BONUS_SRCS:.c=.o})

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

RED = '\033[0;31m'
GREEN = '\033[0;32m'
NC = '\033[0m'

all: ${NAME}

$(NAME): ${OBJS}
	@ar rcs $@ $^
	@echo $(GREEN)✅$@ compiled! $(NC)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: ${OBJS} ${BONUS_OBJS}
	@ar rcs ${NAME} ${BONUS_OBJS} ${OBJS}
	@echo $(GREEN)✅$(NAME) with bonus compiled! $(NC)
clean:
	@rm -f ${OBJS} ${BONUS_OBJS}
	@echo $(RED)🗑️ *.o deleted! $(NC)

fclean:
	@rm -f ${NAME}
	@echo $(RED)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all bonus clean fclean re
