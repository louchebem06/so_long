/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_animation_mewtwo_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:57:31 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 22:11:42 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	end_screend_dead(t_windows *windows)
{
	t_position	axe;

	windows->end_animation.img = mlx_new_image(windows->mlx, windows->size.x,
			windows->size.y);
	windows->end_animation.addr = mlx_get_data_addr(windows->end_animation.img,
			&windows->end_animation.bits_per_pixel,
			&windows->end_animation.line_length,
			&windows->end_animation.endian);
	axe.x = 0;
	axe.y = 0;
	while (axe.y < windows->size.y)
	{
		axe.x = 0;
		while (axe.x < windows->size.x)
		{
			ft_mlx_pixel_put(&windows->end_animation, axe.x, axe.y,
				create_trgb(150, 100, 100, 100));
			axe.x++;
		}
		axe.y++;
	}
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, 0, 0);
	mlx_string_put(windows->mlx, windows->mlx_win, (windows->size.x / 2) - 65,
		(windows->size.y / 2), create_trgb(0, 255, 255, 255), "You're dead.");
}

void	refresh_player(t_windows *windows)
{
	if (windows->player.direction == UP)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.up_s.state, windows->player.position.x,
			windows->player.position.y);
	}
	else if (windows->player.direction == DOWN)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.down_s.state, windows->player.position.x,
			windows->player.position.y);
	}
	else if (windows->player.direction == LEFT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.left_s.state, windows->player.position.x,
			windows->player.position.y);
	}
	else if (windows->player.direction == RIGHT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->player.right_s.state, windows->player.position.x,
			windows->player.position.y);
	}
}

void	choose_move_mewtwo(t_windows *windows, int i, int direction)
{
	if (direction == UP)
		move_mewtwo_attack_up(windows, i);
	else if (direction == DOWN)
		move_mewtwo_attack_down(windows, i);
	else if (direction == LEFT)
		move_mewtwo_attack_left(windows, i);
	else if (direction == RIGHT)
		move_mewtwo_attack_right(windows, i);
}

void	define_animation_mewtwo(t_windows *windows, int direction)
{
	static int	i = 0;
	long long	j;

	j = 0;
	put_ground(windows);
	refresh_player(windows);
	choose_move_mewtwo(windows, i, direction);
	mlx_sync(3, windows->mlx_win);
	i++;
	if (i == 5)
	{
		end_screend_dead(windows);
		windows->dead = YES;
		windows->key = NO;
	}
	else
	{
		while (j < 100000000)
			j++;
		define_animation_mewtwo(windows, direction);
	}
}
