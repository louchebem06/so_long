/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:32:48 by bledda            #+#    #+#             */
/*   Updated: 2021/06/14 15:43:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

# define NO 0
# define YES 1

void	print_move(t_windows *windows);
void	ft_define_mewtwo(t_windows *windows);
void	define_place_mewtwo(t_windows *windows);
void	define_animation_mewtwo(t_windows *windows, int direction);
void	track_player(t_windows *windows);

#endif
