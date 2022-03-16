/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_distros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/15 20:46:43 by anajmi           ###   ########.fr       */
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

void	sorting_up(t_stack *stack)
{
	int	origin_msect;
	int	origin_lsect;

	origin_msect = stack->msect;
	origin_lsect = stack->lsect;
	stack->msect = 3;
	stack->lsect = get_section(stack, stack->size_a);
	stack->hard_sorted = get_the_sorted_list(stack);
	push_by_section_down(stack, stack->hard_sorted);
	hard_sort(stack);
	while (stack->lsect > 0)
	{
		three_sort(stack);
		stack->lsect--;
	}
	stack->msect = origin_msect;
	stack->lsect = origin_lsect;
}

void	hard_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		sorting_2(stack);
	else if (stack->size_a == 3)
		sorting_3(stack);
	else if (stack->size_a == 4)
		sorting_4(stack);
	else if (stack->size_a >= 5)
		sorting_up(stack);
}
