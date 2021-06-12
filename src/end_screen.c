/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:28:16 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:41:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	end_screen(t_windows *windows)
{
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd(" _____                             _         _       ", 1);
	ft_putstr_fd("_   _\n", 1);
	ft_putstr_fd("/  __ \\                           | |       | |     ", 1);
	ft_putstr_fd("| | (_)\n", 1);
	ft_putstr_fd("| /  \\/ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _", 1);
	ft_putstr_fd("| |_ _  ___  _ __  \n", 1);
	ft_putstr_fd("| |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` ", 1);
	ft_putstr_fd("| __| |/ _ \\| '_ \\ \n", 1);
	ft_putstr_fd("| \\__/\\ (_) | | | | (_| | | | (_| | |_| |_| | | (_| ", 1);
	ft_putstr_fd("| |_| | (_) | | | |\n", 1);
	ft_putstr_fd(" \\____/\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|", 1);
	ft_putstr_fd("\\__,_|\\__|_|\\___/|_| |_|\n", 1);
	ft_putstr_fd("                    __/ |\n", 1);
	ft_putstr_fd("                   |___/ \n", 1);
	end_via_animation(windows);
	ft_putstr_fd("\n\nYour score : ", 1);
	ft_putnbr_fd(windows->score, 1);
	ft_putstr_fd("\n", 1);
}
