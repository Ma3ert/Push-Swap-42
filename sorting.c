/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:12:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/21 18:45:44 by yait-iaz         ###   ########.fr       */
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

int	index_finder(t_list *stack, int value)
{
	while (stack->content != value && stack)
		stack = stack->next;
	return (stack->index);
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

void	top_first_element(t_list **stack, int n, int min)
{
	if (n % 2 == 0)
		n = (n / 2);
	else
		n = (n / 2) + 1;
	if (index_finder(*stack, min) > n)
		rotate_decision(stack, min, 1);
	else
		rotate_decision(stack, min, 2);
	re_index(*stack);
}

void	sort_element(t_list **stack_a, t_list **stack_b, int n)
{
	int		i;
	int		min;

	i = 0;
	stack_b = NULL;
	min = ft_min_value(*stack_a);
	if ((*stack_a)->content != min)
		top_first_element(stack_a, n, min);
	// printf("this the n: %d\n", n);
}