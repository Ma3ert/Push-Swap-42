/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:25:26 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/06 13:33:29 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int main()
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		printf("str: %s", str);
		str = get_next_line(STDIN_FILENO);
		if (str[i] == '\n')
			break ;
	}
	printf("ok\n");
	return (0);
}