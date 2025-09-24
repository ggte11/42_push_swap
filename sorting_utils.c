/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martim <martim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:44:30 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/24 19:37:21 by martim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*stack)->content;
	pos2 = (*stack)->down->content;
	pos3 = (*stack)->down->down->content;;
	if (pos1 > pos2 && pos1 < pos3)
		swap_a(stack, 1);
	else if (pos1 > pos2 && pos2 > pos3)
	{
		swap_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	else if (pos1 > pos3 && pos2 < pos3)
		rotate_a(stack, 1);
	else if (pos1 < pos2 && pos1 > pos3)
		reverse_rotate_a(stack, 1);
	else if (pos1 < pos3 && pos2 > pos3)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
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

void	optimal_rotate(t_list **stack_a, t_list **stack_b, t_chunklist *chunks)
{
	push_b(stack_a, stack_b, 1);
	if ((*stack_a)->index > chunks->ch2)
	{
		rotate_both(stack_a, stack_b);
		return ;
	}
	else
	{
		rotate_b(stack_b, 1);
		return ;
	}
}

void	push_double_chunks(t_list **stack_a, t_list **stack_b
		, t_chunklist *chunks)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a) > 3 && i < (chunks->ch2 - chunks->ch1) * 2)
	{
		if ((*stack_a)->index <= chunks->ch1 && (*stack_a)->index < chunks->max)
		{
			optimal_rotate(stack_a, stack_b, chunks);
			i++;
		}
		else if ((*stack_a)->index <= chunks->ch2
			&& (*stack_a)->index < chunks->max)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
}
