/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:47:49 by alejhern          #+#    #+#             */
/*   Updated: 2024/10/12 23:46:45 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

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

void	swap(char **stack) {
    char *temp;

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

	if (!stack)
		return ;
	len = ft_stacklen(stack);
	first = stack[0];
	ft_memmove(stack, stack + 1, (len - 1) * sizeof(char *));
	stack[len - 1] = first;
}	

void	rotate_reverse(char **stack)
{
	size_t len;

	if (!stack)
		return ;
	len = ft_stacklen(stack);
	while (len--)
		rotate(stack);
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
	if (!*stack1)
	{
		return ;
	}
	(*stack1)[len_st1] = (*stack2)[0];
	(*stack1)[len_st1 + 1] = NULL;
	while (len_st1--)
		rotate(*stack1);
	rotate(*stack2);
	*stack2 = (char **)ft_realloc(*stack2, len_st2 * sizeof(char *));
	if (!(*stack2))
	{
		return ;
	}
	(*stack2)[len_st2 - 1] = NULL;
}

void free_stack(char **stack)
{
    if (stack) {
        for (size_t i = 0; stack[i]; i++) {
            free(stack[i]); // Libera cada cadena
        }
        free(stack); // Libera el arreglo principal
    }
}

int main()
{
    // Crear stacks iniciales
    char **numbers = malloc(4 * sizeof(char *));
    numbers[0] = ft_strdup("57");
    numbers[1] = ft_strdup("45");
    numbers[2] = ft_strdup("569");
    numbers[3] = NULL; // Terminamos el arreglo con NULL

    char **numbers2 = malloc(2 * sizeof(char *));
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
	swap(numbers);

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

    return 0;
}
