/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/03 18:27:16 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	the_sections(t_stack *stack)
{
	int i;

	i = 20;
	while (i > 4)
	{
		// printf("%d%%%d=====>%d\n", stack->capacity, i, stack->capacity%i);
		if (stack->capacity%i == 0)
			return (i);
		i--;
	}
	return (10);
}

int	get_section(t_stack *stack, int size)
{
	return (size/stack->msect);
}

int	get_n_section(t_stack *stack, int i)
{
	return (i*stack->msect);
}

void	set_limitations(t_stack *stack, int *list, int size)
{
	int	arr[size];
	int	i;

	// printf ("++++++++++++++++++++++++>>>>>>>>>>>>>>>>>>>>>>>>>%lu\n", sizeof(arr));
	i = -1;
	while (++i < size)
		arr[i] = list[i];
	i = -1;
	while (++i <= size)
	{
		if (arr[i] < arr[i + 1])
		{
			swap(&arr[i], &arr[i + 1]);
			i = -1;
		}
	}
	// for (size_t i = 0; i < 71; i++)
	// {
	// 	printf("arr[%zu]=====> %d\n", i, arr[i]);
	// }
	stack->limit = (int *)malloc(stack->lsect * sizeof(int *));
	i = stack->lsect;
	// printf("%d x %d = %d\n", stack->msect, i, size);
	while (i >= 0)
	{
		stack->limit[i] = arr[get_n_section(stack, i)];
		// printf("stack->limit[%d] = %d <==== %d\n", i, stack->limit[i], arr[get_n_section(stack, i)]);
		i--;
	}
}

void	push_half_b(t_stack *stack)
{
	int	i;

	i = stack->size_a;
	set_limitations(stack, stack->a, stack->size_a);
	while (i >= 0)
	{
		if (stack->a[stack->last_a] < stack->limit[stack->lsect/2])
			pb(stack);
		else
			ra(stack);
		i--;
	}
	show(stack, 0);
}

void	push_by_section(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->size_a;
	j = 0;
	set_limitations(stack, stack->a, stack->size_a);
	while (i >= 0)
	{
		while (j < stack->lsect)
		{
			if (stack->a[stack->last_a] < stack->limit[j])
				pb(stack);
			else
				ra(stack);
			j++;
		}
		i--;
	}
	show(stack, 0);
}

void	sort(t_stack *stack)
{
	int	i = 0;
	stack->msect = the_sections(stack);
	stack->lsect = get_section(stack, stack->size_a);
	// stack->
	// push_half_b(stack);
	push_by_section(stack);
	while (1)
	{
		// if (i % 3 == 0)
		// 	swaping(stack), i = 0;
		// else if (i % 3 == 1)
		// 	rotating(stack), i = 1;
		// else if (i % 3 == 2)
		// 	reverse_rotating(stack), i = 2;
		if (a_isort(stack) || b_isortinv(stack))
			break;
		show(stack, 1);
		i++;
	}
}
