/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_mewtwo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:46:13 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 16:48:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	refresh_mewtwo_left(t_windows *windows)
{
	if (windows->mewtwo.last_state == LEFT)
	{
		if (windows->mewtwo.last_state == UP
			|| windows->mewtwo.last_state == DOWN
			|| windows->mewtwo.last_state == LEFT
			|| windows->mewtwo.last_state == RIGHT)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, ((ft_case(1, windows) + 1) * 30),
				((ft_case(0, windows) - 0) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	refresh_mewtwo_right(t_windows *windows)
{
	if (windows->mewtwo.last_state == RIGHT)
	{
		if (windows->mewtwo.last_state == UP
			|| windows->mewtwo.last_state == DOWN
			|| windows->mewtwo.last_state == LEFT
			|| windows->mewtwo.last_state == RIGHT)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, ((ft_case(1, windows) - 1) * 30),
				((ft_case(0, windows) - 0) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	refresh_mewtwo_up(t_windows *windows)
{
	if (windows->mewtwo.last_state == UP)
	{
		if (windows->mewtwo.last_state == UP
			|| windows->mewtwo.last_state == DOWN
			|| windows->mewtwo.last_state == LEFT
			|| windows->mewtwo.last_state == RIGHT)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, ((ft_case(1, windows) - 0) * 30),
				((ft_case(0, windows) + 1) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	refresh_mewtwo_down(t_windows *windows)
{
	if (windows->mewtwo.last_state == DOWN)
	{
		if (windows->mewtwo.last_state == UP
			|| windows->mewtwo.last_state == DOWN
			|| windows->mewtwo.last_state == LEFT
			|| windows->mewtwo.last_state == RIGHT)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, ((ft_case(1, windows) - 0) * 30),
				((ft_case(0, windows) - 1) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	}
}

void	refresh_mewtwo(t_windows *windows)
{
	refresh_mewtwo_up(windows);
	refresh_mewtwo_down(windows);
	refresh_mewtwo_left(windows);
	refresh_mewtwo_right(windows);
}
