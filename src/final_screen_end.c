/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_screen_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:28:34 by bledda            #+#    #+#             */
/*   Updated: 2021/06/13 03:44:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	starter_animation(t_windows *windows);

int	test(int keycode, t_windows *windows)
{
	(void) windows;
	if (keycode == 54)
		close_click(0, windows);
	starter_animation(windows);
	return (0);
}

void	starter_animation(t_windows *windows)
{
	static int	i = 0;
	long long	j;

	j = 0;
	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->end_animation.img, 0, 95);
	if (i == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.dancing.one.state, (windows->size.x / 2) - 70, 95);
	else if (i == 1)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.dancing.two.state, (windows->size.x / 2) - 70, 95);
	else if (i == 2)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.dancing.tree.state, (windows->size.x / 2) - 70, 95);
	else if (i == 3)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.dancing.fore.state, (windows->size.x / 2) - 70, 95);
	i++;
	if (i == 4)
		i = 0;
	mlx_sync(3, windows->mlx_win);
	while (j < 100000000)
		j++;
	mlx_key_hook(windows->mlx_win, test, windows);
}

void	view_screen(t_windows *windows)
{
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, 0, 0);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->item.congratulation.state, (windows->size.x / 2) - 140, 0);
	mlx_string_put(windows->mlx, windows->mlx_win, (windows->size.x / 2) + 70,
		72, create_trgb(0, 255, 255, 0), ft_itoa(windows->score));
	mlx_string_put(windows->mlx, windows->mlx_win, (windows->size.x / 2) - 120,
		90, create_trgb(0, 255, 255, 255), "Echap or close for quit");
	starter_animation(windows);
}

void	final_screen_end(t_windows *windows)
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
				create_trgb(0, 28, 166, 203));
			axe.x++;
		}
		axe.y++;
	}
	view_screen(windows);
	windows->key = 0;
}
