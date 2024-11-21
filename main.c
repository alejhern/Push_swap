/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:37:34 by alejhern          #+#    #+#             */
/*   Updated: 2024/11/21 20:21:22 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_call_function(char *line, t_stacks *stacks)
{
	if (ft_memcmp(line, "sa\n", 3) == 0)
		sa(stacks, -1);
	if (ft_memcmp(line, "sb\n", 3) == 0)
		sb(stacks, -1);
	if (ft_memcmp(line, "ss\n", 3) == 0)
		ss(stacks, -1);
	if (ft_memcmp(line, "pa\n", 3) == 0)
		pa(stacks, -1);
	if (ft_memcmp(line, "pb\n", 3) == 0)
		pb(stacks, -1);
	if (ft_memcmp(line, "ra\n", 3) == 0)
		ra(stacks, -1);
	if (ft_memcmp(line, "rb\n", 3) == 0)
		rb(stacks, -1);
	if (ft_memcmp(line, "rr\n", 3) == 0)
		rr(stacks, -1);
	if (ft_memcmp(line, "rra\n", 4) == 0)
		rra(stacks, -1);
	if (ft_memcmp(line, "rrb\n", 4) == 0)
		rrb(stacks, -1);
	if (ft_memcmp(line, "rrr\n", 4) == 0)
		rrr(stacks, -1);
}

static void	check_stack(char **stack)
{
	int		i;
	int		j;
	long	current;

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
		ft_printf("Stack_%c[%02d]:%20s\n", ft_tolower(letter), index,
			stack[index]);
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*line;

	if (argc < 3)
		error_exit("You have to pass more than 2 arguments.");
	stacks.stack_a = build_stack(argc, argv);
	stacks.stack_b = NULL;
	stacks.size_a = argc - 1;
	stacks.size_b = 0;
	stacks.move_count = 0;
	print_stack(stacks.stack_a, 'A');
	radix_sort(&stacks);
	ft_printf("\nTotal movements: %d\n", stacks.move_count);
	print_stack(stacks.stack_a, 'A');
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
	ft_printf("move: ");
	line = get_next_line(0);
	while (line)
	{
		ft_call_function(line, &stacks);
		print_stack(stacks.stack_a, 'A');
		print_stack(stacks.stack_b, 'B');
		free(line);
		ft_printf("move: ");
		line = get_next_line(0);
	}
	free_stack(stacks.stack_a);
	if (stacks.stack_b)
		free_stack(stacks.stack_b);
	return (0);
}
