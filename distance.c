/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:44:30 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/05 20:45:49 by yait-iaz         ###   ########.fr       */
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
	if ((node_a->index + 1 > info->a_middle && node_b->index + 1 > info->b_middle) || \
		 (node_a->index + 1 < info->a_middle && node_b->index + 1 < info->b_middle))
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