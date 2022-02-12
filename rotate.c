/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:03 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/10 16:03:47 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_element(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = malloc(sizeof(t_list));
	tmp1 = *stack;
	*stack = tmp1->next;
	tmp2 = tmp1->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
}