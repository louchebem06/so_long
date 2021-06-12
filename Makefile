so_long:	
		cd libft && make bonus
		cd minilibx && make
		cp minilibx/libmlx.dylib ./
		gcc -Wall -Wextra -Werror main.c \
			get_next_line.c \
			ft_mlx_pixel_put.c \
			ft_close_click.c \
			ft_define_player.c \
			ft_define_item.c \
			create_trgb.c \
			ft_correction_pixel.c \
			end_screen.c \
			end_via_animation.c \
			final_screen_end.c \
			end_animation.c \
			maps.c \
			player_animation.c \
			key_release.c \
			refresh_maps.c \
			key_press.c \
			key_press_utils.c \
			parsing_maps.c \
			parsing_maps_utils.c \
			libft/libft.a -L minilibx -lmlx -D BUFFER_SIZE=10 -o so_long
re: 
	rm -rf so_long
	make so_long

clean:
		cd libft && make clean
		cd minilibx && make clean

fclean:
		cd libft && make fclean
		rm -rf libmlx.dylib
		cd minilibx && make clean
		rm -rf so_long