/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_mewtwo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:07:15 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 14:26:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	ft_define_mewtwo_attack_up(t_windows *windows)
{
	windows->mewtwo.up_attack_1.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_up_1.xpm",
			&windows->mewtwo.up_attack_1.height,
			&windows->mewtwo.up_attack_1.width);
	windows->mewtwo.up_attack_2.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_up_2.xpm",
			&windows->mewtwo.up_attack_2.height,
			&windows->mewtwo.up_attack_2.width);
	windows->mewtwo.up_attack_3.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_up_3.xpm",
			&windows->mewtwo.up_attack_3.height,
			&windows->mewtwo.up_attack_3.width);
	windows->mewtwo.up_attack_4.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_up_4.xpm",
			&windows->mewtwo.up_attack_4.height,
			&windows->mewtwo.up_attack_4.width);
	windows->mewtwo.up_attack_5.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_up_5.xpm",
			&windows->mewtwo.up_attack_5.height,
			&windows->mewtwo.up_attack_5.width);
}

void	ft_define_mewtwo_attack_down(t_windows *windows)
{
	windows->mewtwo.down_attack_1.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_down_1.xpm",
			&windows->mewtwo.down_attack_1.height,
			&windows->mewtwo.down_attack_1.width);
	windows->mewtwo.down_attack_2.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_down_2.xpm",
			&windows->mewtwo.down_attack_2.height,
			&windows->mewtwo.down_attack_2.width);
	windows->mewtwo.down_attack_3.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_down_3.xpm",
			&windows->mewtwo.down_attack_3.height,
			&windows->mewtwo.down_attack_3.width);
	windows->mewtwo.down_attack_4.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_down_4.xpm",
			&windows->mewtwo.down_attack_4.height,
			&windows->mewtwo.down_attack_4.width);
	windows->mewtwo.down_attack_5.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_down_5.xpm",
			&windows->mewtwo.down_attack_5.height,
			&windows->mewtwo.down_attack_5.width);
}

void	ft_define_mewtwo_attack_left(t_windows *windows)
{
	windows->mewtwo.left_attack_1.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_left_1.xpm",
			&windows->mewtwo.left_attack_1.height,
			&windows->mewtwo.left_attack_1.width);
	windows->mewtwo.left_attack_2.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_left_2.xpm",
			&windows->mewtwo.left_attack_2.height,
			&windows->mewtwo.left_attack_2.width);
	windows->mewtwo.left_attack_3.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_left_3.xpm",
			&windows->mewtwo.left_attack_3.height,
			&windows->mewtwo.left_attack_3.width);
	windows->mewtwo.left_attack_4.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_left_4.xpm",
			&windows->mewtwo.left_attack_4.height,
			&windows->mewtwo.left_attack_4.width);
	windows->mewtwo.left_attack_5.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_left_5.xpm",
			&windows->mewtwo.left_attack_5.height,
			&windows->mewtwo.left_attack_5.width);
}

void	ft_define_mewtwo_attack_right(t_windows *windows)
{
	windows->mewtwo.right_attack_1.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_right_1.xpm",
			&windows->mewtwo.right_attack_1.height,
			&windows->mewtwo.right_attack_1.width);
	windows->mewtwo.right_attack_2.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_right_2.xpm",
			&windows->mewtwo.right_attack_2.height,
			&windows->mewtwo.right_attack_2.width);
	windows->mewtwo.right_attack_3.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_right_3.xpm",
			&windows->mewtwo.right_attack_3.height,
			&windows->mewtwo.right_attack_3.width);
	windows->mewtwo.right_attack_4.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_right_4.xpm",
			&windows->mewtwo.right_attack_4.height,
			&windows->mewtwo.right_attack_4.width);
	windows->mewtwo.right_attack_5.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/attack_right_5.xpm",
			&windows->mewtwo.right_attack_5.height,
			&windows->mewtwo.right_attack_5.width);
}

void	ft_define_mewtwo(t_windows *windows)
{
	ft_define_mewtwo_attack_up(windows);
	ft_define_mewtwo_attack_down(windows);
	ft_define_mewtwo_attack_left(windows);
	ft_define_mewtwo_attack_right(windows);
	windows->mewtwo.up.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/move_up.xpm",
			&windows->mewtwo.up.height,
			&windows->mewtwo.up.width);
	windows->mewtwo.down.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/move_down.xpm",
			&windows->mewtwo.down.height,
			&windows->mewtwo.down.width);
	windows->mewtwo.left.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/move_left.xpm",
			&windows->mewtwo.left.height,
			&windows->mewtwo.left.width);
	windows->mewtwo.right.state = mlx_xpm_file_to_image(windows->mlx,
			"./asset/mewtwo/move_right.xpm",
			&windows->mewtwo.right.height,
			&windows->mewtwo.right.width);
}
