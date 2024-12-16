/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:34:20 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/16 12:45:05 by amhernandez      ###   ########.fr       */
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
	int	cost_b;

	pos_b = find_position(stacks->stack_b, stacks->size_b, value, 1);
	cost_b = calculate_cost(stacks->size_b, pos_b);
	rotate_stacks_simultaneously(stacks, 0, cost_b);
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
		cost_b = calculate_cost(stacks->size_b, pos_b);
		rotate_stacks_simultaneously(stacks, 0, cost_b);
		pa(stacks, 1);
	}
}

static void	sort_in_chunks(t_stacks *stacks, int *values, int total_size)
{
	int	i;
	int	start;
	int	end;
	int	best_value;

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
			best_value = find_best_value_in_range(stacks, values[start],
					values[end]);
			move_to_top(stacks, best_value);
			insert_sorted_in_b(stacks, best_value);
		}
		i++;
	}
}

void	turk_sort(t_stacks *stacks)
{
	int	total_size;
	int	*values;

	total_size = stacks->size_a;
	if (total_size == 0)
		return ;
	else if (total_size <= 5)
	{
		simple_sort(stacks);
		return ;
	}
	else if (total_size <= 100)
		stacks->chunks = 5;
	else
		stacks->chunks = total_size / 35;
	stacks->group_size = (total_size + stacks->chunks - 1) / stacks->chunks;
	values = get_sorted_values(stacks, total_size);
	sort_in_chunks(stacks, values, total_size);
	sort_and_move_back_to_a(stacks);
	free(values);
}
