/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:47:49 by alejhern          #+#    #+#             */
/*   Updated: 2024/10/13 22:37:25 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_stacklen(char **stack)
{
	size_t	len;

	len = 0;
	if (!stack)
		return (len);
	while (stack[len])
		len++;
	return (len);
}

void	swap(char **stack)
{
	char	*temp;

	if (!stack || ft_stacklen(stack) < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	rotate(char **stack)
{
	size_t	len;
	char	*first;

	len = ft_stacklen(stack);
	if (len < 2)
		return ;
	first = stack[0];
	ft_memmove(stack, stack + 1, (len - 1) * sizeof(char *));
	stack[len - 1] = first;
}

void	rotate_reverse(char **stack)
{
	size_t	len;
	char	*last;

	if (!stack)
		return ;
	len = ft_stacklen(stack);
	last = stack[len - 1];
	ft_memmove(stack + 1, stack, (len - 1) * sizeof(char *));
	stack[0] = last;
}

void	push(char ***stack1, char ***stack2)
{
	size_t	len_st1;
	size_t	len_st2;

	len_st2 = ft_stacklen(*stack2);
	if (!stack1 || !len_st2)
		return ;
	len_st1 = ft_stacklen(*stack1);
	*stack1 = (char **)ft_realloc(*stack1, (len_st1 + 2) * sizeof(char *));
	if (!(*stack1))
		error_exit("Error: Failed to allocate memory with malloc.\n");
	(*stack1)[len_st1] = (*stack2)[0];
	(*stack1)[len_st1 + 1] = NULL;
	rotate_reverse(*stack1);
	rotate(*stack2);
	*stack2 = (char **)ft_realloc(*stack2, len_st2 * sizeof(char *));
	if (!(*stack2))
		error_exit("Error: Failed to allocate memory with malloc.\n");
	(*stack2)[len_st2 - 1] = NULL;
}
/*
void	free_stack(char **stack)
{
	if (stack)
	{
		for (size_t i = 0; stack[i]; i++)
		{
			free(stack[i]); // Libera cada cadena
		}
		free(stack); // Libera el arreglo principal
	}
}

int	main(void)
{
	char	**numbers;
	char	**numbers2;

	// Crear stacks iniciales
	numbers = malloc(4 * sizeof(char *));
	numbers[0] = ft_strdup("57");
	numbers[1] = ft_strdup("45");
	numbers[2] = ft_strdup("569");
	numbers[3] = NULL; // Terminamos el arreglo con NULL
	numbers2 = malloc(2 * sizeof(char *));
	numbers2[0] = ft_strdup("88");
	numbers2[1] = ft_strdup("78");
	numbers2[2] = NULL; // Terminamos el arreglo con NULL
	ft_printf("Beffore-------\n");
	ft_printf("Stack A (numbers):\n");
	for (int i = 0; numbers[i]; i++)
		ft_printf("numbers[%d] = %s\n", i, numbers[i]);
	ft_printf("Stack B (numbers2):\n");
	for (int i = 0; numbers2[i]; i++)
		ft_printf("numbers2[%d] = %s\n", i, numbers2[i]);
	// Realiza el push de numbers2 a numbers
	push(&numbers, &numbers2);
	// Mostrar el estado de ambos stacks después del push
	ft_printf("Affter--------\n");
	ft_printf("Stack A (numbers):\n");
	for (int i = 0; numbers[i]; i++)
		ft_printf("numbers[%d] = %s\n", i, numbers[i]);
	ft_printf("Stack B (numbers2):\n");
	for (int i = 0; numbers2[i]; i++)
		ft_printf("numbers2[%d] = %s\n", i, numbers2[i]);
	// Liberar memoria
	free_stack(numbers);
	free_stack(numbers2);
	return (0);
}
*/
