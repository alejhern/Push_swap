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

static void	ft_call_function(char *line, char ***stack_a, char ***stack_b)
{
	if (ft_memcmp(line, "sa\n", 3) == 0)
		sa(stack_a, -1);
	if (ft_memcmp(line, "sb\n", 3) == 0)
		sb(stack_b, -1);
	if (ft_memcmp(line, "ss\n", 3) == 0)
		ss(stack_a, stack_b, -1);
	if (ft_memcmp(line, "pa\n", 3) == 0)
		pa(stack_a, stack_b, -1);
	if (ft_memcmp(line, "pb\n", 3) == 0)
		pb(stack_b, stack_a, -1);
	if (ft_memcmp(line, "ra\n", 3) == 0)
		ra(stack_a, -1);
	if (ft_memcmp(line, "rb\n", 3) == 0)
		rb(stack_b, -1);
	if (ft_memcmp(line, "rr\n", 3) == 0)
		rr(stack_a, stack_b, -1);
	if (ft_memcmp(line, "rra\n", 4) == 0)
		rra(stack_a, -1);
	if (ft_memcmp(line, "rrb\n", 4) == 0)
		rrb(stack_b, -1);
	if (ft_memcmp(line, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, -1);
}

static void	check_stack(char **stack)
{
	int i;
	int j;
	long current;

	if (!stack || !stack[0])
		return ;
	i = 0;
	while (stack[i])
	{
		current = ft_atoi(stack[i]);
		j = i + 1;
		while (stack[j])
		{
			if (current == ft_atoi(stack[j]))
			{
				free_stack(stack);
				error_exit("Error: Duplicated values in the stack.\n");
			}
			j++;
		}
		i++;
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
	check_stack(stack);
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
	stack_b = NULL;
	stack_a = build_stack(argc, argv);
	print_stack(stack_a, 'A');
	radix_sort(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	return(0);
	ft_printf("move: ");
	line = get_next_line(0);
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
