/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:42:07 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 16:50:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	ft_case(int xy, t_windows *windows)
{
	int	x;
	int	y;
	int	state;

	state = 0;
	x = windows->mewtwo.position.x;
	y = windows->mewtwo.position.y;
	if (xy == 1)
	{
		while (x >= 30)
		{
			x -= 30;
			state++;
		}
	}
	else
	{
		while (y >= 30)
		{
			y -= 30;
			state++;
		}
	}
	return (state);
}

void	move_x_mewtwo(t_windows *windows)
{
	if (windows->mewtwo.position.x > windows->player.position.x
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] != '1'
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] != 'C'
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] != 'E')
	{
		windows->mewtwo.position.x -= 30;
		move_mewtwo_left(windows);
		windows->mewtwo.last_state = LEFT;
	}
	else if (windows->mewtwo.position.x < windows->player.position.x
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] != '1'
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] != 'C'
		&& windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] != 'E')
	{
		windows->mewtwo.position.x += 30;
		move_mewtwo_right(windows);
		windows->mewtwo.last_state = RIGHT;
	}
}

void	move_yx_mewtwo(t_windows *windows)
{
	if (windows->mewtwo.position.y > windows->player.position.y
		&& windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != '1'
		&& windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != 'C'
		&& windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != 'E')
	{
		windows->mewtwo.position.y -= 30;
		move_mewtwo_up(windows);
		windows->mewtwo.last_state = UP;
	}
	else if (windows->mewtwo.position.y < windows->player.position.y
		&& windows->maps[ft_case(0, windows) + 1][ft_case(1, windows)] != '1'
		&& windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != 'C'
		&& windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != 'E')
	{
		windows->mewtwo.position.y += 30;
		move_mewtwo_down(windows);
		windows->mewtwo.last_state = DOWN;
	}
	else
		move_x_mewtwo(windows);
}

void	track_player(t_windows *windows)
{
	static int	speed = 0;

	if (windows->mewtwo.last_state == 100)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	if (speed == 30)
	{
		move_yx_mewtwo(windows);
		speed = 0;
	}
	else
	{
		refresh_mewtwo(windows);
		speed++;
	}
}
