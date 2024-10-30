/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:02 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/30 11:08:06 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(char ***stack_a, int fd)
{
    rotate(*stack_a);
    ft_putendl_fd("ra", fd);
}

void    rb(char ***stack_b, int fd)
{
    rotate(*stack_b);
    ft_putendl_fd("rb", fd);
}

void    rr(char ***stack_a, char ***stack_b, int fd)
{
    rotate(*stack_a);
    rotate(*stack_b);
    ft_putendl_fd("rr", fd);
}
