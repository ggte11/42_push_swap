/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:43:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/23 18:25:39 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_input(int argc, char **argv, t_list **stack)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[0] == '\0')
			return (0);
		
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (!parsing_input(argc, argv, &stack))
	{
		printf("Erro: argumentos inválidos ou duplicados\n");
		return (1);
	}

	printf("Stack inicializada com sucesso!\n");

	// Opcional: imprimir os valores da stack para verificar
	while (stack)
	{
		printf("%d\n", (int)(long)(stack->content));
		stack = stack->next;
	}

	return (0);
}