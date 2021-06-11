/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:32 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:01 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

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
