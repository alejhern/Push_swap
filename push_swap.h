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

/*
** Declarations from ps_utils.c
*/
void	error_exit(const char *msg);
size_t	ft_stacklen(char **stack);
void	free_stack(char **stack);
/*
** Declarations from ps_logic.c
*/
void	radix_sort(char ***stack_a, char ***stack_b);
/*
** Declarations from ps_moves.c
*/
void	swap(char **stack);
void	rotate(char **stack);
void	rotate_reverse(char **stack);
void	push(char ***stack1, char ***stack2);;
/*
** Declarations from ps_swaper.c
*/
void	sa(char ***stack_a, int fd);
void	sb(char ***stack_b, int fd);
void	ss(char ***stack_a, char ***stack_b, int fd);
/*
** Declarations from pu_rotates.c
*/
void	ra(char ***stack_a, int fd);
void	rb(char ***stack_b, int fd);
void	rr(char ***stack_a, char ***stack_b, int fd);
/*
** Declarations from pu_rotates_reverse.c
*/
void	rra(char ***stack_a, int fd);
void	rrb(char ***stack_b, int fd);
void	rrr(char ***stack_a, char ***stack_b, int fd);
/*
** Declarations from ps_pushes.c
*/
void	pa(char ***stack_a, char ***stack_b, int fd);
void	pb(char ***stack_b, char ***stack_a, int fd);

#endif
