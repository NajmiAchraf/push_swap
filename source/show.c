/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:20 by anaimi            #+#    #+#             */
/*   Updated: 2022/03/05 22:42:42 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_int_length(long value)
{
	int	l;

	l = 1;
	if (value < 0)
	{
		value *= (-1);
		l += 1;
	}
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void	show(t_stack *stack, int clear)
{
	int	i, j;

	i = stack->capacity - 1;

	printf("\033[0;37m");
	printf("_________________________\n");
	while (0 <= i)
	{
		if (0 <= i && i <= stack->last_a)
		{
			if (stack->a[i] == stack->sorted[i])
				printf("|\033[0;32m");
			else if (stack->a[i] != stack->sorted[i])
				printf("|\033[0;31m");
			// if (ft_int_length(stack->a[i]) == 1)
			// 	printf("%d          ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 2)
			// 	printf("%d         ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 3)
			// 	printf("%d        ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 4)
			// 	printf("%d       ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 5)
			// 	printf("%d      ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 6)
			// 	printf("%d     ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 7)
			// 	printf("%d    ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 8)
			// 	printf("%d   ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 9)
			// 	printf("%d  ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 10)
			// 	printf("%d ", stack->a[i]);
			// else if (ft_int_length(stack->a[i]) == 11)
			// 	printf("%d", stack->a[i]);
			printf("%d", stack->a[i]);
			j = ft_int_length(stack->a[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
		}
		else
			printf("|           ");
		printf("\033[0;37m");
		if (0 <= i && i <= stack->last_b)
		{
			printf("|\033[0;33m");
			// if (ft_int_length(stack->b[i]) == 1)
			// 	printf("%d          \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 2)
			// 	printf("%d         \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 3)
			// 	printf("%d        \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 4)
			// 	printf("%d       \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 5)
			// 	printf("%d      \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 6)
			// 	printf("%d     \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 7)
			// 	printf("%d    \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 8)
			// 	printf("%d   \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 9)
			// 	printf("%d  \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 10)
			// 	printf("%d \033[0;37m|\n", stack->b[i]);
			// else if (ft_int_length(stack->b[i]) == 10)
			// 	printf("%d\033[0;37m|\n", stack->b[i]);
			printf("%d", stack->a[i]);
			j = ft_int_length(stack->a[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
			printf("\033[0;37m|\n");
		}
		else
			printf("|           |\n");
		i--;
	}
	printf("\033[0;37m");
	printf("|-----------------------|\n");
	printf("|\033[0;32ma          \033[0;37m|\033[0;33mb          \033[0;37m\033[0;37m|\n");
	printf("\033[0;37m");
	printf("|-----------------------|\n");

	usleep(9000);
	if (clear)
	{
		// getchar();
		system("clear");
	}
}
