/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 18:16:19 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

int	ra(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_a)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i++;
			j++;
		}
		return (1);
	}
	return (0);
}

int	rb(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_b > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_b)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i++;
			j++;
		}
		return (1);
	}
	return (0);
}

int	rr(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_a)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i++;
			j++;
		}
		i = 0;
		j = 1;
		while (j < stack->size_b)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i++;
			j++;
		}
		return (1);
	}
	return (0);
}
