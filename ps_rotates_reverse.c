/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotates_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:53 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 20:22:09 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, int fd)
{
	if (rotate_reverse(stacks->stack_a, stacks->size_a))
	{
		stacks->move_count++;
		ft_putendl_fd("rra", fd);
	}
}

void	rrb(t_stacks *stacks, int fd)
{
	if (rotate_reverse(stacks->stack_b, stacks->size_b))
	{
		stacks->move_count++;
		ft_putendl_fd("rrb", fd);
	}
}

void	rrr(t_stacks *stacks, int fd)
{
	int	moved_a;
	int	moved_b;

	moved_a = rotate_reverse(stacks->stack_a, stacks->size_a);
	moved_b = rotate_reverse(stacks->stack_b, stacks->size_b);
	if (moved_a || moved_b)
	{
		stacks->move_count++;
		ft_putendl_fd("rr", fd);
	}
}
