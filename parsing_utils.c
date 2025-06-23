/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:11:16 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/23 18:14:11 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') \
			&& (!str[i + 1] || str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		i++;
	}
	return (1);
}


int	check_duplicates(t_list *lst, int nbr)
{
	while (lst)
	{
		if ((long)lst->content == (long)nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	split_and_convert(const char *arg, t_list **stack)
{
	unsigned int	i;
	int				sign;
	long			result;
	
	i = 0;
	while (arg[i])
	{
		result = 0;
		sign = 1;
		while (arg[i] == ' ')
			i++;
		if (!arg[i])
			break ;
		if (arg[i] == '-' || arg[i] == '+')
			if (arg[i++] == '-')
				sign *= -1;
		while (ft_isdigit(arg[i]))
			result = ((result * 10) + arg[i++] - '0');
		result *= sign;
		if (result > INT_MAX || result < INT_MIN || check_duplicates(*stack, result))
			return (0);
		ft_lstadd_back(stack, ft_lstnew((void *)(long)(result)));
	}
	return (1);
}

