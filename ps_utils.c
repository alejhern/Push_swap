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

int	has_values_in_range(char **stack, int size, int min, int max)
{
	int	i;
	int	value;

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

int	find_best_value_in_range(t_stacks *stacks, int start, int end)
{
	int	best_value;
	int	min_cost;
	int	value;
	int	cost;
	int	i;

	best_value = -1;
	min_cost = INT_MAX;
	i = -1;
	while (++i < stacks->size_a)
	{
		value = ft_atoi(stacks->stack_a[i]);
		if (value >= start && value <= end)
		{
			cost = i - stacks->size_a;
			if (i <= stacks->size_a / 2)
				cost = i;
			if (ft_abs(cost) < min_cost)
			{
				min_cost = ft_abs(cost);
				best_value = value;
			}
		}
	}
	return (best_value);
}

void	move_to_top(t_stacks *stacks, int value)
{
	int	pos_a;
	int	cost_a;

	pos_a = find_position(stacks->stack_a, stacks->size_a, value, 0);
	if (pos_a <= stacks->size_a / 2)
		cost_a = pos_a;
	else
		cost_a = pos_a - stacks->size_a;
	while (cost_a != 0)
	{
		if (cost_a > 0 && cost_a--)
			ra(stacks, 1);
		else if (cost_a < 0 && cost_a++)
			rra(stacks, 1);
	}
}
