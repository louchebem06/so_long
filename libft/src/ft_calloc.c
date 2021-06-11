/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:22 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:49:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void 	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (str == 0)
		return (0);
	ft_memset(str, 0, size * count);
	return (str);
}
