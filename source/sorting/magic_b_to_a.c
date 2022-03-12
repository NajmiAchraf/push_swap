/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/12 15:54:05 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_1rb_2rb(t_stack *stack, int tofindlow, int tofindmax)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_b - 1;
	while (i < stack->size_b / 2 || stack->size_b / 2 < j)
	{
		if (tofindlow <= stack->b[j] && stack->b[j] <= tofindmax)
			return (rb(stack));
		else if (tofindlow <= stack->b[i] && stack->b[i] <= tofindmax)
			return (rrb(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_section_up(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = 0;
	k = stack->size_a % stack->msect;
	while (i < stack->lsect)
	{
		j = 0;
		l = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		m = stack->sorted[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->b[stack->last_b] && stack->b[stack->last_b] <= m)
			{
				pa(stack);
				j++;
			}
			else
				choose_1rb_2rb(stack, l, m);
		}
		i++;
	}
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

static void	core_b_to_a(t_stack *stack, int max, int min, int i)
{
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
	if (i != stack->lsect - 1)
		rrr(stack);
	else
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
	rrb(stack);
	while (i < stack->lsect)
	{
		l = stack->sorted[get_n_section(stack, i + 1) + j - 1];
		m = stack->sorted[get_n_section(stack, i) + j];
		core_b_to_a(stack, m, l, i);
		i++;
	}
}
