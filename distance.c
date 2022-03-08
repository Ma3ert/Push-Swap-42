/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:44:30 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/08 15:25:34 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_element(t_list **stack, int value)
{
	double	n;

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
	info->a_mid = info->a_len / 2;
	info->b_mid = info->b_len / 2;
	if (node_a->index == 0)
		info->a_dis = 0;
	else if (node_a->index + 1 > info->a_mid)
		info->a_dis = info->a_len - (node_a->index + 1) + 1;
	else if (node_a->index + 1 <= info->a_mid)
		info->a_dis = node_a->index;
	if (node_b->index == 0)
		info->b_dis = 0;
	else if (node_b->index + 1 > info->b_mid)
		info->b_dis = info->b_len - (node_b->index + 1) + 1;
	else if (node_b->index + 1 <= info->b_mid)
		info->b_dis = node_b->index;
	if ((node_a->index + 1 > info->a_mid && node_b->index + 1 > info->b_mid) || \
		(node_a->index + 1 < info->a_mid && node_b->index + 1 < info->b_mid))
		node_b->distance = ft_max(info->b_dis, info->a_dis);
	else
		node_b->distance = info->b_dis + info->a_dis;
	node_b->n_index = node_a->index;
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
