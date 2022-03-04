/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:12:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/04 21:27:09 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_count(t_list *stack)
{
	int	n;

	n = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

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

void	top_element(t_list **stack, int value)
{
	double n;

	n = element_count(*stack);
	n = (n / 2.0);
	re_index(*stack);
	if (index_finder(*stack, value) < n)
		rotate_decision(stack, value, 1, "ra\n");
	else
		rotate_decision(stack, value, 2, "rra\n");
	re_index(*stack);
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

void	distance_calcul(t_list *node_a, t_list *node_b, t_info *info)
{
	info->a_middle = info->a_len / 2;
	info->b_middle = info->b_len / 2;
	if (node_a->index == 0)
		info->a_dis = 0;
	else if (node_a->index + 1 > info->a_middle)
		info->a_dis = info->a_len - (node_a->index + 1) + 1;
	else if (node_a->index + 1 <= info->a_middle)
		info->a_dis = node_a->index;
	if (node_b->index == 0)
		info->b_dis = 0;
	else if (node_b->index + 1 > info->b_middle)
		info->b_dis = info->b_len - (node_b->index + 1) + 1;
	else if (node_b->index + 1 <= info->b_middle)
		info->b_dis = node_b->index;
	if ((node_a->index + 1 > info->a_middle && node_b->index > info->b_middle) || \
		 (node_a->index + 1 < info->a_middle && node_b->index < info->b_middle))
		node_b->distance = ft_max(info->b_dis, info->a_dis);
	else
		node_b->distance = info->b_dis + info->a_dis;
	node_b->n_index = node_a->index;
	// printf("a_dis : %d\nb_dis : %d\n", info->a_dis, info->`b_dis);
	// printf("b_content:%d[%d](%d) \ndistance: %d\ncontent_a :%d[%d](%d)\n", \
	// node_b->content, node_b->index, info->b_middle, node_b->distance, node_a->content, node_b->n_index, info->a_middle);
	// printf("----------------------------------------------------\n");
}

t_list	*ft_distance(t_list *stack_b, t_info *info)
{
	t_list	*node_b;
	int		min_d;

	min_d = info->b_len + info->a_len;
	while (stack_b)
	{
		if (stack_b->distance < min_d)
		{
			node_b = stack_b;
			min_d = stack_b->distance;
		}
		stack_b = stack_b->next;
	}
	return (node_b);
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

void	rr_decision(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int		n;
	t_list	*node_a;
	t_list	*node_b;

	n = info->min;
	node_a = find_element(*stack_a, info->a_index);
	node_b = find_element(*stack_b, info->b_index);
	while ((*stack_a)->content != node_a->content && (*stack_b)->content != node_b->content)
	{
		rotate_element(stack_a, "");
		rotate_element(stack_b, "");
		ft_putstr("rr\n");
	}
	if ((*stack_a)->content != node_a->content)
	{
		while ((*stack_a)->content != node_a->content)
			rotate_element(stack_a, "ra\n");
	}
	if ((*stack_b)->content != node_b->content)
	{
		while ((*stack_b)->content != node_b->content)
			rotate_element(stack_b, "rb\n");
	}
	push_element(stack_b, stack_a, "pa\n");
}

void	rrr_decision(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int		n;
	t_list	*node_a;
	t_list	*node_b;

	n = info->min;
	node_a = find_element(*stack_a, info->a_index);
	node_b = find_element(*stack_b, info->b_index);
	while ((*stack_a)->content != node_a->content && (*stack_b)->content != node_b->content)
	{
		reverse_rotate(stack_a, "");
		reverse_rotate(stack_b, "");
		ft_putstr("rrr\n");
	}
	if ((*stack_a)->content != node_a->content)
	{
		while ((*stack_a)->content != node_a->content)
			reverse_rotate(stack_a, "rra\n");
	}
	if ((*stack_b)->content != node_b->content)
	{
		while ((*stack_b)->content != node_b->content)
			reverse_rotate(stack_b, "rrb\n");
	}
	push_element(stack_b, stack_a, "pa\n");
}

void	double_rotate(t_list **stack_a, t_list **stack_b, t_info *info, int dec)
{
	info->min = ft_min(info->a_dis, info->b_dis);
	if (dec == 1)
		rr_decision(stack_a, stack_b, info);
	if (dec == 2)
		rrr_decision(stack_a, stack_b, info);
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

void ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;
	t_info	info;

	best = best_element(*stack_a, *stack_b, &info);
	// printf("best b:%d[%d] -> (%d)\n", best->content, best->index, best->n_index);
	move_best_element(stack_a, stack_b, best, &info);
}

void	sort_element(t_list **stack_a, t_list **stack_b, int n)
{
	int		i;
	int		min;

	i = 0;
	min = ft_min_value(*stack_a);
	re_index(*stack_a);
	i = n - ft_lis(*stack_a);
	re_index(*stack_a);
	while (i != 0)
	{
		if ((*stack_a)->push == 0)
		{
			push_element(stack_a, stack_b, "pb\n");
			i--;
		}
		else
			rotate_element(stack_a, "ra\n");
	}
	// printf("-----------lis-------------\n");
	re_index(*stack_a);
	re_index(*stack_b);
	while (*stack_b)
	{
		ft_sort(stack_a, stack_b);
		re_index(*stack_a);
		re_index(*stack_b);
		// print_stack(*stack_a);
		// printf("-------------------------------------\n");
		// print_stack(*stack_b);
		// printf("------------------before-------------------\n");
	}
	// printf("-----------sort-------------\n");
	top_element(stack_a, min);
	// printf("-----------min-------------\n");
}
