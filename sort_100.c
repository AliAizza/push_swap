/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:56 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:44:52 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make(t_list **a, t_list **b, int count, t_norm g)
{
	int	p;

	while (count > 0)
	{
		p = ft_find_position(a, g.min, g.max);
		ft_push_to_b(a, b, g, p);
		count--;
	}
}

void	ft_convert_last(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->index = -1;
}

int	ft_is_there(t_list *l, int x)
{
	t_list	*tmp;

	tmp = l;
	while (tmp)
	{
		if (tmp->index == x)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_norminette(t_list **a, t_list **b, int k, int p)
{
	int	last;	

	last = ft_lstlast(*a)->index;
	if (k == (*b)->index)
		ft_push(a, b, 'a');
	else
	{
		if ((*b)->index < (*a)->index && (*b)->index > last)
		{
			ft_push(a, b, 'a');
			ft_rotate(a, 'a');
		}
		else
		{
			if (p < ft_lstsize(*b) / 2)
				ft_rotate(b, 'b');
			else
				ft_rev_rotate(b, 'b');
		}
	}
}

void	ft_push_back_to_a(t_list **a, t_list **b, int k)
{
	int	z;
	int	p;

	z = ft_lstsize(*b);
	while (z)
	{
		p = ft_find_biggest(*b);
		if (ft_is_there(*b, k))
			ft_norminette(a, b, k, p);
		else
			ft_rev_rotate(a, 'a');
		z = ft_lstsize(*b);
		k = (*a)->index - 1;
	}
}
