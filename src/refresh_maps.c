/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:54:32 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:40:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	refresh_down(t_windows *windows, t_position *position)
{
	if (windows->player.direction == DOWN)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->item.ground.state, position->x, position->y);
		if (windows->maps[(int)windows->player.position.y / 30 - 1]
			[(int)windows->player.position.x / 30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y - 30);
		if ((int)position->y / 30 != (int)position->y / 30 + 1
			&& windows->maps[(int)windows->player.position.y / 30 + 1]
			[(int)windows->player.position.x / 30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y + 30);
		if (windows->player.last == 1)
		{
			position->x = (int)windows->player.last_position.x / 30 * 30;
			position->y = (int)windows->player.last_position.y / 30 * 30;
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y);
			if (windows->maps[(int)windows->player.position.y / 30]
				[(int)windows->player.position.x / 30 + 1] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.ground.state, position->x + 30, position->y);
		}
	}
}

void	refresh_left(t_windows *windows, t_position *position)
{
	if (windows->player.direction == LEFT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->item.ground.state, position->x, position->y);
		if (windows->maps[(int)windows->player.position.y / 30]
			[(int)windows->player.position.x / 30 + 1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x + 30, position->y);
		if (windows->player.last == 1)
		{
			position->x = (int)windows->player.last_position.x / 30 * 30;
			position->y = (int)windows->player.last_position.y / 30 * 30;
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y);
			if (windows->maps[(int)windows->player.position.y / 30 + 1]
				[(int)windows->player.position.x / 30] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.ground.state, position->x, position->y + 30);
		}
	}
}

void	refresh_right(t_windows *windows, t_position *position)
{
	if (windows->player.direction == RIGHT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->item.ground.state, position->x, position->y);
		if (windows->maps[(int)windows->player.position.y / 30]
			[(int)windows->player.position.x / 30 - 1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x - 30, position->y);
		if ((int)position->x / 30 != (int)position->x / 30 + 1
			&& windows->maps[(int)windows->player.position.y / 30]
			[(int)windows->player.position.x / 30 + 1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x + 30, position->y);
		if (windows->player.last == 1)
		{
			position->x = (int)windows->player.last_position.x / 30 * 30;
			position->y = (int)windows->player.last_position.y / 30 * 30;
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y);
			if (windows->maps[(int)windows->player.position.y / 30 + 1]
				[(int)windows->player.position.x / 30] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.ground.state, position->x, position->y + 30);
		}
	}
}

void	refresh_up(t_windows *windows, t_position *position)
{
	position->x = (int)windows->player.position.x / 30 * 30;
	position->y = (int)windows->player.position.y / 30 * 30;
	if (windows->player.direction == UP)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->item.ground.state, position->x, position->y);
		if (windows->maps[(int)windows->player.position.y / 30 + 1]
			[(int)windows->player.position.x / 30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y + 30);
		if (windows->player.last == 1)
		{
			position->x = (int)windows->player.last_position.x / 30 * 30;
			position->y = (int)windows->player.last_position.y / 30 * 30;
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, position->x, position->y);
			if (windows->maps[(int)windows->player.position.y / 30]
				[(int)windows->player.position.x / 30 + 1] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.ground.state, position->x + 30, position->y);
		}
	}
}

void	refresh_maps(t_windows *windows)
{
	t_position	position;

	refresh_up(windows, &position);
	refresh_down(windows, &position);
	refresh_left(windows, &position);
	refresh_right(windows, &position);
	position.y = -1;
	while (windows->maps[(int)++position.y])
	{
		position.x = -1;
		while (windows->maps[(int)position.y][(int)++position.x])
		{
			if (windows->maps[(int)position.y][(int)position.x] == 'C')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.superball.state, position.x * 30,
					position.y * 30);
			else if (windows->maps[(int)position.y][(int)position.x] == 'E')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win,
					windows->item.exit.state, position.x * 30, position.y * 30);
		}
	}
	if (windows->player.last == 1 && windows->player.direction <= 3)
		windows->player.last = 0;
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->pixel_correction.img, 0, 0);
}
