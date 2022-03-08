/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:18:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/08 18:12:22 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "rrr\n", 3))
	{
		reverse_rotate(stack_b, "");
		reverse_rotate(stack_a, "");
	}
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate_element(stack_b, "");
		rotate_element(stack_a, "");
	}
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap_element(*stack_b, "");
		swap_element(*stack_a, "");
	}
}

void	apply_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_element(*stack_a, "");
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_element(*stack_b, "");
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_element(stack_a, "");
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_element(stack_b, "");
	else if (!ft_strncmp(str, "pa\n", 3))
		push_element(stack_b, stack_a, "");
	else if (!ft_strncmp(str, "pb\n", 3))
		push_element(stack_a, stack_b, "");
	else if (!ft_strncmp(str, "rra\n", 3))
		reverse_rotate(stack_a, "");
	else if (!ft_strncmp(str, "rrb\n", 3))
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
	printf("stack_a: %p\n", *stack_a);
	printf("stack_b: %p\n", *stack_b);
	while (str[0] != '\n')
	{
		apply_instruction(stack_a, stack_b, str);
		printf("stack_a: %p\n", *stack_a);
		printf("stack_b: %p\n", *stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (check_sort(*stack_a) == 1 && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	printf("stack_a: %p\n", *stack_a);
	printf("stack_b: %p\n", *stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = ac - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (arg_validation(av) == 0)
	{
		write(2, "Error!\n", 7);
		return (0);
	}
	while (i > 0)
		add_node(&stack_a, ft_atoi(av[i--]));
	check_instruction(&stack_a, &stack_b);
	printf("stack_a: %d\n", stack_a->content);
	free_stack(stack_a);
	free_stack(stack_b);
}
