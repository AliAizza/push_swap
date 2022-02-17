/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:33:34 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:50:54 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_sortcheck(t_list *head)
{
	int	i;
	int	j;

	i = ft_lstsize(head);
	j = i;
	while (j > 1)
	{
		if (head->content < head->next->content)
			i--;
		j--;
		head = head->next;
	}
	if (i == 1)
		return (i);
	return (0);
}

int	ft_there_is_smaller(t_list *l, int x)
{
	while (l)
	{
		if (l->content <= x)
			return (1);
		l = l->next;
	}
	return (0);
}

int	ft_find_position(t_list **a, int min, int max)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
