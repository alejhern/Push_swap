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

static void	rotate_to_minimize_cost(t_stacks *stacks, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0 && (cost_a--, cost_b--))
		rr(stacks, 1);
	while (cost_a < 0 && cost_b < 0 && (cost_a++, cost_b++))
		rrr(stacks, 1);
	while (cost_a > 0 && cost_a--)
		ra(stacks, 1);
	while (cost_a < 0 && cost_a++)
		rra(stacks, 1);
	while (cost_b > 0 && cost_b--)
		rb(stacks, 1);
	while (cost_b < 0 && cost_b++)
		rrb(stacks, 1);
}

void	split_to_chunks(t_stacks *stacks, long min, long max)
{
	int		i;
	int		size;
	long	current_value;

	size = stacks->size_a;
	i = 0;
	while (i < size)
	{
		current_value = ft_atoi(stacks->stack_a[0]);
		if (current_value >= min && current_value <= max)
		{
			pb(stacks, 1);
			if (current_value <= (min + max) / 2)
				rb(stacks, 1);
		}
		else
			ra(stacks, 1);
		i++;
	}
}

static void	push_chunks_to_b(t_stacks *stacks, long *values, int total_size)
{
	int	i;
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
		split_to_chunks(stacks, values[start], values[end]);
		i++;
	}
}

static void	push_all_to_a(t_stacks *stacks)
{
	int	pos_b;
	int	cost_b;

	while (stacks->size_b > 0)
	{
		pos_b = find_position(stacks->stack_b, stacks->size_b,
				find_max_value(stacks->stack_b), 0);
		cost_b = calculate_cost(stacks->size_b, pos_b);
		rotate_to_minimize_cost(stacks, 0, cost_b);
		pa(stacks, 1);
	}
}

void	turk_sort(t_stacks *stacks)
{
	long	*values;
	int		total_size;

	total_size = stacks->size_a;
	if (total_size <= 5)
		return (simple_sort(stacks));
	if (total_size <= 100)
		stacks->chunks = 5;
	else if (total_size <= 500)
		stacks->chunks = 11;
	else
		stacks->chunks = total_size / 35;
	stacks->group_size = (total_size + stacks->chunks - 1) / stacks->chunks;
	values = get_sorted_values(stacks, total_size);
	push_chunks_to_b(stacks, values, total_size);
	push_all_to_a(stacks);
	free(values);
}
