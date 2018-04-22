/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/14 12:04:31 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static unsigned long long	get_num(va_list *lst, t_format *f, char *c)
{
	*c = 'x';
	if (f->conv[0] == 'X' || f->conv[1] == 'X' || f->conv[2] == 'X')
		*c = 'X';
	if (f->conv[0] == 'x' || f->conv[0] == 'X')
		return ((unsigned long long)(va_arg(*lst, unsigned int)));
	if (f->conv[1] == 'x' || f->conv[1] == 'X')
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
		ret = 0;
		if (!(f->flag & 32) && f->precision == 0)
			ret = 1;
	}
	while (n > 0)
	{
		ret++;
		n /= 16;
	}
	if (f->flag & 1 && f->flag & 2 && f->precision == 0 && f->f_width > 0)
		f->precision = (f->f_width - 2) * (!(f->flag & 4));
	if (f->precision > ret)
		ret = f->precision;
	if (f->flag & 1 && num > 0)
		ret += 2;
	else
		f->flag &= 0xFE;
	return (ret);
}

static char					get_char(int i, char c)
{
	char	*x;
	char	*y;

	if (i > 16)
		return (0);
	x = "0123456789abcdef";
	y = "0123456789ABCDEF";
	if (c == 'X')
		return (y[i]);
	return (x[i]);
}

int							ft_puthexf(va_list *lst, t_format *f)
{
	unsigned long long	num;
	int					len;
	char				*str;
	char				c;

	num = get_num(lst, f, &c);
	len = get_len(num, f);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = get_char(num % 16, c);
		num /= 16;
		len--;
	}
	if (f->flag & 1)
		str[0] = '0';
	if (f->flag & 1)
		str[1] = c;
	len = ft_print_width(str, f);
	free(str);
	return (len);
}
