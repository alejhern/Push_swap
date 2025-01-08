/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:14:21 by amhernandez       #+#    #+#             */
/*   Updated: 2024/12/16 16:31:24 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack(char **stack)
{
	int		i;
	int		j;
	long	current;

	i = -1;
	while (stack[++i])
	{
		current = ft_atoi(stack[i]);
		if (!ft_isnum(stack[i]) || current > INT_MAX || current < INT_MIN)
		{
			ft_free_array((void ***)&stack);
			ft_error_exit("Error");
		}
		j = i;
		while (stack[++j])
		{
			if (current == ft_atoi(stack[j]))
			{
				ft_free_array((void ***)&stack);
				ft_error_exit("Error");
			}
		}
	}
}

char	**build_stack(int argc, char **argv)
{
	char	**stack;
	int		index;

	stack = (char **)malloc(argc * sizeof(char *));
	if (!stack)
		ft_error_exit("Error");
	index = 0;
	while (index < argc - 1)
	{
		stack[index] = ft_strdup(argv[index + 1]);
		if (!stack[index] || !argv[index + 1][0])
		{
			ft_free_array((void ***)&stack);
			ft_error_exit("Error");
		}
		index++;
	}
	stack[index] = NULL;
	check_stack(stack);
	return (stack);
}

int	is_sorted(char **stack)
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

void	set_stacks_info(t_stacks *stacks)
{
	stacks->desfase = 0;
	if (stacks->size_a <= 50)
		stacks->chunks = 2;
	else if (stacks->size_a <= 85)
	{
		stacks->desfase = 1;
		stacks->chunks = 3;
	}
	else if (stacks->size_a <= 100)
	{
		stacks->desfase = 1;
		stacks->chunks = 5;
	}
	else if (stacks->size_a <= 200)
	{
		stacks->desfase = 2;
		stacks->chunks = 4;
	}
	else
	{
		stacks->desfase = 4;
		stacks->chunks = 6;
	}
	stacks->group_size = (stacks->size_a + stacks->chunks - 1) / stacks->chunks;
}
