/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:36:21 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/18 15:13:03 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node with the provided content
t_list	*ft_lstnew(int content)
{
	t_list	*ele;

	ele = malloc(sizeof(t_list));
	if (!ele)
		return (NULL);
	ele->content = content;
	ele->down = NULL;
	ele->up = NULL;
	return (ele);
}

// Adds a node to the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->up = NULL;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->down = new;
		new->up = last;
	}
	new->down = NULL;
}

// Returns the last node of the list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->down)
		temp = temp->down;
	return (temp);
}

// Adds a node in the begining of the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->down = *lst;
	new->up = NULL;
	if (*lst)
		(*lst)->up = new;
	*lst = new;
}

// Counts how many nodes exist on the list
int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->down;
		i++;
	}
	return (i);
}
