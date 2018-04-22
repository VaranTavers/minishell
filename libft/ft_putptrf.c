/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 12:52:18 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static unsigned long long	get_num(va_list *lst, t_format *f, char *c)
{
	*c = 'x';
	f->flag |= 1;
	return ((unsigned long long)(size_t)(va_arg(*lst, void *)));
}

static int					get_len(unsigned long long n, t_format *f)
{
	int					ret;
	unsigned long long	num;

	num = n;
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
		n /= 16;
	}
	if (f->flag & 2 && f->precision == 0 && f->f_width > 0)
		f->precision = f->f_width - 2;
	if (f->precision > ret)
		ret = f->precision;
	ret += 2;
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

int							ft_putptrf(va_list *lst, t_format *f)
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
	str[0] = '0';
	str[1] = c;
	len = ft_print_width(str, f);
	free(str);
	return (len);
}
