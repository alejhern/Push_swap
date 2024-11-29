/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:26 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 20:24:17 by alejhern         ###   ########.fr       */
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
** Declarations from ps_utils.c
*/
void		error_exit(const char *msg);
size_t		ft_stacklen(char **stack);
int			ft_sqrt(int nb);
int			is_sorted(char **stack, size_t size);
void		free_stack(char **stack);
/*
** Declarations from ps_sort_utils.c
*/
long		find_max_value(char **stack);
long		find_min_value(char **stack);
int			find_position(char **stack, int size, int value, int mode);
int			*get_sorted_values(t_stacks *stacks, int total_size);
/*
** Declarations from ps_sorters_2_5.c
*/
void		sort_two(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_four_to_five(t_stacks *stacks);
/*
** Declarations from ps_turk_sort.c
*/
void		turk_sort(t_stacks *stacks);
/*
** Declarations from ps_moves.c
*/
int			swap(char **stack);
int			rotate(char **stack);
int			rotate_reverse(char **stack);
int			push(char ***stack1, char ***stack2);
;
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
