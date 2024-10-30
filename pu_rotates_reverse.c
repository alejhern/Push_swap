/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_rotates_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:53 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/30 11:08:56 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(char ***stack_a, int fd)
{
    rotate_reverse(*stack_a);
    ft_putendl_fd("rra", fd);
}

void    rrb(char ***stack_b, int fd)
{
    rotate_reverse(*stack_b);
    ft_putendl_fd("rrb", fd);
}

void    rrr(char ***stack_a, char ***stack_b, int fd)
{
    rotate_reverse(*stack_a);
    rotate_reverse(*stack_b);
    ft_putendl_fd("rrr", fd);
}
