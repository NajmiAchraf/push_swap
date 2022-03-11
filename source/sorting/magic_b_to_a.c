/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 18:57:19 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	restore_all(t_stack *stack)
{
	while (stack->size_b > 0)
		pa(stack);
}

void	three_sort(t_stack *stack)
{
	swap_b(stack);
	pa(stack);
	swap_b(stack);
	pa(stack);
	swap_a(stack);
	pa(stack);
}

static void	core_b_to_a(t_stack *stack, int max, int min)
{
	rrb(stack);
	rrb(stack);
	if (max == stack->b[stack->last_b])
		pa(stack);
	if (min == stack->b[stack->last_b])
	{
		pa(stack);
		ra(stack);
	}
	if (max == stack->b[stack->last_b])
		pa(stack);
	three_sort(stack);
	rra(stack);
}

void	five_three_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	l;
	int	m;

	i = 0;
	j = stack->capacity % stack->msect;
	while (i < stack->lsect)
	{
		l = stack->sorted[get_n_section(stack, i + 1) + j - 1];
		m = stack->sorted[get_n_section(stack, i) + j];
		core_b_to_a(stack, m, l);
		i++;
	}
}
