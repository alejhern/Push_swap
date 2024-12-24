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

static void	split_to_chunks(t_stacks *stacks, long min, long max)
{
	int	pos;

	while (has_values_in_range(stacks->stack_a, stacks->size_a, min, max))
	{
		pos = find_closest_in_range(stacks->stack_a, stacks->size_a, min, max);
		if (pos <= stacks->size_a / 2)
			rotate_to_minimize_cost(stacks, pos, 0);
		else
			rotate_to_minimize_cost(stacks, pos - stacks->size_a, 0);
		pb(stacks, 1);
		if (ft_atoi(stacks->stack_b[0]) <= (min + max) / 2)
			rb(stacks, 1);
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
		if (pos_b == 1)
			sb(stacks, 1);
		else
			rotate_to_minimize_cost(stacks, 0, cost_b);
		pa(stacks, 1);
	}
}

void	turk_sort(t_stacks *stacks)
{
	long	*values;

	if (is_sorted(stacks->stack_a))
		return ;
	if (stacks->size_a <= 5)
		return (simple_sort(stacks));
	if (stacks->size_a <= 100)
		stacks->chunks = 5;
	else if (stacks->size_a <= 500)
		stacks->chunks = 8;
	else
		stacks->chunks = stacks->size_a / 35;
	stacks->group_size = (stacks->size_a + stacks->chunks - 1) / stacks->chunks;
	values = get_sorted_values(stacks, stacks->size_a);
	push_chunks_to_b(stacks, values, stacks->size_a);
	push_all_to_a(stacks);
	free(values);
	if (is_sorted(stacks->stack_a) && stacks->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
