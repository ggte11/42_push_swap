/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:56 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/18 17:01:40 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	count_words(const char *str, char sep)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != sep && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == sep)
			in_word = 0;
		i++;
	}
	return (count);
}

void	push_my_chunks(t_list **stack_a, t_list **stack_b, int divider)
{
	t_chunklist chunks;

	chunks.ch1 = divider;
	chunks.ch2 = divider * 2;
	chunks.max = ft_lstsize(*stack_a) - 2;
	while (ft_lstsize(*stack_a) > 3)
	{
		push_double_chunks(stack_a, stack_b, &chunks);
		chunks.ch1 += (divider * 2);
		chunks.ch2 += (divider * 2);
	}
}
