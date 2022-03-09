/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:50 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/09 18:03:35 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_value(char *str, char *str2)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(str);
	while (i <= n)
	{
		if (ft_strncmp(&str[i], &str2[i], 1) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_range(char *str)
{
	int	i;
	int	n;

	n = ft_strlen(str);
	i = 0;
	if (n > 11)
		return (0);
	if (n == 10)
		return (check_value(str, MAX_INT));
	else if (n == 11 && str[i] == '-')
		return (check_value(str, MIN_INT));
	return (1);
}

int	arg_validation(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (av[i])
	{
		while (av[j])
		{
			if (is_num(av[i]) == 1 && is_num(av[j]) == 1 \
				&& check_range(av[i]) == 1)
			{
				if (j != i && (ft_strcmp(av[j], av[i]) == 0))
					return (0);
			}
			else
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}
