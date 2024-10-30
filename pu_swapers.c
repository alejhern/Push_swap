/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_swapers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:05 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/30 11:09:07 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(char ***stack_a, int fd)
{
    swap(*stack_a);
    ft_putendl_fd("sa", fd);
}

void    sb(char ***stack_b, int fd)
{
    swap(*stack_b);
    ft_putendl_fd("sb", fd);
}

void    ss(char ***stack_a, char ***stack_b, int fd)
{
    swap(*stack_a);
    swap(*stack_b);
    ft_putendl_fd("ss", fd);
}
