/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:08:03 by aaizza            #+#    #+#             */
/*   Updated: 2021/12/19 16:07:26 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_till_line(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*ft_get_remain(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = ft_substr(s, i + 1, ft_strlen(s));
			free(s);
			return (str);
		}
		i++;
	}
	free(s);
	return (0);
}

char	*ft_read_line(int fd, char *s)
{
	char	*str;
	int		i;

	str = malloc (1);
	if (!str)
	{
		free(s);
		return (NULL);
	}
	i = 1;
	while (!ft_checkline(s) && i)
	{
		i = read (fd, str, 1);
		if (i == -1)
		{
			free (str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin(s, str);
	}
	free (str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*rem;

	if (fd < 0)
		return (NULL);
	rem = ft_read_line(fd, rem);
	if (!rem)
		return (NULL);
	new = ft_till_line(rem);
	rem = ft_get_remain(rem);
	return (new);
}
