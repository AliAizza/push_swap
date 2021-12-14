#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	temp->next = new;
	new->next = 0;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;
	
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
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

int	ft_lst_rev_sortcheck(t_list *head)
{
	int	i;
	int	j;

	i = ft_lstsize(head);
	j = i;
	while (j > 1)
	{
		if (head->content > head->next->content)
			i--;
		j--;
		head = head->next;
	}
	if (i == 1)
		return (i);
	return (0);
}
/*int main()
{
	t_list	*a;

	a = ft_lstnew(5);
	a->next = ft_lstnew(3);
	ft_lstadd_back(&a, ft_lstnew(4));
	ft_lstadd_back(&a, ft_lstnew(2));
	ft_lstadd_back(&a, ft_lstnew(1));

	//printf("%d\n", ft_lstsize(a));
	//printf("%d\n", ft_lstlast(a)->content);
	printf("%d\n", ft_lst_rev_sortcheck(a));
}*/
