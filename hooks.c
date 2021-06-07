#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	hooks(int keycode, t_vars *vars)
{
	//mlx_destroy_window(vars->mlx, vars->win);
	printf("Bien fermer !");
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 17, 1, hooks, &vars);
	mlx_loop(vars.mlx);
}