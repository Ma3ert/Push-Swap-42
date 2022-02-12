/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:59 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/02/09 13:14:05 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_element(t_list *first_element)
{
	int		content;
	int		content2;

	// printf("hoho\n");
	content = first_element->content;
	content2 = first_element->next->content;
	first_element->content = content2;
	first_element->next->content = content;
}