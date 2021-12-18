/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:59:02 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/18 10:49:19 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_list **a)
{
	t_list	*t;

	if (ft_lstsize(*a) < 2)
		return ;
	t = *a;
	if (t->content > t->next->content)
		ft_swap(a, 'a');
}

void	ft_norm(t_list	**t)
{
	if (((*t)->content > (*t)->next->content
			&& (*t)->next->content < (*t)->next->next->content)
		&& ((*t)->content > (*t)->next->content
			&& (*t)->content > (*t)->next->next->content))
		ft_rotate(t, 'a');
	if ((*t)->content > (*t)->next->content
		&& (*t)->next->content < (*t)->next->next->content)
		ft_sort_2(t);
	if ((*t)->content > (*t)->next->next->content
		&& (*t)->next->content > (*t)->next->next->content)
	{
		ft_sort_2(t);
		ft_rev_rotate(t, 'a');
	}
}

void	ft_sort_3(t_list **a)
{
	t_list	*t;

	t = *a;
	ft_norm(&t);
	if (t->content > t->next->content
		&& t->content > t->next->next->content)
	{
		ft_rotate(&t, 'a');
		ft_sort_2(&t);
	}
	if (t->content < t->next->content
		&& t->next->content > t->next->next->content)
	{
		ft_rev_rotate(&t, 'a');
		ft_sort_2(&t);
	}
	*a = t;
}
