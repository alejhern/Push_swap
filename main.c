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
	size_t	index;

	if (stack)
	{
		index = 0;
		while (stack[index])
			free(stack[index]);
		free(stack);
	}
}

static void	ft_call_function(char *line, char ***stack_a, char ***stack_b)
{
	if (ft_memcmp(line, "sa\n", 3) == 0)
		swap(*stack_a);
	if (ft_memcmp(line, "sb\n", 3) == 0)
		swap(*stack_b);
	if (ft_memcmp(line, "ss\n", 3) == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	if (ft_memcmp(line, "pa\n", 3) == 0)
		push(stack_a, stack_b);
	if (ft_memcmp(line, "pb\n", 3) == 0)
		push(stack_b, stack_a);
	if (ft_memcmp(line, "ra\n", 3) == 0)
		rotate(*stack_a);
	if (ft_memcmp(line, "rb\n", 3) == 0)
		rotate(*stack_b);
	if (ft_memcmp(line, "rr\n", 3) == 0)
	{
		rotate(*stack_a);
		rotate(*stack_b);
	}
	if (ft_memcmp(line, "rra\n", 4) == 0)
		rotate_reverse(*stack_a);
	if (ft_memcmp(line, "rrb\n", 4) == 0)
		rotate_reverse(*stack_b);
	if (ft_memcmp(line, "rrr\n", 4) == 0)
	{
		rotate_reverse(*stack_a);
		rotate_reverse(*stack_b);
	}
}

static char	**build_stack(int argc, char **argv)
{
	char	**stack;
	int		index;

	stack = (char **)malloc(argc * sizeof(char *));
	if (!stack)
		error_exit("Error: Failed to allocate memory with malloc.\n");
	index = 0;
	while (index < argc - 1)
	{
		stack[index] = ft_strdup(argv[index + 1]);
		if (!stack[index])
		{
			free_stack(stack);
			error_exit("Error: Failed to allocate memory with malloc.\n");
		}
		index++;
	}
	stack[index] = NULL;
	return (stack);
}

static void	print_stack(char **stack, char letter)
{
	unsigned int	index;

	if (!stack)
		return ;
	index = 0;
	ft_printf("--- STACK %c ---\n", letter);
	while (stack[index])
	{
		ft_printf("Stack_%c[%d]:%s\n", ft_tolower(letter), index, stack[index]);
		index++;
	}
}

int	main(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	char	*line;

	if (argc < 3)
		error_exit("You have to pass more than 2 argmunts;");
	stack_a = build_stack(argc, argv);
	print_stack(stack_a, 'A');
	ft_printf("move: ");
	line = get_next_line(0);
	stack_b = NULL;
	while (line)
	{
		ft_call_function(line, &stack_a, &stack_b);
		print_stack(stack_a, 'A');
		print_stack(stack_b, 'B');
		free(line);
		ft_printf("move: ");
		line = get_next_line(0);
	}
	free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
