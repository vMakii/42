SRCS := main.cpp Character.cpp MateriaSource.cpp Ice.cpp Cure.cpp AMateria.cpp
SRCS_PATH := ./srcs

OBJS_PATH := ./objs
OBJS := $(addprefix $(OBJS_PATH)/,$(SRCS:.cpp=.o))

CC := c++
INC := -I includes/
CFLAGS := -Wall -Wextra -Werror -std=c++98

vpath %.cpp $(SRCS_PATH)

NAME := Abstract

all: $(NAME)

$(OBJS_PATH)/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INC)

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re