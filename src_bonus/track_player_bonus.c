/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:42:07 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 19:10:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	ft_case(int xy, t_windows *windows)
{
	int x;
	int y;
	int state;

	state = 0;
	x = windows->mewtwo.position.x;
	y = windows->mewtwo.position.y;
	if (xy == 1)
	{
		while (x >= 30)
		{
			x -= 30;
			state++;
		}
	}
	else
	{
		while (y >= 30)
		{
			y -= 30;
			state++;
		}
	}
	return (state);
}

void	ft_clean_ground_mewtow(t_windows *windows, int direction)
{
	if (ft_case(0, windows) - 1 != 0)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) - 1) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) - 1) * 30));
		if (direction != UP)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) - 1) * 30));
		
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) - 1] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) + 1] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) - 1) * 30));
		
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) - 1] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) + 1] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) - 1) * 30));
		
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) - 1] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) - 1) * 30));
		if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows) + 1] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) - 1) * 30));
	}

	if (ft_case(0, windows) + 2 != windows->size.y / 30)
	{
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) + 1) * 30));
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) + 1) * 30));
		if (direction != DOWN)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) + 1) * 30));

		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows)] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) + 1] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) - 1] == 'E')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) + 1) * 30));

		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows)] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) + 1] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) - 1] == '1')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) + 1) * 30));

		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows)] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, (ft_case(1, windows) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) + 1] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) + 1) * 30), ((ft_case(0, windows) + 1) * 30));
		if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows) - 1] == 'C')
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) - 1) * 30), ((ft_case(0, windows) + 1) * 30));
	}

	if (direction != RIGHT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) + 1) * 30), (ft_case(0, windows) * 30));
	if (direction != LEFT)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, ((ft_case(1, windows) - 1) * 30), (ft_case(0, windows) * 30));

	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.ground.state, (ft_case(1, windows) * 30), (ft_case(0, windows) * 30));
	

	if (windows->maps[ft_case(0, windows)][ft_case(1, windows)] == 'E')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, (ft_case(1, windows) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] == 'E')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) + 1) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] == 'E')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.exit.state, ((ft_case(1, windows) - 1) * 30), (ft_case(0, windows) * 30));

	if (windows->maps[ft_case(0, windows)][ft_case(1, windows)] == '1')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, (ft_case(1, windows) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] == '1')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) + 1) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] == '1')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.wall.state, ((ft_case(1, windows) - 1) * 30), (ft_case(0, windows) * 30));
	
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows)] == 'C')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, (ft_case(1, windows) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] == 'C')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) + 1) * 30), (ft_case(0, windows) * 30));
	if (windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] == 'C')
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->item.superball.state, ((ft_case(1, windows) - 1) * 30), (ft_case(0, windows) * 30));
}

void	track_player(t_windows *windows)
{
	// FOR END ANIMATION
	// define_animation_mewtwo(windows, DOWN);

	if (windows->mewtwo.position.x < windows->player.position.x)
	{
		ft_clean_ground_mewtow(windows, RIGHT);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->mewtwo.right.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	}
	else if (windows->mewtwo.position.x > windows->player.position.x)
	{
		ft_clean_ground_mewtow(windows, LEFT);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->mewtwo.left.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	}
	else if (windows->mewtwo.position.y > windows->player.position.y)
	{
		ft_clean_ground_mewtow(windows, UP);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->mewtwo.up.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	}
	else if (windows->mewtwo.position.y < windows->player.position.y)
	{
		ft_clean_ground_mewtow(windows, DOWN);
		mlx_put_image_to_window(windows->mlx, windows->mlx_win,
		windows->mewtwo.down.state, windows->mewtwo.position.x,
		windows->mewtwo.position.y);
	}

	static int speed = 0;
	if (speed == 30)
	{
		if (windows->mewtwo.position.x < windows->player.position.x)
		{
			ft_clean_ground_mewtow(windows, RIGHT);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.right.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
			if (windows->maps[ft_case(0, windows)][ft_case(1, windows) + 1] != '1')
				windows->mewtwo.position.x += 30;
		}
		else if (windows->mewtwo.position.x > windows->player.position.x)
		{
			ft_clean_ground_mewtow(windows, LEFT);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.left.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
			if (windows->maps[ft_case(0, windows)][ft_case(1, windows) - 1] != '1')
				windows->mewtwo.position.x -= 30;
		}
		else if (windows->mewtwo.position.y > windows->player.position.y)
		{
			ft_clean_ground_mewtow(windows, UP);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.up.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
			if (windows->maps[ft_case(0, windows) - 1][ft_case(1, windows)] != '1')
				windows->mewtwo.position.y -= 30;
		}
		else if (windows->mewtwo.position.y < windows->player.position.y)
		{
			ft_clean_ground_mewtow(windows, DOWN);
			mlx_put_image_to_window(windows->mlx, windows->mlx_win,
			windows->mewtwo.down.state, windows->mewtwo.position.x,
			windows->mewtwo.position.y);
			if (windows->maps[ft_case(0, windows) + 1][ft_case(1, windows)] != '1')
				windows->mewtwo.position.y += 30;
		}
		speed = 0;
	}
	else
		speed++;
}
