/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/11 19:23:57 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	action(char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		ft_putendl_fd("sa", 1);
	else if (!ft_strncmp(str, "sb", 2))
		ft_putendl_fd("sb", 1);
	else if (!ft_strncmp(str, "ss", 2))
		ft_putendl_fd("ss", 1);
	else if (!ft_strncmp(str, "pa", 2))
		ft_putendl_fd("pa", 1);
	else if (!ft_strncmp(str, "pb", 2))
		ft_putendl_fd("pb", 1);
	else if (!ft_strncmp(str, "ra", 2))
		ft_putendl_fd("ra", 1);
	else if (!ft_strncmp(str, "rb", 2))
		ft_putendl_fd("rb", 1);
	else if (!ft_strncmp(str, "rra", 3))
		ft_putendl_fd("rra", 1);
	else if (!ft_strncmp(str, "rrb", 3))
		ft_putendl_fd("rrb", 1);
	else if (!ft_strncmp(str, "rrr", 3))
		ft_putendl_fd("rrr", 1);
	else if (!ft_strncmp(str, "rr", 2))
		ft_putendl_fd("rr", 1);
}

int	pa(t_stack *stack)
{
	if (0 < stack->size_b && stack->size_b <= stack->capacity)
	{
		stack->a[stack->last_a + 1] = stack->b[stack->last_b];
		stack->size_a++;
		stack->size_b--;
		stack->last_a++;
		stack->last_b--;
		action("pa");
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
		action("pb");
		return (1);
	}
	return (0);
}
