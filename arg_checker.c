/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:50 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/21 15:36:25 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
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
			if (is_num(av[i]) == 1 && is_num(av[j]) == 1)
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
