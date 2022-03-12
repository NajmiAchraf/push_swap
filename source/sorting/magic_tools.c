/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/12 15:28:13 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_section(t_stack *stack, int size)
{
	return (size / stack->msect);
}

int	get_n_section(t_stack *stack, int i)
{
	return (i * stack->msect);
}
