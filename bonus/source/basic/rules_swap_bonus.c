/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 18:16:26 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

void	swap(int *n1, int *n2)
{
	int	save;

	save = *n1;
	*n1 = *n2;
	*n2 = save;
}

int	sa(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		return (1);
	}
	return (0);
}

int	sb(t_stack *stack)
{
	if (stack->size_b > 1)
	{
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
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
		return (1);
	}
	return (0);
}
