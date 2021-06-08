/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:02:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/08 15:25:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc test.c -L ./minilibx -lmlx
//gcc test.c -L ./minilibx_linux/ -lmlx -lm -lbsd -lX11 -lXext
//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

#include "minilibx/mlx.h"
//#include "minilibx_linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_player
{
	void *state;
	int height;
	int width;
}			t_player;

typedef struct s_position
{
	float x;
	float y;
}			t_position;

typedef struct s_item
{
	t_player superball;
	t_player wall;
	t_player ground;
}			t_item;

typedef struct s_state
{
	t_player	up_s;
	t_player	up_l;
	t_player	up_r;
	t_player	down_s;
	t_player	down_l;
	t_player	down_r;
	t_player	left_s;
	t_player	left_l;
	t_player	left_r;
	t_player	right_s;
	t_player	right_l;
	t_player	right_r;
	t_position position;
	int direction;
}			t_state;

typedef struct s_windows
{
	void	*mlx;
	void	*mlx_win;
	t_state player;
	t_item item;
	t_position size;
}			t_windows;

void maps(t_windows *windows)
{
	t_position position;

	position.x = 0;
	position.y = 0;
	while (position.x < windows->size.x)
	{
		position.y = 0;
		while (position.y < windows->size.y)
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			position.y += 30;
		}
		position.x += 30;
	}
	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, 30, 30);
	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, 60, 60);
}

void refresh_maps(t_windows *windows)
{
	t_position position;

	position.x = 0;
	position.y = 0;
	while (position.x < windows->player.position.x)
		position.x += 30;
	while (position.y < windows->player.position.y)
		position.y += 30;
	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
	if (windows->player.direction < 4)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x - 30, position.y);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x + 30, position.y);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y - 30);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x + 30, position.y + 30);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x - 30, position.y + 30);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x - 30, position.y - 30);
	}
}

void ft_define_player(t_windows *windows)
{
	windows->player.up_s.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/up_s.xpm", &windows->player.up_s.height, &windows->player.up_s.width);
	windows->player.up_l.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/up_l.xpm", &windows->player.up_l.height, &windows->player.up_l.width);
	windows->player.up_r.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/up_r.xpm", &windows->player.up_r.height, &windows->player.up_r.width);
	windows->player.down_s.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/down_s.xpm", &windows->player.down_s.height, &windows->player.down_s.width);
	windows->player.down_l.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/down_l.xpm", &windows->player.down_l.height, &windows->player.down_l.width);
	windows->player.down_r.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/down_r.xpm", &windows->player.down_r.height, &windows->player.down_r.width);
	windows->player.left_s.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/left_s.xpm", &windows->player.left_s.height, &windows->player.left_s.width);
	windows->player.left_l.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/left_l.xpm", &windows->player.left_l.height, &windows->player.left_l.width);
	windows->player.left_r.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/left_r.xpm", &windows->player.left_r.height, &windows->player.left_r.width);
	windows->player.right_s.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/right_s.xpm", &windows->player.right_s.height, &windows->player.right_s.width);
	windows->player.right_l.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/right_l.xpm", &windows->player.right_l.height, &windows->player.right_l.width);
	windows->player.right_r.state = mlx_xpm_file_to_image(windows->mlx, "./asset/ronflex/right_r.xpm", &windows->player.right_r.height, &windows->player.right_r.width);
}

void ft_define_item(t_windows *windows)
{
	windows->item.superball.state = mlx_xpm_file_to_image(windows->mlx, "./asset/item/superball.xpm", &windows->item.superball.height, &windows->item.superball.width);
	windows->item.wall.state = mlx_xpm_file_to_image(windows->mlx, "./asset/item/wall.xpm", &windows->item.wall.height, &windows->item.wall.width);
	windows->item.ground.state = mlx_xpm_file_to_image(windows->mlx, "./asset/item/ground.xpm", &windows->item.ground.height, &windows->item.ground.width);
}

void up_animation(t_windows *windows, float vitesse)
{
	static int up = 2;

	windows->player.direction = 0;
	if (up > 4)
		up = 2;
	up++;
	if (up % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_r.state, windows->player.position.x, windows->player.position.y);
	else if (up % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.y -= vitesse;
}

void down_animation(t_windows *windows, float vitesse)
{
	static int down = 2;

	windows->player.direction = 1;
	if (down > 4)
		down = 2;
	down++;
	if (down % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_r.state, windows->player.position.x, windows->player.position.y);
	else if (down % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.y += vitesse;
}

void left_animation(t_windows *windows, float vitesse)
{
	static int left = 2;

	windows->player.direction = 2;
	if (left > 4)
		left = 2;
	left++;
	if (left % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_r.state, windows->player.position.x, windows->player.position.y);
	else if (left % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.x -= vitesse;
}

void right_animation(t_windows *windows, float vitesse)
{
	static int right = 2;

	windows->player.direction = 3;
	if (right > 4)
		right = 2;
	right++;
	if (right % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_r.state, windows->player.position.x, windows->player.position.y);
	else if (right % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.x += vitesse;
}

int key_press(int keycode, t_windows *windows)
{
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100 || keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
	{
		refresh_maps(windows);
		if (keycode == 119 || keycode == 13)
			up_animation(windows, 7.5);
		if (keycode == 115 || keycode == 1)
			down_animation(windows, 7.5);
		if (keycode == 97 || keycode == 0)
			left_animation(windows, 7.5);
		if (keycode == 100 || keycode == 2)
			right_animation(windows, 7.5);
		if (windows->player.position.x <= 0)
			windows->player.position.x = 0;
		if (windows->player.position.y <= 0)
			windows->player.position.y = 0;
		if (windows->player.position.x >= windows->size.x - 30)
			windows->player.position.x = windows->size.x - 30;
		if (windows->player.position.y >= windows->size.y - 30)
			windows->player.position.y = windows->size.y - 30;
		printf("X : %f\nY : %f\n", windows->player.position.x, windows->player.position.y);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(windows->mlx, windows->mlx_win);
		exit(0);
	}
	return (0);
}

/*int close_click(int keycode, t_windows *windows)
{
	(void) windows;
	(void) keycode;
	printf("des famille");
	return (0);
}*/


int	key_hook(int keycode, t_windows *windows)
{
	(void) windows;
	printf("key : %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_windows windows;

	windows.size.x = 30*20;
	windows.size.y = 30*20;

	windows.player.position.x = windows.size.x/2-15;
	windows.player.position.y = windows.size.y/2-15;

	windows.mlx = mlx_init();
	windows.mlx_win = mlx_new_window(windows.mlx, windows.size.x, windows.size.y, "so_long!");
	ft_define_player(&windows);
	ft_define_item(&windows);

	maps(&windows);

	mlx_put_image_to_window(windows.mlx, windows.mlx_win, windows.player.right_s.state, windows.player.position.x, windows.player.position.y);
	windows.player.direction = 3;
	mlx_hook(windows.mlx_win, 2, 1L<<0, key_press, &windows);

	mlx_key_hook(windows.mlx_win, key_hook, &windows);
	//Visiblement ne lance pas ma commande pour kill le programme voir fonction close_click
	//mlx_hook(windows.mlx_win, 17, 1L<<6, close_click, &windows);

	mlx_loop(windows.mlx);
	return (0);
}
