/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:42:34 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/14 15:11:32 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_d(const char *s, char c)
{
	int		i;
	int		count;
	int		end;

	i = 0;
	count = 0;
	end = (int)ft_strlen(s) - 1;
	while (s[i] == c)
		i++;
	while (s[end] == c)
		end--;
	end += 1;
	while (s[i] && end >= i)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (end == (int)ft_strlen(s))
		count++;
	return (count);
}

static int	l_i(const char *s, char c, int i, int *l)
{
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		(*l)++;
		i++;
	}
	return (i);
}

void	free_t(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL ;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	int		count;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	count = count_d(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (0);
	while (s[i] && count > j)
	{
		l = 0;
		i = l_i(s, c, i, &l);
		str[j] = ft_strdupi(&s[i - l], l);
		if (!str[j])
			free_t(str);
		j++;
	}
	str[j] = 0;
	return (str);
}
