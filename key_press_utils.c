/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:43:29 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 14:43:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_stats_pokeball(t_windows *windows)
{
	if (windows->maps[(int)windows->player.position.y / 30]
		[(int)windows->player.position.x / 30] == 'C'
		&& (windows->player.direction == LEFT
			|| windows->player.direction == UP))
	{
		if ((windows->player.direction == LEFT
				&& (int)windows->player.position.x % 30 == 0)
			|| (windows->player.direction == UP
				&& (int)windows->player.position.y % 30 == 0))
		{
			windows->maps[(int)windows->player.position.y / 30]
			[(int)windows->player.position.x / 30] = '0';
			windows->score++;
		}
	}
	else if (windows->maps[(int)windows->player.position.y / 30]
		[(int)windows->player.position.x / 30] == 'C'
		&& (windows->player.direction == RIGHT
			|| windows->player.direction == DOWN))
	{
		windows->maps[(int)windows->player.position.y / 30]
		[(int)windows->player.position.x / 30] = '0';
		windows->score++;
	}
}

void	change_stats_exit(t_windows *windows)
{
	if (windows->maps[(int)windows->player.position.y / 30]
		[(int)windows->player.position.x / 30] == 'E'
		&& (windows->player.direction == LEFT
			|| windows->player.direction == UP))
	{
		if ((windows->player.direction == LEFT
				&& (int)windows->player.position.x % 30 == 0)
			|| (windows->player.direction == UP
				&& (int)windows->player.position.y % 30 == 0))
			end_screen(windows);
	}
	else if (windows->maps[(int)windows->player.position.y / 30]
		[(int)windows->player.position.x / 30] == 'E'
		&& (windows->player.direction == RIGHT
			|| windows->player.direction == DOWN))
		end_screen(windows);
}

void	press_correction_x(t_windows *windows)
{
	if ((int)windows->player.position.x % 30 != 0)
	{
		windows->player.last = 1;
		windows->player.last_position.x
			= windows->player.position.x;
		windows->player.last_position.y
			= windows->player.position.y;
		if ((int)(windows->player.position.x + 7.5) % 30 == 0)
			windows->player.position.x += 7.5;
		else if ((int)(windows->player.position.x - 7.5) % 30 == 0)
			windows->player.position.x -= 7.5;
		else if ((int)(windows->player.position.x + 15) % 30 == 0)
			windows->player.position.x += 15;
		else if ((int)(windows->player.position.x - 15) % 30 == 0)
			windows->player.position.x -= 15;
		else if ((int)(windows->player.position.x + 22.5) % 30 == 0)
			windows->player.position.x += 22.5;
		else if ((int)(windows->player.position.x - 22.5) % 30 == 0)
			windows->player.position.x -= 22.5;
		else
			windows->player.last = 0;
	}
}

void	press_correction_y(t_windows *windows)
{
	if ((int)windows->player.position.y % 30 != 0)
	{
		windows->player.last = 1;
		windows->player.last_position.x
			= windows->player.position.x;
		windows->player.last_position.y
			= windows->player.position.y;
		if ((int)(windows->player.position.y + 7.5) % 30 == 0)
			windows->player.position.y += 7.5;
		else if ((int)(windows->player.position.y - 7.5) % 30 == 0)
			windows->player.position.y -= 7.5;
		else if ((int)(windows->player.position.y + 15) % 30 == 0)
			windows->player.position.y += 15;
		else if ((int)(windows->player.position.y - 15) % 30 == 0)
			windows->player.position.y -= 15;
		else if ((int)(windows->player.position.y + 22.5) % 30 == 0)
			windows->player.position.y += 22.5;
		else if ((int)(windows->player.position.y - 22.5) % 30 == 0)
			windows->player.position.y -= 22.5;
		else
			windows->player.last = 0;
	}
}
