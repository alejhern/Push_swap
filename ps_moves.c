/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:47:49 by alejhern          #+#    #+#             */
/*   Updated: 2024/11/21 20:20:32 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(char **stack, int size)
{
	char	*temp;

	if (!stack || size < 2)
		return (0);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (1);
}

int	rotate(char **stack, int size)
{
	char	*first;

	if (size < 2)
		return (0);
	first = stack[0];
	ft_memmove(stack, stack + 1, (size - 1) * sizeof(char *));
	stack[size - 1] = first;
	return (1);
}

int	rotate_reverse(char **stack, int size)
{
	char	*last;

	if (!stack || size < 2)
		return (0);
	last = stack[size - 1];
	ft_memmove(stack + 1, stack, (size - 1) * sizeof(char *));
	stack[0] = last;
	return (1);
}

int	push(char ***stack1, char ***stack2, int size_1, int size_2)
{
	size_t	len_st1;
	size_t	len_st2;

	len_st2 = size_2;
	if (!stack1 || !len_st2)
		return (0);
	len_st1 = size_1;
	*stack1 = realloc(*stack1, (len_st1 + 2) * sizeof(char *));
	if (!*stack1)
		return (-1);
	(*stack1)[len_st1] = (*stack2)[0];
	(*stack1)[len_st1 + 1] = NULL;
	rotate_reverse(*stack1, len_st1 + 1);
	rotate(*stack2, len_st2);
	len_st2 = size_2;
	(*stack2)[len_st2 - 1] = NULL;
	return (1);
}
