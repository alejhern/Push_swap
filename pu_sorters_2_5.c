/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sorters_2_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:54:26 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/15 19:54:29 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void sort_two(t_stacks *stacks)
{
    if (ft_atoi(stacks->stack_a[0]) > ft_atoi(stacks->stack_a[1]))
        sa(stacks, 1);
}

void sort_three(t_stacks *stacks)
{
    int first;
    int second;
    int third;

    first = ft_atoi(stacks->stack_a[0]);
    second = ft_atoi(stacks->stack_a[1]);
    third = ft_atoi(stacks->stack_a[2]);
    if (first > second && first > third)
        ra(stacks, 1);
    else if (first > second && second > third)
    {
        sa(stacks, 1);
        rra(stacks, 1);
    }
    else if (first > third && second < third)
        rra(stacks, 1);
    else if (first < second && first > third)
        sa(stacks, 1);
    else if (first < third && second > third)
        ra(stacks, 1);
}
void sort_four(t_stacks *stacks)
{
    long    min;
    int     i;

    min = find_min_value(stacks->stack_a);
    i = 0;
    while (i < stacks->size_a)
    {
        if (ft_atoi(stacks->stack_a[i]) == min)
        {
            pb(stacks, 1);
            break;
        }
        i++;
    }
    sort_three(stacks);
    pa(stacks, 1);
}

void sort_five(t_stacks *stacks)
{
    long    min;
    int     i;

    min = find_min_value(stacks->stack_a);
    i = 0;
    while (i < stacks->size_a)
    {
        if (ft_atoi(stacks->stack_a[i]) == min)
        {
            pb(stacks, 1);
            break;
        }
        i++;
    }
    sort_four(stacks);
    pa(stacks, 1);
}
