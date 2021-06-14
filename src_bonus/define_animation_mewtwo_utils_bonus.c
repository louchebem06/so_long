/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_animation_mewtwo_utils_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:04:13 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 22:07:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	move_mewtwo_attack_up(t_windows *windows, int i)
{
	if (i == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up_attack_1.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 1)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up_attack_2.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 2)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up_attack_3.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 3)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up_attack_4.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 4)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up_attack_5.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
}

void	move_mewtwo_attack_down(t_windows *windows, int i)
{
	if (i == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down_attack_1.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 1)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down_attack_2.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 2)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down_attack_3.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 3)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down_attack_4.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 4)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down_attack_5.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
}

void	move_mewtwo_attack_left(t_windows *windows, int i)
{
	if (i == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left_attack_1.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 1)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left_attack_2.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 2)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left_attack_3.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 3)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left_attack_4.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 4)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left_attack_5.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
}

void	move_mewtwo_attack_right(t_windows *windows, int i)
{
	if (i == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right_attack_1.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 1)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right_attack_2.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 2)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right_attack_3.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 3)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right_attack_4.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
	else if (i == 4)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right_attack_5.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
}

void	put_ground(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->item.ground.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->item.ground.state, windows->player.position.x,
		windows->player.position.y);
}
