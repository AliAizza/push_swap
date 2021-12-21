/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:32:14 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/20 19:12:37 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nor1(t_list **a, t_list **b, int z)
{
	if (z > ft_lstsize(*a) / 2)
	{
		z = ft_lstsize(*a) - z;
		while (z > 0)
		{
			ft_rev_rotate(a, 'a');
			z--;
		}
		ft_push(b, a, 'b');
	}
	else
	{
		while (z > 0)
		{
			ft_rotate(a, 'a');
			z--;
		}
		ft_push(b, a, 'b');
	}
}

void	ft_nor2(t_list **a, t_list **b, int k)
{
	if (k > ft_lstsize(*b) / 2)
	{
		k = ft_lstsize(*b) - k;
		while (k > 0)
		{
			ft_rev_rotate(b, 'b');
			k--;
		}
		ft_push(a, b, 'a');
	}
	else
	{
		while (k > 0)
		{
			ft_rotate(b, 'b');
			k--;
		}
		ft_push(a, b, 'a');
	}
}

void	ft_sort1(t_list **a, t_list **b, int p)
{
	int		z;
	t_list	*h;

	while (ft_there_is_smaller(*a, p) && (*a))
	{
		z = 0;
		h = *a;
		while (h->content > p && h)
		{
			z++;
			h = h->next;
		}
		ft_nor1(a, b, z);
	}
}

void	ft_sort2(t_list **a, t_list **b)
{
	int	k;

	while (*a)
	{
		k = ft_find_min_index(*a);
		ft_nor1(a, b, k);
	}
}

void	ft_sort3(t_list **a, t_list **b)
{
	int	k;

	while (*b)
	{
		k = ft_find_biggest(*b);
		ft_nor2(a, b, k);
	}
}
