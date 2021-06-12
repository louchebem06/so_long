/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:36:14 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 11:45:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_x(t_windows *windows, float vitesse, int direction, int *move)
{
	if (direction == LEFT)
		windows->player.position.x -= vitesse;
	else if (direction == RIGHT)
		windows->player.position.x += vitesse;
	if (*move <= 1 && direction == RIGHT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.right_r.state, windows->player.position.x,
			windows->player.position.y);
	else if (*move >= 2 && direction == RIGHT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.right_l.state, windows->player.position.x,
			windows->player.position.y);
	if (*move <= 1 && direction == LEFT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.left_r.state, windows->player.position.x,
			windows->player.position.y);
	else if (*move >= 2 && direction == LEFT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.left_l.state, windows->player.position.x,
			windows->player.position.y);
}

void	move_y(t_windows *windows, float vitesse, int direction, int *move)
{
	if (direction == DOWN)
		windows->player.position.y += vitesse;
	else if (direction == UP)
		windows->player.position.y -= vitesse;
	if (*move <= 1 && direction == UP)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.up_r.state, windows->player.position.x,
			windows->player.position.y);
	else if (*move >= 2 && direction == UP)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.up_l.state, windows->player.position.x,
			windows->player.position.y);
	if (*move <= 1 && direction == DOWN)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.down_r.state, windows->player.position.x,
			windows->player.position.y);
	else if (*move >= 2 && direction == DOWN)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.down_l.state, windows->player.position.x,
			windows->player.position.y);
}

void	player_animation(t_windows *windows, float vitesse, int state,
	int direction)
{
	static int	move = 0;

	if (state)
		move++;
	windows->player.direction = direction;
	move_x(windows, vitesse, direction, &move);
	move_y(windows, vitesse, direction, &move);
	if (move > 2)
		move = 0;
}
