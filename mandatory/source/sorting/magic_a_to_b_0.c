/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_a_to_b_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 19:18:26 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	core2_push_by_two_sections(t_stack *stack, t_var *v)
{
	if ((v->mindown <= stack->a[stack->last_a]
			&& stack->a[stack->last_a] <= v->maxdown)
		|| (v->minup <= stack->a[stack->last_a]
			&& stack->a[stack->last_a] <= v->maxup))
	{
		if (v->mindown <= stack->a[stack->last_a]
			&& stack->a[stack->last_a] <= v->maxdown)
		{
			pb(stack);
			v->i++;
		}
		if (v->minup <= stack->a[stack->last_a]
			&& stack->a[stack->last_a] <= v->maxup && v->s1 != v->s2)
		{
			pb(stack);
			rb(stack);
			v->j++;
		}
	}
	else
		choose_by_two_sections_ra_rra(stack, v);
}

static void	core1_push_by_two_sections(t_stack *stack, t_var *v)
{
	while (v->s2 >= 0)
	{
		v->i = 0;
		v->j = 0;
		v->minup = stack->sorted[get_n_section(stack, v->s1 + 1) + v->k - 1];
		v->maxup = stack->sorted[get_n_section(stack, v->s1) + v->k];
		v->mindown = stack->sorted[get_n_section(stack, v->s2 + 1) + v->k - 1];
		v->maxdown = stack->sorted[get_n_section(stack, v->s2) + v->k];
		if (v->s1 == v->s2)
			v->j = stack->msect;
		while (v->i < stack->msect || v->j < stack->msect)
		{
			core2_push_by_two_sections(stack, v);
		}
		v->s1++;
		v->s2--;
	}
}

int	choose_by_two_sections_ra_rra(t_stack *stack, t_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_a - 1;
	while (i < stack->size_a / 2 || stack->size_a / 2 < j)
	{
		if ((v->minup <= stack->a[j] && stack->a[j] <= v->maxup)
			|| (v->mindown <= stack->a[j] && stack->a[j] <= v->maxdown))
			return (ra(stack));
		else if ((v->minup <= stack->a[i] && stack->a[i] <= v->maxup)
			|| (v->mindown <= stack->a[i] && stack->a[i] <= v->maxdown))
			return (rra(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_two_sections_down(t_stack *stack)
{
	t_var	v;

	v.k = stack->capacity % stack->msect;
	if (stack->lsect % 2 == 0)
	{
		v.s1 = (stack->lsect) / 2;
		v.s2 = (stack->lsect) / 2 - 1;
	}
	else if (stack->lsect % 2 != 0)
	{
		v.s1 = (stack->lsect) / 2;
		v.s2 = v.s1;
	}
	core1_push_by_two_sections(stack, &v);
}
