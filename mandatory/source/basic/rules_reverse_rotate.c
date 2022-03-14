/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 19:24:15 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	rra(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1)
	{
		i = stack->last_a;
		j = stack->last_a - 1;
		while (j >= 0)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i--;
			j--;
		}
		action("rra");
		return (1);
	}
	return (0);
}

int	rrb(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_b > 1)
	{
		i = stack->last_b;
		j = stack->last_b - 1;
		while (j >= 0)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i--;
			j--;
		}
		action("rrb");
		return (1);
	}
	return (0);
}

int	rrr(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = stack->last_a;
		j = stack->last_a - 1;
		while (j >= 0)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i--;
			j--;
		}
		i = stack->last_b;
		j = stack->last_b - 1;
		while (j >= 0)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i--;
			j--;
		}
		action("rrr");
		return (1);
	}
	return (0);
}
