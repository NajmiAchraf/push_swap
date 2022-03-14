/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 18:16:11 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

int	pa(t_stack *stack)
{
	if (0 < stack->size_b && stack->size_b <= stack->capacity)
	{
		stack->a[stack->last_a + 1] = stack->b[stack->last_b];
		stack->size_a++;
		stack->size_b--;
		stack->last_a++;
		stack->last_b--;
		return (1);
	}
	return (0);
}

int	pb(t_stack *stack)
{
	if (0 < stack->size_a && stack->size_a <= stack->capacity)
	{
		stack->b[stack->last_b + 1] = stack->a[stack->last_a];
		stack->size_b++;
		stack->size_a--;
		stack->last_b++;
		stack->last_a--;
		return (1);
	}
	return (0);
}
