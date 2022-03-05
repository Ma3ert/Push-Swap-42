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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	stack_a = NULL;
	i = ac - 1;
	if (arg_validation(av) == 0)
	{
		write(1, "unvalid argument", 16);
		return (0);
	}
	while(i > 0)
		add_node(&stack_a, ft_atoi(av[i--]));
	// print_stack(stack_a);
	// printf("-------------------------------------\n");
	// print_stack(stack_b);
	sort_element(&stack_a, &stack_b, ac - 1);
	// print_stack(stack_a);
	// printf("-------------------------------------\n");
	// print_stack(stack_b);
}
