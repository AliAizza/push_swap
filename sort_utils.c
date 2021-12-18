/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:33:34 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/18 16:37:10 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_copy(t_list *l)
{
	t_list	*copy;

	copy = ft_lstnew(l->content);
	l = l->next;
	while (l)
	{
		ft_lstadd_back(&copy, ft_lstnew(l->content));
		l = l->next;
	}
	return (copy);
}

t_list	*ft_lst_sortlist(t_list *l)
{
	t_list	*s;
	t_list	*r;
	t_list	*t;
	int		f;

	t = ft_copy(l);
	r = t;
	while (!ft_lst_sortcheck(t))
	{
		s = t->next;
		while (s)
		{
			if (t->content > s->content)
			{
				f = s->content;
				s->content = t->content;
				t->content = f;
			}
			s = s->next;
		}
		t = t->next;
	}
	return (r);
}

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
