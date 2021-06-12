/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:22:20 by bledda            #+#    #+#             */
/*   Updated: 2021/06/12 23:40:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	valid_file(t_parsing *var)
{
	if (var->state == -1)
	{
		ft_putstr_fd("error\nFile is nots valid\n", 1);
		return (1);
	}
	return (0);
}

int	valid_extension(char *file)
{
	if (ft_strnstr(file, ".ber", ft_strlen(file)) != 0 && ft_strlen(file) > 4)
	{
		if (!(file[ft_strlen(file) - 4] == '.'
				&& file[ft_strlen(file) - 3] == 'b'
				&& file[ft_strlen(file) - 2] == 'e'
				&& file[ft_strlen(file) - 1] == 'r'))
		{
			ft_putstr_fd("error\nExtension is not valid\n", 1);
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("error\nExtension is not valid\n", 1);
		return (1);
	}
	return (0);
}

int	valid_size(t_parsing *var)
{
	if (var->turn == 0)
		var->size_first_line = ft_strlen(var->line);
	else if (var->size_first_line < (int)ft_strlen(var->line))
	{
		ft_putstr_fd("error\nMaps is invalid line ", 1);
		ft_putnbr_fd(var->turn + 1, 1);
		ft_putstr_fd(" is too small", 1);
		return (1);
	}
	else if (var->size_first_line < (int)ft_strlen(var->line))
	{
		ft_putstr_fd("error\nMaps is invalid line ", 1);
		ft_putnbr_fd(var->turn + 1, 1);
		ft_putstr_fd(" is too long\n", 1);
		return (1);
	}
	return (0);
}

int	valid_wall(t_parsing *var)
{
	if (var->state == 0 || var->turn == 0)
	{
		while (var->line[var->i])
		{
			if (var->line[var->i] != '1')
			{
				ft_putstr_fd("error\nWall is not found line ", 1);
				ft_putnbr_fd(var->turn + 1, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			var->i++;
		}
	}
	else
	{
		if (var->line[0] != '1' || var->line[ft_strlen(var->line) - 1] != '1')
		{
			ft_putstr_fd("error\nWall is not found line ", 1);
			ft_putnbr_fd(var->turn + 1, 1);
			ft_putchar_fd('\n', 1);
			return (1);
		}
	}
	return (0);
}

int	valid_object(t_parsing *var)
{
	var->i = 0;
	while (var->line[var->i])
	{
		if (var->line[var->i] == 'C')
			var->pokeball++;
		else if (var->line[var->i] == 'E')
			var->exit++;
		else if (var->line[var->i] == 'P')
			var->start_position++;
		if (var->line[var->i] == 'C' || var->line[var->i] == 'E'
			|| var->line[var->i] == 'P' || var->line[var->i] == '0'
			|| var->line[var->i] == '1')
			var->i++;
		else
		{
			ft_putstr_fd("error\nLine ", 1);
			ft_putnbr_fd(var->turn + 1, 1);
			ft_putstr_fd(" '", 1);
			ft_putchar_fd(var->line[var->i], 1);
			ft_putstr_fd("' is forbidden\n", 1);
			ft_putchar_fd('\n', 1);
			return (1);
		}
	}
	return (0);
}
