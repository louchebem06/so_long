/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 23:30:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 00:35:08 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	print_info(t_windows *windows)
{
	mlx_string_put(windows->mlx, windows->mlx_win, 10, 20,
		create_trgb(0, 255, 255, 0), "Move  :");
	mlx_string_put(windows->mlx, windows->mlx_win, 100, 20,
		create_trgb(0, 255, 255, 0), ft_itoa(windows->move));
	mlx_string_put(windows->mlx, windows->mlx_win, 10, windows->size.y - 10,
		create_trgb(0, 255, 255, 0), "Score :");
	mlx_string_put(windows->mlx, windows->mlx_win, 100,
		windows->size.y - 10,
		create_trgb(0, 255, 255, 0), ft_itoa(windows->score));
}

void	print_move(t_windows *windows)
{
	int	i;

	if (windows->key == 1)
	{
		i = 3;
		while (i < windows->size.x / 30 - 1)
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, 30 * i, 0);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.ground.state, 30 * i,
				windows->size.y / 30 * 30 - 30);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.wall.state, 30 * i, 0);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
				windows->item.wall.state, 30 * i,
				windows->size.y / 30 * 30 - 30);
			i++;
		}
		print_info(windows);
		mlx_sync(3, windows->mlx_win);
	}
}
