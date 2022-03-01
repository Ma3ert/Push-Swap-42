/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:08:27 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/01 16:20:33 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis_lenght(t_list *i, t_list *j)
{
	if (j->content < i->content)
	{
		if ((j->len + 1) > i->len)
			i->len = j->len + 1;
		if ((j->len + 1) >= i->len)
			i->p_index = j->index;
	}
}

int	max_len(t_list *tmp)
{
	int	max_l;

	max_l = tmp->len;
	while (tmp != NULL)
	{
		if (tmp->len > max_l)
			max_l = tmp->len;
		tmp = tmp->next;
	}
	return (max_l);
}

int	ft_markup(t_list *head)
{
	int		n;
	int		max_l;
	t_list	*tmp;

	n = 1;
	tmp = head;
	max_l = max_len(tmp);
	while (tmp->len != max_l && tmp)
		tmp = tmp->next;
	tmp->push = 1;
	while (tmp->p_index != -1)
	{
		tmp = find_element(head, tmp->p_index);
		tmp->push = 1;
		n++;
	}
	return (n);
}

int	ft_lis(t_list *head)
{
	t_list *tmp_j;
	t_list *tmp_i;

	tmp_j = head;
	tmp_i = head->next; 
	while (tmp_i != NULL)
	{
		while (tmp_j != tmp_i)
		{
			ft_lis_lenght(tmp_i, tmp_j);
			tmp_j = tmp_j->next;
		}
		tmp_j = head;
		tmp_i = tmp_i->next;
	}
	return (ft_markup(head));
}