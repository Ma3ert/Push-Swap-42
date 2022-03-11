/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:55:02 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/11 20:10:37 by yait-iaz         ###   ########.fr       */
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
		{
			j++;
		}
		count++;
		i++;
	}
	return (count);
}

char	**join_arg(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**str;
	int		count;

	i = 0;
	j = 0;
	count = string_count(s1) + string_count(s2);
	str = (char **)malloc(sizeof(char *) * count + 1);
	while (s1[i] && i < count)
	{
		str[i] = ft_strdupi(s1[i], ft_strlen(s1[i]));
		if (!str[i])
			free_t(str, count);
		i++;
	}
	while (s2[j] && i < count)
	{
		str[i] = ft_strdupi(s2[j], ft_strlen(s2[j]));
		if (!str[i])
			free_t(str, count);
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	**adjust_arg(char **av, int *ac)
{
	int	i;
	char **arg;
	char **tmp;

	i = 0;
	while (av[i])
	{
		if (count_d(av[i], ' ') != 0)
		{
			tmp = ft_split(av[i], ' ');
			*ac += string_count(tmp) - 1;
			arg = join_arg(arg, tmp);
		}
		else
			arg = join_arg(arg, &av[i]);
		i++;
	}
	return (arg);
}