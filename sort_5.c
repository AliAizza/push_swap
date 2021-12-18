/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:01:38 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/18 10:55:14 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotateandpush(t_list **i, t_list **j)
{
	ft_rotate(i, 'a');
	ft_push(i, j, 'a');
	return (1);
}

int	ft_norm1(t_list **i, t_list **j, int k)
{
	if ((*j)->content < (*i)->content)
	{
		ft_push(i, j, 'a');
		return (1);
	}
	else if ((*j)->content < (*i)->next->content)
		return (ft_rotateandpush(i, j));
	else if ((*j)->content < (*i)->next->next->content)
	{
		ft_rotate(i, 'a');
		return (ft_rotateandpush(i, j));
	}
	else if (k == 0)
	{
		if ((*j)->content > (*i)->next->next->content)
		{
			ft_push(i, j, 'a');
			ft_rotate(i, 'a');
			return (1);
		}
	}
	return (0);
}

void	ft_norm2(t_list **i, t_list **j)
{
	if ((*j)->content < (*i)->next->next->next->content)
	{
		ft_rev_rotate(i, 'a');
		ft_push(i, j, 'a');
	}
	else if ((*j)->content > (*i)->next->next->next->content)
	{
		ft_push(i, j, 'a');
		ft_rotate(i, 'a');
	}
}

void	ft_norm3(t_list **i)
{
	int	k;

	k = ft_find_min(*i);
	while (!ft_lst_sortcheck(*i))
	{
		if (k > 2)
			ft_rev_rotate(i, 'a');
		else
			ft_rotate(i, 'a');
	}
}

void	ft_sort_5(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;
	int		k;
	int		z;

	k = 0;
	if (ft_lstsize(*a) == 5)
		ft_push(b, a, 'b');
	ft_push(b, a, 'b');
	ft_sort_3(a);
	i = *a;
	j = *b;
	while (k < 2 && j)
	{
		z = 0;
		z += ft_norm1(&i, &j, k);
		if (k == 1 && z == 0)
			ft_norm2(&i, &j);
		k++;
		while (!ft_lst_sortcheck(i))
			ft_rev_rotate(&i, 'a');
	}
	ft_norm3(&i);
	*a = i;
	*b = j;
}
