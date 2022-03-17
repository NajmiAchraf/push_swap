/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/17 00:29:49 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_by_two_sections_1ra_2ra(t_stack *stack, int minup, int maxup, int mindown, int maxdown)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_a - 1;
	while (i < stack->size_a / 2 || stack->size_a / 2 < j)
	{
		if ((minup <= stack->a[j] && stack->a[j] <= maxup)
			|| (mindown <= stack->a[j] && stack->a[j] <= maxdown))
			return (ra(stack));
		else if ((minup <= stack->a[i] && stack->a[i] <= maxup)
			|| (mindown <= stack->a[i] && stack->a[i] <= maxdown))
			return (rra(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_two_sections_down(t_stack *stack)
{
	int	i;
	int	j1;
	int	j2;
	int	k;
	int	lu;
	int	mu;
	int	ld;
	int	md;
	int	n;

	k = stack->capacity % stack->msect;
	if (stack->lsect % 2 == 0)
	{
		i = (stack->lsect) / 2;
		n = (stack->lsect) / 2 - 1;
	}
	else if (stack->lsect % 2 != 0)
	{
		i = (stack->lsect) / 2;
		n = i;
	}
	while (n >= 0)
	{
		j1 = 0;
		j2 = 0;
		lu = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		mu = stack->sorted[get_n_section(stack, i) + k];
		ld = stack->sorted[get_n_section(stack, n + 1) + k - 1];
		md = stack->sorted[get_n_section(stack, n) + k];
		if (n == i)
			j2 = stack->msect;
		while (j1 < stack->msect || j2 < stack->msect)
		{
			if ((ld <= stack->a[stack->last_a] && stack->a[stack->last_a] <= md)
				|| (lu <= stack->a[stack->last_a] && stack->a[stack->last_a] <= mu))
			{
				if (ld <= stack->a[stack->last_a] && stack->a[stack->last_a] <= md)
				{
					pb(stack);
					// swap_b(stack);
					j1++;
				}
				if (lu <= stack->a[stack->last_a] && stack->a[stack->last_a] <= mu && n != i)
				{
					pb(stack);
					rb(stack);
					j2++;
				}
			}
			else
				choose_by_two_sections_1ra_2ra(stack, lu, mu, ld, md);
		}
		i++;
		n--;
	}
}

int	choose_by_section_1ra_2ra(t_stack *stack, int min, int max)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_a - 1;
	while (i < stack->size_a / 2 || stack->size_a / 2 < j)
	{
		if (min <= stack->a[j] && stack->a[j] <= max)
			return (ra(stack));
		else if (min <= stack->a[i] && stack->a[i] <= max)
			return (rra(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_section_down(t_stack *stack, int *sorted_list)
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
		l = sorted_list[get_n_section(stack, i + 1) + k - 1];
		m = sorted_list[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->a[stack->last_a] && stack->a[stack->last_a] <= m)
			{
				pb(stack);
				j++;
			}
			else
				choose_by_section_1ra_2ra(stack, l, m);
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

void	push_by_section_fly(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = stack->lsect - 1;
	k = stack->capacity % stack->msect;
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
				choose_by_section_1ra_2ra(stack, l, m);
		}
		i--;
	}
}
