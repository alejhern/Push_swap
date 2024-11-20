/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:26 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/30 11:09:29 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stacks {
    char **stack_a;
    char **stack_b;
    int size_a;
    int size_b;
    int move_count;
    int *target_positions; // Arreglo para posiciones objetivo en stack_a
    int group_size; // Tamaño de grupo para reducir movimientos en radix_sort
} t_stacks;

/*
** Declarations from ps_utils.c
*/
void	error_exit(const char *msg);
size_t	ft_stacklen(char **stack);
void	free_stack(char **stack);
/*
** Declarations from ps_sort_utils.c
*/
long    find_min_value(char **stack);
long    find_max_value(char **stack);
int     get_max_bits(long max, long min);
/*
** Declarations from ps_sorters_2_5.c
*/
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
/*
** Declarations from ps_radix_sort.c
*/
void	radix_sort(t_stacks *stacks);
/*
** Declarations from ps_moves.c
*/
int	swap(char **stack);
int	rotate(char **stack);
int	rotate_reverse(char **stack);
int	push(char ***stack1, char ***stack2);;
/*
** Declarations from ps_swaper.c
*/
void	sa(t_stacks *stacks, int fd);
void	sb(t_stacks *stacks, int fd);
void	ss(t_stacks *stacks, int fd);
/*
** Declarations from ps_rotates.c
*/
void	ra(t_stacks *stacks, int fd);
void	rb(t_stacks *stacks, int fd);
void	rr(t_stacks *stacks, int fd);
/*
** Declarations from ps_rotates_reverse.c
*/
void	rra(t_stacks *stacks, int fd);
void	rrb(t_stacks *stacks, int fd);
void	rrr(t_stacks *stacks, int fd);
/*
** Declarations from ps_pushes.c
*/
void	pa(t_stacks *stacks, int fd);
void    pb(t_stacks *stacks, int fd);

#endif
