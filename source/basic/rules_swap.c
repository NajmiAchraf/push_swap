/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 19:24:59 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sa(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		action("sa");
		return (1);
	}
	return (0);
}

int	sb(t_stack *stack)
{
	if (stack->size_b > 1)
	{
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
		action("sb");
		return (1);
	}
	return (0);
}

int	ss(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
		action("ss");
		return (1);
	}
	return (0);
}
