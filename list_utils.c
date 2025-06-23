/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:36:21 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/23 14:46:22 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cria um novo nó com o conteúdo fornecido
t_list	*ft_lstnew(void *content)
{
	t_list	*ele;

	ele = malloc(sizeof(t_list));
	if (!ele)
		return (NULL);
	ele->content = content;
	ele->next = NULL;
	ele->previous = NULL;
	return (ele);
}

// Adiciona um nó no fim da lista
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->previous = NULL;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->previous = last;
	}
	new->next = NULL;
}

// Retorna o último nó da lista
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// Adiciona um nó no início da lista
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->previous = NULL;
	if (*lst)
		(*lst)->previous = new;
	*lst = new;
}

// Conta quantos nós existem na lista
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
		tmp = tmp->next;
		i++;
	}
	return (i);
}