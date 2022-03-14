/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:18:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/14 17:05:17 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "rrr\n"))
	{
		reverse_rotate(stack_b, "");
		reverse_rotate(stack_a, "");
	}
	else if (!ft_strcmp(str, "rr\n"))
	{
		rotate_element(stack_b, "");
		rotate_element(stack_a, "");
	}
	else if (!ft_strcmp(str, "ss\n"))
	{
		swap_element(*stack_b, "");
		swap_element(*stack_a, "");
	}
	else
	{
		write(2, "Error!\n", 8);
		exit(1);
	}
}

void	apply_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap_element(*stack_a, "");
	else if (!ft_strcmp(str, "sb\n"))
		swap_element(*stack_b, "");
	else if (!ft_strcmp(str, "ra\n"))
		rotate_element(stack_a, "");
	else if (!ft_strcmp(str, "rb\n"))
		rotate_element(stack_b, "");
	else if (!ft_strcmp(str, "pa\n"))
		push_element(stack_b, stack_a, "");
	else if (!ft_strcmp(str, "pb\n"))
		push_element(stack_a, stack_b, "");
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate(stack_a, "");
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate(stack_b, "");
	else
		double_instruction(stack_a, stack_b, str);
}

int	check_sort(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

void	check_instruction(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		apply_instruction(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (check_sort(*stack_a) == 1 && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		i;
	char	**arg;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arg = adjust_arg(av, &ac);
	i = ac - 1;
	if (arg_validation(arg) == 0)
	{
		free_t(arg);
		write(2, "Error!\n", 7);
		return (0);
	}
	while (i > 0)
		add_node(&stack_a, ft_atoi(arg[i--]));
	check_instruction(&stack_a, &stack_b);
	free_t(arg);
	free_stack(stack_a);
	free_stack(stack_b);
}
