so_long:	
			cd libft && make bonus
			cd minilibx && make
			cp minilibx/libmlx.dylib ./
			gcc main.c get_next_line.c libft/libft.a -L minilibx -lmlx -D BUFFER_SIZE=10 -o so_long

clean:
		cd libft && make clean
		cd minilibx && make clean

fclean:
		cd libft && make fclean
		rm -rf libmlx.dylib
		cd minilibx && make clean
		rm -rf so_long