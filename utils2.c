/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:22:57 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/18 00:50:49 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_index(int data, int *arr, t_list **a)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(*a))
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (0);
}

void	ft_index(t_list **a)
{
	int		*t;
	t_list	*tmp;

	t = ft_sorted_array(*a);
	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = ft_create_index(tmp->content, t, a);
		tmp = tmp->next;
	}
	free(t);
}

int	ft_chunk(t_list **a)
{
	int	count;
	int	chunk;
	int	size;

	size = ft_lstsize(*a);
	if (size <= 100)
		chunk = 3;
	else
		chunk = 5;
	count = ((ft_lstsize(*a) - 5) / chunk) + 1;
	return (count);
}

void	ft_norminette2(t_list **a, t_list **b, int p)
{
	if (p < ft_lstsize(*a) / 2)
	{
		while (p)
		{
			ft_rotate(a, 'a');
			p--;
		}
		ft_push(b, a, 'b');
	}
	else
	{
		while (p < ft_lstsize(*a))
		{
			ft_rev_rotate(a, 'a');
			p++;
		}
		ft_push(b, a, 'b');
	}
}

void	ft_push_to_b(t_list **a, t_list **b, t_norm g, int p)
{	
	g.med = (g.min + g.max) / 2;
	if ((*a)->index >= g.min && (*a)->index <= g.max)
		ft_push(b, a, 'b');
	else
	{
		ft_norminette2(a, b, p);
		if ((*b)->index < g.med)
			ft_rotate(b, 'b');
	}
}
