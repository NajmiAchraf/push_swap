/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:26 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/18 19:10:08 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../Libft/libft.h"

typedef struct s_stack
{
	int	msect;
	int	lsect;
	int	capacity;
	int	size_a;
	int	size_b;
	int	last_a;
	int	last_b;
	int	*a;
	int	*b;
	int	*sorted;
	int	*hard_sorted;
}				t_stack;

typedef struct s_var
{
	int	minup;
	int	maxup;
	int	mindown;
	int	maxdown;
	int	nbr;
	int	sa;
	int	sb;
	int	s1;
	int	s2;
	int	i;
	int	j;
	int	k;

}				t_var;

void	create_stack(t_stack *stack, int capacity);
void	fill_in(t_stack *stack, int ac, char *av[]);

int		arg_check(int ac, char **av);
int		sort_check(t_stack *stack);

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

int		*get_the_sorted_list(t_stack *stack);

void	sorting_2(t_stack *stack);
void	sorting_3(t_stack *stack);
void	sorting_4(t_stack *stack);
void	sorting_up(t_stack *stack);
void	hard_sort(t_stack *stack);

void	sorting_5_50(t_stack *stack);
void	sorting_51_350(t_stack *stack);
void	sorting_351(t_stack *stack);

void	first_sort(t_stack *stack);
void	second_sort(t_stack *stack);
void	choose_sorting(t_stack *stack);

int		get_section(t_stack *stack, int size);
int		get_n_section(t_stack *stack, int i);

int		choose_by_two_sections_ra_rra(t_stack *stack, t_var *v);
void	push_by_two_sections_down(t_stack *stack);

int		choose_by_section_ra_rra(t_stack *stack, int min, int max);
void	push_by_section_down(t_stack *stack, int *sorted_list);

void	three_sort(t_stack *stack);

int		choose_one_by_one_rb_rrb(t_stack *stack, int nbr);
void	push_one_by_one_directly(t_stack *stack);

#endif