/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:56 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/09 16:06:22 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = NULL;
		i = ac - 1;
		if (arg_validation(av) == 0)
		{
			write(2, "Error!\n", 7);
			return (0);
		}
		while (i > 0)
			add_node(&stack_a, ft_atoi(av[i--]));
		sort_element(&stack_a, &stack_b, ac - 1);
		print_stack(stack_a);
		print_stack(stack_b);
		free_stack(stack_a);
	}
}
