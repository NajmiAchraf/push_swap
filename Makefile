# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:11:09 by anajmi            #+#    #+#              #
#    Updated: 2022/03/14 16:10:09 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

MFL = \
		./mandatory/source/basic/rules_push.c			\
		./mandatory/source/basic/rules_reverse_rotate.c	\
		./mandatory/source/basic/rules_rotate.c			\
		./mandatory/source/basic/rules_swap.c			\
		./mandatory/source/basic/swap.c					\
		./mandatory/source/check/checking.c				\
		./mandatory/source/sorting/hard_distros.c		\
		./mandatory/source/sorting/magic_a_to_b.c		\
		./mandatory/source/sorting/magic_b_to_a.c		\
		./mandatory/source/sorting/magic_distros.c		\
		./mandatory/source/sorting/magic_tools.c		\
		./mandatory/source/sorting/sort_distro.c		\
		./mandatory/push_swap.c

OBJ = $(MFL:.c=.o)

BNM = checker

BFL = \
		./bonus/get_next_line/get_next_line_utils.c			\
		./bonus/get_next_line/get_next_line.c				\
		./bonus/source/basic/rules_push_bonus.c				\
		./bonus/source/basic/rules_reverse_rotate_bonus.c	\
		./bonus/source/basic/rules_rotate_bonus.c			\
		./bonus/source/basic/rules_swap_bonus.c				\
		./bonus/source/source/checking_bonus.c				\
		./bonus/source/source/stack_bonus.c					\
		./bonus/checker_bonus.c

BOBJ = $(BFL:.c=.o)

LIBFT = ./Libft
ARLIB = $(LIBFT)/libft.a
ALLIBFT = make -C $(LIBFT)
CLEANLIBFT = make clean -C $(LIBFT)
FCLEANLIBFT = rm -f $(ARLIB)
RELIBFT = make re -C $(LIBFT)

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
	@$(ALLIBFT)
	@gcc $(OBJ) $(ARLIB) -o $(NAME)
	@echo "$(C_GREEN)[MANDATORY CREATED!]$(C_RES)"

bonus : $(BNM)

$(BNM) : $(BOBJ)
	@$(ALLIBFT)
	@gcc $(BOBJ) $(ARLIB) -o $(BNM)
	@echo "$(C_L_BLUE)[BONUS CREATED!]$(C_RES)"

clean :
	@$(CLEANLIBFT)
	@rm -f $(OBJ)
	@rm -f $(BOBJ)
	@echo "$(C_RED)[OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(FCLEANLIBFT)
	@rm -f $(NAME)
	@rm -f $(BNM)
	@echo "$(C_RED)[ARCHIVE & EXECUTABLES REMOVED!]$(C_RES)"

re : fclean all

.PHONY : all clean fclean re bonus