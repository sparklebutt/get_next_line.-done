/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:12:17 by araveala          #+#    #+#             */
/*   Updated: 2024/02/07 17:00:18 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*build_line(char *buffer, char *line)
{
	char	*the_line;
	int		full_count;
	int		i;

	if (!*buffer)
		return (NULL);
	i = -1;
	full_count = ft_strlen_a(buffer);
	if (line == NULL)
	{
		line = ft_calloc_b(full_count + 1);
		if (line == NULL)
			return (NULL);
		while (i++ < full_count)
			line[i] = buffer[i];
		return (line);
	}
	the_line = ft_strjoin_b(line, buffer);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (the_line);
}

char	*get_the_line(char *line)
{
	char	*the_line;
	int		count;
	int		i;

	i = -1;
	count = find_nl(line);
	if (count == -1)
		count = ft_strlen_a(line) - 1;
	the_line = ft_calloc_b(count + 2);
	if (the_line == NULL)
		return (NULL);
	while (i++ < count)
		the_line[i] = line[i];
	return (the_line);
}

char	*get_left_overs(char *str)
{
	int		i;
	char	*temp;

	i = find_nl(str);
	if (i == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (str[i] != '\n')
		i++;
	i = i + 1;
	temp = ft_strdup_b(str, i);
	if (temp == NULL)//
		return (NULL);//
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (temp);
}

char	*read_to_buff(char *buffer, char *s_line, int read_len)
{
	if (read_len == -1)
	{
		if (s_line != NULL)
		{
			free(s_line);
			s_line = NULL;
		}
		return (NULL);
	}
	buffer[read_len] = '\0';
	if (*buffer != '\0' && *buffer)
		s_line = build_line(buffer, s_line);
	if (s_line == NULL)
		return (NULL);
	if (read_len == 0 && *buffer == '\0' && *s_line == '\0')
	{
		if (s_line != NULL)
		{
			free(s_line);
			s_line = NULL;
		}
		return (NULL);
	}
	return (s_line);
}

char	*get_next_line(int fd)
{
	static char	*s_line[1024];
	char		*final_line;
	char		buffer[BUFFER_SIZE + 1];
	int			r_len;

	r_len = 0;
	while (r_len > -1 && BUFFER_SIZE > 0 && fd >= 0)
	{
		r_len = read(fd, buffer, BUFFER_SIZE);
		s_line[fd] = read_to_buff(buffer, s_line[fd], r_len);
		if (s_line[fd] == NULL)
			return (NULL);
		else if (find_nl(s_line[fd]) > -1 || (r_len == 0 && s_line[fd] != NULL))
		{
			final_line = get_the_line(s_line[fd]);
			s_line[fd] = get_left_overs(s_line[fd]);
			return (final_line);
		}
	}
	if (s_line[fd] != NULL && fd > 0)
	{
		free(s_line[fd]);
		s_line[fd] = NULL;
	}
	return (NULL);
}
