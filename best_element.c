/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:42:01 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/05 20:47:14 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_decision(t_list **stack, int value, int dec, char *s)
{
	if (dec == 1)
	{
		while ((*stack)->content != value)
			rotate_element(stack, s);
	}
	else
	{
		while ((*stack)->content != value)
			reverse_rotate(stack, s);
	}
}

t_list	*best_position(t_list *stack_a, int content)
{
	t_list *head;

	head = stack_a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->content < content && stack_a->next->content > content)
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	if (stack_a->content < content && head->content >content)
		return(head);
	return (NULL);
}

void	move_best_element(t_list **stack_a, t_list **stack_b, t_list *node_b, t_info *info)
{
	t_list	*node_a;

	node_a = find_element(*stack_a, node_b->n_index);
	info->a_index = node_a->index;
	info->b_index = node_b->index;
	if (node_a->index + 1 > info->a_middle && node_b->index + 1 > info->b_middle)
		return (double_rotate(stack_a, stack_b, info, 2));
	else if (node_a->index + 1 < info->a_middle && node_b->index + 1 < info->b_middle)
		return (double_rotate(stack_a, stack_b, info, 1));
	if (node_a->index + 1 <= info->a_middle)
		rotate_decision(stack_a, node_a->content, 1, "ra\n");
	else if (node_a->index + 1 > info->a_middle)
		rotate_decision(stack_a, node_a->content, 2, "rra\n");
	if (node_b->index + 1 <= info->b_middle)
		rotate_decision(stack_b, node_b->content, 1, "rb\n");
	else if (node_b->index + 1 > info->b_middle)
		rotate_decision(stack_b, node_b->content, 2, "rrb\n");
	push_element(stack_b, stack_a, "pa\n");
}

t_list	*best_element(t_list *stack_a, t_list *stack_b, t_info *info)
{
	t_list	*node;
	t_list	*head;
	int		index;

	head = stack_b;
	info->a_len = element_count(stack_a);
	info->b_len = element_count(stack_b);
	info->min_a = ft_min_value(stack_a);
	info->max_a = ft_max_value(stack_a);
	info->min_b = ft_min_value(stack_b);
	info->max_b = ft_max_value(stack_b);
	while (stack_b)
	{
		node = best_position(stack_a, stack_b->content);
		if (node != NULL)
			distance_calcul(node, stack_b, info);
		else
		{
			index = (int)index_finder(stack_a, info->min_a);
			node = find_element(stack_a, index);
			distance_calcul(node, stack_b, info);
		}
		stack_b = stack_b->next;
	}
	stack_b = head;
	node = ft_distance(stack_b, info);
	// printf("node_b:%d ->[%d] (%d)\n", node->content, node->n_index, node->distance);
	return (node);
}