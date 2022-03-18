/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_distros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 19:02:06 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting_5_50(t_stack *stack)
{
	stack->msect = 3;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	hard_sort(stack);
	while (stack->lsect > 0)
	{
		three_sort(stack);
		stack->lsect--;
	}
}

void	sorting_51_350(t_stack *stack)
{
	stack->msect = 12;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	hard_sort(stack);
	push_one_by_one_directly(stack);
}

void	sorting_351(t_stack *stack)
{
	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	hard_sort(stack);
	push_one_by_one_directly(stack);
}
