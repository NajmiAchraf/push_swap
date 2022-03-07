/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:44:34 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 18:09:42 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting_3(t_stack *stack)
{
	if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0]
		&& stack->a[0] < stack->a[1])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->a[2] < stack->a[1] && stack->a[2] > stack->a[0]
		&& stack->a[0] < stack->a[1])
		rra(stack);
	else if (stack->a[2] > stack->a[1] && stack->a[2] < stack->a[0]
		&& stack->a[0] < stack->a[1])
		sa(stack);
	else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0]
		&& stack->a[0] < stack->a[1])
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0]
		&& stack->a[0] > stack->a[1])
		ra(stack);
}
