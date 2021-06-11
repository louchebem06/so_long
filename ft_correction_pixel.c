/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correction_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:23:13 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 00:20:42 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	correction_x(t_windows *windows, t_position	*axe)
{
	if ((int)windows->size.x / 30 % 2 == 0)
	{
		if (windows->size.x / 30 >= 10)
			ft_mlx_pixel_put(&windows->pixel_correction,
				windows->size.x / 2 + 30, axe->y,
				create_trgb(0, 128, 208, 112));
		else
			ft_mlx_pixel_put(&windows->pixel_correction,
				windows->size.x / 2,
				axe->y, create_trgb(0, 128, 208, 112));
	}
	else
		ft_mlx_pixel_put(&windows->pixel_correction,
			windows->size.x / 2 + 15, axe->y,
			create_trgb(0, 128, 208, 112));
}

void	correction_y(t_windows *windows, t_position	*axe)
{
	if ((int)windows->size.y / 30 % 2 == 0)
	{
		if (windows->size.y / 30 >= 10)
			ft_mlx_pixel_put(&windows->pixel_correction, axe->x,
				windows->size.y / 2 + 30,
				create_trgb(0, 128, 208, 112));
		else
			ft_mlx_pixel_put(&windows->pixel_correction, axe->x,
				windows->size.y / 2, create_trgb(0, 128, 208, 112));
	}
	else
		ft_mlx_pixel_put(&windows->pixel_correction, axe->x,
			windows->size.y / 2 + 15, create_trgb(0, 128, 208, 112));
}

void	ft_correction_pixel(t_windows *windows)
{
	t_position	axe;

	windows->pixel_correction.img = mlx_new_image(windows->mlx,
			windows->size.x, windows->size.y);
	windows->pixel_correction.addr = mlx_get_data_addr(
			windows->pixel_correction.img,
			&windows->pixel_correction.bits_per_pixel,
			&windows->pixel_correction.line_length,
			&windows->pixel_correction.endian);
	axe.y = 0;
	axe.x = 0;
	while (axe.y < windows->size.y)
	{
		axe.x = 0;
		while (axe.x < windows->size.x)
		{
			ft_mlx_pixel_put(&windows->pixel_correction, axe.x, axe.y,
				create_trgb(255, 0, 0, 0));
			correction_x(windows, &axe);
			correction_y(windows, &axe);
			axe.x++;
		}
		axe.y++;
	}
}
