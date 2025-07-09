/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martim <martim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:44:30 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/09 23:30:20 by martim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*last;
	int		second;
	int		third;

	
	last = ft_lstlast(*stack);
	if ((*stack)->content > (*stack)->down->content)
		swap_a(stack, 1);
	second = (*stack)->down->content;
	third = last->content;
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
	while(i <= chunk_size)
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

void	push_double_chunks(t_list **stack_a, t_list **stack_b, int chunk1, int chunk2, int chunklimit)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a) > 3 && i < (chunk2 - chunk1) * 2)
	{
		if ((*stack_a)->index < chunk1 && (*stack_a)->index < chunklimit)
		{
			push_b(stack_a, stack_b, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= chunk2 && (*stack_a)->index < chunklimit)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
}

void	push_back_b(t_list **stack_a, t_list **stack_b)
{
	int	max;

	while (ft_lstsize (*stack_b) > 0)
	{
		max = ft_lstsize(*stack_b);
		if (max == (*stack_b)->index)
			push_a(stack_a, stack_b, 1);
		else if (top_cost(*stack_b, max) < bottom_cost(*stack_b, max))
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
	}
}
