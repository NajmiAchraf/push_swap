/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:23:03 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/01 14:51:33 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_a(t_stack *stack)
{
	if (stack->a[0] > stack->a[stack->last_a])
		return (ra(stack));
	return (0);
}

int	rotate_b(t_stack *stack)
{
	if (stack->b[0] < stack->b[stack->last_b])
		return (rb(stack));
	return (0);
}

int	rotate_ab(t_stack *stack)
{
	if (stack->a[0] > stack->a[stack->last_a]
		&& stack->b[0] < stack->b[stack->last_b])
		return (rr(stack));
	return (0);
}

void	rotating(t_stack *stack)
{
	int i;

	i = 1;
	while (i)
	{
		i = rotate_ab(stack);
		if (!i)
		{
			rotate_a(stack);
			rotate_b(stack);
		}
	}
}
