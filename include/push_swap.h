/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:26 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/10 22:53:17 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

#include <stdio.h> // to remove
#include <time.h> // to remove
typedef struct s_stack
{
	int	msect;
	int	lsect;
	int	*maxlimit;
	int	*lowlimit;
	int	capacity;
	int	size_a;
	int	size_b;
	int	last_a;
	int	last_b;
	int	*a;
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

void	action(t_stack *stack, char *str);
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

void	get_the_sorted_list(t_stack *stack);

void	sorting_2(t_stack *stack);
void	sorting_3(t_stack *stack);
void	sorting_4(t_stack *stack);
void	sorting_5_50(t_stack *stack);
void	sorting_51_350(t_stack *stack);
void	sorting_351(t_stack *stack);
void	first_sort(t_stack *stack);
void	second_sort(t_stack *stack);
void	choose_sorting(t_stack *stack);

int		get_section(t_stack *stack, int size);
int		get_n_section(t_stack *stack, int i);
void	three_sort(t_stack *stack);
void	five_three_sort(t_stack *stack);

void	set_limitations(t_stack *stack, int size);

int		choose_1ra_2ra(t_stack *stack, int tofindlow, int tofindmax);
void	push_by_section_3(t_stack *stack);
void	push_by_section_three(t_stack *stack);
void	push_by_section_five(t_stack *stack);
void	restore_all(t_stack *stack);

void	hard_sort(t_stack *stack);

void	show(t_stack *stack, int clear); // should delete

#endif