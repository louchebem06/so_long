/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:49:56 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_isset_tab(s1[start], (char *)set) == 1)
		start++;
	while (end > start && ft_isset_tab(s1[end - 1], (char *)set) == 1)
		end--;
	string = ft_calloc(sizeof(char), (end - start) + 1);
	if (string == 0)
		return (0);
	while (start < end)
	{
		string[i] = s1[start];
		i++;
		start++;
	}
	return (string);
}
