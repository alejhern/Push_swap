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

char	**build_stack(int argc, char **argv)
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

void	print_stack(char **stack, char letter)
{
	unsigned int	index;

	if (!stack)
		return ;
	index = 0;
	ft_printf("--- STACK %c ---\n", letter);
	while (stack[index])
	{
		ft_printf("Stack_%c[%03d]:%20s\n", ft_tolower(letter), index,
			stack[index]);
		index++;
	}
}

void	free_stack(char **stack)
{
	size_t	index;

	if (stack)
	{
		index = 0;
		while (stack[index])
			free(stack[index++]);
		free(stack);
	}
}

void	error_exit(const char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}
