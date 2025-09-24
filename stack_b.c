/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:21:21 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/23 14:40:05 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack B
// Does nothing if there is only 1 element or none
void	swap_b(t_list **stack_b, int print)
{
	int	temp;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->down->content;
	(*stack_b)->down->content = temp;
	if (print)
		write (1, "sb\n", 3);
}

// Takes the first element at the top A and puts it at the top B
// Does nothing if A is empty
void	push_b(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->down;
	if (*stack_a)
		(*stack_a)->up = NULL;
	if (!*stack_b)
	{
		*stack_b = node;
		(*stack_b)->down = NULL;
		(*stack_b)->up = NULL;
	}
	else
	{
		node->down = *stack_b;
		(*stack_b)->up = node;
		*stack_b = node;
	}
	if (print)
		write(1, "pb\n", 3);
}

// Shift up all elements of stack B by 1
void	rotate_b(t_list **stack_b, int print)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_b || ft_lstsize(*stack_b) < 2)
		return ;
	first_node = *stack_b;
	last_node = ft_lstlast(*stack_b);
	*stack_b = first_node->down;
	(*stack_b)->up = NULL;
	last_node->down = first_node;
	first_node->up = last_node;
	first_node->down = NULL;
	if (print)
		write(1, "rb\n", 3);
}

// Shift down all elements of stack B by 1
void	reverse_rotate_b(t_list **stack_b, int print)
{
	t_list	*last_node;

	if (!*stack_b || !(*stack_b)->down)
		return ;
	last_node = ft_lstlast(*stack_b);
	if (!last_node->up)
		return ;
	last_node->up->down = NULL;
	last_node->down = *stack_b;
	(*stack_b)->up = last_node;
	last_node->up = NULL;
	*stack_b = last_node;
	if (print)
		write(1, "rrb\n", 4);
}
