#include <stdio.h>
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
		printf ("%s\n", "sa");
	else if (c == 'b')
		printf ("%s\n", "sb");
}

void	ft_push(t_list **i, t_list **j, char c)
{
	t_list	*t;

	t = *j;
	ft_lstadd_front(i, ft_lstnew(t->content));
	t = t->next;
	*j = t;
	if (c == 'a')
		printf("%s\n", "pa");
	else if (c == 'b')
		printf("%s\n", "pb");
}

void	ft_rotate(t_list **a, char c)
{
	t_list	*t;

	t = *a;
	ft_lstadd_back(a, ft_lstnew(t->content));
	t = t->next;
	*a = t;
	if (c == 'a')
		printf("%s\n", "ra");
	else if (c == 'b')
		printf("%s\n", "rb");
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
		printf("%s\n", "rra");
	else if (c == 'b')
		printf("%s\n", "rrb");
}
