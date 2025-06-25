/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:43:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/25 15:26:18 by mcardoso         ###   ########.fr       */
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
	while(stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (write(2 ,"Error\n", 6), 1);
	if (!parsing_input(argc, argv, &stack_a))
	{
		write(2 ,"Error\n", 6);
		return (1);
	}
	if (check_if_sorted(stack_a))
		return (write(2, "sorted\n", 7));
	while (stack_a)
	{
		printf("%d\n", (int)(long)(stack_a->content));
		stack_a = stack_a->next;
	}
	return (0);
}