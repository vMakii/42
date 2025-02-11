# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:36:11 by mivogel           #+#    #+#              #
#    Updated: 2025/02/11 11:58:43 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

LIBFT = libft/libft.a
LIBFTDIR = libft/

SRCS = main.c op/push.c op/reverse_rotate.c op/rotate.c op/swap.c sort/big_sort.c sort/move.c sort/sorting.c utils/checks.c utils/lst_utils.c utils/sort_utils.c
BONUS_SRCS = bonus/checker.c bonus/checker_utils.c op/push.c op/reverse_rotate.c op/rotate.c op/swap.c sort/sorting.c utils/checks.c utils/lst_utils.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})
BONUS_OBJS = $(addprefix srcs/, ${BONUS_SRCS:.c=.o})

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

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

ac: all clean

all: ${NAME}

100: $(NAME) $(BONUS)
	$(eval ARG = $(shell shuf -i 0-999 -n 100))
	@./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Nombre d'operations: " 
	@./push_swap $(ARG) | wc -l

500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-999 -n 500))
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'operations: " 
	@./push_swap $(ARG) | wc -l

$(NAME): ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} -o $@ $(OBJS) ${LIBFT}
	@echo $(L_Green)✅$@ compiled! $(NC)

bonus: ${LIBFT} ${OBJS} ${BONUS_OBJS}
	@${CC} ${CFLAGS} -o ${BONUS} ${BONUS_OBJS} ${LIBFT}
	@echo $(L_Purple)✅$@ compiled! $(NC)

%.o: %.c 	
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) --no-print-directory -C ${LIBFTDIR}

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFTDIR)
	@rm -f ${OBJS}
	@echo $(L_Red)🗑️ *.o deleted! $(NC)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f ${NAME}
	@echo $(L_Red)🗑️ $(NAME) deleted! $(NC)

re: fclean all

.PHONY : ac all bonus clean fclean

# ------------------------------------------------------------------------------------------------------------- >
# 
# 				████████╗███████╗░██████╗████████╗███████╗██╗░░░██╗██████╗░
# 				╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██║░░░██║██╔══██╗
# 				░░░██║░░░█████╗░░╚█████╗░░░░██║░░░█████╗░░██║░░░██║██████╔╝
# 				░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░██╔══╝░░██║░░░██║██╔══██╗
# 				░░░██║░░░███████╗██████╔╝░░░██║░░░███████╗╚██████╔╝██║░░██║
# 				░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░╚══════╝░╚═════╝░╚═╝░░╚═╝

# 	COPY PASTE ALL OF THIS SOMEWHERE IN YOUR MAKEFILE
# 	MAKE SURE THE NAME OF THE PROJECT IS:
# 		$(NAME) = push_swap
# 	or else change the value of $(NAMEE)

# 	AVAILABLE: (see desccription below)
# 	make a
# 	make m
# 	make n

NAMEE = push_swap
NAMEE_BONUS = push_swap_bonus

MIN = -999
MAX = 999
HOW_MANY = 5
HOW_MUCH = 100

# MAKE A: Run PUSH_SWAP with 'HOW_MANY' random numbers between 'MIN' and 'MAX'
# 
a: $(NAMEE)
	@$(call random_shmol_cat, "\'tis push shwap", $(HOW_MANY) number ね?, $(CLS), );
	@ARGS=$$(seq $(MIN) $(MAX) | shuf -n $(HOW_MANY) | tr '\n' ' ' | sed -r 's/ $$//'); \
	echo $$ARGS; \
	./$(word 1, $^) $$ARGS

# MAKE M: Run PUSH_SWAP 'HOW_MUCH' times, output the total move cost
# 			prints the return of YOUR main (0 is expeccted for stack sorted, 1 if not)
# 
m: $(NAMEE)
	@$(call random_shmol_cat, "\'tis push shwap tesshter、0 is OK、1 is KO", $(HOW_MANY) numbers、$(HOW_MUCH) times ね?, $(CLS), );
	@total=0; \
	for i in $$(seq 1 $(HOW_MUCH)); do \
		ARGS=$$(seq $(MIN) $(MAX) | shuf -n $(HOW_MANY) | tr '\n' ' ' | sed -r 's/ $$//'); \
		output=$$(./$(word 1, $^) $$ARGS); \
		return_code=$$?; \
		count=$$(echo "$$output" | wc -l); \
		echo "test $$i: $$count moves, OK? $$return_code"; \
		if [ $$return_code -eq 1 ]; then \
			echo "pile isnt sorted with these: $$ARGS"; \
			echo "$$ARGS" > bad_output; \
			echo "$$output" >> bad_output; \
		fi; \
		total=$$((total + count)); \
	done; \
	average=$$((total / $(HOW_MUCH))); \
	$(call random_shmol_cat, "heres average numbar:", $$average, , )

BAD_ARGS =  "0 1 2 2a 5" "0 1 2 wtf" "0 1 2 -2147483648 -2147483650" "0 1 2 9999999999 9" "4" "" " "  "-" "i want ..." "0 1-2 8 5" "0 1 2 8 1 5"

# MAKE N: Run a dozen bad arguments, with valgrind
# 
n: $(NAMEE)
	@for arg in $(BAD_ARGS); do \
	$(call random_shmol_cat, teshting lots of bad args:, $$arg, $(CLS), ); \
	$(VALGRIIND) ./$(word 1, $^) $$arg; \
	echo "\t\033[5m~ Press Enter to continue...\033[0m"; \
	read -p "" key; \
	done
	$(call random_shmol_cat, this one should work fine:, 1 5 2 7 -3, $(CLS), )
	$(VALGRIIND) ./$(word 1, $^) 1 5 2 7

# ------------------------------------------------------------------------------------------------------------- >
# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

CLS = \033[2J\033[H
# - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - VALGRIIND
VALGRIIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes
# ------------------------------------------------------------------------------------------------------------- >
