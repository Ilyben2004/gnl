/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:37 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/30 09:42:50 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffercreate(int fd, char *reminder)
{
	char	*readbuffer;
	ssize_t	read_ret;
	char	*buffer;

	readbuffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!readbuffer)
		return (NULL);
	while (1)
	{
		read_ret = read(fd, readbuffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(readbuffer), NULL);
		readbuffer[read_ret] = '\0';
		buffer = ft_strjoin(reminder, readbuffer);
		if (!buffer)
			return (free(readbuffer), NULL);
		free(reminder);
		reminder = buffer;
		if (read_ret == 0 || ft_strchr(buffer, '\n'))
			break ;
	}
	free(readbuffer);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (buffer[i] != '\n')
			i++;
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_memmove(line, buffer, i + 1);
		line[i + 1] = '\0';
		return (line);
	}
	line = ft_strdup(buffer);
	return (line);
}

char	*set_reminder(char *buffer)
{
	char	*new_line_adresse;

	new_line_adresse = ft_strchr(buffer, '\n');
	if (new_line_adresse)
	{
		if (*(new_line_adresse + 1))
			return (ft_strdup(new_line_adresse + 1));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = buffercreate(fd, reminder);
	if (!buffer || !*buffer)
		return (free(buffer), NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	reminder = set_reminder(buffer);
	free(buffer);
	return (line);
}
