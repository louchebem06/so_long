/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:02:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/10 19:19:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc test.c -L ./minilibx -lmlx
//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

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
	t_player exit;
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
	t_position last_position;
	int last;
	int direction;
}			t_state;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_windows
{
	void	*mlx;
	void	*mlx_win;
	t_state player;
	t_data pixel_correction;
	t_data end_animation;
	t_item item;
	t_position size;
	char **maps;
}			t_windows;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	int i = 0;
	while (windows->maps[i])
	{
		int j = 0;
		while (windows->maps[i][j])
		{
			if (windows->maps[i][j] == '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, j * 30, i * 30);
			else if (windows->maps[i][j] == 'C')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, j * 30, i * 30);
			else if (windows->maps[i][j] == 'E')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, j * 30, i * 30);
			else if (windows->maps[i][j] == 'P')
			{
				windows->player.position.x = j * 30;
				windows->player.position.y = i * 30;
			}
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->pixel_correction.img, 0, 0);
}

void refresh_maps(t_windows *windows)
{
	t_position position;

	position.x = (int)windows->player.position.x / 30 * 30;
	position.y = (int)windows->player.position.y / 30 * 30;

	if (windows->player.direction == UP)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
		if (windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);
		if (windows->player.last)
		{
			position.x = (int)windows->player.last_position.x / 30 * 30;
			position.y = (int)windows->player.last_position.y / 30 * 30;

			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30+1] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x+30, position.y);

			windows->player.last = 0;
		}
	}
	else if (windows->player.direction == DOWN)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
		if (windows->maps[(int)windows->player.position.y/30-1][(int)windows->player.position.x/30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y - 30);
		if ((int)position.y/30 != (int)position.y/30+1 && windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);
		if (windows->player.last)
		{
			position.x = (int)windows->player.last_position.x / 30 * 30;
			position.y = (int)windows->player.last_position.y / 30 * 30;

			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30+1] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x + 30, position.y);

			windows->player.last = 0;
		}
	}
	else if (windows->player.direction == LEFT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
		if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30+1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x+30, position.y);
		if (windows->player.last)
		{
			position.x = (int)windows->player.last_position.x / 30 * 30;
			position.y = (int)windows->player.last_position.y / 30 * 30;

			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			if (windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);

			windows->player.last = 0;
		}
	}
	else if (windows->player.direction == RIGHT)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
		if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30-1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x-30, position.y);
		if ((int)position.x/30 != (int)position.x/30+1 && windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30+1] != '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x+30, position.y);
		if (windows->player.last)
		{
			position.x = (int)windows->player.last_position.x / 30 * 30;
			position.y = (int)windows->player.last_position.y / 30 * 30;

			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			if (windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);

			windows->player.last = 0;
		}
	}

	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->pixel_correction.img, 0, 0);
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
	windows->item.exit.state = mlx_xpm_file_to_image(windows->mlx, "./asset/item/exit.xpm", &windows->item.exit.height, &windows->item.exit.width);
}

void player_animation(t_windows *windows, float vitesse, int state, int direction)
{
	static int move = 0;

	if (state)
		move++;

	windows->player.direction = direction;

	if (direction == LEFT)
		windows->player.position.x -= vitesse;
	else if (direction == RIGHT)
		windows->player.position.x += vitesse;
	else if (direction == DOWN)
		windows->player.position.y += vitesse;
	else if (direction == UP)
		windows->player.position.y -= vitesse;


	if (move <= 1 && direction == RIGHT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_r.state, windows->player.position.x, windows->player.position.y);
	else if (move >= 2 && direction == RIGHT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_l.state, windows->player.position.x, windows->player.position.y);

	
	if (move <= 1 && direction == LEFT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_r.state, windows->player.position.x, windows->player.position.y);
	else if (move >= 2 && direction == LEFT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_l.state, windows->player.position.x, windows->player.position.y);

	
	if (move <= 1 && direction == UP)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_r.state, windows->player.position.x, windows->player.position.y);
	else if (move >= 2 && direction == UP)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_l.state, windows->player.position.x, windows->player.position.y);
	
	if (move <= 1 && direction == DOWN)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_r.state, windows->player.position.x, windows->player.position.y);
	else if (move >= 2 && direction == DOWN)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_l.state, windows->player.position.x, windows->player.position.y);
	
	if (move > 2)
		move = 0;
}

//void end_via_animation(t_windows *windows);

int key_press(int keycode, t_windows *windows)
{
	static int vitesse = 0;
	vitesse++;
	int setting_vitesse = 5;
	/*if (keycode == 12)//q
	{
		end_via_animation(windows);
	}*/
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)//wsda
	{
		refresh_maps(windows);
		if (keycode == 13)//w
		{
			printf("UP\n");
			if(windows->player.direction == UP)
			{
				if (vitesse % setting_vitesse == 0)
				{
					if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == '1'
						|| windows->maps[(int)(windows->player.position.y-7.5)/30][(int)windows->player.position.x/30] == '1')
						player_animation(windows, 0, 1, UP);
					else
						player_animation(windows, 7.5, 1, UP);
				}
				else
					player_animation(windows, 0, 0, UP);
			}
			else
			{
				player_animation(windows, 0, 1, UP);
				if ((int)windows->player.position.x % 30 != 0)
				{
					windows->player.last = 1;
					windows->player.last_position.x = windows->player.position.x;
					windows->player.last_position.y = windows->player.position.y;
					if ((int)(windows->player.position.x + 7.5) % 30 == 0)
						windows->player.position.x += 7.5;
					else if ((int)(windows->player.position.x - 7.5) % 30 == 0)
						windows->player.position.x -= 7.5;
					else if ((int)(windows->player.position.x + 15) % 30 == 0)
						windows->player.position.x += 15;
					else if ((int)(windows->player.position.x - 15) % 30 == 0)
						windows->player.position.x -= 15;
					else if ((int)(windows->player.position.x + 22.5) % 30 == 0)
						windows->player.position.x += 22.5;
					else if ((int)(windows->player.position.x - 22.5) % 30 == 0)
						windows->player.position.x -= 22.5;
					else
						windows->player.last = 0;
				}
			}
		}
		if (keycode == 1)//s
		{
			printf("DOWN\n");
			if(windows->player.direction == DOWN)
			{
				if (vitesse % setting_vitesse == 0)
				{
					if (windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] == '1')
						player_animation(windows, 0, 1, DOWN);
					else
						player_animation(windows, 7.5, 1, DOWN);
				}
				else
					player_animation(windows, 0, 0, DOWN);
			}
			else
			{
				player_animation(windows, 0, 1, DOWN);
				if ((int)windows->player.position.x % 30 != 0)
				{
					windows->player.last = 1;
					windows->player.last_position.x = windows->player.position.x;
					windows->player.last_position.y = windows->player.position.y;
					if ((int)(windows->player.position.x + 7.5) % 30 == 0)
						windows->player.position.x += 7.5;
					else if ((int)(windows->player.position.x - 7.5) % 30 == 0)
						windows->player.position.x -= 7.5;
					else if ((int)(windows->player.position.x + 15) % 30 == 0)
						windows->player.position.x += 15;
					else if ((int)(windows->player.position.x - 15) % 30 == 0)
						windows->player.position.x -= 15;
					else if ((int)(windows->player.position.x + 22.5) % 30 == 0)
						windows->player.position.x += 22.5;
					else if ((int)(windows->player.position.x - 22.5) % 30 == 0)
						windows->player.position.x -= 22.5;
					else
						windows->player.last = 0;
				}
			}
		}
		if (keycode == 0)//a
		{
			printf("LEFT\n");
			if(windows->player.direction == LEFT)
			{
				if (vitesse % setting_vitesse == 0)
				{
					if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == '1'
						|| windows->maps[(int)windows->player.position.y/30][(int)(windows->player.position.x-7.5)/30] == '1')
						player_animation(windows, 0, 1, LEFT);
					else
						player_animation(windows, 7.5, 1, LEFT);
				}
				else
				{
					player_animation(windows, 0, 0, LEFT);
				}
			}
			else
			{
				player_animation(windows, 0, 1, LEFT);
				if ((int)windows->player.position.y % 30 != 0)
				{
					windows->player.last = 1;
					windows->player.last_position.x = windows->player.position.x;
					windows->player.last_position.y = windows->player.position.y;
					if ((int)(windows->player.position.y + 7.5) % 30 == 0)
						windows->player.position.y += 7.5;
					else if ((int)(windows->player.position.y - 7.5) % 30 == 0)
						windows->player.position.y -= 7.5;
					else if ((int)(windows->player.position.y + 15) % 30 == 0)
						windows->player.position.y += 15;
					else if ((int)(windows->player.position.y - 15) % 30 == 0)
						windows->player.position.y -= 15;
					else if ((int)(windows->player.position.y + 22.5) % 30 == 0)
						windows->player.position.y += 22.5;
					else if ((int)(windows->player.position.y - 22.5) % 30 == 0)
						windows->player.position.y -= 22.5;
					else
						windows->player.last = 0;
				}
			}
		}
		if (keycode == 2)//d
		{
			printf("RIGHT\n");
			if(windows->player.direction == RIGHT)
			{
				if (vitesse % setting_vitesse == 0)
				{
					if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30+1] == '1')
						player_animation(windows, 0, 1, RIGHT);
					else
						player_animation(windows, 7.5, 1, RIGHT);
				}
				else
					player_animation(windows, 0, 0, RIGHT);
			}
			else
			{
				player_animation(windows, 0, 1, RIGHT);
				if ((int)windows->player.position.y % 30 != 0)
				{
					windows->player.last = 1;
					windows->player.last_position.x = windows->player.position.x;
					windows->player.last_position.y = windows->player.position.y;
					if ((int)(windows->player.position.y + 7.5) % 30 == 0)
						windows->player.position.y += 7.5;
					else if ((int)(windows->player.position.y - 7.5) % 30 == 0)
						windows->player.position.y -= 7.5;
					else if ((int)(windows->player.position.y + 15) % 30 == 0)
						windows->player.position.y += 15;
					else if ((int)(windows->player.position.y - 15) % 30 == 0)
						windows->player.position.y -= 15;
					else if ((int)(windows->player.position.y + 22.5) % 30 == 0)
						windows->player.position.y += 22.5;
					else if ((int)(windows->player.position.y - 22.5) % 30 == 0)
						windows->player.position.y -= 22.5;
					else
						windows->player.last = 0;
				}
			}
		}
		if (vitesse == setting_vitesse)
			vitesse = 0;
		printf("X : %f\nY : %f\n", windows->player.position.x, windows->player.position.y);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(windows->mlx, windows->mlx_win);
		exit(0);
	}
	return (0);
}

int key_release(int keycode, t_windows *windows)
{
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)//wsda
	{
		refresh_maps(windows);
		if (keycode == 13)//w
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_s.state, windows->player.position.x, windows->player.position.y);
		}
		if (keycode == 1)//s
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_s.state, windows->player.position.x, windows->player.position.y);
		}
		if (keycode == 0)//a
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_s.state, windows->player.position.x, windows->player.position.y);
		}
		if (keycode == 2)//d
		{
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_s.state, windows->player.position.x, windows->player.position.y);
		}
	}
	return (0);
}

void 	parsing_maps(t_windows *windows)
{
	(void) windows;
	char *line;
	char path[] = "./maps/simple.ber";
	char path2[] = "./maps/simple2.ber";
	char invalid_maps[] = "./maps/invalid_maps.ber";
	char invalid_path[] = "./maps/invalid.ber";
	(void) path2;
	(void) path;
	(void) invalid_maps;
	(void) invalid_path;
	char *test = strdup(path2);
	int fd;
	line = 0;
	fd = open(test, O_RDONLY);
	int state = 1;
	int turn = 0;
	int size_first_line = 0;
	int i = 0;
	while (state == 1)
	{
		i = 0;
		state = get_next_line(fd, &line);
		if (turn == 0)
			size_first_line = ft_strlen(line);
		else if (size_first_line < (int)ft_strlen(line))
		{
			printf("error\nMaps is invalid line %d is too small\n", turn+1);
		}
		else if (size_first_line < (int)ft_strlen(line))
		{
			printf("error\nMaps is invalid line %d is too long\n", turn+1);
		}
		if (state == 0 || turn == 0)
		{
			while (line[i])
			{
				if (line[i] != '1')
					printf("error\nWall is not found line : %d\n", turn + 1);
				i++;
			}
		}
		else
		{
			if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
				printf("error\nWall is not found line : %d\n", turn + 1);
		}
		turn++;
		windows->size.y = turn * 30;
	}
	close(fd);
	state = 1;
	windows->size.x = size_first_line * 30;
	fd = open(test, O_RDONLY);
	i = 0;
	windows->maps = ft_calloc(sizeof(char *), windows->size.x + 1);
	while (state == 1)
	{
		state = get_next_line(fd, &line);
		windows->maps[i] = ft_strdup(line);
		i++;
	}
	close(fd);
	i = -1;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void ft_correction_pixel(t_windows *windows)
{
	windows->pixel_correction.img = mlx_new_image(windows->mlx, windows->size.x, windows->size.y);
	windows->pixel_correction.addr = mlx_get_data_addr(windows->pixel_correction.img, &windows->pixel_correction.bits_per_pixel, &windows->pixel_correction.line_length, &windows->pixel_correction.endian);

	for (int y = 0; y < windows->size.y; y++)
	{
		for (int x = 0; x < windows->size.x; x++)
		{
			ft_mlx_pixel_put(&windows->pixel_correction, x, y, create_trgb(255, 0, 0, 0));
			if ((int)windows->size.x/30 % 2 == 0)
			{
				if (windows->size.x/30 >= 10)
					ft_mlx_pixel_put(&windows->pixel_correction, windows->size.x/2+30, y, create_trgb(0, 128, 208, 112));
				else
					ft_mlx_pixel_put(&windows->pixel_correction, windows->size.x/2, y, create_trgb(0, 128, 208, 112));
			}
			else
				ft_mlx_pixel_put(&windows->pixel_correction, windows->size.x/2+15, y, create_trgb(0, 128, 208, 112));
			if ((int)windows->size.y/30 % 2 == 0)
			{
				if(windows->size.y/30 >= 10)
					ft_mlx_pixel_put(&windows->pixel_correction, x, windows->size.y/2+30, create_trgb(0, 128, 208, 112));
				else
					ft_mlx_pixel_put(&windows->pixel_correction, x, windows->size.y/2, create_trgb(0, 128, 208, 112));	
			}
			else
				ft_mlx_pixel_put(&windows->pixel_correction, x, windows->size.y/2+15, create_trgb(0, 128, 208, 112));
		}
	}
}
/*
void	end_animation(t_windows *windows)
{
	static int state = 0;
	static int move = 0;
	if (state == 0)
	{
		windows->end_animation.img = mlx_new_image(windows->mlx, windows->size.x, windows->size.y);
		windows->end_animation.addr = mlx_get_data_addr(windows->end_animation.img, &windows->end_animation.bits_per_pixel, &windows->end_animation.line_length, &windows->end_animation.endian);
		for (int y = 0; y < windows->size.y; y++)
			for (int x = 0; x < windows->size.x; x++)
				ft_mlx_pixel_put(&windows->end_animation, x, y, create_trgb(255, 0, 0, 0));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->end_animation.img, 0, 0);
		state++;
	}

	if (state == 1)
	{
		for (int y = windows->size.y/2-7; y < windows->size.y/2+8; y++)
			for (int x = windows->size.x/2+7; x < windows->size.x/2+22; x++)
				ft_mlx_pixel_put(&windows->end_animation, x, y, create_trgb(0, 150, 150, 150));
		state++;
	}
}

void end_via_animation(t_windows *windows)
{
	static int i = 0;
	char str[] = "coucou";

	if (i == 0)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->end_animation.img, 0, 0);
		while (i < 10000)
		{
			printf("%d\n", i);
			i++;
		}
		end_via_animation(windows);
	}
	else
	{
		ft_mlx_pixel_put(&windows->end_animation, 15, 15, create_trgb(0, 150, 150, 150));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->end_animation.img, 15, 15);
	}
}
*/

int close_click(int keycode, t_windows *windows)
{
	(void) windows;
	(void) keycode;
	printf("des famille");
	return (0);
}

int	main(void)
{
	t_windows windows;

	parsing_maps(&windows);

	windows.mlx = mlx_init();
	windows.mlx_win = mlx_new_window(windows.mlx, windows.size.x, windows.size.y, "so_long!");
	
	ft_correction_pixel(&windows);

	//end_animation(&windows);
	
	ft_define_player(&windows);
	ft_define_item(&windows);

	maps(&windows);

	mlx_put_image_to_window(windows.mlx, windows.mlx_win, windows.player.right_s.state, windows.player.position.x, windows.player.position.y);
	windows.player.direction = RIGHT;

	mlx_hook(windows.mlx_win, 2, 1L<<0, key_press, &windows);
	mlx_hook(windows.mlx_win, 3, 1L<<1, key_release, &windows);
	mlx_hook(windows.mlx_win, 4, 0L, close_click, &windows);

	mlx_loop(windows.mlx);
	return (0);
}
