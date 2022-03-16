/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:51 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/14 19:59:43 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][0] == '-' || av[i][0] == '+'))
			{
				if (!ft_isdigit(av[i][1]))
					return (0);
			}
			else
			{
				if (!ft_isdigit(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_double(int ac, char **av)
{
	int	check;
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		check = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[j]) == check)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_limit_int(int ac, char **av)
{
	int		i;
	long	check;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) >= 10)
		{
			check = ft_atoi(av[i]);
			if (check == 0 || check == -1)
				return (0);
		}
		if (av[i][0] == '\0' || av[i][0] == ' '
			|| (9 <= av[i][0] && av[i][0] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	arg_check(int ac, char **av)
{
	int	check[3];

	check[0] = check_digit(ac, av);
	check[1] = check_double(ac, av);
	check[2] = check_limit_int(ac, av);
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
		return (0);
	return (1);
}

int	sort_check(t_stack *stack)
{
	int	i;

	if (stack->size_a <= 1)
		return (0);
	i = stack->size_a;
	while (i > 0)
	{
		if (stack->a[i] > stack->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
