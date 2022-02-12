/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:23:24 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/07 11:23:49 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check(char str)
{
	if (str == ' ' || str == '\t'
		|| str == '\n' || str == '\v'
		|| str == '\r' || str == '\f')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (check(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] - '0' + nb * 10;
		i++;
	}
	return (sign * nb);
}