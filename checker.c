/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:00:19 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/07 23:56:59 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_exit(t_stacks *stacks, char *line)
{
	ft_free_array((void ***)&stacks->stack_a);
	if (stacks->stack_b)
		ft_free_array((void ***)&stacks->stack_b);
	free(line);
	ft_error_exit("Error");
}

static void	ft_call_function(char *line, t_stacks *stacks)
{
	if (ft_memcmp(line, "sa\n", 3) == 0)
		sa(stacks, -1);
	else if (ft_memcmp(line, "sb\n", 3) == 0)
		sb(stacks, -1);
	else if (ft_memcmp(line, "ss\n", 3) == 0)
		ss(stacks, -1);
	else if (ft_memcmp(line, "pa\n", 3) == 0)
		pa(stacks, -1);
	else if (ft_memcmp(line, "pb\n", 3) == 0)
		pb(stacks, -1);
	else if (ft_memcmp(line, "ra\n", 3) == 0)
		ra(stacks, -1);
	else if (ft_memcmp(line, "rb\n", 3) == 0)
		rb(stacks, -1);
	else if (ft_memcmp(line, "rr\n", 3) == 0)
		rr(stacks, -1);
	else if (ft_memcmp(line, "rra\n", 4) == 0)
		rra(stacks, -1);
	else if (ft_memcmp(line, "rrb\n", 4) == 0)
		rrb(stacks, -1);
	else if (ft_memcmp(line, "rrr\n", 4) == 0)
		rrr(stacks, -1);
	else
		return (free_exit(stacks, line));
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
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = build_stack(argc, argv);
	stacks.stack_b = NULL;
	stacks.size_a = argc - 1;
	stacks.size_b = 0;
	stacks.move_count = 0;
	checker(&stacks);
	ft_free_array((void ***)&stacks.stack_a);
	if (stacks.stack_b)
		ft_free_array((void ***)&stacks.stack_b);
	return (0);
}
