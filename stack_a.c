/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:21:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/26 20:10:03 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack A
// Does nothing if there is only 1 element or none
void	swap_a(t_list **stack_a)
{
	int	temp;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	write (1, "sa\n", 3);
}

// Takes the first element at the top B and puts it at the top A
// Does nothing if B is empty
void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	if (!*stack_a)
	{
		*stack_a = node;
		(*stack_a)->next = NULL;
		(*stack_a)->previous = NULL;
	}
	else
	{
		node->next = *stack_a;
		(*stack_a)->previous = node;
		*stack_a = node;
	}
	write(1, "pa\n", 3);
}

// Shift up all elements of stack A by 1
void	rotate_a(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	last_node = ft_lstlast(*stack_a);
	*stack_a = first_node->next;
	(*stack_a)->previous = NULL;
	last_node->next = first_node;
	first_node->previous = last_node;
	first_node->next = NULL;
	write(1, "ra\n", 3);
}

// Shift down all elements of stack A by 1
void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->previous)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->previous->next = NULL;
	last_node->next = *stack_a;
	(*stack_a)->previous = last_node;
	last_node->previous = NULL;
	*stack_a = last_node;
	write(1, "rra\n", 4);
}
