/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:37:34 by alejhern          #+#    #+#             */
/*   Updated: 2024/10/13 22:42:26 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(char **stack)
{
	if (stack)
	{
		for (size_t i = 0; stack[i]; i++)
		{
			free(stack[i]); // Libera cada cadena
		}
		free(stack); // Libera el arreglo principal
	}
}

static void	ft_call_function(char *line, char ****stack_a, char ****stack_b)
{
	if (ft_memcmp(line, "sa", ft_strlen(line)))
		swap(*stack_a);
	if (ft_memcmp(line, "sb", ft_strlen(line)))
		swap(*stack_b);
	if (ft_memcmp(line, "ss", ft_strlen(line)))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	if (ft_memcmp(line, "pa", ft_strlen(line)))
		push(&*stack_a, &*stack_b);
	if (ft_memcmp(line, "pb", ft_strlen(line)))
		push(&*stack_b, &*stack_a);
	if (ft_memcmp(line, "ra", ft_strlen(line)))
		rotate(*stack_a);
	if (ft_memcmp(line, "rb", ft_strlen(line)))
		rotate(*stack_b);
	if (ft_memcmp(line, "rr", ft_strlen(line)))
	{
		rotate(*stack_a);
		rotate(*stack_b);
	}
	if (ft_memcmp(line, "rra", ft_strlen(line)))
		rotate_reverse(*stack_a);
	if (ft_memcmp(line, "rrb", ft_strlen(line)))
		rotate_reverse(*stack_b);
	if (ft_memcmp(line, "rrr", ft_strlen(line)))
	{
		rotate_reverse(*stack_a);
		rotate_reverse(*stack_b);
	}
}

static void	print_stack(char **stack, char letter)
{
	unsigned int 	index;

	if (!stack)
		return ;
	index = 0;
	ft_printf("--- STACK %c ---", letter);
	while (stack_a[index])
		ft_printf("Stack_%c[%d]:%s\n", ft_tolower(letter), index, stack[index++]);
}

int		main(int argc, char **argv);
{
	char **stack_a;
	char **stack_b;
	char *line;

	if (argc < 3)
	{
		ft_printf("You have to pass more than 2 argmunts;");
		return (1);
	}
	stack_a = (char **)ft_realloc(argv + 1, argc - 1);
	if (!stack_a)
		error_exit("Error: Failed to allocate memory with malloc.\n");
	print_stack(stack_a, "A");
	line = get_next_line(0);
	stack_b = NULL;
	while (line)
	{
		ft_call_function(line, &stack_a, &stack_b);
		print_stack(stack_a, "A");
		print_stack(stack_b, "B");
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
