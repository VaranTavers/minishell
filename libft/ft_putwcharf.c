/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcharf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 10:14:34 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void			ft_putcharr(char *str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		write(1, &str[j], 1);
		j++;
	}
}

static int		ft_print_wcharwidth(char *c, t_format *f, int i)
{
	int l;

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
	ft_putcharr(c, i);
	if (l < f->f_width && f->flag & 4)
		while (l < f->f_width)
		{
			write(1, " ", 1);
			++l;
		}
	if (i >= f->f_width)
		return (i);
	return (f->f_width - 1 + i);
}

void			ft_wchar2(char *str, wchar_t wc, int *len)
{
	if (wc <= 0x3FFFFFF)
	{
		str[(*len)++] = ((wc >> 24) | 0xF8);
		str[(*len)++] = (((wc >> 18) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 12) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 6) & 0x3F) | 0x80);
		str[(*len)++] = ((wc & 0x3F) | 0x80);
	}
	else
	{
		str[(*len)++] = ((wc >> 30) | 0xFC);
		str[(*len)++] = (((wc >> 24) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 18) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 12) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 6) & 0x3F) | 0x80);
		str[(*len)++] = ((wc & 0x3F) | 0x80);
	}
}

void			ft_wchar1(char *str, wchar_t wc, int *len)
{
	if (wc < 0x80)
		str[(*len)++] = wc;
	else if (wc <= 0x7FF)
	{
		str[(*len)++] = (0xC0 | (wc >> 6));
		str[(*len)++] = (0x80 | (wc & 0x3F));
	}
	else if (wc <= 0xFFFF)
	{
		str[(*len)++] = ((wc >> 12) | 0xE0);
		str[(*len)++] = (((wc >> 6) & 0x3F) | 0x80);
		str[(*len)++] = ((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0x1FFFFF)
	{
		str[(*len)++] = ((wc >> 18) | 0xF0);
		str[(*len)++] = (((wc >> 12) & 0x3F) | 0x80);
		str[(*len)++] = (((wc >> 6) & 0x3F) | 0x80);
		str[(*len)++] = ((wc & 0x3F) | 0x80);
	}
	else
		ft_wchar2(str, wc, len);
}

int				ft_putwcharf(va_list *lst, t_format *f)
{
	wchar_t		wc;
	char		*str;
	int			ret;
	int			len;

	len = 0;
	wc = (wchar_t)va_arg(*lst, wint_t);
	str = (char*)malloc(sizeof(*str) * 10);
	ft_wchar1(str, wc, &len);
	ret = ft_print_wcharwidth(str, f, len);
	free(str);
	return (ret);
}
