/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:35 by araveala          #+#    #+#             */
/*   Updated: 2024/02/07 11:02:27 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4//10//89000//0 //10/141/1030/1/0
# endif

void	*ft_calloc_b(int count);
int		ft_strlen_a(char *s);
int		find_nl(char *str);
int		check_err(int read_len, char *buffer, char *line);
char	*ft_strdup_b(char *s1, int x);
char	*ft_strjoin_b(char *s1, char *s2);
char	*build_line(char *buffer, char *line);
char	*get_next_line(int fd);
char	*get_the_line(char *line);
char	*get_left_overs(char *str); // , int read_len);

#endif
// a stands for original version, b stands for another version
