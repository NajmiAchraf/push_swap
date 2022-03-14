/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:34:29 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 19:35:00 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

void	create_stack(t_stack *stack, int capacity)
{
	stack->capacity = capacity - 1;
	stack->size_a = stack->capacity;
	stack->size_b = 0;
	stack->last_a = stack->capacity - 1;
	stack->last_b = -1;
	stack->a = (int *)malloc(stack->capacity * sizeof(int *));
	if (!stack->a)
	{
		free(stack);
		return ;
	}
	stack->b = (int *)malloc(stack->capacity * sizeof(int *));
	if (!stack->b)
	{
		free(stack->a);
		free(stack);
		return ;
	}
}

void	fill_in(t_stack *stack, int ac, char *av[])
{
	int	i;

	i = 0;
	while (--ac > 0)
	{
		stack->a[i] = ft_atoi(av[ac]);
		i++;
	}
}
