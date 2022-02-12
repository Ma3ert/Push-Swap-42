/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:01 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/09 17:44:59 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_list **from_list, t_list **to_list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*new_node;

	tmp1 = *from_list;
	tmp2 = *to_list;
	new_node = malloc(sizeof(t_list));
	new_node->content = tmp1->content;
	new_node->next = *to_list;
	*to_list = new_node;
	*from_list = tmp1->next;
}
