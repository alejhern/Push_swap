/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:20:03 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/21 00:05:27 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int is_sorted(char **stack, size_t size)
{
    int     i;
    long    prev;
    long    current;

    if (!stack || !stack[0])
        return (1);
    if (size !=  ft_stacklen(stack))
        return (0);
    i = 0;
    prev = ft_atoi(stack[0]);
    while (stack[i])
    {
        current = ft_atoi(stack[i]);
        if (current < prev)
            return (0);
        prev = current;
        i++;
    }
    return (1);
}

static void simple_sort(t_stacks *stacks)
{
    if (stacks->size_a == 2)
        sort_two(stacks);
    else if (stacks->size_a == 3)
        sort_three(stacks);
    else if (stacks->size_a == 5)
        sort_five(stacks);
}

void radix_sort(t_stacks *stacks)
{
    long    min;
    int     bit;
    int     i;
    int     size;

    min = find_min_value(stacks->stack_a);
    size = ft_stacklen(stacks->stack_a);
    bit = 0;
    simple_sort(stacks);
    while (bit < get_max_bits(find_max_value(stacks->stack_a), min) && !is_sorted(stacks->stack_a, size))
    {
        i = 0;
        while (i < size)
        {
            if (((ft_atoi((stacks->stack_a)[0]) - min) >> bit) & 1)
                ra(stacks, 1);
            else
                pb(stacks, 1);
            i++;
        }
        while (stacks->size_b)
            pa(stacks, 1);
        bit++;
    }
    ft_printf("\nTotal movements: %d\n", stacks->move_count);
}
