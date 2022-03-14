# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:11:09 by anajmi            #+#    #+#              #
#    Updated: 2022/03/13 20:12:15 by anajmi           ###   ########.fr        #
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
FCLEANLIBFT = rm $(ARLIB)
RELIBFT = make re -C $(LIBFT)

$(NAME) : $(OBJ)
	$(ALLIBFT)
	gcc $(OBJ) $(ARLIB) -o $(NAME)

all : $(NAME)

clean :
	$(CLEANLIBFT)
	rm $(OBJ)
	rm $(BOBJ)

fclean : clean
	$(FCLEANLIBFT)
	rm $(NAME)
	rm $(BNM)

re : fclean all

$(BNM) : $(BOBJ)
	$(ALLIBFT)
	gcc $(BOBJ) $(ARLIB) -o $(BNM)

bonus : $(BNM)

.PHONY : all clean fclean re bonus