/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/02 17:43:16 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_element(t_list *first_element, char *str)
{
	int		content;
	int		content2;

	content = first_element->content;
	content2 = first_element->next->content;
	first_element->content = content2;
	first_element->next->content = content;
	ft_putstr(str);
}