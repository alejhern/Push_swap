/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:20:03 by amhernandez       #+#    #+#             */
/*   Updated: 2024/10/18 21:20:07 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int find_min_value(char **stack)
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

static int find_max_value(char **stack)
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

static int get_max_bits(int max, int min)
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

static int is_sorted(char **stack, size_t size)
{
    int i;
    long prev;
    long current;

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

void radix_sort(char ***stack_a, char ***stack_b)
{
    int min;
    int bit;
    int i;
    int size;
    long num;
    int move_count = 0; // Contador de movimientos

    min = find_min_value(*stack_a);
    size = ft_stacklen(*stack_a);
    bit = 0;
    while (bit < get_max_bits(find_max_value(*stack_a), min) && !is_sorted(*stack_a, size))
    {
        i = 0;
        while (i < size)
        {
            num = ft_atoi((*stack_a)[0]) - min;
            if ((num >> bit) & 1)
            {
                rotate(*stack_a);
                ft_printf("ra");
            }
            else
            {
                push(stack_b, stack_a);
                ft_printf("pb");
            }
            move_count++; // Incrementar el contador de movimientos
            i++;
        }
        while (*stack_b && (*stack_b)[0])
        {
            push(stack_a, stack_b);
            ft_printf("pa");
            move_count++; // Incrementar el contador de movimientos
        }
        bit++;
    }
    ft_printf("\nTotal movements: %d\n", move_count);
}
