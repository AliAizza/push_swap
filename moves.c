/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:35:17 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/19 17:07:30 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **head, char c)
{
	t_list	*t;
	t_list	*a;

	a = *head;
	t = ft_lstnew(a->content);
	a->content = a->next->content;
	a->next->content = t->content;
	if (c == 'a')
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	ft_push(t_list **i, t_list **j, char c)
{
	t_list	*t;

	t = *j;
	ft_lstadd_front(i, ft_lstnew(t->content));
	t = t->next;
	*j = t;
	if (c == 'a')
		ft_putstr("pa\n");
	else if (c == 'b')
		ft_putstr("pb\n");
}

void	ft_rotate(t_list **a, char c)
{
	t_list	*t;

	t = *a;
	ft_lstadd_back(a, ft_lstnew(t->content));
	t = t->next;
	*a = t;
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
}

void	ft_rev_rotate(t_list **a, char c)
{
	t_list	*t;
	t_list	*f;

	t = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(t->content));
	t = *a;
	while (t->next->next != NULL)
		t = t->next;
	f = t->next;
	t->next = NULL;
	free(f);
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
}
