/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:22:26 by anajmi            #+#    #+#             */
/*   Updated: 2022/03/13 19:36:43 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

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
}				t_stack;

void	create_stack(t_stack *stack, int capacity);
void	fill_in(t_stack *stack, int ac, char *av[]);

int		arg_check(int ac, char **av);
int		sort_check(t_stack *stack);

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

#endif
