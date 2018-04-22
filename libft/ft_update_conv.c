/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:28:14 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 13:39:39 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	update_conv2(int *tb, t_format *f, char c)
{
	if (tb['z'] > 0)
	{
		f->conv[0] = 'z';
		f->conv[1] = c;
	}
	else if (tb['h'] > 1)
	{
		ft_memcpy(f->conv, "hh", 2);
		f->conv[2] = c;
	}
	else if (tb['h'] > 0)
	{
		f->conv[0] = 'h';
		f->conv[1] = c;
	}
	else
		f->conv[0] = c;
}

void	update_conv(int *tb, t_format *f, char c)
{
	if (tb['j'] > 0)
	{
		f->conv[0] = 'j';
		f->conv[1] = c;
	}
	else if (tb['l'] > 1)
	{
		ft_memcpy(f->conv, "ll", 2);
		f->conv[2] = c;
	}
	else if (tb['l'] > 0)
	{
		f->conv[0] = 'l';
		f->conv[1] = c;
	}
	else
		update_conv2(tb, f, c);
}
