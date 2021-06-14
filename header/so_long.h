/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:32:48 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 23:05:21 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/header/libft.h"

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define BUFFER_SIZE 10

typedef struct s_player
{
	void	*state;
	int		height;
	int		width;
}				t_player;

typedef struct s_position
{
	float	x;
	float	y;
}				t_position;

typedef struct s_dancing
{
	t_player	one;
	t_player	two;
	t_player	tree;
	t_player	fore;
}				t_dancing;

typedef struct s_item
{
	t_player	superball;
	t_player	wall;
	t_player	ground;
	t_player	exit;
	t_player	congratulation;
	t_dancing	dancing;
}				t_item;

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
	t_position	position;
	t_position	last_position;
	int			last;
	int			direction;
}				t_state;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_end_animation
{
	int	x;
	int	neg_x;
	int	y;
	int	save_y;
	int	neg_y;
	int	save_neg_y;
}				t_end_animation;

typedef struct s_parsing
{
	char	*line;
	int		fd;
	int		state;
	int		turn;
	int		size_first_line;
	int		i;
	int		pokeball;
	int		exit;
	int		start_position;
}			t_parsing;

typedef struct s_mewtwo
{
	t_player	up;
	t_player	down;
	t_player	left;
	t_player	right;
	t_player	up_attack_1;
	t_player	up_attack_2;
	t_player	up_attack_3;
	t_player	up_attack_4;
	t_player	up_attack_5;
	t_player	down_attack_1;
	t_player	down_attack_2;
	t_player	down_attack_3;
	t_player	down_attack_4;
	t_player	down_attack_5;
	t_player	left_attack_1;
	t_player	left_attack_2;
	t_player	left_attack_3;
	t_player	left_attack_4;
	t_player	left_attack_5;
	t_player	right_attack_1;
	t_player	right_attack_2;
	t_player	right_attack_3;
	t_player	right_attack_4;
	t_player	right_attack_5;
	t_position	position;
	int			isset;
	int			last_state;
}				t_mewtwo;

typedef struct s_windows
{
	void				*mlx;
	void				*mlx_win;
	t_state				player;
	t_data				pixel_correction;
	t_data				end_animation;
	t_item				item;
	t_position			size;
	char				**maps;
	int					score;
	int					key;
	int					speed;
	unsigned long long	move;
	t_mewtwo			mewtwo;
	int					dead;

}				t_windows;

int		get_next_line(int fd, char **line);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_click(int keycode, t_windows *windows);
void	ft_define_item(t_windows *windows);
void	ft_define_player(t_windows *windows);
int		create_trgb(int t, int r, int g, int b);
void	ft_correction_pixel(t_windows *windows);
void	end_screen(t_windows *windows);
void	end_via_animation(t_windows *windows);
void	final_screen_end(t_windows *windows);
void	end_animation(t_windows *windows);
void	maps(t_windows *windows);
void	player_animation(t_windows *windows, float vitesse, int state,
			int direction);
int		key_release(int keycode, t_windows *windows);
void	refresh_maps(t_windows *windows);
int		key_press(int keycode, t_windows *windows);
void	change_stats_pokeball(t_windows *windows);
void	change_stats_exit(t_windows *windows);
void	press_correction_x(t_windows *windows);
void	press_correction_y(t_windows *windows);
int		parsing_maps(t_windows *windows, char *file);
int		valid_file(t_parsing *var);
int		valid_extension(char *file);
int		valid_size(t_parsing *var);
int		valid_wall(t_parsing *var);
int		valid_object(t_parsing *var);
void	starter_animation(t_windows *windows);

#endif
