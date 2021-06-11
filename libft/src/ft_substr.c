/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:14:45 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

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
