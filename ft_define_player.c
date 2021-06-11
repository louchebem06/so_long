/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:05:14 by bledda            #+#    #+#             */
/*   Updated: 2021/06/11 22:18:16 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_windows *windows)
{
	windows->player.up_s.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/up_s.xpm", &windows->player.up_s.height,
			&windows->player.up_s.width);
	windows->player.up_l.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/up_l.xpm", &windows->player.up_l.height,
			&windows->player.up_l.width);
	windows->player.up_r.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/up_r.xpm", &windows->player.up_r.height,
			&windows->player.up_r.width);
}

void	player_down(t_windows *windows)
{
	windows->player.down_s.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/down_s.xpm", &windows->player.down_s.height,
			&windows->player.down_s.width);
	windows->player.down_l.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/down_l.xpm", &windows->player.down_l.height,
			&windows->player.down_l.width);
	windows->player.down_r.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/down_r.xpm", &windows->player.down_r.height,
			&windows->player.down_r.width);
}

void	player_left(t_windows *windows)
{
	windows->player.left_s.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/left_s.xpm", &windows->player.left_s.height,
			&windows->player.left_s.width);
	windows->player.left_l.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/left_l.xpm", &windows->player.left_l.height,
			&windows->player.left_l.width);
	windows->player.left_r.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/left_r.xpm", &windows->player.left_r.height,
			&windows->player.left_r.width);
}

void	player_right(t_windows *windows)
{
	windows->player.right_s.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/right_s.xpm", &windows->player.right_s.height,
			&windows->player.right_s.width);
	windows->player.right_l.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/right_l.xpm", &windows->player.right_l.height,
			&windows->player.right_l.width);
	windows->player.right_r.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/ronflex/right_r.xpm", &windows->player.right_r.height,
			&windows->player.right_r.width);
}

void	ft_define_player(t_windows *windows)
{
	player_up(windows);
	player_down(windows);
	player_left(windows);
	player_right(windows);
}
