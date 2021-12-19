/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:33:34 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/19 22:01:44 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_array(int *s)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
			{
				k = s[i];
				s[i] = s[j];
				s[j] = k;
			}
			j++;
		}
		i++;
	}
	return (s);
}

int	*ft_sorted_array(t_list *l)
{
	int		*s;
	int		i;

	i = ft_lstsize(l);
	s = malloc(i * sizeof(long int));
	i = 0;
	while (l)
	{
		s[i] = l->content;
		i++;
		l = l->next;
	}
	return (ft_sort_array(s));
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
