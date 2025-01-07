/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:54:26 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/09 22:19:23 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stacks *stacks)
{
	if (ft_atoi(stacks->stack_a[0]) > ft_atoi(stacks->stack_a[1]))
		sa(stacks, 1);
}

static void	sort_three(t_stacks *stacks)
{
	long	first;
	long	second;
	long	third;

	first = ft_atoi(stacks->stack_a[0]);
	second = ft_atoi(stacks->stack_a[1]);
	third = ft_atoi(stacks->stack_a[2]);
	if (first > second && second < third && first < third)
		sa(stacks, 1);
	else if (first > second && second > third)
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stacks, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stacks, 1);
}

static void	sort_four_to_five(t_stacks *stacks)
{
	long	min;
	int		i;

	while (stacks->size_a != 3)
	{
		min = find_min_value(stacks->stack_a);
		i = -1;
		while (++i < stacks->size_a)
		{
			if (ft_atoi(stacks->stack_a[0]) == min)
			{
				pb(stacks, 1);
				break ;
			}
			else if (calculate_cost(stacks->size_a,
					find_position(stacks->stack_a, stacks->size_a, min)) > 0)
				ra(stacks, 1);
			else
				rra(stacks, 1);
		}
	}
	sort_three(stacks);
	while (stacks->size_b)
		pa(stacks, 1);
}

void	simple_sort(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	if (stacks->size_a == 2)
		sort_two(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4 || stacks->size_a == 5)
		sort_four_to_five(stacks);
}
