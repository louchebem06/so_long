/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:49:36 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:53:26 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size_s;
	unsigned int	i;
	char			*string;

	if (s == 0)
		return (0);
	size_s = ft_strlen((char *)s);
	i = 0;
	string = ft_calloc(sizeof(char), size_s + 1);
	if (string == 0)
		return (0);
	while (((char *)s)[i] != 0)
	{
		string[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	return (string);
}
