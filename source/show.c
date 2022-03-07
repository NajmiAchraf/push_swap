/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:20 by anaimi            #+#    #+#             */
/*   Updated: 2022/03/07 21:47:36 by anajmi           ###   ########.fr       */
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
			printf("%d", stack->b[i]);
			j = ft_int_length(stack->b[i]);
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
	printf("|-----------------------|\n");
	printf("|a          |b          |\n");
	printf("|-----------------------|\n");

	usleep(90000);
	if (clear)
	{
		// getchar();
		system("clear");
	}
}
