/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/16 15:07:38 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_by_section_1rb_2rb(t_stack *stack, int min, int max)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_b - 1;
	while (i < stack->size_b / 2 || stack->size_b / 2 < j)
	{
		if (min <= stack->b[j] && stack->b[j] <= max)
			return (rb(stack));
		else if (min <= stack->b[i] && stack->b[i] <= max)
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

	i = -1;
	k = stack->size_a;
	while (++i < stack->lsect)
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
				choose_by_section_1rb_2rb(stack, l, m);
		}
	}
}

int	choose_one_by_one_1rb_2rb(t_stack *stack, int nbr)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_b - 1;
	while (i < (stack->size_b / 2) || (stack->size_b / 2) < j)
	{
		if (stack->b[j] == nbr)
			return (rb(stack));
		else if (stack->b[i] == nbr)
			return (rrb(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_one_by_one_directly(t_stack *stack)
{
	int	i;
	int	sa;
	int	sb;
	int	nbr;

	i = 0;
	sa = stack->size_a;
	sb = stack->size_b;
	while (i < sb)
	{
		nbr = stack->sorted[i + sa];
		if (stack->b[stack->last_b] == nbr)
		{
			pa(stack);
			i++;
		}
		else
			choose_one_by_one_1rb_2rb(stack, nbr);
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
