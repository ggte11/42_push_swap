/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:43:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/08 16:38:51 by mcardoso         ###   ########.fr       */
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
void	free_stack(t_list **stack)
{
	t_list *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->down;
		free(temp);
	}
}

int	apropriate_divider(int size)
{
	int	divider;

	if (size > 400)
		divider = 30;
	else if (size >= 100)
		divider = 10;
	else if (size >= 50)
		divider = 5;
	else if (size >= 10)
		divider = size / 4;
	else
		divider = 4;
	return (divider);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parsing_input(argc, argv, &stack_a))
		return (write(2 ,"Error\n", 6), 1);
	if (check_if_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	i = apropriate_divider(ft_lstsize(stack_a));
	choose_sort(&stack_a, &stack_b, 1);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
