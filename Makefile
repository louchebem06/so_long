so_long:	
		cd libft && make bonus
		cd minilibx && make
		cp minilibx/libmlx.dylib ./
		gcc -Wall -Wextra -Werror src/main.c \
			src/get_next_line.c \
			src/ft_mlx_pixel_put.c \
			src/ft_close_click.c \
			src/ft_define_player.c \
			src/ft_define_item.c \
			src/create_trgb.c \
			src/ft_correction_pixel.c \
			src/end_screen.c \
			src/end_via_animation.c \
			src/final_screen_end.c \
			src/end_animation.c \
			src/maps.c \
			src/player_animation.c \
			src/key_release.c \
			src/refresh_maps.c \
			src/key_press.c \
			src/key_press_utils.c \
			src/parsing_maps.c \
			src/parsing_maps_utils.c \
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