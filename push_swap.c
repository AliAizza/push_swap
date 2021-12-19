/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:38:54 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/19 17:07:36 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (!ft_error_check(argv) || argc < 2)
		return (0);
	a = ft_make_list(argc, argv);
	if (!ft_lst_sortcheck(a))
	{
		if (ft_lstsize(a) <= 2)
			ft_sort_2(&a);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else if (ft_lstsize(a) <= 5)
			ft_sort_5(&a, &b);
		else if (ft_lstsize(a) <= 100)
			ft_sort_100(&a, &b);
		else
			ft_sort_500(&a, &b);
	}
}
