/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:53:47 by amhernandez       #+#    #+#             */
/*   Updated: 2024/11/15 19:53:54 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_value(char **stack)
{
    int i;
    long min;
    long current;

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
    return ((int)min);
}

int find_max_value(char **stack)
{
    int i;
    long max;
    long current;

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
    return ((int)max);
}

int get_max_bits(int max, int min)
{
    unsigned int range;
    int bits;

    range = (unsigned int)(max - min);
    bits = 0;
    while (range > 0)
    {
        range >>= 1;
        bits++;
    }
    return (bits);
}
