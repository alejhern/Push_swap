/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:31:57 by alejhern          #+#    #+#             */
/*   Updated: 2024/10/13 21:55:12 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

// Declarations from ps_utils.c
void	error_exit(const char *msg);
size_t  ft_stacklen(char **stack);
void    ft_stackfree(char **stack);

// Declarations fron ps_logic.c
void    radix_sort(char ***stack_a, char ***stack_b);
// Declarations from ps_moves.c
void	swap(char **stack);
void	rotate(char **stack);
void	rotate_reverse(char **stack);
void	push(char ***stack1, char ***stack2);
void	free_stack(char **stack);

#endif
