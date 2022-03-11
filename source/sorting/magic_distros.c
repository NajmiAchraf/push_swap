/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_distros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 19:04:26 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting_5_50(t_stack *stack)
{
	stack->msect = 3;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_3(stack);
	hard_sort(stack);
	while (1)
	{
		three_sort(stack);
		if (stack->capacity == stack->size_a)
			break ;
	}
}

void	sorting_51_350(t_stack *stack)
{
	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_three(stack);
	restore_all(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_five(stack);
	hard_sort(stack);
	five_three_sort(stack);
}

void	sorting_351(t_stack *stack)
{
	stack->msect = 100;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_three(stack);
	restore_all(stack);
	sorting_51_350(stack);
}
