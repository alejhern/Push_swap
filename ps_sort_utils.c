/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:53:47 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 20:22:18 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_max_value(char **stack)
{
	int		i;
	long	max;
	long	current;

	if (!stack || !stack[0])
		return (0);
	i = 0;
	max = ft_atoi(stack[0]);
	while (stack[i])
	{
		current = ft_atoi(stack[i]);
		if (current > max)
			max = current;
		i++;
	}
	return (max);
}

long	find_min_value(char **stack)
{
	int		i;
	long	min;
	long	current;

	if (!stack || !stack[0])
		return (0);
	i = 0;
	min = ft_atoi(stack[0]);
	while (stack[i])
	{
		current = ft_atoi(stack[i]);
		if (current < min)
			min = current;
		i++;
	}
	return (min);
}

int	find_position(char **stack, int size, long value, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (i < size)
		{
			if (ft_atoi(stack[i]) == value)
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		while (i < size && ft_atoi(stack[i]) >= value)
			i++;
		return (i);
	}
}

int	find_closest_in_range(char **stack, int size, long min, long max)
{
	int		i;
	int		closest;
	long	current;

	i = 0;
	closest = -1;
	while (i < size)
	{
		current = ft_atoi(stack[i]);
		if (current >= min && current <= max)
		{
			if (closest == -1 || abs(i) < abs(closest))
				closest = i;
		}
		i++;
	}
	return (closest);
}
