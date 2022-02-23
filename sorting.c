/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:12:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/23 12:36:33 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_count(t_list *stack)
{
	int	n;

	n = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

void	rotate_decision(t_list **stack, int value, int dec)
{
	if (dec == 1)
	{
		while ((*stack)->content != value)
		{
			printf("ra\n");
			rotate_element(&(*stack));
		}
	}
	else
	{
		while ((*stack)->content != value)
		{
			printf("rra\n");
			reverse_rotate(&(*stack));
		}
	}
}

void	top_element(t_list **stack, double n, int value)
{
	n = (n / 2.0);
	if (index_finder(*stack, value) > n)
		rotate_decision(stack, value, 1);
	else
		rotate_decision(stack, value, 2);
	re_index(*stack);
}

void	sort_element(t_list **stack_a, t_list **stack_b, int n)
{
	int		i;
	int		r;
	int		min;

	r = 0;
	i = 0;
	min = ft_min_value(*stack_a);
	if ((*stack_a)->content != min)
		top_element(stack_a, n, min);
	re_index(*stack_a);
	i = n - ft_lis(*stack_a);
	while (i != 0 && r < n)
	{
		if ((*stack_a)->push == 0)
		{
			printf("pa\n");
			push_element(stack_a, stack_b);
			i--;
		}
		else
		{
			printf("ra\n");
			rotate_element(stack_a);
			r++;
		}
	}
}
