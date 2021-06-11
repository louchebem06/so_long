/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:32:48 by bledda            #+#    #+#             */
/*   Updated: 2021/06/11 19:36:13 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/header/libft.h"

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
	t_player congratulation;
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
	int score;
	int key;
}			t_windows;

int	get_next_line(int fd, char **line);

#endif