SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o : %.c
	${GCC} ${FLAGS)} -c $*.c -Iincludes -o $*.o

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
