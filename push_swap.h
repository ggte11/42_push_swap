/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:59 by mcardoso          #+#    #+#             */
/*   Updated: 2025/07/17 20:23:35 by mcardoso         ###   ########.fr       */
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
	struct s_list	*down;
	struct s_list	*up;
	int				content;
	int				index;
}					t_list;

// main
int		parsing_input(int argc, char **argv, t_list **stack);
int		check_if_sorted(t_list *stack);
void	free_stack(t_list **stack);
int		apropriate_divider(int size);

// list utils
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// utils
int		ft_isdigit(int c);
size_t	count_words(const char *str, char sep);
void	push_my_chunks(t_list **stack_a, t_list **stack_b, int divider);

//Parsing Utils
int		is_valid_number(char *str);
int		split_and_convert(const char *arg, t_list **stack);

// stack_a commands
void	swap_a(t_list **stack_a, int print);
void	push_a(t_list **stack_a, t_list **stack_b, int print);
void	rotate_a(t_list **stack_a, int print);
void	reverse_rotate_a(t_list **stack_a, int print);

// stack_b commands
void	swap_b(t_list **stack_b, int print);
void	push_b(t_list **stack_a, t_list **stack_b, int print);
void	rotate_b(t_list **stack_b, int print);
void	reverse_rotate_b(t_list **stack_b, int print);

// stack_both commands
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);

// sorting_utils
void	sort_three(t_list **stack);
void	normalize_numbers(t_list *stack);
void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk_size);
void	push_double_chunks(t_list **stack_a, t_list **stack_b, int chunk1, int chunk2, int chunklimit);
void	push_back_b(t_list **stack_a, t_list **stack_b);

// sorting_utils2
void	push_decider(t_list **stack_a, t_list **stack_b);
void	choose_sort(t_list **stack_a, t_list **stack_b, int divider);
int		top_cost(t_list *stack, int idx);
int		bottom_cost(t_list *stack, int idx);
int		push_cost(t_list *stack, int idx);

// sorting_b
void	push_b_down(t_list **stack_a, t_list **stack_b, int idx);
void	push_b_up(t_list **stack_a, t_list **stack_b, int idx);
void	push_b_down_rev(t_list **stack_a, t_list **stack_b, int idx);
void	push_b_up_rev(t_list **stack_a, t_list **stack_b, int idx);
void	organize_four(t_list **stack_a, t_list **stack_b);

// delete
//void	print_value(t_list *a, t_list *b);

#endif