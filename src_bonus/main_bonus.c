/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:02:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 12:41:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	define_main(t_windows *windows)
{
	windows->score = NO;
	windows->key = YES;
	windows->speed = NO;
	windows->move = NO;
	windows->dead = NO;
	windows->mlx = mlx_init();
	windows->mlx_win = mlx_new_window(windows->mlx, windows->size.x,
			windows->size.y, "so_long");
	windows->mewtwo.isset = NO;
	ft_correction_pixel(windows);
	end_animation(windows);
	ft_define_player(windows);
	ft_define_item(windows);
	ft_define_mewtwo(windows);
	define_place_mewtwo(windows);
	windows->mewtwo.last_state = 100;
}

int	end_starter_animation(t_windows *windows)
{
	print_move(windows);
	if (windows->key == 0 && windows->dead == NO)
		starter_animation(windows);
	if (windows->mewtwo.isset == YES && windows->key == YES)
		track_player(windows);
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
