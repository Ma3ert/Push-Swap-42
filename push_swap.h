/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:26:53 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/12 12:00:21 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct d_list{

	int				content;
	int				head;
	struct d_list	*next;
}				t_list;

int		ft_atoi(const char *str);
void	swap_element(t_list *first_element);
void	push_element(t_list **from_list, t_list **to_list);
void	add_node(t_list **old_node, int content);
void	rotate_element(t_list **stack);
void	reverse_rotate(t_list **stack);
#endif