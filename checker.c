/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:18:51 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/05 20:16:25 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && n > 0)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
		n--;
	}
	return (0);
}

void	apply_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3))
		swap_element(*stack_a, "");
	else if (ft_strncmp(str, "sb\n", 3))
		swap_element(*stack_b, "");
	else if (ft_strncmp(str, "ra\n", 3))
		rotate_element(stack_a, "");
	else if (ft_strncmp(str, "rb\n", 3))
		rotate_element(stack_b, "");	
	else if (ft_strncmp(str, "pa\n", 3))
		push_element(stack_b, stack_a, "");
	else if (ft_strncmp(str, "pb\n", 3))
		push_element(stack_a, stack_b, "");
	else if (ft_strncmp(str, "rra\n", 3))
		reverse_rotate(stack_a, "");
	else if (ft_strncmp(str, "rrb\n", 3))
		reverse_rotate(stack_b, "");	
	else if (ft_strncmp(str, "rrr\n", 3))
	{
		reverse_rotate(stack_b, "");
		reverse_rotate(stack_a, "");
	}
	else if (ft_strncmp(str, "rr\n", 3))
	{
		rotate_element(stack_b, "");
		rotate_element(stack_a, "");
	}
}

int	check_sort(t_list **stack_a)
{
	while (*stack_a)
	{
		if ((*stack_a)->content < (*stack_a)->next->content)
			*stack_a = (*stack_a)->next;
		else
			return (0);
	}
	return (1);
}

void	check_instruction(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		apply_instruction(stack_b, stack_a, str);
		str = get_next_line(0);
	}
	if (check_sort(stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
}