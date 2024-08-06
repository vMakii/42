NAME = do-op
SRC = main.c ft.c
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $*.c -o $*.o

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
