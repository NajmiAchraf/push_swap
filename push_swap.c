/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:05 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/28 14:23:19 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

t_stack	*create_stack(t_stack *stack, int capacity)
{
	stack->capacity = capacity - 1;
	stack->size_a = stack->capacity;
	stack->size_b = 0;
	stack->last_a = stack->capacity - 1;
	stack->last_b = -1;
	stack->a = (int *)malloc(stack->capacity * sizeof(int *));
	stack->b = (int *)malloc(stack->capacity * sizeof(int *));
	return (stack);
}

t_stack *fill_in(t_stack *stack, int ac, char *av[])
{
	int	 i;
	
	i = 0;
	while (--ac > 0)
	{
		stack->a[i] = ft_atoi(av[ac]);
		i++;
	}
	return (stack);
}

static void	show0(t_stack *stack, int ac)
{
	int	i, j, k;
	i = 0;
	j = 0;
	k = ac - 1;
	printf("-------------------------------------------------------------\n");
	printf("a | |");
	while (0 <= k)
	{
		if (stack->last_a >= i)
		{
			printf("\t\t%d |", stack->a[i]);
			i++;
		}
		else
			printf("		  |");
		k--;
	}
	printf("\nb | | ");
	k = ac - 1;
	while (0 <= k)
	{
		if (stack->last_b >= j)
		{
			printf("\t\t%d |", stack->b[j]);
			j++;
		}
		else
			printf("		  |");
		k--;
	}
	printf("\n");
}

static int	ft_int_length(long value)
{
	int	l;

	l = 1;
	if (value < 0)
	{
		value *= (-1);
		l += 1;
	}
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}

static void	show(t_stack *stack)
{
	int	i, j, k;

	i = stack->capacity - 1;
	j = i;
	k = j;
	printf("_______________________\n");
	while (0 <= k)
	{
		if (0 <= i && i <= stack->last_a)
		{
			if (ft_int_length(stack->a[i]) == 1)
				printf("|%d         ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 2)
				printf("|%d        ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 3)
				printf("|%d       ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 4)
				printf("|%d      ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 5)
				printf("|%d     ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 6)
				printf("|%d    ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 7)
				printf("|%d   ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 8)
				printf("|%d  ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 9)
				printf("|%d ", stack->a[i]);
			else if (ft_int_length(stack->a[i]) == 10)
				printf("|%d", stack->a[i]);
		}
		else
			printf("|          ");
		if (0 <= j && j <= stack->last_b)
		{
			if (ft_int_length(stack->b[j]) == 1)
				printf("|%d         |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 2)
				printf("|%d        |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 3)
				printf("|%d       |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 4)
				printf("|%d      |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 5)
				printf("|%d     |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 6)
				printf("|%d    |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 7)
				printf("|%d   |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 8)
				printf("|%d  |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 9)
				printf("|%d |\n", stack->b[j]);
			else if (ft_int_length(stack->b[j]) == 10)
				printf("|%d|\n", stack->b[j]);
		}
		else
			printf("|          |\n");
			i--;
		j--;
		k--;
	}
	printf("|---------------------|\n");
	printf("|a         |b         |\n");
	printf("|---------------------|\n");

	// getchar();
	// system("clear");
}

void	try0(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (save > stack->a[stack->last_a])
		{
			save = stack->a[stack->last_a];
			pb(stack);
			i = stack->size_a + 1;
		}
		else
		{
			ra(stack);
		}
	}
}

void	try1(t_stack *stack)
{
	int	save = INT32_MIN;
	int	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (save < stack->a[stack->last_a])
		{
			save = stack->a[stack->last_a];
			pb(stack);
			i = stack->size_a + 1;
		}
		else
		{
			ra(stack);
		}
	}
}

int	stack_is_not_empty(t_stack *stack)
{
	if (stack->size_b > 0 && stack->size_a > 0)
		return (1);
	return (0);
}

void	try00(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i;
	int	j;

	try0(stack);
	i = stack->size_a + 1;
	while (--i >= 0)
	{
		// if (stack->a[stack->last_a - 1])
		if (stack->b[stack->last_b] < stack->a[stack->last_a] && stack_is_not_empty(stack))
		{
			pa(stack);
			ra(stack);
			i = stack->size_a + 1;
		}
		else if (stack->b[stack->last_b] > stack->a[stack->last_a] && stack_is_not_empty(stack))
		{
			ra(stack);
		}
		if (stack->size_b == 0)
		{
			printf("pass0-----------------------\n");
			try0(stack);
			i = stack->size_a + 1;
		}
	}
	show(stack);
}

void	try11(t_stack *stack)
{
	int	save = INT32_MAX;
	int	i;
	try1(stack);
	i = stack->size_a + 1;
	while (--i >= 0)
	{
		if (stack->b[stack->last_b] < stack->a[stack->last_a] && stack_is_not_empty(stack))
		{
			pa(stack);
			ra(stack);
			i = stack->size_a + 1;
		}
		else if (stack->b[stack->last_b] > stack->a[stack->last_a] && stack_is_not_empty(stack))
		{
			pa(stack);
			sa(stack);
			i = stack->size_a + 1;
		}
		if (stack->size_b == 0)
		{
			printf("pass1-----------------------\n");
			try1(stack);
			i = stack->size_a + 1;
		}
	}
	show(stack);
}

int	main(int ac, char *av[])
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (ac <= 2 || !arg_check(ac, av))
		exit(0);
	stack = create_stack(stack, ac);
	fill_in(stack, ac, av);
	show(stack);
	try00(stack);
	show(stack);
	try11(stack);
	// sa(stack);
	// sb(stack);
	// ss(stack);
	// pa(stack);
	// pb(stack);
	// ra(stack);
	// rb(stack);
	// rr(stack);
	// rra(stack);
	// rrb(stack);
	// rrr(stack);
	// show(stack);
	return (0);
}
