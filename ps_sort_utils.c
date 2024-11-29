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

int	find_position(char **stack, int size, int value, int mode)
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

static void	ft_qsort(int *values, int total_size)
{
	int	temp;
	int	pivot;
	int	i;
	int	j;

	if (total_size < 2)
		return ;
	pivot = values[total_size / 2];
	i = 0;
	j = total_size - 1;
	while (i < j)
	{
		while (values[i] < pivot)
			i++;
		while (pivot < values[j])
			j--;
		if (i >= j)
			break ;
		temp = values[i];
		values[i] = values[j];
		values[j] = temp;
	}
	ft_qsort(values, i);
	ft_qsort(values + i, total_size - i);
}

int	*get_sorted_values(t_stacks *stacks, int total_size)
{
	int	*values;
	int	i;

	values = malloc(total_size * sizeof(int));
	if (!values)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		values[i] = ft_atoi(stacks->stack_a[i]);
		i++;
	}
	ft_qsort(values, total_size);
	return (values);
}
