/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:58:21 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/11 20:15:27 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	av = adjust_arg(av, &ac);
	printf("ac : %d\n", ac);
	i = ac;
	while (i > 0)
	{
		printf("arg[%d]: %s\n", i, av[i]);
		i--;
	}
}