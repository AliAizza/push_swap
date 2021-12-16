#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	ft_dup_check(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
			{
				printf("%s\n", "ERROR");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_error_check(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (!ft_digit_check(s[i]))
			return (0);
		i++;
	}
	if (!ft_dup_check(s))
		return (0);
	return (1);
}

t_list	*ft_make_list(int a, char **s)
{
	t_list	*head;
	int	i;

	i = 1;
	head = ft_lstnew(ft_atoi(s[i++]));
	while (i < a)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(s[i])));
		i++;
	}
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
