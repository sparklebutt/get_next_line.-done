/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:50 by araveala          #+#    #+#             */
/*   Updated: 2024/02/07 16:36:52 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc_b(int count)
{
	char	*storage_ptr;
	int		i;

	i = 0;
	storage_ptr = malloc(sizeof(char) * count);
	if (storage_ptr == NULL)
	{
		return (NULL);
	}
	while (count > 0)
	{
		storage_ptr[i] = '\0';
		count--;
		i++;
	}
	return (storage_ptr);
}

int	ft_strlen_a(char *s)
{
	int	counter;

	counter = 0;
	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

int	find_nl(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			return (i);
		str++;
		i++;
	}
	return (-1);
}

char	*ft_strdup_b(char *s1, int x)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_a(s1);
	new = ft_calloc_b(len + 1);
	if (new == NULL)
	{
		return (NULL);
	}
	while (s1[x] != '\0' && i <= (len))
	{
		new[i] = s1[x];
		i++;
		x++;
	}
	return (new);
}

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*new;
	int		total_len;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen_a(s1) + ft_strlen_a(s2);
	new = ft_calloc_b((total_len) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0' && x < ft_strlen_a(s2))
	{
		new[i] = s2[x];
		i++;
		x++;
	}
	return (new);
}
