/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:12:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/14 13:46:15 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_decision(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int		n;
	t_list	*node_a;
	t_list	*node_b;

	n = info->min;
	node_a = find_element(*stack_a, info->a_index);
	node_b = find_element(*stack_b, info->b_index);
	while ((*stack_a)->content != node_a->content && \
		(*stack_b)->content != node_b->content)
	{
		rotate_element(stack_a, "");
		rotate_element(stack_b, "");
		ft_putstr("rr\n");
	}
	while ((*stack_a)->content != node_a->content)
		rotate_element(stack_a, "ra\n");
	while ((*stack_b)->content != node_b->content)
		rotate_element(stack_b, "rb\n");
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
	while ((*stack_a)->content != node_a->content && \
		(*stack_b)->content != node_b->content)
	{
		reverse_rotate(stack_a, "");
		reverse_rotate(stack_b, "");
		ft_putstr("rrr\n");
	}
	while ((*stack_a)->content != node_a->content)
		reverse_rotate(stack_a, "rra\n");
	while ((*stack_b)->content != node_b->content)
		reverse_rotate(stack_b, "rrb\n");
	push_element(stack_b, stack_a, "pa\n");
}

void	double_rotate(t_list **a, t_list **b, t_info *info, int dec)
{
	info->min = ft_min(info->a_dis, info->b_dis);
	if (dec == 1)
		rr_decision(a, b, info);
	if (dec == 2)
		rrr_decision(a, b, info);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;
	t_info	info;

	best = best_element(*stack_a, *stack_b, &info);
	move_best_element(stack_a, stack_b, best, &info);
}

void	sort_element(t_list **stack_a, t_list **stack_b, int n)
{
	int		i;
	int		min;

	i = 0;
	if (n <= 5)
		sort_five_less(stack_a, stack_b, n);
	else
	{	
		min = ft_min_value(*stack_a);
		re_index(*stack_a);
		i = n - ft_lis(*stack_a);
		push_lis(stack_a, stack_b, i);
		re_index(*stack_a);
		re_index(*stack_b);
		while (*stack_b)
		{
			ft_sort(stack_a, stack_b);
			re_index(*stack_a);
			re_index(*stack_b);
		}
		top_element(stack_a, min);
	}
}
