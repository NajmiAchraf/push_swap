/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/10 22:53:07 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_1ra_2ra(t_stack *stack, int tofindlow, int tofindmax)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_a - 1;
	while (i < stack->size_a / 2 || stack->size_a / 2 < j)
	{
		if (tofindlow <= stack->a[j] && stack->a[j] <= tofindmax)
			return (ra(stack));
		else if (tofindlow <= stack->a[i] && stack->a[i] <= tofindmax)
			return (rra(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_section_3(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lsect - 1;
	set_limitations(stack, stack->size_a);
	while (i >= 0)
	{
		j = 0;
		while (j < stack->msect)
		{
			if (stack->lowlimit[i] <= stack->a[stack->last_a]
				&& stack->a[stack->last_a] <= stack->maxlimit[i])
			{
				pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, stack->lowlimit[i], stack->maxlimit[i]);
		}
		i--;
	}
}

void	push_by_section_three(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = stack->lsect - 1;
	k = stack->size_a % stack->msect;
	while (i > 0)
	{
		j = 0;
		l = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		m = stack->sorted[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->a[stack->last_a] && stack->a[stack->last_a] <= m)
			{
				pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, l, m);
		}
		i--;
	}
}

static void	core_a_to_b(t_stack *stack, int max, int min)
{
	if (min == stack->a[stack->last_a] || max == stack->a[stack->last_a])
	{
		pb(stack);
		rb(stack);
	}
	else
		pb(stack);
}

void	push_by_section_five(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = stack->lsect - 1;
	k = stack->size_a % stack->msect;
	while (i >= 0)
	{
		j = 0;
		l = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		m = stack->sorted[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->a[stack->last_a] && stack->a[stack->last_a] <= m)
			{
				core_a_to_b(stack, m, l);
				j++;
			}
			else
				choose_1ra_2ra(stack, l, m);
		}
		i--;
	}
}
