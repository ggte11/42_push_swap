/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:36:44 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/07 19:35:04 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_down(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
			push_a(stack_a, stack_b, 1);
		else
			reverse_rotate_a(stack_a, 0);
	}
}

void	push_b_up(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
			push_b(stack_a, stack_b, 1);
		else
			reverse_rotate_a(stack_a, 0);
	}
}

// void	push_b_down(t_list **stack_a, int idx)
// {
	
// }

void	organize_four(t_list **stack_a, t_list **stack_b)
{
	normalize_numbers(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index == 1)
		{
			push_b(stack_a, stack_b, 1);
			break ;
		}
		else
			rotate_a (stack_a, 1);
	}
	if (!check_if_sorted(*stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b, 1);
}
