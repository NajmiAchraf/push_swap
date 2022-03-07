/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crease.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:23:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 16:30:39 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	increase2b(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (save > stack->a[stack->last_a])
		{
			save = stack->a[stack->last_a];
			pb(stack);
			i = stack->size_a + 1;
		}
		else
		{
			ra(stack);
		}
	}
}

void	decrease2b(t_stack *stack)
{
	int	save = INT32_MIN;
	int	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (save < stack->a[stack->last_a])
		{
			save = stack->a[stack->last_a];
			pb(stack);
			i = stack->size_a + 1;
		}
		else
		{
			ra(stack);
		}
	}
}

int	empty_stacks(t_stack *stack)
{
	if (stack->size_b > 0 && stack->size_a > 0)
		return (0);
	return (1);
}

void	increase_sort(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i;
	int	j;

	increase2b(stack);
	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (stack->b[stack->last_b] < stack->a[stack->last_a] && !empty_stacks(stack))
		{
			pa(stack);
			ra(stack);
			i = stack->size_a + 1;
		}
		else if (stack->b[stack->last_b] > stack->a[stack->last_a] && !empty_stacks(stack))
		{
			// pb(stack);
			ra(stack);
			// i = stack->size_a + 1;
		}
		if (stack->size_b == 0 )
		{
			printf("pass0-----------------------\n");
			increase2b(stack);
			i = stack->size_a + 1;
		}
		show(stack, 1);
	}
	show(stack, 0);
}

void	decrease_sort(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i;
	decrease2b(stack);
	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (stack->b[stack->last_b] < stack->a[stack->last_a] && !empty_stacks(stack))
		{
			pa(stack);
			ra(stack);
			i = stack->size_a + 1;
		}
		else if (stack->b[stack->last_b] > stack->a[stack->last_a] && !empty_stacks(stack))
		{
			pa(stack);
			sa(stack);
			i = stack->size_a + 1;
		}
		if (stack->size_b == 0)
		{
			printf("pass1-----------------------\n");
			decrease2b(stack);
			i = stack->size_a + 1;
		}
		show(stack, 1);
	}
	show(stack, 0);
	printf("===>%d\n", b_isort(stack));
}
