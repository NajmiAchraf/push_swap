/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 21:41:28 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	create_stack(t_stack *stack, int capacity)
{
	stack->capacity = capacity - 1;
	stack->size_a = stack->capacity;
	stack->size_b = 0;
	stack->last_a = stack->capacity - 1;
	stack->last_b = -1;
	stack->a = (int *)malloc(stack->capacity * sizeof(int *));
	if (!stack->a)
	{
		free(stack);
		return ;
	}
	stack->b = (int *)malloc(stack->capacity * sizeof(int *));
	if (!stack->b)
	{
		free(stack->a);
		free(stack);
		return ;
	}
}

void fill_in(t_stack *stack, int ac, char *av[])
{
	int	 i;
	
	i = 0;
	while (--ac > 0)
	{
		stack->a[i] = ft_atoi(av[ac]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_stack	*stack;

	if (ac <= 2 || !arg_check(ac, av))
		exit(0);
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	create_stack(stack, ac);
	fill_in(stack, ac, av);
	get_the_sorted_list(stack);

	// show(stack, 0);

	choose_sorting(stack);
	// sort(stack);

	show(stack, 0);
	
	// system("leaks a.out");
	return (0);
}
