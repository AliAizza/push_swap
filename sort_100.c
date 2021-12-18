/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:56 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/18 17:35:10 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_list **a, t_list **b)
{
	t_list	*t;
	int		k;
	int		p;
	int		i;

	i = 0;
	t = ft_lst_sortlist(*a);
	k = ft_lstsize(t) / 4;
	p = ft_find_by_index(t, k);
	while (i < 3)
	{	
		ft_sort1(a, b, p);
		k += (ft_lstsize(t) / 4);
		p = ft_find_by_index(t, k);
		i++;
	}
	ft_sort2(a, b);
	ft_sort3(a, b);
}

void	ft_sort_500(t_list **a, t_list **b)
{
	t_list	*t;
	int		k;
	int		p;
	int		i;

	i = 0;
	t = ft_lst_sortlist(*a);
	k = ft_lstsize(t) / 13;
	p = ft_find_by_index(t, k);
	while (i < 12)
	{	
		ft_sort1(a, b, p);
		k += (ft_lstsize(t) / 13);
		p = ft_find_by_index(t, k);
		i++;
	}
	ft_sort2(a, b);
	ft_sort3(a, b);
}
