/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:07:43 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 13:25:01 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char char_to_put;

	if (nb / 10 != 0)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	else
	{
		if (nb < 0)
			write(fd, "-", 1);
	}
	if (nb % 10 >= 0)
		char_to_put = (char)(nb % 10) + '0';
	else
		char_to_put = '0' - (char)(nb % 10);
	ft_putchar_fd(char_to_put, fd);
}
