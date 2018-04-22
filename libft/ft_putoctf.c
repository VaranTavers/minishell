/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/14 11:34:34 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static unsigned long long	get_num(va_list *lst, t_format *f)
{
	if (f->conv[0] == 'o')
		return ((unsigned long long)(va_arg(*lst, unsigned int)));
	if (f->conv[0] == 'O' || f->conv[1] == 'O' || f->conv[2] == 'O')
		return ((unsigned long long)(va_arg(*lst, unsigned long)));
	if (f->conv[1] == 'o')
	{
		if (f->conv[0] == 'l')
			return ((unsigned long long)(va_arg(*lst, unsigned long)));
		if (f->conv[0] == 'h')
			return ((unsigned long long)(unsigned short)(va_arg(*lst, int)));
		if (f->conv[0] == 'j')
			return ((unsigned long long)(va_arg(*lst, uintmax_t)));
		if (f->conv[0] == 'z')
			return ((unsigned long long)(va_arg(*lst, size_t)));
	}
	if (f->conv[1] == 'l')
		return (va_arg(*lst, unsigned long long));
	if (f->conv[1] == 'h')
		return ((unsigned long long)(unsigned char)(va_arg(*lst, int)));
	return (ft_dn(lst, f));
}

static int					get_len(unsigned long long n, t_format *f)
{
	int					ret;
	unsigned long long	num;

	num = n;
	ret = 0;
	if (n == 0)
	{
		if ((!(f->flag & 32) && f->precision == 0) || f->flag & 1)
			ret = 1;
		else
			ret = 0;
	}
	while (n > 0)
	{
		ret++;
		n /= 8;
	}
	if (f->precision > ret)
		ret = f->precision;
	else if (f->flag & 1 && num > 0)
		ret++;
	return (ret);
}

int							ft_putoctf(va_list *lst, t_format *f)
{
	unsigned long long	num;
	int					len;
	char				*str;

	num = get_num(lst, f);
	len = get_len(num, f);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + (num % 8);
		num /= 8;
		len--;
	}
	len = ft_print_width(str, f);
	free(str);
	return (len);
}
