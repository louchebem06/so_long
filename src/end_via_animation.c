/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_via_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:28:26 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:41:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	define_var(t_end_animation	*var)
{
	var->x = 0;
	var->neg_x = 0;
	var->y = 0;
	var->save_y = 0;
	var->neg_y = 0;
	var->save_neg_y = 0;
}

void	define_new_var(t_end_animation	*var)
{
	var->x = 0;
	var->neg_x = 0;
	var->save_y += 30;
	var->y = var->save_y;
	var->save_neg_y -= 30;
	var->neg_y = var->save_neg_y;
}

void	print_pixel(t_end_animation	*var, t_windows *windows)
{
	if (var->y == var->save_y)
		var->y += 15;
	else
		var->y -= 15;
	if (var->neg_y == var->save_neg_y)
		var->neg_y += 15;
	else
		var->neg_y -= 15;
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, var->x, var->y);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, var->neg_x, var->y);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, var->x, var->neg_y);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->end_animation.img, var->neg_x, var->neg_y);
	mlx_sync(3, windows->mlx_win);
	var->x += 15;
	var->neg_x -= 15;
}

void	end_via_animation(t_windows *windows)
{
	t_end_animation	var;

	define_var(&var);
	while (var.y <= ((int)windows->size.y / 2))
	{
		while (var.x <= (int)windows->size.x / 2
			&& var.neg_x >= ((int)windows->size.x / 2 * -1) + -30)
			print_pixel(&var, windows);
		define_new_var(&var);
	}
	final_screen_end(windows);
}
