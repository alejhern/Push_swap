/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:26 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/09 22:48:05 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stacks
{
	char	**stack_a;
	char	**stack_b;
	int		size_a;
	int		size_b;
	int		move_count;
	int		*sorted_values;
	int		chunks;
	int		group_size;
}			t_stacks;

/*
** Declarations from ps_stack_utils.c
*/
char		**build_stack(int argc, char **argv);
int			is_sorted(char **stack);
void		free_stack(char **stack);
void		error_exit(const char *msg);

/*
** Declarations from ps_utils.c
*/
int			calculate_cost(int size, int pos);
long		*get_sorted_values(t_stacks *stacks, int total_size);
int			has_values_in_range(char **stack, int size, long min, long max);

/*
** Declarations from ps_sort_utils.c
*/
long		find_max_value(char **stack);
long		find_min_value(char **stack);
int			find_position(char **stack, int size, long value, int mode);
int			find_closest_in_range(char **stack, int size, long min, long max);

/*
** Declarations from ps_simple_sort.c
*/
void		simple_sort(t_stacks *stacks);

/*
** Declarations from ps_turk_sort.c
*/
void		turk_sort(t_stacks *stacks);

/*
** Declarations from ps_moves.c
*/
int			swap(char **stack, int size);
int			rotate(char **stack, int size);
int			rotate_reverse(char **stack, int size);
int			push(char ***stack1, char ***stack2, int size_1, int size_2);

/*
** Declarations from ps_swaper.c
*/
void		sa(t_stacks *stacks, int fd);
void		sb(t_stacks *stacks, int fd);
void		ss(t_stacks *stacks, int fd);

/*
** Declarations from ps_rotates.c
*/
void		ra(t_stacks *stacks, int fd);
void		rb(t_stacks *stacks, int fd);
void		rr(t_stacks *stacks, int fd);

/*
** Declarations from ps_rotates_reverse.c
*/
void		rra(t_stacks *stacks, int fd);
void		rrb(t_stacks *stacks, int fd);
void		rrr(t_stacks *stacks, int fd);

/*
** Declarations from ps_pushes.c
*/
void		pa(t_stacks *stacks, int fd);
void		pb(t_stacks *stacks, int fd);

#endif
