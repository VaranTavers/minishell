/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbinf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/14 10:35:40 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static unsigned long long	get_num(va_list *lst, t_format *f)
{
	if (f->conv[0] == 'b')
		return ((unsigned long long)(va_arg(*lst, unsigned int)));
	if (f->conv[1] == 'b')
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
	int		ret;

	ret = 0;
	if (n == 0)
	{
		if (!(f->flag & 32) && f->precision == 0)
			ret = 1;
		else
			ret = 0;
	}
	while (n > 0)
	{
		ret++;
		n /= 2;
	}
	if (f->precision > ret)
		ret = f->precision;
	return (ret);
}

int							ft_putbinf(va_list *lst, t_format *f)
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
		str[len] = '0' + (num % 2);
		num /= 2;
		len--;
	}
	len = ft_print_width(str, f);
	free(str);
	return (len);
}
