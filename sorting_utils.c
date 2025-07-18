/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:44:30 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/18 16:59:46 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*last;
	int		second;
	int		third;

	second = (*stack)->down->content;
	last = ft_lstlast(*stack);
	third = last->content;
	if ((*stack)->content > second)
		swap_a(stack, 1);
	if (third < second && third < (*stack)->content)
		reverse_rotate_a(stack, 1);
	else if (third < second)
	{
		reverse_rotate_a(stack, 1);
		swap_a(stack, 1);
	}
}

void	normalize_numbers(t_list *stack)
{
	int		i;
	t_list	*current;
	t_list	*compare;

	current = stack;
	while (current)
	{
		i = 1;
		compare = stack;
		while (compare)
		{
			if (compare->content < current->content)
				i++;
			compare = compare->down;
		}
		current->index = i;
		current = current->down;
	}
}

void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int	i;

	i = 1;
	while (i <= chunk_size)
	{
		if ((*stack_a)->index <= chunk_size)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
}

void	push_double_chunks(t_list **stack_a, t_list **stack_b, t_chunklist *chunks)
{
	int	i;
	
	i = 0;
	while (ft_lstsize(*stack_a) > 3 && i < (chunks->ch2 - chunks->ch1) * 2)
	{
		if ((*stack_a)->index < chunks->ch1 && (*stack_a)->index < chunks->max)
		{
			push_b(stack_a, stack_b, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= chunks->ch2 && (*stack_a)->index < chunks->max)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
}
