/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_animation_mewtwo_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:57:31 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 15:36:42 by bledda           ###   ########.fr       */
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

void	define_animation_mewtwo(t_windows *windows, int direction)
{
	static int	i = 0;
	long long	j;

	j = 0;
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->item.ground.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	if (direction == UP)
		move_mewtwo_attack_up(windows, i);
	else if (direction == DOWN)
		move_mewtwo_attack_down(windows, i);
	else if (direction == LEFT)
		move_mewtwo_attack_left(windows, i);
	else if (direction == RIGHT)
		move_mewtwo_attack_right(windows, i);
	mlx_sync(3, windows->mlx_win);
	i++;
	if (i == 5)
	{
		ft_putstr_fd("\nFile a finir define_animation_mewtwo_bonus.c\n\n", 1);
		windows->key = NO;
	}
	while (j < 100000000)
		j++;
}
