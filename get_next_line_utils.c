/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:42:17 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/28 14:36:18 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_new_line(char *buffer, char **reminder)
{
	char	*new_line_address;
	char	*extracted_line;
	size_t	i;
	size_t	new_line_size;

	i = -1;
	new_line_address = ft_strchr(buffer, '\n');
	if (new_line_address)
	{
		new_line_size = new_line_address - buffer + 1;
		extracted_line = ft_calloc(new_line_size + 1, 1);
		if (!extracted_line)
			return (NULL);
		while (++i < new_line_size)
			extracted_line[i] = buffer[i];
		extracted_line[i] = '\0';
		if (*(new_line_address + 1))
			*reminder = ft_strdup(new_line_address + 1);
		free(buffer);
		return (extracted_line);
	}
	return (buffer);
}

void	*make_it_bigger(char **buffer, int i)
{
	char	*buffer_bigger;
	int		j;

	j = -1;
	buffer_bigger = ft_calloc((size_t)BUFFER_SIZE * i + 1, 1);
	if (!buffer_bigger)
		return (NULL);
	while ((*buffer)[++j])
		buffer_bigger[j] = (*buffer)[j];
	free(*buffer);
	*buffer = buffer_bigger;
	return (*buffer);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
