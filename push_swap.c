#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (!ft_error_check(argv) || argc < 2)
		return (0);
	a = ft_make_list(argc, argv);
	if (!ft_lst_sortcheck(a))
	{
		if (ft_lstsize(a) <= 2)
			ft_sort_2(&a);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else if (ft_lstsize(a) <= 5)
			ft_sort_5(&a, &b);
		else
			ft_sort_100(&a, &b);
	}
	while (a)
	{
		printf("*->%d\n", a->content);
		a = a->next;
	}
}
