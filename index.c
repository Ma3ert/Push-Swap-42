/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:05:43 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/01 17:57:53 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void re_index(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

t_list	*find_element(t_list *stack, int index)
{
	while (stack->index != index && stack)
		stack = stack->next;
	return (stack);
}

double	index_finder(t_list *stack, int value)
{
	while (stack->content != value && stack)
		stack = stack->next;
	return ((double)stack->index);
}