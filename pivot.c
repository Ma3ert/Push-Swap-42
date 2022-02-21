/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:45:13 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/21 17:32:41 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_value(t_list *stack)
{
	int		min;
	t_list 	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp = stack;
	min = tmp->content;
	while (tmp->next != NULL)
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
	t_list 	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp = stack;
	max = tmp->content;
	while (tmp->next != NULL)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

// int	ft_best_element(int high, int low, t_list *stack)
// {
// 	t_list	*tmp;

// 	tmp = malloc(sizeof(t_list));
// 	tmp = stack;
// 	while (tmp->next != NULL)
// 	{
// 		if (tmp->content < high && tmp->content > low)
// 			return (tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (ft_best_element(high + 5, low - 5, stack));
// }

// int	pivot_checker(t_list *stack, int pivot, int n)
// {
// 	int	middle;

// 	if (ft_middle(stack, pivot) == )
// }

// int	ft_best_pivot(t_list *stack, t_pivot pivot)
// {
// 	int		n;

// 	n = element_count(stack);
// 	pivot.value = ft_best_element(pivot.value + 5, pivot.value - 5, stack);
// 	if (pivot_checker(stack, pivot.value, n) == 1)
		
// 	return (pivot.value);
// }

// int	pivot_finder(t_list *stack)
// {
// 	int		best_pivot;
// 	t_pivot pivot;

// 	pivot.min = ft_min_value(stack);
// 	pivot.max = ft_max_value(stack);
// 	pivot.value = (pivot.max - pivot.min) / 2;
// 	best_pivot = ft_best_pivot(stack, pivot);
// 	return (best_pivot);
// }
