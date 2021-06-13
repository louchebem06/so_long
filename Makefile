# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 19:38:21 by bledda            #+#    #+#              #
#    Updated: 2021/06/13 19:39:46 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

HEADER_FILE = header/so_long.h

FOLDER		= src/

SRCS		= main.c \
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
			parsing_maps_utils.c

SRC			= $(addprefix ${FOLDER},${SRCS})

OBJS		= ${SRC:.c=.o}

CC			= gcc
CFLAGS  	= -Wall -Wextra -Werror
RM			= rm -f

$(NAME):	${OBJS}
			cd libft && make
			$(CC) $(CFLAGS) ${OBJS} libft/libft.a -L/usr/local/lib -lmlx -L/usr/include -lmlx -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			${RM} $(OBJS) $(OBJSBONUS)
			cd libft && make clean

fclean:		
			${RM} $(OBJS) $(OBJSBONUS)
			cd libft && make fclean
			${RM} so_long

.PHONY: 	all clean fclean re