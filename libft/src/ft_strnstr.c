/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:09:11 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:31 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((ft_strncmp(haystack, needle, ft_strlen(haystack)) == 0
			&& ft_strlen(needle) <= ft_strlen(haystack)) || needle[0] == 0)
		return ((char *)haystack);
	else if (haystack[0] == 0)
		return (0);
	while (i < len)
	{
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (j == ft_strlen(needle))
				return ((char *)haystack + i - j);
		}
		i = i - j + 1;
		j = 0;
	}
	return (0);
}
