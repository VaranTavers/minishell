/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/14 11:36:45 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static long long	get_num(va_list *lst, t_format *f)
{
	if (f->conv[0] == 'd' || f->conv[0] == 'i')
		return ((long long)(va_arg(*lst, int)));
	if (f->conv[0] == 'D' || f->conv[1] == 'D' || f->conv[2] == 'D')
		return ((long long)(va_arg(*lst, long)));
	if (f->conv[1] == 'd' || f->conv[1] == 'i')
	{
		if (f->conv[0] == 'l')
			return ((long long)(va_arg(*lst, long)));
		if (f->conv[0] == 'h')
			return ((long long)(short)(va_arg(*lst, int)));
		if (f->conv[0] == 'j')
			return ((long long)(va_arg(*lst, intmax_t)));
		if (f->conv[0] == 'z')
			return ((long long)(va_arg(*lst, long int)));
	}
	if (f->conv[1] == 'l')
		return (va_arg(*lst, long long));
	if (f->conv[1] == 'h')
		return ((long long)(signed char)(va_arg(*lst, int)));
	return (ft_dn(lst, f));
}

static int			get_len(long long n, t_format *f)
{
	int			ret;
	long long	num;

	num = n;
	ret = 0;
	if (n == 0)
	{
		if (!(f->flag & 32) && f->precision == 0)
			ret = 1;
		else
			ret = 0;
	}
	while (n != 0)
	{
		ret++;
		n /= 10;
	}
	if (f->f_width > 0 && f->precision == 0 && f->flag & 2 && !(f->flag & 4))
		f->precision = f->f_width - (num < 0 || f->flag & 8 || f->flag & 16);
	if (f->precision > ret)
		ret = f->precision;
	if (num < 0 || f->flag & 8 || f->flag & 16)
		ret++;
	return (ret);
}

int					positive(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int					ft_putnbrf(va_list *lst, t_format *f)
{
	long long	num;
	int			len;
	char		*str;
	char		start;

	start = '+';
	num = get_num(lst, f);
	len = get_len(num, f);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	str[len--] = '\0';
	if (num < 0)
		start = '-';
	while (len >= 0)
	{
		str[len] = '0' + positive((num % 10));
		num /= 10;
		len--;
	}
	if (start == '-' || f->flag & 8)
		str[0] = start;
	else if (f->flag & 16)
		str[0] = ' ';
	len = ft_print_width(str, f);
	free(str);
	return (len);
}
