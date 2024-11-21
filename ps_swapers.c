/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swapers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:05 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 20:23:25 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, int fd)
{
	if (swap(stacks->stack_a))
	{
		stacks->move_count++;
		ft_putendl_fd("sa", fd);
	}
}

void	sb(t_stacks *stacks, int fd)
{
	if (swap(stacks->stack_b))
	{
		stacks->move_count++;
		ft_putendl_fd("sb", fd);
	}
}

void	ss(t_stacks *stacks, int fd)
{
	if (swap(stacks->stack_a) || swap(stacks->stack_b))
	{
		stacks->move_count++;
		ft_putendl_fd("ss", fd);
	}
}
