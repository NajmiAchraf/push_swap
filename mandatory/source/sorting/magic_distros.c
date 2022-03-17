/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_distros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/17 01:08:14 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
//////////////////////////
#include <stdio.h>
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

void	show(t_stack *stack, int clear)
{
	int	i, j;

	i = stack->capacity - 1;

	printf("\033[0;37m");
	printf("_________________________\n");
	while (0 <= i)
	{
		if (0 <= i && i <= stack->last_a)
		{
			if (stack->a[i] == stack->sorted[i])
				printf("|\033[0;32m");
			else if (stack->a[i] != stack->sorted[i])
				printf("|\033[0;31m");
			printf("%d", stack->a[i]);
			j = ft_int_length(stack->a[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
		}
		else
			printf("|           ");
		printf("\033[0;37m");
		if (0 <= i && i <= stack->last_b)
		{
			printf("|\033[0;33m");
			printf("%d", stack->b[i]);
			j = ft_int_length(stack->b[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
			printf("\033[0;37m|\n");
		}
		else
			printf("|           |\n");
		i--;
	}
	printf("|-----------------------|\n");
	printf("|a          |b          |\n");
	printf("|-----------------------|\n");

	usleep(1000);
	if (clear)
	{
		// getchar();
		system("clear");
	}
}

//////////////////////////////
void	sorting_5_50(t_stack *stack)
{
	stack->msect = 3;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	hard_sort(stack);
	while (stack->lsect > 0)
	{
		three_sort(stack);
		stack->lsect--;
	}
}

void	sorting_51_350(t_stack *stack)
{
	stack->msect = 10;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	hard_sort(stack);
	// push_one_by_one_directly(stack);
	// push_two_by_two_directly(stack);
	push_one_by_one_imp_directly(stack);
	// show(stack, 0);
	/* stack->msect = 30;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	stack->msect = 15;
	stack->lsect = get_section(stack, stack->size_b);
	push_by_section_up(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_fly(stack);
	hard_sort(stack);
	five_three_sort(stack); */
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

void	sorting_351(t_stack *stack)
{
	// stack->msect = 60;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_two_sections_down(stack);
	// restore_all(stack);
	// // stack->msect = 74;
	// // stack->lsect = get_section(stack, stack->size_b);
	// // push_by_section_up(stack);
	// stack->msect = 5;
	// stack->lsect = get_section(stack, stack->size_a);
	// push_by_two_sections_down(stack);
	// hard_sort(stack);
	// push_one_by_one_directly(stack);

	stack->msect = 125;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_two_sections_down(stack);
	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_b);
	push_by_section_up(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_fly(stack);
	hard_sort(stack);
	five_three_sort(stack); 

	/* stack->msect = 100;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_down(stack, stack->sorted);
	stack->msect = 25;
	stack->lsect = get_section(stack, stack->size_b);
	push_by_section_up(stack);
	stack->msect = 5;
	stack->lsect = get_section(stack, stack->size_a);
	push_by_section_fly(stack);
	hard_sort(stack);
	five_three_sort(stack); */
}
