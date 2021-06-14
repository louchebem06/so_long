# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 19:38:21 by bledda            #+#    #+#              #
#    Updated: 2021/06/14 19:14:47 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

HEADER_FILE 		= header/so_long.h
HEADER_FILE_BONUS 	= header/so_long_bonus.h

FOLDER				= src/
FOLDER_BONUS		= src_bonus/

SRCS				= key_press.c \
						main.c

SRCS_COMU 			= get_next_line.c \
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
						key_press_utils.c \
						parsing_maps.c \
						parsing_maps_utils.c

SRCS_BONUS			= key_press_bonus.c \
						main_bonus.c \
						print_move_bonus.c \
						ft_define_mewtwo_bonus.c \
						define_place_mewtwo_bonus.c \
						define_animation_mewtwo_bonus.c \
						track_player_bonus.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_COMU			= $(addprefix ${FOLDER},${SRCS_COMU})
SRC_BONUS			= $(addprefix ${FOLDER_BONUS},${SRCS_BONUS})

OBJS				= ${SRC:.c=.o}
OBJS_COMU			= ${SRC_COMU:.c=.o}
OBJS_BONUS			= ${SRC_BONUS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f

ifdef WITH_BONUS
OBJ 				= $(OBJS_COMU) $(OBJS_BONUS)
HEADER 				= $(HEADER_FILE) $(HEADER_FILE_BONUS)
else
OBJ 				= $(OBJS_COMU) $(OBJS)
HEADER 				= $(HEADER_FILE)
endif

$(NAME):	${OBJ}
			cd libft && make
			#$(CC) $(CFLAGS) ${OBJ} libft/libft.a -L/usr/local/lib -lmlx -L/usr/include -lmlx -o $(NAME)
			$(CC) $(CFLAGS) ${OBJ} libft/libft.a -l mlx -framework OpenGL -framework AppKit -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)
			cd libft && make clean

fclean:		
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)
			cd libft && make fclean
			${RM} so_long

bonus: 		
			$(MAKE) WITH_BONUS=1

.PHONY: 	all clean fclean re bonus
