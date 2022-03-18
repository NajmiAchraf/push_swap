/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 19:17:48 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	choose_one_by_one_rb_rrb(t_stack *stack, int nbr)
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

static void	core_push_directly(t_stack *stack, t_var *v)
{
	if (stack->b[stack->last_b] == v->nbr)
	{
		pa(stack);
		v->i++;
	}
	else if (stack->size_a > 0 && stack->size_b != 0
		&& ((v->j == -1 && stack->b[stack->last_b] < stack->a[0])
			|| (v->j > -1 && stack->b[stack->last_b] > stack->a[0])))
	{
		pa(stack);
		ra(stack);
		v->j++;
	}
	else if (stack->a[0] == v->nbr)
	{
		rra(stack);
		v->i++;
		v->j--;
	}
	else
		choose_one_by_one_rb_rrb(stack, v->nbr);
}

void	push_one_by_one_directly(t_stack *stack)
{
	t_var	v;

	v.i = 0;
	v.j = -1;
	v.sa = stack->size_a;
	v.sb = stack->size_b;
	while (v.i < v.sb)
	{
		v.nbr = stack->sorted[v.i + v.sa];
		core_push_directly(stack, &v);
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
