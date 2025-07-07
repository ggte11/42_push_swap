/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:09:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/07 17:56:38 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_decider(t_list **stack_a, t_list **stack_b, int size)
{
	int	max_idx;
	int	cost_top;
	int	cost_bottom;

	if (!*stack_b)
		return ;
	max_idx = find_max_index(*stack_b);
	cost_top = top_cost(*stack_b, max_idx);
	cost_bottom = bottom_cost(*stack_b, max_idx);
	if (cost_top <= cost_bottom)
	{
		while ((*stack_b)->index != max_idx)
			rotate_b(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->index != max_idx)
			reverse_rotate_b(stack_b, 1);
	}
	push_a(stack_a, stack_b, 1);
}

void	choose_sort(t_list **stack_a, t_list **stack_b, int divider)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		return (swap_a(stack_a, 1));
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		;
	else
	{
		normalize_numbers(stack_a);
		if (!check_if_sorted(stack_a))
			sort_three(stack_a);
		while (ft_lstsize(*stack_b) > 0)
			push_decider(stack_a, stack_b, ft_lstsize(*stack_b));
	}
}

int	top_cost(t_list *stack, int idx)
{
	int	cost;

	cost = 0;
	while (stack && stack->index != idx)
	{
		stack = stack->down;
		cost++;
	}
	return (cost);
}
int	bottom_cost(t_list *stack, int idx)
{
	int	cost;

	cost = 0;
	while (stack && stack->index != idx)
	{
		stack = stack->up;
		cost++;
	}
	return (cost);
}

int	push_cost(t_list *stack, int idx)
{
	int	top;
	int	bottom;

	top = top_cost(stack, idx);
	bottom = bottom_cost(stack, idx);
	if (top <= bottom)
		return (top);
	return (bottom);
}
