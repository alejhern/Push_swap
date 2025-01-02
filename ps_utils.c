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

int	calculate_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

static void	ft_qsort(long *values, int total_size)
{
	long	temp;
	long	pivot;
	int		i;
	int		j;

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

long	*get_sorted_values(t_stacks *stacks, int total_size)
{
	long	*values;
	int		i;

	values = malloc(total_size * sizeof(long));
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

void	set_stacks_info(t_stacks *stacks)
{
	stacks->desfase = 0;
	if (stacks->size_a <= 85)
		stacks->chunks = 3;
	else if (stacks->size_a <= 100)
		stacks->chunks = 5;
	else if (stacks->size_a <= 200)
	{
		stacks->desfase = 2;
		stacks->chunks = 4;
	}
	else
	{
		stacks->desfase = 4;
		stacks->chunks = 6;
	}
	stacks->group_size = (stacks->size_a + stacks->chunks - 1) / stacks->chunks;
}
