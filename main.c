/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:37:34 by alejhern          #+#    #+#             */
/*   Updated: 2024/12/09 23:04:21 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
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
	turk_sort(&stacks);
	ft_printf("\nTotal movements: %d\n", stacks.move_count);
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}
