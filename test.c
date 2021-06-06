/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 06:14:44 by bledda            #+#    #+#             */
/*   Updated: 2021/06/06 07:05:27 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc test.c -L ./minilibx -lmlx

#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	coucou1;
	int  	coucou2;
	void	*img;

	char *img_pixel;
	int ppp;
	int heigh_img;
	int order;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./pika.xpm", &coucou1, &coucou2);
	img_pixel = mlx_get_data_addr (img, &ppp, &heigh_img, &order);
	//mlx_put_image_to_window(mlx, mlx_win, img, 5, 5);
	//mlx_loop(mlx);
	for (int i = 0; img_pixel[i]; i++)
		write(1, &img_pixel[i], 1);
}