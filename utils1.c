/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:22:22 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:24:50 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_x(t_list *l, int x)
{
	int		i;
	t_list	*t;

	i = 0;
	t = l;
	while (t->index != x)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	ft_find_biggest(t_list *l)
{
	int		x;
	t_list	*t;

	t = l;
	x = t->index;
	t = t->next;
	while (t)
	{
		if (x < t->index)
			x = t->index;
		t = t->next;
	}
	return (ft_find_x(l, x));
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	*ft_sort_array(int *s, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (s[i] > s[j])
			{
				k = s[i];
				s[i] = s[j];
				s[j] = k;
			}
			j++;
		}
		i++;
	}
	return (s);
}

int	*ft_sorted_array(t_list *l)
{
	int	*s;
	int	i;
	int	size;

	i = ft_lstsize(l);
	size = i;
	s = malloc(i * sizeof(long int));
	i = 0;
	while (l)
	{
		s[i] = l->content;
		i++;
		l = l->next;
	}
	return (ft_sort_array(s, size));
}
