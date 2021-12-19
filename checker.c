/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:02:49 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/19 17:18:36 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker1(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(a, 'c');
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(b, 'c');
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push(a, b, 'c');
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(b, a, 'c');
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(a, 'c');
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(b, 'c');
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rev_rotate(a, 'c');
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rev_rotate(b, 'c');
	else
		return (0);
	return (1);
}

int	ft_checker2(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "ss\n") == 0)
	{
		ft_swap(a, 'c');
		ft_swap(b, 'c');
		return (1);
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_rotate(a, 'c');
		ft_rotate(b, 'c');
		return (1);
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rev_rotate(a, 'c');
		ft_rev_rotate(b, 'c');
		return (1);
	}
	return (0);
}

void	ft_sortchecker(t_list *a)
{
	if (ft_lst_sortcheck(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (!ft_error_check(argv) || argc < 2)
		return (0);
	b = NULL;
	a = ft_make_list(argc, argv);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_checker1(&a, &b, line) && !ft_checker2(&a, &b, line))
		{
			free (line);
			ft_putstr("ERROR\n");
			return (0);
		}
		free (line);
		line = get_next_line(0);
	}
	free (line);
	ft_sortchecker(a);
	free(a);
	free(b);
}
