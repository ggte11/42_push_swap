/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:21:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/25 17:42:19 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	temp;
	int	i;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->previous->content;
	(*stack_a)->previous->content = temp;
	write (1, "sa\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->previous;
	(*stack_b)->next = NULL;
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

void	rotate_a(t_list **stack_a)
{
	
}