/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 19:39:36 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/checker_bonus.h"

static void	xite(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

static int	action(t_stack *stack, char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		return (sa(stack));
	else if (!ft_strncmp(str, "sb", 2))
		return (sb(stack));
	else if (!ft_strncmp(str, "ss", 2))
		return (ss(stack));
	else if (!ft_strncmp(str, "pa", 2))
		return (pa(stack));
	else if (!ft_strncmp(str, "pb", 2))
		return (pb(stack));
	else if (!ft_strncmp(str, "ra", 2))
		return (ra(stack));
	else if (!ft_strncmp(str, "rb", 2))
		return (rb(stack));
	else if (!ft_strncmp(str, "rra", 3))
		return (rra(stack));
	else if (!ft_strncmp(str, "rrb", 3))
		return (rrb(stack));
	else if (!ft_strncmp(str, "rrr", 3))
		return (rrr(stack));
	else if (!ft_strncmp(str, "rr", 2))
		return (rr(stack));
	xite();
	return (0);
}

static void	core(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		action(stack, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char *av[])
{
	t_stack	*stack;

	if (ac <= 1)
		exit(0);
	if (!arg_check(ac, av))
		xite();
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	create_stack(stack, ac);
	fill_in(stack, ac, av);
	core(stack);
	if ((stack->size_a == stack->capacity && sort_check(stack))
		|| stack->size_a == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}
