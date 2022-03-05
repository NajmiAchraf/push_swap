/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:26 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/05 21:58:36 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Libft/libft.h"

#include <stdio.h> // to remove
#include <time.h> // to remove
typedef struct	s_stack
{
	int	msect;
	int	lsect;
	int	*limit;
	int capacity;
	int	size_a;
	int	size_b;
	int	last_a;
	int	last_b;
	int *a;
	int	*b;
	int	*sorted;
}				t_stack;

void	create_stack(t_stack *stack, int capacity);
void	fill_in(t_stack *stack, int ac, char *av[]);

int		arg_check(int ac, char **av);

int		a_isortinv(t_stack *stack);
int		a_isort(t_stack *stack);
int		b_isortinv(t_stack *stack);
int		b_isort(t_stack *stack);

void	action(char *str);
void	swap(int *n1, int *n2);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);
int		pa(t_stack *stack);
int		pb(t_stack *stack);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack);
int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *stack);

int		swap_a(t_stack *stack);
int		swap_b(t_stack *stack);
int		swap_ab(t_stack *stack);
void	swaping(t_stack *stack);

void	pp(t_stack *stack);

int		rotate_a(t_stack *stack);
int		rotate_b(t_stack *stack);
int		rotate_ab(t_stack *stack);
void	rotating(t_stack *stack);

int		reverse_rotate_a(t_stack *stack);
int		reverse_rotate_b(t_stack *stack);
int		reverse_rotate_ab(t_stack *stack);
void	reverse_rotating(t_stack *stack);

void	push_half_b(t_stack *stack);
void	sort(t_stack *stack);

void	increase2b(t_stack *stack);
void	decrease2b(t_stack *stack);
int		empty_stacks(t_stack *stack);
void	increase_sort(t_stack *stack);
void	decrease_sort(t_stack *stack);

void	show(t_stack *stack, int clear);

#endif