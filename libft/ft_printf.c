/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:08:04 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 12:42:03 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		(*g_printfs[64])(va_list *lst, t_format *f) =
{&ft_percent, &ft_dn, &ft_putbinf, &ft_putwcharf, &ft_putnbrf,
	&ft_dn, &ft_dn, &ft_dn, &ft_dn, &ft_putnbrf,
	&ft_dn, &ft_dn, &ft_dn, &ft_dn, &ft_dn,
	&ft_putoctf, &ft_dn, &ft_dn, &ft_dn, &ft_putwstrf,
	&ft_dn, &ft_putunbrf, &ft_dn, &ft_dn, &ft_puthexf,
	&ft_dn, &ft_dn, &ft_dn, &ft_dn, &ft_dn,
	&ft_dn, &ft_dn, &ft_dn, &ft_dn, &ft_putbinf,
	&ft_putcharf, &ft_putnbrf, &ft_dn, &ft_dn, &ft_dn,
	&ft_dn, &ft_putnbrf, &ft_dn, &ft_dn, &ft_dn,
	&ft_dn, &ft_dn, &ft_putoctf, &ft_putptrf, &ft_dn,
	&ft_dn, &ft_putstrf, &ft_dn, &ft_putunbrf, &ft_dn,
	&ft_dn, &ft_puthexf, &ft_dn, &ft_dn, &ft_dn,
	&ft_dn, &ft_dn, &ft_dn};

int		ft_print_width(char *str, t_format *f)
{
	int		l;

	l = ft_strlen(str);
	if (l < f->f_width && !(f->flag & 4))
		while (l < f->f_width)
		{
			if (f->flag & 2 && f->precision == 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			++l;
		}
	ft_putstr(str);
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

int		do_conv(va_list *lst, t_format *f)
{
	int		i;

	i = 0;
	while (i < 2 && (f->conv[i] == 'h' || f->conv[i] == 'l' ||
				f->conv[i] == 'j' || f->conv[i] == 'z'))
		i++;
	if (f->conv[i] == '%')
		return (g_printfs[0](lst, f));
	else if (f->conv[i] >= 'A' && f->conv[i] <= 127)
		return (g_printfs[f->conv[i] - '@'](lst, f));
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		printed;
	va_list	lst;

	va_start(lst, format);
	i = 0;
	printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar((char)format[i]);
		else
		{
			j = do_flags(&lst, (char *)(format + i + 1), &printed);
			if (j >= 0)
				i += j;
			printed--;
		}
		printed++;
		i++;
	}
	va_end(lst);
	return (printed);
}
