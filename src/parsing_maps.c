/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:46:34 by bledda            #+#    #+#             */
/*   Updated: 2021/06/13 00:58:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
	var->fd = open(file, O_RDONLY);
}

int	isset_object(t_parsing *var)
{
	if (var->pokeball < 1 || var->exit < 1 || var->start_position < 1)
	{
		ft_putstr_fd("error\nYour maps don't content :\n", 1);
		if (var->pokeball < 1)
			ft_putstr_fd("	- collectable\n", 1);
		if (var->exit < 1)
			ft_putstr_fd("	- exit\n", 1);
		if (var->start_position < 1)
			ft_putstr_fd("	- start position\n", 1);
		return (1);
	}
	return (0);
}

void	second_check(t_parsing *var, t_windows *windows, char *file)
{
	var->state = 1;
	windows->size.x = var->size_first_line * 30;
	var->fd = open(file, O_RDONLY);
	var->i = 0;
	windows->maps = ft_calloc(sizeof(char *), windows->size.x + 1);
	while (var->state == 1)
	{
		var->state = get_next_line(var->fd, &var->line);
		windows->maps[var->i] = ft_strdup(var->line);
		free(var->line);
		var->i++;
	}
}

int	valid_rectangle(t_parsing *var)
{
	if (var->i < 2 || var->size_first_line < 2)
	{
		ft_putstr_fd("error\nYour maps is not rectangle\n", 1);
		return (1);
	}
	return (0);
}

int 	parsing_maps(t_windows *windows, char *file)
{
	t_parsing	var;

	define_parsing_var(&var, file);
	while (var.state == 1)
	{
		var.i = 0;
		var.state = get_next_line(var.fd, &var.line);
		if (valid_file(&var)
			|| valid_extension(file)
			|| valid_size(&var)
			|| valid_wall(&var)
			|| valid_object(&var))
			return (1);
		free(var.line);
		var.turn++;
		windows->size.y = var.turn * 30;
	}
	if (isset_object(&var))
		return (1);
	close(var.fd);
	second_check(&var, windows, file);
	valid_rectangle(&var);
	close(var.fd);
	return (0);
}
