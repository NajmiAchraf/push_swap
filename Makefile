# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:11:09 by anajmi            #+#    #+#              #
#    Updated: 2022/03/12 18:46:49 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

FILES = \
		./source/basic/rules_push.c				\
		./source/basic/rules_reverse_rotate.c	\
		./source/basic/rules_rotate.c			\
		./source/basic/rules_swap.c				\
		./source/basic/swap.c					\
		./source/checks/checking.c				\
		./source/sorting/hard_distros.c			\
		./source/sorting/magic_a_to_b.c			\
		./source/sorting/magic_b_to_a.c			\
		./source/sorting/magic_distros.c		\
		./source/sorting/magic_tools.c			\
		./source/sorting/sort_distro.c			\
		./push_swap.c

OBJ = $(FILES:.c=.o)

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

fclean : clean
	$(FCLEANLIBFT)
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re