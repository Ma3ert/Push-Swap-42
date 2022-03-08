/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/08 19:22:21 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char *str)
{
	t_list	*tmp1;
	int		content;

	if (element_count(*stack) < 2)
		return ;
	tmp1 = *stack;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	content = tmp1->next->content;
	// free(tmp1->next);
	tmp1->next = NULL;
	add_node(stack, content);
	ft_putstr(str);
}
