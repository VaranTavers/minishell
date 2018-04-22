/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/13 12:07:46 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int		ft_print_charwidth(char c, t_format *f)
{
	int	l;

	l = 1;
	if (l < f->f_width && !(f->flag & 4))
		while (l < f->f_width)
		{
			if (f->flag & 2 && f->precision == 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			++l;
		}
	ft_putchar(c);
	if (l < f->f_width && f->flag & 4)
		while (l < f->f_width)
		{
			write(1, " ", 1);
			++l;
		}
	if (l >= f->f_width)
		return (l);
	else
		return (f->f_width);
}

int				ft_putcharf(va_list *lst, t_format *f)
{
	int				ret;
	unsigned char	c;

	if (f->conv[0] == 'l')
		return (ft_putwcharf(lst, f));
	c = (unsigned char)(va_arg(*lst, int));
	ret = ft_print_charwidth(c, f);
	return (ret);
}
