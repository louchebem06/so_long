/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:43:00 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:48:07 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static	int	neg_symbole(int i)
{
	if (i == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long int	atoi;
	int					i;
	int					symbole;

	i = 0;
	symbole = 1;
	atoi = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symbole *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - 48);
		i++;
		if (atoi >= 922337203685477587)
			return (neg_symbole(symbole));
	}
	return ((int)(atoi * symbole));
}

/* https://en.wikibooks.org/wiki/C_Programming/limits.h */