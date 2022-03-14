/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:55:02 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/14 13:36:18 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_count(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		count++;
		i++;
	}
	return (count);
}

char	**adjust_arg(char **av, int *ac)
{
	int		i;
	int		j;
	char	**arg;
	char	*tmp;

	i = 0;
	j = 0;
	arg = NULL;
	tmp = ft_strdupi(av[i], ft_strlen(av[i]));
	i++;
	while (av[i])
	{
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, av[i]);
		i++;
	}
	arg = ft_split(tmp, ' ');
	free(tmp);
	*ac = string_count(arg);
	return (arg);
}
