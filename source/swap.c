/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:14:37 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/01 14:49:33 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *n1, int *n2)
{
	int	save;

	save = *n1;
	*n1 = *n2;
	*n2 = save;
}

int	swap_a(t_stack *stack)
{
	if (stack->a[stack->last_a] > stack->a[stack->last_a - 1])
		return (sa(stack));
	return (0);
}

int	swap_b(t_stack *stack)
{
	if (stack->b[stack->last_b] < stack->b[stack->last_b - 1])
		return (sb(stack));
	return (0);
}

int	swap_ab(t_stack *stack)
{
	if (stack->a[stack->last_a] > stack->a[stack->last_a - 1]
		&& stack->b[stack->last_b] < stack->b[stack->last_b - 1])
		return (ss(stack));
	return (0);
}

void	swaping(t_stack *stack)
{
	int i;

	i = 1;
	while (i)
	{
		i = swap_ab(stack);
		if (!i)
		{
			swap_a(stack);
			swap_b(stack);
		}
	}
}
