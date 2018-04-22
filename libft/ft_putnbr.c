/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:07:43 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 13:05:05 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char char_to_put;

	if (nb / 10 != 0)
	{
		ft_putnbr(nb / 10);
	}
	else
	{
		if (nb < 0)
			write(1, "-", 1);
	}
	if (nb % 10 >= 0)
		char_to_put = (char)(nb % 10) + '0';
	else
		char_to_put = '0' - (char)(nb % 10);
	ft_putchar(char_to_put);
}
