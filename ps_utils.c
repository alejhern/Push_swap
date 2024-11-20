/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:51:39 by alejhern          #+#    #+#             */
/*   Updated: 2024/10/13 22:35:06 by alejhern         ###   ########.fr       */
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

void	error_exit(const char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}
