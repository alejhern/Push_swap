/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swapers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:09:05 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/07 23:45:07 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, int fd)
{
	if (swap(stacks->stack_a, stacks->size_a))
	{
		stacks->move_count++;
		ft_putendl_fd("sa", fd);
	}
}

void	sb(t_stacks *stacks, int fd)
{
	if (swap(stacks->stack_b, stacks->size_b))
	{
		stacks->move_count++;
		ft_putendl_fd("sb", fd);
	}
}

void	ss(t_stacks *stacks, int fd)
{
	int	moved_a;
	int	moved_b;

	moved_a = swap(stacks->stack_a, stacks->size_a);
	moved_b = swap(stacks->stack_b, stacks->size_b);
	if (moved_a || moved_a)
	{
		stacks->move_count++;
		ft_putendl_fd("ss", fd);
	}
}
