/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/03 18:31:25 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
	ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
	rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
	rrr : rra and rrb at the same time.
*/

void	action(char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		printf("sa\n");
	else if (!ft_strncmp(str, "sb", 2))
		printf("sb\n");
	else if (!ft_strncmp(str, "ss", 2))
		printf("ss\n");
	else if (!ft_strncmp(str, "pa", 2))
		printf("pa\n");
	else if (!ft_strncmp(str, "pb", 2))
		printf("pb\n");
	else if (!ft_strncmp(str, "ra", 2))
		printf("ra\n");
	else if (!ft_strncmp(str, "rb", 2))
		printf("rb\n");
	else if (!ft_strncmp(str, "rra", 3))
		printf("rra\n");
	else if (!ft_strncmp(str, "rrb", 3))
		printf("rrb\n");
	else if (!ft_strncmp(str, "rrr", 3))
		printf("rrr\n");
	else if (!ft_strncmp(str, "rr", 2))
		printf("rr\n");
}

int	sa(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		action("sa");
		return (1);
	}
	return (0);
}

int	sb(t_stack *stack)
{
	if (stack->size_b > 1)
	{
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
		action("sb");
		return (1);
	}
	return (0);
}

int	ss(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
		action("ss");
		return (1);
	}
	return (0);
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

int	ra(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_a)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i++;
			j++;
		}
		action("ra");
		return (1);
	}
	return (0);
}

int	rb(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_b > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_b)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i++;
			j++;
		}
		action("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = 0;
		j = 1;
		while (j < stack->size_a)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i++;
			j++;
		}
		i = 0;
		j = 1;
		while (j < stack->size_b)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i++;
			j++;
		}
		action("rr");
		return (1);
	}
	return (0);
}

int	rra(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1)
	{
		i = stack->last_a;
		j = stack->last_a - 1;
		while (j >= 0)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i--;
			j--;
		}
		action("rra");
		return (1);
	}
	return (0);
}

int	rrb(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_b > 1)
	{
		i = stack->last_b;
		j = stack->last_b - 1;
		while (j >= 0)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i--;
			j--;
		}
		action("rrb");
		return (1);
	}
	return (0);
}

int	rrr(t_stack *stack)
{
	int	i;
	int	j;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		i = stack->last_a;
		j = stack->last_a - 1;
		while (j >= 0)
		{
			swap(&stack->a[stack->last_a - i], &stack->a[stack->last_a - j]);
			i--;
			j--;
		}
		i = stack->last_b;
		j = stack->last_b - 1;
		while (j >= 0)
		{
			swap(&stack->b[stack->last_b - i], &stack->b[stack->last_b - j]);
			i--;
			j--;
		}
		action("rrr");
		return (1);
	}
	return (0);
}
