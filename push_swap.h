/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:59 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/26 17:47:30 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				content;
}					t_list;

//main
int	parsing_input(int argc, char **argv, t_list **stack)
;

//list utils
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//utils
int		ft_isdigit(int c);
size_t	count_words(const char *str, char sep);

//Parsing Utils
int	is_valid_number(char *str);
int	split_and_convert(const char *arg, t_list **stack);

//stack_a commands
void	swap_a(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b);


#endif