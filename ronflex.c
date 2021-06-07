//gcc test.c -L ./minilibx -lmlx
//gcc test.c -L ./minilibx_linux/ -lmlx -lm -lbsd -lX11 -lXext
//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

#include "minilibx/mlx.h"
//#include "minilibx_linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_player
{
	void *state;
	int height;
	int width;
}			t_player;

typedef struct s_position
{
	int x;
	int y;
}			t_position;

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
}			t_state;

typedef struct s_windows
{
	void	*mlx;
	void	*mlx_win;
	t_state player;
	t_position size;
	t_pixel pixel;
}			t_windows;

void	ft_mlx_pixel_put(t_windows *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixel.addr + (y * data->pixel.line_length + x * (data->pixel.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void maps(t_windows *windows)
{
	int i;
	int j;

	i = 0;
	j = 0;
	windows->pixel.img = mlx_new_image(windows->mlx, windows->size.x, windows->size.y);
	windows->pixel.addr = mlx_get_data_addr(windows->pixel.img, &windows->pixel.bits_per_pixel, &windows->pixel.line_length, &windows->pixel.endian);
	while (i <= windows->size.x)
	{
		j = 0;
		while (j <= windows->size.y)
		{
			ft_mlx_pixel_put(windows, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->pixel.img, 0, 0);
}

void ft_define_player(t_windows *windows)
{
	windows->player.up_s.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/up_s.xpm", &windows->player.up_s.height, &windows->player.up_s.width);
	windows->player.up_l.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/up_l.xpm", &windows->player.up_l.height, &windows->player.up_l.width);
	windows->player.up_r.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/up_r.xpm", &windows->player.up_r.height, &windows->player.up_r.width);
	windows->player.down_s.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/down_s.xpm", &windows->player.down_s.height, &windows->player.down_s.width);
	windows->player.down_l.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/down_l.xpm", &windows->player.down_l.height, &windows->player.down_l.width);
	windows->player.down_r.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/down_r.xpm", &windows->player.down_r.height, &windows->player.down_r.width);
	windows->player.left_s.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/left_s.xpm", &windows->player.left_s.height, &windows->player.left_s.width);
	windows->player.left_l.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/left_l.xpm", &windows->player.left_l.height, &windows->player.left_l.width);
	windows->player.left_r.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/left_r.xpm", &windows->player.left_r.height, &windows->player.left_r.width);
	windows->player.right_s.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/right_s.xpm", &windows->player.right_s.height, &windows->player.right_s.width);
	windows->player.right_l.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/right_l.xpm", &windows->player.right_l.height, &windows->player.right_l.width);
	windows->player.right_r.state = mlx_xpm_file_to_image(windows->mlx, "./ronflex/right_r.xpm", &windows->player.right_r.height, &windows->player.right_r.width);
}

int key_release(int keycode, t_windows *windows)
{
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		maps(windows);
		if (keycode == 119)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_s.state, windows->player.position.x, windows->player.position.y);
		if (keycode == 115)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_s.state, windows->player.position.x, windows->player.position.y);
		if (keycode == 97)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_s.state, windows->player.position.x, windows->player.position.y);
		if (keycode == 100)
			mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.right_s.state, windows->player.position.x, windows->player.position.y);
	}
	return (0);
}

void up_animation(t_windows *windows, int vitesse)
{
	static int up = 0;

	if (up >= 1000)
		up = 0;
	up++;
	if (up % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_r.state, windows->player.position.x, windows->player.position.y);
	else if (up % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.up_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.y -= vitesse;
}

void down_animation(t_windows *windows, int vitesse)
{
	static int down = 0;

	if (down >= 1000)
		down = 0;
	down++;
	if (down % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_r.state, windows->player.position.x, windows->player.position.y);
	else if (down % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.down_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.y += vitesse;
}

void left_animation(t_windows *windows, int vitesse)
{
	static int left = 0;

	if (left >= 1000)
		left = 0;
	left++;
	if (left % 3 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_r.state, windows->player.position.x, windows->player.position.y);
	else if (left % 2 == 0)
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_l.state, windows->player.position.x, windows->player.position.y);
	else
		mlx_put_image_to_window(windows->mlx, windows->mlx_win, windows->player.left_s.state, windows->player.position.x, windows->player.position.y);
	windows->player.position.x -= vitesse;
}

void right_animation(t_windows *windows, int vitesse)
{
	static int right = 0;

	if (right >= 1000)
		right = 0;
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
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		maps(windows);
		if (keycode == 119)
			up_animation(windows, 7);
		if (keycode == 115)
			down_animation(windows, 7);
		if (keycode == 97)
			left_animation(windows, 7);
		if (keycode == 100)
			right_animation(windows, 7);
	}
	return (0);
}

int	main(void)
{
	t_windows windows;

	windows.size.x = 500;
	windows.size.y = 500;

	windows.player.position.x = windows.size.x/2-15;
	windows.player.position.y = windows.size.y/2-15;

	windows.mlx = mlx_init();
	windows.mlx_win = mlx_new_window(windows.mlx, windows.size.x, windows.size.y, "Ronflex adventure!");
	ft_define_player(&windows);
	
	maps(&windows);

	mlx_put_image_to_window(windows.mlx, windows.mlx_win, windows.player.right_s.state, windows.player.position.x, windows.player.position.y);
	mlx_hook(windows.mlx_win, 2, 1L<<0, key_press, &windows);
	mlx_hook(windows.mlx_win, 3, 1L<<1, key_release, &windows);

	mlx_loop(windows.mlx);
	return (0);
}