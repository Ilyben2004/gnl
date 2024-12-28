/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:42:06 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/28 15:24:34 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_read_struct
{
	ssize_t	read_return;
	size_t	read_count;
}	t_read_values;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*extract_new_line(char *buffer, char **reminder);
void	*make_it_bigger(char **buffer, int i);
int		ft_strcpy(char *dst, const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
void	*helper_func(char **reminder, t_read_values *rdvals, int f);
#endif