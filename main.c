/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:56 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/11 17:52:07 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*max;
	t_list	*min;

	re_index(*stack);
	max = find_element(*stack, index_finder(*stack, ft_max_value(*stack)));
	min = find_element(*stack, index_finder(*stack, ft_min_value(*stack)));
	if (max->index == 2 && min->index == 0)
		return ;
	else if (max->index == 0 && min->index != 2)
		rotate_element(stack, "ra\n");
	else if (max->index != 0 && min->index == 2)
		reverse_rotate(stack, "rra\n");
	else if (max->index == 2 && min->index != 0)
		swap_element(*stack, "sa\n");
	else if (max->index == 0 && min->index == 2)
	{
		rotate_element(stack, "ra\n");
		swap_element(*stack, "sa\n");
	}
	else if (max->index != 0 && min->index == 0)
	{
		reverse_rotate(stack, "rra\n");
		swap_element(*stack, "sa\n");
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = NULL;
		av = adjust_arg(av, &ac);
		i = ac - 1;
		if (arg_validation(av) == 0)
		{
			write(2, "Error!\n", 7);
			return (0);
		}
		while (i > 0)
			add_node(&stack_a, ft_atoi(av[i--]));
		if (ac == 4)
			sort_three(&stack_a);
		else
			sort_element(&stack_a, &stack_b, ac - 1);
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
