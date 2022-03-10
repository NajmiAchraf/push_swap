/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/09 23:12:03 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_section(t_stack *stack, int size)
{
	return (size/stack->msect);
}

int	get_n_section(t_stack *stack, int i)
{
	return (i*stack->msect);
}

void	set_limitations(t_stack *stack, int size)
{
	int	i;
	int	j;

	stack->lowlimit = (int *)malloc(stack->lsect * sizeof(int *));
	stack->maxlimit = (int *)malloc(stack->lsect * sizeof(int *));
	i = stack->lsect;
	j = stack->size_a % stack->msect;
	while (i >= 0)
	{
		stack->lowlimit[i] = stack->sorted[get_n_section(stack, i + 1) + j - 1];
		stack->maxlimit[i] = stack->sorted[get_n_section(stack, i) + j];
		i--;
	}
}
