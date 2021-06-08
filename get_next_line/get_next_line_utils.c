/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:33:14 by bledda            #+#    #+#             */
/*   Updated: 2021/04/09 20:03:44 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void 	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(size * count);
	if (str == 0)
		return (0);
	while (i < size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char 	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (str == 0)
		return (0);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strings;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	strings = ft_calloc(sizeof(char), i);
	i = 0;
	j = 0;
	if (strings == 0)
		return (0);
	while (s1[j] != 0)
		strings[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		strings[i++] = s2[j++];
	return (strings);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (len < ft_strlen(s))
		string = ft_calloc(sizeof(char), len + 1);
	else
		string = ft_calloc(sizeof(char), ft_strlen(s + start) + 1);
	if (string == 0)
		return (0);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			string[i] = s[start];
			i++;
			start++;
		}
	}
	return (string);
}
