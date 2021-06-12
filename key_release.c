/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:47:41 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 11:53:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->player.up_s.state, windows->player.position.x,
		windows->player.position.y);
}

void	key_down(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->player.down_s.state, windows->player.position.x,
		windows->player.position.y);
}

void	key_left(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->player.left_s.state, windows->player.position.x,
		windows->player.position.y);
}

void	key_right(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->player.right_s.state, windows->player.position.x,
		windows->player.position.y);
}

int	key_release(int keycode, t_windows *windows)
{
	if ((keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		&& windows->key == 1)
	{
		refresh_maps(windows);
		if (keycode == 13)
			key_up(windows);
		if (keycode == 1)
			key_down(windows);
		if (keycode == 0)
			key_left(windows);
		if (keycode == 2)
			key_right(windows);
	}
	return (0);
}
