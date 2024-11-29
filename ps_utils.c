/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:51:39 by alejhern          #+#    #+#             */
/*   Updated: 2024/11/21 20:23:43 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_stacklen(char **stack)
{
	size_t	len;

	len = 0;
	if (!stack)
		return (len);
	while (stack[len])
		len++;
	return (len);
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

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb && i * i >= 0)
		i++;
	return (i - 1);
}

int	is_sorted(char **stack, size_t size)
{
	int		i;
	long	prev;
	long	current;

	if (!stack || !stack[0])
		return (1);
	if (size != ft_stacklen(stack))
		return (0);
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

void	error_exit(const char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}
