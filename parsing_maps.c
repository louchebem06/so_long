/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:46:34 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 15:11:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_parsing_var(t_parsing *var, char *file)
{
	var->line = 0;
	var->state = 1;
	var->turn = 0;
	var->size_first_line = 0;
	var->i = 0;
	var->pokeball = 0;
	var->exit = 0;
	var->start_position = 0;
	fd = open(file, O_RDONLY);
}

int 	parsing_maps(t_windows *windows, char *file)
{
	t_parsing	var;

	define_parsing_var(&var, file);
	while (var.state == 1)
	{
		var.i = 0;
		var.state = get_next_line(fd, &line);
		if (var.state == -1)
		{
			ft_putstr_fd("error\nFile is nots valid\n", 1);
			return (1);
		}
		if (var.turn == 0)
			var.size_first_line = ft_strlen(line);
		else if (var.size_first_line < (int)ft_strlen(var.line))
		{
			ft_putstr_fd("error\nMaps is invalid line ", 1);
			ft_putnbr_fd(var.turn+1, 1);
			ft_putstr_fd(" is too small", 1);
			return (1);
		}
		else if (var.size_first_line < (int)ft_strlen(var.line))
		{
			ft_putstr_fd("error\nMaps is invalid line ", 1);
			ft_putnbr_fd(var.turn+1, 1);
			ft_putstr_fd(" is too long\n", 1);
			return (1);
		}
		if (var.state == 0 || var.turn == 0)
		{
			while (var.line[i])
			{
				if (var.line[i] != '1')
				{
					ft_putstr_fd("error\nWall is not found line ", 1);
					ft_putnbr_fd(var.turn + 1, 1);
					ft_putchar_fd('\n', 1);
					return (1);
				}
				i++;
			}
		}
		else
		{
			if (var.line[0] != '1' || var.line[ft_strlen(var.line) - 1] != '1')
			{
				ft_putstr_fd("error\nWall is not found line ", 1);
				ft_putnbr_fd(var.turn + 1, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
		}
		i = 0;
		while (var.line[i])
		{
			if (var.line[i] == 'C')
				var.pokeball++;
			else if (var.line[i] == 'E')
				var.exit++;
			else if (var.line[i] == 'P')
				var.start_position++;
			if (var.line[i] == 'C' || var.line[i] == 'E' || var.line[i] == 'P' || var.line[i] == '0' || var.line[i] == '1')
				i++;
			else
			{
				ft_putstr_fd("error\nLine ", 1);
				ft_putnbr_fd(var.turn + 1, 1);
				ft_putstr_fd(" '", 1);
				ft_putchar_fd(var.line[i], 1);
				ft_putstr_fd("' is forbidden\n", 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
		}
		var.turn++;
		var.windows->size.y = var.turn * 30;
	}
	if (var.pokeball < 1 || var.exit < 1 || var.start_position < 1)
	{
		ft_putstr_fd("error\nYour maps don't content :\n", 1);
		if (var.pokeball < 1)
			ft_putstr_fd("	- collectable\n", 1);
		if (var.exit < 1)
			ft_putstr_fd("	- exit\n", 1);
		if (var.start_position < 1)
			ft_putstr_fd("	- start position\n", 1);
		return (1);
	}
	close(var.fd);
	var.state = 1;
	var.windows->size.x = var.size_first_line * 30;
	var.fd = open(file, O_RDONLY);
	var.i = 0;
	windows->maps = ft_calloc(sizeof(char *), windows->size.x + 1);
	while (state == 1)
	{
		var.state = get_next_line(fd, &var.line);
		windows->maps[i] = ft_strdup(var.line);
		i++;
	}
	if (i < 2)
	{
		ft_putstr_fd("error\nYour maps is not rectangle\n", 1);
		return (1);
	}
	close(var.fd);
	return (0);
}
