# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:05:51 by mivogel           #+#    #+#              #
#    Updated: 2025/07/02 16:45:11 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_atol.c ft_atoll.c ft_bzero.c ft_calloc.c ft_free.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnum.c ft_isprint.c \
	   ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tablen.c ft_tolower.c ft_toupper.c \
	   ft_printf.c ft_printf_fun.c ft_puthexa.c ft_putvoid.c \
	   get_next_line.c get_next_line_utils.c ft_isspace.c ft_print_tab.c
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

Red='\e[0;31m'
Green='\e[0;32m'
NC='\e[0m'

all: ${NAME}

bonus: $(BONUS)

$(NAME): ${OBJS}
	@ar rcs $@ $^
	@printf "\n"
	@echo $(Green)✅$@ compiled! $(NC)

${OBJS_DIR}/%.o: srcs/%.c
	@printf "\e[0;33mCompiling: %-30s\r\e[0m" "$<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS): ${OBJS} ${BONUS_OBJS}
	@ar rcs $@ ${BONUS_OBJS} ${OBJS}
	@echo $(Green)✅$@ compiled! $(NC)
clean:
	@rm -rf ${OBJS_DIR} 

fclean:
	@rm -f ${NAME} $(BONUS)
	@echo $(Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : all bonus clean fclean re
