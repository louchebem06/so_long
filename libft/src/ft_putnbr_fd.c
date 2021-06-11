/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:48:51 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:52:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	n2 = n;
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
	}
	n2 = n2 % 10 + '0';
	ft_putchar_fd(n2, fd);
}
