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

void	add_node(t_list **first_node, int content)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = *first_node;
	new_node = malloc(sizeof(t_list));
	new_node->content = content;
	new_node->index = tmp->index + 1;
	new_node->next = tmp;
	*first_node = new_node;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list *tmp;
	int		i;

	i = 1;
	if (arg_validation(av) == 0)
	{
		write(1, "unvalid argument", 16);
		return (0);
	}
	stack_b = malloc(sizeof(t_list));
	stack_a = malloc(sizeof(t_list));
	stack_a->content = ft_atoi(av[i++]);
	stack_a->index = 0;
	stack_a->next = NULL;
	while(i < ac)
		add_node(&stack_a, ft_atoi(av[i++]));
	tmp = stack_a;
	while (tmp)
	{
		printf("stack_a:%d [%d]\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
	rotate_element(&stack_a);
	reverse_rotate(&stack_a);
	sort_element(&stack_a, &stack_b, ac - 1);
	while (stack_a)
	{
		printf("stack_a:%d [%d]\n", stack_a->content, stack_a->index);
		stack_a = stack_a->next;
	}
	// while (stack_b)
	// {
	// 	printf("stack_b:%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
}
