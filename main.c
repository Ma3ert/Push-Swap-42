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
	new_node->next = tmp;
	*first_node = new_node;
}

int	main(int ac, char **av)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = malloc(sizeof(t_list));
	stack->content = ft_atoi(av[i++]);
	stack->next = NULL;
	stack->head = 1;
	while(i < ac)
		add_node(&stack, ft_atoi(av[i++]));
	// rotate_element(&stack);
	reverse_rotate(&stack);
	while (stack)
	{
		printf("stack:%d\n", stack->content);
		stack = stack->next;
	}
}
