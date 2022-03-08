/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/08 20:59:06 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	tri_sort(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->lsect)
	{
		rrb(stack);
		rrb(stack);
		if (stack->maxlimit[i] == stack->b[stack->last_b])
			pa(stack);
		if (stack->lowlimit[i] == stack->b[stack->last_b])
		{
			pa(stack);
			ra(stack);
		}
		if (stack->maxlimit[i] == stack->b[stack->last_b])
			pa(stack);
		pa(stack);
		rra(stack);
		i++;
	}
}

void	tls_sort(t_stack *stack)
{
	swap_b(stack);
	pa(stack);
	swap_b(stack);
	pa(stack);
	swap_a(stack);
	pa(stack);
}

void	fts(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->lsect)
	{
		rrb(stack);
		rrb(stack);
		if (stack->maxlimit[i] == stack->b[stack->last_b])
			pa(stack);
		if (stack->lowlimit[i] == stack->b[stack->last_b])
		{
			pa(stack);
			ra(stack);
		}
		if (stack->maxlimit[i] == stack->b[stack->last_b])
			pa(stack);
		tls_sort(stack);
		rra(stack);
		i++;
	}
}

void	five_sort(t_stack *stack)
{
	swaping(stack);
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
	pb(stack);
	
	swaping(stack);
	pa(stack);
	pa(stack);
	pa(stack);
}

void	twelve_sort(t_stack *stack)
{
	swaping(stack);
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
	pb(stack);
	
	swaping(stack);
	pa(stack);
	pa(stack);
	pa(stack);
}

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


void	set_limitations(t_stack *stack, int size)
{
	int	i;
	int	j;

	stack->lowlimit = (int *)malloc(stack->lsect * sizeof(int *));
	stack->maxlimit = (int *)malloc(stack->lsect * sizeof(int *));
	i = stack->lsect;
	j = stack->size_a % stack->msect;
	// printf("%d x %d = %d\n", stack->msect, stack->lsect, size);
	while (i >= 0)
	{
		stack->lowlimit[i] = stack->sorted[get_n_section(stack, i + 1) + j - 1];
		// printf("stack->lowlimit[%d] = %d <==== %d\n", i, stack->lowlimit[i], stack->sorted[get_n_section(stack, i + 1) + j - 1]);
		stack->maxlimit[i] = stack->sorted[get_n_section(stack, i) + j];
		// printf("stack->maxlimit[%d] = %d <==== %d\n", i, stack->maxlimit[i], stack->sorted[get_n_section(stack, i) + j]);
		// printf("%d\n", j);
		i--;
	}
	// getchar();
}

int	choose_1ra_2ra(t_stack *stack, int tofindlow, int tofindmax)
{
	int	i;

	i = 0;
	while (i < stack->size_a / 2)
	{
		if (tofindlow <= stack->a[i] && stack->a[i] <= tofindmax)
			return (rra(stack));
		i++;
	}
	return (ra(stack));
}

void	push_by_section(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lsect - 1;
	// printf("i ====== %d\n", i);
	// printf("stack->lsect ====== %d\n", stack->lsect);
	// printf("stack->msect ====== %d\n", stack->msect);
	// getchar();
	set_limitations(stack, stack->size_a);
	while (i >= 0)//stack->lsect / 2)
	{
		j = 0;
		while (j < stack->msect)
		{
			if (stack->lowlimit[i] <= stack->a[stack->last_a] && stack->a[stack->last_a] <= stack->maxlimit[i])
			{
				
				if (stack->lowlimit[i] == stack->a[stack->last_a] || stack->maxlimit[i] == stack->a[stack->last_a])
				{
					pb(stack);
					rb(stack);
				}
				else
					pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, stack->lowlimit[i], stack->maxlimit[i]);
		}
		i--;
	}
}

void	sort(t_stack *stack)
{
	// stack->msect = the_sections(stack);
	stack->lsect = get_section(stack, stack->size_a);
	// push_half_b(stack);
	push_by_section(stack);
	// decrease_sort(stack);

	// show(stack, 0);
	// getchar();
	if (stack->size_a == 2)
		sorting_2(stack);
	else if (stack->size_a == 3)
		sorting_3(stack);
	// show(stack, 0);
	// getchar();
	// sa(stack);

	// fts(stack);
	while (1)
	{
		// sort by two
		// swaping(stack);
		// pa(stack);
		if (stack->msect == 3)
			// sort by three
			tri_sort(stack);

		if (stack->msect == 5)
			// sort by five
			// five_sort(stack);
			fts(stack);
			

		if (stack->msect == 12)
			// sort by twelve
			twelve_sort(stack);

		if (stack->size_a == stack->capacity)
			break;
	}
}
