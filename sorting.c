/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:12:06 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/27 20:06:13 by yait-iaz         ###   ########.fr       */
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
	if (index_finder(*stack, value) < n)
		rotate_decision(stack, value, 1);
	else
		rotate_decision(stack, value, 2);
	re_index(*stack);
}

t_list	*best_position(t_list *stack_a, int content)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content < content && stack_a->next->content > content)
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	distance_calcul(t_list *node_a, int a_len, t_list *node_b, int b_len)
{
	int	a_middle;
	int	b_middle;
	int	a_dis;
	int	b_dis;

	a_middle = a_len /2;
	b_middle = b_len /2;
	if (node_a->index + 1 > a_middle)
	{
		a_dis = a_middle - node_a->index + 1;
		a_dis *= -1;
	}
	else
		a_dis = a_middle - node_a->index + 1;
	if (node_b->index + 1 > b_middle)
	{
		b_dis = b_middle - node_b->index + 1;
		b_dis *= -1;
	}
	else
		b_dis = b_middle - node_b->index + 1;
	node_b->distance = b_dis + a_dis;
	node_b->n_index = node_a->index;
}

t_list	*ft_distance(t_list *stack_b)
{
	t_list	*node_b;
	int		max_d;

	max_d = 0;
	while (stack_b)
	{
		if (stack_b->distance > max_d)
		{
			printf("hoho\n");
			node_b = stack_b;
			max_d = stack_b->distance;
		}
		stack_b = stack_b->next;
	}
	return (node_b);
}

t_list	*best_element(t_list *stack_a, t_list *stack_b)
{
	t_list	*node;
	t_list	*head;
	int		index;
	int		b_len;
	int		a_len;
	int		min_a;

	head = stack_b;
	a_len = element_count(stack_a);
	b_len = element_count(stack_b);
	min_a = ft_min_value(stack_a);
	while (stack_b)
	{
		node = best_position(stack_a, stack_b->content);
		if (node != NULL)
			distance_calcul(node, a_len, stack_b, b_len);
		else
		{
			index = (int)index_finder(stack_a, min_a);
			node = find_element(stack_a, index);
			distance_calcul(node, a_len, stack_b, b_len);
		}
		stack_b = stack_b->next;
	}
	// stack_b = head;
	node = ft_distance(stack_b);
	printf("node_b:%d ->[%d] (%d)\n", node->content, node->n_index, node->distance);
	return (node);
}

void	move_best_element(t_list **stack_a, t_list **stack_b, t_list *node_b)
{
	t_list	*node_a;
	stack_b = NULL;

	node_a = find_element(*stack_a, node_b->n_index);
}

void ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;
	t_info	*info;

	info = malloc(sizeof(t_info));
	best = best_element(*stack_a, *stack_b);
	printf("best b :%d\n", best->content);
	move_best_element(stack_a, stack_b, best);
}

void	sort_element(t_list **stack_a, t_list **stack_b, int n)
{
	int		i;
	int		r;
	int		min;

	r = 0;
	i = 0;
	min = ft_min_value(*stack_a);
	re_index(*stack_a);
	if ((*stack_a)->content != min)
		top_element(stack_a, n, min);
	i = n - ft_lis(*stack_a);
	while (i != 0 && r < n)
	{
		if ((*stack_a)->push == 0)
		{
			push_element(stack_a, stack_b);
			i--;
			printf("pa\n");
		}
		else
		{
			rotate_element(stack_a);
			r++;
			printf("ra\n");
		}
	}
	re_index(*stack_a);
	re_index(*stack_b);
	print_stack(*stack_a);
	printf("-------------------------------------\n");
	print_stack(*stack_b);
	printf("------------------before-------------------\n");
	ft_sort(stack_a, stack_b);
	// top_element(stack_a, n, min);
	// while (*stack_b)
	// {
	// 	re_index(*stack_a);
	// 	re_index(*stack_b);
	// }
}
