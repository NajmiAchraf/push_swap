/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:33 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/09 19:46:52 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_section(t_stack *stack, int size)
{
	return (size/stack->msect);
}

int	get_n_section(t_stack *stack, int i)
{
	return (i*stack->msect);
}

void	three_sort(t_stack *stack)
{
	swap_b(stack);
	pa(stack);
	swap_b(stack);
	pa(stack);
	swap_a(stack);
	pa(stack);
}

void	five_three_sort(t_stack *stack)
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
		three_sort(stack);
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

void	seven_sort(t_stack *stack)
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
		five_sort(stack);
		rra(stack);
		i++;
	}
}

void	five_h_sort(t_stack *stack)
{
	int i;
	int j;
	int l;
	int m;
	
	i = 0;
	j = stack->capacity % stack->msect;
	while (i < stack->lsect)
	{
		l = stack->sorted[get_n_section(stack, i + 1) + j - 1];
		m = stack->sorted[get_n_section(stack, i) + j];
		rrb(stack);
		rrb(stack);
		if (m == stack->b[stack->last_b])
			pa(stack);
		if (l == stack->b[stack->last_b])
		{
			pa(stack);
			ra(stack);
		}
		if (m == stack->b[stack->last_b])
			pa(stack);
		three_sort(stack);
		rra(stack);
		i++;
	}
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
	int	j;

	i = 0;
	j = stack->last_a - 1;
	while (i < stack->size_a / 2 || stack->size_a / 2 < j)
	{
		if (tofindlow <= stack->a[j] && stack->a[j] <= tofindmax)
			return (ra(stack));
		else if (tofindlow <= stack->a[i] && stack->a[i] <= tofindmax)
			return (rra(stack));
		i++;
		j--;
	}
	return (0);
}

void	push_by_section_3(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lsect - 1;
	set_limitations(stack, stack->size_a);
	while (i >= 0)
	{
		j = 0;
		while (j < stack->msect)
		{
			if (stack->lowlimit[i] <= stack->a[stack->last_a] && stack->a[stack->last_a] <= stack->maxlimit[i])
			{
				pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, stack->lowlimit[i], stack->maxlimit[i]);
		}
		i--;
	}
}

void	push_by_section_5(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lsect - 1;
	set_limitations(stack, stack->size_a);
	while (i >= 0)
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

void	push_by_section_3h(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = stack->lsect - 1;
	k = stack->size_a % stack->msect;
	while (i > 0) // removed = to reduce moves
	{
		j = 0;
		l = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		m = stack->sorted[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->a[stack->last_a] && stack->a[stack->last_a] <= m)
			{
				pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, l, m);
		}
		i--;
	}
}

void	push_by_section_5h(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = stack->lsect - 1;
	k = stack->size_a % stack->msect;
	while (i >= 0)
	{
		j = 0;
		l = stack->sorted[get_n_section(stack, i + 1) + k - 1];
		m = stack->sorted[get_n_section(stack, i) + k];
		while (j < stack->msect)
		{
			if (l <= stack->a[stack->last_a] && stack->a[stack->last_a] <= m)
			{
				if (l == stack->a[stack->last_a] || m == stack->a[stack->last_a])
				{
					pb(stack);
					rb(stack);
				}
				else
					pb(stack);
				j++;
			}
			else
				choose_1ra_2ra(stack, l, m);
		}
		i--;
	}
}

void	restore_all(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->size_b;
	while (i > 0)
	{
		pa(stack);
		i--;
	}
}

void	sort(t_stack *stack)
{
	// stack->msect = the_sections(stack);
	stack->lsect = get_section(stack, stack->size_a);

	if (stack->msect == 3)
		push_by_section_3(stack);
	else if (stack->msect == 5)
		push_by_section_5(stack);
	else if (stack->msect == 7)
	{
		stack->msect = 100;
		stack->lsect = get_section(stack, stack->size_a);
		push_by_section_3h(stack);

		restore_all(stack);

		stack->msect = 5;
		stack->lsect = get_section(stack, stack->size_a);
		push_by_section_5h(stack);

		if (stack->size_a == 2)
			sorting_2(stack);
		else if (stack->size_a == 3)
			sorting_3(stack);
			
		five_h_sort(stack);
	}

	if (stack->size_a == 2)
		sorting_2(stack);
	else if (stack->size_a == 3)
		sorting_3(stack);
	// else if (stack->size_a == 4)
	// 	sorting_4(stack);

	// show(stack, 0);
	// getchar();
	// sa(stack);

	// fts(stack);
	// while (1)
	// {
	// 	// sort by two
	// 	// swaping(stack);
	// 	// pa(stack);
	// 	if (stack->msect == 3)
	// 		// sort by three
	// 		three_sort(stack);

	// 	if (stack->msect == 5)
	// 		// sort by five
	// 		five_three_sort(stack);
			
	// 	if (stack->msect == 7)
	// 	{
	// 		// sort by seven
	// 		// seven_sort(stack);
	// 	}
			

	// 	if (stack->size_a == stack->capacity)
	// 		break;
	// }
}
