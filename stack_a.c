/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:21:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/01 20:06:50 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack A
// Does nothing if there is only 1 element or none
void	swap_a(t_list **stack_a, int print)
{
	int	temp;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->down->content;
	(*stack_a)->down->content = temp;
	if (print)
		write (1, "sa\n", 3);
}

// Takes the first element at the top B and puts it at the top A
// Does nothing if B is empty
void	push_a(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->down;
	if (*stack_b)
		(*stack_b)->up = NULL;
	if (!*stack_a)
	{
		*stack_a = node;
		(*stack_a)->down = NULL;
		(*stack_a)->up = NULL;
	}
	else
	{
		node->down = *stack_a;
		(*stack_a)->up = node;
		*stack_a = node;
	}
	if (print)
		write(1, "pa\n", 3);
}

// Shift up all elements of stack A by 1
void	rotate_a(t_list **stack_a, int print)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_a)
		return ;
	first_node = *stack_a;
	last_node = ft_lstlast(*stack_a);
	*stack_a = first_node->down;
	(*stack_a)->up = NULL;
	last_node->down = first_node;
	first_node->up = last_node;
	first_node->down = NULL;
	if (print)
		write(1, "ra\n", 3);
}

// Shift down all elements of stack A by 1
void	reverse_rotate_a(t_list **stack_a, int print)
{
	t_list	*last_node;

	if (!*stack_a)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->up->down = NULL;
	last_node->down = *stack_a;
	(*stack_a)->up = last_node;
	last_node->up = NULL;
	*stack_a = last_node;
	if (print)
		write(1, "rra\n", 4);
}
