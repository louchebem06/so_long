/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:50:05 by bledda            #+#    #+#             */
/*   Updated: 2021/06/13 03:22:03 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	press_up(t_windows *windows, int *vitesse, int keycode)
{
	if (keycode != 13)
		return ;
	ft_putstr_fd("UP\n", 1);
	if (windows->player.direction == UP)
	{
		if (*vitesse % 5 == 0)
		{
			if (windows->maps[(int)windows->player.position.y / 30]
				[(int)windows->player.position.x / 30] == '1'
				|| windows->maps
				[(int)(windows->player.position.y - 7.5) / 30]
				[(int)windows->player.position.x / 30] == '1')
				player_animation(windows, 0, 1, UP);
			else
				player_animation(windows, 7.5, 1, UP);
		}
		else
			player_animation(windows, 0, 0, UP);
	}
	else
	{
		player_animation(windows, 0, 1, UP);
		press_correction_x(windows);
	}
}

void	press_down(t_windows *windows, int *vitesse, int keycode)
{
	if (keycode != 1)
		return ;
	ft_putstr_fd("DOWN\n", 1);
	if (windows->player.direction == DOWN)
	{
		if (*vitesse % 5 == 0)
		{
			if (windows->maps[(int)windows->player.position.y / 30 + 1]
				[(int)windows->player.position.x / 30] == '1')
				player_animation(windows, 0, 1, DOWN);
			else
				player_animation(windows, 7.5, 1, DOWN);
		}
		else
			player_animation(windows, 0, 0, DOWN);
	}
	else
	{
		player_animation(windows, 0, 1, DOWN);
		press_correction_x(windows);
	}
}

void	press_left(t_windows *windows, int *vitesse, int keycode)
{
	if (keycode != 0)
		return ;
	ft_putstr_fd("LEFT\n", 1);
	if (windows->player.direction == LEFT)
	{
		if (*vitesse % 5 == 0)
		{
			if (windows->maps[(int)windows->player.position.y / 30]
				[(int)windows->player.position.x / 30] == '1'
				|| windows->maps[(int)windows->player.position.y / 30]
				[(int)(windows->player.position.x - 7.5) / 30] == '1')
				player_animation(windows, 0, 1, LEFT);
			else
				player_animation(windows, 7.5, 1, LEFT);
		}
		else
			player_animation(windows, 0, 0, LEFT);
	}
	else
	{
		player_animation(windows, 0, 1, LEFT);
		press_correction_y(windows);
	}
}

void	press_right(t_windows *windows, int *vitesse, int keycode)
{
	if (keycode != 2)
		return ;
	ft_putstr_fd("RIGHT\n", 1);
	if (windows->player.direction == RIGHT)
	{
		if (*vitesse % 5 == 0)
		{
			if (windows->maps[(int)windows->player.position.y / 30]
				[(int)windows->player.position.x / 30 + 1] == '1')
				player_animation(windows, 0, 1, RIGHT);
			else
				player_animation(windows, 7.5, 1, RIGHT);
		}
		else
			player_animation(windows, 0, 0, RIGHT);
	}
	else
	{
		player_animation(windows, 0, 1, RIGHT);
		press_correction_y(windows);
	}
}

int	key_press(int keycode, t_windows *windows)
{
	static int	vitesse = 0;

	vitesse++;
	if ((keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		&& windows->key == 1)
	{
		refresh_maps(windows);
		press_up(windows, &vitesse, keycode);
		press_down(windows, &vitesse, keycode);
		press_left(windows, &vitesse, keycode);
		press_right(windows, &vitesse, keycode);
		if (vitesse == 5)
			vitesse = 0;
		change_stats_pokeball(windows);
		change_stats_exit(windows);
	}
	else if (keycode == 53)
		close_click(0, windows);
	return (0);
}
