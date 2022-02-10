/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:35:17 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/10 23:27:08 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **head, char c)
{
	t_list	*tmp;

	if (ft_lstsize(*head) < 2)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	if (c == 'a')
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	ft_push(t_list **i, t_list **j, char c)
{
	t_list	*tmp;

	if (!(*j))
		return ;
	tmp = *j;
	*j = (*j)->next;
	tmp->next = NULL;
	ft_lstadd_front(i, tmp);
	if (c == 'a')
		ft_putstr("pa\n");
	else if (c == 'b')
		ft_putstr("pb\n");
}

void	ft_rotate(t_list **a, char c)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
}

void	ft_rev_rotate(t_list **a, char c)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = ft_lstlast(*a);
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	ft_lstadd_front(a, tmp);
	last->next = NULL;
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
}
