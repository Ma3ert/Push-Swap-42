/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:22:24 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/08 15:22:37 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (stack)
	{
		stack = tmp->next;
		free(tmp);
		tmp = stack;
	}
}