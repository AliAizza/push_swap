/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:38:54 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:53:51 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_list **a, t_list **b)
{
	int		size;
	int		count;
	int		k;
	t_norm	g;

	ft_index(a);
	size = ft_lstsize(*a);
	while (size > 5)
	{
		count = ft_chunk(a);
		g.min = ft_find_min(*a);
		g.max = (count + g.min) - 1;
		ft_make(a, b, count, g);
		size = ft_lstsize(*a);
	}
	ft_sort_5(a, b);
	ft_convert_last(a);
	k = (*a)->index - 1;
	ft_push_back_to_a(a, b, k);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (!ft_error_check(argv) || argc < 3)
		return (0);
	a = ft_make_list(argc, argv);
	if (!ft_lst_sortcheck(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sort_2(&a);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else if (ft_lstsize(a) <= 5)
			ft_sort_5(&a, &b);
		else
			ft_sort_100(&a, &b);
	}
	while (!ft_lst_sortcheck(a))
		ft_rev_rotate(&a, 'a');
}
