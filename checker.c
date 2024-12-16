/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:00:19 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/16 16:00:22 by amhernandez      ###   ########.fr       */
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

static int	is_sorted(char **stack)
{
	int		i;
	long	prev;
	long	current;

	if (!stack || !stack[0])
		return (1);
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

static void	checker(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_call_function(line, stacks);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stacks->stack_a) && stacks->size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 3)
		error_exit("You have to pass more than 2 arguments.");
	stacks.stack_a = build_stack(argc, argv);
	stacks.stack_b = NULL;
	stacks.size_a = argc - 1;
	stacks.size_b = 0;
	stacks.move_count = 0;
	checker(&stacks);
	free_stack(stacks.stack_a);
	if (stacks.stack_b)
		free_stack(stacks.stack_b);
	return (0);
}
