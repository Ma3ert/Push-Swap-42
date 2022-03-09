/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/09 12:43:14 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char *str)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*head;

	if (element_count(*stack) < 2)
		return ;
	head = *stack;
	tmp1 = *stack;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp2->next = head;
	tmp1->next = NULL;
	*stack = tmp2;
	ft_putstr(str);
}
