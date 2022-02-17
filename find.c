/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:29 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:20:44 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_list *l)
{
	int	x;

	x = l->index;
	l = l->next;
	while (l)
	{
		if (x > l->index)
			x = l->index;
		l = l->next;
	}
	return (x);
}

int	ft_find_by_index(int *s, int index)
{
	int	i;

	i = 0;
	while (i < index - 1)
		i++;
	return (s[i]);
}

int	ft_find_min_index(t_list *l)
{
	int		x;
	t_list	*t;

	t = l;
	x = t->content;
	t = t->next;
	while (t)
	{
		if (x > t->content)
			x = t->content;
		t = t->next;
	}
	return (ft_find_x(l, x));
}
