/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:50:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/28 22:50:05 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushing(t_stack *stack)
{
	if (stack->a[stack->last_a] < stack->b[stack->last_b])
	{
		pa(stack);
		sa(stack);
		pb(stack);
	}
}