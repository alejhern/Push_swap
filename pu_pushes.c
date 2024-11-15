/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:07:22 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/30 11:07:25 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función que realiza el push de `stack_b` a `stack_a`
void pa(t_stacks *stacks, int fd) {
    int result;

    result = push(&(stacks->stack_a), &(stacks->stack_b)); // Movimiento de `stack_b` a `stack_a`
    if (result == 1)
    {
        stacks->size_a++;
        stacks->size_b--;
        stacks->move_count++;
        ft_putendl_fd("pa", fd);
    }
    else if (result == -1)
    {
        free_stack(stacks->stack_a);
        free_stack(stacks->stack_b);
        error_exit("Error: Failed to reallocate memory with realloc.\n");
    }
}

// Función que realiza el push de `stack_a` a `stack_b`
void pb(t_stacks *stacks, int fd) {
    int result;

    result = push(&(stacks->stack_b), &(stacks->stack_a)); // Movimiento de `stack_a` a `stack_b`
    if (result == 1)
    {
        stacks->size_b++;
        stacks->size_a--;
        stacks->move_count++;
        ft_putendl_fd("pb", fd);
    }
    else if (result == -1)
    {
        free_stack(stacks->stack_a);
        free_stack(stacks->stack_b);
        error_exit("Error: Failed to reallocate memory with realloc.\n");
    }
}