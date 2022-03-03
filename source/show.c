/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:20 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/03 12:49:01 by anajmi           ###   ########.fr       */
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
	int	i, j, k;

	i = stack->capacity - 1;
	j = i;
	k = j;
	printf("_______________________\n");
	while (0 <= k)
	{
		if (0 <= i && i <= stack->last_a)
		{
			if (ft_int_length(stack->a[i]) == 1)
				printf("|%d         ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 2)
				printf("|%d        ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 3)
				printf("|%d       ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 4)
				printf("|%d      ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 5)
				printf("|%d     ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 6)
				printf("|%d    ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 7)
				printf("|%d   ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 8)
				printf("|%d  ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 9)
				printf("|%d ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 10)
				printf("|%d", stack->a[i]);
		}
		else
			printf("|          ");
		if (0 <= j && j <= stack->last_b)
		{
			if (ft_int_length(stack->b[j]) == 1)
				printf("|%d         |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 2)
				printf("|%d        |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 3)
				printf("|%d       |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 4)
				printf("|%d      |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 5)
				printf("|%d     |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 6)
				printf("|%d    |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 7)
				printf("|%d   |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 8)
				printf("|%d  |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 9)
				printf("|%d |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 10)
				printf("|%d|\n", stack->b[j]);
		}
		else
			printf("|          |\n");
		i--;
		j--;
		k--;
	}
	printf("|---------------------|\n");
	printf("|a         |b         |\n");
	printf("|---------------------|\n");

	usleep(50000);
	if (clear)
	{
		// getchar();
		system("clear");
	}
		
}
