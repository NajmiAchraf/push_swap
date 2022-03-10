/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:51 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/10 22:31:24 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
			if (j == 0)
			{
				if (!ft_isdigit(av[i][0]) && av[i][0] != '-' && av[i][0] != '+')
					j = 0;
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

static int	check_maxint(int ac, char **av)
{
	int	i;
	int	check;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) >= 9)
		{
			check = ft_atoi(av[i]);
			if (check <= 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	arg_check(int ac, char **av)
{
	int	check[3];

	check[0] = check_digit(ac, av);
	if (!check[0])
		ft_putstr_fd("error not integer\n", 2);
	check[1] = check_double(ac, av);
	if (!check[1])
		ft_putstr_fd("error double argument\n", 2);
	check[2] = check_maxint(ac, av);
	if (!check[2])
		ft_putstr_fd("error max integer\n", 2);
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
		return (0);
	return (1);
}