/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:34:20 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/09 23:03:05 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks_simultaneously(t_stacks *stacks, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0 && (pos_a--, pos_b--))
		rr(stacks, 1);
	while (pos_a < 0 && pos_b < 0 && (pos_a++, pos_b++))
		rrr(stacks, 1);
	while (pos_a > 0 && pos_a--)
		ra(stacks, 1);
	while (pos_a < 0 && pos_a++)
		rra(stacks, 1);
	while (pos_b > 0 && pos_b--)
		rb(stacks, 1);
	while (pos_b < 0 && pos_b++)
		rrb(stacks, 1);
}

static void	insert_sorted_in_b(t_stacks *stacks, int value)
{
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_b = find_position(stacks->stack_b, stacks->size_b, value, 1);
	cost_a = 0;
	if (pos_b <= stacks->size_b / 2)
		cost_b = pos_b;
	else
		cost_b = pos_b - stacks->size_b;
	rotate_stacks_simultaneously(stacks, cost_a, cost_b);
	pb(stacks, 1);
}

static void	sort_and_move_back_to_a(t_stacks *stacks)
{
	int	max;
	int	pos_b;
	int	cost_b;

	while (stacks->size_b > 0)
	{
		max = find_max_value(stacks->stack_b);
		pos_b = find_position(stacks->stack_b, stacks->size_b, max, 0);
		if (pos_b <= stacks->size_b / 2)
			cost_b = pos_b;
		else
			cost_b = pos_b - stacks->size_b;
		rotate_stacks_simultaneously(stacks, 0, cost_b);
		pa(stacks, 1);
	}
}

static void	sort_in_chunks(t_stacks *stacks, int *values, int total_size)
{
	int	i;
	int	value;
	int	start;
	int	end;

	i = 0;
	while (i < stacks->chunks)
	{
		start = i * stacks->group_size;
		if ((i + 1) * stacks->group_size < total_size)
			end = (i + 1) * stacks->group_size - 1;
		else
			end = total_size - 1;
		while (has_values_in_range(stacks->stack_a, stacks->size_a,
				values[start], values[end]))
		{
			value = ft_atoi(stacks->stack_a[0]);
			if (value >= values[start] && value <= values[end])
				insert_sorted_in_b(stacks, value);
			else
				ra(stacks, 1);
		}
		i++;
	}
}

void	turk_sort(t_stacks *stacks)
{
	int	total_size;
	int	*values;

	total_size = stacks->size_a;
	if (total_size <= 100)
		stacks->chunks = 5;
	else
		stacks->chunks = total_size / 35;
	stacks->group_size = (total_size + stacks->chunks - 1) / stacks->chunks;
	values = get_sorted_values(stacks, total_size);
	sort_in_chunks(stacks, values, total_size);
	sort_and_move_back_to_a(stacks);
	free(values);
}
