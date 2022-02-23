/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:26:53 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/23 12:08:50 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct d_pivot
{
	int	min;
	int	max;
	int	value;
}				t_pivot;

typedef struct d_list
{
	int				push;
	int				p_index;
	int				index;
	int				len;
	int				content;
	struct d_list	*next;
}				t_list;

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		arg_validation(char **av);
int		is_num(char *str);

t_list	*pop_node(t_list **head);
void	add_node(t_list **old_node, int content);
void	add_first_node(t_list **first_node, int content);

void	swap_element(t_list *first_element);
void	push_element(t_list **from_list, t_list **to_list);
void	rotate_element(t_list **stack);
void	reverse_rotate(t_list **stack);

int		ft_max_value(t_list *stack);
int		ft_min_value(t_list *stack);
int		element_count(t_list *stack);

void 	re_index(t_list *stack);
double	index_finder(t_list *stack, int value);
t_list	*find_element(t_list *stack, int index);

int		ft_lis(t_list *stack);
void	rotate_decision(t_list **stack, int value, int dec);
void	top_element(t_list **stack, double n, int value);
void	sort_element(t_list **stack_a, t_list **stack_b, int n);


#endif