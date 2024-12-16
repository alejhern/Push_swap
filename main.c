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
	print_stack(stacks.stack_a, 'A');
	turk_sort(&stacks);
	ft_printf("\nTotal movements: %d\n", stacks.move_count);
	print_stack(stacks.stack_a, 'A');
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}
