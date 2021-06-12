/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:23:08 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:40:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	deploye_ground(t_windows *windows)
{
	t_position	axe;

	axe.x = 0;
	axe.y = 0;
	while (axe.x < windows->size.x)
	{
		axe.y = 0;
		while (axe.y < windows->size.y)
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, axe.x, axe.y);
			axe.y += 30;
		}
		axe.x += 30;
	}
}

void	deploye_item(t_windows *windows)
{
	t_position	axe;

	axe.y = 0;
	while (windows->maps[(int)axe.y])
	{
		axe.x = -1;
		while (windows->maps[(int)axe.y][(int)++axe.x])
		{
			if (windows->maps[(int)axe.y][(int)axe.x] == '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.wall.state, axe.x * 30, axe.y * 30);
			else if (windows->maps[(int)axe.y][(int)axe.x] == 'C')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.superball.state, axe.x * 30, axe.y * 30);
			else if (windows->maps[(int)axe.y][(int)axe.x] == 'E')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.exit.state, axe.x * 30, axe.y * 30);
			else if (windows->maps[(int)axe.y][(int)axe.x] == 'P')
			{
				windows->player.position.x = axe.x * 30;
				windows->player.position.y = axe.y * 30;
			}
		}
		axe.y++;
	}
}

void	maps(t_windows *windows)
{
	deploye_ground(windows);
	deploye_item(windows);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->pixel_correction.img, 0, 0);
}
