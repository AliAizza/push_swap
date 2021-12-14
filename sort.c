#include "push_swap.h"
#include <stdio.h>

void	ft_sort_2(t_list **a)
{
	t_list	*t;

	if (ft_lstsize(*a) < 2)
		return ;
	t = *a;
	if (t->content > t->next->content)
		ft_swap(a, 'a');
}

void	ft_sort_3(t_list **a)
{
	t_list	*t;

	if (ft_lstsize(*a) < 3)
		return ;
	t = *a;
	if ((t->content > t->next->content && t->next->content < t->next->next->content)
	&& (t->content > t->next->content && t->content > t->next->next->content))
		ft_rotate(&t, 'a');
	if (t->content > t->next->content && t->next->content < t->next->next->content)
		ft_sort_2(&t);
	if (t->content > t->next->next->content && t->next->content > t->next->next->content)
	{
		ft_sort_2(&t);
		ft_rev_rotate(&t, 'a');
	}
	if (t->content > t->next->content && t->content > t->next->next->content)
	{
		ft_rotate(&t, 'a');
		ft_sort_2(&t);
	}
	if (t->content < t->next->content && t->next->content > t->next->next->content)
	{
		ft_rev_rotate(&t, 'a');
		ft_sort_2(&t);
	}
	*a = t;
}

int	ft_find_x(t_list *l, int x)
{
	int	i;

	i = 0;
	while (l->content != x)
	{
		i++;
		l = l->next;
	}
	return (i);
}

int	ft_find_min(t_list *l)
{
	int	x;
	t_list	*t;

	t = l;
	x = t->content;
	t = t->next;
	while (t)
	{
		if (x > t->content)
			x = t->content;
		t = t->next;
	}
	return (ft_find_x(l, x));
}

void	ft_sort_5(t_list **a, t_list **b, int x)
{
	t_list	*i;
	t_list	*j;
	int	k;
	int	f;
	int	z;

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
		if (k >= 0)
		{
			if (j->content < i->content)
			{
				ft_push(&i, &j, 'a');
				z++;
			}
			else if (j->content < i->next->content)
			{
				ft_rotate(&i, 'a');
				ft_push(&i, &j, 'a');
				z++;
			}
			else if (j->content < i->next->next->content)
			{
				ft_rotate(&i, 'a');
				ft_rotate(&i, 'a');
				ft_push(&i, &j, 'a');
				z++;
			}
			else if (k == 0)
			{
				if (j->content > i->next->next->content)
				{
					ft_push(&i, &j, 'a');
					ft_rotate(&i, 'a');
					z++;
				}
			}
		}
		if (k == 1 && z == 0)
		{
			if (j->content < i->next->next->next->content)
			{
				ft_rev_rotate(&i, 'a');
				ft_push(&i, &j, 'a');
			}
			else if (j->content > i->next->next->next->content)
			{
				ft_push(&i, &j, 'a');
				ft_rotate(&i, 'a');
			}
		}
		k++;
		while (!ft_lst_sortcheck(i))
			ft_rev_rotate(&i, 'a');
	}
	f = ft_find_x(i, x);
	while (!ft_lst_sortcheck(i))
	{
		if (f > 3)
			ft_rev_rotate(&i, 'a');
		else
			ft_rotate(&i, 'a');
	}
	*a = i;
	*b = j;
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*j;
	t_list	*i;
	t_list	*y;
	int	k;

	i = *a;
	j = *b;
	if (i->next->content == i->min)
		ft_swap(&i, 'a');
	if (ft_lstlast(i)->content == i->min)
		ft_rev_rotate(&i, 'a');
	if (!ft_lst_sortcheck(i))
	{
		ft_push(&j, &i, 'b');
		while (i)
		{
			y = j;
			k = 0;
			while (i->content < y->content && y)
			{
				k++;
				if (!y->next)
					break;
				y = y->next;
			}
			if (k == ft_lstsize(j))
				ft_push(&j, &i, 'b');
			else if (k > ft_lstsize(i) / 2)
			{
				k = ft_lstsize(j) - k;
				while (k > 0)
				{
					ft_rev_rotate(&j, 'b');
					k--;
				}
				ft_push(&j, &i, 'b');
			}
			else if (k <= ft_lstsize(i) / 2)
			{
				while (k > 0)
				{
					ft_rotate(&j, 'b');
					k--;
				}
				ft_push(&j, &i, 'b');
			}
			k = ft_find_min(j);
			while (!ft_lst_rev_sortcheck(j))
			{
				if (k <= ft_lstsize(j) / 2)
					ft_rotate(&j, 'b');
				else
					ft_rev_rotate(&j, 'b');
			}
			if (ft_lst_sortcheck(i))
				break;
		}
	}
	while (j)
	{
		k = 0;
		y = i;
		while (j->content > y->content && y)
		{
			k++;
			if (!y->next)
				break;
			y = y->next;
		}
		if (k == ft_lstsize(i))
			ft_push(&i, &j, 'a');
		else if (k > ft_lstsize(i) / 2)
		{
			k = ft_lstsize(i) - k;
			while (k)
			{
				ft_rev_rotate(&i, 'a');
				k--;
			}
			ft_push(&i, &j, 'a');
		}
		else if (k <= ft_lstsize(i))
		{
			while (k)
			{
				ft_rotate(&i, 'a');
				k--;
			}
			ft_push(&i, &j, 'a');
		}
		k = ft_find_min(i);
		while (!ft_lst_sortcheck(i))
		{
			if (k > ft_lstsize(i) / 2)
				ft_rev_rotate(&i, 'a');
			else
				ft_rotate(&i, 'a');
		}
	}
	*a = i;
	*b = j;
}
