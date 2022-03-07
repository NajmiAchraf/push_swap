/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:23:03 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 19:14:14 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	reverse_rotate_a(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		if (stack->a[0] > stack->a[stack->last_a])
			return (rra(stack));
	}
	return (0);
}

int	reverse_rotate_b(t_stack *stack)
{
	if (stack->size_b > 1)
	{
		if (stack->b[0] < stack->b[stack->last_b])
			return (rrb(stack));
	}
	return (0);
}

int	reverse_rotate_ab(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1)
	{
		if (stack->a[0] > stack->a[stack->last_a]
			&& stack->b[0] < stack->b[stack->last_b])
			return (rrr(stack));
	}
	return (0);
}

void	reverse_rotating(t_stack *stack)
{
	int i;

	i = reverse_rotate_ab(stack);
	if (!i)
	{
		reverse_rotate_a(stack);
		reverse_rotate_b(stack);
	}
}