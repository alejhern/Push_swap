/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:34:20 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 00:34:28 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_sorted_in_b(t_stacks *stacks, int value)
{
	int	pos;

	pos = find_position(stacks->stack_b, stacks->size_b, value, 1);
	if (pos <= stacks->size_b / 2)
	{
		while (pos-- > 0)
			rb(stacks, 1);
	}
	else
	{
		while (pos++ < stacks->size_b)
			rrb(stacks, 1);
	}
	pb(stacks, 1);
}

static void	sort_and_move_back_to_a(t_stacks *stacks)
{
	int	max;
	int	pos;

	while (stacks->size_b > 0)
	{
		max = find_max_value(stacks->stack_b);
		pos = find_position(stacks->stack_b, stacks->size_b, max, 0);
		if (pos <= stacks->size_b / 2)
		{
			while (pos-- > 0)
				rb(stacks, 1);
		}
		else
		{
			while (pos++ < stacks->size_b)
				rrb(stacks, 1);
		}
		pa(stacks, 1);
	}
}

static void	sort_in_chunks(t_stacks *stacks, int *values, int total_size)
{
	int	i;
	int	min;
	int	max;
	int	value;
	int	initial_size_a;

	i = 0;
	while (i < stacks->chunks)
	{
		min = values[i * stacks->group_size];
		if ((i + 1) * stacks->group_size < total_size)
			max = values[(i + 1) * stacks->group_size - 1];
		else
			max = values[total_size - 1];
		initial_size_a = stacks->size_a;
		while (initial_size_a--)
		{
			value = ft_atoi(stacks->stack_a[0]);
			if (value >= min && value <= max)
				insert_sorted_in_b(stacks, value);
			else
				ra(stacks, 1);
		}
		i++;
	}
}

static void	simple_sort(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		sort_two(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4 || stacks->size_a == 5)
		sort_four_to_five(stacks);
}

void	turk_sort(t_stacks *stacks)
{
	int	total_size;
	int	*values;

	total_size = stacks->size_a;
	simple_sort(stacks);
	if (is_sorted(stacks->stack_a, total_size))
		return ;
	stacks->chunks = ft_sqrt(total_size);
	stacks->group_size = (total_size + stacks->chunks - 1) / stacks->chunks;
	values = get_sorted_values(stacks, total_size);
	sort_in_chunks(stacks, values, total_size);
	sort_and_move_back_to_a(stacks);
	free(values);
}
