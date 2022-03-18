/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 03:22:18 by anajmi           ###   ########.fr       */
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
	if (!ft_strncmp(str, "sa", ft_strlen(str) - 1))
		return (sa(stack));
	else if (!ft_strncmp(str, "sb", ft_strlen(str) - 1))
		return (sb(stack));
	else if (!ft_strncmp(str, "ss", ft_strlen(str) - 1))
		return (ss(stack));
	else if (!ft_strncmp(str, "pa", ft_strlen(str) - 1))
		return (pa(stack));
	else if (!ft_strncmp(str, "pb", ft_strlen(str) - 1))
		return (pb(stack));
	else if (!ft_strncmp(str, "ra", ft_strlen(str) - 1))
		return (ra(stack));
	else if (!ft_strncmp(str, "rb", ft_strlen(str) - 1))
		return (rb(stack));
	else if (!ft_strncmp(str, "rra", ft_strlen(str) - 1))
		return (rra(stack));
	else if (!ft_strncmp(str, "rrb", ft_strlen(str) - 1))
		return (rrb(stack));
	else if (!ft_strncmp(str, "rrr", ft_strlen(str) - 1))
		return (rrr(stack));
	else if (!ft_strncmp(str, "rr", ft_strlen(str) - 1))
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
		return (0);
	if (!arg_check(ac, av))
		xite();
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	create_stack(stack, ac);
	fill_in(stack, ac, av);
	core(stack);
	if (stack->size_a == stack->capacity && sort_check(stack))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}
