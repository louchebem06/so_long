/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_place_mewtwo_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:39:53 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 16:54:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	define_place_mewtwo(t_windows *windows)
{
	int	x;
	int	y;

	y = 0;
	while (windows->maps[y])
	{
		x = 0;
		while (windows->maps[y][x])
		{
			if (windows->maps[y][x] == '0')
			{
				windows->mewtwo.isset = YES;
				windows->mewtwo.position.x = x * 30;
				windows->mewtwo.position.y = y * 30;
			}
			x++;
		}
		y++;
	}
}
