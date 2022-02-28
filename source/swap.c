/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:14:37 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/28 14:16:01 by anajmi           ###   ########.fr       */
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

void	swap_a(t_stack *stack)
{
	if (stack->a[stack->last_a] < stack->a[stack->last_a - 1])
		sa(stack);
}

void	swap_b(t_stack *stack)
{
	if (stack->b[stack->last_b] < stack->b[stack->last_b - 1])
		sb(stack);
}

void	swap_ab(t_stack *stack)
{
	if (stack->a[stack->last_a] < stack->a[stack->last_a - 1]
		&& stack->b[stack->last_b] < stack->b[stack->last_b - 1])
		ss(stack);
}

void	swaping(t_stack *stack)
{
	swap_ab(stack);
	swap_a(stack);
	swap_b(stack);
}