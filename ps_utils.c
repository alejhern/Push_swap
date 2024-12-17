/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:51:39 by alejhern          #+#    #+#             */
/*   Updated: 2024/12/09 22:47:02 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_values_in_range(char **stack, int size, long min, long max)
{
	int		i;
	long	value;

	i = 0;
	while (i < size)
	{
		value = ft_atoi(stack[i]);
		if (value >= min && value <= max)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calculate_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

long	find_best_value_in_range(t_stacks *stacks, long start, long end)
{
	long	best_value;
	int		min_cost;
	int		i;
	int		cost;

	best_value = -1;
	min_cost = INT_MAX;
	i = -1;
	while (++i < stacks->size_a)
	{
		if (ft_atoi(stacks->stack_a[i]) >= start
			&& ft_atoi(stacks->stack_a[i]) <= end)
		{
			cost = ft_abs(calculate_cost(stacks->size_a, i))
				+ ft_abs(calculate_cost(stacks->size_b,
						find_position(stacks->stack_b, stacks->size_b,
							ft_atoi(stacks->stack_a[i]), 1)));
			if (cost < min_cost)
			{
				min_cost = cost;
				best_value = ft_atoi(stacks->stack_a[i]);
			}
		}
	}
	return (best_value);
}

void	move_to_top(t_stacks *stacks, long value)
{
	int	pos_a;
	int	cost_a;

	pos_a = find_position(stacks->stack_a, stacks->size_a, value, 0);
	cost_a = calculate_cost(stacks->size_a, pos_a);
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(stacks, 1);
			cost_a--;
		}
		else
		{
			rra(stacks, 1);
			cost_a++;
		}
	}
}
