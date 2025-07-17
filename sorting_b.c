/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martim <martim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:36:44 by mcardoso          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/17 16:11:18 by mcardoso         ###   ########.fr       */
=======
/*   Updated: 2025/07/09 23:22:57 by martim           ###   ########.fr       */
>>>>>>> 8ef88d2dd978b5365537e4921b953cefb54a6bf6
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_down(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a(stack_a, stack_b, 1);
			return ;
		}
		else
			reverse_rotate_b(stack_b, 1);
	}
}

void	push_b_up(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a(stack_a, stack_b, 1);
			return ;
		}
		else
		{
			print_value (*stack_a, *stack_b);
			rotate_b(stack_b, 1);
<<<<<<< HEAD
		}
=======
		//print_value(*stack_a, *stack_b);
>>>>>>> 8ef88d2dd978b5365537e4921b953cefb54a6bf6
	}
}

void	push_b_down_rev(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a(stack_a, stack_b, 1);
			swap_a(stack_a, 1);
			return ;
		}
		else
			reverse_rotate_b(stack_b, 1);
	}
}

void	push_b_up_rev(t_list **stack_a, t_list **stack_b, int idx)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == idx)
		{
			push_a(stack_a, stack_b, 1);
			swap_a(stack_a, 1);
			return ;
		}
		else
		{
			print_value (*stack_a, *stack_b);
			rotate_b(stack_b, 1);
<<<<<<< HEAD
		}
=======
		//print_value(*stack_a, *stack_b);
>>>>>>> 8ef88d2dd978b5365537e4921b953cefb54a6bf6
	}
}

void	organize_four(t_list **stack_a, t_list **stack_b)
{
	normalize_numbers(*stack_a);
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
