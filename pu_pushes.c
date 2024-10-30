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

void    pa(char ***stack_a, char ***stack_b, int fd)
{
    push(stack_a, stack_b);
    ft_putendl_fd("pa", fd);
}

void    pb(char ***stack_b, char ***stack_a, int fd)
{
    push(stack_b, stack_a);
    ft_putendl_fd("pb", fd);
}
