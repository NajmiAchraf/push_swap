/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/07 22:35:56 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	tri_sort(t_stack *stack)
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
	int i, j, k;

	i = stack->lsect; // 21
	while (i >= 0 && stack->size_a <= stack->capacity)
	{
		j = stack->msect; // 5
		k = 0;
		while (j > 0)
		{
			if (stack->maxlimit[ i] == stack->b[stack->last_b])
				pa(stack), k++;
			if (i < stack->lsect)
			{
				if (stack->lowlimit[i] == stack->b[stack->last_b])
				{
					pa(stack);
					ra(stack);
					k++;
				}
			}
			else if (i == stack->lsect)
			{
				if (stack->maxlimit[i] < stack->b[stack->last_b])
				{
					pa(stack);
					ra(stack);
					k++;
				}
			}
			if (k == 2)
				break ;
			rb(stack);
			j--;
		}
		while (j < stack->msect)
		{
			rrb(stack);
			j++;
		}
		tri_sort(stack);
		rra(stack);
		i--;
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
		stack->maxlimit[i] = stack->sorted[get_n_section(stack, i + j)];
		printf("stack->maxlimit[%d] = %d <==== %d\n", i, stack->maxlimit[i], stack->sorted[get_n_section(stack, i + j)]);
		stack->lowlimit[i] = stack->sorted[get_n_section(stack, i + j + 1) - 1];
		printf("stack->lowlimit[%d] = %d <==== %d\n", i, stack->lowlimit[i], stack->sorted[get_n_section(stack, i + j + 1) - 1]);
		// printf("%d\n", j);
		i--;
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
// 		if (stack->a[stack->last_a] < stack->maxlimit[stack->lsect/2])
// 			pb(stack);
// 		else
// 			ra(stack);
// 		i--;
// 	}
// 	show(stack, 0);
// }

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
	int	sz;

	i = stack->lsect;
	set_limitations(stack, stack->size_a);
	while (i >= 0)//stack->lsect / 2)
	{
		j = 0;
		sz = stack->size_a;
		while (j <= sz)
		{
			if (stack->lowlimit[i] <= stack->a[stack->last_a] && stack->a[stack->last_a] <= stack->maxlimit[i])
				pb(stack);
			else
				choose_1ra_2ra(stack, stack->lowlimit[i], stack->maxlimit[i]);
			if (stack->lowlimit[i] <= stack->a[stack->last_a] && stack->a[stack->last_a] <= stack->maxlimit[i])
				pb(stack);
				// a_isort
			j++;
		}
		i--;
	}
}

void	sort(t_stack *stack)
{
	// int	i = 0;
	// stack->msect = the_sections(stack);
	// stack->msect = 3;
	stack->lsect = get_section(stack, stack->size_a);
	// stack->
	// push_half_b(stack);
	push_by_section(stack);
	// decrease_sort(stack);

	// show(stack, 0);
	// getchar();
	if (stack->size_a == 2)
		swaping(stack);
	show(stack, 0);
	getchar();
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
			five_sort(stack);

		// if (i % 3 == 0)
		//	 swaping(stack), i = 0;
		// else if (i % 3 == 1)
		// 	rotating(stack), i = 1;
		// else if (i % 3 == 2)
		// 	reverse_rotating(stack), i = 2;
		if (stack->size_a == stack->capacity)// && a_isortinv(stack))// || b_isortinv(stack))
			break;
		// i++;
	}
}
