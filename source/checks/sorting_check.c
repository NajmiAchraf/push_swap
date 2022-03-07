/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:40:10 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 16:30:51 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	a_isortinv(t_stack *stack)
{
	int	i;

	if (stack->size_a <= 1)
		return (0);
	i = stack->size_a;
	while (i > 0)
	{
		if (stack->a[i] < stack->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	a_isort(t_stack *stack)
{
	int	i;

	if (stack->size_a <= 1)
		return (0);
	i = stack->size_a;
	while (i > 0)
	{
		if (stack->a[i] > stack->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	b_isortinv(t_stack *stack)
{
	int	i;

	if (stack->size_b <= 1)
		return (0);
	i = stack->size_b;
	while (i > 0)
	{
		if (stack->b[i] < stack->b[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	b_isort(t_stack *stack)
{
	int	i;

	if (stack->size_b <= 1)
		return (0);
	i = stack->size_b;
	while (i > 0)
	{
		if (stack->b[i] > stack->b[i - 1])
			return (0);
		i--;
	}
	return (1);
}
