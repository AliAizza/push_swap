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
	t_list	*t;

	i = 1;
	t = ft_copy(l);
	while (t->content != x)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	ft_find_min_index(t_list *l)
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

int	ft_find_min(t_list *l)
{
	int	x;

	x = l->content;
	l = l->next;
	while (l)
	{
		if (x > l->content)
			x = l->content;
		l = l->next;
	}
	return (x);
}

int	ft_find_by_index(t_list *l, int index)
{
	if (index == 0)
		return (0);
	while (l && index - 1)
	{
		index--;
		l = l->next;
	}
	return (l->content);
}

int	ft_find_biggest(t_list *l)
{
	int	i;
	t_list	*t;

	t = ft_copy(l);
	i = t->content;
	while (t)
	{
		if (i < t->content)
			i = t->content;
		t = t->next;
	}
	return (ft_find_x(l, i));
}

t_list	*ft_copy(t_list *l)
{
	t_list	*copy;

	copy = ft_lstnew(l->content);
	l = l->next;
	while (l)
	{
		ft_lstadd_back(&copy, ft_lstnew(l->content));
		l = l->next;
	}
	return (copy);
}

t_list	*ft_lst_sortlist(t_list *l)
{
	t_list	*s;
	t_list	*r;
	t_list	*t;
	int	f;

	t = ft_copy(l);
	r = t;
	while (!ft_lst_sortcheck(t))
	{
		s = t->next;
		while (s)
		{
			if (t->content > s->content)
			{
				f = s->content;
				s->content = t->content;
				t->content = f;
			}
			s = s->next;
		}
		t = t->next;
	}
	return (r);
}
void	ft_sort_5(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;
	int	k;
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
	k = ft_find_min(i);
	while (!ft_lst_sortcheck(i))
	{
		if (k > 2)
			ft_rev_rotate(&i, 'a');
		else
			ft_rotate(&i, 'a');
	}
	*a = i;
	*b = j;
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

void	ft_sort_100(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;
	t_list	*t;
	t_list	*h;
	int	k;
	int	z;
	int	p;

	i = *a;
	j = *b;
	t = ft_lst_sortlist(i);
	k = ft_lstsize(t) / 4;
	p = ft_find_by_index(t, k);
	while (ft_there_is_smaller(i, p) && i)
	{
		z = 0;
		h = i;
		while (h->content > p && h)
		{
			z++;
			h = h->next;
		}
		if (z > ft_lstsize(i) / 2)
		{
			z = ft_lstsize(i) - z;
			while (z > 0)
			{
				ft_rev_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
		else
		{
			while (z > 0)
			{
				ft_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
	}
	k = ft_lstsize(t) / 2;
	p = ft_find_by_index(t, k);
	while (ft_there_is_smaller(i, p) && i)
	{
		z = 0;
		h = i;
		while (h->content > p && h)
		{
			z++;
			h = h->next;
		}
		if (z > ft_lstsize(i) / 2)
		{
			z = ft_lstsize(i) - z;
			while (z > 0)
			{
				ft_rev_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
		else
		{
			while (z > 0)
			{
				ft_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
	}
	k = k + (ft_lstsize(t) / 4);
	p = ft_find_by_index(t, k);
	while (ft_there_is_smaller(i, p) && i)
	{
		z = 0;
		h = i;
		while (h->content > p && h)
		{
			z++;
			h = h->next;
		}
		if (z > ft_lstsize(i) / 2)
		{
			z = ft_lstsize(i) - z;
			while (z > 0)
			{
				ft_rev_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
		else
		{
			while (z > 0)
			{
				ft_rotate(&i, 'a');
				z--;
			}
			ft_push(&j, &i, 'b');
		}
	}
	while (i)
	{
		k = ft_find_min_index(i);
		if (k > ft_lstsize(i) / 2)
		{
			k = ft_lstsize(i) - k;
			while (k > 0)
			{
				ft_rev_rotate(&i, 'a');
				k--;
			}
			ft_push(&j, &i, 'b');
		}
		else
		{
			while (k > 0)
			{
				ft_rev_rotate(&i, 'a');
				k--;
			}
			ft_push(&j, &i, 'b');
		}
	}
	while (j)
	{
		k = ft_find_biggest(j) - 1;
		if (k > ft_lstsize(j) / 2)
		{
			k = ft_lstsize(j) - k;
			while (k > 0)
			{
				ft_rev_rotate(&j, 'b');
				k--;
			}
			ft_push(&i, &j, 'a');
		}
		else
		{
			while (k > 0)
			{
				ft_rotate(&j, 'b');
				k--;
			}
			ft_push(&i, &j, 'a');
		}
	}
	*a = i;
	*b = j;
}
