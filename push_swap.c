#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*head;
	t_list	*a;

	a = NULL;
	if (argc <= 1)
		return (1);
	if (!ft_error_check(argv))
		return (0);
	head = ft_make_list(argc, argv);
	ft_sort(&head, &a);
	while (head)
	{
		printf("***%d\n", head->content);
		head = head->next;
	}
}
