/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:39:41 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

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
