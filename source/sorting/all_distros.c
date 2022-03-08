/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_distros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/08 18:15:07 by anajmi           ###   ########.fr       */
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

void	sorting_4_50(t_stack *stack)
{
	stack->msect = 3;
	sort(stack);
}

void	sorting_51_350(t_stack *stack)
{
	stack->msect = 5;
	sort(stack);
}

void	sorting_351(t_stack *stack)
{
	stack->msect = 12;
	sort(stack);
}
