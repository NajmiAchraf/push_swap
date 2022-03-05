/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/05 22:37:31 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tri_sort(t_stack *stack)
{
	swap_b(stack);
	pa(stack);
	swap_b(stack);
	pa(stack);
	swap_a(stack);
	pa(stack);
}

void	five_sort(t_stack *stack)
{
	pa(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pb(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pa(stack);
	swaping(stack);
	pb(stack);
	swaping(stack);
	pa(stack);
	pa(stack);
	pa(stack);
}

// int	the_sections(t_stack *stack)
// {
// 	int i;

// 	i = 20;
// 	while (i > 4)
// 	{
// 		// printf("%d%%%d=====>%d\n", stack->capacity, i, stack->capacity%i);
// 		if (stack->capacity%i == 0)
// 			return (i);
// 		i--;
// 	}
// 	return (10);
// }


int	the_sections(t_stack *stack)
{
	int i;

	i = 2;
	while (i < 100)
	{
		// printf("%d%%%d=====>%d\n", stack->capacity, i, stack->capacity%i);
		if (stack->capacity%i == 0)
			return (i);
		i++;
	}
	return (2);
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
	int	i;

	// printf ("++++++++++++++++++++++++>>>>>>>>>>>>>>>>>>>>>>>>>%lu\n", sizeof(stack->sorted));
	stack->sorted = (int *)malloc(stack->capacity * sizeof(int *));
	i = -1;
	while (++i < size)
		stack->sorted[i] = list[i];
	i = -1;
	while (++i <= size)
	{
		if (stack->sorted[i] < stack->sorted[i + 1])
		{
			swap(&stack->sorted[i], &stack->sorted[i + 1]);
			i = -1;
		}
	}
	// for (size_t i = 0; i < 71; i++)
	// {
	// 	printf("stack->sorted[%zu]=====> %d\n", i, stack->sorted[i]);
	// }
	stack->limit = (int *)malloc(stack->lsect * sizeof(int *));
	i = 0;
	printf("%d x %d = %d\n", stack->msect, i, size);
	while (i <= stack->lsect)
	{
		stack->limit[i] = stack->sorted[get_n_section(stack, i)];
		printf("stack->limit[%d] = %d <==== %d\n", i, stack->limit[i], stack->sorted[get_n_section(stack, i)]);
		i++;
	}

	getchar();
}

// void	push_half_b(t_stack *stack)
// {
// 	int	i;

// 	i = stack->size_a;
// 	set_limitations(stack, stack->a, stack->size_a);
// 	while (i >= 0)
// 	{
// 		if (stack->a[stack->last_a] < stack->limit[stack->lsect/2])
// 			pb(stack);
// 		else
// 			ra(stack);
// 		i--;
// 	}
// 	show(stack, 0);
// }

int	choose_1ra_2ra(t_stack *stack, int tofind)
{
	int	i;

	i = 0;
	while (i < stack->size_a / 2)
	{
		if (stack->a[i] < tofind)
			return (1);
		i++;
	}
	return (0);
}

void	push_by_section(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->lsect;
	set_limitations(stack, stack->a, stack->size_a);
	while (j >= 0)//stack->lsect / 2)
	{
		i = 0;
		while (i < stack->size_a)
		{
			if (stack->a[stack->last_a] <= stack->limit[j])
				pb(stack);
			else
			{
				if (choose_1ra_2ra(stack, stack->limit[j]))
					rra(stack);
				else
					ra(stack);
			}
			i++;
			// show(stack, 1);
		}
		j--;
	}
}

void	sort(t_stack *stack)
{
	// int	i = 0;
	// stack->msect = the_sections(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	// stack->
	// push_half_b(stack);
	push_by_section(stack);
	// decrease_sort(stack);

	show(stack, 0);
	getchar();
	// swaping(stack);
	// show(stack, 0);
	// getchar();
	// sa(stack);
	while (1)
	{
		// sort by two
		// swaping(stack);
		// pa(stack);
		
		// sort by three
		// tri_sort(stack);
		
		// sort by five
		five_sort(stack);

		// if (i % 3 == 0)
		//	 swaping(stack), i = 0;
		// else if (i % 3 == 1)
		// 	rotating(stack), i = 1;
		// else if (i % 3 == 2)
		// 	reverse_rotating(stack), i = 2;
		if (stack->size_a == stack->capacity)// && a_isortinv(stack))// || b_isortinv(stack))
			break;
		show(stack, 1);
		// i++;
	}
}
