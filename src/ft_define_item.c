/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:05:02 by bledda            #+#    #+#             */
/*   Updated: 2021/06/13 02:33:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	define_dancing(t_windows *windows)
{
	windows->item.dancing.one.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/starter_dancing1.xpm",
			&windows->item.dancing.one.height,
			&windows->item.dancing.one.width);
	windows->item.dancing.two.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/starter_dancing2.xpm",
			&windows->item.dancing.two.height,
			&windows->item.dancing.two.width);
	windows->item.dancing.tree.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/starter_dancing3.xpm",
			&windows->item.dancing.tree.height,
			&windows->item.dancing.tree.width);
	windows->item.dancing.fore.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/item/starter_dancing4.xpm",
			&windows->item.dancing.fore.height,
			&windows->item.dancing.fore.width);
}

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
	define_dancing(windows);
}
