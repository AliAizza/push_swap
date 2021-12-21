/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:29 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/20 18:56:12 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_x(t_list *l, int x)
{
	int		i;
	t_list	*t;

	i = 0;
	t = l;
	while (t->content != x)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	ft_find_min(t_list *l)
{
	int	x;

	x = l->content;
	l = l->next;
	while (l)
	{
		if (x > l->content)
			x = l->content;
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

int	ft_find_biggest(t_list *l)
{
	int		x;
	t_list	*t;

	t = l;
	x = t->content;
	t = t->next;
	while (t)
	{
		if (x < t->content)
			x = t->content;
		t = t->next;
	}
	return (ft_find_x(l, x));
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
