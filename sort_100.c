/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:28:56 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/20 19:02:26 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_list **a, t_list **b)
{
	int	*t;
	int	k;
	int	p;
	int	i;
	int	j;

	i = 0;
	t = ft_sorted_array(*a);
	k = ft_lstsize(*a) / 4;
	j = k;
	p = ft_find_by_index(t, k);
	while (i < 3)
	{	
		ft_sort1(a, b, p);
		k += j;
		p = ft_find_by_index(t, k);
		i++;
	}
	free(t);
	ft_sort2(a, b);
	ft_sort3(a, b);
}

void	ft_sort_500(t_list **a, t_list **b)
{
	int	*t;
	int	k;
	int	p;
	int	i;
	int	j;

	i = 0;
	t = ft_sorted_array(*a);
	k = ft_lstsize(*a) / 13;
	j = k;
	p = ft_find_by_index(t, k);
	while (i < 12)
	{	
		ft_sort1(a, b, p);
		k += j;
		p = ft_find_by_index(t, k);
		i++;
	}
	free(t);
	ft_sort2(a, b);
	ft_sort3(a, b);
}
