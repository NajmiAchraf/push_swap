/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 01:23:39 by anajmi           ###   ########.fr       */
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

void	push_one_by_one_directly(t_stack *stack)
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
		else if (stack->size_a > 0 && stack->size_b != 0
			&& ((j == -1 && stack->b[stack->last_b] < stack->a[0])
				|| (j > -1 && stack->b[stack->last_b] > stack->a[0])))
		{
			pa(stack);
			ra(stack);
			j++;
		}
		else if (stack->a[0] == nbr)
		{
			rra(stack);
			i++;
			j--;
		}
		else
			choose_one_by_one_rb_rrb(stack, nbr);
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
