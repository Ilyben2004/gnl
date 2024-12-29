/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:55 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/29 19:49:59 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	s1size;
	size_t	s2size;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	joinstr = (char *)malloc(s1size + s2size + 1);
	if (!joinstr)
		return (NULL);
	ft_memmove(joinstr, s1, s1size);
	ft_memmove(joinstr + s1size, s2, s2size);
	joinstr[s1size + s2size] = '\0';
	return (joinstr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		higheroverlap;
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	higheroverlap = dst > src;
	while (len > 0)
	{
		if (higheroverlap)
			*((unsigned char *)dst + len - 1) = *((unsigned char *)src + len
					- 1);
		else
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
		len--;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	s2 = (char *)malloc(size + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;

	cc = c;
	i = 0;
	if (cc == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
