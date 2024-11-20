/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:02 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 00:05:46 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stacks *stacks, int fd) {
    if (rotate(stacks->stack_a)) {
        stacks->move_count++;
        ft_putendl_fd("ra", fd);
    }
}

void rb(t_stacks *stacks, int fd) {
    if (rotate(stacks->stack_b)) {
        stacks->move_count++;
        ft_putendl_fd("rb", fd);
    }
}

void rr(t_stacks *stacks, int fd)
{
    int moved_a;
    int moved_b;

    moved_a = rotate(stacks->stack_a);
    moved_b = rotate(stacks->stack_b);
    if (moved_a || moved_b)
    {
        stacks->move_count++;
        ft_putendl_fd("rr", fd);
    }
}
