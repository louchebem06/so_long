/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isset_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:24:56 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:50:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_isset_tab(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (ft_isset(c, s[i]) == 1)
			return (1);
		if (ft_isset(c, s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
