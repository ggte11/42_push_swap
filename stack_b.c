/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:21:21 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/30 15:02:17 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack B
// Does nothing if there is only 1 element or none
void	swap_b(t_list **stack_b)
{
	int	temp;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	write (1, "sb\n", 3);
}

// Takes the first element at the top A and puts it at the top B
// Does nothing if A is empty
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	if (!*stack_b)
	{
		*stack_b = node;
		(*stack_b)->next = NULL;
		(*stack_b)->previous = NULL;
	}
	else
	{
		node->next = *stack_b;
		(*stack_b)->previous = node;
		*stack_b = node;
	}
	write(1, "pb\n", 3);
}

// Shift up all elements of stack B by 1
void	rotate_b(t_list **stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first_node = *stack_b;
	last_node = ft_lstlast(*stack_b);
	*stack_b = first_node->next;
	(*stack_b)->previous = NULL;
	last_node->next = first_node;
	first_node->previous = last_node;
	first_node->next = NULL;
	write(1, "rb\n", 3);
}

// Shift down all elements of stack B by 1
void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*last_node;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last_node = ft_lstlast(*stack_b);
	last_node->previous->next = NULL;
	last_node->next = *stack_b;
	(*stack_b)->previous = last_node;
	last_node->previous = NULL;
	*stack_b = last_node;
	write(1, "rrb\n", 4);
}