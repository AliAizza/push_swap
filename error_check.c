/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:40:39 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/18 17:35:04 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_digit_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == 48)
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			printf("%s\n", "ERROR");
			return (0);
		}
		i++;
	}
	return (1);
}

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

int	ft_limit_check(char **s)
{
	long int	num;
	int			i;

	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			printf("%s\n", "ERROR");
			return (0);
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
	if (!ft_limit_check(s))
		return (0);
	return (1);
}
