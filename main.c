/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:37:34 by alejhern          #+#    #+#             */
/*   Updated: 2024/11/09 18:05:58 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_call_function(char *line, t_stacks *stacks)
{
	if (ft_memcmp(line, "sa\n", 3) == 0)
		sa(stacks, -1);
	if (ft_memcmp(line, "sb\n", 3) == 0)
		sb(stacks, -1);
	if (ft_memcmp(line, "ss\n", 3) == 0)
		ss(stacks, -1);
	if (ft_memcmp(line, "pa\n", 3) == 0)
		pa(stacks, -1);
	if (ft_memcmp(line, "pb\n", 3) == 0)
		pb(stacks, -1);
	if (ft_memcmp(line, "ra\n", 3) == 0)
		ra(stacks, -1);
	if (ft_memcmp(line, "rb\n", 3) == 0)
		rb(stacks, -1);
	if (ft_memcmp(line, "rr\n", 3) == 0)
		rr(stacks, -1);
	if (ft_memcmp(line, "rra\n", 4) == 0)
		rra(stacks, -1);
	if (ft_memcmp(line, "rrb\n", 4) == 0)
		rrb(stacks, -1);
	if (ft_memcmp(line, "rrr\n", 4) == 0)
		rrr(stacks, -1);
}

static void	check_stack(char **stack)
{
	int i;
	int j;
	long current;

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

static char	**build_stack(int argc, char **argv)
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

static void	print_stack(char **stack, char letter)
{
	unsigned int	index;

	if (!stack)
		return ;
	index = 0;
	ft_printf("--- STACK %c ---\n", letter);
	while (stack[index])
	{
		ft_printf("Stack_%c[%02d]:%20s\n", ft_tolower(letter), index, stack[index]);
		index++;
	}
}

#include "libft.h"      // Asegúrate de tener la biblioteca adecuada para `ft_printf` y `get_next_line`.
#include "push_swap.h"  // Incluye aquí el archivo de cabecera con la definición de `t_stacks` y funciones auxiliares.

int main(int argc, char **argv) {
    t_stacks stacks;
    char *line;

    // Verificar que se han pasado suficientes argumentos
    if (argc < 3)
        error_exit("You have to pass more than 2 arguments.");

    // Inicializar stack_a y stack_b
    stacks.stack_a = build_stack(argc, argv);  // build_stack debería inicializar y cargar stack_a
    stacks.stack_b = NULL;                     // Inicializar stack_b como NULL
    stacks.size_a = argc - 1;                  // El tamaño de stack_a es argc - 1 (ignorando argv[0])
    stacks.size_b = 0;
    stacks.move_count = 0;

    // Imprimir stack inicial
    print_stack(stacks.stack_a, 'A');

    // Ejecutar el algoritmo de ordenación
    radix_sort(&stacks);

    // Imprimir stack_a ordenado
    print_stack(stacks.stack_a, 'A');

    // Liberar memoria de stack_a y stack_b
    free_stack(stacks.stack_a);
    free_stack(stacks.stack_b);
	return (0);
    // Interacción con el usuario para realizar movimientos manualmente
    ft_printf("move: ");
    line = get_next_line(0);  // Leer línea de entrada
    while (line) {
        ft_call_function(line, &stacks);  // Ejecutar la función correspondiente al comando
        print_stack(stacks.stack_a, 'A'); // Imprimir estado actual de stack_a
        print_stack(stacks.stack_b, 'B'); // Imprimir estado actual de stack_b
        free(line);                       // Liberar memoria de la línea
        ft_printf("move: ");
        line = get_next_line(0);
    }

    // Liberar memoria final de las pilas
    free_stack(stacks.stack_a);
    if (stacks.stack_b)
        free_stack(stacks.stack_b);

    return (0);
}
