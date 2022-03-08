/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:45:13 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/07 14:52:41 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_value(t_list *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_max_value(t_list *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else if (a < b)
		return (a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else if (a > b)
		return (a);
	return (a);
}
