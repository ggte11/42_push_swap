/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:09:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/18 15:18:12 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_decider(t_list **stack_a, t_list **stack_b, int size)
{
	if (size < 2)
		push_a (stack_a, stack_b, 1);
	else if (push_cost (*stack_b, size) <= push_cost (*stack_b, size - 1))
	{
		if (top_cost (*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up (stack_a, stack_b, size);
		else
			push_b_down (stack_a, stack_b, size);
		if (top_cost (*stack_b, size - 1) < bottom_cost(*stack_b, size - 1))
			push_b_up (stack_a, stack_b, size - 1);
		else
			push_b_down (stack_a, stack_b, size - 1);
	}
	else
	{
		if (top_cost (*stack_b, size - 1) < bottom_cost(*stack_b, size - 1))
			push_b_up (stack_a, stack_b, size - 1);
		else
			push_b_down (stack_a, stack_b, size - 1);
		if (top_cost (*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up_rev (stack_a, stack_b, size);
		else
			push_b_down_rev (stack_a, stack_b, size);
	}
}

// void	push_decider(t_list **stack_a, t_list **stack_b)
// {
// 	int	max;

// 	if (!*stack_b)
// 		return ;
// 	max = ft_lstsize (*stack_b);
// 	if (top_cost(*stack_b, max) <= bottom_cost(*stack_b, max))
// 		while ((*stack_b)->index != max)
// 			rotate_b(stack_b, 1);
// 	else
// 		while ((*stack_b)->index != max)
// 			reverse_rotate_b(stack_b, 1);
// 	push_a(stack_a, stack_b, 1);
// }

void	choose_sort(t_list **stack_a, t_list **stack_b, int divider)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		return (swap_a(stack_a, 1));
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		organize_four(stack_a, stack_b);
	else
	{
		normalize_numbers(*stack_a);
		divider = apropriate_divider(size);
		push_my_chunks(stack_a, stack_b, divider);
		if (!check_if_sorted(*stack_a))
			sort_three(stack_a);
		while (ft_lstsize(*stack_b) > 0)
			push_decider(stack_a, stack_b, ft_lstsize (*stack_b));
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
	int		cost;
	t_list	*last;

	cost = 0;
	last = ft_lstlast(stack);
	while (last && last->index != idx)
	{
		last = last->up;
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
