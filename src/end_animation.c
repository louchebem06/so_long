/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:45:03 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:41:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	define_alpha(t_windows *windows)
{
	t_position	axe;

	axe.x = 0;
	axe.y = 0;
	while (axe.y < windows->size.y)
	{
		axe.x = 0;
		while (axe.x < windows->size.x)
		{
			ft_mlx_pixel_put(&windows->end_animation, axe.x, axe.y,
				create_trgb(255, 0, 0, 0));
			axe.x++;
		}
		axe.y++;
	}
}

void	define_cube_color(t_windows *windows)
{
	t_position	axe;

	axe.x = windows->size.x / 2;
	axe.y = windows->size.y / 2 - 15;
	while (axe.y < windows->size.y / 2)
	{
		axe.x = windows->size.x / 2;
		while (axe.x < windows->size.x / 2 + 15)
		{
			ft_mlx_pixel_put(&windows->end_animation, axe.x, axe.y,
				create_trgb(0, 28, 166, 203));
			axe.x++;
		}
		axe.y++;
	}
}

void	end_animation(t_windows *windows)
{
	windows->end_animation.img = mlx_new_image(windows->mlx, windows->size.x,
			windows->size.y);
	windows->end_animation.addr = mlx_get_data_addr(windows->end_animation.img,
			&windows->end_animation.bits_per_pixel,
			&windows->end_animation.line_length,
			&windows->end_animation.endian);
	define_alpha(windows);
	define_cube_color(windows);
}
