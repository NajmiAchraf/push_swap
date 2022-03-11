/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_distro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:29:47 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 19:12:53 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_the_sorted_list(t_stack *stack)
{
	int	i;

	stack->sorted = (int *)malloc(stack->capacity * sizeof(int *));
	i = -1;
	while (++i < stack->size_a)
		stack->sorted[i] = stack->a[i];
	i = -1;
	while (++i < stack->last_a)
	{
		if (stack->sorted[i] < stack->sorted[i + 1])
		{
			swap(&stack->sorted[i], &stack->sorted[i + 1]);
			i = -1;
		}
	}
}

void	first_sort(t_stack *stack)
{
	if (stack->capacity == 2)
		sorting_2(stack);
	else if (stack->capacity == 3)
		sorting_3(stack);
	else if (stack->capacity == 4)
		sorting_4(stack);
}

void	second_sort(t_stack *stack)
{
	if (4 < stack->capacity && stack->capacity < 51)
		sorting_5_50(stack);
	else if (50 < stack->capacity && stack->capacity < 351)
		sorting_51_350(stack);
	else if (350 < stack->capacity)
		sorting_351(stack);
}

void	choose_sorting(t_stack *stack)
{
	if (stack->capacity < 5)
		first_sort(stack);
	else if (stack->capacity > 4)
		second_sort(stack);
}
