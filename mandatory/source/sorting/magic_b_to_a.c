/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/17 01:10:02 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	int	j;
	int	sa;
	int	sb;
	int	nbr;

	i = 0;
	j = 0;
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
		else if (stack->b[stack->last_b - 1] == nbr
			&& stack->b[stack->last_b] == stack->sorted[i + sa + 1])
			swaping(stack);
		else
			choose_one_by_one_1rb_2rb(stack, nbr);
	}
}

void	push_one_by_one_imp_directly(t_stack *stack)
{
	int	i;
	int	j;
	int	sa;
	int	sb;
	int	nbr;

	i = 0;
	j = -1;
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
		else if (stack->b[stack->last_b - 1] == nbr
			&& stack->b[stack->last_b] == stack->sorted[i + sa + 1])
			swaping(stack);
		else if (stack->size_a >= 1
			&& ((j == -1 && stack->b[stack->last_b] < stack->a[0])
			|| (j >= 0 && stack->b[stack->last_b] > stack->a[0])))
		{
			pa(stack);
			ra(stack);
			j++;
		}
		else if (stack->a[0] == nbr)
		{
			rra(stack);
			j--;
			i++;
		}
		else
			choose_one_by_one_1rb_2rb(stack, nbr);
	}
	while (stack->a[0] < stack->a[stack->last_a])
		rra(stack);
}

int	choose_two_by_two_1rb_2rb(t_stack *stack, int nbr1, int nbr2)
{
	int	i;
	int	j;

	i = 0;
	j = stack->last_b - 1;
	while (i < (stack->size_b / 2) || (stack->size_b / 2) < j)
	{
		if (stack->b[j] == nbr1 || stack->b[j] == nbr2)
			return (rb(stack));
		else if (stack->b[i] == nbr1 || stack->b[i] == nbr2)
			return (rrb(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_two_by_two_directly(t_stack *stack)
{
	int	i;
	int	j;
	int	osa;
	int	osb;
	int	nbr_i;
	int	nbr_j;

	osa = stack->size_a;
	osb = stack->size_b;
	if (osb % 2 == 0)
	{
		i = osb / 2;
		j = i - 1;
	}
	else if (osb % 2 != 0)
	{
		i = osb / 2;
		j = i;
	}
	while (i < osb || j >= osa)
	{
		nbr_i = stack->sorted[i + osa];
		nbr_j = stack->sorted[j + osa];
		if (stack->b[stack->last_b] == nbr_i || stack->b[stack->last_b] == nbr_j)
		{
			if (stack->b[stack->last_b] == nbr_i)
			{
				pa(stack);
				i++;
			}
			else if (stack->b[stack->last_b] == nbr_j)
			{
				pa(stack);
				ra(stack);
				j--;
			}
		}
		else
			choose_two_by_two_1rb_2rb(stack, nbr_i, nbr_j);
	}
}

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
