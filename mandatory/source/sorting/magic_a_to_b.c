/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 04:52:16 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* int	choose_by_two_sections_ra_rra(t_stack *stack, int minup, int maxup, \
		int mindown, int maxdown)
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
				choose_by_two_sections_ra_rra(stack, lu, mu, ld, md);
		}
		i++;
		n--;
	}
}
 */

void core2(t_stack *stack, t_var *v)
{
	if ((v->mindown <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v->maxdown)
		|| (v->minup <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v->maxup))
	{
		if (v->mindown <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v->maxdown)
		{
			pb(stack);
			v->i++;
		}
		if (v->minup <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v->maxup && v->s1 != v->s2)
		{
			pb(stack);
			rb(stack);
			v->j++;
		}
	}
	else
		choose_by_two_sections_ra_rra(stack, v);
}

void core1(t_stack *stack, t_var *v)
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
			core2(stack, v);
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
	core1(stack, &v);
}
void	push_by_two_sections_down_save(t_stack *stack)
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
	while (v.s2 >= 0)
	{
		v.i = 0;
		v.j = 0;
		v.minup = stack->sorted[get_n_section(stack, v.s1 + 1) + v.k - 1];
		v.maxup = stack->sorted[get_n_section(stack, v.s1) + v.k];
		v.mindown = stack->sorted[get_n_section(stack, v.s2 + 1) + v.k - 1];
		v.maxdown = stack->sorted[get_n_section(stack, v.s2) + v.k];
		if (v.s1 == v.s2)
			v.j = stack->msect;
		while (v.i < stack->msect || v.j < stack->msect)
		{
			if ((v.mindown <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v.maxdown)
				|| (v.minup <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v.maxup))
			{
				if (v.mindown <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v.maxdown)
				{
					pb(stack);
					v.i++;
				}
				if (v.minup <= stack->a[stack->last_a] && stack->a[stack->last_a] <= v.maxup && v.s1 != v.s2)
				{
					pb(stack);
					rb(stack);
					v.j++;
				}
			}
			else
				choose_by_two_sections_ra_rra(stack, &v);
		}
		v.s1++;
		v.s2--;
	}
}

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
