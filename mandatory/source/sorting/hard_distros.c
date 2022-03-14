/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_distros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/14 15:01:20 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting_2(t_stack *stack)
{
	swaping(stack);
}

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
		&& stack->a[0] > stack->a[1])
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

void	sorting_4(t_stack *stack)
{
	swaping(stack);
	pb(stack);
	swaping(stack);
	pb(stack);
	swaping(stack);
	pb(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
}

void	hard_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		sorting_2(stack);
	else if (stack->size_a == 3)
		sorting_3(stack);
	else if (stack->size_a == 4)
		sorting_4(stack);
}
