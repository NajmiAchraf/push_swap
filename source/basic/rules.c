/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:55:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/09 16:54:14 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	action(t_stack *stack, char *str)
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
	// show(stack, 1);
}

int	sa(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		swap(&stack->a[stack->last_a], &stack->a[stack->last_a - 1]);
		action(stack, "sa");
		return (1);
	}
	return (0);
}

int	sb(t_stack *stack)
{
	if (stack->size_b > 1)
	{
		swap(&stack->b[stack->last_b], &stack->b[stack->last_b - 1]);
		action(stack, "sb");
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
		action(stack, "ss");
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
		action(stack, "pa");
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
		action(stack, "pb");
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
		action(stack, "ra");
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
		action(stack, "rb\n");
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
		action(stack, "rr");
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
		action(stack, "rra");
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
		action(stack, "rrb");
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
		action(stack, "rrr");
		return (1);
	}
	return (0);
}
