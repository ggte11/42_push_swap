/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:43:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/07 19:39:16 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_input(int argc, char **argv, t_list **stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]) || !split_and_convert(argv[i], stack))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_sorted(t_list *stack)
{
	while(stack->down)
	{
		if (stack->content > stack->down->content)
			return (0);
		stack = stack->down;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parsing_input(argc, argv, &stack_a))
		return (write(2 ,"Error\n", 6), 1);
	if (check_if_sorted(stack_a))
		return (0);
	choose_sort(&stack_a, &stack_b, 5);
	normalize_numbers(stack_a);
	push_chunks(&stack_a, &stack_b, 5);
	print_value(stack_a, stack_b);
}
	

void	print_value(t_list *a, t_list *b) // delete
{
	printf("\nA\tB");
	printf("\n");
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			printf("%d", (int)a->index);
			a = a->down;
		}
		else
			printf("   ");
		printf("\t");
		if (b)
		{
			printf("%d\n", (int)b->index);
			b = b->down;
		}
		else
			printf("\n");
	}
	printf("\n");
	printf("--------------------------------\n");
	fflush(stdout);
}