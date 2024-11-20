/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:47:49 by alejhern          #+#    #+#             */
/*   Updated: 2024/11/21 00:04:47 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(char **stack)
{
	char	*temp;

	if (!stack || ft_stacklen(stack) < 2)
		return (0);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (1);
}

int	rotate(char **stack)
{
	size_t	len;
	char	*first;

	len = ft_stacklen(stack);
	if (len < 2)
		return (0);
	first = stack[0];
	ft_memmove(stack, stack + 1, (len - 1) * sizeof(char *));
	stack[len - 1] = first;
	return (1);
}

int	rotate_reverse(char **stack)
{
	size_t	len;
	char	*last;

	if (!stack)
		return (0);
	len = ft_stacklen(stack);
	last = stack[len - 1];
	ft_memmove(stack + 1, stack, (len - 1) * sizeof(char *));
	stack[0] = last;
	return (1);
}

int	push(char ***stack1, char ***stack2)
{
	size_t	len_st1;
	size_t	len_st2;

	len_st2 = ft_stacklen(*stack2);
	if (!stack1 || !len_st2)
		return (0);
	len_st1 = ft_stacklen(*stack1);
	*stack1 = realloc(*stack1, (len_st1 + 2) * sizeof(char *));
	if (!*stack1)
		return (-1);
	(*stack1)[len_st1] = (*stack2)[0];
	(*stack1)[len_st1 + 1] = NULL;
	rotate_reverse(*stack1);
	rotate(*stack2);
	len_st2 = ft_stacklen(*stack2);
	(*stack2)[len_st2 - 1] = NULL;
	return (1);
}
