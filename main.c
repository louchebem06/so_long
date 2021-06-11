/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:02:37 by bledda            #+#    #+#             */
/*   Updated: 2021/06/11 22:20:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc test.c -L ./minilibx -lmlx
//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

#include "so_long.h"

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
		if (windows->player.last == 1)
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
		if (windows->player.last == 1)
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
		if (windows->player.last == 1)
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
		if (windows->player.last == 1)
		{
			position.x = (int)windows->player.last_position.x / 30 * 30;
			position.y = (int)windows->player.last_position.y / 30 * 30;

			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y);
			if (windows->maps[(int)windows->player.position.y/30+1][(int)windows->player.position.x/30] != '1')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, position.x, position.y + 30);

			windows->player.last = 0;
		}
	}

	int i = 0;
	while (windows->maps[i])
	{
		int j = 0;
		while (windows->maps[i][j])
		{
			if (windows->maps[i][j] == 'C')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, j * 30, i * 30);
			else if (windows->maps[i][j] == 'E')
				mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, j * 30, i * 30);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->pixel_correction.img, 0, 0);
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

int key_press(int keycode, t_windows *windows)
{
	static int vitesse = 0;
	vitesse++;
	int setting_vitesse = 5;
	if ((keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0) && windows->key == 1)//wsda
	{
		refresh_maps(windows);
		if (keycode == 13)//w
		{
			ft_putstr_fd("UP\n", 1);
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
			ft_putstr_fd("DOWN\n", 1);
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
			ft_putstr_fd("LEFT\n", 1);
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
			ft_putstr_fd("RIGHT\n", 1);
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

		if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == 'C' && (windows->player.direction == LEFT || windows->player.direction == UP))
		{
			if ((windows->player.direction == LEFT && (int)windows->player.position.x % 30 == 0) || (windows->player.direction == UP  && (int)windows->player.position.y % 30 == 0))
			{
				windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] = '0';
				windows->score++;
			}
		}
		else if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == 'C' && (windows->player.direction == RIGHT || windows->player.direction == DOWN))
		{
			windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] = '0';
			windows->score++;
		}

		if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == 'E' && (windows->player.direction == LEFT || windows->player.direction == UP))
		{
			if ((windows->player.direction == LEFT && (int)windows->player.position.x % 30 == 0) || (windows->player.direction == UP  && (int)windows->player.position.y % 30 == 0))
			{
				end_screen(windows);
			}
		}
		else if (windows->maps[(int)windows->player.position.y/30][(int)windows->player.position.x/30] == 'E' && (windows->player.direction == RIGHT || windows->player.direction == DOWN))
		{
			end_screen(windows);
		}

	}
	else if (keycode == 53)
		close_click(0, windows);
	return (0);
}

int key_release(int keycode, t_windows *windows)
{
	if ((keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0) && windows->key == 1)//wsda
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

int 	parsing_maps(t_windows *windows, char *file)
{
	char *line;
	int fd;
	int state = 1;
	int turn = 0;
	int size_first_line = 0;
	int i = 0;
	int pokeball = 0;
	int exit = 0;
	int start_position = 0;

	line = 0;
	fd = open(file, O_RDONLY);
	while (state == 1)
	{
		i = 0;
		state = get_next_line(fd, &line);
		if (state == -1)
		{
			ft_putstr_fd("error\nFile is nots valid\n", 1);
			return (1);
		}
		if (turn == 0)
			size_first_line = ft_strlen(line);
		else if (size_first_line < (int)ft_strlen(line))
		{
			ft_putstr_fd("error\nMaps is invalid line ", 1);
			ft_putnbr_fd(turn+1, 1);
			ft_putstr_fd(" is too small", 1);
			return (1);
		}
		else if (size_first_line < (int)ft_strlen(line))
		{
			ft_putstr_fd("error\nMaps is invalid line ", 1);
			ft_putnbr_fd(turn+1, 1);
			ft_putstr_fd(" is too long\n", 1);
			return (1);
		}
		if (state == 0 || turn == 0)
		{
			while (line[i])
			{
				if (line[i] != '1')
				{
					ft_putstr_fd("error\nWall is not found line ", 1);
					ft_putnbr_fd(turn + 1, 1);
					ft_putchar_fd('\n', 1);
					return (1);
				}
				i++;
			}
		}
		else
		{
			if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			{
				ft_putstr_fd("error\nWall is not found line ", 1);
				ft_putnbr_fd(turn + 1, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
		}
		i = 0;
		while (line[i])
		{
			if (line[i] == 'C')
				pokeball++;
			else if (line[i] == 'E')
				exit++;
			if (line[i] == 'P')
				start_position++;
			i++;
		}
		turn++;
		windows->size.y = turn * 30;
	}
	if (pokeball < 1 || exit < 1 || start_position < 1)
	{
		ft_putstr_fd("error\nYour maps don't content :\n", 1);
		if (pokeball < 1)
			ft_putstr_fd("	- collectable\n", 1);
		if (exit < 1)
			ft_putstr_fd("	- exit\n", 1);
		if (start_position < 1)
			ft_putstr_fd("	- start position\n", 1);
		return (1);
	}
	close(fd);
	state = 1;
	windows->size.x = size_first_line * 30;
	fd = open(file, O_RDONLY);
	i = 0;
	windows->maps = ft_calloc(sizeof(char *), windows->size.x + 1);
	while (state == 1)
	{
		state = get_next_line(fd, &line);
		windows->maps[i] = ft_strdup(line);
		i++;
	}
	if (i < 2)
	{
		ft_putstr_fd("error\nYour maps is not rectangle\n", 1);
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_windows windows;

	if (ac != 2)
	{
		ft_putstr_fd("error\nMaps is not found\n", 1);
		return (0);
	}
	else if (ac == 2)
	{
		if (parsing_maps(&windows, av[1]) == 1)
			return (0);
	}

	windows.score = 0;
	windows.key = 1;

	windows.mlx = mlx_init();
	windows.mlx_win = mlx_new_window(windows.mlx, windows.size.x, windows.size.y, "so_long!");
	
	ft_correction_pixel(&windows);

	end_animation(&windows);
	
	ft_define_player(&windows);
	ft_define_item(&windows);

	maps(&windows);

	mlx_put_image_to_window(windows.mlx, windows.mlx_win, windows.player.right_s.state, windows.player.position.x, windows.player.position.y);
	windows.player.direction = RIGHT;

	mlx_hook(windows.mlx_win, 2, 1L<<0, key_press, &windows);
	mlx_hook(windows.mlx_win, 3, 1L<<1, key_release, &windows);
	mlx_hook(windows.mlx_win, 17, 0, close_click, &windows);

	mlx_loop(windows.mlx);
	return (0);
}
