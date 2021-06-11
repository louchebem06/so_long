/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:21:12 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (j > dstsize)
		return (dstsize + ft_strlen(src));
	while (j + 1 < dstsize && src[i] != 0)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return ((j - i) + ft_strlen(src));
}
