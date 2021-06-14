/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:02:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 14:09:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	define_main(t_windows *windows)
{
	windows->score = 0;
	windows->key = 1;
	windows->speed = 0;
	windows->move = 0;
	windows->mlx = mlx_init();
	windows->mlx_win = mlx_new_window(windows->mlx, windows->size.x,
			windows->size.y, "so_long");
}

int	end_starter_animation(t_windows *windows)
{
	if (windows->key == 0)
		starter_animation(windows);
	return (0);
}

int	main(int ac, char **av)
{
	t_windows	windows;

	if (ac == 2)
	{
		if (parsing_maps(&windows, av[1]) == 1)
			return (0);
		define_main(&windows);
		ft_correction_pixel(&windows);
		end_animation(&windows);
		ft_define_player(&windows);
		ft_define_item(&windows);
		maps(&windows);
		mlx_put_image_to_window(windows.mlx, windows.mlx_win,
			windows.player.right_s.state, windows.player.position.x,
			windows.player.position.y);
		windows.player.direction = RIGHT;
		mlx_hook(windows.mlx_win, 2, 1L << 0, key_press, &windows);
		mlx_hook(windows.mlx_win, 3, 1L << 1, key_release, &windows);
		mlx_hook(windows.mlx_win, 17, 0, close_click, &windows);
		mlx_loop_hook(windows.mlx, end_starter_animation, &windows);
		mlx_loop(windows.mlx);
	}
	else
		ft_putstr_fd("error\nMaps is not found\n", 1);
	return (0);
}
