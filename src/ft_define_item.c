/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:05:02 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:41:05 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_define_item(t_windows *windows)
{
	windows->item.superball.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/superball.xpm", &windows->item.superball.height,
			&windows->item.superball.width);
	windows->item.wall.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/wall.xpm", &windows->item.wall.height,
			&windows->item.wall.width);
	windows->item.ground.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/ground.xpm", &windows->item.ground.height,
			&windows->item.ground.width);
	windows->item.exit.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/exit.xpm", &windows->item.exit.height,
			&windows->item.exit.width);
	windows->item.congratulation.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/congratulation.xpm",
			&windows->item.congratulation.height,
			&windows->item.congratulation.width);
}
