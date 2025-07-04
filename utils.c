/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:56 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/23 17:45:51 by mcardoso         ###   ########.fr       */
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
