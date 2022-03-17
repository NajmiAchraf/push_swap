/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_distros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 00:28:50 by anajmi           ###   ########.fr       */
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
	stack->msect = 10;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	hard_sort(stack);
	push_one_by_one_directly(stack);
	
	/* stack->msect = 30;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	stack->msect = 15;
	stack->lsect = get_section(stack, stack->size_b);
	push_by_section_up(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_fly(stack);
	hard_sort(stack);
	five_three_sort(stack); */
}

void	restore_all(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->size_b;
	while (i > 0)
	{
		pa(stack);
		i--;
	}
}

void	sorting_351(t_stack *stack)
{

	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	hard_sort(stack);
	push_one_by_one_directly(stack);
	
	// stack->msect = 60;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_two_sections_down(stack);
	// restore_all(stack);
	// // stack->msect = 74;
	// // stack->lsect = get_section(stack, stack->size_b);
	// // push_by_section_up(stack);
	// stack->msect = 5;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_two_sections_down(stack);
	// hard_sort(stack);
	// push_one_by_one_directly(stack);

	// stack->msect = 125;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_two_sections_down(stack);
	// stack->msect = 25;
	// stack->lsect = get_section(stack, stack->size_b);
	// push_by_section_up(stack);
	// stack->msect = 5;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_section_fly(stack);
	// hard_sort(stack);
	// five_three_sort(stack); 

	/* stack->msect = 100;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_b);
	push_by_section_up(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_fly(stack);
	hard_sort(stack);
	five_three_sort(stack); */
}
