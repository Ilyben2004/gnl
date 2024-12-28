/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:42:13 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:16 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*helper_func(char **reminder, t_read_values *rdvals, int f)
{
	char	*buff;

	if (BUFFER_SIZE <= 0 || f < 0)
		return (NULL);
	buff = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	if (!buff)
		return (NULL);
	if (*reminder)
	{
		if (read(f, buff, 0) == -1)
			return (NULL);
		rdvals->read_count = ft_strcpy(buff, (*reminder));
		free(*reminder);
		*reminder = NULL;
	}
	else
	{
		rdvals->read_return (= read(f, buff, BUFFER_SIZE));
		if (rdvals->read_return <= 0)
			return (free(buff), NULL);
		rdvals->read_count = rdvals->read_return ;
	}
	return (buff);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while ((i < nmemb * size))
		*((char *)array + i++) = 0;
	return (array);
}

char	*get_next_line(int fd)
{
	static char		*reminder;
	char			*buffer;
	int				i;
	t_read_values	rdvals;

	rdvals.read_count = 0;
	i = 2;
	buffer = helper_func(&reminder, &rdvals, fd);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && rdvals.read_count > 0)
	{
		if (!make_it_bigger(&buffer, i++))
			return (free(buffer), NULL);
		rdvals.read_return (= read(fd, buffer + rdvals.read_count,
				BUFFER_SIZE));
		if (rdvals.read_return == 0)
			break ;
		else if (rdvals.read_return == -1)
			return (free(buffer), NULL);
		rdvals.read_count += rdvals.read_return ;
	}
	if (!*buffer)
		return (free(buffer), NULL);
	return (extract_new_line(buffer, &reminder));
}
