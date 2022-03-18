/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_a_to_b_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 19:08:17 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_by_section_ra_rra(t_stack *stack, int min, int max)
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
				choose_by_section_ra_rra(stack, l, m);
		}
		i--;
	}
}
