SRCS = ft_atoi.c ft_bzero.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
