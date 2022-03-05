/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:35:39 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/05 20:36:10 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_first_node(t_list **first_node, int content)
{
	(*first_node) = malloc(sizeof(t_list));
	(*first_node)->content = content;
	(*first_node)->len = 1;
	(*first_node)->distance = 0;
	(*first_node)->p_index = -1;
	(*first_node)->push = 0;
	(*first_node)->next = NULL;
}

t_list	*pop_node(t_list **head)
{
	t_list *node;

	node = *head;
	*head = node->next;
	node->next = NULL;
	return (node); 
}

void	add_node(t_list **first_node, int content)
{
	t_list	*new_node;
	t_list	*tmp;

	if (*first_node != NULL)
	{
		tmp = *first_node;
		new_node = malloc(sizeof(t_list));
		new_node->content = content;
		new_node->p_index = -1;
		new_node->n_index = -1;
		new_node->push = 0;
		new_node->len = 1;
		new_node->distance = 0;
		new_node->next = tmp;
		*first_node = new_node;
	}
	else
		add_first_node(first_node, content);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		// printf("stack: %d[%d]\n", stack->content, stack->index);
		printf("stack: %d [%d] -> %d  (%d)  [%d]\n", stack->content, stack->index, stack->push, stack->len, stack->p_index);
		stack = stack->next;
	}
}