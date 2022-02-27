/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:01 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/24 13:45:38 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_list **from_list, t_list **to_list)
{
	t_list *new_node;

	new_node = pop_node(from_list);
	if (to_list != NULL)
	{
		new_node->next = *to_list;
		*to_list = new_node;
	}
	else
		to_list = &new_node;
}
