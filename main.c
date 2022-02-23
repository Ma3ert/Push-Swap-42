// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:56 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/10 15:41:22 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_first_node(t_list **first_node, int content)
{
	(*first_node) = malloc(sizeof(t_list));
	(*first_node)->content = content;
	(*first_node)->index = 0;
	(*first_node)->len = 1;
	(*first_node)->p_index = -1;
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
		new_node->index = tmp->index + 1;
		new_node->p_index = -1;
		new_node->len = 1;
		new_node->next = tmp;
		*first_node = new_node;
	}
	else
		add_first_node(first_node, content);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	if (arg_validation(av) == 0)
	{
		write(1, "unvalid argument", 16);
		return (0);
	}
	while(i < ac)
		add_node(&stack_a, ft_atoi(av[i++]));
	sort_element(&stack_a, &stack_b, ac - 1);
	while (stack_a)
	{
		// printf("stack_a: %d\n", stack_a->content);
		printf("stack_a: %d [%d] -> %d  (%d)  [%d]\n", stack_a->content, stack_a->index, stack_a->push, stack_a->len, stack_a->p_index);
		// printf("-------------------------------------\n");
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("stack_b:%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}
