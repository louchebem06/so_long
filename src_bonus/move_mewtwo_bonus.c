/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mewtwo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:50:42 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 16:51:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	move_mewtwo_up(t_windows *windows)
{
	if (windows->mewtwo.position.y <= windows->player.position.y
		&& windows->mewtwo.position.x == windows->player.position.x)
	{
		windows->mewtwo.position.y += 30;
		define_animation_mewtwo(windows, UP);
	}
	else
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	move_mewtwo_down(t_windows *windows)
{
	if (windows->mewtwo.position.y >= windows->player.position.y
		&& windows->mewtwo.position.x == windows->player.position.x)
	{
		windows->mewtwo.position.y -= 30;
		define_animation_mewtwo(windows, DOWN);
	}
	else
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	move_mewtwo_left(t_windows *windows)
{
	if (windows->mewtwo.position.x <= windows->player.position.x
		&& windows->mewtwo.position.y == windows->player.position.y)
	{
		windows->mewtwo.position.x += 30;
		define_animation_mewtwo(windows, LEFT);
	}
	else
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	move_mewtwo_right(t_windows *windows)
{
	if (windows->mewtwo.position.x >= windows->player.position.x
		&& windows->mewtwo.position.y == windows->player.position.y)
	{
		windows->mewtwo.position.x -= 30;
		define_animation_mewtwo(windows, RIGHT);
	}
	else
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}
